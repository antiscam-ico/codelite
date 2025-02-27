#include "bitmap_loader.h"
#include "clConfigurationSelectionCtrl.h"
#include "clThemeUpdater.h"
#include "clThemedChoice.h"
#include "cl_config.h"
#include "codelite_events.h"
#include "configuration_manager_dlg.h"
#include "event_notifier.h"
#include "frame.h"
#include "globals.h"
#include "imanager.h"
#include "manager.h"
#include "wxStringHash.h"

clConfigurationSelectionCtrl::clConfigurationSelectionCtrl(wxWindow* parent, wxWindowID winid, const wxPoint& pos,
                                                           const wxSize& size, long style)
    : wxPanel(parent, winid, pos, size, style)
{
    clThemeUpdater::Get().RegisterWindow(this);
    SetSizer(new wxBoxSizer(wxVERTICAL));
    m_choice = new clThemedChoice(this, wxID_ANY, pos, size, {});
    m_choice->Bind(wxEVT_CHOICE, &clConfigurationSelectionCtrl::OnChoice, this);
    GetSizer()->Add(m_choice, 1, wxEXPAND);

    EventNotifier::Get()->Bind(wxEVT_WORKSPACE_LOADED, &clConfigurationSelectionCtrl::OnWorkspaceLoaded, this);
    EventNotifier::Get()->Bind(wxEVT_WORKSPACE_CLOSED, &clConfigurationSelectionCtrl::OnWorkspaceClosed, this);
    EventNotifier::Get()->Bind(wxEVT_PROJ_ADDED, &clConfigurationSelectionCtrl::OnProjectAdded, this);
    EventNotifier::Get()->Bind(wxEVT_PROJ_REMOVED, &clConfigurationSelectionCtrl::OnProjectRemoved, this);
    wxTheApp->Bind(wxEVT_MENU, &clConfigurationSelectionCtrl::OnConfigurationManager, this,
                   XRCID("configuration_manager"));
    EventNotifier::Get()->Bind(wxEVT_ACTIVE_PROJECT_CHANGED, &clConfigurationSelectionCtrl::OnActiveProjectChanged,
                               this);
}

clConfigurationSelectionCtrl::~clConfigurationSelectionCtrl()
{
    m_choice->Unbind(wxEVT_CHOICE, &clConfigurationSelectionCtrl::OnChoice, this);
    EventNotifier::Get()->Unbind(wxEVT_WORKSPACE_LOADED, &clConfigurationSelectionCtrl::OnWorkspaceLoaded, this);
    EventNotifier::Get()->Unbind(wxEVT_WORKSPACE_CLOSED, &clConfigurationSelectionCtrl::OnWorkspaceClosed, this);
    EventNotifier::Get()->Unbind(wxEVT_PROJ_ADDED, &clConfigurationSelectionCtrl::OnProjectAdded, this);
    EventNotifier::Get()->Unbind(wxEVT_PROJ_REMOVED, &clConfigurationSelectionCtrl::OnProjectRemoved, this);
    wxTheApp->Unbind(wxEVT_MENU, &clConfigurationSelectionCtrl::OnConfigurationManager, this,
                     XRCID("configuration_manager"));
    EventNotifier::Get()->Unbind(wxEVT_ACTIVE_PROJECT_CHANGED, &clConfigurationSelectionCtrl::OnActiveProjectChanged,
                                 this);
}

void clConfigurationSelectionCtrl::Update(const wxArrayString& projects, const wxArrayString& configurations)
{
    m_projects = projects;
    m_configurations = configurations;
    m_configurations.push_back(OPEN_CONFIG_MGR_STR);
    m_choice->Set(configurations);
}

void clConfigurationSelectionCtrl::SetActiveConfiguration(const wxString& activeConfiguration)
{
    this->m_activeConfiguration = activeConfiguration;
    m_choice->SetStringSelection(m_activeConfiguration); // this will ensure that the checkbox is placed correctly
    // override the text to include the active project name
    m_choice->SetText(wxString() << m_activeProject << " :: " << m_activeConfiguration);
}

void clConfigurationSelectionCtrl::SetActiveProject(const wxString& activeProject)
{
    this->m_activeProject = activeProject;
    m_choice->SetText(wxString() << m_activeProject << " :: " << m_activeConfiguration);
}

void clConfigurationSelectionCtrl::OnChoice(wxCommandEvent& event)
{
    int where = event.GetSelection();
    if(where == wxNOT_FOUND)
        return;

    wxString selectedString = m_choice->GetString(where);
    if(selectedString != OPEN_CONFIG_MGR_STR) {

        SetActiveConfiguration(selectedString);
        DoConfigChanged(selectedString);

        // Fire 'config-changed' event
        clCommandEvent changeEvent(wxEVT_WORKSPACE_BUILD_CONFIG_CHANGED);
        changeEvent.SetString(selectedString);
        EventNotifier::Get()->AddPendingEvent(changeEvent);
    } else {
        DoOpenConfigurationManagerDlg();
    }
}

void clConfigurationSelectionCtrl::Clear() {}

void clConfigurationSelectionCtrl::SetConfigurations(const wxArrayString& configurations)
{
    m_configurations = configurations;
    m_configurations.push_back(OPEN_CONFIG_MGR_STR);
    m_choice->Set(m_configurations);
}

void clConfigurationSelectionCtrl::OnWorkspaceLoaded(wxCommandEvent& event)
{
    event.Skip();
    if(ManagerST::Get()->IsWorkspaceOpen()) {
        Enable(true);
        DoWorkspaceConfig();
        DoUpdateChoiceWithProjects();
    }
}

void clConfigurationSelectionCtrl::OnWorkspaceClosed(wxCommandEvent& event)
{
    event.Skip();
    Clear();
    Enable(false);
}

void clConfigurationSelectionCtrl::OnProjectAdded(clCommandEvent& event)
{
    event.Skip();
    DoUpdateChoiceWithProjects();
}

void clConfigurationSelectionCtrl::OnProjectRemoved(clCommandEvent& event)
{
    event.Skip();
    DoUpdateChoiceWithProjects();
}

void clConfigurationSelectionCtrl::DoUpdateChoiceWithProjects()
{
    if(clCxxWorkspaceST::Get()->IsOpen()) {
        SetActiveProject(ManagerST::Get()->GetActiveProjectName());
    }
}

void clConfigurationSelectionCtrl::DoWorkspaceConfig()
{
    // Update the workspace configuration
    BuildMatrixPtr matrix = clCxxWorkspaceST::Get()->GetBuildMatrix();
    auto confs = matrix->GetConfigurations();

    confs.sort([](WorkspaceConfigurationPtr one, WorkspaceConfigurationPtr two) {
        return one->GetName().CmpNoCase(two->GetName()) < 0;
    });

    wxArrayString configurations;
    std::for_each(confs.begin(), confs.end(),
                  [&](WorkspaceConfigurationPtr conf) { configurations.push_back(conf->GetName()); });

    SetConfigurations(configurations);
    wxString activeConfig = configurations.IsEmpty() ? "" : matrix->GetSelectedConfigurationName();
    SetActiveConfiguration(activeConfig);

    clMainFrame::Get()->SelectBestEnvSet();
}

void clConfigurationSelectionCtrl::OnConfigurationManager(wxCommandEvent& e)
{
    wxUnusedVar(e);
    DoOpenConfigurationManagerDlg();
}

void clConfigurationSelectionCtrl::DoOpenConfigurationManagerDlg()
{
    ConfigurationManagerDlg dlg(EventNotifier::Get()->TopFrame());
    dlg.ShowModal();

    BuildMatrixPtr matrix = ManagerST::Get()->GetWorkspaceBuildMatrix();
    SetActiveConfiguration(matrix->GetSelectedConfigurationName());
}

void clConfigurationSelectionCtrl::DoConfigChanged(const wxString& newConfigName)
{
    wxBusyCursor bc;
    BuildMatrixPtr matrix = ManagerST::Get()->GetWorkspaceBuildMatrix();
    matrix->SetSelectedConfigurationName(newConfigName);
    ManagerST::Get()->SetWorkspaceBuildMatrix(matrix);

    // Set the focus to the active editor if any
    clEditor* editor = clMainFrame::Get()->GetMainBook()->GetActiveEditor();
    if(editor) {
        editor->SetActive();
    }

    ManagerST::Get()->UpdateParserPaths(true);
}

void clConfigurationSelectionCtrl::OnActiveProjectChanged(clProjectSettingsEvent& event)
{
    event.Skip();
    SetActiveProject(event.GetProjectName());
}

#include "BuildTargetDlg.h"
#include "ColoursAndFontsManager.h"
#include "FSConfigPage.h"
#include "clFSWNewConfigDlg.h"
#include "clFileSystemWorkspace.hpp"
#include "clFileSystemWorkspaceDlg.h"
#include "globals.h"
#include "macros.h"
#include <wx/msgdlg.h>
#include <wx/textdlg.h>
#include <wx/wupdlock.h>

clFileSystemWorkspaceDlg::clFileSystemWorkspaceDlg(wxWindow* parent)
    : clFileSystemWorkspaceDlgBase(parent)
{
    wxWindowUpdateLocker locker(this);
    const auto& configsMap = clFileSystemWorkspace::Get().GetSettings().GetConfigsMap();
    clFileSystemWorkspaceConfig::Ptr_t conf = clFileSystemWorkspace::Get().GetSettings().GetSelectedConfig();
    wxString selConf;
    if(conf) {
        selConf = conf->GetName();
    }
    for(const auto& vt : configsMap) {
        FSConfigPage* page = new FSConfigPage(m_notebook, vt.second);
        m_notebook->AddPage(page, vt.second->GetName(), (selConf == vt.first));
    }
    ::clSetDialogBestSizeAndPosition(this);
}

clFileSystemWorkspaceDlg::~clFileSystemWorkspaceDlg() {}

void clFileSystemWorkspaceDlg::OnOK(wxCommandEvent& event)
{
    for(size_t i = 0; i < m_notebook->GetPageCount(); ++i) {
        FSConfigPage* page = dynamic_cast<FSConfigPage*>(m_notebook->GetPage(i));
        if(!page) {
            continue;
        }
        page->Save();
    }

    int sel = m_notebook->GetSelection();
    clFileSystemWorkspace::Get().Save(false);
    clFileSystemWorkspace::Get().GetSettings().SetSelectedConfig(m_notebook->GetPageText(sel));
    clFileSystemWorkspace::Get().Save(true);
    EndModal(wxID_OK);
}

void clFileSystemWorkspaceDlg::OnNewConfig(wxCommandEvent& event)
{
    wxUnusedVar(event);
    clFSWNewConfigDlg dlg(this);
    if(dlg.ShowModal() != wxID_OK) {
        return;
    }

    wxString name = dlg.GetConfigName();
    if(name.IsEmpty()) {
        return;
    }

    wxString copyFrom = dlg.GetCopyFrom();
    if(copyFrom == "-- None --") {
        copyFrom.Clear();
    }

    if(clFileSystemWorkspace::Get().GetSettings().AddConfig(name, copyFrom)) {
        clFileSystemWorkspaceConfig::Ptr_t conf = clFileSystemWorkspace::Get().GetSettings().GetConfig(name);
        FSConfigPage* page = new FSConfigPage(m_notebook, conf);
        m_notebook->AddPage(page, name, true);
    }
}

void clFileSystemWorkspaceDlg::OnDeleteConfig(wxCommandEvent& event)
{
    if(m_notebook->GetSelection() == wxNOT_FOUND) {
        return;
    }
    if(m_notebook->GetPageCount() == 1) {
        return;
    }
    int sel = m_notebook->GetSelection();
    if(sel == wxNOT_FOUND) {
        return;
    }

    wxString message;
    message << _("Choosing 'Yes' will delete workspace configuration '") << m_notebook->GetPageText(sel) << "'\n";
    message << _("Continue?");
    if(::wxMessageBox(message, "Confirm", wxYES_NO | wxCANCEL | wxCANCEL_DEFAULT, this) != wxYES) {
        return;
    }

    if(clFileSystemWorkspace::Get().GetSettings().DeleteConfig(m_notebook->GetPageText(sel))) {
        wxWindowUpdateLocker locker(this);
        m_notebook->DeletePage(sel);
    }
}

void clFileSystemWorkspaceDlg::OnDeleteConfigUI(wxUpdateUIEvent& event)
{
    event.Enable(m_notebook->GetPageCount() > 1);
}

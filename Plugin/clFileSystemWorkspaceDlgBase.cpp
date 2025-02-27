//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: clFileSystemWorkspaceDlgBase.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#include "clFileSystemWorkspaceDlgBase.h"

// Declare the bitmap loading function
extern void wxCB09InitBitmapResources();

static bool bBitmapLoaded = false;

clFileSystemWorkspaceDlgBase::clFileSystemWorkspaceDlgBase(wxWindow* parent, wxWindowID id, const wxString& title,
                                                           const wxPoint& pos, const wxSize& size, long style)
    : wxDialog(parent, id, title, pos, size, style)
{
    if(!bBitmapLoaded) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxCB09InitBitmapResources();
        bBitmapLoaded = true;
    }

    wxBoxSizer* boxSizer2 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer2);

    wxBoxSizer* boxSizer97 = new wxBoxSizer(wxHORIZONTAL);

    boxSizer2->Add(boxSizer97, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_notebook = new wxChoicebook(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxBK_DEFAULT);
    m_notebook->SetName(wxT("m_notebook"));

    boxSizer97->Add(m_notebook, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer99 = new wxBoxSizer(wxVERTICAL);

    boxSizer97->Add(boxSizer99, 0, wxLEFT | wxRIGHT | wxBOTTOM | wxEXPAND, WXC_FROM_DIP(5));

    m_buttonNew = new wxButton(this, wxID_NEW, _("New"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer99->Add(m_buttonNew, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_buttonDelete =
        new wxButton(this, wxID_DELETE, _("Delete"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer99->Add(m_buttonDelete, 0, wxALL, WXC_FROM_DIP(5));

    m_stdBtnSizer4 = new wxStdDialogButtonSizer();

    boxSizer2->Add(m_stdBtnSizer4, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, WXC_FROM_DIP(5));

    m_buttonOK = new wxButton(this, wxID_OK, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_buttonOK->SetDefault();
    m_stdBtnSizer4->AddButton(m_buttonOK);

    m_button12 = new wxButton(this, wxID_CANCEL, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_stdBtnSizer4->AddButton(m_button12);
    m_stdBtnSizer4->Realize();

#if wxVERSION_NUMBER >= 2900
    if(!wxPersistenceManager::Get().Find(m_notebook)) {
        wxPersistenceManager::Get().RegisterAndRestore(m_notebook);
    } else {
        wxPersistenceManager::Get().Restore(m_notebook);
    }
#endif

    SetName(wxT("clFileSystemWorkspaceDlgBase"));
    SetSize(wxDLG_UNIT(this, wxSize(-1, -1)));
    if(GetSizer()) {
        GetSizer()->Fit(this);
    }
    if(GetParent()) {
        CentreOnParent(wxBOTH);
    } else {
        CentreOnScreen(wxBOTH);
    }
#if wxVERSION_NUMBER >= 2900
    if(!wxPersistenceManager::Get().Find(this)) {
        wxPersistenceManager::Get().RegisterAndRestore(this);
    } else {
        wxPersistenceManager::Get().Restore(this);
    }
#endif
    // Connect events
    m_buttonNew->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(clFileSystemWorkspaceDlgBase::OnNewConfig),
                         NULL, this);
    m_buttonDelete->Connect(wxEVT_COMMAND_BUTTON_CLICKED,
                            wxCommandEventHandler(clFileSystemWorkspaceDlgBase::OnDeleteConfig), NULL, this);
    m_buttonDelete->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(clFileSystemWorkspaceDlgBase::OnDeleteConfigUI),
                            NULL, this);
    m_buttonOK->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(clFileSystemWorkspaceDlgBase::OnOK), NULL,
                        this);
}

clFileSystemWorkspaceDlgBase::~clFileSystemWorkspaceDlgBase()
{
    m_buttonNew->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED,
                            wxCommandEventHandler(clFileSystemWorkspaceDlgBase::OnNewConfig), NULL, this);
    m_buttonDelete->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED,
                               wxCommandEventHandler(clFileSystemWorkspaceDlgBase::OnDeleteConfig), NULL, this);
    m_buttonDelete->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(clFileSystemWorkspaceDlgBase::OnDeleteConfigUI),
                               NULL, this);
    m_buttonOK->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(clFileSystemWorkspaceDlgBase::OnOK),
                           NULL, this);
}

BuildTargetDlgBase::BuildTargetDlgBase(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos,
                                       const wxSize& size, long style)
    : wxDialog(parent, id, title, pos, size, style)
{
    if(!bBitmapLoaded) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxCB09InitBitmapResources();
        bBitmapLoaded = true;
    }

    wxBoxSizer* boxSizer48 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer48);

    wxFlexGridSizer* flexGridSizer56 = new wxFlexGridSizer(0, 2, 0, 0);
    flexGridSizer56->SetFlexibleDirection(wxBOTH);
    flexGridSizer56->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);
    flexGridSizer56->AddGrowableCol(1);
    flexGridSizer56->AddGrowableRow(1);

    boxSizer48->Add(flexGridSizer56, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText58 =
        new wxStaticText(this, wxID_ANY, _("Name:"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer56->Add(m_staticText58, 0, wxALL | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));

    m_textCtrlaName = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(200, -1)), 0);
    m_textCtrlaName->SetFocus();
#if wxVERSION_NUMBER >= 3000
    m_textCtrlaName->SetHint(wxT(""));
#endif

    flexGridSizer56->Add(m_textCtrlaName, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText62 =
        new wxStaticText(this, wxID_ANY, _("Command:"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer56->Add(m_staticText62, 0, wxALL | wxALIGN_RIGHT | wxALIGN_TOP, WXC_FROM_DIP(5));

    m_textCtrlValue = new wxStyledTextCtrl(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    // Configure the fold margin
    m_textCtrlValue->SetMarginType(4, wxSTC_MARGIN_SYMBOL);
    m_textCtrlValue->SetMarginMask(4, wxSTC_MASK_FOLDERS);
    m_textCtrlValue->SetMarginSensitive(4, true);
    m_textCtrlValue->SetMarginWidth(4, 0);

    // Configure the tracker margin
    m_textCtrlValue->SetMarginWidth(1, 0);

    // Configure the symbol margin
    m_textCtrlValue->SetMarginType(2, wxSTC_MARGIN_SYMBOL);
    m_textCtrlValue->SetMarginMask(2, ~(wxSTC_MASK_FOLDERS));
    m_textCtrlValue->SetMarginWidth(2, 0);
    m_textCtrlValue->SetMarginSensitive(2, true);

    // Configure the line numbers margin
    m_textCtrlValue->SetMarginType(0, wxSTC_MARGIN_NUMBER);
    m_textCtrlValue->SetMarginWidth(0, 0);

    // Configure the line symbol margin
    m_textCtrlValue->SetMarginType(3, wxSTC_MARGIN_FORE);
    m_textCtrlValue->SetMarginMask(3, 0);
    m_textCtrlValue->SetMarginWidth(3, 0);
    // Select the lexer
    m_textCtrlValue->SetLexer(wxSTC_LEX_NULL);
    // Set default font / styles
    m_textCtrlValue->StyleClearAll();
    m_textCtrlValue->SetWrapMode(2);
    m_textCtrlValue->SetIndentationGuides(0);
    m_textCtrlValue->SetKeyWords(0, wxT(""));
    m_textCtrlValue->SetKeyWords(1, wxT(""));
    m_textCtrlValue->SetKeyWords(2, wxT(""));
    m_textCtrlValue->SetKeyWords(3, wxT(""));
    m_textCtrlValue->SetKeyWords(4, wxT(""));

    flexGridSizer56->Add(m_textCtrlValue, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_stdBtnSizer50 = new wxStdDialogButtonSizer();

    boxSizer48->Add(m_stdBtnSizer50, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, WXC_FROM_DIP(5));

    m_button52 = new wxButton(this, wxID_CANCEL, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_stdBtnSizer50->AddButton(m_button52);

    m_button54 = new wxButton(this, wxID_OK, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_button54->SetDefault();
    m_stdBtnSizer50->AddButton(m_button54);
    m_stdBtnSizer50->Realize();

    SetName(wxT("BuildTargetDlgBase"));
    SetSize(wxDLG_UNIT(this, wxSize(-1, -1)));
    if(GetSizer()) {
        GetSizer()->Fit(this);
    }
    if(GetParent()) {
        CentreOnParent(wxBOTH);
    } else {
        CentreOnScreen(wxBOTH);
    }
#if wxVERSION_NUMBER >= 2900
    if(!wxPersistenceManager::Get().Find(this)) {
        wxPersistenceManager::Get().RegisterAndRestore(this);
    } else {
        wxPersistenceManager::Get().Restore(this);
    }
#endif
    // Connect events
    m_button54->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(BuildTargetDlgBase::OnOK_UI), NULL, this);
}

BuildTargetDlgBase::~BuildTargetDlgBase()
{
    m_button54->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(BuildTargetDlgBase::OnOK_UI), NULL, this);
}

FSConfigPageBase::FSConfigPageBase(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style)
    : wxPanel(parent, id, pos, size, style)
{
    if(!bBitmapLoaded) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxCB09InitBitmapResources();
        bBitmapLoaded = true;
    }

    wxBoxSizer* boxSizer76 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer76);

    m_notebook = new wxNotebook(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxBK_DEFAULT);
    m_notebook->SetName(wxT("m_notebook"));

    boxSizer76->Add(m_notebook, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_panelGeneral =
        new wxPanel(m_notebook, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_notebook, wxSize(-1, -1)), wxTAB_TRAVERSAL);
    m_panelGeneral->SetFocus();
    m_notebook->AddPage(m_panelGeneral, _("General"), true);

    wxFlexGridSizer* flexGridSizer33 = new wxFlexGridSizer(0, 2, 0, 0);
    flexGridSizer33->SetFlexibleDirection(wxBOTH);
    flexGridSizer33->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);
    flexGridSizer33->AddGrowableCol(1);
    flexGridSizer33->AddGrowableRow(2);
    m_panelGeneral->SetSizer(flexGridSizer33);

    m_staticText109 = new wxStaticText(m_panelGeneral, wxID_ANY, _("Executable:"), wxDefaultPosition,
                                       wxDLG_UNIT(m_panelGeneral, wxSize(-1, -1)), 0);

    flexGridSizer33->Add(m_staticText109, 0, wxALL | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));

    m_filePickerExe = new wxFilePickerCtrl(m_panelGeneral, wxID_ANY, wxEmptyString, _("Select a file"), wxT("*"),
                                           wxDefaultPosition, wxDLG_UNIT(m_panelGeneral, wxSize(-1, -1)),
                                           wxFLP_DEFAULT_STYLE | wxFLP_USE_TEXTCTRL | wxFLP_SMALL);
    m_filePickerExe->SetToolTip(_("The executable to use for debugging / executing"));

    flexGridSizer33->Add(m_filePickerExe, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText191 = new wxStaticText(m_panelGeneral, wxID_ANY, _("Working directory:"), wxDefaultPosition,
                                       wxDLG_UNIT(m_panelGeneral, wxSize(-1, -1)), 0);

    flexGridSizer33->Add(m_staticText191, 0, wxALL, WXC_FROM_DIP(5));

    m_dirPickerWD = new wxDirPickerCtrl(m_panelGeneral, wxID_ANY, wxEmptyString, _("Select a folder"),
                                        wxDefaultPosition, wxDLG_UNIT(m_panelGeneral, wxSize(-1, -1)),
                                        wxDIRP_SMALL | wxDIRP_DEFAULT_STYLE | wxDIRP_USE_TEXTCTRL);

    flexGridSizer33->Add(m_dirPickerWD, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText113 = new wxStaticText(m_panelGeneral, wxID_ANY, _("Arguments:"), wxDefaultPosition,
                                       wxDLG_UNIT(m_panelGeneral, wxSize(-1, -1)), 0);

    flexGridSizer33->Add(m_staticText113, 0, wxALL | wxALIGN_RIGHT | wxALIGN_TOP, WXC_FROM_DIP(5));

    m_textCtrlArgs =
        new clThemedSTC(m_panelGeneral, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panelGeneral, wxSize(-1, -1)), 0);
    // Configure the fold margin
    m_textCtrlArgs->SetMarginType(4, wxSTC_MARGIN_SYMBOL);
    m_textCtrlArgs->SetMarginMask(4, wxSTC_MASK_FOLDERS);
    m_textCtrlArgs->SetMarginSensitive(4, true);
    m_textCtrlArgs->SetMarginWidth(4, 0);

    // Configure the tracker margin
    m_textCtrlArgs->SetMarginWidth(1, 0);

    // Configure the symbol margin
    m_textCtrlArgs->SetMarginType(2, wxSTC_MARGIN_SYMBOL);
    m_textCtrlArgs->SetMarginMask(2, ~(wxSTC_MASK_FOLDERS));
    m_textCtrlArgs->SetMarginWidth(2, 0);
    m_textCtrlArgs->SetMarginSensitive(2, true);

    // Configure the line numbers margin
    m_textCtrlArgs->SetMarginType(0, wxSTC_MARGIN_NUMBER);
    m_textCtrlArgs->SetMarginWidth(0, 0);

    // Configure the line symbol margin
    m_textCtrlArgs->SetMarginType(3, wxSTC_MARGIN_FORE);
    m_textCtrlArgs->SetMarginMask(3, 0);
    m_textCtrlArgs->SetMarginWidth(3, 0);
    // Select the lexer
    m_textCtrlArgs->SetLexer(wxSTC_LEX_NULL);
    // Set default font / styles
    m_textCtrlArgs->StyleClearAll();
    m_textCtrlArgs->SetWrapMode(2);
    m_textCtrlArgs->SetIndentationGuides(0);
    m_textCtrlArgs->SetKeyWords(0, wxT(""));
    m_textCtrlArgs->SetKeyWords(1, wxT(""));
    m_textCtrlArgs->SetKeyWords(2, wxT(""));
    m_textCtrlArgs->SetKeyWords(3, wxT(""));
    m_textCtrlArgs->SetKeyWords(4, wxT(""));

    flexGridSizer33->Add(m_textCtrlArgs, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText125 = new wxStaticText(m_panelGeneral, wxID_ANY, _("Tool chain:"), wxDefaultPosition,
                                       wxDLG_UNIT(m_panelGeneral, wxSize(-1, -1)), 0);
    m_staticText125->SetToolTip(_("Select the toolchain to use"));

    flexGridSizer33->Add(m_staticText125, 0, wxALL | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));

    wxArrayString m_choiceCompilerArr;
    m_choiceCompiler = new clThemedChoice(m_panelGeneral, wxID_ANY, wxDefaultPosition,
                                          wxDLG_UNIT(m_panelGeneral, wxSize(-1, -1)), m_choiceCompilerArr, 0);
    m_choiceCompiler->SetToolTip(_("Select the toolchain to use"));

    flexGridSizer33->Add(m_choiceCompiler, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText179 = new wxStaticText(m_panelGeneral, wxID_ANY, _("Debugger:"), wxDefaultPosition,
                                       wxDLG_UNIT(m_panelGeneral, wxSize(-1, -1)), 0);

    flexGridSizer33->Add(m_staticText179, 0, wxALL | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));

    wxArrayString m_choiceDebuggersArr;
    m_choiceDebuggers = new clThemedChoice(m_panelGeneral, wxID_ANY, wxDefaultPosition,
                                           wxDLG_UNIT(m_panelGeneral, wxSize(-1, -1)), m_choiceDebuggersArr, 0);

    flexGridSizer33->Add(m_choiceDebuggers, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText35 = new wxStaticText(m_panelGeneral, wxID_ANY, _("File extensions:"), wxDefaultPosition,
                                      wxDLG_UNIT(m_panelGeneral, wxSize(-1, -1)), 0);
    m_staticText35->SetToolTip(_("Set the file extensions to be parsed in this\nworkspace"));

    flexGridSizer33->Add(m_staticText35, 0, wxALL | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));

    m_textCtrlFileExt = new wxTextCtrl(m_panelGeneral, wxID_ANY, wxT(""), wxDefaultPosition,
                                       wxDLG_UNIT(m_panelGeneral, wxSize(-1, -1)), 0);
    m_textCtrlFileExt->SetToolTip(_("Set the file extensions to be parsed in this\nworkspace"));
#if wxVERSION_NUMBER >= 3000
    m_textCtrlFileExt->SetHint(wxT(""));
#endif

    flexGridSizer33->Add(m_textCtrlFileExt, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText187 = new wxStaticText(m_panelGeneral, wxID_ANY, _("Exclude files:"), wxDefaultPosition,
                                       wxDLG_UNIT(m_panelGeneral, wxSize(-1, -1)), 0);

    flexGridSizer33->Add(m_staticText187, 0, wxALL | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));

    m_textCtrlExcludeFiles = new wxTextCtrl(m_panelGeneral, wxID_ANY, wxT(""), wxDefaultPosition,
                                            wxDLG_UNIT(m_panelGeneral, wxSize(-1, -1)), 0);
    m_textCtrlExcludeFiles->SetToolTip(_("Files matching this pattern will not be\ndisplayed in the tree view"));
#if wxVERSION_NUMBER >= 3000
    m_textCtrlExcludeFiles->SetHint(wxT(""));
#endif

    flexGridSizer33->Add(m_textCtrlExcludeFiles, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText207 = new wxStaticText(m_panelGeneral, wxID_ANY, _("Exclude paths:"), wxDefaultPosition,
                                       wxDLG_UNIT(m_panelGeneral, wxSize(-1, -1)), 0);

    flexGridSizer33->Add(m_staticText207, 0, wxALL | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer209 = new wxBoxSizer(wxHORIZONTAL);

    flexGridSizer33->Add(boxSizer209, 1, wxEXPAND, WXC_FROM_DIP(5));

    m_textCtrlExcludePaths = new wxTextCtrl(m_panelGeneral, wxID_ANY, wxT(""), wxDefaultPosition,
                                            wxDLG_UNIT(m_panelGeneral, wxSize(-1, -1)), 0);
    m_textCtrlExcludePaths->SetToolTip(
        _("Add here list of paths to be ignored.\nThe path is expected to be relative to the root folder of the "
          "workspace\nIgnored paths will still be visible in the tree, but they will not be\nused in workspace "
          "operations (find in files, code completion etc)"));
#if wxVERSION_NUMBER >= 3000
    m_textCtrlExcludePaths->SetHint(wxT(""));
#endif

    boxSizer209->Add(m_textCtrlExcludePaths, 1, wxALL, WXC_FROM_DIP(5));

    m_button213 = new wxButton(m_panelGeneral, wxID_ANY, _("Edit"), wxDefaultPosition,
                               wxDLG_UNIT(m_panelGeneral, wxSize(-1, -1)), 0);

    boxSizer209->Add(m_button213, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_panelBuild =
        new wxPanel(m_notebook, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_notebook, wxSize(-1, -1)), wxTAB_TRAVERSAL);
    m_notebook->AddPage(m_panelBuild, _("Build"), false);

    wxBoxSizer* boxSizer30 = new wxBoxSizer(wxVERTICAL);
    m_panelBuild->SetSizer(boxSizer30);

    wxBoxSizer* boxSizer38 = new wxBoxSizer(wxHORIZONTAL);

    boxSizer30->Add(boxSizer38, 1, wxEXPAND, WXC_FROM_DIP(5));

    m_dvListCtrlTargets = new clThemedListCtrl(m_panelBuild, wxID_ANY, wxDefaultPosition,
                                               wxDLG_UNIT(m_panelBuild, wxSize(-1, -1)), wxDV_ROW_LINES | wxDV_SINGLE);

    boxSizer38->Add(m_dvListCtrlTargets, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_dvListCtrlTargets->AppendTextColumn(_("Target Name"), wxDATAVIEW_CELL_INERT, WXC_FROM_DIP(-2), wxALIGN_LEFT,
                                          wxDATAVIEW_COL_RESIZABLE);
    m_dvListCtrlTargets->AppendTextColumn(_("Command"), wxDATAVIEW_CELL_INERT, WXC_FROM_DIP(-2), wxALIGN_LEFT,
                                          wxDATAVIEW_COL_RESIZABLE);
    wxBoxSizer* boxSizer40 = new wxBoxSizer(wxVERTICAL);

    boxSizer38->Add(boxSizer40, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_buttonNew =
        new wxButton(m_panelBuild, wxID_NEW, _("New"), wxDefaultPosition, wxDLG_UNIT(m_panelBuild, wxSize(-1, -1)), 0);
    m_buttonNew->SetDefault();

    boxSizer40->Add(m_buttonNew, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_buttonEdit = new wxButton(m_panelBuild, wxID_EDIT, _("Edit"), wxDefaultPosition,
                                wxDLG_UNIT(m_panelBuild, wxSize(-1, -1)), 0);

    boxSizer40->Add(m_buttonEdit, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_buttonDelete = new wxButton(m_panelBuild, wxID_DELETE, _("Delete"), wxDefaultPosition,
                                  wxDLG_UNIT(m_panelBuild, wxSize(-1, -1)), 0);

    boxSizer40->Add(m_buttonDelete, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_panelCodeCompletion =
        new wxPanel(m_notebook, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_notebook, wxSize(-1, -1)), wxTAB_TRAVERSAL);
    m_notebook->AddPage(m_panelCodeCompletion, _("Code Completion"), false);

    wxBoxSizer* boxSizer22 = new wxBoxSizer(wxVERTICAL);
    m_panelCodeCompletion->SetSizer(boxSizer22);

    m_staticText26 = new wxStaticText(m_panelCodeCompletion, wxID_ANY, _("Place your build flags one-per-line here"),
                                      wxDefaultPosition, wxDLG_UNIT(m_panelCodeCompletion, wxSize(-1, -1)), 0);
    m_staticText26->SetToolTip(_("Place your build flags one-per-line here.\nFor "
                                 "example:\n\n-I/home/eran/include\n-I/home/eran/wx/include\n-DSOME=1\n\nThese flags "
                                 "will be used by CodeLite for better\ncode completion"));

    boxSizer22->Add(m_staticText26, 0, wxALL, WXC_FROM_DIP(5));

    m_stcCCFlags = new wxStyledTextCtrl(m_panelCodeCompletion, wxID_ANY, wxDefaultPosition,
                                        wxDLG_UNIT(m_panelCodeCompletion, wxSize(-1, -1)), 0);
    m_stcCCFlags->SetFocus();
    // Configure the fold margin
    m_stcCCFlags->SetMarginType(4, wxSTC_MARGIN_SYMBOL);
    m_stcCCFlags->SetMarginMask(4, wxSTC_MASK_FOLDERS);
    m_stcCCFlags->SetMarginSensitive(4, true);
    m_stcCCFlags->SetMarginWidth(4, 0);

    // Configure the tracker margin
    m_stcCCFlags->SetMarginWidth(1, 0);

    // Configure the symbol margin
    m_stcCCFlags->SetMarginType(2, wxSTC_MARGIN_SYMBOL);
    m_stcCCFlags->SetMarginMask(2, ~(wxSTC_MASK_FOLDERS));
    m_stcCCFlags->SetMarginWidth(2, 0);
    m_stcCCFlags->SetMarginSensitive(2, true);

    // Configure the line numbers margin
    m_stcCCFlags->SetMarginType(0, wxSTC_MARGIN_NUMBER);
    m_stcCCFlags->SetMarginWidth(0, 0);

    // Configure the line symbol margin
    m_stcCCFlags->SetMarginType(3, wxSTC_MARGIN_FORE);
    m_stcCCFlags->SetMarginMask(3, 0);
    m_stcCCFlags->SetMarginWidth(3, 0);
    // Select the lexer
    m_stcCCFlags->SetLexer(wxSTC_LEX_NULL);
    // Set default font / styles
    m_stcCCFlags->StyleClearAll();
    m_stcCCFlags->SetWrapMode(2);
    m_stcCCFlags->SetIndentationGuides(0);
    m_stcCCFlags->SetKeyWords(0, wxT(""));
    m_stcCCFlags->SetKeyWords(1, wxT(""));
    m_stcCCFlags->SetKeyWords(2, wxT(""));
    m_stcCCFlags->SetKeyWords(3, wxT(""));
    m_stcCCFlags->SetKeyWords(4, wxT(""));

    boxSizer22->Add(m_stcCCFlags, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_panelEnv =
        new wxPanel(m_notebook, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_notebook, wxSize(-1, -1)), wxTAB_TRAVERSAL);
    m_notebook->AddPage(m_panelEnv, _("Environment"), false);

    wxBoxSizer* boxSizer117 = new wxBoxSizer(wxVERTICAL);
    m_panelEnv->SetSizer(boxSizer117);

    m_staticText119 = new wxStaticText(m_panelEnv, wxID_ANY, _("Environment variables:"), wxDefaultPosition,
                                       wxDLG_UNIT(m_panelEnv, wxSize(-1, -1)), 0);

    boxSizer117->Add(m_staticText119, 0, wxALL, WXC_FROM_DIP(5));

    m_stcEnv = new wxStyledTextCtrl(m_panelEnv, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panelEnv, wxSize(-1, -1)), 0);
    // Configure the fold margin
    m_stcEnv->SetMarginType(4, wxSTC_MARGIN_SYMBOL);
    m_stcEnv->SetMarginMask(4, wxSTC_MASK_FOLDERS);
    m_stcEnv->SetMarginSensitive(4, true);
    m_stcEnv->SetMarginWidth(4, 0);

    // Configure the tracker margin
    m_stcEnv->SetMarginWidth(1, 0);

    // Configure the symbol margin
    m_stcEnv->SetMarginType(2, wxSTC_MARGIN_SYMBOL);
    m_stcEnv->SetMarginMask(2, ~(wxSTC_MASK_FOLDERS));
    m_stcEnv->SetMarginWidth(2, 0);
    m_stcEnv->SetMarginSensitive(2, true);

    // Configure the line numbers margin
    m_stcEnv->SetMarginType(0, wxSTC_MARGIN_NUMBER);
    m_stcEnv->SetMarginWidth(0, 0);

    // Configure the line symbol margin
    m_stcEnv->SetMarginType(3, wxSTC_MARGIN_FORE);
    m_stcEnv->SetMarginMask(3, 0);
    m_stcEnv->SetMarginWidth(3, 0);
    // Select the lexer
    m_stcEnv->SetLexer(wxSTC_LEX_NULL);
    // Set default font / styles
    m_stcEnv->StyleClearAll();
    m_stcEnv->SetWrapMode(1);
    m_stcEnv->SetIndentationGuides(0);
    m_stcEnv->SetKeyWords(0, wxT(""));
    m_stcEnv->SetKeyWords(1, wxT(""));
    m_stcEnv->SetKeyWords(2, wxT(""));
    m_stcEnv->SetKeyWords(3, wxT(""));
    m_stcEnv->SetKeyWords(4, wxT(""));

    boxSizer117->Add(m_stcEnv, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_panelRemote =
        new wxPanel(m_notebook, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_notebook, wxSize(-1, -1)), wxTAB_TRAVERSAL);
    m_notebook->AddPage(m_panelRemote, _("Remote"), false);

    wxBoxSizer* boxSizer153 = new wxBoxSizer(wxVERTICAL);
    m_panelRemote->SetSizer(boxSizer153);

    wxFlexGridSizer* flexGridSizer155 = new wxFlexGridSizer(0, 3, 0, 0);
    flexGridSizer155->SetFlexibleDirection(wxBOTH);
    flexGridSizer155->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);
    flexGridSizer155->AddGrowableCol(1);

    boxSizer153->Add(flexGridSizer155, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    flexGridSizer155->Add(0, 0, 1, wxALL, WXC_FROM_DIP(5));

    m_checkBoxEnableRemote = new wxCheckBox(m_panelRemote, wxID_ANY, _("Enable remote development"), wxDefaultPosition,
                                            wxDLG_UNIT(m_panelRemote, wxSize(-1, -1)), 0);
    m_checkBoxEnableRemote->SetValue(false);

    flexGridSizer155->Add(m_checkBoxEnableRemote, 0, wxALL, WXC_FROM_DIP(5));

    flexGridSizer155->Add(0, 0, 1, wxALL, WXC_FROM_DIP(5));

    m_staticText161 = new wxStaticText(m_panelRemote, wxID_ANY, _("SSH Account:"), wxDefaultPosition,
                                       wxDLG_UNIT(m_panelRemote, wxSize(-1, -1)), 0);

    flexGridSizer155->Add(m_staticText161, 0, wxALL | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));

    wxArrayString m_choiceSSHAccountArr;
    m_choiceSSHAccount = new wxChoice(m_panelRemote, wxID_ANY, wxDefaultPosition,
                                      wxDLG_UNIT(m_panelRemote, wxSize(-1, -1)), m_choiceSSHAccountArr, 0);

    flexGridSizer155->Add(m_choiceSSHAccount, 0, wxALL | wxEXPAND | wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));

    flexGridSizer155->Add(0, 0, 1, wxALL, WXC_FROM_DIP(5));

    m_staticText165 = new wxStaticText(m_panelRemote, wxID_ANY, _("Remote folder:"), wxDefaultPosition,
                                       wxDLG_UNIT(m_panelRemote, wxSize(-1, -1)), 0);

    flexGridSizer155->Add(m_staticText165, 0, wxALL | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));

    m_textCtrlRemoteFolder = new wxTextCtrl(m_panelRemote, wxID_ANY, wxT(""), wxDefaultPosition,
                                            wxDLG_UNIT(m_panelRemote, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlRemoteFolder->SetHint(wxT(""));
#endif

    flexGridSizer155->Add(m_textCtrlRemoteFolder, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_button169 = new wxButton(m_panelRemote, wxID_ANY, _("..."), wxDefaultPosition,
                               wxDLG_UNIT(m_panelRemote, wxSize(-1, -1)), wxBU_EXACTFIT);
    m_button169->SetToolTip(_("Browse for folder"));

    flexGridSizer155->Add(m_button169, 0, wxALL | wxALIGN_TOP, WXC_FROM_DIP(5));

    flexGridSizer155->Add(0, 0, 1, wxALL, WXC_FROM_DIP(5));

    m_checkBoxRemoteBuild = new wxCheckBox(m_panelRemote, wxID_ANY, _("Use remote build"), wxDefaultPosition,
                                           wxDLG_UNIT(m_panelRemote, wxSize(-1, -1)), 0);
    m_checkBoxRemoteBuild->SetValue(false);
    m_checkBoxRemoteBuild->SetToolTip(_("Execute the build commands on the remote machine"));

    flexGridSizer155->Add(m_checkBoxRemoteBuild, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    SetName(wxT("FSConfigPageBase"));
    SetSize(wxDLG_UNIT(this, wxSize(-1, -1)));
    if(GetSizer()) {
        GetSizer()->Fit(this);
    }
    // Connect events
    m_button213->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FSConfigPageBase::OnEditExcludePaths),
                         NULL, this);
    m_dvListCtrlTargets->Connect(wxEVT_COMMAND_DATAVIEW_ITEM_ACTIVATED,
                                 wxDataViewEventHandler(FSConfigPageBase::OnTargetActivated), NULL, this);
    m_buttonNew->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FSConfigPageBase::OnNewTarget), NULL,
                         this);
    m_buttonEdit->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FSConfigPageBase::OnEditTarget), NULL,
                          this);
    m_buttonEdit->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(FSConfigPageBase::OnEditTargetUI), NULL, this);
    m_buttonDelete->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FSConfigPageBase::OnDelete), NULL,
                            this);
    m_buttonDelete->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(FSConfigPageBase::OnDeleteUI), NULL, this);
    m_checkBoxEnableRemote->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(FSConfigPageBase::OnEnableRemoteUI), NULL,
                                    this);
    m_choiceSSHAccount->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(FSConfigPageBase::OnRemoteEnabledUI), NULL,
                                this);
    m_choiceSSHAccount->Connect(wxEVT_COMMAND_CHOICE_SELECTED,
                                wxCommandEventHandler(FSConfigPageBase::OnSSHAccountChoice), NULL, this);
    m_textCtrlRemoteFolder->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(FSConfigPageBase::OnRemoteEnabledUI), NULL,
                                    this);
    m_button169->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(FSConfigPageBase::OnRemoteEnabledUI), NULL, this);
    m_button169->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FSConfigPageBase::OnSSHBrowse), NULL,
                         this);
    m_checkBoxRemoteBuild->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(FSConfigPageBase::OnRemoteEnabledUI), NULL,
                                   this);
}

FSConfigPageBase::~FSConfigPageBase()
{
    m_button213->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FSConfigPageBase::OnEditExcludePaths),
                            NULL, this);
    m_dvListCtrlTargets->Disconnect(wxEVT_COMMAND_DATAVIEW_ITEM_ACTIVATED,
                                    wxDataViewEventHandler(FSConfigPageBase::OnTargetActivated), NULL, this);
    m_buttonNew->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FSConfigPageBase::OnNewTarget), NULL,
                            this);
    m_buttonEdit->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FSConfigPageBase::OnEditTarget), NULL,
                             this);
    m_buttonEdit->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(FSConfigPageBase::OnEditTargetUI), NULL, this);
    m_buttonDelete->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FSConfigPageBase::OnDelete), NULL,
                               this);
    m_buttonDelete->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(FSConfigPageBase::OnDeleteUI), NULL, this);
    m_checkBoxEnableRemote->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(FSConfigPageBase::OnEnableRemoteUI),
                                       NULL, this);
    m_choiceSSHAccount->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(FSConfigPageBase::OnRemoteEnabledUI), NULL,
                                   this);
    m_choiceSSHAccount->Disconnect(wxEVT_COMMAND_CHOICE_SELECTED,
                                   wxCommandEventHandler(FSConfigPageBase::OnSSHAccountChoice), NULL, this);
    m_textCtrlRemoteFolder->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(FSConfigPageBase::OnRemoteEnabledUI),
                                       NULL, this);
    m_button169->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(FSConfigPageBase::OnRemoteEnabledUI), NULL, this);
    m_button169->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(FSConfigPageBase::OnSSHBrowse), NULL,
                            this);
    m_checkBoxRemoteBuild->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(FSConfigPageBase::OnRemoteEnabledUI),
                                      NULL, this);
}

NewFileSystemWorkspaceDialogBase::NewFileSystemWorkspaceDialogBase(wxWindow* parent, wxWindowID id,
                                                                   const wxString& title, const wxPoint& pos,
                                                                   const wxSize& size, long style)
    : wxDialog(parent, id, title, pos, size, style)
{
    if(!bBitmapLoaded) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxCB09InitBitmapResources();
        bBitmapLoaded = true;
    }

    wxBoxSizer* boxSizer131 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer131);

    wxFlexGridSizer* flexGridSizer139 = new wxFlexGridSizer(0, 2, 0, 0);
    flexGridSizer139->SetFlexibleDirection(wxBOTH);
    flexGridSizer139->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);
    flexGridSizer139->AddGrowableCol(1);

    boxSizer131->Add(flexGridSizer139, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText141 =
        new wxStaticText(this, wxID_ANY, _("Workspace path:"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer139->Add(m_staticText141, 0, wxALL | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));

    m_dirPickerPath = new wxDirPickerCtrl(this, wxID_ANY, wxEmptyString, _("Select a folder"), wxDefaultPosition,
                                          wxDLG_UNIT(this, wxSize(300, -1)),
                                          wxDIRP_SMALL | wxDIRP_DEFAULT_STYLE | wxDIRP_USE_TEXTCTRL);
    m_dirPickerPath->SetFocus();

    flexGridSizer139->Add(m_dirPickerPath, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText145 =
        new wxStaticText(this, wxID_ANY, _("Workspace name:"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer139->Add(m_staticText145, 0, wxALL | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));

    m_textCtrlName = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlName->SetHint(wxT(""));
#endif

    flexGridSizer139->Add(m_textCtrlName, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_stdBtnSizer133 = new wxStdDialogButtonSizer();

    boxSizer131->Add(m_stdBtnSizer133, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, WXC_FROM_DIP(5));

    m_buttonOK = new wxButton(this, wxID_OK, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_buttonOK->SetDefault();
    m_stdBtnSizer133->AddButton(m_buttonOK);

    m_button137 = new wxButton(this, wxID_CANCEL, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_stdBtnSizer133->AddButton(m_button137);
    m_stdBtnSizer133->Realize();

    SetName(wxT("NewFileSystemWorkspaceDialogBase"));
    SetSize(wxDLG_UNIT(this, wxSize(-1, -1)));
    if(GetSizer()) {
        GetSizer()->Fit(this);
    }
    if(GetParent()) {
        CentreOnParent(wxBOTH);
    } else {
        CentreOnScreen(wxBOTH);
    }
#if wxVERSION_NUMBER >= 2900
    if(!wxPersistenceManager::Get().Find(this)) {
        wxPersistenceManager::Get().RegisterAndRestore(this);
    } else {
        wxPersistenceManager::Get().Restore(this);
    }
#endif
    // Connect events
    m_dirPickerPath->Connect(wxEVT_COMMAND_DIRPICKER_CHANGED,
                             wxFileDirPickerEventHandler(NewFileSystemWorkspaceDialogBase::OnDirSelected), NULL, this);
    m_buttonOK->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(NewFileSystemWorkspaceDialogBase::OnOKUI), NULL, this);
}

NewFileSystemWorkspaceDialogBase::~NewFileSystemWorkspaceDialogBase()
{
    m_dirPickerPath->Disconnect(wxEVT_COMMAND_DIRPICKER_CHANGED,
                                wxFileDirPickerEventHandler(NewFileSystemWorkspaceDialogBase::OnDirSelected), NULL,
                                this);
    m_buttonOK->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(NewFileSystemWorkspaceDialogBase::OnOKUI), NULL,
                           this);
}

clFSWNewConfigDlgBase::clFSWNewConfigDlgBase(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos,
                                             const wxSize& size, long style)
    : wxDialog(parent, id, title, pos, size, style)
{
    if(!bBitmapLoaded) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxCB09InitBitmapResources();
        bBitmapLoaded = true;
    }

    wxBoxSizer* boxSizer221 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer221);

    wxFlexGridSizer* flexGridSizer229 = new wxFlexGridSizer(0, 2, 0, 0);
    flexGridSizer229->SetFlexibleDirection(wxBOTH);
    flexGridSizer229->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);
    flexGridSizer229->AddGrowableCol(1);

    boxSizer221->Add(flexGridSizer229, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText231 =
        new wxStaticText(this, wxID_ANY, _("Name:"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer229->Add(m_staticText231, 0, wxALL | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));

    m_textCtrlName = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(200, -1)), 0);
    m_textCtrlName->SetFocus();
#if wxVERSION_NUMBER >= 3000
    m_textCtrlName->SetHint(wxT(""));
#endif

    flexGridSizer229->Add(m_textCtrlName, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText235 =
        new wxStaticText(this, wxID_ANY, _("Copy from:"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer229->Add(m_staticText235, 0, wxALL | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));

    wxArrayString m_choiceCopyFromArr;
    m_choiceCopyFrom =
        new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), m_choiceCopyFromArr, 0);

    flexGridSizer229->Add(m_choiceCopyFrom, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_stdBtnSizer223 = new wxStdDialogButtonSizer();

    boxSizer221->Add(m_stdBtnSizer223, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, WXC_FROM_DIP(5));

    m_button225 = new wxButton(this, wxID_OK, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_button225->SetDefault();
    m_stdBtnSizer223->AddButton(m_button225);

    m_button227 = new wxButton(this, wxID_CANCEL, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_stdBtnSizer223->AddButton(m_button227);
    m_stdBtnSizer223->Realize();

    SetName(wxT("clFSWNewConfigDlgBase"));
    SetSize(wxDLG_UNIT(this, wxSize(-1, -1)));
    if(GetSizer()) {
        GetSizer()->Fit(this);
    }
    if(GetParent()) {
        CentreOnParent(wxBOTH);
    } else {
        CentreOnScreen(wxBOTH);
    }
#if wxVERSION_NUMBER >= 2900
    if(!wxPersistenceManager::Get().Find(this)) {
        wxPersistenceManager::Get().RegisterAndRestore(this);
    } else {
        wxPersistenceManager::Get().Restore(this);
    }
#endif
    // Connect events
    m_button225->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(clFSWNewConfigDlgBase::OnOKUI), NULL, this);
}

clFSWNewConfigDlgBase::~clFSWNewConfigDlgBase()
{
    m_button225->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(clFSWNewConfigDlgBase::OnOKUI), NULL, this);
}

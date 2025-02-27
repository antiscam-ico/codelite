#ifndef CLSYSTEMSETTINGS_H
#define CLSYSTEMSETTINGS_H

#include "clColours.h"
#include "cl_command_event.h"
#include "codelite_exports.h"
#include <wx/event.h>
#include <wx/settings.h>

wxDECLARE_EXPORTED_EVENT(WXDLLIMPEXP_SDK, wxEVT_SYS_COLOURS_CHANGED, clCommandEvent);

enum wxSysColourEx {
    wxSYS_COLOUR_TOOLBAR = wxSYS_COLOUR_MAX + 1,
    wxSYS_COLOUR_TOOLBARTEXT,
};

class WXDLLIMPEXP_SDK clSystemSettings : public wxEvtHandler, public wxSystemSettings
{
    static bool m_useCustomColours;
    static clColours m_customColours;

protected:
    void OnColoursChanged(clCommandEvent& event);
    void OnSystemColourChanged(wxSysColourChangedEvent& event);
    void DoColourChangedEvent();
    clSystemSettings();

public:
    static clSystemSettings& Get();

    virtual ~clSystemSettings();
    static wxColour GetColour(int index);
};

#endif // CLSYSTEMSETTINGS_H

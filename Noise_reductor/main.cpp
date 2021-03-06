﻿#include <wx/wx.h>
#include "initFrame.h"
#include "infoFrame.h"
#include "editFrame.h"


class MyApp : public wxApp {

public:

    virtual bool OnInit();
    virtual int OnExit() { return 0; }

};

IMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    wxFrame* mainFrame = new InitFrame(NULL, wxID_ANY, wxString("Wybierz fragmenty do analizy"), wxDefaultPosition, wxSize(900, 600), wxDEFAULT_FRAME_STYLE);
    mainFrame->Show(true);
    SetTopWindow(mainFrame);

    return true;
}

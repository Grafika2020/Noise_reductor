#include <wx/wx.h>
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
    wxInitAllImageHandlers();
    wxFrame* mainFrame = new InitFrame(NULL);
    mainFrame->Show(true);
    SetTopWindow(mainFrame);

    return true;
}

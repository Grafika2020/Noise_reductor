#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/panel.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/statline.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/spinbutt.h>
#include <wx/scrolwin.h>
#include <wx/choice.h>
#include <wx/slider.h>
#include <wx/listbox.h>
#include "imageHandler.h"

///////////////////////////////////////////////////////////////////////////////
/// Class InfoFrame
///////////////////////////////////////////////////////////////////////////////
class InfoFrame : public wxFrame
{
private:

protected:
	wxStaticText* info;
	wxButton* button;
	ImageHandler *m_imageHandler;
	// Virtual event handlers, overide them in your derived class
	void closeInfo(wxCommandEvent& event);
	std::vector<std::string> temp;
	int xd;
	
public:

	InfoFrame(wxWindow* parent, ImageHandler *imageHandler = nullptr, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(600, 300), long style = wxDEFAULT_FRAME_STYLE ^ wxRESIZE_BORDER);

	~InfoFrame();
	void OnClose(wxCloseEvent &evt);

	void readData();
	double max(double, double, double) const;
	double min(double, double, double) const;

};

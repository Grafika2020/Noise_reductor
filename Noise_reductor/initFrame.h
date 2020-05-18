#pragma once

#include <wx/wx.h>
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
#include <wx/dcbuffer.h>

#include "infoFrame.h"
#include "editFrame.h"

///////////////////////////////////////////////////////////////////////////////
/// Class InitFrame
///////////////////////////////////////////////////////////////////////////////
class InitFrame : public wxFrame
{

protected:
	wxBitmap image;
	wxScrolledWindow* loadedImagePanel;
	wxStaticLine* line1;
	wxStaticLine* line2;
	wxButton* finishButton;
	wxButton* loadButton;

	wxStaticText* framesDescription;
	wxListBox* framesList;

	void openFrames(wxCommandEvent& event);
	void loadImage(wxCommandEvent& event);

public:

	InitFrame(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(910, 500), long style = wxDEFAULT_FRAME_STYLE ^ wxRESIZE_BORDER);

	~InitFrame();

};
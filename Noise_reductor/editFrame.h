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
#include <wx/radiobox.h>
#include "imageHandler.h"
#include "synchronizedWindow.h"


#define imageOrginalID 5000
#define imageModifiedID 5001

///////////////////////////////////////////////////////////////////////////////
/// Class EditFrame
///////////////////////////////////////////////////////////////////////////////
class EditFrame : public wxFrame
{
private:
	int m_lastselected{ 0 };
	
protected:
	wxStaticText* text;
	wxSpinButton* spin;
	SynchronizedWindow* imageOrginal;
	SynchronizedWindow* imageModified;
	wxStaticLine* line;
	wxSlider* slider1;
	wxRadioBox* selectRepresentation;
	wxRadioBox* selectRGB;
	wxRadioBox* selectHSL;
	wxRadioBox* selectHSV;
	ImageHandler* m_imageHandler;
	
public:

	EditFrame(wxWindow* parent, ImageHandler *imageHandler = nullptr, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(1000, 700), long style = wxDEFAULT_FRAME_STYLE ^ wxRESIZE_BORDER);

	~EditFrame();
	void OnClose(wxCloseEvent &evt);
	void OnUpdateUI(wxUpdateUIEvent &evt);
	void OnRadioBox(wxCommandEvent &evt);
	void OnScroll(wxWindowID id, int x, int y);
	void draw();
};


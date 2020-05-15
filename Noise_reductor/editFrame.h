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

///////////////////////////////////////////////////////////////////////////////
/// Class EditFrame
///////////////////////////////////////////////////////////////////////////////
class EditFrame : public wxFrame
{
private:

protected:
	wxStaticText* text;
	wxSpinButton* spin;
	wxScrolledWindow* imageOrginal;
	wxScrolledWindow* imageModified;
	wxStaticLine* line;
	wxChoice* choiceKanal;
	wxSlider* slider1;
	wxSlider* slider2;
	wxSlider* slider3;

public:

	EditFrame(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(979, 560), long style = wxDEFAULT_FRAME_STYLE ^ wxRESIZE_BORDER);

	~EditFrame();

};

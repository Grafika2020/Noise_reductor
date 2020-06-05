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
#include <wx/msgdlg.h>
#include "imageHandler.h"
#include "synchronizedWindow.h"
#include "infoFrame.h"


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
	
	
	SynchronizedWindow* imageOrginal;
	SynchronizedWindow* imageModified;
	wxStaticLine* line1;
	wxStaticLine* line2;
	wxSlider* slider1;
	wxStaticText* sliderDesc;
	wxStaticText* sliderVal;
	wxRadioBox* selectRepresentation;
	wxRadioBox* selectRGB;
	wxRadioBox* selectHSL;
	wxRadioBox* selectHSV;
	wxButton* startButton;
	wxButton* fullImageButton;
	wxButton* resetButton;
	wxButton* saveButton;
	ImageHandler* m_imageHandler;
	InfoFrame* m_infoFrame;
	
public:

	EditFrame(wxWindow* parent, InfoFrame* infoFrame = nullptr, ImageHandler *imageHandler = nullptr, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(1000, 700), long style = wxDEFAULT_FRAME_STYLE ^ wxRESIZE_BORDER);

	~EditFrame();
	void gausssian_blur(bool fragment = true);
	void blur_RGB(float sigma, int channel, wxSize visible_area, wxPoint starrt_of_view, wxImage image_to_mod, wxImage original_img);
	void blur_HSL(float sigma, wxSize visible_area, wxPoint start_of_view, wxImage image_to_mod, wxImage original_img);
	void blur_HSV(float sigma, wxSize visible_area, wxPoint start_of_view, wxImage image_to_mod, wxImage original_img);
	void OnClose(wxCloseEvent &evt);
	void OnUpdateUI(wxUpdateUIEvent &evt);
	void OnRadioBox(wxCommandEvent &evt);
	void OnScroll(wxWindowID id, int x, int y);
	void OnReset(wxCommandEvent& event);
	void Save(wxCommandEvent& event);
	void blurFragment(wxCommandEvent& event);
	void blurFull(wxCommandEvent &event);
	void setSliderLabel();
	void draw();
};

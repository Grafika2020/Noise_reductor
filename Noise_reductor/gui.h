///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame1
///////////////////////////////////////////////////////////////////////////////
class MyFrame1 : public wxFrame
{
	private:

	protected:
		wxPanel* loadedImagePanel;
		wxStaticLine* line1;
		wxButton* button1;

		// Virtual event handlers, overide them in your derived class
		virtual void openFrames( wxCommandEvent& event ) { event.Skip(); }


	public:

		MyFrame1( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 638,394 ), long style = wxDEFAULT_FRAME_STYLE^wxRESIZE_BORDER );

		~MyFrame1();

};

///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame2
///////////////////////////////////////////////////////////////////////////////
class MyFrame2 : public wxFrame
{
	private:

	protected:
		wxStaticText* textTemp;
		wxButton* button2;

		// Virtual event handlers, overide them in your derived class
		virtual void closeInfo( wxCommandEvent& event ) { event.Skip(); }


	public:

		MyFrame2( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 326,105 ), long style = wxDEFAULT_FRAME_STYLE^wxRESIZE_BORDER);

		~MyFrame2();

};

///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame3
///////////////////////////////////////////////////////////////////////////////
class MyFrame3 : public wxFrame
{
	private:

	protected:
		wxStaticText* text3;
		wxSpinButton* spin3;
		wxScrolledWindow* imageOrginal;
		wxScrolledWindow* imageModified;
		wxStaticLine* m_staticline6;
		wxChoice* choiceKanal;
		wxSlider* slider1;
		wxSlider* slider2;
		wxSlider* slider3;

	public:

		MyFrame3( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 979,560 ), long style = wxDEFAULT_FRAME_STYLE^wxRESIZE_BORDER);

		~MyFrame3();

};


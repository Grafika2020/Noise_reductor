///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "gui.h"

///////////////////////////////////////////////////////////////////////////

MyFrame1::MyFrame1( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* sizer1main;
	sizer1main = new wxBoxSizer( wxVERTICAL );

	loadedImagePanel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	loadedImagePanel->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHTTEXT ) );

	sizer1main->Add( loadedImagePanel, 1, wxEXPAND | wxALL, 5 );

	line1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	sizer1main->Add( line1, 0, wxEXPAND | wxALL, 5 );

	button1 = new wxButton( this, wxID_ANY, wxT("Gotowe"), wxDefaultPosition, wxDefaultSize, 0 );
	sizer1main->Add( button1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	this->SetSizer( sizer1main );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	button1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::openFrames ), NULL, this );
}

MyFrame1::~MyFrame1()
{
	// Disconnect Events
	button1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::openFrames ), NULL, this );

}

MyFrame2::MyFrame2( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->Hide();

	wxBoxSizer* sizer2main;
	sizer2main = new wxBoxSizer( wxVERTICAL );

	textTemp = new wxStaticText( this, wxID_ANY, wxT("informacje"), wxDefaultPosition, wxDefaultSize, 0 );
	textTemp->Wrap( -1 );
	sizer2main->Add( textTemp, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	button2 = new wxButton( this, wxID_ANY, wxT("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	sizer2main->Add( button2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	this->SetSizer( sizer2main );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	button2->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame2::closeInfo ), NULL, this );
}

MyFrame2::~MyFrame2()
{
	// Disconnect Events
	button2->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame2::closeInfo ), NULL, this );

}

MyFrame3::MyFrame3( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->Hide();

	wxBoxSizer* sizer3main;
	sizer3main = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* sizer3fragments;
	sizer3fragments = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* sizer3chooseFragment;
	sizer3chooseFragment = new wxBoxSizer( wxHORIZONTAL );


	sizer3chooseFragment->Add( 0, 0, 1, wxEXPAND, 5 );

	text3 = new wxStaticText( this, wxID_ANY, wxT("Wybor fragmentu"), wxDefaultPosition, wxDefaultSize, 0 );
	text3->Wrap( -1 );
	sizer3chooseFragment->Add( text3, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	spin3 = new wxSpinButton( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_HORIZONTAL );
	sizer3chooseFragment->Add( spin3, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	sizer3chooseFragment->Add( 0, 0, 1, wxEXPAND, 5 );


	sizer3fragments->Add( sizer3chooseFragment, 1, wxEXPAND|wxALIGN_RIGHT, 5 );

	wxBoxSizer* sizer3chosenFragment;
	sizer3chosenFragment = new wxBoxSizer( wxHORIZONTAL );

	imageOrginal = new wxScrolledWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	imageOrginal->SetScrollRate( 5, 5 );
	imageOrginal->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNHIGHLIGHT ) );

	sizer3chosenFragment->Add( imageOrginal, 1, wxEXPAND | wxALL, 5 );

	imageModified = new wxScrolledWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	imageModified->SetScrollRate( 5, 5 );
	imageModified->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNHIGHLIGHT ) );

	sizer3chosenFragment->Add( imageModified, 1, wxEXPAND | wxALL, 5 );


	sizer3fragments->Add( sizer3chosenFragment, 8, wxEXPAND, 5 );


	sizer3main->Add( sizer3fragments, 6, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );

	m_staticline6 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	sizer3main->Add( m_staticline6, 0, wxEXPAND | wxALL, 5 );

	wxBoxSizer* sizer3modifyFragemtns;
	sizer3modifyFragemtns = new wxBoxSizer( wxHORIZONTAL );


	sizer3modifyFragemtns->Add( 0, 0, 1, wxEXPAND, 5 );

	wxString choiceKanalChoices[] = { wxT("RGB"), wxT("HSL"), wxT("HSV"), wxT("LAB") };
	int choiceKanalNChoices = sizeof( choiceKanalChoices ) / sizeof( wxString );
	choiceKanal = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, choiceKanalNChoices, choiceKanalChoices, 0 );
	choiceKanal->SetSelection( 0 );
	sizer3modifyFragemtns->Add( choiceKanal, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wxBoxSizer* sizer3suwaki;
	sizer3suwaki = new wxBoxSizer( wxVERTICAL );

	slider1 = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	sizer3suwaki->Add( slider1, 0, wxALL, 5 );

	slider2 = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	sizer3suwaki->Add( slider2, 0, wxALL, 5 );

	slider3 = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	sizer3suwaki->Add( slider3, 0, wxALL, 5 );


	sizer3modifyFragemtns->Add( sizer3suwaki, 0, wxALIGN_CENTER_VERTICAL, 5 );


	sizer3modifyFragemtns->Add( 0, 0, 1, wxEXPAND, 5 );


	sizer3main->Add( sizer3modifyFragemtns, 1, wxEXPAND, 5 );


	this->SetSizer( sizer3main );
	this->Layout();

	this->Centre( wxBOTH );
}

MyFrame3::~MyFrame3()
{
}

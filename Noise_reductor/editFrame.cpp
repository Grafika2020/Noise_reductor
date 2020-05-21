#include "editFrame.h"

EditFrame::EditFrame(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style, ImageHandler *imageHandler) : wxFrame(parent, id, title, pos, size, style),m_imageHandler(imageHandler)
{
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);
	this->Hide();

	wxBoxSizer* sizer3main;
	sizer3main = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* sizer3fragments;
	sizer3fragments = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* sizer3chooseFragment;
	sizer3chooseFragment = new wxBoxSizer(wxHORIZONTAL);


	sizer3chooseFragment->Add(0, 0, 1, wxEXPAND, 5);

	text = new wxStaticText(this, wxID_ANY, wxT("Wybor fragmentu"), wxDefaultPosition, wxDefaultSize, 0);
	text->Wrap(-1);
	sizer3chooseFragment->Add(text, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

	spin = new wxSpinButton(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_HORIZONTAL);
	sizer3chooseFragment->Add(spin, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);


	sizer3chooseFragment->Add(0, 0, 1, wxEXPAND, 5);


	sizer3fragments->Add(sizer3chooseFragment, 1, wxEXPAND | wxALIGN_RIGHT, 5);

	wxBoxSizer* sizer3chosenFragment;
	sizer3chosenFragment = new wxBoxSizer(wxHORIZONTAL);

	imageOrginal = new wxScrolledWindow(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL | wxVSCROLL);
	imageOrginal->SetScrollRate(5, 5);
	imageOrginal->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNHIGHLIGHT));

	sizer3chosenFragment->Add(imageOrginal, 1, wxEXPAND | wxALL, 5);

	imageModified = new wxScrolledWindow(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL | wxVSCROLL);
	imageModified->SetScrollRate(5, 5);
	imageModified->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNHIGHLIGHT));

	sizer3chosenFragment->Add(imageModified, 1, wxEXPAND | wxALL, 5);


	sizer3fragments->Add(sizer3chosenFragment, 8, wxEXPAND, 5);


	sizer3main->Add(sizer3fragments, 6, wxALIGN_CENTER_HORIZONTAL | wxEXPAND, 5);

	line = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
	sizer3main->Add(line, 0, wxEXPAND | wxALL, 5);

	wxBoxSizer* sizer3modifyFragemtns;
	sizer3modifyFragemtns = new wxBoxSizer(wxHORIZONTAL);


	sizer3modifyFragemtns->Add(0, 0, 1, wxEXPAND, 5);

	wxString choiceKanalChoices[] = { wxT("RGB"), wxT("HSL"), wxT("HSV"), wxT("LAB") };
	int choiceKanalNChoices = sizeof(choiceKanalChoices) / sizeof(wxString);
	choiceKanal = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, choiceKanalNChoices, choiceKanalChoices, 0);
	choiceKanal->SetSelection(0);
	sizer3modifyFragemtns->Add(choiceKanal, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

	wxBoxSizer* sizer3suwaki;
	sizer3suwaki = new wxBoxSizer(wxVERTICAL);

	slider1 = new wxSlider(this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL);
	sizer3suwaki->Add(slider1, 0, wxALL, 5);

	slider2 = new wxSlider(this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL);
	sizer3suwaki->Add(slider2, 0, wxALL, 5);

	slider3 = new wxSlider(this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL);
	sizer3suwaki->Add(slider3, 0, wxALL, 5);


	sizer3modifyFragemtns->Add(sizer3suwaki, 0, wxALIGN_CENTER_VERTICAL, 5);


	sizer3modifyFragemtns->Add(0, 0, 1, wxEXPAND, 5);


	sizer3main->Add(sizer3modifyFragemtns, 1, wxEXPAND, 5);


	this->SetSizer(sizer3main);
	this->Layout();

	this->Centre(wxBOTH);
	this->Connect(wxEVT_CLOSE_WINDOW, wxCloseEventHandler(EditFrame::OnClose));
}

EditFrame::~EditFrame()
{
}

void EditFrame::OnClose(wxCloseEvent & evt)
{
	GetParent()->Destroy();
}

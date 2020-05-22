#include "infoFrame.h"

InfoFrame::InfoFrame(wxWindow* parent, ImageHandler *imageHandler, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxFrame(parent, id, title, pos, size, style), m_imageHandler(imageHandler)
{
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);
	this->Hide();

	wxBoxSizer* sizer1info;
	sizer1info = new wxBoxSizer(wxVERTICAL);

	info = new wxStaticText(this, wxID_ANY, wxT("informacje"), wxDefaultPosition, wxDefaultSize, 0);
	info->Wrap(-1);
	sizer1info->Add(info, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

	button = new wxButton(this, wxID_ANY, wxT("OK"), wxDefaultPosition, wxDefaultSize, 0);
	sizer1info->Add(button, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);


	this->SetSizer(sizer1info);
	this->Layout();

	this->Centre(wxBOTH);

	// Connect Events
	button->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(InfoFrame::closeInfo), NULL, this);
	this->Connect(wxEVT_CLOSE_WINDOW, wxCloseEventHandler(InfoFrame::OnClose));
}

InfoFrame::~InfoFrame()
{
	// Disconnect Events
	button->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(InfoFrame::closeInfo), NULL, this);
	this->Disconnect(wxEVT_CLOSE_WINDOW, wxCloseEventHandler(InfoFrame::OnClose));
}

void InfoFrame::OnClose(wxCloseEvent &evt)
{
	GetParent()->Destroy();
}

void InfoFrame::closeInfo(wxCommandEvent& event)
{
	this->Close();
}

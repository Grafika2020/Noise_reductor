#include "infoFrame.h"

InfoFrame::InfoFrame(wxWindow* parent, ImageHandler *imageHandler, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxFrame(parent, id, title, pos, size, style), m_imageHandler(imageHandler)
{
	readData();

	this->SetSizeHints(wxDefaultSize, wxDefaultSize);
	this->Hide();

	wxBoxSizer* sizer1info;
	sizer1info = new wxBoxSizer(wxVERTICAL);


	std::string temp_all;
	for (auto x : temp) {
		temp_all += x;
	}
	info = new wxStaticText(this, wxID_ANY, temp_all, wxDefaultPosition, wxDefaultSize, 0);
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

void InfoFrame::readData() {

	int i = 1;
	for (auto frag : m_imageHandler->getFragments()) {

		int elements = 0;
		std::string new_data;
		double avRed;
		double avBlu;
		double avGrn;
		unsigned long long int R = 0;
		unsigned long long int B = 0;
		unsigned long long int G = 0;

		for (int i = 0; i < frag.GetHeight(); ++i) {
			for (int j = 0; j < frag.GetWidth(); ++j) {
				R += frag.GetRed(i, j);
				B += frag.GetBlue(i, j);
				G += frag.GetGreen(i, j);
				elements += 1;
			}
		}

		avRed = R / static_cast<double>(elements);
		avBlu = B / static_cast<double>(elements);
		avGrn = G / static_cast<double>(elements);
		
		new_data += "frag ";
		new_data += std::to_string(i);
		new_data += ": R:";
		new_data += std::to_string(avRed);
		new_data += ", B:";
		new_data += std::to_string(avBlu);
		new_data += ", G:";
		new_data += std::to_string(avGrn);
		new_data += "\n";

		temp.push_back(new_data);
		
		++i;
	}

}
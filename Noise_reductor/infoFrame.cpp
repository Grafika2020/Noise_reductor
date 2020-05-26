#include "infoFrame.h"

InfoFrame::InfoFrame(wxWindow* parent, ImageHandler *imageHandler, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxFrame(parent, id, title, pos, size, style), m_imageHandler(imageHandler)
{
	/*readData();*/

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
		double avR, avB, avG, avL, avV;
		unsigned long long int R, B, G;
		double L, V;
		R = B = G = L = V = 0;
		double cmax, cmin;

		for (int i = 0; i < frag.GetHeight(); ++i) {
			for (int j = 0; j < frag.GetWidth(); ++j) {

				cmax = max(frag.GetRed(i, j) / 255., frag.GetBlue(i, j) / 255., frag.GetGreen(i, j) / 255.);
				cmin = min(frag.GetRed(i, j) / 255., frag.GetBlue(i, j) / 255., frag.GetGreen(i, j) / 255.);

				R += frag.GetRed(i, j);
				B += frag.GetBlue(i, j);
				G += frag.GetGreen(i, j);
				V += cmax;
				L += (cmax + cmin) / 2.;

				elements += 1;
			}
		}

		avR = R / static_cast<double>(elements);
		avB = B / static_cast<double>(elements);
		avG = G / static_cast<double>(elements);
		avL = L / static_cast<double>(elements);
		avV = V / static_cast<double>(elements);
		
		double sdR, sdG, sdB, sdL, sdV;
		sdR = sdG = sdB = sdL = sdV = 0;
		for (int i = 0; i < frag.GetHeight(); ++i) {
			for (int j = 0; j < frag.GetWidth(); ++j) {

				cmax = max(frag.GetRed(i, j) / 255., frag.GetBlue(i, j) / 255., frag.GetGreen(i, j) / 255.);
				cmin = min(frag.GetRed(i, j) / 255., frag.GetBlue(i, j) / 255., frag.GetGreen(i, j) / 255.);

				sdR += pow(frag.GetRed(i, j) - avR, 2);
				sdB += pow(frag.GetRed(i, j) - avB, 2);
				sdG += pow(frag.GetRed(i, j) - avG, 2);
				sdV += pow(cmax - avV, 2);
				sdL += pow((cmax + cmin) / 2. - avL, 2);
			}
		}

		sdR /= elements;
		sdB /= elements;
		sdG /= elements;
		sdL /= elements;
		sdV /= elements;

		sdR = sqrt(sdR);
		sdB = sqrt(sdB);
		sdG = sqrt(sdG);
		sdL = sqrt(sdL);
		sdV = sqrt(sdV);

		new_data += "frag ";
		new_data += std::to_string(i);
		new_data += "\nsrednie: R:";
		new_data += std::to_string(avR);
		new_data += ", B:";
		new_data += std::to_string(avB);
		new_data += ", G:";
		new_data += std::to_string(avG);
		new_data += ", V:";
		new_data += std::to_string(avV);
		new_data += ", L:";
		new_data += std::to_string(avL);
		new_data += "\nodch.std.: R:";
		new_data += std::to_string(sdR);
		new_data += ", B:";
		new_data += std::to_string(sdB);
		new_data += ", G:";
		new_data += std::to_string(sdG);
		new_data += ", V:";
		new_data += std::to_string(sdV);
		new_data += ", L:";
		new_data += std::to_string(sdL);
		new_data += "\n";

		temp.push_back(new_data);
		
		++i;
	}

}

double InfoFrame::max(double a, double b, double c) const {
	return a > b ? (a > c ? a : c) : (b > c ? b : c);
}

double InfoFrame::min(double a, double b, double c) const {
	return a < b ? (a < c ? a : c) : (b < c ? b : c);
}

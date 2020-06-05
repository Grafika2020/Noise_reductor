#include "infoFrame.h"

InfoFrame::InfoFrame(wxWindow* parent, ImageHandler *imageHandler, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxFrame(parent, id, title, pos, size, style), m_imageHandler(imageHandler)
{

	this->SetSizeHints(wxDefaultSize, wxDefaultSize);
	this->Hide();

	wxBoxSizer* sizer1info;
	sizer1info = new wxBoxSizer(wxVERTICAL);

	listBox = new wxListBox(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, wxLB_HSCROLL);
	sizer1info->Add(listBox, 1, wxALL | wxEXPAND, 5);

	this->SetSizer(sizer1info);
	this->Layout();

	this->Centre(wxBOTH);

	readData();

	// Connect Events
	
	this->Connect(wxEVT_CLOSE_WINDOW, wxCloseEventHandler(InfoFrame::OnClose));

}

InfoFrame::~InfoFrame()
{
	// Disconnect Events
	this->Disconnect(wxEVT_CLOSE_WINDOW, wxCloseEventHandler(InfoFrame::OnClose));
}

void InfoFrame::OnClose(wxCloseEvent &evt)
{
	GetParent()->Destroy();
}



void InfoFrame::readData() {

	int i = 1;
	wxArrayString str_arr;
	for (auto frag : m_imageHandler->getFragments()) {

		int elements = 0;
		std::string new_data;
		float avR, avB, avG, avL, avV;
		unsigned long long int R, B, G;
		float L, V;
		R = B = G = L = V = 0;
		float cmax, cmin;

		for (int i = 0; i < frag.GetWidth(); ++i) {
			for (int j = 0; j < frag.GetHeight(); ++j) {

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
		
		float sdR, sdG, sdB, sdL, sdV;
		sdR = sdG = sdB = sdL = sdV = 0;
		for (int i = 0; i < frag.GetWidth(); ++i) {
			for (int j = 0; j < frag.GetHeight(); ++j) {

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

		sdR = sqrt(sdR) * 100 / 255;
		sdB = sqrt(sdB) * 100 / 255;
		sdG = sqrt(sdG) * 100 / 255;
		sdL = sqrt(sdL) * 100;
		sdV = sqrt(sdV) * 100;

		new_data += "Fragment ";
		new_data += std::to_string(i);
		str_arr.Add(wxString(new_data));

		std::stringstream stream_avR, stream_avB, stream_avG,
			stream_avV, stream_avL, stream_sdR, stream_sdB,
			stream_sdG, stream_sdV, stream_sdL;

		new_data = "srednie:               R:";
		stream_avR << std::fixed << std::setprecision(2) << avR;
		new_data += stream_avR.str();

		new_data += ", G:";
		stream_avG << std::fixed << std::setprecision(2) << avG;
		new_data += stream_avG.str();

		new_data += ", B:";
		stream_avB << std::fixed << std::setprecision(2) << avB;
		new_data += stream_avB.str();

		new_data += ", L:";
		stream_avL << std::fixed << std::setprecision(2) << avL;
		new_data += stream_avL.str();

		new_data += ", V:";
		stream_avV << std::fixed << std::setprecision(2) << avV;
		new_data += stream_avV.str();

		str_arr.Add(wxString(new_data));

		new_data = "odchyl. stand.: R:";
		stream_sdR << std::fixed << std::setprecision(2) << sdR;
		new_data += stream_sdR.str();

		new_data += "%, G:";
		stream_sdG << std::fixed << std::setprecision(2) << sdG;
		new_data += stream_sdG.str();

		new_data += "%, B:";
		stream_sdB << std::fixed << std::setprecision(2) << sdB;
		new_data += stream_sdB.str();
		
		new_data += "%, L:";
		stream_sdL << std::fixed << std::setprecision(2) << sdL;
		new_data += stream_sdL.str();

		new_data += "%, V:";
		stream_sdV << std::fixed << std::setprecision(2) << sdV;
		new_data += stream_sdV.str();
		
		new_data += "%";
		str_arr.Add(wxString(new_data));

		new_data = "--------";
		str_arr.Add(wxString(new_data));

		++i;
	}
	if (!m_imageHandler->getFragments().empty()) {
		listBox->InsertItems(str_arr, listBox->GetCount());
	}

}


void InfoFrame::update() {

	while (listBox->GetCount()) {
		listBox->Delete(listBox->GetCount() - 1);
	};

	readData();

}

float InfoFrame::max(float a, float b, float c) const {
	return a > b ? (a > c ? a : c) : (b > c ? b : c);
}

float InfoFrame::min(float a, float b, float c) const {
	return a < b ? (a < c ? a : c) : (b < c ? b : c);
}

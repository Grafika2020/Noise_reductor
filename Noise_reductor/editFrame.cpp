#include "editFrame.h"
#include <wx/dcbuffer.h>
#include "CImg.h"
#include <iostream>


EditFrame::EditFrame(wxWindow* parent, ImageHandler *imageHandler, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxFrame(parent, id, title, pos, size, style),m_imageHandler(imageHandler)
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

	imageOrginal = new SynchronizedWindow(this, imageOrginalID, wxDefaultPosition, wxDefaultSize, wxHSCROLL | wxVSCROLL);
	imageOrginal->SetScrollRate(5, 5);
	imageOrginal->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNHIGHLIGHT));

	sizer3chosenFragment->Add(imageOrginal, 1, wxEXPAND | wxALL, 5);

	imageModified = new SynchronizedWindow(this, imageModifiedID, wxDefaultPosition, wxDefaultSize, wxHSCROLL | wxVSCROLL);
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

	wxString selectRepresentationChoices[] = { wxT("RGB"), wxT("HSL"), wxT("HSV") };
	int selectRepresentationNChoices = sizeof(selectRepresentationChoices) / sizeof(wxString);
	selectRepresentation = new wxRadioBox(this, wxID_ANY, wxT("RGB"), wxDefaultPosition, wxDefaultSize, selectRepresentationNChoices, selectRepresentationChoices, 1, wxRA_SPECIFY_ROWS);
	selectRepresentation->SetSelection(0);
	sizer3modifyFragemtns->Add(selectRepresentation, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

	wxString selectRGBChoices[] = { wxT("R"), wxT("G"), wxT("B") };
	int selectRGBNChoices = sizeof(selectRGBChoices) / sizeof(wxString);
	selectRGB = new wxRadioBox(this, wxID_ANY, wxT("RGB"), wxDefaultPosition, wxDefaultSize, selectRGBNChoices, selectRGBChoices, 1, wxRA_SPECIFY_ROWS);
	selectRGB->SetSelection(0);
	sizer3modifyFragemtns->Add(selectRGB, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

	wxString selectHSLChoices[] = { wxT("L") };
	int selectHSLNChoices = sizeof(selectHSLChoices) / sizeof(wxString);
	selectHSL = new wxRadioBox(this, wxID_ANY, wxT("HSL"), wxDefaultPosition, wxDefaultSize, selectHSLNChoices, selectHSLChoices, 1, wxRA_SPECIFY_COLS);
	selectHSL->SetSelection(0);
	sizer3modifyFragemtns->Add(selectHSL, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);
	selectHSL->Enable(false);

	wxString selectHSVChoices[] = { wxT("V") };
	int selectHSVNChoices = sizeof(selectHSVChoices) / sizeof(wxString);
	selectHSV = new wxRadioBox(this, wxID_ANY, wxT("HSV"), wxDefaultPosition, wxDefaultSize, selectHSVNChoices, selectHSVChoices, 1, wxRA_SPECIFY_COLS);
	selectHSV->SetSelection(0);
	sizer3modifyFragemtns->Add(selectHSV, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);
	selectHSV->Enable(false);

	wxBoxSizer* sizer3suwaki;
	sizer3suwaki = new wxBoxSizer(wxVERTICAL);

	slider1 = new wxSlider(this, wxID_ANY, 0, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL);
	sizer3modifyFragemtns->Add(slider1, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

	startButton = new wxButton(this, wxID_ANY, wxT("Odszumiaj"), wxDefaultPosition, wxDefaultSize, 0);
	sizer3modifyFragemtns->Add(startButton, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

	//sizer3modifyFragemtns->Add(sizer3suwaki, 0, wxALIGN_CENTER_VERTICAL, 5);


	sizer3modifyFragemtns->Add(0, 0, 1, wxEXPAND, 5);


	sizer3main->Add(sizer3modifyFragemtns, 1, wxEXPAND, 5);


	this->SetSizer(sizer3main);
	this->Layout();

	this->Centre(wxBOTH);

	startButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EditFrame::gausssian_blur), NULL, this);
	this->Connect(wxEVT_CLOSE_WINDOW, wxCloseEventHandler(EditFrame::OnClose));
	this->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(EditFrame::OnUpdateUI));
	this->Connect(wxEVT_RADIOBOX, wxCommandEventHandler(EditFrame::OnRadioBox));
	//Bind(wxEVT_RADIOBOX, EditFrame::OnRadioBox);

}

EditFrame::~EditFrame()
{
	//To do deleting all objects

	//Disconnect events
	startButton->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(EditFrame::gausssian_blur), NULL, this);
	this->Disconnect(wxEVT_CLOSE_WINDOW, wxCloseEventHandler(EditFrame::OnClose));
	this->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(EditFrame::OnUpdateUI));
}

void EditFrame::gausssian_blur(wxCommandEvent& event)
{
	int  sigma = slider1->GetValue();
	
	wxSize visible_area = imageModified->GetClientSize();
	wxPoint start_of_view = imageModified->GetViewStart();
	wxImage original_img = m_imageHandler->getMainImage();

	wxImage image_to_mod = m_imageHandler->getModifiedImage();
	if (visible_area.GetWidth() > image_to_mod.GetWidth()) {
		visible_area.SetWidth(image_to_mod.GetWidth());
	}
	if (visible_area.GetHeight() > image_to_mod.GetHeight()) {
		visible_area.SetHeight(image_to_mod.GetHeight());
	}
	

	int col_repr = selectRepresentation->GetSelection();
	int channel = 0;
	switch (col_repr)
	{
	case 0:
		channel = selectRGB->GetSelection();
		blur_RGB(sigma, channel, visible_area, start_of_view, image_to_mod, original_img);
		break;
	case 1:
		channel = selectHSL->GetSelection();
		m_imageHandler->setModifiedImage(original_img);
		break;
	case 2:
		m_imageHandler->setModifiedImage(original_img);
		channel = selectHSV->GetSelection();
		break;
	default:
		break;
	}
	draw();
}

void EditFrame::blur_RGB(int sigma, int channel, wxSize visible_area, wxPoint start_of_view, wxImage image_to_mod, wxImage original_img)
{
	cimg_library::CImg<unsigned char> image_to_blur(visible_area.GetWidth(), visible_area.GetHeight(), 1, 3);
	const int x = start_of_view.x;
	const int y = start_of_view.y;
	
	if (channel == 0) {
		for (int i = 0; i < visible_area.GetWidth(); i++) {
			for (int j = 0; j < visible_area.GetHeight(); j++) {
				image_to_blur(i, j, 0) = original_img.GetRed(x+i, y+j);
				image_to_blur(i, j, 1) = 0;
				image_to_blur(i, j, 2) = 0;
			}
		}
		image_to_blur.blur(sigma);

		for (int i = 0; i < visible_area.GetWidth(); i++) {
			for (int j = 0; j < visible_area.GetHeight(); j++) {
				unsigned char gr = image_to_mod.GetGreen(x + i, y + j);
				unsigned char bl = image_to_mod.GetBlue(x + i, y + j);
				image_to_mod.SetRGB(x + i, y + j, image_to_blur(i, j, 0), gr, bl);
			}
		}
	}
	
	if (channel == 1) {
		for (int i = 0; i < visible_area.GetWidth(); i++) {
			for (int j = 0; j < visible_area.GetHeight(); j++) {
				image_to_blur(i, j, 0) = 0;
				image_to_blur(i, j, 1) = image_to_mod.GetGreen(x + i, y + j);
				image_to_blur(i, j, 2) = 0;
			}
		}
		image_to_blur.blur(sigma);

		for (int i = 0; i < visible_area.GetWidth(); i++) {
			for (int j = 0; j < visible_area.GetHeight(); j++) {
				unsigned char r = image_to_mod.GetRed(x + i, y + j);
				unsigned char bl = image_to_mod.GetBlue(x + i, y + j);
				image_to_mod.SetRGB(x + i, y + j,r, image_to_blur(i, j, 1), bl);
			}
		}
	}
	
	if (channel == 2) {
		for (int i = 0; i < visible_area.GetWidth(); i++) {
			for (int j = 0; j < visible_area.GetHeight(); j++) {
				image_to_blur(i, j, 0) = 0;
				image_to_blur(i, j, 1) = 0;
				image_to_blur(i, j, 2) = image_to_mod.GetBlue(x + i, y + j);
			}
		}
		image_to_blur.blur(sigma);

		for (int i = 0; i < visible_area.GetWidth(); i++) {
			for (int j = 0; j < visible_area.GetHeight(); j++) {
				unsigned char gr = image_to_mod.GetGreen(x + i, y + j);
				unsigned char r = image_to_mod.GetRed(x + i, y + j);
				image_to_mod.SetRGB(x + i, y + j, r, gr, image_to_blur(i, j, 2));
			}
		}
	}
	
	m_imageHandler->setModifiedImage(image_to_mod);
}

void EditFrame::blur_HSL()
{
}

void EditFrame::blur_HSV()
{
}

void EditFrame::OnClose(wxCloseEvent & evt)
{
	GetParent()->Destroy();
}

void EditFrame::OnUpdateUI(wxUpdateUIEvent & evt)
{
	draw();
}

void EditFrame::OnRadioBox(wxCommandEvent & evt)
{
	int selection = selectRepresentation->GetSelection();

	if (selection!=m_lastselected) {
		//m_imageHandler->resetImage(); tego nie ma a musi byæ napisane
		if (selection == 0) {
			selectRGB->Enable(true);
			selectHSL->Enable(false);
			selectHSV->Enable(false);
		}
		else if (selection == 1) {
			selectRGB->Enable(false);
			selectHSL->Enable(true);
			selectHSV->Enable(false);
		}
		else {
			selectRGB->Enable(false);
			selectHSL->Enable(false);
			selectHSV->Enable(true);
		} 
		m_lastselected = selection;
	}
	

}

void EditFrame::OnScroll(wxWindowID id, int x, int y)
{
	if (id ==imageOrginalID) imageModified->Scroll(x, y);
	if (id == imageModifiedID) imageOrginal->Scroll(x, y);
}



void EditFrame::draw()
{
	
		wxClientDC clientDCOriginal(imageOrginal);
		wxClientDC clientDCModified(imageModified);
		wxBufferedDC buffOriginal(&clientDCOriginal);
		wxBufferedDC buffModified(&clientDCModified);


		imageOrginal->SetVirtualSize(m_imageHandler->getMainImage().GetSize());
		imageModified->SetVirtualSize(m_imageHandler->getModifiedImage().GetSize());

		imageOrginal->DoPrepareDC(buffOriginal);
		imageModified->DoPrepareDC(buffModified);

		wxBitmap bmpOri(m_imageHandler->getMainImage());
		wxBitmap bmpMod(m_imageHandler->getModifiedImage());

		buffOriginal.DrawBitmap(bmpOri, wxPoint(0, 0));
		buffModified.DrawBitmap(bmpMod, wxPoint(0, 0));
	
}



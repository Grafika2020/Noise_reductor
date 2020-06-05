#include "initFrame.h"
#include <wx/dcbuffer.h>
#include <wx/msgdlg.h>

InitFrame::InitFrame(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxFrame(parent, id, title, pos, size, style)
{
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);

	wxBoxSizer* sizer1init;
	sizer1init = new wxBoxSizer(wxHORIZONTAL);

	wxBoxSizer* sizer2init;
	sizer2init = new wxBoxSizer(wxVERTICAL);

	loadedImagePanel = new wxScrolledWindow(this, wxID_ANY, wxDefaultPosition, wxSize(1, 1), wxHSCROLL | wxVSCROLL);
	loadedImagePanel->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHTTEXT));
	loadedImagePanel->SetScrollbars(25, 25, 20, 20);
	loadedImagePanel->SetScrollRate(5, 5);
	sizer2init->Add(loadedImagePanel, 1, wxEXPAND | wxALL, 5);

	line1 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
	sizer2init->Add(line1, 0, wxEXPAND | wxALL, 5);

	wxBoxSizer* blackFrameSizer;
	blackFrameSizer = new wxBoxSizer(wxHORIZONTAL);
	blackFrameSizer->Add(0, 0, 1, wxEXPAND, 5);

	addBlackImageButton = new wxButton(this, wxID_ANY, wxT("Dodaj czarn¹ klatkê"), wxDefaultPosition, wxDefaultSize, 0);
	blackFrameSizer->Add(addBlackImageButton, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

	wxBoxSizer* sizerSuwak;
	sizerSuwak = new wxBoxSizer(wxVERTICAL);
	sizerSuwak->Add(0, 0, 1, wxEXPAND, 5);

	sliderDesc = new wxStaticText(this, wxID_ANY, wxT("Ustaw wspó³czynnik klatki"), wxDefaultPosition, wxDefaultSize);
	sliderDesc->Wrap(-1);
	sizerSuwak->Add(sliderDesc, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 2);


	slider = new wxSlider(this, wxID_ANY, 0, 0, 10, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL);
	slider->Enable(false);
	sizerSuwak->Add(slider, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 2);


	sliderVal = new wxStaticText(this, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize);
	sliderVal->Wrap(-1);
	sizerSuwak->Add(sliderVal, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 2);
	
	blackFrameSizer->Add(sizerSuwak, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);
	
	substractFrame = new wxButton(this, wxID_ANY, wxT("Odejmij"), wxDefaultPosition, wxDefaultSize, 0);
	substractFrame->Enable(false);
	blackFrameSizer->Add(substractFrame, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);



	blackFrameSizer->Add(0, 0, 1, wxEXPAND, 5);

	sizer2init->Add(blackFrameSizer, 0, wxEXPAND, 5);


	finishButton = new wxButton(this, wxID_ANY, wxT("Gotowe"), wxDefaultPosition, wxDefaultSize, 0);
	sizer2init->Add(finishButton, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);


	sizer1init->Add(sizer2init, 3, wxEXPAND, 5);

	line2 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL);
	sizer1init->Add(line2, 0, wxEXPAND | wxALL, 5);

	wxBoxSizer* sizer3init;
	sizer3init = new wxBoxSizer(wxVERTICAL);

	framesDescription = new wxStaticText(this, wxID_ANY, wxT("wybrano 0 fragmentów:"), wxDefaultPosition, wxDefaultSize, 0);
	framesDescription->Wrap(-1);
	sizer3init->Add(framesDescription, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

	framesList = new wxListBox(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0);
	sizer3init->Add(framesList, 1, wxALL | wxEXPAND, 5);


	sizer1init->Add(sizer3init, 1, wxEXPAND | wxALIGN_CENTER_VERTICAL, 5);

	this->SetSizer(sizer1init);
	this->Layout();

	this->Centre(wxBOTH);

	m_imageHandler = new ImageHandler;
	// Connect Events
	loadedImagePanel->Connect(wxEVT_SCROLLBAR, wxScrollEventHandler(InitFrame::OnScroll), NULL, this);
	addBlackImageButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(InitFrame::addBlackImage), NULL, this);
	substractFrame->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(InitFrame::substract), NULL, this);
	finishButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(InitFrame::openFrames), NULL, this);
	this->Connect(wxEVT_CLOSE_WINDOW, wxCloseEventHandler(InitFrame::OnClose),NULL,this);
	this->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(InitFrame::OnUpdateUI),NULL,this);
	loadedImagePanel->Connect(wxEVT_MOTION, wxMouseEventHandler(InitFrame::addFrag), NULL, this);
	loadedImagePanel->Connect(wxEVT_LEFT_DOWN, wxMouseEventHandler(InitFrame::addFrag), NULL, this);
	loadedImagePanel->Connect(wxEVT_LEFT_UP, wxMouseEventHandler(InitFrame::addFrag), NULL, this);
	OnShow();
}

InitFrame::~InitFrame()
{
	delete m_imageHandler;
	// Disconnect Events
	addBlackImageButton->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(InitFrame::addBlackImage), NULL, this);
	substractFrame->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(InitFrame::substract), NULL, this);
	loadedImagePanel->Disconnect(wxEVT_SCROLLBAR, wxScrollEventHandler(InitFrame::OnScroll), NULL, this);
	loadedImagePanel->Disconnect(wxEVT_MOTION, wxMouseEventHandler(InitFrame::addFrag), NULL, this);
	loadedImagePanel->Disconnect(wxEVT_LEFT_DOWN, wxMouseEventHandler(InitFrame::addFrag), NULL, this);
	loadedImagePanel->Disconnect(wxEVT_LEFT_UP, wxMouseEventHandler(InitFrame::addFrag), NULL, this);
	finishButton->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(InitFrame::openFrames), NULL, this);
	this->Disconnect(wxEVT_CLOSE_WINDOW, wxCloseEventHandler(InitFrame::OnClose), NULL, this);
	this->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(InitFrame::OnUpdateUI), NULL, this);
}

void InitFrame::OnClose(wxCloseEvent & evt)
{
	Destroy();
}

void InitFrame::OnShow()
{
	wxInitAllImageHandlers();
	
	wxFileDialog Dialog(this, wxT("Wybierz plik"), wxT(""), wxT(""), wxT("Pictures (*.jpg, *.bmp)|*.jpg; *.bmp"), wxFD_OPEN | wxFD_FILE_MUST_EXIST);

	if (Dialog.ShowModal() == wxID_OK) {
		m_imageHandler->setImage(Dialog.GetPath());
	}

	draw();


}

void InitFrame::OnScroll(wxScrollEvent & evt)
{
	draw();
}

void InitFrame::OnUpdateUI(wxUpdateUIEvent & evt)
{
	draw();
	
}

void InitFrame::setSliderLabel()
{
	int val = slider->GetValue();
	int a = val / 10;
	int b = val % 10;
	wxString str = std::to_string(a) + "." + std::to_string(b);
	sliderVal->SetLabel(str);
}


void InitFrame::draw()
{
	if (m_imageHandler->getMainImage().IsOk()) {
		wxClientDC clientDC(loadedImagePanel);
		wxBufferedDC buff(&clientDC);

		wxSize imageSize = m_imageHandler->getMainImage().GetSize();

		loadedImagePanel->SetVirtualSize(imageSize);

		wxPoint imgStart = loadedImagePanel->CalcUnscrolledPosition(wxPoint(0, 0));
		wxSize imgSize = loadedImagePanel->GetSize();
		if (imgSize.GetWidth() > imageSize.GetWidth() - imgStart.x) {
			imgSize.SetWidth(imageSize.GetWidth() - imgStart.x);
		}
		if (imgSize.GetHeight() > imageSize.GetHeight() - imgStart.y) {
			imgSize.SetHeight(imageSize.GetHeight() - imgStart.y);
		}

		loadedImagePanel->DoPrepareDC(buff);

		wxBitmap bmp(m_imageHandler->getMainImage().GetSubImage(wxRect(imgStart, imgSize)));
		buff.DrawBitmap(bmp, imgStart);
		
		wxSize img_size = m_imageHandler->getMainImage().GetSize();
		buff.SetBrush(*wxTRANSPARENT_BRUSH);
		buff.SetPen(wxPen(wxColour(35, 35, 35), 3));
		if (!frags_cord.empty() && frags_cord.size() % 2 == 0) {
			for (unsigned i = 0; i < frags_cord.size(); i += 2) {
				int j = i + 1;
				buff.DrawRectangle(wxRect(frags_cord[i], frags_cord[j]));
			}

		}
		if (marking && moving_cursor.y < img_size.GetHeight() && moving_cursor.x < img_size.GetWidth()) {
			buff.DrawRectangle(wxRect(first_click, moving_cursor));
		}
	}
	else {
		Close(true);
	}
	
	
	setSliderLabel();
}

void InitFrame::addFrag(wxMouseEvent& event)
{
	windowMoved = loadedImagePanel->CalcUnscrolledPosition(wxPoint(0, 0));
	if (event.LeftDown()) {
		initFlag = true;
		first_click = event.GetPosition();
		first_click += windowMoved;
		frags_cord.push_back(first_click);
	}
	if (event.Dragging() && initFlag) {
		moving_cursor = event.GetPosition();
		moving_cursor += windowMoved;
		marking = true;
	}
	if (event.LeftUp() && initFlag) {
		second_click = event.GetPosition();
		second_click += windowMoved;
		wxSize img_size = m_imageHandler->getMainImage().GetSize();
		if (second_click.y <= img_size.GetHeight()&& second_click.x <= img_size.GetWidth()){
			marking = false;
			frags_cord.push_back(second_click);
			wxImage tmp_frag = m_imageHandler->getMainImage().GetSubImage(wxRect(first_click,second_click));
			m_imageHandler->frag_pos1.push_back(first_click);
			m_imageHandler->frag_pos2.push_back(second_click);

			m_imageHandler->getFragments().push_back(tmp_frag);

			framesDescription->SetLabel(wxString::Format(wxT("wybrano %i fragmentów:"), ++frag_num));
			wxArrayString description_arr;
			wxString tmp_str = wxString::Format(wxT("(%i, %i),(%i, %i)"), first_click.x, first_click.y, second_click.x, second_click.y);
			description_arr.Add(tmp_str);
			framesList->InsertItems(description_arr, framesList->GetCount());
		}
		
	}

}

void InitFrame::addBlackImage(wxCommandEvent & evt)
{
	wxInitAllImageHandlers();

	wxFileDialog Dialog(this, wxT("Wybierz plik"), wxT(""), wxT(""), wxT("Pictures (*.jpg, *.bmp)|*.jpg; *.bmp"), wxFD_OPEN | wxFD_FILE_MUST_EXIST);
	wxImage blackImage;
	if (Dialog.ShowModal() == wxID_OK) {
		blackImage.LoadFile(Dialog.GetPath(), wxBITMAP_TYPE_ANY);
	}
	if (blackImage.GetSize() != m_imageHandler->getMainImage().GetSize()) {
		wxString msg;
		if (blackImage.GetSize() == wxSize(0, 0)) {
			msg = "Nie podano obrazu";
		}
		else {
			msg = "B³êdny rozmiar klatki \n Czarna klatka musi mieæ rozmiar g³ównego obrazu.";
		}
		wxMessageDialog message(this, msg, wxT("B³¹d ³adowania klatki"), wxOK);
		message.ShowModal();
			
	}
	else {
		m_imageHandler->setBlackImage(blackImage);
		wxString msg;
		msg = "Klatka zosta³a dodana poprawnie";
		wxMessageDialog message(this, msg, wxT("Sukces"), wxOK);
		message.ShowModal();
		substractFrame->Enable(true);
		slider->Enable(true);
	}
	


}

void InitFrame::substract(wxCommandEvent & evt)
{
	float level = slider->GetValue()/10.0;
	m_imageHandler->substractBlackImage(level);
	
}

void InitFrame::openFrames( wxCommandEvent& event )
{

	InfoFrame* infoFrame = new InfoFrame(this, m_imageHandler,wxID_ANY,wxString("Informacje o obrazie"),wxDefaultPosition,wxSize(400,600), wxDEFAULT_FRAME_STYLE);
	EditFrame* editFrame = new EditFrame(this, infoFrame, m_imageHandler, wxID_ANY, wxString("Edytuj obraz"), wxDefaultPosition, wxSize(900, 600), wxDEFAULT_FRAME_STYLE);
	editFrame->Show();
	infoFrame->Show();
	this->Hide();
	
}

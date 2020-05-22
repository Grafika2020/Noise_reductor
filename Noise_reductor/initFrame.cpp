#include "initFrame.h"
#include <wx/dcbuffer.h>

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

	finishButton = new wxButton(this, wxID_ANY, wxT("Gotowe"), wxDefaultPosition, wxDefaultSize, 0);
	sizer2init->Add(finishButton, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);


	sizer1init->Add(sizer2init, 3, wxEXPAND, 5);

	line2 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL);
	sizer1init->Add(line2, 0, wxEXPAND | wxALL, 5);

	wxBoxSizer* sizer3init;
	sizer3init = new wxBoxSizer(wxVERTICAL);

	framesDescription = new wxStaticText(this, wxID_ANY, wxT("wybrano X fragmentów:"), wxDefaultPosition, wxDefaultSize, 0);
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
	finishButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(InitFrame::openFrames), NULL, this);
	this->Connect(wxEVT_CLOSE_WINDOW, wxCloseEventHandler(InitFrame::OnClose),NULL,this);
	this->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(InitFrame::OnUpdateUI),NULL,this);
	OnShow();
}

InitFrame::~InitFrame()
{
	delete m_imageHandler;
	// Disconnect Events
	loadedImagePanel->Disconnect(wxEVT_SCROLLBAR, wxScrollEventHandler(InitFrame::OnScroll), NULL, this);
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



void InitFrame::draw()
{
	wxClientDC clientDC(loadedImagePanel);
	wxBufferedDC buff(&clientDC);
	
	loadedImagePanel->SetVirtualSize(m_imageHandler->getMainImage().GetSize());
	
	loadedImagePanel->DoPrepareDC(buff);
	
	wxBitmap bmp(m_imageHandler->getMainImage());
	buff.DrawBitmap(bmp, wxPoint(0, 0));
}

void InitFrame::openFrames( wxCommandEvent& event )
{
// TODO: Implement openFrames
	wxFrame* infoFrame = new InfoFrame(this);
	wxFrame* editFrame = new EditFrame(this, m_imageHandler);
	editFrame->Show();
	infoFrame->Show();
	this->Hide();
	
}

#include "initFrame.h"

InitFrame::InitFrame(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxFrame(parent, id, title, pos, size, style)
{
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);

	wxBoxSizer* sizer1init;
	sizer1init = new wxBoxSizer(wxHORIZONTAL);

	wxBoxSizer* sizer2init;
	sizer2init = new wxBoxSizer(wxVERTICAL);

	loadedImagePanel = new wxScrolledWindow(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	loadedImagePanel->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHTTEXT));
	// loadedImagePanel->SetVirtualSize(3000, 3000);
	loadedImagePanel->SetScrollRate(1, 1);

	sizer2init->Add(loadedImagePanel, 1, wxEXPAND | wxALL, 5);

	line1 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
	sizer2init->Add(line1, 0, wxEXPAND | wxALL, 5);

	finishButton = new wxButton(this, wxID_ANY, wxT("Gotowe"), wxDefaultPosition, wxDefaultSize, 0);
	sizer2init->Add(finishButton, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);
	loadButton = new wxButton(this, wxID_ANY, wxT("Obrazek"), wxDefaultPosition, wxDefaultSize, 0);
	sizer2init->Add(loadButton, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

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


	// Connect Events
	finishButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(InitFrame::openFrames), NULL, this);
	loadButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(InitFrame::loadImage), NULL, this);

}

InitFrame::~InitFrame()
{
	// Disconnect Events
	finishButton->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(InitFrame::openFrames), NULL, this);
	loadButton->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(InitFrame::loadImage), NULL, this);

}

void InitFrame::openFrames( wxCommandEvent& event )
{

	wxFrame* infoFrame = new InfoFrame(NULL);
	wxFrame* editFrame = new EditFrame(NULL);
	editFrame->Show();
	infoFrame->Show();
	this->Close();

}

void InitFrame::loadImage(wxCommandEvent& event) {

	wxClientDC dc(loadedImagePanel);
	wxBufferedDC bdc(&dc);
	loadedImagePanel->DoPrepareDC(bdc);
	image.LoadFile("file.PNG", wxBITMAP_TYPE_ANY);
	loadedImagePanel->SetVirtualSize(image.GetWidth(), image.GetHeight());
	bdc.DrawBitmap(image, 0, 0);

}

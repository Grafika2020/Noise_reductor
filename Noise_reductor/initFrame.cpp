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
	finishButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(InitFrame::openFrames), NULL, this);
	this->Connect(wxEVT_CLOSE_WINDOW, wxCloseEventHandler(InitFrame::OnClose),NULL,this);
	this->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(InitFrame::OnUpdateUI),NULL,this);
	loadedImagePanel->Connect(wxEVT_MOTION, wxMouseEventHandler(InitFrame::add_frag), NULL, this);
	loadedImagePanel->Connect(wxEVT_LEFT_DOWN, wxMouseEventHandler(InitFrame::add_frag), NULL, this);
	loadedImagePanel->Connect(wxEVT_LEFT_UP, wxMouseEventHandler(InitFrame::add_frag), NULL, this);
	OnShow();
}

InitFrame::~InitFrame()
{
	delete m_imageHandler;
	// Disconnect Events
	loadedImagePanel->Disconnect(wxEVT_SCROLLBAR, wxScrollEventHandler(InitFrame::OnScroll), NULL, this);
	loadedImagePanel->Disconnect(wxEVT_MOTION, wxMouseEventHandler(InitFrame::add_frag), NULL, this);
	loadedImagePanel->Disconnect(wxEVT_LEFT_DOWN, wxMouseEventHandler(InitFrame::add_frag), NULL, this);
	loadedImagePanel->Disconnect(wxEVT_LEFT_UP, wxMouseEventHandler(InitFrame::add_frag), NULL, this);
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
	if (m_imageHandler->getMainImage().IsOk()) {
		wxClientDC clientDC(loadedImagePanel);
		wxBufferedDC buff(&clientDC);

		loadedImagePanel->SetVirtualSize(m_imageHandler->getMainImage().GetSize());

		loadedImagePanel->DoPrepareDC(buff);

		wxBitmap bmp(m_imageHandler->getMainImage());
		buff.DrawBitmap(bmp, wxPoint(0, 0));
		wxSize img_size = m_imageHandler->getMainImage().GetSize();
		buff.SetBrush(*wxTRANSPARENT_BRUSH);
		buff.SetPen(wxPen(wxColour(160, 75, 75), 5));
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
	
	
	
}

void InitFrame::add_frag(wxMouseEvent& event)
{
	windowMoved = loadedImagePanel->CalcUnscrolledPosition(wxPoint(0, 0));
	if (event.LeftDown()) {
		/*first_click = wxGetMousePosition();*/
		first_click = event.GetPosition();
		first_click += windowMoved;
		frags_cord.push_back(first_click);
	}
	if (event.Dragging()) {
		moving_cursor = event.GetPosition();
		moving_cursor += windowMoved;
		marking = true;
	}
	if (event.LeftUp()) {
		second_click = event.GetPosition();
		
		second_click += windowMoved;
		wxSize img_size = m_imageHandler->getMainImage().GetSize();
		if (second_click.y <= img_size.GetHeight()&& second_click.x <= img_size.GetWidth()){
			marking = false;
			frags_cord.push_back(second_click);
			wxImage tmp_frag = m_imageHandler->getMainImage().GetSubImage(wxRect(first_click,second_click));
			m_imageHandler->getFragments().push_back(tmp_frag);

			framesDescription->SetLabel(wxString::Format(wxT("wybrano %i fragmentów:"), ++frag_num));

			wxArrayString description_arr;
			wxString tmp_str = wxString::Format(wxT("(%i, %i),(%i, %i)"), first_click.x, first_click.y, second_click.x, second_click.y);
			description_arr.Add(tmp_str);
			framesList->InsertItems(description_arr, framesList->GetCount());
		}
		
	}

}

void InitFrame::openFrames( wxCommandEvent& event )
{
// TODO: Implement openFrames
	wxFrame* infoFrame = new InfoFrame(this, m_imageHandler);
	wxFrame* editFrame = new EditFrame(this, m_imageHandler);
	editFrame->Show();
	infoFrame->Show();
	this->Hide();
	
}

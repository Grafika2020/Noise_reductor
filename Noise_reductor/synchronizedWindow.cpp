#include "synchronizedWindow.h"
#include "editFrame.h"

IMPLEMENT_DYNAMIC_CLASS(SynchronizedWindow, wxScrolledWindow)

BEGIN_EVENT_TABLE(SynchronizedWindow, wxScrolledWindow)
EVT_SCROLLWIN_THUMBRELEASE(SynchronizedWindow::OnScroll)
EVT_SCROLLWIN_LINEDOWN(SynchronizedWindow::OnScrollDown)
EVT_SCROLLWIN_LINEUP(SynchronizedWindow::OnScrollUp)

END_EVENT_TABLE()

SynchronizedWindow::SynchronizedWindow(wxWindow *parent, wxWindowID id, const wxPoint &pos, const wxSize &size, long style)
	: wxScrolledWindow(parent, id, pos, size, style)
{

}


void SynchronizedWindow::OnScroll(wxScrollWinEvent& event) {
	event.Skip();

	int x, y;
	x = y = 50;
	int *xp = &x;
	int *yp = &y;

	GetViewStart(xp, yp);

	EditFrame* parent = (EditFrame*)GetParent();

	if (parent) {
		parent->OnScroll(GetId(), x, y);
	}

}

void SynchronizedWindow::OnScrollDown(wxScrollWinEvent &event)
{
	event.Skip();
	int x, y;
	x = y = 50;
	GetViewStart(&x, &y);
	EditFrame* parent = (EditFrame*)GetParent();
	if (parent) {
		if (event.GetOrientation() == wxHORIZONTAL) {

			parent->OnScroll(GetId(),x+1, y);
		}
		if (event.GetOrientation() == wxVERTICAL) {

			parent->OnScroll(GetId(),x, y+1);
		}
	
	}

}

void SynchronizedWindow::OnScrollUp(wxScrollWinEvent & event)
{
	event.Skip();
	int x, y;
	x = y = 50;
	GetViewStart(&x, &y);
	EditFrame* parent = (EditFrame*)GetParent();
	if (parent) {
		if (event.GetOrientation() == wxHORIZONTAL) {

			parent->OnScroll(GetId(), x - 1, y);
		}
		if (event.GetOrientation() == wxVERTICAL) {

			parent->OnScroll(GetId(), x, y - 1);
		}

	}
}

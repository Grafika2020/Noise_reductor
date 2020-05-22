#pragma once
#include "wx/scrolwin.h"


class SynchronizedWindow : public wxScrolledWindow
{
public:
	SynchronizedWindow() = default;
	SynchronizedWindow(wxWindow *parent, wxWindowID id, const wxPoint &pos, const wxSize &size, long style);

	//this is called by the event table and in turn calls MyFrame::OnScroll
	void OnScroll(wxScrollWinEvent& event);
	void OnScrollDown(wxScrollWinEvent& event);
	void OnScrollUp(wxScrollWinEvent& event);
	DECLARE_DYNAMIC_CLASS(SynchronizedWindow)
	DECLARE_EVENT_TABLE()
};



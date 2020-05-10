#include "MyProject1MyFrame1.h"
#include "MyProject1MyFrame2.h"
#include "MyProject1MyFrame3.h"

MyProject1MyFrame1::MyProject1MyFrame1( wxWindow* parent )
:
MyFrame1( parent )
{

}

void MyProject1MyFrame1::openFrames( wxCommandEvent& event )
{
// TODO: Implement openFrames
	wxFrame* frame2 = new MyProject1MyFrame2(NULL);
	wxFrame* frame3 = new MyProject1MyFrame3(NULL);
	frame2->Show();
	frame3->Show();
	this->Hide();
}

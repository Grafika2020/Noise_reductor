#include "MyProject1MyFrame2.h"

MyProject1MyFrame2::MyProject1MyFrame2( wxWindow* parent )
:
MyFrame2( parent )
{

}

void MyProject1MyFrame2::closeInfo(wxCommandEvent& event)
{
	this->Close();
}

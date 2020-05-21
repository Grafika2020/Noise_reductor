#pragma once
#include <wx/image.h>



class ImageHandler {
public:
	ImageHandler() = default;
	void setImage(wxString filePath);
	const wxImage& getMainImage()const;
private: 
	wxImage m_mainImage;
};
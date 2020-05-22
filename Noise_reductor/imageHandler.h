#pragma once
#include <wx/image.h>
#include <iostream>


class ImageHandler {
public:
	ImageHandler() = default;
	~ImageHandler() {
		std::cout << "usuwanko";
	}
	void setImage(wxString filePath);
	const wxImage& getMainImage()const;
	const wxImage& getModifiedImage()const;
private: 
	wxImage m_mainImage;
	wxImage m_modifiedImage;
};
#pragma once
#include <wx/image.h>
#include <iostream>
#include<vector>

class ImageHandler {
public:
	ImageHandler() = default;
	~ImageHandler() {
		std::cout << "usuwanko";
	}
	void setImage(wxString filePath);
	const wxImage& getMainImage()const;
	wxImage& getModifiedImage();
	void setModifiedImage(wxImage img) {
		m_modifiedImage = img;
	}
	std::vector<wxImage>& getFragments() { return fragments; }
	
private: 
	wxImage m_mainImage;
	wxImage m_modifiedImage;
	std::vector<wxImage> fragments;
};
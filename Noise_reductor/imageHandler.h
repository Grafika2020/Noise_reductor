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
	const wxImage& getModifiedImage()const;
	std::vector<wxImage> getFragments()const { return fragments; }
	std::vector<wxImage> fragments;
private: 
	wxImage m_mainImage;
	wxImage m_modifiedImage;
	
};
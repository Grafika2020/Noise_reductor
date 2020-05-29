#pragma once
#include <wx/image.h>
#include <iostream>
#include<vector>

class ImageHandler {
public:
	ImageHandler() = default;
	~ImageHandler() {}
	void setImage(wxString filePath);
	const wxImage& getMainImage()const;
	wxImage& getModifiedImage();
	void setModifiedImage(wxImage img);
	void setBlackImage(wxImage img);
	bool substractBlackImage();
	bool isBlackImage()const;
	void resetModifiedImage();
	std::vector<wxImage>& getFragments();
	
private: 
	wxImage m_mainImage;
	wxImage m_modifiedImage;
	wxImage m_blackImage;
	bool blackImageStatus{ false };
	std::vector<wxImage> fragments;
};
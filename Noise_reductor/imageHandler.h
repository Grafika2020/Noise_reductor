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
	void substractBlackImage(float level=0.0);
	bool isBlackImage()const;
	void resetModifiedImage();
	void updateFragments();
	std::vector<wxImage>& getFragments();
	std::vector<wxPoint> frag_pos1;
	std::vector<wxPoint> frag_pos2;
	
private: 
	wxImage m_mainImage;
	wxImage m_modifiedImage;
	wxImage m_blackImage;
	bool blackImageStatus{ false };
	std::vector<wxImage> fragments;

};
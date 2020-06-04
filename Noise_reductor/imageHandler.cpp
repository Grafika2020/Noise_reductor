#include "imageHandler.h"
#include "CImg.h"




void ImageHandler::setImage(wxString filePath)
{
	m_mainImage.LoadFile(filePath, wxBITMAP_TYPE_ANY);
	m_modifiedImage.LoadFile(filePath, wxBITMAP_TYPE_ANY);
}

const wxImage & ImageHandler::getMainImage() const
{
	return m_mainImage;
}

wxImage & ImageHandler::getModifiedImage()
{
	return m_modifiedImage;
}

void ImageHandler::setModifiedImage(wxImage img)
{
	m_modifiedImage = img;
}

void ImageHandler::setBlackImage(wxImage img)
{
	m_blackImage = img;
	blackImageStatus = true;
}

void ImageHandler::substractBlackImage(float level)
{
	if (isBlackImage()) {
		for (int i = 0; i < m_mainImage.GetWidth(); i++) {
			for (int j = 0; j < m_mainImage.GetHeight(); j++) {
				int r = m_mainImage.GetRed(i, j) - level*m_blackImage.GetRed(i, j);
				int g = m_mainImage.GetGreen(i, j) - level*m_blackImage.GetGreen(i, j);
				int b = m_mainImage.GetBlue(i, j) - level*m_blackImage.GetBlue(i, j);

				r = (r >= 0) ? r : 0;
				g = (g >= 0) ? g : 0;
				b = (b >= 0) ? b : 0;
				m_mainImage.SetRGB(i, j, r, g, b);
			}
		}
		resetModifiedImage();
		
	}
	
	

}

bool ImageHandler::isBlackImage() const
{
	return blackImageStatus;
}

void ImageHandler::resetModifiedImage()
{
	m_modifiedImage = m_mainImage;
}

std::vector<wxImage>& ImageHandler::getFragments()
{
	return fragments;
}

void ImageHandler::updateFragments() {

	std::vector<wxImage> newFragments;
	for (int i = 0; i < fragments.size(); ++i) {
		wxImage tmp_frag = getModifiedImage().GetSubImage(wxRect(frag_pos1[i], frag_pos2[i]));
		newFragments.push_back(tmp_frag);
	}
	fragments = newFragments;
}

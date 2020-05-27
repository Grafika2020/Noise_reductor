#include "imageHandler.h"



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

void ImageHandler::resetModifiedImage()
{
	m_modifiedImage = m_mainImage;
}

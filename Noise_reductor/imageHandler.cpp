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

const wxImage & ImageHandler::getModifiedImage() const
{
	return m_modifiedImage;
}

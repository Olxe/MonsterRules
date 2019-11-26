#include "Image.h"

using namespace Builder;

Image::Image(std::string source, float width, float height)
	: m_source(source)
	, m_width(width)
	, m_height(height)
{
}

Image::~Image()
{
}
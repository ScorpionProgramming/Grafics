#include "RGBImage.h"

RGBImage::RGBImage(unsigned int Width, unsigned int Height)
{
	m_Width = Width;
	m_Height = Height;
	m_Image = new Color[Width * Height];
}

RGBImage::~RGBImage()
{
	delete m_Image;
}

void RGBImage::setPixelColor(unsigned int x, unsigned int y, const Color & c)
{
	if(x >= 0 && x <= m_Width && y >= 0 && y <= m_Height-1)
		m_Image[ x * m_Height + y ] = c;
}

const Color & RGBImage::getPixelColor(unsigned int x, unsigned int y) const
{
	if (x >= 0 && x <= m_Width && y >= 0 && y <= m_Height-1)
		return m_Image[ x * m_Height + y ];
}

bool RGBImage::saveToDist(const char * Filename)
{
	FILE *pFile;
	pFile = fopen(Filename, "W");

	if (pFile != NULL)
	{
		// TODO: here add bmp-data header 

		for (int i = 0; i < m_Width; i++) 
		{
			for (int j = 0; j < m_Height; j++) 
			{
				char r = this->convertColorChannel(this->getPixelColor(i, j).R);
				char g = this->convertColorChannel(this->getPixelColor(i, j).G);
				char b = this->convertColorChannel(this->getPixelColor(i, j).B);

				fputs(""+r, pFile);
				fputs("" + g, pFile);
				fputs("" + b, pFile);
			}
		}
	}
	fclose(pFile);

}

unsigned int RGBImage::width() const
{
	return m_Width;
}

unsigned int RGBImage::height() const
{
	return m_Height;
}

unsigned char RGBImage::convertColorChannel(float f)
{
	if (f < 0) 
	{
		f = 0.0f;
	}
	else if (f > 1.0f) 
	{
		f = 1.0f;
	}
	return f*255;
}

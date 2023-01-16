#pragma once

#include "../../GLFW Header.h"
#include <string>

class Texture
{
public:
	Texture(const std::string& path);
	~Texture();

	int getWidth() const;
	int getHeight() const;
private:
	unsigned int m_id;
	std::string m_filePath;
	unsigned char* m_localBuffer;
	int m_Width, m_Height, m_BPP;
};


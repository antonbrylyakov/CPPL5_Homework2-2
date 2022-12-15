#include "readText.h"


char* readText(std::istream& ifs, int& length)
{
	ifs.seekg(0, std::ios::end);
	length = ifs.tellg();
	ifs.seekg(0, std::ios::beg);
	char* buffer;
	buffer = new char[length];
	ifs.read(buffer, length);
	return buffer;
}
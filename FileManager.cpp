/*
 * FileManager.cpp
 *
 *  Created on: Jul 4, 2013
 *      Author: slacker
 */

#include "FileManager.h"


FileManager::FileManager()
{

}

FileManager::~FileManager()
{
}

void FileManager::LoadContent(const char* filename,
		std::vector<std::vector<std::string> >& attributes,
		std::vector<std::vector<std::string> >& contents)
{
	std::fstream openfile(filename);

	attributes.clear();
	contents.clear();

	if(openfile.is_open())
	{
		while(!openfile.eof())
		{
			std::string line;

			std::getline(openfile, line);

			std::remove(line.begin(), line.end(), ' ');

			if(line.find("Load=") != std::string::npos)
			{
				curState = ATTRIBUTES;
				line.erase(0, line.find('=') + 1);
				tempAttr.clear();
			}
			else
			{
				curState = CONTENTS;
				tempContents.clear();
			}

			line.erase(std::remove(line.begin(), line.end(), '['), line.end());

			// Erase comments, they start with #
			// only one line comments are accepted though
			if(line.find('#') != std::string::npos)
				line.erase(line.find('#'), line.size() - 1);

			std::stringstream strStream(line);

			while(strStream)
			{
				std::getline(strStream, line, ']');

				if(line != "")
				{
					if(curState == ATTRIBUTES)
						tempAttr.push_back(line);
					else
						tempContents.push_back(line);

					std::cout << line << std::endl;
				}
			}

			if(tempContents.size() > 0)
				contents.push_back(tempContents);
			else if(tempAttr.size() > 0)
				contents.push_back(tempAttr);
		}
	}
	else
	{
		std::cerr << "FileManager could not load specified file" << std::endl;
	}
}


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


bool FileManager::LoadContent(const char* filename)
{
	std::fstream openfile(filename);

	attributes.clear();
	contents.clear();

	if(openfile.is_open())
	{
		std::vector<std::string> tempAttr;
		std::vector<std::string> tempContents;

		while(!openfile.eof())
		{
			std::string line;

			std::getline(openfile, line);

			std::remove(line.begin(), line.end(), ' ');

			if(line.find("Load=") != std::string::npos)
			{
				curState = ATTRIBUTES;
				line.erase(0, line.find('=') + 1);
			}
			else
				curState = CONTENTS;

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
				attributes.push_back(tempAttr);
		}
	}
	else
	{
		std::cerr << "FileManager could not load specified file: "
				<< filename << std::endl;
		return false;
	}
	return true;
}



std::string FileManager::GetAttrContents(const std::string& attrName) const
{
	for(unsigned int i = 0; i < attributes.size(); i++)
	{
		for(unsigned int j = 0; j < attributes[i].size(); j++)
			if(attributes[i][j] == attrName)
				return contents[i][j];
	}

	return NULL;
}

const FileManager::cfgData& FileManager::GetAttributes(void)
{
	return attributes;
}

const FileManager::cfgData& FileManager::GetContents()
{
	return contents;
}

/*
 * FileManager.h
 *
 *  Created on: Jul 4, 2013
 *      Author: slacker
 */

#ifndef FILEMANAGER_H_
#define FILEMANAGER_H_

#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <sstream>

enum LOADSTATE { ATTRIBUTES, CONTENTS };

class FileManager
{
public:
	FileManager();
	virtual ~FileManager();

	void LoadContent(const char* filename,
			std::vector<std::vector<std::string> >& attributes,
			std::vector<std::vector<std::string> >& contents);
	void UnloadContent();

private:
	int curState;

	std::vector<std::string> tempAttr;
	std::vector<std::string> tempContents;
};

#endif /* FILEMANAGER_H_ */

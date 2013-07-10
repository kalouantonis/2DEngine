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

	typedef std::vector<std::vector<std::string> > cfgData;
	typedef cfgData::iterator iterator;
	typedef cfgData::const_iterator const_iterator;

	bool LoadContent(const char* filename);
	bool LoadContent(const char* filename, const std::string& id);

	// Will return NULL if nothing is found
	std::string GetAttrContents(const std::string& attrName) const;
	const cfgData& GetAttributes(void);
	const cfgData& GetContents(void);

	void UnloadContent();


private:
	int curState;

	void ParseLoad(std::string& line);

	bool idFound;

	cfgData attributes;
	cfgData contents;

	std::vector<std::string> tempAttr;
	std::vector<std::string> tempContents;
};

#endif /* FILEMANAGER_H_ */

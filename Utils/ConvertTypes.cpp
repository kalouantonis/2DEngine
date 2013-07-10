/*
 * ConvertTypes.cpp
 *
 *  Created on: Jul 4, 2013
 *      Author: slacker
 */

#include "ConvertTypes.h"

bool StrToInt(int & i, const std::string& s)
{
	std::stringstream ss(s);

	// Send string though ss to convert to integer value
	ss >> i;

	if(ss.fail())
		return false;
	return true;
}



//
//  TestHelpers.cpp
//  Prototype-UnitTesting
//
//  Created by Alex Turner on 6/16/15.
//  Copyright © 2015 University of Michigan – Soar Group. All rights reserved.
//

#include "TestHelpers.hpp"

#ifdef _MSC_VER
#include <Windows.h>
#endif

#include <exception>
#include <sstream>

bool isfile(const char* path)
{
#ifdef _WIN32
	DWORD a = GetFileAttributes(path);
	return a != INVALID_FILE_ATTRIBUTES && !(a & FILE_ATTRIBUTE_DIRECTORY);
#else
	struct stat st;
	return (stat(path, &st) == 0 && !S_ISDIR(st.st_mode));
#endif
}

void printDebugInformation(std::stringstream& output, sml::Agent* agent)
{
	if (!agent)
		return;
	
	output << "============================================================" << std::endl << std::endl;
	output << "Debug Information" << std::endl << std::endl;
	output << "============================================================" << std::endl << std::endl;
	
	output << "============================================================" << std::endl << std::endl;
	output << agent->ExecuteCommandLine("print -d 100 s1") << std::endl << std::endl;
	output << "============================================================" << std::endl << std::endl;
	
	output << "============================================================" << std::endl << std::endl;
	
	std::string rules = agent->ExecuteCommandLine("p");
	std::stringstream ss(rules);
	std::string line;
	
	while (std::getline(ss, line, '\n'))
	{
		output << "=======================" << std::endl;
		output << "matches " << line << ":" << std::endl << agent->ExecuteCommandLine(("matches " + line).c_str()) << std::endl << std::endl;
		output << "fc " << line << ":" << std::endl << agent->ExecuteCommandLine(("fc " + line).c_str()) << std::endl << std::endl;
	}
	output << "=======================" << std::endl;
	
	output << std::endl;
	
	output << agent->ExecuteCommandLine("matches") << std::endl << std::endl;
	output << "============================================================" << std::endl << std::endl;
	
	output << "============================================================" << std::endl << std::endl;
	output << agent->ExecuteCommandLine("stats") << std::endl << std::endl;
	output << "============================================================" << std::endl << std::endl;
}
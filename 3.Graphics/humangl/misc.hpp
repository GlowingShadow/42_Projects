#pragma once
#include <direct.h>
#include <string>
#include <fstream>
#include <algorithm>

class Misc
{
public:
	Misc();
	~Misc();

	static std::string		getCurrentDirectory(void);
	static std::string		getFileContent(const char *filename);
	static void				logfile(std::string basename, std::string logs);
	static void				breakExit(int err);
};


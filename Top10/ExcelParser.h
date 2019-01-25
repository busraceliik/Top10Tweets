#include <string>

#pragma once
class ExcelParser
{
public:
	ExcelParser() { }

	string GetTweetContent(const string& str)
	{
		size_t position = str.rfind("\",\"");

		if (position != string::npos)
		{
			string line = str.substr(position + 3);

			return line.substr(0, line.length() - 1);
		}

		return "";
	}
};



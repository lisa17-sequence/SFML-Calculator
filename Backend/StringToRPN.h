#pragma once

#include <string>
#include <map>
#include <iostream>
#include <stack>
#include <algorithm>

class StringToRPN
{
private:
	std::string str;
	void remove_spaces(std::string& str);
public:
	std::string RPN(std::string str);
};


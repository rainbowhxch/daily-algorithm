#include <string>
#include <regex>
using std::string;
using std::regex;

bool is_numeric(string s)
{
    if (s.empty())
	return false;
    regex r("[+-]?\\d*(\\.\\d+)?([eE][+-]?\\d+)?");
    return std::regex_match(s, r);
}

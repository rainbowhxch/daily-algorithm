#include <string>
#include <cctype>

using std::string;

class Solution {
public:
    string reorderSpaces(string text) {
        int wordCount = 0, spaceCount = 0;
        int lastCharPosition = 0;

        for (int i = 0; i < text.length(); i++) {
            if (text[i] == ' ') {
                spaceCount++;
                continue;
            }

            if (i == 0 or text[i-1] == ' ')
                wordCount++;

            lastCharPosition = i;
        }

        int spaceLength = spaceCount, extraSpace = 0;
        int spaceRegions = wordCount - 1;

        if (spaceRegions)
            spaceLength = spaceCount / spaceRegions,
            extraSpace = spaceCount % spaceRegions;
        else
            extraSpace = spaceCount;

        string result;

        for (int i = 0; i < text.length(); i++) {
            if (text[i] != ' ')
                result += text[i];
            else if (i > 0 and isalpha(text[i-1]) and i-1 != lastCharPosition)
                result += string(spaceLength, ' ');
        }

        if (extraSpace)
            result += string(extraSpace, ' ');

        return result;
    }
};

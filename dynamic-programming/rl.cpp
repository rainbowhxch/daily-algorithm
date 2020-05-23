#include <string>

using std::string;

#define SIZE_REG 1024
static string regex, text;
static int book[SIZE_REG][SIZE_REG];

bool regex_match(int i, int j)
{
    bool fir_match, res;
    if (i == regex.size())
      return j == text.size();

    fir_match = (j < text.size()) && (regex[i] == text[j] || regex[i] == '.');
    if (i <= regex.size() - 2 && regex[i + 1] == '*')
      res = regex_match(i + 2, j) || (regex_match(i, j + 1) && fir_match);
    else
        res = regex_match(i+1, j+1);

    return (book[i][j] = res);
}

#include <string>

using std::string;

#define SIZE_REG 1024
static string regx, text;
static int book[SIZE_REG][SIZE_REG];

bool regx_match(int i, int j)
{
    bool fir_match, res;
    if (i == regx.size()) return j == text.size();

    fir_match = (j < text.size()) && \
                     (regx[i] == text[j] || regx[i] == '.');
    if (i <= regx.size()-2 && regx[i+1] == '*')
        res = regx_match(i+2, j) || \
             (regx_match(i, j+1) && fir_match);
    else
        res = regx_match(i+1, j+1);
    return (book[i][j] = res);
}

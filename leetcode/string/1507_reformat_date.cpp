#include <sstream>
#include <vector>
#include <string>
#include <unordered_map>

using std::string;
using std::vector;
using std::istringstream;
using std::unordered_map;
using std::getline;
using std::to_string;

class Solution {
public:
  Solution() {
      for (int i = 4; i <= 31; ++i) {
          if (i == 2 or i == 22 or i == 23 or i == 31) continue;
          if (i < 10) {
              day_map[to_string(i) + "th"] = "0" + to_string(i);
          } else {
              day_map[to_string(i) + "th"] = to_string(i);
          }
      }
  }

    string reformatDate(string date) {
        istringstream ss(date);
        string res;
        string tmp_string;
        vector<string> tmp_vec;

        while (getline(ss, tmp_string, ' '))
            tmp_vec.push_back(tmp_string);

        return tmp_vec[2] + "-" + month_map[tmp_vec[1]] + "-" + day_map[tmp_vec[0]].substr(0, 2);
    }

 private:
  unordered_map<string, string> month_map{
      {"Jan", "01"},
      {"Feb", "02"},
      {"Mar", "03"},
      {"Apr", "04"},
      {"May", "05"},
      {"Jun", "06"},
      {"Jul", "07"},
      {"Aug", "08"},
      {"Sep", "09"},
      {"Oct", "10"},
      {"Nov", "11"},
      {"Dec", "12"}
  };

  unordered_map<string, string> day_map {
      {"1st", "01"},
      {"21st", "21"},
      {"31st", "31"},
      {"2nd", "02"},
      {"22nd", "22"},
      {"3rd", "03"},
      {"23rd", "23"}
  };
};

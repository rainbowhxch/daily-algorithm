#include <string>

using std::string;

class Solution {
public:
    int dayOfYear(string date)
    {
        int months[14] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

        int year = 0;
        for (int i = 0; i < 4; i++) {
            year *= 10;
            year += date[i] - '0';
        }

        int month = 0;
        month += date[5] - '0';
        month *= 10;
        month += date[6] - '0';

        int day = 0;
        day += date[8] - '0';
        day *= 10;
        day += date[9] - '0';

        int num = 0;
        for (int i = 0; i < month; i++) {
            num += months[i];
        }

        num += day;

        if (year % 400 == 0 && month > 2) {
            num++;
        }
        else {
            if (year % 4 == 0 && year % 100 && month > 2)
                num++;
        }

        return num;
    }
};

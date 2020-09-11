#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using std::atoi;
using std::string;
using std::to_string;
static string s1 = "-2147483648";
static string s2 = "2147483647";

class Solution
{
public:
    int reverse(int x)
    {
        if (x < 0)
        {
            string str = to_string(x);
            std::reverse(str.begin() + 1, str.end());
            if (str.length() >= s1.length() && str > s1)
            {
                return 0;
            }
            else
            {
                return atoi(str.c_str());
            }
        }
        else if (x > 0)
        {
            string str = to_string(x);
            std::reverse(str.begin(), str.end());
            if (str.length() >= s2.length() && str > s2)
            {
                return 0;
            }
            else
            {
                return atoi(str.c_str());
            }
        }
        else
        {
            return 0;
        }
    }
};

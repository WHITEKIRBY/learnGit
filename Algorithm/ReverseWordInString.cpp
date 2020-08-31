#include <iostream>
#include <string.h>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        char c;
        int npos = -1;
        int pos;

        do
        {
            pos = npos;
            npos = s.find(" ", ++pos);
            if (npos != -1)
            {
                for (int i = 1; (npos - i) >= (pos + i); i++)
                {
                    c = s[npos - i];
                    s[npos - i] = s[pos + i - 1];
                    s[pos + i - 1] = c;
                }
            }
        } while (npos != -1);

        npos = s.size();
        for (int i = 1; (npos - i) >= (pos + i); i++)
        {
            c = s[npos - i];
            s[npos - i] = s[pos + i - 1];
            s[pos + i - 1] = c;
        }

        return s;
    }
};

int main()
{

    string s1{"Let's take LeetCode contest"};

    Solution reverse;

    string s2{""};

    s2 = reverse.reverseWords(s1);
    cout << s2 << endl;

    return 0;
}
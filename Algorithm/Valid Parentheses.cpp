#include <iostream>
#include <string>
#include <stack>
using std::stack;
using std::string;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        for (auto i : s)
        {
            if (i == '(')
                st.push(')');
            else if (i == '{')
                st.push('}');
            else if (i == '[')
                st.push(']');
            else if (st.empty() || i != st.top())
                return false;
            else
            {
                st.pop();
            }
        }
        return st.empty();
    }
};
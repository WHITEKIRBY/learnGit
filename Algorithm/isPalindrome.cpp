#include <iostream>

class Solution
{
public:
    int reverse(int x)
    {
        int rev = 0;
        while (x != 0)
        {
            int pop = x % 10;
            x /= 10;
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7))
                return 0;
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8))
                return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
    bool isPalindrome(int x)
    {
        if (x < 0)
        {
            return false;
        }
        else if (x >= 10)
        {
            int rev = reverse(x);
            if (rev == x)
                return true;
            else
                return false;
        }
        else
            return true;
    }
};
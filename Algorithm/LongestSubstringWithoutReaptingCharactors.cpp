#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using std::unordered_map;
using std::string;
using std::vector;
using std::max;

//此法时间复杂度极高，因为对一个hashmap进行了O（n^2）次访问，插入和删除。
//正确的做法应该是使用双指针。
//更新：只需遍历一次并且无需删除map元素的方法：增加一个k变量标记，相当于一个指针！
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char,int> check;
        int count = 0;
        int k = -1;
        for (int i = 0; i < s.size(); i++)
        {
            if (check.find(s[i]) != check.end() && check[s[i]] > k)
            {
                k = check[s[i]];
                check[s[i]] = i;
            }
            else
            {
                check[s[i]] = i;
                count = max(count,i-k);
            }
        }
        return count;
    }
};

int main()
{
    Solution s;
    int ans;
    ans = s.lengthOfLongestSubstring(" ");

    return 0;
}
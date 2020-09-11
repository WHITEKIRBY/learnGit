#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using std::map;
using std::sort;
using std::vector;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, int> mapele;
        vector<int> ans{};
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (mapele.find(target - nums[i]) != mapele.end())
            {
                ans.push_back(mapele[target - nums[i]]);
                ans.push_back(i);
                return ans;
            }
            mapele[nums[i]] = i;
        }
        return ans;
    }
};
//这题最快的做法还是用map，不知道为什么之前的题想到了这题没想到map。。可能是递归回溯的题做多了产生了一点思维惯性。

int main()
{
    return 0;
}
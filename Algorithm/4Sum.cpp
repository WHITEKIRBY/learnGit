#include <iostream>
#include <vector>
#include <algorithm>
using std::sort;
using std::vector;

class Solution
{
public:
    void bt(vector<vector<int>> &ans, vector<int> &nums, int numsize, int target, vector<int> combine, int index)
    {
        if (combine.size() == 4 && target == 0)
        {
            ans.push_back(combine);
            return;
        }
        else
        {
            if (combine.size() == 4)
                return;
            for (int i = index; i < numsize; i++)
            {
                if (numsize - i < 4 - combine.size())
                    return;
                if (i != index && nums[i] == nums[i - 1])
                    continue;
                if (target < 0 && nums[i] > 0)
                    return;
                //这里剪支剪的不够导致超时。。
                
                combine.push_back(nums[i]);
                bt(ans, nums, target - nums[i], numsize, combine, i + 1);
                combine.pop_back();
            }
        }
    }
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans{};
        auto numsize = nums.size();
        bt(ans, nums, numsize, target, {}, 0);
        return ans;
    }
};
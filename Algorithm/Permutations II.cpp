#include <iostream>
#include <vector>
#include <algorithm>
using std::swap;
using std::vector;

//参考了博客：https://www.cnblogs.com/sooner/p/3264882.html
//条件 ！i || nums[i] != nums[i-1] 是不起作用的，因为这种算法原地运行——
//——有多个重复元素的情况下，重复的元素被交换后会不出现在自身的前个位置。
//所以只能遍历nums[cur]至nums[i] 的元素来判断是否出现重复元素的交换。

class Solution
{
public:
    bool IsSwap(vector<int> nums, int nBegin, int nEnd)
    {
        for (int i = nBegin; i < nEnd; i++)
            if (nums[i] == nums[nEnd])
                return false;
        return true;
    }
    void backtrack(vector<int> &nums, vector<vector<int>> &solutions, int n, int cur)
    {
        if (cur == n)
        {
            solutions.push_back(nums);
        }
        else
        {
            for (int i = cur; i <= n; i++)
            {
                if (IsSwap(nums,cur,i))
                {
                    swap(nums[i], nums[cur]);
                    backtrack(nums, solutions, n, cur + 1);
                    swap(nums[i], nums[cur]);
                }
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> solutions;
        backtrack(nums, solutions, n - 1, 0);
        return solutions;
    }
};
int main()
{
    vector<int> nums{1, 1, 2, 2};
    Solution s;
    vector<vector<int>> ans{};
    ans = s.permuteUnique(nums);
    return 0;
}
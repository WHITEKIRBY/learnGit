#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using std::accumulate;
using std::sort;
using std::vector;

//又是一道动态规划题目，不过这题的题解算是没有什么困难就看懂了
//下面自己写的解答严重超时，，因为backtrack搜索对很多重复的情况进行了计算。
//尝试1：将nums降序排列 结果：还是超时了，测试用例n较大时dfs不可能比动态规划快
//正确的（0-1背包做法）https://leetcode-cn.com/problems/partition-equal-subset-sum/solution/fen-ge-deng-he-zi-ji-by-leetcode-solution/

class Solution
{
private:
    int sum;

public:
    bool backtrack(vector<int> &nums, int subsum, int index)
    {
        if (subsum == 0)
            return true;
        if (subsum < 0)
            return false;
        for (int i = index; i < nums.size(); i++)
        {
            if (backtrack(nums, subsum - nums[i], i + 1))
                return true;
        }
        return false;
    }
    bool canPartition(vector<int> &nums)
    {
        sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1)
            return false;
        else
        {
            sort(nums.rbegin(), nums.rend());
            if (nums.front() > (sum / 2))
                return false;
            else
            {
                return backtrack(nums, sum / 2, 0);
            }
        }
    }
};
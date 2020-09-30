#include <iostream>
#include <vector>
using std::vector;

//可能因为写了很多回溯的题目了，这次解决问题的速度特别快

class Solution
{
public:
    void backtrack(vector<int> &nums, vector<vector<int>> &solu, vector<int> combine, int &n, int count)
    {
        if (count == n)
        {
            solu.push_back(combine);
            return;
        }
        else
        {
            for (int i = count; i < nums.size(); i++)
            {
                combine.push_back(nums[i]);
                backtrack(nums, solu, combine, n, i + 1);
                combine.pop_back();
            }
        }
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> solu{};
        vector<int> combine{};
        for (int i = 0; i <= nums.size(); i++)
        {
            backtrack(nums,solu,combine,i,0);
        }
        return solu;
    }
};
#include <iostream>
#include <vector>
#include <algorithm>

using std::sort;
using std::vector;

class Solution
{
public:
    void dfs(vector<vector<int>> &solution, vector<int> &candidates, vector<int> combine, int target, int index)
    {
        if (target == 0)
        {
            solution.push_back(combine);
            return;
        }
        if (target < 0)
            return;
        if (index == candidates.size())
            return;
        combine.push_back(candidates[index]);
        dfs(solution, candidates, combine, target - candidates[index], index);
        combine.pop_back();
        dfs(solution, candidates, combine, target, index + 1);
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> solution{};
        vector<int> combine{};
        sort(candidates.begin(), candidates.end());
        for (int i = 0; i < candidates.size();)
        {
            if (candidates[i] > target)
                candidates.erase(candidates.begin() + i);
            else
            {
                i++;
            }
        }
        dfs(solution, candidates, combine, target, 0);
        return solution;
    }
};

int main()
{
    Solution s;
    vector<int> candidates{2, 3, 6, 7};
    s.combinationSum(candidates, 7);

    return 0;
}
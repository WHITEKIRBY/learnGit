#include <iostream>
#include <vector>
#include <algorithm>
using std::sort;
using std::vector;
class Solution
{
public:
    vector<vector<int>> res;
    vector<int> temp;

    void backtrack(vector<int> &candidates, int target, int index)
    {
        if (target == 0)
        {
            res.push_back(temp);
            return;
        }
        for (int i = index; i < candidates.size() && target - candidates[i] >= 0; i++)
        {
            if (i > index && candidates[i] == candidates[i - 1])
                continue;
            temp.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i + 1);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0);
        return res;
    }
};
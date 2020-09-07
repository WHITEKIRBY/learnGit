#include <iostream>
#include <vector>
#include <map>
using std::map;
using std::swap;
using std::vector;
//没有理论知识支撑的瞎写一通，，还不如solution1的直白做法，至少复杂度还是在O（NlogN）
//从中午debug到下午。。
//正确答案在leetcode：https://leetcode-cn.com/problems/top-k-frequent-elements/solution/qian-k-ge-gao-pin-yuan-su-by-leetcode-solution/
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (n == 0)
            return nums;
        map<int, int> map_pos{};
        map<int, int> map_times{};
        int i = 0;
        int t;
        int temp = 0;
        for (int count = 0; count < n; count++)
        {
            if (map_pos.find(nums[i]) == map_pos.end())
            {
                map_times[nums[i]] = 1;
                map_pos[nums[i]] = i;
                i++;
            }
            else
            {
                map_times[nums[i]] += 1;
                if (map_pos[nums[i]] == 0)
                {
                    nums.erase(nums.begin() + i);
                }
                else if (map_times[nums[i]] > map_times[nums[map_pos[nums[i]] - 1]])
                {
                    t = 1;
                    while (map_times[nums[i]] > map_times[nums[map_pos[nums[i]] - t]] && map_pos[nums[i]] - t != 0)
                        t++;
                    if(map_times[nums[i]] <= map_times[nums[map_pos[nums[i]]-t]])
                        t--;
                    temp = nums[map_pos[nums[i]] - t];
                    swap(nums[map_pos[nums[i]]], nums[map_pos[nums[i]] - t]);
                    map_pos[nums[i]] -= t;
                    map_pos[temp] += t;
                    nums.erase(nums.begin() + i);
                }
                else
                {
                    nums.erase(nums.begin() + i);
                }
            }
        }
        vector<int> solution;
        for (int i = 0; i < k; i++)
        {
            solution.push_back(nums[i]);
        }
        return solution;
    }
};

int main()
{
    Solution s;
    vector<int> nums{4, 1, -1, 2, -1, 2, 3};
    vector<int> ss;
    ss = s.topKFrequent(nums, 2);
    return 0;
}
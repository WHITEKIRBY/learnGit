#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using std::map;
using std::pair;
using std::vector;

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second > b.second;
}

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        map<int, int> mapnum{};
        for (auto i : nums)
        {
            if (mapnum.find(i) != mapnum.end())
            {
                mapnum[i] += 1;
            }
            else
            {
                mapnum[i] = 1;
            }
        }
        vector<pair<int, int>> orders(mapnum.begin(), mapnum.end());
        sort(orders.begin(), orders.end(), cmp);
        vector<int> solution;
        for (int i = 0; i < k; i++)
        {
            solution.push_back(orders[i].first);
        }
        return solution;
    }
};

int main()
{
    return 0;
}
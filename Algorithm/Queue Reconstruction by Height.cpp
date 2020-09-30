#include <iostream>
#include <vector>
#include <map>
#include <functional>
using std::greater;
using std::map;
using std::pair;
using std::vector;

class Solution
{
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        vector<vector<int>> ans{};
        if (people.empty())
        {
            return ans;
        }
        map<int, map<int, int>, greater<int>> record{};
        for (int i = 0; i < people.size(); i++)
        {
            record[people[i][0]].insert(pair<int, int>(people[i][1], i));
        }
        auto iter = record.begin();
        auto iter2 = (*iter).second.begin();
        while (iter != record.end())
        {
            iter2 = (*iter).second.begin();
            while (iter2 != (*iter).second.end())
            {
                ans.insert(ans.begin() + (*iter2).first, people[(*iter2).second]);
                ++iter2;
            }
            ++iter;
        }

        return ans;
    }
};
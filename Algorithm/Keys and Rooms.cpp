#include <iostream>
#include <set>
#include <vector>
using namespace std;
/*
这一题应该使用深度优先搜索或者广度优先搜索完成，不了解有向图相关的算法的情况下
直接采用了双集合去重的思路，虽然也完成了，但是时间开销和空间开销都很大。
*/

class Solution
{
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        set<int> myset_1{0};
        set<int> myset_2{0};
        while (myset_1.empty() != true)
        {
            for (int i : myset_1)
            {
                for (int j : rooms[i])
                {
                    if (i != j && myset_2.count(j) != 1)
                        myset_1.insert(j);
                    myset_2.insert(j);
                }
                myset_1.erase(i);
            }
        }
        if (myset_2.size() == rooms.size())
            return true;
        else
            return false;
    }
};

int main()
{
    return 0;
}
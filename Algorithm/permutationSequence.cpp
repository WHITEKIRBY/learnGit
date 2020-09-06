#include <iostream>
#include <set>
#include <string>
using std::cin;
using std::cout;
using std::set;
using std::string;
using std::to_string;

class Solution
{
public:
    string getPermutation(int n, int k)
    {
        int count;
        set<int> num;
        string sequence{};
        string temp{};
        for (int i = 1; i <= n; i++)
        {
            num.insert(i);
        }
        findKthSequence(num, n, k, count, temp, sequence);
    }
    void findKthSequence(set<int> num, int n, int k, int &count, string temp, string &sequence)
    {
        if (temp.size() != n)
        {
            temp += to_string(*(num.begin()));
            int t = *(num.begin());
            num.erase(*(num.begin()));
            findKthSequence(num, n, k, count, temp, sequence);
            num.insert(t);
        }
        if (temp.size() == n)
        {
            count++;
        }
        if (count == k)
        {
            sequence = temp;
            return;
        }
    }
};

int main()
{
    Solution s1;
    cout << s1.getPermutation(3, 1);
    cin.get();
    return 0;
}
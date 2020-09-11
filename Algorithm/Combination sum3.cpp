#include <iostream>
#include <vector>
using std::vector;

class Solution
{
public:
    void bt(vector<vector<int>> &solutions, vector<int> combine, int k, int n, int index)
    {
        if (n == 0 && combine.size() == k)
        {
            solutions.push_back(combine);
            return;
        }
        else if (combine.size() == k)
            return;
        else
        {
            for (int i = index; i <= 9; i++){
                if(n >= i){
                    combine.push_back(i);
                    bt(solutions,combine,k,n-i,i+1);
                    combine.pop_back();
                }
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        if(n>45)
            return{};
        vector<vector<int>> solutions;
        vector<int> combine;
        bt(solutions,combine,k,n,1);
        return solutions;
    }
};

int main(){
    Solution s;
    vector<vector<int>> ans;
    ans = s.combinationSum3(3,7);
    return 0;
}
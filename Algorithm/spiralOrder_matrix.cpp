#include <iostream>
#include <vector>
using std::vector;

//注意清晰的思考很重要，不要一味的瞎jb调试

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {   
        vector<int> ans {};
        if(matrix.empty()){
            return ans;
        }
        int i = 0;
        int j = 0;
        int k = 0;
        int l = 0;
        int n = matrix.size() * matrix[0].size();
        int count = 0;
        
        while (count != n)
        {
            if (i == matrix[0].size() - k)
            {
                i--;
                while (i >= l)
                {
                    ans.push_back(matrix[j][i]);
                    count++;
                    i--;
                }
            }
            else
            {
                while (i != matrix[0].size() - k)
                {
                    ans.push_back(matrix[j][i]);
                    count++;
                    i++;
                }
                i--;
                k++;
                j++;
                if (count == n)
                    break;
            }
            if (j == matrix.size() - l)
            {
                while (j >= k)
                {
                    ans.push_back(matrix[j][i]);
                    count++;
                    j--;
                }
                j++;
                i++;
            }
            else
            {
                while (j != matrix.size() - l)
                {
                    ans.push_back(matrix[j][i]);
                    count++;
                    j++;
                }
                j--;
                l++;
                if (count == n)
                    break;
            }
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> test{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    Solution s;
    vector<int> answer;
    answer = s.spiralOrder(test);
    return 0;
}
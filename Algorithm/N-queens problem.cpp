#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        unordered_set<int> columns;
        unordered_set<int> diagonals1;
        unordered_set<int> diagonals2;
        vector<int> queens(n,-1);
        vector<vector<string>> Solution;
        backtrack(Solution, queens, n, 0, columns, diagonals1, diagonals2);
        return Solution;
    }

    void backtrack(vector<vector<string>> &solutions, vector<int> &queens, int n, int row, unordered_set<int> &columns, unordered_set<int> &diagonals1, unordered_set<int> &diagonals2)
    {
        if (row == n)
        {
            vector<string> board = generateBoard(queens, n);
            solutions.push_back(board);
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (columns.count(i) == 1)
                    continue;
                
                int diagonal1 = row - i;
                if (diagonals1.count(diagonal1) == 1)
                    continue;
                
                int diagonal2 = row + i;
                if (diagonals2.count(diagonal2) == 1)
                    continue;
                
                queens[row] = i;
                columns.insert(i);
                diagonals1.insert(diagonal1);
                diagonals2.insert(diagonal2);
                //TIPS:
                //以下是这个回溯算法最为关键的一步，通过递归函数row参数加一的方式处理下一行的皇后放置问题
                //若总能找到合法的位置，到最后row == n时，触发（基准情况），函数将board推入solution中
                //假若在某row中，出现了全部不能放置的情况，此时并未生成solution
                //则上一级函数回溯到上一行皇后未摆放的情况，继续进行循环
                //循环会继续尝试下一个位置。
                //这里的关键在于回溯时每个递归都会清除上一次留下的标记，这是我自己写程序时没能想到怎么做的点。
                backtrack(solutions,queens,n,row + 1,columns,diagonals1,diagonals2);
                queens[row] = -1;
                columns.erase(i);
                diagonals1.erase(diagonal1);
                diagonals2.erase(diagonal2);
            }
        }
    }

    vector<string> generateBoard(vector<int> queens, int n)
    {
        vector<string> board;
        string row;
        for (int i = 0; i < n; i++)
        {
            row = string(n, '.');
            row[queens[i]] = 'Q';
            board.push_back(row);
        }
        return board;
    }
};

int main()
{
    return 0;
}
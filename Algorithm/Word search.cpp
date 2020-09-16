#include <iostream>
#include <vector>
#include <string>
using std::string;
using std::vector;

class Solution
{
public:
    void dfs(vector<vector<char>> &board, int &sizex, int &sizey, string &word, vector<vector<bool>> &m, int j, int k, int i, bool &find)
    {
        if (find == true)
        {
            return;
        }
        else if (m[j][k] == 1)
            return;
        else if (board[j][k] == word[i])
        {
            m[j][k] = 1;
            if (i == word.size() - 1)
            {
                find = true;
                return;
            }
            else
            {
                if (j != sizey - 1)
                    dfs(board, sizex, sizey, word, m, j + 1, k, i + 1, find);
                if (k != sizex - 1)
                    dfs(board, sizex, sizey, word, m, j, k + 1, i + 1, find);
                if (j != 0)
                    dfs(board, sizex, sizey, word, m, j - 1, k, i + 1, find);
                if (k != 0)
                    dfs(board, sizex, sizey, word, m, j, k - 1, i + 1, find);
            }
            m[j][k] = 0;
        }
        else
        {
            return;
        }
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        bool find = false;
        int sizex = board[0].size();
        int sizey = board.size();
        vector<vector<bool>> m(sizey, vector<bool>(sizex, 0));
        for (int i = 0; i < sizey; i++)
        {
            for (int j = 0; j < sizex; j++)
                dfs(board, sizex, sizey, word, m, i, j, 0, find);
        }
        return find;
    }
};
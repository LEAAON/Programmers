#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) 
{
    vector<stack<int>> _board(board.size(), stack<int>());

    for (int i = board.size() - 1; i >= 0; i--)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            int doll = board[i][j];

            if (doll == 0) 
            {
                continue;
            }

            _board[j].push(doll);
        }
    }

    stack<int> mainStack;
    int answer = 0;

    for (int i = 0; i < moves.size(); i++)
    {
        int col = moves[i] - 1;

        if (_board[col].empty())
            continue;

        int doll = _board[col].top();
        _board[col].pop();

        if (!mainStack.empty() && mainStack.top() == doll) 
        {
            mainStack.pop();
            answer += 2;
        }
        else 
        {
            mainStack.push(doll);
        }
    }

    return answer;
}
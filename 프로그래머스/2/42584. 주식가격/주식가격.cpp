#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) 
{
    stack<pair<int, int>> stock;
    int size = prices.size();
    vector<int> answer(size, 0);

    for (int i = 0; i < size; i++) 
    {
        while (!stock.empty() && stock.top().first > prices[i]) 
        {
            int index = stock.top().second;
            answer[index] = i - index;
            stock.pop();
        }

        stock.push({ prices[i], i });
    }

    while (!stock.empty()) 
    {
        int index = stock.top().second;
        answer[index] = (size - 1) - index;
        stock.pop();
    }

    return answer;
}
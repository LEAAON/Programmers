#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int solution(vector<int> order) 
{
    int answer = 0;

    queue<int> main_belt;
    stack<int> sub_belt;

    for (int i = 0; i < order.size(); ++i)
    {
        main_belt.push(i + 1);
    }

    for (int i = 0; i < order.size(); ++i)
    {
        int orderBox = order[i];

        // Step A: 보조 벨트 맨 위에 내가 찾는 상자가 있는가?
        if (!sub_belt.empty() && sub_belt.top() == orderBox)
        {
            sub_belt.pop();
            answer++;
            continue;
        }

        while (!main_belt.empty() && main_belt.front() != orderBox)
        {
            sub_belt.push(main_belt.front());
            main_belt.pop();
        }

        if (!main_belt.empty() && main_belt.front() == orderBox)
        {
            main_belt.pop();
            answer++;
        }
        else
        {
            break;
        }
    }

    return answer;
}
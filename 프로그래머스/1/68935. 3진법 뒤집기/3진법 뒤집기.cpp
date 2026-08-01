#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(int n) 
{
    int answer = 0;

    stack<int> ternary;
    {
        while (n > 2)
        {
            ternary.push(n % 3);
            n /= 3;
        }

        ternary.push(n);
    }

    int ter = 1;
    while (!ternary.empty())
    {
        int bin = ternary.top();
        ternary.pop();
        answer += ter * bin;
        ter *= 3;
    }

    return answer;
}
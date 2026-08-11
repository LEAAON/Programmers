#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s)
{
    string doubleS = s + s;
    int answer = 0;

    stack<char> brackets;
    int count = 0;
    for (int i = 0; i < s.size(); i++)
    {
        count = 0;
        brackets = stack<char>();

        for (int j = i; j < s.size() + i; j++)
        {
            char ch = doubleS[j];
             
            if (ch == '(' || ch == '{' || ch == '[')
            {
                count++;
                brackets.push(ch);
            }
            else
            {
                if (brackets.empty())
                {
                    count--;
                    break;
                }

                char topCh = brackets.top();

                if (ch == ')' && topCh == '(')
                {
                    count--;
                    brackets.pop();
                }
                else if (ch == '}' && topCh == '{')
                {
                    count--;
                    brackets.pop();
                }
                else if (ch == ']' && topCh == '[')
                {
                    count--;
                    brackets.pop();
                }
                else
                {
                    count--;
                    break;
                }
            }
        }

        if (brackets.empty() && count == 0)
            answer++;
    }

    return answer;
}
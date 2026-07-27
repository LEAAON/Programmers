#include <string>

using namespace std;

int solution(string s)
{
    string stack = "";

    for (char c : s)
    {
        if (!stack.empty() && stack.back() == c)
        {
            stack.pop_back();
            continue;
        }

        stack.push_back(c);
    }

    if (stack.empty())
        return 1;

    return 0;
}
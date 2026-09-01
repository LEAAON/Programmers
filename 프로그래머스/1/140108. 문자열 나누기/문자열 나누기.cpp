#include <string>
#include <vector>

using namespace std;

int solution(string s) 
{
    int answer = 0;

    char x = '\0';
    int xCount = 0;
    int otherCount = 0;

    for (char c : s)
    {
        if (xCount == otherCount)
            x = c;

        if (c == x)
            xCount++;
        else
            otherCount++;

        if (xCount == otherCount)
        {
            answer++;
            xCount = 0;
            otherCount = 0;
        }
    }

    if (xCount != 0)
        answer++;

    return answer;
}
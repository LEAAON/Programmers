#include <string>
#include <vector>

using namespace std;

int solution(int n, int w, int num) 
{
    int numH = (num - 1) / w;
    int numCol = (numH % 2 == 0) ? ((num - 1) % w) : (w - 1 - ((num - 1) % w));

    int maxH = (n - 1) / w;
    int maxCol = (maxH % 2 == 0) ? ((n - 1) % w) : (w - 1 - ((n - 1) % w));

    int answer = maxH - numH + 1;
    if (maxH % 2 == 0)
    {
        if (numCol > maxCol)
            answer--;
    }
    else
    {
        if (numCol < maxCol)
            answer--;
    }

    return answer;
}
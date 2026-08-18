#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section)
{
    int answer = 0;

    int curIndex = 0;

    for (int index : section)
    {
        if (curIndex >= index)
            continue;

        curIndex = index + m - 1;
        answer++;
    }

    return answer;
}
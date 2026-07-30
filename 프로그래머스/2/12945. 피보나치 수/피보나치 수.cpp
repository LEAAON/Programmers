#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
    int answer = 0;

    int dp0 = 1;
    int dp1 = 1;

    if (n == 1)
        return dp0;
    else if (n == 2)
        return dp1;

    for (int i = 3; i <= n; i++)
    {
        int dp2 = (dp0 + dp1) % 1234567;
        dp0 = dp1;
        dp1 = dp2;
    }

    answer = dp1;

    return answer;
}
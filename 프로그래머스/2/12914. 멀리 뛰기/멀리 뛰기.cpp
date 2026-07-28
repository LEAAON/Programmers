#include <string>
#include <vector>

using namespace std;

long long solution(int n) 
{
    long long answer = 0;

    long long dp0 = 1;
    long long dp1 = 2;

    if (n == 1)
        return dp0;
    else if (n == 2)
        return dp1;

    for (int i = 3; i <= n; i++)
    {
        long long dp2 = (dp0 + dp1) % 1234567LL;
        dp0 = dp1;
        dp1 = dp2;
    }

    answer = dp1;

    return answer;
}
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, long long left, long long right)
{
    vector<int> answer;
    answer.reserve(right - left);

    for (long long i = left; i <= right; i++)
    {
        long long x = i % n;
        long long y = i / n;

        long long maxNum = max(x, y);

        answer.push_back(maxNum + 1);
    }

    return answer;
}
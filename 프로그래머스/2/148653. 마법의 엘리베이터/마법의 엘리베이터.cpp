#include <string>
#include <vector>

using namespace std;

int solution(int storey)
{
    int answer = 0;
    int copyStorey = storey;

    vector<int> dp;
    while (copyStorey > 0)
    {
        int remain = copyStorey % 10;
        copyStorey /= 10;

        if (remain > 5)
        {
            answer += (10 - remain);
            copyStorey += 1;
        }
        else if (remain < 5)
        {
            answer += remain;
        }
        else
        {
            if (copyStorey % 10 >= 5) {
                answer += (10 - remain);
                copyStorey += 1;
            }
            else {
                answer += remain;
            }
        }
    }

    return answer;
}
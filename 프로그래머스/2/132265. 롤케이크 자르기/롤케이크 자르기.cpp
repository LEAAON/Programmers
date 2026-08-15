#include <string>
#include <vector>

using namespace std;

int solution(vector<int> topping) 
{
    vector<int> right;
    right.resize(10001, 0);

    vector<int> left;
    left.resize(10001, 0);

    int rCount = 0;
    int lCount = 0;

    int answer = 0;

    for(int cake : topping)
    {
        if (right[cake] == 0)
            rCount++;

        right[cake]++;
    }

    for (int cake : topping)
    {
        right[cake]--;
        if (right[cake] == 0)
            rCount--;

        if (left[cake] == 0)
            lCount++;

        left[cake]++;

        if (rCount == lCount)
            answer++;
    }

    return answer;
}
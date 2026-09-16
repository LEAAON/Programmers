#include <string>
#include <vector>

using namespace std;

int dfsF(const vector<int>& numbers, int target, int index, int sum)
{
    if (index == numbers.size())
    {
        if (sum == target)
            return 1;
        else
            return 0;
    }

    int add = dfsF(numbers, target, (index + 1), (sum + numbers[index]));
    int sub = dfsF(numbers, target, (index + 1), (sum - numbers[index]));

    return add + sub;
}

int solution(vector<int> numbers, int target)
{
    return dfsF(numbers, target, 0, 0);
}
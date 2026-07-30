#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) 
{
    vector<int> copyPeople = people;
    sort(copyPeople.begin(), copyPeople.end(), greater<int>());
    int size = copyPeople.size();

    int answer = 0;

    for (int i = 0; i < size; i++)
    {
        int large = copyPeople[i];
        int small = copyPeople[size - 1];

        if (large + small <= limit)
            size -= 1;

        answer += 1;
    }

    return answer;
}
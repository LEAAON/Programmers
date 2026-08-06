#include <string>
#include <vector>

using namespace std;

int GetFactorCount(int num)
{
    int count = 0;

    for (int i = 1; i * i <= num; i++)
    {
        if (num % i != 0)
            continue;

        if (i * i == num)
            count += 1;
        else
            count += 2;
    }

    return count;
}

int solution(int number, int limit, int power) 
{
    int answer = 0;

    vector<int> weapons;
    weapons.resize(number);

    for (int i = 1; i <= number; i++)
    {
        int weapon = GetFactorCount(i);

        if (weapon > limit)
            weapon = power;

        weapons[i - 1] = weapon;
    }

    for (auto weight : weapons)
        answer += weight;

    return answer;
}
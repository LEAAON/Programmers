#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

bool IsPrime(int num)
{
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
            return false;
    }

    return true;
}

int solution(vector<int> nums) 
{
    int answer = 0;

    int numsSize = nums.size();

    for (int i = 0; i < numsSize; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            for (int k = j + 1; k < numsSize; k++)
            {
                int num = nums[i] + nums[j] + nums[k];

                if (IsPrime(num))
                    answer++;
            }
        }
    }

    return answer;
}
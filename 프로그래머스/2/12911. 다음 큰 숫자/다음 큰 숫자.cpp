#include <string>
#include <vector>

using namespace std;

int countSetBits(int n) { return popcount(static_cast<unsigned int>(n)); }

int solution(int n) 
{
    int target_count = countSetBits(n);

    int answer = n + 1;
    while (countSetBits(answer) != target_count) 
    { 
        answer++;
    }

    return answer;
}
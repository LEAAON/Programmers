#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) 
{
    int answer = 0;

    for (int i = 0; i < absolutes.size(); i++)
    {
        int num = absolutes[i];
        if (signs[i] == false)
        {
            num *= -1;
        }

        answer += num;
    }

    return answer;
}
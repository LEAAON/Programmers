#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) 
{
    vector<bool> check(10, false);

    for (int index : numbers)
    {    
        check[index] = true;
    }

    int answer = 0;

    for (int i = 0; i < check.size(); i++)
    {
        if (check[i] == false)
        {    
            answer += i;
        }
    }

    return answer;
}
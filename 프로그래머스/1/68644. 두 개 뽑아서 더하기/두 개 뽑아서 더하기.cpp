#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers) 
{
    vector<int> answer;

    set<int> sum;

    for (int i = 0; i < numbers.size(); i++)
    {
        for (int j = i + 1; j < numbers.size(); j++)
        {
            int temp = numbers[i] + numbers[j];
            sum.insert(temp);
        }
    }

    for (int num : sum)
    {    
        answer.push_back(num);
    }

    return answer;
}
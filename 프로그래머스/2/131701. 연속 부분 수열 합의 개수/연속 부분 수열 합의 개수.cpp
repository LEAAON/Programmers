#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> elements) 
{
    int size = elements.size(); 
    unordered_set<int> sums;

    int answer = 0;

    for (int i = 0; i < size; i++)
    {
        int sum = 0;

        for (int j = 0; j < size; j++)
        {
            sum += elements[(i + j) % size];
            sums.insert(sum);
        }
    }

    answer = sums.size();

    return answer;
}
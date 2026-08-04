#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(vector<int> weights) 
{
    long long answer = 0;
    vector<int> _weights = weights;

    sort(_weights.begin(), _weights.end());

    for (int i = 0; i < _weights.size() - 1; i++)
    {
        int n = _weights[i];

        for (int j = i + 1; j < _weights.size(); j++)
        {
            if (_weights[j] == n)
                answer++;
            else if (_weights[j] == n * 2)
                answer++;
            else if (_weights[j] * 2 == n * 3)
                answer++;
            else if (_weights[j] * 3 == n * 4)
                answer++;
        }
        
    }

    return answer;
}
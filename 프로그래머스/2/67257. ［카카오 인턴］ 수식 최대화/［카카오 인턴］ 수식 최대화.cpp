#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

long long Oper(vector<long long> numbers, vector<char> operaters, vector<char> ops)
{
    for (char op : ops) 
    {
        for (size_t i = 0; i < operaters.size(); ) 
        {
            if (operaters[i] == op) 
            {
                if (op == '+') 
                    numbers[i] += numbers[i + 1];
                else if (op == '-') 
                    numbers[i] -= numbers[i + 1];
                else if (op == '*') 
                    numbers[i] *= numbers[i + 1];

                numbers.erase(numbers.begin() + i + 1);
                operaters.erase(operaters.begin() + i);
            }
            else 
            {
                i++;
            }
        }
    }

    return abs(numbers[0]);
}

long long solution(string expression) 
{
    vector<long long> numbers;
    vector<char> operaters;
    long long answer = 0;

    stringstream ss(expression);

    long long num{};
    char op{};
    if (ss >> num)
        numbers.push_back(num);

    while (ss >> op >> num) 
    {
        operaters.push_back(op);
        numbers.push_back(num);
    }

    vector<char> ops = { '+', '-', '*' };
    sort(ops.begin(), ops.end());

    do 
    {
        long long result = Oper(numbers, operaters, ops);
        answer = max(answer, result);
    } while (next_permutation(ops.begin(), ops.end()));

    return answer;
}
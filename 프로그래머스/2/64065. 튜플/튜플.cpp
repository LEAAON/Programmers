#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

vector<int> solution(string s) 
{
    vector<vector<int>> tuples;

    vector<int> numbers;
    string number = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (isdigit(s[i]))
        {
            number += s[i];
        }
        else if (s[i] == ',')
        {
            if (number.empty())
                continue;

            numbers.push_back(stoi(number));
            number = "";
            continue;
        }
        else if (s[i] == '}')
        {
            if (number.empty() == false)
            {
                numbers.push_back(stoi(number));
                number = "";
            }

            if (numbers.empty())
                continue;

            tuples.push_back(numbers);
            numbers.clear();
            continue;
        }
    }

    sort(tuples.begin(), tuples.end(), 
        [](vector<int>& a, vector<int>& b) { return a.size() < b.size(); });

    unordered_set<int> set;
    vector<int> answer;

    for (const vector<int>& t : tuples)
    {
        for (int n : t)
        {
            auto iter = set.find(n);
            if (iter == set.end())
            {
                answer.push_back(n);
                set.insert(n);
            }
        }
    }

    return answer;
}
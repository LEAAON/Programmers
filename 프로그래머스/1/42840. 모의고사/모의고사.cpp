#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) 
{
    vector<int> result;

    vector<int> fi = { 1, 2, 3, 4, 5 };
    vector<int> se = { 2, 1, 2, 3, 2, 4, 2, 5 };
    vector<int> th = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

    int maxScore = 0;
    vector<int> scores(3, 0);

    for (int i = 0; i < answers.size(); i++)
    {
        int answer = answers[i];

        if (answer == fi[i % fi.size()])
            scores[0]++;

        if (answer == se[i % se.size()])
            scores[1]++;

        if (answer == th[i % th.size()])
            scores[2]++;

        for (auto sc : scores)
            maxScore = max(maxScore, sc);
    }

    for (int i = 0; i < scores.size(); i++)
    {
        if (scores[i] == maxScore)
            result.push_back(i + 1);
    }

    return result;
}
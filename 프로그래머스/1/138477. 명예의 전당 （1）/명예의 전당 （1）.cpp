#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score) 
{
    vector<int> ranks;
    ranks.reserve(k);
    vector<int> answer;
    answer.reserve(score.size());

    for (int i = 0; i < score.size(); i++)
    {
        if (ranks.size() < k)
            ranks.push_back(score[i]);
        else
        {
            bool isBigScore = false;

            for (int j = 0; j < ranks.size(); j++)
            {
                if (ranks[j] < score[i])
                {
                    isBigScore = true;
                    break;
                }
            }

            if (isBigScore)
                ranks[ranks.size() - 1] = score[i];
        }

        sort(ranks.begin(), ranks.end(), greater<int>());

        if (ranks.size() < k)
            answer.push_back(ranks[ranks.size() - 1]);
        else
            answer.push_back(ranks[k - 1]);
    }


    return answer;
}
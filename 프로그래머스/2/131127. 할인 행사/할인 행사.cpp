#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount)
{
    int answer = 0;

    unordered_map<string, int> wantMap;
    for (int i = 0; i < want.size(); ++i)
        wantMap[want[i]] = number[i];

    for(int i = 0; i <= discount.size() - 10; i++)
    {
        unordered_map<string, int> findMap;

        for (int j = i; j < 10 + i; j++)
            findMap[discount[j]]++;

        // check
        bool sign = true;
        for (const auto& pair : wantMap)
        {
            auto iter = findMap.find(pair.first);
            if (iter == findMap.end() || iter->second != pair.second)
            {
                sign = false;
                break;
            }
        }

        if (sign)
            answer++;
    }

    return answer;
}
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <utility>

using namespace std;

vector<int> solution(int N, vector<int> stages) 
{
    vector<int> answer;
    answer.reserve(N);

    double totalPer = stages.size();

    unordered_map<int, int> stageMap;
    for (int stage : stages)
        stageMap[stage]++;
    
    vector<pair<double, int>> failed;
    failed.reserve(N);

    for (int i = 1; i <= N; i++)
    {
        int count = stageMap[i];

        double fail = 0.0;
        if (totalPer > 0)
            fail = (double)count / totalPer;

        totalPer -= count;

        failed.push_back({ fail, i });
    }

    sort(failed.begin(), failed.end(), [](const pair<double, int>& a, const pair<double, int>& b) 
        {
            if (a.first == b.first)
                return a.second < b.second;

            return a.first > b.first;
        });

    for (const auto& fail : failed)
        answer.push_back(fail.second);

    return answer;
}
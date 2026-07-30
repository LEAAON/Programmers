#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) 
{
    int answer = 1;

    unordered_map<string, vector<string>> pair;
    for (const auto& vec : clothes)
    {
        auto iter = pair.find(vec[1]);
        if (iter != pair.end())
            (iter->second).push_back(vec[0]);
        else
            pair.emplace(vec[1], vector<string>({ vec[0] }));
    }

    for (const auto& map : pair)
    {
        int size = map.second.size() + 1;
        answer *= size;
    }

    return answer - 1;
}
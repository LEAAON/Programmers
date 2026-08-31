#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) 
{
    string answer = "";

    unordered_map<string, int> hashs;

    for (auto name : participant)
        hashs[name]++;

    for (auto name : completion)
        hashs[name]--;

    for (auto hash : hashs)
    {
        if (hash.second == 1)
        {
            answer = hash.first;
            break;
        }
    }

    return answer;
}
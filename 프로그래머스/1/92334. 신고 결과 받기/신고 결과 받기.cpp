#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <unordered_map>
#include <utility>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) 
{
    vector<int> answer;

    unordered_map<string, int> userList;
    unordered_map<string, set<string>> reports;

    for (int i = 0; i < id_list.size(); i++)
    {
        userList[id_list[i]] = 0;
        reports[id_list[i]] = set<string>();
    }

    for (int i = 0; i < report.size(); i++)
    {
        stringstream ss(report[i]);

        string reporter, reportedUser;
        ss >> reporter >> reportedUser;

        reports[reportedUser].insert(reporter);
    }

    for (const auto& pair : reports)
    {
        if (pair.second.size() < k)
            continue;

        for (const auto& setUser : pair.second)
        {
            userList[setUser]++;
        }
    }

    for (const string& id : id_list)
    {
        answer.push_back(userList[id]);
    }

    return answer;
}
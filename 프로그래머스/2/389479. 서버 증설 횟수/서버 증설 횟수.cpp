#include <string>
#include <vector>

using namespace std;

void SetPlayerCount(vector<int>& playerCount, int totalServer, int m)
{
    playerCount[0] = totalServer * m;
    playerCount[1] = (totalServer + 1) * m;
}

void SetTotalServer(int& totalServer, const vector<pair<int, int>>& servers)
{
    int total = 0;

    for (const pair<int, int>& server : servers)
        total += server.first;

    totalServer = total;
}

void UpdateServer(vector<pair<int, int>>& servers)
{
    if (servers.empty())
        return;

    for (pair<int, int>& server : servers)
        server.second--;

    auto iter = servers.begin();
    while (iter != servers.end())
    {
        if (iter->second == 0)
            iter = servers.erase(iter);
        else
            iter++;
    }
}

int solution(vector<int> players, int m, int k) 
{
    int answer = 0;

    vector<int> playerCount = { m, m + 1 };
    int totalServer = 0;

    vector<pair<int, int>> servers;

    for (int i = 0; i < players.size(); i++)
    {
        int player = players[i];

        int serverC = player / m;
        if (totalServer < serverC)
        {
            pair<int, int> addServer = { serverC - totalServer, k };
            servers.push_back(addServer);

            SetTotalServer(totalServer, servers);

            answer += addServer.first;
        }

        SetPlayerCount(playerCount, totalServer, m);

        UpdateServer(servers);

        SetTotalServer(totalServer, servers);
    }

    return answer;
}
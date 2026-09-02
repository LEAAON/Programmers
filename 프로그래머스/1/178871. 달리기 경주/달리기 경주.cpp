#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) 
{
    unordered_map<string, int> name_to_idx;
    for (int i = 0; i < players.size(); i++)
        name_to_idx[players[i]] = i;

    for (const string& name : callings)
    {
        int curr_idx = name_to_idx[name];
        int prev_idx = curr_idx - 1;

        string prev_player = players[prev_idx];

        swap(players[curr_idx], players[prev_idx]);

        name_to_idx[name] = prev_idx;
        name_to_idx[prev_player] = curr_idx;
    }

    return players;
}
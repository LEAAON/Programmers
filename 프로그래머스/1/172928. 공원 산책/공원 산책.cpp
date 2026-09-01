#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) 
{
    unordered_map<char, vector<int>> move;
    move['N'] = { -1, 0 };
    move['S'] = { 1, 0 };
    move['W'] = { 0, -1 };
    move['E'] = { 0, 1 };

    int H = park.size();
    int W = park[0].size();

    int r{}, c{};

    for (int i = 0; i < H; i++)
    {
        bool set = false;
        for (int j = 0; j < W; j++)
        {
            if (park[i][j] == 'S')
            {
                r = i;
                c = j;
                set = true;
                break;
            }
        }

        if (set == true)
            break;
    }

    for (const auto& route : routes)
    {
        stringstream ss(route);
        char dir{};
        int dist{};

        ss >> dir >> dist;
        
        int nr = r;
        int nc = c;

        int dr = move[dir][0];
        int dc = move[dir][1];
        bool is_ok = true;

        for (int i = 0; i < dist; i++)
        {
            nr += dr;
            nc += dc;

            if (nr < 0 || nr >= H || nc < 0 || nc >= W || park[nr][nc] == 'X')
            {
                is_ok = false;
                break;
            }
        }

        if (is_ok == true)
        {
            r = nr;
            c = nc;
        }

    }

    return { r, c };
}
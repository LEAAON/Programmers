#include <string>
#include <vector>
#include <set>
using namespace std;

const vector<int> maxCoordinate = { 5, 5 };
const vector<int> minCoordinate = { -5, -5 };

bool IsValid(vector<int> pos, vector<int> dir)
{
    if (pos[0] + dir[0] > 5 || pos[0] + dir[0] < -5)
        return false;
    if (pos[1] + dir[1] > 5 || pos[1] + dir[1] < -5)
        return false;

    return true;
}

int solution(string dirs)
{
    set<vector<int>> visit;

    int answer = 0;

    vector<int> pos = { 0, 0 };
    for (const auto& dir : dirs)
    {
        vector<int> direction(2, 0);

        switch (dir)
        {
        case 'U':
            direction[1] += 1;
            break;
        case 'D':
            direction[1] -= 1;
            break;
        case 'R':
            direction[0] += 1;
            break;
        case 'L':
            direction[0] -= 1;
            break;
        }

        if (IsValid(pos, direction) == false)
            continue;

        vector<int> nextPos = { pos[0] + direction[0], pos[1] + direction[1] };

        visit.insert({ pos[0], pos[1], nextPos[0], nextPos[1] });
        visit.insert({ nextPos[0], nextPos[1], pos[0], pos[1] });
        
        pos = nextPos;
    }

    answer = visit.size() / 2;

    return answer;
}
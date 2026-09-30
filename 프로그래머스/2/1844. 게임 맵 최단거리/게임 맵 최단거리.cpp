#include<vector>
#include <queue>
using namespace std;



int solution(vector<vector<int>> maps)
{
    const int dx[4] = { 0, 0, -1, 1 };
    const int dy[4] = { -1, 1, 0, 0 };

    struct Point
    {
        int y{};
        int x{};
        int dist{};
    };
    
    int row = maps.size();
    int col = maps[0].size();

    queue<Point> q;

    q.push({ 0, 0, 1 });
    maps[0][0] = 0;

    while (q.empty() != true)
    {
        Point cur = q.front();
        q.pop();

        if (cur.y == row - 1 && cur.x == col -1)
        {
            return cur.dist;
        }

        for (int i = 0; i < 4; i++) 
        {
            int ny = cur.y + dy[i];
            int nx = cur.x + dx[i];

            if (ny >= 0 && ny < row && nx >= 0 && nx < col) 
            {
                if (maps[ny][nx] == 1) 
                {
                    maps[ny][nx] = 0;
                    q.push({ ny, nx, cur.dist + 1 });
                }
            }
        }
    }

    return -1;
}
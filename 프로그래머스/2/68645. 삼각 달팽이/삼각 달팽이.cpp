#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) 
{
    vector<vector<int>> tri(n);
    for (int i = 0; i < n; i++)
        tri[i].resize(i + 1);

    vector<int> pos{ 0, -1 };
    // 0 -> Down / 1 -> Right / 2 -> LeftUp
    int dir = 0;

    int num = 1;
    int index = n;

    while (index > 0)
    {
        for (int i = index; i > 0; i--)
        {
            if (dir == 0)
            {
                pos[1] += 1;
            }
            else if (dir == 1)
            {
                pos[0] += 1;
            }
            else if (dir == 2)
            {
                pos[0] -= 1;
                pos[1] -= 1;
            }
                
            tri[pos[1]][pos[0]] = num++;
        }

        index--;
        dir = (dir + 1) % 3;
    }
    
    vector<int> answer;

    for (int i = 0; i < tri.size(); i++)
    {
        for (int j = 0; j < tri[i].size(); j++)
            answer.push_back(tri[i][j]);
    }

    return answer;
}
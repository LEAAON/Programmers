#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool IsViable(vector<vector<string>>& park, int matSize, int indexX, int indexY)
{
    int parkWidth = park[0].size();
    int parkHeight = park.size(); 

    for (int y = 0; y < matSize; y++)
    {
        for (int x = 0; x < matSize; x++)
        {
            if (indexY + y >= parkHeight)
                return false;
            if (indexX + x >= parkWidth)
                return false;

            if (park[indexY + y][indexX + x] != "-1")
                return false;
        }
    }

    return true;
}

int solution(vector<int> mats, vector<vector<string>> park) 
{
    int answer = -1;

    int size = -1;
    int indexX{-1}, indexY{-1};

    for (int matSize : mats)
    {

        int height = park.size();
        for (int i = 0; i <= height - matSize; i++)
        {
            int width = park[i].size();
            for (int j = 0; j <= width - matSize; j++)
            {
                if (park[i][j] != "-1")
                    continue;

                if (IsViable(park, matSize, j, i))
                    size = matSize;
            }
        }

        answer = max(answer, size);
    }

    return answer;
}
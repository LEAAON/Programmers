#include <string>
#include <vector>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) 
{
    vector<double> answer;

    vector<int> sequences;
    sequences.push_back(k);
    while (k != 1)
    {
        if (k % 2 == 0)
            k /= 2;
        else
            k = (k * 3) + 1;

        sequences.push_back(k);
    }

    int totalRange = sequences.size() - 1;

    vector<double> extents;
    extents.reserve(totalRange);
    for (size_t i = 0; i < totalRange; i++)
    {
        double extent = static_cast<double>(sequences[i] + sequences[i + 1]) / 2.0;
        extents.push_back(extent);
    }

    for (size_t i = 0; i < ranges.size(); i++)
    {
        double result = 0.0;

        int startIndex = ranges[i][0];
        int endIndex = totalRange + ranges[i][1];

        if (endIndex < startIndex)
        {
            result = -1.0;
        }
        else
        {
            for (int j = startIndex; j < endIndex; j++)
            {
                result += extents[j];
            }
        }

        answer.push_back(result);
    }

    return answer;
}
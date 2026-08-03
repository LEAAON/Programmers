#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2)
{
    vector<string> answer;
    int size = n * n;
    vector<bool> secretMap(size, false);

    int index = 0;
    for (int i = 0; i < n; i++)
    {
        int num = arr1[i] | arr2[i];

        for (int j = n - 1; j >= 0; --j)
        {
            bool temp = (num >> j) & 1;
            secretMap[index++] = temp;
        }
    }

    string line{};
    for (int i = 0; i < size; ++i)
    {
        if (secretMap[i] == true)
            line += "#";
        else
            line += " ";

        if (i == 0)
            continue;

        if ((i + 1) % n == 0)
        {
            answer.push_back(line);
            line = "";
        }
    }

    return answer;
}
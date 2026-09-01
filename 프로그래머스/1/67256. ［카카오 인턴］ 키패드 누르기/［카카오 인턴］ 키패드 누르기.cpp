#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<int> numbers, string hand) 
{
    unordered_map<int, vector<int>> pad;
    pad[0] = { 3, 1 };
    pad[1] = { 0, 0 };
    pad[2] = { 0, 1 };
    pad[3] = { 0, 2 };
    pad[4] = { 1, 0 };
    pad[5] = { 1, 1 };
    pad[6] = { 1, 2 };
    pad[7] = { 2, 0 };
    pad[8] = { 2, 1 };
    pad[9] = { 2, 2 };

    vector<int> left  = { 3, 0 };
    vector<int> right = { 3, 2 };

    string answer = "";

    for (int i = 0; i < numbers.size(); i++)
    {
        int number = numbers[i];

        if (number == 1 || number == 4 || number == 7)
        {
            left = pad[number];
            answer += "L";
            continue;
        }
        else if(number == 3 || number == 6 || number == 9)
        {
            right = pad[number];
            answer += "R";
            continue;
        }

        int distL = 0;
        int distR = 0;

        vector<int> numberPos = pad[number];

        distL = abs(left[0] - numberPos[0]) + abs(left[1] - numberPos[1]);
        distR = abs(right[0] - numberPos[0]) + abs(right[1] - numberPos[1]);

        if (distL < distR)
        {
            left = pad[number];
            answer += "L";
            continue;
        }
        else if (distL > distR)
        {
            right = pad[number];
            answer += "R";
            continue;
        }
        else
        {
            if (hand == "right")
            {
                right = pad[number];
                answer += "R";
                continue;
            }
            else if (hand == "left")
            {
                left = pad[number];
                answer += "L";
                continue;
            }
        }
    }

    return answer;
}
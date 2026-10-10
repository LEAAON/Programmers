#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
    int answer = 0;

    vector<string> strVec;

    string str;
    for (auto& ch : s)
    {
        switch (ch)
        {
        case ' ':
            strVec.push_back(str);
            str.clear();
            break;
        default:
            str += ch;
            break;
        }
    }

    if (!str.empty())
    {
        strVec.push_back(str);
        str.clear();
    }

    int iForSize = strVec.size();
    for (int i = 0; i < iForSize; i++)
    {
        if (strVec[i] == "Z" && i > 0)
        {
            answer -= stoi(strVec[i - 1]);
        }
        else
        {    
            answer += stoi(strVec[i]);
        }
    }

    return answer;
}
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(string msg) 
{
    vector<int> answer;
    unordered_map<string, int> dic;
    for (int i = 0; i < 26; i++)
    {
        string ch(1, 'A' + i);
        dic[ch] = i + 1;
    }

    int index = 0;
    while (index < msg.size())
    {
        int output = 0;
        string w = "";
        string c = "";

        for (int i = index; i < msg.size(); i++)
        {
            w += msg[i];

            if (i + 1 < msg.size())
                c += msg[i + 1];
            else
                break;

            string temp = w + c;

            auto iter = dic.find(temp);
            if (iter != dic.end())
            {
                c = "";
                continue;
            }

            int num = dic.size() + 1;
            dic[temp] = num;
            break;
        }
        
        output = dic[w];
        answer.push_back(output);

        index += w.size();
    }

    return answer;
}
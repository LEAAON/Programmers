#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> babbling) 
{
    int answer = 0;

    vector<string> words = { "aya", "ye", "woo", "ma" };
    vector<string> repeats = { "ayaaya", "yeye", "woowoo", "mama" };
    std::string replacement = " ";

    for (auto str : babbling)
    {
        bool is_valid = true;

        for (auto rep : repeats)
        {
            if (str.find(rep) != string::npos)
            {
                is_valid = false;
                break;
            }
        }

        if (is_valid == false)
            continue;

        for (auto w : words)
        {
            size_t pos = str.find(w);

            while (pos != std::string::npos) 
            {
                str.replace(pos, w.length(), replacement);

                pos = str.find(w, pos + replacement.length());
            }
        }

        str.erase(std::remove(str.begin(), str.end(), ' '), str.end());

        if (str.size() == 0)
            answer++;
    }

    return answer;
}
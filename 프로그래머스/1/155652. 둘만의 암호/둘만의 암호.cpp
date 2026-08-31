#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) 
{
    string valid = "";
    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        if (skip.find(ch) == string::npos)
            valid += ch;
    }

    string answer = "";

    for (auto ch : s)
    {
        size_t current_idx = valid.find(ch);

        auto next_idx = (current_idx + index) % valid.length();
        
        answer += valid[next_idx];
    }

    return answer;
}
#include <string>
#include <vector>

using namespace std;

string solution(string new_id) 
{
    string answer = "";

    for (auto ch : new_id)
    {
        if (isalnum(ch)) 
        {
            answer += tolower(ch);
        }
        else if (ch == '-' || ch == '_' || ch == '.')
        {
            answer += ch;
        }
    }

    string step3 = "";
    for (auto ch : answer)
    {
        if (ch == '.' && !step3.empty() && step3.back() == '.')
            continue;
        
        step3 += ch;
    }
    
    answer = step3;

    if (!answer.empty() && answer.front() == '.')
        answer.erase(answer.begin());

    if (!answer.empty() && answer.back() == '.')
        answer.pop_back();

    if (answer.empty())
        answer = "a";

    if (answer.size() > 15)
    {
        answer = answer.substr(0, 15);
        
        if (answer.back() == '.')
        answer.pop_back();
    }

    while (answer.length() <= 2) 
    {
        answer += answer.back();
    }

    return answer;
}
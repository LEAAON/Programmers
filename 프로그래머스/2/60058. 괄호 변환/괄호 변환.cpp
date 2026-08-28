#include <string>
#include <vector>
#include <stack>

using namespace std;

bool CheckValid(string u)
{
    stack<char> brackets;

    for (char ch : u)
    {
        if (ch == '(')
        {
            brackets.push(ch);
        }
        else
        {
            if (brackets.empty())
                return false;

            brackets.pop();
        }
    }

    if (!brackets.empty())
        return false;
        
    return true;
}   

string solution(string p) 
{
    if (p.empty())
        return "";

    size_t left_count = 0;
    size_t right_count = 0;
    string u = "";
    string v = "";

    for (size_t i = 0; i < p.size(); i++)
    {
        if (p[i] == '(')
            left_count++;
        else
            right_count++;

        if (left_count == right_count)
        {
            u = p.substr(0, i + 1);
            v = p.substr(i + 1);
            break;
        }
    }

    if (CheckValid(u) == true)
    {
        return u + solution(v);
    }
    else
    {
        string result = "(";
        result += solution(v);
        result += ")";

        if (u.size() > 2)
        {
            string u_trimmed = u.substr(1, u.size() - 2);

            for (char ch : u_trimmed)
            {
                if (ch == '(')
                {
                    result += ')';
                }
                else
                {
                    result += '(';
                }
            }
        }

        return result;
    }
}
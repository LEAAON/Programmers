#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) 
{
    string answer = "";

    for (auto ch : number)
    {
        while (!answer.empty() && answer.back() < ch && k >0)
        {
            answer.pop_back();
            k -= 1;
        }

        answer.push_back(ch);
    }

    while (k > 0)
    {
        answer.pop_back();
        k -= 1;
    }

    return answer;
}
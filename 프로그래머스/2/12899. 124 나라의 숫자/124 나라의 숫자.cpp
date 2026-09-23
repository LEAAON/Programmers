#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n) 
{
    string answer = "";
    string chars = "124";

    while (n > 0) {
        n--;
        answer += chars[n % 3];
        n /= 3;
    }
    
    reverse(answer.begin(), answer.end());

    return answer;
}
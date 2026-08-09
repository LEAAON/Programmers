#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) 
{
    vector<string> day = { "THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED" };
    vector<int> month = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    int count = b;
    for (int i = 0; i < a - 1; i++)
        count += month[i];

    count %= 7;

    return day[count];
}
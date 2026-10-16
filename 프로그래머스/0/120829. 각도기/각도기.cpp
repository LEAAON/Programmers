#include <string>
#include <vector>

using namespace std;

int solution(int angle) 
{
    if(angle == 180)
    {
        return 4;
    }
    else if(angle == 90)
    {
        return 2;
    }
    else if(angle < 90)
    {
        return 1;
    }
    else
    {
        return 3;
    }
}
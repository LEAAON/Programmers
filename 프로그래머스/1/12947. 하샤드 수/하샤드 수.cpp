#include <string>
#include <vector>

using namespace std;

bool solution(int x) 
{
    int number = x;
    int sum = 0;
    while(x > 0)
    {
        sum += (x % 10);
        x /= 10;
    }
    
    if(number % sum == 0)
        return true;
    else
        return false;
    
}
#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) 
{
    int x{3}, y{3};

    x = ((4 + brown) + sqrt((4 + brown) * (4 + brown) - 16 * (brown + yellow))) / 4;
    y = ((4 + brown) - sqrt((4 + brown) * (4 + brown) - 16 * (brown + yellow))) / 4;

    return { x, y };
}
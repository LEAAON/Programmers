#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations)
{
    int size = citations.size();

    sort(citations.begin(), citations.end());

    for (int i = 0; i < size; i++)
    {
        int h = size - i;
        
        if (citations[i] >= h)
            return h;
    }

    return 0;
}
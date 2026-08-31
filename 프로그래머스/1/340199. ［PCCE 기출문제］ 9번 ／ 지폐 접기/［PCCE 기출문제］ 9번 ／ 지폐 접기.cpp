#include <vector>
#include <utility>

using namespace std;

void SortBox(vector<int>& box)
{
    if (box[0] < box[1])
        swap(box[0], box[1]);

    return;
}

int solution(vector<int> wallet, vector<int> bill) 
{
    int answer = 0;

    SortBox(wallet);
    SortBox(bill);

    while (wallet[0] < bill[0] || wallet[1] < bill[1])
    {
        bill[0] = bill[0] / 2;
        answer++;
        SortBox(bill);
    }

    return answer;
}
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int GetRank(int count)
{
    if (count >= 2)
        return 7 - count;
    else
        return 6;
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) 
{
    int zero_count = 0;
    int min_match = 0;

    for (auto num : lottos)
    {
        if (num == 0)
            zero_count++;
        else if (find(win_nums.begin(), win_nums.end(), num) != win_nums.end())
            min_match++;
    }

    int max_match = min_match + zero_count;

    int highest_rank = GetRank(max_match);
    int lowest_rank = GetRank(min_match);

    return { highest_rank, lowest_rank };
}
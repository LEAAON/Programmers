#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

int solution(vector<int> nums)
{
    unordered_set<int> pokemon(nums.begin(), nums.end());
    
    return min(pokemon.size(), nums.size() / 2);
}
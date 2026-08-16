#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

int UpdateCache(vector<string>& cache, int cacheSize, string city)
{
    if (cacheSize == 0)
        return 5;
    
    for (char& c : city)
        c = tolower(c);

    auto iter = find(cache.begin(), cache.end(), city);
    if (iter != cache.end())
    {
        cache.erase(iter);
        cache.push_back(city);
        return 1;
    }

    if (cache.size() == cacheSize)
        cache.erase(cache.begin());

    cache.push_back(city);

    return 5;
}

int solution(int cacheSize, vector<string> cities) 
{
    vector<string> cache;
    cache.reserve(cacheSize);

    int answer = 0;

    for (string city : cities)
        answer += UpdateCache(cache, cacheSize, city);

    return answer;
}
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> solution(int n, vector<string> words) 
{
    unordered_set<string> word;

    char lastAlpha{};

    word.insert(words[0]);
    lastAlpha = words[0].back();

    for (int i = 1; i < words.size(); i++)
    {
        auto iter = word.find(words[i]);
        if (iter != word.end())
            return { (i % n) + 1, (i / n) + 1 };

        if(words[i][0] != lastAlpha)
            return { (i % n) + 1, (i / n) + 1 };

        word.insert(words[i]);
        lastAlpha = words[i].back();
    }

    return {0, 0};
}
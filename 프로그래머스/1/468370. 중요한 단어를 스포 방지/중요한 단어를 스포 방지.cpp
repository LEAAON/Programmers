#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(string message, vector<vector<int>> spoiler_ranges) 
{
    int answer = 0;

    unordered_set<string> words;

    struct WORD
    {
        string word = "";
        bool spoiler = false;
    };

    vector<WORD> splitWords;

    string word = "";

    bool isSpoiler = false;
    int spoilderIndex = 0;
    for (int i = 0; i < message.size(); i++)
    {
        if (message[i] == ' ')
        {
            WORD w;
            w.word = word;
            w.spoiler = isSpoiler;

            if (isSpoiler == false)
                words.insert(word);

            splitWords.push_back(w);
            word = "";
            isSpoiler = false;

            if (spoilderIndex >= spoiler_ranges.size())
                continue;

            int endIndex = spoiler_ranges[spoilderIndex][1];
            if (i == endIndex)
                spoilderIndex += 1;

            continue;
        }

        word += message[i];

        if (spoilderIndex >= spoiler_ranges.size())
            continue;

        int startIndex = spoiler_ranges[spoilderIndex][0];
        int endIndex = spoiler_ranges[spoilderIndex][1];

        if (i == endIndex)
            spoilderIndex += 1;

        if (isSpoiler)
            continue;

        if (i >= startIndex && i <= endIndex)
            isSpoiler = true;
    }

    if (!word.empty())
    {
        WORD w;
        w.word = word;
        w.spoiler = isSpoiler;

        if (isSpoiler == false)
            words.insert(word);

        splitWords.push_back(w);
        word = "";
        isSpoiler = false;
    }

    for (WORD w : splitWords)
    {
        auto iter = words.find(w.word);
        if (iter != words.end())
            continue;

        if (w.spoiler == true)
        {
            words.insert(w.word);
            answer++;
        }
        else
        {
            words.insert(w.word);
        }
    }

    return answer;
}
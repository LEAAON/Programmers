#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) 
{
    unordered_map<string, int> friendID;
    int friend_idx = 0;
    for (const string& name : friends)
        friendID[name] = friend_idx++;

    int friendSize = friends.size();
    vector<vector<int>> gift_matrix(friendSize, vector<int>(friendSize, 0));
    
    vector<int> gift_score(friendSize, 0);

    for (int i = 0; i < gifts.size(); i++)
    {
        stringstream ss(gifts[i]);
        string giver, receiver;
        ss >> giver >> receiver;
        gift_matrix[friendID[giver]][friendID[receiver]]++;

        gift_score[friendID[giver]]++;
        gift_score[friendID[receiver]]--;
    }

    vector<int> nextMonthGift(friendSize, 0);

    for (int i = 0; i < friendSize; i++)
    {
        for (int j = i + 1; j < friendSize; j++)
        {
            if (gift_matrix[i][j] > gift_matrix[j][i])
            {
                nextMonthGift[i]++;
            }
            else if (gift_matrix[i][j] < gift_matrix[j][i])
            {
                nextMonthGift[j]++;
            }
            else
            {
                if (gift_score[i] > gift_score[j])
                    nextMonthGift[i]++;
                else if (gift_score[j] > gift_score[i])
                    nextMonthGift[j]++;
            }
        }
    }

    int answer = 0;

    for (int count : nextMonthGift)
        answer = max(answer, count);

    return answer;
}
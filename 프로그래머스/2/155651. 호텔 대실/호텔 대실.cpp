#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int StringToTime(string time)
{
    string h = time.substr(0, 2);
    string m = time.substr(3, 2);

    int hour = stoi(h);
    int min = stoi(m);

    return hour * 60 + min;
}

int solution(vector<vector<string>> book_time) 
{ 
    vector<pair<int, int>> reservations;
    for (const auto& book : book_time) 
    {
        int start = StringToTime(book[0]);
        int end = StringToTime(book[1]) + 10;
        reservations.push_back({ start, end });
    }

    sort(reservations.begin(), reservations.end());

    priority_queue<int, vector<int>, greater<int>> pq;

    for (const auto& res : reservations) 
    {
        int start = res.first;
        int end = res.second;

        if (!pq.empty() && pq.top() <= start) 
        {
            pq.pop();
        }

        pq.push(end);
    }

    return pq.size();
}
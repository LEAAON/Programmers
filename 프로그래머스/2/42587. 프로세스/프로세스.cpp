#include <string>
#include <vector>
#include <utility>
#include <list>
#include <iterator>

using namespace std;

int solution(vector<int> priorities, int location) 
{
    int answer = 0;

    int size = priorities.size();
    list<pair<int, int>> pq;
   
    for (int i = 0; i < size; i++)
        pq.push_back({ priorities[i], i });

    while (!pq.empty())
    {
        auto cur = pq.front();
        bool has_higher = false;

        for (auto it = next(pq.begin()); it != pq.end(); ++it) 
        {
            if (it->first > cur.first) 
            {
                has_higher = true;
                break;
            }
        }

        if (has_higher) 
        {
            pq.splice(pq.end(), pq, pq.begin());
        }
        else 
        {
            pq.pop_front();
            answer++;

            if (cur.second == location) 
                return answer;
        }
    }

    return answer;
}
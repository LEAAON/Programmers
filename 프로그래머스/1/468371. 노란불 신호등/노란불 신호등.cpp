#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> signals)
{
    int answer = 0;

    vector<int> blinker(signals.size(), 0);

    for (int time = 1; time <= 3200000; time++)
    {
        bool all_yellow = true;

        for (int i = 0; i < blinker.size(); i++)
        {
            blinker[i]++;

            int G = signals[i][0];
            int Y = signals[i][1];
            int R = signals[i][2];

            int sum = G + Y + R;
            
            int curTime = (blinker[i] - 1) % sum;
            if (curTime < G || curTime >= G + Y)
                all_yellow = false;
        }

        if (all_yellow)
            return time;
    }

    return -1;
}
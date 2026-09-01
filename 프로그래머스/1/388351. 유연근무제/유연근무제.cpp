#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) 
{
    int peopleCount = schedules.size();
    vector<int> times(peopleCount, 0);
    for (int i = 0; i < peopleCount; i++)
    {
        int time = schedules[i] + 10;
        if (time % 100 >= 60)
        {
            time += 100;
            time -= 60;
        }

        times[i] = time;
    }

    vector<bool> peoples(peopleCount, true);

    for (int i = 0; i < 7; i++)
    {
        int currentDay = (startday - 1 + i) % 7;

        if (currentDay >= 5)
            continue;

        for (int j = 0; j < peopleCount; j++)
        {
            if (peoples[j] == false)
                continue;

            if (timelogs[j][i] > times[j])
                peoples[j] = false;
        }
    }

    int answer = 0;

    for (auto people : peoples)
    {
        if (people)
            answer++;
    }

    return answer;
}
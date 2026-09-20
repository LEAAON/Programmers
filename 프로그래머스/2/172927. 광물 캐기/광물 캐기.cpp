#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> picks, vector<string> minerals)
{
    struct Group
    {
        int dia = { 0 };
        int iron = { 0 };
        int stone = { 0 };

        int m_iFatigue = { 0 };

        void AddMineral(string mineral)
        {
            if (mineral == "diamond")
            {
                dia += 1;
                m_iFatigue += 25;
            }
            else if (mineral == "iron")
            {
                iron += 1;
                m_iFatigue += 5;
            }
            else if (mineral == "stone")
            {
                stone += 1;
                m_iFatigue += 1;
            }
        }

        int UsePick(int pick) const
        {
            if (pick == 0)
            {
                return dia + iron + stone;
            }
            else if (pick == 1)
            {
                return (dia * 5) + iron + stone;
            }

            return m_iFatigue;
        }
    };

    int pickCount = picks[0] + picks[1] + picks[2];
    int mineralCount = minerals.size();

    int groupCount = min(pickCount, (mineralCount + 4) / 5);
    vector<Group> groups;

    for (int i = 0; i < groupCount; i++)
    {
        Group group;

        for (int j = 0; j < 5; j++)
        {
            int idx = i * 5 + j;
            if (idx >= mineralCount) 
                break;
            group.AddMineral(minerals[idx]);
        }

        groups.push_back(group);
    }

    int answer = 0;

    sort(groups.begin(), groups.end(), 
        [groups](Group a, Group b) 
        {
            return a.m_iFatigue > b.m_iFatigue;
        }
    );

    for (const auto& group : groups)
    {
        if (picks[0] > 0)
        {
            answer += group.UsePick(0);
            picks[0]--;
        }
        else if (picks[1] > 0)
        {
            answer += group.UsePick(1);
            picks[1]--;
        }
        else if (picks[2] > 0)
        {
            answer += group.UsePick(2);
            picks[2]--;
        }
    }

    return answer;
}
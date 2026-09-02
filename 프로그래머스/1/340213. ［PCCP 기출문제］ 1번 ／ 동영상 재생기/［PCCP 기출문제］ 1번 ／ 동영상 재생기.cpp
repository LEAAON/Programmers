#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int ToTime(string time_str)
{
    stringstream ss(time_str);
    string strMinutes, strSeconds;
    
    getline(ss, strMinutes, ':');
    getline(ss, strSeconds, ':');

    int minutes = stoi(strMinutes);
    int seconds = stoi(strSeconds);

    return minutes * 60 + seconds;
}

string TimeToString(int time)
{
    int minutes = time / 60;
    int seconds = time % 60;

    ostringstream oss;
    
    oss << setw(2) << setfill('0') << minutes << ":"
        << setw(2) << setfill('0') << seconds;

    return oss.str();
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) 
{
    string answer = "";

    int curTime = ToTime(pos);

    int videoTime = ToTime(video_len);
    int opSTime = ToTime(op_start);
    int opETime = ToTime(op_end);

    if (curTime >= opSTime && curTime < opETime)
        curTime = opETime;

    for (string command : commands)
    {
        int addTime = 0;

        if (command == "next")
            addTime = 10;
        else if (command == "prev")
            addTime = -10;

        curTime += addTime;

        curTime = max(curTime, 0);
        curTime = min(curTime, videoTime);

        if (curTime >= opSTime && curTime < opETime)
            curTime = opETime;
    }

    answer = TimeToString(curTime);

    return answer;
}
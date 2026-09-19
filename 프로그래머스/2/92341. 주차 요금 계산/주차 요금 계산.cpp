#include <string>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) 
{
    vector<int> answer;

    map<string, int> cars;

    unordered_map<string, int> checks;
    
    for (const string& record : records)
    {
        string h = record.substr(0, 2);
        string m = record.substr(3, 2);
        string car = record.substr(6, 4);
        string check = record.substr(11, 1);

        int time = stoi(h) * 60 + stoi(m);

        if (check == "I")
        {
            checks[car] = time;
        }
        else
        {
            auto iter = checks.find(car);
            int t = time - iter->second;
            cars[car] += t;
            checks.erase(iter);
        }
    }

    for (const auto& check : checks)
    {
        string car = check.first;
        int time = 23 * 60 + 59;
        int t = time - check.second;
        cars[car] += t;
    }

    checks.clear();

    int baseTime = fees[0];
    int basePrice = fees[1];
    int min = fees[2];
    int minPrice = fees[3];

    for (const auto& car : cars)
    {
        int totalTime = car.second;
        int price = basePrice;

        if (totalTime > baseTime) {
            int extraTime = totalTime - baseTime;
            int unitCount = (extraTime + min - 1) / min;
            price += unitCount * minPrice;
        }

        answer.push_back(price);
    }

    return answer;
}
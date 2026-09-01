#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool SetHealth(int& health, int maxHealth, int delta)
{
    health += delta;

    if (health <= 0)
        return false;

    health = min(health, maxHealth);
    
    return true;
}

void Heal(int& health, int maxHealth, int& successTime, const vector<int>& bandage)
{
    successTime++;

    int heal = bandage[1];

    if (successTime == bandage[0])
    {
        heal += bandage[2];
        successTime = 0;
    }

    SetHealth(health, maxHealth, heal);
}

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) 
{
    int _maxHealth = health;
    int _health = _maxHealth;
    int _successTime = 0;

    int _turnCount = 0;
    int _attackIndex = 0;
    int _totalTurn = attacks.back()[0];

    while (true)
    {
        _turnCount++;

        if (attacks[_attackIndex][0] == _turnCount)
        {
            _successTime = 0;

            if (SetHealth(_health, _maxHealth, -attacks[_attackIndex++][1]) == false)
                return -1;

            if (_totalTurn == _turnCount)
                break;

            continue;
        }

        Heal(_health, _maxHealth, _successTime, bandage);

        if (_turnCount >= _totalTurn)
            break;
    }

    return _health;
}
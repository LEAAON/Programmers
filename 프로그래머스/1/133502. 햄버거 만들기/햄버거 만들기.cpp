#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient)
{
    vector<int> correct = { 1, 2, 3, 1 };
    int answer = 0;

    vector<int> stack;
    stack.reserve(ingredient.size());

    for (int i = 0; i < ingredient.size(); i++)
    {
        stack.push_back(ingredient[i]);

        if (stack.size() < 4)
            continue;

        bool isValid = true;
        size_t startIndex = stack.size() - 4;
        for (int j = 0; j < 4; j++)
        {
            if (stack[startIndex + j] == correct[j])
                continue;

            isValid = false;
        }

        if (isValid == false)
            continue;

        for (int j = 0; j < 4; j++)
            stack.pop_back();

        answer++;
    }

    return answer;
}
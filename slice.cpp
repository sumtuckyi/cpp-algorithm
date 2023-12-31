#include <string>
#include <vector>

using namespace std;

vector<int> slicing(vector<int> arr, int x, int y)
{
    return vector<int>(arr.begin() + x, arr.begin() + y + 1);
}

vector<int> solution(vector<int> arr, vector<int> query)
{
    vector<int> answer = arr;
    for (int i = 0; i < query.size(); i++)
    {
        if (i % 2 == 0)
            answer = slicing(answer, 0, query[i]);
        else
            answer = slicing(answer, query[i], answer.size() - 1);
    }
    return answer;
}
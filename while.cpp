#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr)
{
    int answer = 0;
    while (true)
    {
        vector<int> temp = arr; // 작업 이전의 배열을 저장
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] >= 50 && arr[i] % 2 == 0)
                arr[i] /= 2;
            else if (arr[i] < 50 && arr[i] % 2 != 0)
                arr[i] = arr[i] * 2 + 1;
        }
        answer += 1;
        if (temp == arr)
            break;
    }

    return answer - 1;
}
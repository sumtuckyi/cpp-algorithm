#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

void BS(int max_dist, vector<int> arr, int C, int &res)
{
    int start = 1;
    int end = max_dist;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        int idx = arr[0];
        int cnt = 0;
        bool tof = true;
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] - idx >= mid)
            {
                cnt += 1;
                idx = arr[i];
                if (cnt >= C - 1)
                {
                    start = mid + 1;
                    tof = not tof;
                    res = mid;
                    break;
                }
            }
        }
        if (tof)
        {
            end = mid - 1;
        }
    }
}
int main()
{
    int N, C;
    int res; // 정답
    cin >> N >> C;

    // 배열 선언하고 채우기
    vector<int> arr;
    for (int i = 1; i <= N; i++)
    {
        int num;
        cin >> num;
        arr.push_back(num);
    }

    // 배열 정렬하기
    sort(arr.begin(), arr.end());
    // k의 범위 지정을 위해 최대 가능거리 구하기
    int max_dist = arr.back() - arr.front();
    // 이분탐색 수행
    BS(max_dist, arr, C, res);
    cout << res << endl;
}
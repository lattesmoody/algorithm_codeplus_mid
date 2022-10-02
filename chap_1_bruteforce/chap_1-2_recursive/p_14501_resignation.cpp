/*
https://www.acmicpc.net/problem/14501
* 문제 자체를 이해하지 못함.

다이나믹으로 풀 수 있음.
=> 앞의 값에 영향을 받지 않는다.

의미있는 데이터(방법): 최대수익이 나오는.

* memoization
 컴퓨터 프로그램이 동일한 계산을 반복해야 할 때,
 이전에 계산한 값을 메모리에 저장함으로써
 동일한 계산의 반복 수행을 제거하여
 프로그램 실행 속도를 빠르게 하는 기술.

※ 부분 수열의 합은
이전에 선택한 것에 따라 합이 달라짐.
=> 다이나믹이 안됨.

go(day, sum)
- day일이 되었을 때, day일에 있는 상담 할지 말지 결정.
- sum: 지금까지 얻은 수익.

[정답을 찾은 경우]
day == n

[불가능한 경우]
day > n

[다음 조건으로 넘어갈 때]
1. 상담 한다: 해(day + t[day], sum+p[day])
2. 상담을 하지 않는다: go(day+1, sum)
*/

#include <iostream>
using namespace std;
const int inf = -100000000;
int t[21];
int p[21];
int n;
int ans = 0;
void go(int day, int sum)
{
    if (day == n + 1)
    {
        if (ans < sum)
            ans = sum;
        return;
    }
    if (day > n + 1)
    {
        return;
    }
    go(day + 1, sum);
    go(day + t[day], sum + p[day]);
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i] >> p[i];
    }
    go(1, 0);
    cout << ans << '\n';
    return 0;
}
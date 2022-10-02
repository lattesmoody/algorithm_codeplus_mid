/*
부분수열: 수열에서 일부를 선택해서 만든 수열.
각각의 수가 부분 수열에 포함되는지 안되는지 판단해야한다.

만드는 방법: 재귀호출, 비트마스크

*/

#include <iostream>
using namespace std;
bool c[20 * 100000 + 10];
int a[20];
int n;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < (1 << n); i++)
    {
        int sum = 0;
        // line 25 모르겠음.
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                sum += a[j];
            }
        }
        c[sum] = true;
    }
    for (int i = 1;; i++)
    {   // 만들 수 없는 수가 나오 경우 출력 후 프로그램 중단.
        if (c[i] == false)
        {
            cout << i << '\n';
            break;
        }
    }
    return 0;
}
/*

[key Point]
1. 두 동전 중 하나만 보드에 떨어뜨리기 위해
버튼을 몇 번 눌러야 하는가? (최소값)

[조건]
10번보다 많이 눌러야 하면 -1을 출력

[경우]
4개의 버튼 => 최대 10번

4^10 = 2^20 => 1048576

[고민]
1. 칸: 비어있음, 벽, 동전(동전은 위치가 변경됨)
=> 동전의 위치만 이용. (중요)

go(step, x1, y1, x2, y2)

- step: 버튼을 누른 횟수
- (x1, y1): 한 동전의 위치 (행, 열)
- (x2, y2): 다른 동전의 위치 (행, 열)

[불가능한 경우]
1. step이 11인 경우
2. 하나만 보드에 떨어뜨리기 위해
=> 두 동전 모두 떨어진 경우.

[정답을 찾은 경우]
1. 두 동전 중에서 하나만 떨어진 경우.

[다음 경우를 호출]
1. 버튼을 위, 아래, 왼쪽, 오른쪽을 눌렀을 때

*/

#include <iostream>
using namespace std;
int n, m;
string a[20];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int go(int step, int x1, int y1, int x2, int y2)
{
    // [불가능한 경우]
    if (step == 11)
        return -1;

    bool fall1 = false, fall2 = false;

    // [동전 1이 떨어진 경우]
    if (x1 < 0 || x1 >= n || y1 < 0 || y1 >= m)
        fall1 = true;

    // [동전 2가 떨어진 경우]    
    if (x2 < 0 || x2 >= n || y2 < 0 || y2 >= m)
        fall2 = true;

    // [불가능한 경우]
    if (fall1 && fall2)
        return -1;

    // [정답을 찾은 경우]
    if (fall1 || fall2)
        return step;
    int ans = -1;

    // [다음 경우를 호출]
    for (int k = 0; k < 4; k++)
    {
        int nx1 = x1 + dx[k];
        int ny1 = y1 + dy[k];
        int nx2 = x2 + dx[k];
        int ny2 = y2 + dy[k];

        // 이동하려는 칸이 존재, 벽이면 이동 안함, 현재 칸으로 똑같이
        if (0 <= nx1 && nx1 < n && 0 <= ny1 && ny1 < m && a[nx1][ny1] == '#')
        {
            nx1 = x1;
            ny1 = y1;
        }
        if (0 <= nx2 && nx2 < n && 0 <= ny2 && ny2 < m && a[nx2][ny2] == '#')
        {
            nx2 = x2;
            ny2 = y2;
        }

        // 동전 이동.
        int temp = go(step + 1, nx1, ny1, nx2, ny2);
        
        // 불가능한 경우
        if (temp == -1)
            continue;

        // 가능한 경우 값 return
        if (ans == -1 || ans > temp)
        {
            ans = temp;
        }
    }
    return ans;
}
int main()
{
    cin >> n >> m;
    int x1, y1, x2, y2;
    x1 = y1 = x2 = y2 = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 'o')
            {
                if (x1 == -1)
                {
                    x1 = i;
                    y1 = j;
                }
                else
                {
                    x2 = i;
                    y2 = j;
                }
                a[i][j] = '.';
            }
        }
    }
    cout << go(0, x1, y1, x2, y2) << '\n';
    return 0;
}
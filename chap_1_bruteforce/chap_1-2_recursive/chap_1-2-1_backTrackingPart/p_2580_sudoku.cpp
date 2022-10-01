/*

이 스도쿠 문제의 경우 백트레킹으로 풀 수 있는 입력 데이터만 주어졌음.
모든 방법을 만든다 => BruteForce.
방법 중 의미없는 호출은 버림 => BackTracking.

go(z): z번째 칸 채우는 함수

(x,y) -> 9*x + y번째 칸

c[i][j] = i행에 숫자 j가 있으면 true
c2[i][j] = i열에 숫자 j가 있으면 true
c3[i][j] = i번 작은 정사각형에 숫자 j가 있으면 true
* (x,y)는 (x/3)*3+(y/3)번째 칸


*/

#include <iostream>
using namespace std;
int a[10][10];
bool c[10][10];
bool c2[10][10];
bool c3[10][10];
int n=9;
int square(int x, int y) {
    return (x/3)*3+(y/3);
}
bool go(int z) {
    if (z == 81) { // 81번까지 호출되었을 경우 정답 출력.
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                cout << a[i][j] << ' ';
            }
            cout << '\n';
        }
        return true;
    }
    int x = z/n;
    int y = z%n;
    if (a[x][y] != 0) { // 수가 존재할 경우
        return go(z+1); // 다음 수로 넘어간다.
    } else {
        for (int i=1; i<=9; i++) { // x행 y열
            if (c[x][i] == 0 && c2[y][i] == 0 && c3[square(x,y)][i]==0) {
                c[x][i] = c2[y][i] = c3[square(x,y)][i] = true;
                a[x][y] = i;
                if (go(z+1)) {
                    return true;
                }
                a[x][y] = 0;
                c[x][i] = c2[y][i] = c3[square(x,y)][i] = false;
            }
        }
    }
    return false;
}
int main() {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> a[i][j];
            if (a[i][j] != 0) { // 빈 칸이 아닐 경우 true로 세팅.
                c[i][a[i][j]] = true;
                c2[j][a[i][j]] = true;
                c3[square(i,j)][a[i][j]] = true;
            }
        }
    }
    go(0);
    return 0;
}
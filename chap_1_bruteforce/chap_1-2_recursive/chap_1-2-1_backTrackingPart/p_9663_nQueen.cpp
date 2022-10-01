/*

[N-Queen]
각각의 행에 퀸 하나, 각각의 열에도 퀸 하나.
N!

calc(row): row 행에 퀸을 어디에 놓을지 결정.

check_col[i] = i번 열에 퀸이 놓여져 있으면 true
check_dig[i] = / 대각선에 퀸이 있으면 [row + col]
check_dig2[i] = \ 대각선에 퀸이 있으면 ?? [row - col + n)]

*/

#include <iostream>
using namespace std;
bool a[15][15];
int n;
bool check_col[15];
bool check_dig[40];
bool check_dig2[40];
bool check(int row, int col) {
    // | (열에 대해)
    if (check_col[col]) {
        return false;
    }
    // \ 왼쪽 위 대각선
    if (check_dig[row+col]) {
        return false;
    }
    // /
    if (check_dig2[row-col+n]) {
        return false;
    }
    return true;
}
int calc(int row) {
    if (row == n) {
        // ans += 1;
        return 1;
    }
    int cnt = 0;
    for (int col=0; col<n; col++) {
        if (check(row, col)) {
            // 퀸 두기 전 값 세팅
            check_dig[row+col] = true;
            check_dig2[row-col+n] = true;
            check_col[col] = true;

            // 퀸을 놓음.
            a[row][col] = true;

            // 다음 퀸을 놓기 위한 카운터 업
            cnt += calc(row+1);

            // 세팅값 초기화.
            check_dig[row+col] = false;
            check_dig2[row-col+n] = false;
            check_col[col] = false;
            a[row][col] = false;
        }
    }
    return cnt;
}
int main() {
    cin >> n;
    cout << calc(0) << '\n';
    return 0;
}
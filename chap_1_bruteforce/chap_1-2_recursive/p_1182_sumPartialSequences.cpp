/*

크기가 양수인 부분 수열 => 2^N - 1

go(index, sum)

- index: 부분수열에 포함할지 말지 결정해야 하는 인덱스
- sum: 현재까지 부분수열의 합

- 정답을 찾은 경우
: index == n && sum == s

- 불가능
: index == n && sum != s

- 다음의 경우
1. index 번째를 부분수열에 추가: go(index+1, sum+a[i])
2. index 번째를 부분수열에 추가하지 않음. go(index+1, sum)

시간복잡도: O(2^N)

*/

#include <iostream>
using namespace std;
int a[20];
int n, m;
int ans = 0;
void go(int i, int sum){
    if (i == n){
        if (sum == m){
            ans += 1;
        }
        return;
    }
    go(i+1, sum+a[i]);
    go(i+1, sum);
}
int main(){
    cin >> n >> m;
    for (int i = 0; i< n; i++){
        cin >> a[i];
    }
    go(0,0);
    if (m==0) ans -= 1;
    cout << ans << '\n';
    return 0;
}
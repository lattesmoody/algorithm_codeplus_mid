/*

1 2 3 4 5
4를 지우고 
5는 4로 변환.

1 2 3 4

[Key Point]
1. 에너지를 모으는 방법은 몇 가지?
예) 5개
=> 3개를 고른다 (2,3,4) = (조건)첫 번째, 마지막 못 고름.

4개
=> 2개

3개
=> 1개

N -> N-2
N-1 -> N-3
...
3 -> 1

전체 경우의 수 : (N-2)!

*/

#include <iostream>
#include <vector>
using namespace std;
int go(vector<int> &a) {
    int n = a.size();
    // 에너지 2개면 합칠 수 없음.
    if (n == 2) return 0;
    
    int ans = 0;

    for (int i=1; i<n-1; i++) {
        int energy = a[i-1]*a[i+1];
        vector<int> b(a);
        b.erase(b.begin()+i);
        energy += go(b);
        if (ans < energy) {
            ans = energy;
        }
    }
    return ans;
}
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    cout << go(a) << '\n';
    return 0;
}
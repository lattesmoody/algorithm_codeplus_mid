// https://www.acmicpc.net/problem/1339
/*
=> 이 문제는 그리디로 풀 수 있음. 
[key point]

1. 0부터 9까지의 수.
2. 서로 다른 알파벳의 개수는 10개.

=> 각각의 알파벳이 어떤 수를 의미하는지.
=> 10!

=> 서로 다른 알파벳이 M개라면, 큰 숫자 M개만 넣어서.

*/

// 순열 구하는 함수 관련 설명.
// https://twpower.github.io/82-next_permutation-and-prev_permutation


#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
using namespace std;
char alpha[256];
int calc(vector<string> &a, vector<char> &letters, vector<int> &d)
{
    int m = letters.size();
    int sum = 0;
    for (int i = 0; i<m; i++){
        alpha[letters[i]] = d[i];
    }
    for (string s : a){
        int now = 0;
        for (char x : s){
            now = now * 10 + alpha[x];
        }
        sum += now;
    }
    return sum;
}

int main(){
    int n;
    cin >> n;
    vector<string> a(n);
    vector<char> letters;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        for (char x : a[i]){
            letters.push_back(x);
        }
    }
    sort(letters.begin(), letters.end());
    letters.erase(unique(letters.begin(), letters.end()),letters.end());
    // 어려움.
    // (https://sangwoo0727.github.io/c++/Cplus-unique/)
    // erase 함수는 vector 배열에서 특정 원소를 삭제하는 함수이다.
    // unique 함수는 vector 배열에서 중복되지 않는 원소들을 앞에서부터 채워나가는 함수
    int m = letters.size();
    vector<int> d;
    for (int i = 9; i>9-m; i--){
        d.push_back(i);
    }
    sort(d.begin(),d.end());
    int ans = 0;
    do {
        int now = calc(a, letters, d);
        if (ans < now){
            ans = now;
        }
    }while (next_permutation(d.begin(), d.end()));
    cout << ans << '\n';
    return 0;
}
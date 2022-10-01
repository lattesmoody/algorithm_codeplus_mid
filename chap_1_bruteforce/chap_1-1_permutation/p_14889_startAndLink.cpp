/*
https://www.acmicpc.net/problem/14889

[순서와 관련된 문제.]

N/2가 없으면 순열 문제

20! / 10! * 10! = 184756

문제 자체 이해하지 못함

*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<vector<int>> a(n,vector<int>(n));
    for (int i = 0; i < n; i++){
        for (int j = 0; j<n; j++){
            cin >> a[i][j];
        }
    }
    vector<int> b(n);
    for (int i = 0; i < n /2; i++){
        b[i]=1;
    }
    sort(b.begin(), b.end());
    int ans = 2147483647;
    do{
        vector<int> first, second;
        for (int i = 0; i <n; i++){
            if (b[i] == 0){
                first.push_back(i);
            }else{
                second.push_back(i);
            }
        }
        int one = 0;
        int two = 0;
        for (int i = 0; i<n/2; i++){
            for (int j = 0; j<n/2; j++){
                if (i == j) continue;
                one += a[first[i]][first[j]];
                two += a[second[i]][second[j]];
            }
        }
        int diff = one - two;
        if (diff<0) diff = -diff;
        if(ans > diff) ans = diff;
    }while (next_permutation(b.begin(), b.end()));
    cout << ans << '\n';
    return 0;
}
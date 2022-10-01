/*

수열 S가 주어졌을 때, 수열 S의 부분 수열의 합으로 
나올 수 없는 가장 작은 자연수를 구하는 문제

*/

#include <iostream>
using namespace std;
bool c[200*100000+10];
int a[20];
int n;
void go(int i, int sum){
    if (i ==n){
        c[sum] = true;
        return;
    }
    go(i+1, sum +a[i]);
    go(i+1, sum);
}

int main(){
    cin >> n;
    for (int i = 0; i<n; i++){
        cin >> a[i];
    }
    go(0,0);
    for (int i = 1 ;; i++){
        if (c[i] == false){
            cout << i << '\n';
            break;
        }
    }
    return 0;
}
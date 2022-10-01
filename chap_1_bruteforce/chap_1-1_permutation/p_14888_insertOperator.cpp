/*
https://www.acmicpc.net/problem/14888

[key point]
- 연산자의 순서 고려

경우의 수 : (N-1)! => 10! => 3628800

연산자는 5개 
같은 숫자가 있을 수 있는 순열이어서
+가 2개 있으므로 5!/2! = 60가지


vector<int> b; // 각각의 연산자를 갯수만큼 넣는다.
+ , -, *, / 는 0, 1, 2, 3으로.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int calc(vector<int> &a, vector<int> &b){
    int n = a.size();
    int ans = a[0];
    for (int i = 1; i<n; i++){
        if (b[i-1] == 0){
            ans = ans + a[i];
        }else if (b[i-1] == 1){
            ans = ans - a[i];
        }else if (b[i-1] == 2){
            ans = ans * a[i];
        }else{
            ans = ans/ a[i];
        }
    }
    return ans;
}
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i <n; i++){
        cin >> a[i];
    }
    vector<int> b;
    for (int i = 0; i< 4; i++){
        int cnt;
        cin >> cnt;
        for (int k = 0; k <cnt; k++){
            b.push_back(i);
        }
    }
    sort(b.begin(),b.end());
    vector<int> result;
    do{
        int temp = calc(a,b);
        result.push_back(temp);
    }while(next_permutation(b.begin(), b.end()));
    auto ans = minmax_element(result.begin(), result.end());
    cout << *ans.second << '\n';
    cout << *ans.first << '\n';
    return 0;
}
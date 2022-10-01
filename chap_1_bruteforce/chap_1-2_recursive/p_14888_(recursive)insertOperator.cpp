/*

go(a,index,cur,plus,minus,mul,div)

a: 입력으로 주어진 수열
index: 현재 계산해야 하는 인덱스
cur: index - 1번째까지 계산한 결과
plus, minus, mul, div: 사용할 수 있는 연산자의 개수

+ 사용:go(a,index+1,cur+a[index],plus-1,minus,mul,div)
- 사용:go(a,index+1,cur-a[index],plus,minus-1,mul,div)
× 사용:go(a,index+1,cur*a[index],plus,minus,mul-1,div)
/ 사용:go(a,index+1,cur/a[index],plus,minus,mul,div-1)

*/

// line 43 주의. (실제 코드 line 63)

// pair 구조체는 두 인수의 쌍을 값으로 가지는 구조체

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
pair<int,int> calc(vector<int> &a, int index, int cur, int plus, int minus, int mul, int div){
    int n = a.size();
    if (index == n){
        return make_pair(cur, cur);
    }
    vector<pair<int,int>> res;
    if(plus>0){
        res.push_back(calc(a, index+1, cur+a[index] , plus - 1, minus, mul, div));
    }
    if(minus>0){
        res.push_back(calc(a, index+1, cur-a[index] , plus, minus-1, mul, div));
    }
    if(mul>0){
        res.push_back(calc(a, index+1, cur*a[index] , plus, minus, mul-1, div));
    }
    if(div>0){
        res.push_back(calc(a, index+1, cur/a[index] , plus, minus, mul, div-1));
    }
    auto ans = res[0];
    for (auto p : res){
        if (ans.first < p.first){
            ans.first = p.first;
        }
        if (ans.second > p.second){
            ans.second = p.second;
        }
    }
    return ans;
}
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++){
        cin>>a[i];
    }
    int plus, minus, mul, div;
    cin >> plus >> minus >> mul >> div;
    auto p = calc(a, 1, a[0], plus, minus, mul, div);
    cout << p.first << '\n';
    cout << p.second << '\n';
    return 0;
}
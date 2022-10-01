/*

로또의 모든 조합을 출력해보는 문제.

* 22.10.01_소스코드 이해 불가.

go(a,index,cnt)
a: 입력으로 주어진 수
index: 선택할지 말지 결정해야 하는 인덱스
cnt: 현재까지 포함(고른)한 수의 개수

[종료 조건]
1. 정답을 찾음 (cnt == 6)
2. 불가능한 경우 (index == a.size()) 

[다음의 경우를 호출할 때]
1. 선택하였을 때 : go(a, index + 1, cnt + 1)
2. 선택하지 않았을 때 : go(a, index+1, cnt)

line 4: 함수가 고른 수 저장
line 14: 종료 조건 2번 조건을 만족하면 종료.
line 15 ~ 16 : index 번째를 선택.
line 17 ~ 18 : index 번째를 선택하지 않음.

6개 고르는 것을 사전 순으로.
코드에는 그런게 없음.
왜? 문제의 조건에는 k개의 순서는 오름차순으로 주어진다.
함수의 구현에는 index번째를 먼저 선택하는 것이 있음.
=> 작은 수를 선택하는 걸 먼저 처리했기 때문에 사전 순으로 된다.
=> 사전 순을 따로 처리하지 않아도 된다.
(line 15 ~ 18)
*/

#include <iostream>
#include <vector>
using namespace std;
vector<int> lotto;
void solve(vector<int> &a, int index, int cnt){
    if (cnt == 6){
        for (int num : lotto){
            printf("%d ", num);
        }
        printf("\n");
        return;
    }
    int n = a.size();
    if (n == index) return;
    lotto.push_back(a[index]);
    solve(a, index+1, cnt + 1);
    lotto.pop_back();
    solve(a,index+1, cnt);
}

int main(){
    while (true){
        int n;
        cin >> n;
        if (n == 0) break;
        vector<int> a(n);
        for (int i = 0; i < n ;i++){
            cin >> a[i];
        }
        solve(a,0,0);
        cout<<'\n';
    }
    return 0;
}



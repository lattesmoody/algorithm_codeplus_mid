/*

[부등호]
(입력)
첫 줄에 부등호 문자의 개수를 나타내는 정수 k가 주어진다
그 다음 줄에는 k개의 부등호 기호가 하나의 공백을 두고 한 줄에 모두 제시된다. 
k의 범위는 2 ≤ k ≤ 9 이다. 


<중요한 조건>
1. 한 자리 숫자
2. 선택된 수는 모두 달라야 함.

[풀이]
1. 10개의 수 중에서 k+1 개를 고른다.
2. (k+1)! 순서를 모두 만들고 부등호를 검사한다.

2^(k+1) * (k+1)! * (k+1)

2^10 * 10! * 10 = ... 

=> 시간이 너무 오래 걸린다.
=> 바꿔 보자.

=> 대소 관계를 잘 보자 
(가장 큰 수 => 9 8 7 6)
(가장 작은 수 => 0 1 2 3)

=> "10개의 수 중에서" 라는 조건은 필요없어짐.

=> (k+1)! * (k+1)


*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool check(vector<int> &perm, vector<char> &a){
    for (int i = 0; i<a.size(); i++){
        if (a[i] == '<' && perm[i] > perm[i+1]){
            return false;
        }
        if (a[i] == '>' && perm[i] < perm[i+1]){
            return false;
        }
    }
    return true;
}

int main(){
    int k;
    cin >> k;
    vector<char> a(k);
    for (int i = 0; i<k; i++){
        cin >> a[i];
    }
    // vector 관련 https://modoocode.com/223
    vector<int> small(k+1);
    vector<int> big(k+1);
    for (int i = 0; i<=k; i++){
        small[i] = i;
        big[i] = 9-i;
    }
    // 가장 작은 수 찾기 시작.
    do {
        if (check(small, a)){
            break;
        }
    }while(next_permutation(small.begin(),small.end()));
    // 가장 작은 수 찾기 끝.
    do{
        if(check(big,a)){
            break;
        }
    }while(prev_permutation(big.begin(), big.end()));
    for(int i = 0; i < big.size(); i++){
        cout<<big[i];
    }
    cout << '\n';
    for (int i = 0; i< small.size(); i++){
        cout << small[i];
    }
}

// 트리만 보면 중위순회지만 결과값을 통해서 코드를 작성할 때는 전위순회로 작성
// mid를 중심으로 left right 탐색
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int K, a[1028];
vector<int> ret[11];

void preOrder(int left, int right, int level)
{
    cout << left << " :  : " << right << '\n';
    if (left > right)
        return ;
    if (left == right){
        ret[level].push_back(a[left]); // 리프노드 일 경우
        return ;
    }
    int mid = (left + right) / 2; // 중간값 설정
    ret[level].push_back(a[mid]);
    preOrder(left, mid - 1, level + 1);
    preOrder(mid + 1, right, level + 1);
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> K;
    int _end = (int)pow(2, K) - 1;
    for (int i = 0; i < _end; i++){
        cin >> a[i];
    }
    preOrder(0, _end, 1);
    for (int i = 1; i <= K; i++){
        for (int j : ret[i]){
            cout << j << " ";
        }
        cout << '\n';
    }
    return 0;
}

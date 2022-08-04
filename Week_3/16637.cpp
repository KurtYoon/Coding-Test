#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int N, ret = -987654321; // 최댓값을 구하기 위해서 최솟값으로 설정
string s;
vector<int> num; // 정수가 담길 벡터
vector<char> op; // 연산자가 담길 벡터

int oper(char a, int b, int c)
{
    if (a == '+')return b+c; // 각 연산자 마다의 연산 수행
    if (a == '-')return b-c;
    if (a == '*')return b*c;
    return -1;
}

void go(int here, int number)
{
    if (here == num.size() - 1){ // 끝까지 도달했다면 최종적인 최댓값을 담음
        ret = max(ret, number);
        return ;
    }

    go(here + 1, oper(op[here], number, num[here + 1]));
    if (here + 2 <= num.size() - 1){
        int tmp = oper(op[here + 1], num[here + 1], num[here + 2]); // 뒷쪽 인덱스의 연선을 선행
        go(here + 2, oper(op[here], number, tmp));
    }
    return ;
}

// 만약에 3+8*5라는 수식이 있다고 했을 떄 연산의 경우의 수는
// (3+8)*5 or 3+(8*5) 두가지 이다.
// 그래서 재귀함수를 사용하여 인덱스가 충분할 경우에는 뒷쪽의 연선을 선행한 후 재귀함수를 사용하는 코드 추가

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    cin >> s;
    for (int i = 0; i < N; i++){
        if (i % 2){
            op.push_back(s[i]);
        }
        else{
            num.push_back(s[i] - '0');
        }
    }
    go(0, num[0]);
    cout << ret << '\n';
    return 0;
}
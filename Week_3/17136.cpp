#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

const int INF = 987654321;
int a[104][104], ret = INF, n = 10;
map<int, int> mp;

bool check(int y, int x, int cnt){ // 색종이를 붙일 수 있으면 true 아니면 false
    if (y + cnt > n || x + cnt > n) return false;
    for (int i = y; i < y + cnt; i++){
        for (int j = x; j < x + cnt; j++){
            if (a[i][j] == 0) return false;
        }
    }
    return true;
}

void draw(int y, int x, int cnt, int value){ // 0 혹은 1로 값 뼌동
    for (int i = y; i < y + cnt; i++){
        for (int j = x; j < x + cnt; j++){
            a[i][j] = value;
        }
    }
}

void dfs(int y, int x, int cnt){
    if (cnt >= ret) return;
    if (x == n){
        dfs(y + 1, 0, cnt);  // 가로줄을 먼저 모두 탐색하고
        return;              // 만약 가로줄이 끝까지 갔다면 세로줄 탐색
    }
    if (y == n){
        ret = min(cnt, ret); // 탐색이 끝났으므로 색종이의 갯수의 최솟값을 구함
        return;
    }
    if (a[y][x] == 0){ // 생각할 필요가 없는 지저
        dfs(y, x + 1, cnt); return; // 그 다음칸을 탐색
    }
    for (int _size = 5; _size >= 1; _size--){ // 색종이를 5x5부터 붙이기 위해서
        if(mp[_size] == 5) continue; // 총 색종이의 갯수는 5개인데 5개를 넘어버리면 continue
        if (check(y, x, _size)){
            mp[_size]++;
            draw(y, x, _size, 0); // 색칠이 가능하다면 해당 칸만큼 0으로 바꾸고 dfs 탐색 후 다시 1로 바꿈
            dfs(y, x + _size, cnt + 1);
            draw(y, x, _size, 1);
            mp[_size]--;
        }
    }
    return ;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    dfs(0, 0, 0);
    cout << (ret == INF ? -1 : ret) << '\n'; // 최대부터 최소를 찾기
    return 0;
}
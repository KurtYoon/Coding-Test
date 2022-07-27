#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <cstring>
#define rep(i, x, n) for (int i = x; i < n; i++)
using namespace std;

const int INF = 987654321;
const int dy[4] = {0, -1, 0, 1};
const int dx[4] = {1, 0, -1, 0};
int R, C, fire[1004][1004], person[1004][1004];
char a[1004][1004];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> R >> C;
    rep(i, 0, R){
        rep(j, 0, C){
            cin >> a[i][j];
        }
    }
}
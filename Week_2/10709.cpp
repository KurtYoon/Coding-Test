#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int H, W, a[104][104];
string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> H >> W;
    for (int i = 0; i < H; i++){
        cin >> s;
        for (int j = 0; j < W; j++){
            if (s[j] == '.')
                a[i][j] = -1;
            else
                a[i][j] = 0;
        }
    }
    for (int i = 0; i < H; i++){
        for (int j = 0; j < W; j++){
            if (a[i][j] == 0){
                int cnt = 1;
                while (a[i][j + 1] == -1){
                    a[i][j + 1] = cnt++;
                    j++;
                }
            }
        }
    }
    for (int i = 0; i < H; i++){
        for (int j = 0; j < W; j++){
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
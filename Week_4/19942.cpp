#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <cstring>
#include <map>
using namespace std;

const int INF = 987654321;
int N, mp, mf, ms, mv, sum, ret = INF, b, c, d, e;
struct A
{
    int mp, mf, ms, mv, cost;
}a[16];
map<int, vector<vector<int> > > ret_v; // map의 int 번째에 있는 vector에 vector을 집어넣기

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    cin >> mp >> mf >> ms >> mv;
    for (int i = 0; i < N; i++){
        cin >> a[i].mp >> a[i].mf >> a[i].ms >> a[i].mv >> a[i].cost;
    }
    for (int i = 1; i < (1 << N); i++){ // 모든 경우의 수에 대해서 탐색
        b = c = d = e = sum = 0;
        vector<int> v;
        for (int j = 0; j < N; j++){
            if (i & (1 << j)){
                v.push_back(j + 1);
                b += a[j].mp;
                c += a[j].mf;
                d += a[j].ms;
                e += a[j].mv;
                sum += a[j].cost;
            }
        }
        if (b >= mp && c >= mf && d >= ms && e >= mv){
            if (ret >= sum){
                ret = sum;
                ret_v[ret].push_back(v); // cost조건을 만족하면 ret_v벡터의 ret 인덱스에 해당 벡터 저장
            }
        }
    }
    if (ret == INF){
        cout << -1 << '\n';
    }
    else{
        sort(ret_v[ret].begin(), ret_v[ret].end());
        cout << ret << '\n';
        for (int a : ret_v[ret][0]){
            cout << a << ' ';
        }
    }
    return 0;
}
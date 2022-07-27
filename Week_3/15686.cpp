// 치킨집 리스트들 중에서 M개의 치킨집을 골라야 한다.
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 987654321;
const int dy[4] = {0, -1, 0, 1};
const int dx[4] = {1, 0, -1, 0};
int N, M, a[54][54], dis = INF;

vector<pair<int, int> > house, chicken;
vector<vector<int> > chickenList;

void combi(int start, vector<int> v) // 일반적인 조합 함수
{
    if (v.size() == M)
    {
        chickenList.push_back(v);
        return ;
    }
    for (int i = start + 1; i < chicken.size(); i++)
    {
        v.push_back(i);
        combi(i, v);
        v.pop_back();
    }
    return ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> a[i][j];
            if (a[i][j] == 1) house.push_back(make_pair(i, j));  // 집과 치킨집의 좌표를 각각의 벡터에 저장함
            if (a[i][j] == 2) chicken.push_back(make_pair(i, j));
        }
    }
    vector<int> v;
    combi(-1, v); // 치킨집을 고를 수 있는 모든 조합을 chickenList 벡터에 담을 수 있도록 combi함수 진입
    for (vector<int> cList : chickenList) // 벡터로 저장된 조합들을 하나씩 꺼내서 탐색함
    {
        int ret = 0;
        for (pair<int, int> home : house){ // 집의 좌표를 하나씩 꺼내어 탐색함
            int _min = 987654321;
            for (int ch : cList){ // 해당 조합에 저장되어 있는 치킨집의 좌표를 탐색함
                int dst = abs(home.first - chicken[ch].first) + abs(home.second - chicken[ch].second);
                // 문제에서 요구하는 치킨거리 공식
                _min = min(_min, dst); // 치킨거리가 가장짧은 조합에서의 거리를 저장함
            }
            ret += _min; // 최솟값을 더함
        }
        dis = min(dis, ret); // 최솟값들의 합
    }
    cout << dis << "\n";
    return 0;
}
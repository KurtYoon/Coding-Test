#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> adj[54];
int a[14], v[104], m[4], n = 10;

int move(int here, int cnt)
{
    if (here == 100) // 목표지점이라면 큰 수 반환
        return 100;
    if (adj[here].size() >= 2){ // 파란색 칸이라서 이동방향이 2개 이상일 떄
        here = adj[here][1]; // [0]은 빨간 화살표, [1]은 파란 화살표 이므로 adj[here][1]을 선택
        cnt--;
    }
    if (cnt) // cnt가 존재한다면 BFS사용
    {
        queue<int> q;
        q.push(here);
        int there;
        while (q.size())
        {
            int x = q.front(); q.pop();
            there = adj[x][0];
            q.push(there);
            if (there == 100)
                break;
            cnt--;
            if (cnt == 0)
                break;
        }
        return there;
    }
    else
        return here;
}

bool isM(int m_idx, int idx) // 말이 있으면 true, 말이 없거나 말의 위치가 목표지점이라면 false
{
    if (m_idx == 100)
        return false;
    for (int i = 0; i < 4; i++){
        if (i == idx)
            continue;
        if (m[i] == m_idx)
            return true;
    }
    return false;
}

void add(int here, int there)
{
    adj[here].push_back(there);
}

void mapSet()
{
    for (int i = 0; i <= 19; i++)
        add(i, i + 1);

    add(5, 21); add(21, 22); add(22, 23); add(23, 24);
    add(10, 25); add(25, 26); add(26, 24);
    add(15, 27); add(27, 28); add(28, 29); add(29, 24);
    add(24, 30); add(30, 31); add(31, 20); add(20, 100);

    v[1] = 2; v[2] = 4; v[3] = 6; v[4] = 8; v[5] = 10;
    v[6] = 12; v[7] = 14; v[8] = 16; v[9] = 18; v[10] = 20;
    v[11] = 22; v[12] = 24; v[13] = 26; v[14] = 28; v[15] = 30;
    v[16] = 32; v[17] = 34; v[18] = 36; v[19] = 38; v[20] = 40;

    v[21] = 13; v[22] = 16; v[23] = 19; v[24] = 25;
    v[25] = 22; v[26] = 24;
    v[27] = 28; v[28] = 27; v[29] = 26;
    v[30] = 30; v[31] = 35;
}

int go(int here)
{
    if (here == n)
        return 0;
    int ret = 0;
    for (int i = 0; i < 4; i++){ // 각각의 말의 위치와 주사위 값을 이용해 최댓값을 찾아서 저장함
        int tmp_idx = m[i];
        int m_idx = move(tmp_idx, a[here]); // tmp_idx로 부터 움직임
        if (isM(m_idx, i))
            continue;
        m[i] = m_idx;
        ret = max(ret, go(here + 1) + v[m_idx]);
        m[i] = tmp_idx;
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); mapSet();

    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << go(0) << '\n';
    return 0;
}
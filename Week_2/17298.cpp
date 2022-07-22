#include <iostream>
#include <stack>
#include <algorithm>
#include <cstring>
using namespace std;

int N, a[1000004], m[1000004];
stack<int> s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    memset(m, -1, sizeof(m));
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
        while (s.size() && a[s.top()] < a[i]){
            m[s.top()] = a[i];
            s.pop();
        }
        s.push(i);
    }
    for (int i = 0; i < N; i++)
    {
        cout << m[i] << " ";
    }
}
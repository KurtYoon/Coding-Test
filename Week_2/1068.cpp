#include <iostream>
#include <vector>
using namespace std;

int N, a[51], R, root;
bool visited[51];
vector<int> C[51];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> a[i];
        if (a[i] == -1)
            root = i;
        else
            C[a[i]].push_back(i);
    }
    cin >> R;
}
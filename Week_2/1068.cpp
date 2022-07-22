#include <iostream>
#include <vector>
using namespace std;

int N, R, root, tmp;
vector<int> v[54];

int dfs(int here)
{
    int ret = 0;
    int child = 0;
    for (int there : v[here]){
        if (there == R)
            continue;
        ret += dfs(there);
        child++;
    }
    if (child == 0)
        return 1;
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> tmp;
        if (tmp == -1){
            root = i;
        }
        else{
            v[tmp].push_back(i);
        }
    }
    cin >> R;
    if (R == root){
        cout << 0 << '\n';
        return 0;
    }
    cout << dfs(root) << "\n";
    return 0;
}
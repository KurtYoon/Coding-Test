#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, cnt = 0;
    cin >> N;
    string s;
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> s;
        stack<char> stk;
        for (char a : s)
        {
            if (stk.size() && stk.top() == a)
                stk.pop();
            else
                stk.push(a);
        }
        if (stk.size() == 0)
            count++;
    }
    cout << count << '\n';
    return 0;
}

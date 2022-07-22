#include <iostream>
#include <stack>
#include <algorithm>
#include <cstring>
using namespace std;

int N;
string S;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> S;
        stack<char> a;
        int L = 0, R = 0;
        for (int j = 0; j < S.size(); j++)
        {
            if (S[j] == '(')
            {
                a.push(S[j]); 
                L++;
            }
            else if (S[j] == ')')
            {
                if (!a.empty())
                    a.pop();
                R++;
            }
        }
        if (!a.empty() || L != R)
            cout << "NO" << '\n';
        else
            cout << "YES" << '\n';
    }
    return 0;
}
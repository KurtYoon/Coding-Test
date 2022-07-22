#include <iostream>
#include <stack>
#include <algorithm>
#include <cstring>
using namespace std;

string S;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    while (1)
    {
        stack<char> stk;
        int anw = 0;
        getline(cin, S);
        if (S.length() == 1 && S[0] == '.')
            break;
        for (int i = 0; i < S.length(); i++)
        {
            if (S[i] == '[' || S[i] == '(')
                stk.push(S[i]);
            else if (S[i] == ')')
            {
                if (stk.empty() || stk.top() == '[')
                    anw = 1;
                else
                    stk.pop();
            }
            else if (S[i] == ']')
            {
                if (stk.empty() || stk.top() == '(')
                    anw = 1;
                else
                    stk.pop();
            }
        }
        if (anw || !stk.empty())
            cout << "no" << '\n';
        else
            cout << "yes" << '\n';
    }
    return 0;
}
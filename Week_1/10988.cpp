#include <iostream>
using namespace std;
string s;

int main()
{
    cin >> s;
    string tmp = s;
    reverse(tmp.begin(), tmp.end());
    if (s == tmp)
        cout << 1 << '\n';
    else
        cout << 0 << '\n';
    return 0;
}
#include <iostream>
using namespace std;
string s;
int alpha[26];
int main(void)
{
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        alpha[s[i] - 'a'] += 1;
    }
    for (int i = 0; i < 26; i++)
        cout << alpha[i] << ' ';
    cout << '\n';
    return 0;
}
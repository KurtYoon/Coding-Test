#include <iostream>
using namespace std;
string s;

int main()
{
    getline(cin, s);
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'm')
            s[i] += 13;
        else if (s[i] >= 'A' && s[i] <= 'M')
            s[i] += 13;
        else if (s[i] >= 'n' && s[i] <= 'z')
            s[i] -= 13;
        else if (s[i] >= 'N' && s[i] <= 'Z')
            s[i] -= 13;
    }
    cout << s << '\n';
    return 0;
}
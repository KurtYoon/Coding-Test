#include <iostream>
using namespace std;

int N;
string a, b, c, d;

int main()
{
    cin >> N;
    cin >> a;
    int pos = a.find("*");
    c = a.substr(0, pos);
    d = a.substr(pos + 1);
    for (int i = 0; i < N; i++)
    {
        cin >> b;
        if (c.size() + d.size() > b.size())
            cout << "NE" << '\n';
        else
        {
            if (c == b.substr(0, c.size()) && d == b.substr(b.size() - d.size()))
                cout << "DA" << '\n';
            else
                cout << "NE" << '\n';
        }
    }
    return 0;
}

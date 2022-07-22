#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int N;
char a[65][65];

void search(int y, int x, int size)
{
    for (int i = y; i < y + size; i++)
    {
        for (int j = x; j < x + size; j++)
        {
            if (a[i][j] != a[y][x])
            {
                cout << "(";
                search(y, x, size/2);
                search(y, x + size/2, size/2);
                search(y + size/2, x, size/2);
                search(y + size/2, x + size/2, size/2);
                cout << ")";
                return ;
            }
        }
    }
    cout << a[y][x];
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < N; j++)
        {
            a[i][j] = s[j];
        }
    }
    search(0, 0, N);
    return 0;
}
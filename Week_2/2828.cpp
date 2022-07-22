#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    int j;
    cin >> j;
    int ret = 0;
    int xpos1, xpos2;
    xpos1 = 1;
    xpos2 = xpos1 + M - 1;
    for (int i = 0; i < j; i++)
    {
        int x;
        cin >> x;
        if (x >= xpos1 && x <= xpos2)
            continue ;
        else if (x > xpos2)
        {
            while (x != xpos2)
            {
                xpos2++;
                xpos1++;
                ret++;
            }
        }
        else if (x < xpos1)
        {
            while (x != xpos1)
            {
                xpos2--;
                xpos1--;
                ret++;
            }
        }
    }
    cout << ret << '\n';
    return 0;
}
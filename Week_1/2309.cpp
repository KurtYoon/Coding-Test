#include <iostream>
#include <algorithm>
using namespace std;
int dwaf[10];

int main()
{
    for (int i = 0; i < 9; i++)
        cin >> dwaf[i];
    sort(dwaf, dwaf + 9);
    do
    {
        int sum = 0;
        for (int i = 0; i < 7; i++)
        {
            sum += dwaf[i];
        }
        if (sum == 100)
            break ;
    }while (next_permutation(dwaf, dwaf+9));
    for (int i = 0; i < 7; i++)
        cout << dwaf[i] << '\n';
    return 0;
}


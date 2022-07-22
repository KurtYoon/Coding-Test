#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

int N, W, A, B, asum, bsum;
string T, P;

int to_int(string s)
{
    return atoi(s.substr(0, 2).c_str()) * 60 + atoi(s.substr(3, 2).c_str());
}

void Score(int &sum, string s)
{
    sum += to_int(s) - to_int(P);
}

string Print(int sum)
{
    string s1 = "00" + to_string(sum / 60);
    string s2 = "00" + to_string(sum % 60);
    return (s1.substr(s1.size() - 2, 2) + ":" + s2.substr(s2.size() - 2, 2));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> W >> T;
        if (A > B)
            Score(asum, T);
        else if (B > A)
            Score(bsum, T);
        W == 1 ? A++ : B++;
        P = T;
    }
    if (A > B)
        Score(asum, "48:00");
    else if (B > A)
        Score(bsum, "48:00");
    cout << Print(asum) << '\n';
    cout << Print(bsum) << '\n';
    return 0;
}
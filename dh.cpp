#include <bits/stdc++.h>
using namespace std;
int prem_root(int P)
{
    int e1 = 0;
    for (int i = 2; i < P; i++)
    {
        bool checker = true;
        for (int j = 1; j < P - 1; j++)
        {
            int mod = 1, k = j;
            while (k--)
            {
                mod = (mod * i) % P;
            }
            if (mod == 1)
            {
                checker = false;
                break;
            }
        }
        if (checker)
        {
            e1 = i;
            break;
        }
    }
    return e1;
}
int main()
{
    int q;
    cout << "Enter a large prime number : ";
    cin >> q;
    int a = prem_root(q);
    // Two user A and B
    cout << "Enter private number of A and B : ";
    int private_A, private_B;
    cin >> private_A >> private_B;
    int YA = 1, YB = 1;
    for (int i = 0; i < private_A; i++)
    {
        YA = (YA * a) % q;
    }
    for (int i = 0; i < private_B; i++)
    {
        YB = (YB * a) % q;
    }

    int kA=1,kB=1;
    for (int i = 0; i < private_A; i++)
    {
        kA = (kA * YB) % q;
    }
    for (int i = 0; i < private_B; i++)
    {
        kB = (kB * YA) % q;
    }
    cout<<"Key get by A : "<<kA<<" "<<"Key get by B : "<<kB;
    return 0;
}
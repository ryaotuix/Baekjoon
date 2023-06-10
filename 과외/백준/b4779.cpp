#include<bits/stdc++.h>

using namespace std;
void printEmpty(int len)
{
    for (int i = 0; i < len; i++)
        cout << " ";
}

void printCantorSet(int n)
{
    // base case : n = 0
    if (n == 0)
    {
        cout << "-";
        return;
    }

    // otherwise
    int len = pow(3, n-1);
    printCantorSet(n-1);
    printEmpty(len);
    printCantorSet(n-1);
}


int main()
{
   do
   {
        int n;
        cin >> n;
        printCantorSet(n);
        
   } while (true);
    
}
#include <bits/stdc++.h>

using namespace std;
int N;
int x, y;


int getTimes(int distance)
{

    if (distance <= 3) 
        return distance;
        
    int sqr = sqrt(distance);
    int res;
    pow(sqr, 2) == distance ? res = sqr * 2 - 1 : res = 2 * sqr;
    if (distance > sqr * (sqr + 1)) res++;

    return res;
}


void input()
{
    cin >> N;
    while(N--)
    {
        cin >> x >> y;
        cout << getTimes(y - x) << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();
}
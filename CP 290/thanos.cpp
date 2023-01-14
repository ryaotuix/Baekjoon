#include <iostream>

using namespace std;

int doom(long p, const long r, const long f)
{
    int i = 0;
    // breaks when p > f
    while (p <= f)
    {
        i++;
        p *= r;
    }
    return i;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    
    long P; // curr population
    long R; // grows by a factor of R
    long F; // annual food production F tons

    // each individual consumes 1 ton of food 
    // pop is always whole number rounded DOWN


    for (int i = 0; i < n; i++)
    {
        cin >> P >> R >> F;
        cout << doom(P, R, F) << "\n";
    }
}
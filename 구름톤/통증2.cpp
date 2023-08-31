#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000000 + 5;
int pain[MAX];
int N;  // current pain amount
int A, B;


void input()
{
    cin >> N;
    cin >> A >> B;
    memset(pain, 0x3f, sizeof(pain));

}

// idea pain[x] = min(pain[x], pain[x-B]) + 1
int getItems()
{
    pain[0] = 0;    // base case

    for (int i = 1; i <= N; ++i) {
        if (0 <= i - A) pain[i] = min(pain[i], pain[i - A] + 1);
        if (0 <= i - B) pain[i] = min(pain[i], pain[i - B] + 1);
    }
   
    cout << (pain[N] > 1E9 ? -1 : pain[N]);
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();
    int a =getItems();
}
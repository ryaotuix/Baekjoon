#include <bits/stdc++.h>

using namespace std;

const int MAX= 20 + 1;

int city[MAX][MAX];
bool isFive[MAX][MAX];
int n;  
int x, y, d1, d2;
int population[5 + 1];
int totalpop;
int ans = 20*20*101;


void init()
{
    // Margin init
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            isFive[i][j] = false;
        }
    }

    // population init
    for (int i = 1; i < 6; i++)
    {
        population[i] = 0;
    }
}

void print()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j= 1; j <= n; j++)
        {
            cout << isFive[i][j] << " ";
        }
        cout << "\n";
    }
}

void input()
{
    cin >> n;
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> city[i][j];
            totalpop += city[i][j];
        }
    }
}

bool checkBound()
{
    if (x + d1 + d2 >= n) return false;
    if (y - d1 < 0 || y + d2 >= n) return false;
        
    return true;
}

void markMargin()
{
    // 1.
    for (int i = 0; i <= d1; i++)
    {
        isFive[x+i][y-i] = true;
    }
    // 2.
    for (int i = 0; i <= d2; i++)
    {
        isFive[x+i][y+i] = true;
    }
    // 3.
    for (int i = 0; i <= d2; i++)
    {
        isFive[x+d1+i][y-d1+i] = true;
    }
    // 4.
    for (int i = 0; i <= d1; i++)
    {
        isFive[x+d2+i][y+d2-i] = true;
    }
}


void getPop()
{
    // pop1
    for (int row = 1; row < x+d1; row++)
    {
        for (int col = 1; col <= y; col++)
        {
            if (isFive[row][col]) 
                break;
            
            population[1] += city[row][col];
        }
    }

    // pop2
    for (int row = 1; row <= x+d2; row++)
    {
        for (int col = n ; col > y; col--)
        {
            if (isFive[row][col])
                break;
    
            population[2] += city[row][col];
        }
    }

    // pop3
    for (int row = x+d1; row <= n; row++)
    {
        for (int col = 1; col < y-d1+d2; col++)
        {
            if (isFive[row][col])
                break;
            
            population[3] += city[row][col];
        }
    }

    // pop4
    for (int row = x+d2+1; row <= n; row++)
    {
        for (int col = n; col >= y-d1+d2; col--)
        {
            if (isFive[row][col])
                break;
            
            population[4] += city[row][col];
        }
    }

    population[5] = totalpop - population[1] - population[2] - population[3] - population[4]; 

    int maxPop = population[1];
    int minPop = population[1];
    for (int i = 1; i <= 5; i++)
    {
        maxPop = max(maxPop, population[i]);
        minPop = min(minPop, population[i]);
    }

    ans = min(ans, abs(maxPop - minPop));
}


void solve()
{
    for (d1 = 1; d1 < MAX; d1++)
    {
        for (d2 = 1; d2 < MAX; d2++)
        {
            for (x = 1; x < MAX; x++)
            {
                for (y = 1; y < MAX; y++)
                {
                    // if all of them are in bound,
                    if(checkBound())
                    {
                        init();         // init margin and population
                        markMargin();   // mark margin of section 5
                        getPop();       // get population of each section

                        // print();
                        // for (int i = 1 ; i <= 5; i++)
                        //     cout << population[i] << " ";
                        // cout << "ans : " << ans << "\n";
                        // cout << x << " " << y << " " << d1 << " " << d2 << "\n\n";
                    }
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();

    cout << ans;
}
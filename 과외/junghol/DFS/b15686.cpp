#include <bits/stdc++.h>

using namespace std;

#define HOME 1
#define CHICKEN 2

// materials
int n;                      // grid size
int m;                      // # of chicken survived :(
int city[50 + 5][50 + 5];   // city grid

// # of chickens and homes
int chicken = 1;
int home = 1;

// location <starts at index 1>
int chickenR[13 + 5];     
int chickenC[13 + 5];

int homeR[100 + 5];
int homeC[100 + 5];

bool usedChicken[13 + 5] = {false, };

int homeToChicken(int homeIndex)
{
    int res = 1e9;
    // cout << "looking at home : " << "{" << homeR[homeIndex] << "," << homeC[homeIndex] << "}\n";

    // iterate over all possible chicken
    for (int i = 0; i <= chicken; i++)
    {
        // stop by all chicken we have used
        if (usedChicken[i])
        {
            // cout << "looking at chicken : " << "{" << chickenR[i] << "," << chickenC[i] << "}\n";
            // get distance
            int dist = abs(homeR[homeIndex] - chickenR[i]) + abs(homeC[homeIndex] - chickenC[i]);
            res = min(res, dist);
        }
    }

    // cout << "res : " << res << "\n";

    return res;
}

int result = 1e9 + 9;
void getCityTotal()
{
    int total = 0;
    for (int i = 1; i <= home; i++)
    {
        int hToC = homeToChicken(i);
        // check curr home to Closest Chicken
        // cout << "home : ";
        // cout << i << " = {" << homeR[i] << ", " << homeC[i] << "} ";
        // cout << "Shortest : " << hToC << endl;

        total += hToC;
    }

    result = min(result, total);
}

/* Getting combination of surviving chicken */ // starting Depth 1, Prev 0
void combChicken(int depth, int prev)
{
    // Base Case : when we are done choosing m+1 chickens
    if (depth == m+1)
    {
        //check survived chicken
        // cout << "\nSurvived : ";
        // for (int i = 0; i <= chicken; i++) 
        //     if (usedChicken[i])
        //         cout << i << " = {" << chickenR[i] << ", " << chickenC[i] << "}  ";
        // cout << endl;

        // get도시의 치킨 거리
        getCityTotal();
        return;
    }

    for (int i = 1; i <= chicken; i++)
    {
        // if not used
        if (!usedChicken[i] && i >= prev)
        {
            usedChicken[i] = true;
            combChicken(depth + 1, i);
            usedChicken[i] = false;
        }
    }
    
}

void input()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> city[i][j];
            // if home
            if (city[i][j] == HOME)
            {
                homeR[home] = i;
                homeC[home] = j;
                home++;
            }
            // if chicken
            else if (city[i][j] == CHICKEN)
            {
                chickenR[chicken] = i;
                chickenC[chicken] = j;
                chicken++;
            }
        }
    }

    // Must decrement chicken and home count lastly
    home--;
    chicken--; 
}

void checkInput()
{
    // double check
    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << city[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Chicken : ";
    for (int i = 1; i <= chicken; i++)
    {
        cout << "{" << chickenR[i] << "," << chickenC[i] << "}, ";
    }

    cout << endl;

    cout << "Home : ";
    for (int i = 1; i <= home; i++)
    {
        cout << "{" << homeR[i] << "," << homeC[i] << "}, ";
    }     
}



int main()
{
    input();
    combChicken(1, 1);

    cout << result;
}
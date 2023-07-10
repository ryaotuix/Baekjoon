#include <bits/stdc++.h>


using namespace std;

int adjMatrix[15][15];  // adj matrix
int minCost = 1e9;      // min cost
bool visited[15];       // visited arr
int n;                  // number of cities


void input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int cost; cin >> cost;
            adjMatrix[i][j] = cost;
        }
    }

    // INPUT DONE starting at index 1
}

void printMatrix()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

// cityCNt starts with 0
void traverse(int currCity, int cityCnt, int sum)
{
    // cout << "currCity : " << currCity << " city Cnt : " << cityCnt << endl;

    // Improvement
    if (sum > minCost)
        return;

    // Base Case :
    if (cityCnt == n)
    {
        // check if we can go to city 1 from curr city
        if (adjMatrix[currCity][1] != 0)
        {
            sum += adjMatrix[currCity][1];  // add cost
            minCost = min(minCost, sum);    // update cost
        }
        
        return;
    }

    // iterate thru adj City of curr City
    for (int adjCity = 1; adjCity <= n; adjCity++)
    {
        // if not visited and can go to adj city
        if (!visited[adjCity] && adjMatrix[currCity][adjCity] != 0)
        {
            visited[adjCity] = true;
            // recurse down
            traverse(adjCity, cityCnt + 1, sum + adjMatrix[currCity][adjCity]);
            visited[adjCity] = false;
        }
    }
}

int main()
{
    input();
    // printMatrix();
    visited[1] = true;  // must mark first city visited
    traverse(1, 1, 0);

    cout << minCost;
}
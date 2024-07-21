#include <bits/stdc++.h>

using namespace std;


// typedef pair<int, int> pii;     // city, topological level


const int MAX = 500;
vector<int> graph [MAX] ;
int tme [MAX] ;
int indegree [MAX] ;
int res [MAX] ;

int N;

void input()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        int temp;
        cin >> temp;

        // mark tme for each building
        tme[i] = temp;
        
        // while true,
        while(true)
        {
            cin >> temp;
            // last digit is -1
            if (temp == -1) break;
            
            indegree[i]++;
            graph[temp].push_back(i);    // temp -> i
        }
    }
}

// use topological sort
void topologicalSort()
{
    // make queue
    queue<int> q;

    // enqueue first nodes
    for (int i = 1; i <= N; i++)
    {
        res[i] = tme[i];

        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    while(!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (int next : graph[curr])
        {
            // reduce indegree
            indegree[next]--;
            res[next] = max(res[next], res[curr] + tme[next]);


            if (indegree[next] == 0)
            {
                q.push(next);   // enqueue next
            }
        }
    }
}

void printInD()
{
    for (int i = 1; i <= N; i++)
        cout << indegree[i] << " ";
    
    cout << "\n";
}

void print()
{
    for (int i = 1; i <= N; i++)
    {
        cout << res[i] << "\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();
    // printInD();
    topologicalSort();
    print();
}
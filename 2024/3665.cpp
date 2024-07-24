#include <bits/stdc++.h>

using namespace std;

// sorting from lowest score -> highest score

int T;
int N;
vector<int> lastRank;

const int MAX = 500 + 1;
int graph[MAX][MAX];        // [higher-score][lower-score]
int indegree[MAX];          

void init()
{
    lastRank.clear();
    for (int i = 0; i < MAX; i++)
    {
        indegree[i] = 0;
        for (int j = 0; j < MAX; j++)
        {
            graph[i][j] = 0;
        }
    }
}

void printInDegree()
{
    for (int i = 1; i <= N; i++)
    {
        cout << indegree[i] << " ";
    }
    cout << "\n";
}

void printGraph()
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }
}

void input()
{
    cin >> N;
    

    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        lastRank.push_back(temp);
    }

    // init indegree and graph array
    for (int i = 0; i < lastRank.size(); i++)
    {
        for (int j = i + 1; j < lastRank.size(); j++)
        {
            int higher = lastRank[i];
            int lower = lastRank[j];
            // cout << "lower : " << lower << " higher : " << higher << "\n";
            
            graph[higher][lower]++;  
            indegree[lower]++;      
        }
    }

    // cout << "originally : ";
    // printInDegree();
    // printGraph();
    int m;
    cin >> m;

    // modify topological order
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b; // a placed above b
        

        // [higher][lower]
        /* 여기 틀림 */
        if (graph[a][b] == 1) {
            graph[a][b] = 0;
            indegree[b]--;
            graph[b][a] = 1;
            indegree[a]++;
        }
        else {
            indegree[a]--;
            graph[b][a] = 0;
            graph[a][b] = 1;
            indegree[b]++;
        }
    }

    // cout << "aftermodified : ";
    // printInDegree();
    // printGraph();
}

void topSort()
{
    vector<int> res;

    queue<int> q;
    for (int i = 1; i <= N; i++)
    {
        if (indegree[i] == 0) // lower ranks first !!!
        {
            q.push(i);
        }
    }

    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        res.push_back(curr);    // push lowest ranks first

        for (int i = 1; i <= N; i++)
        {
            // only when i is higher than curr, 
            if (graph[curr][i] == 0)    continue;
            
            // i is next 
            indegree[i]--; 
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }
    }

    if (res.size() != N)
    {
        cout << "IMPOSSIBLE";
    }
    else
    {
        for (int i = 0; i < res.size(); i++)
        {
            cout << res[i] << " ";
        }
    }

    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while(T--)
    {
        init();
        input();
        // printInDegree();
        // printGraph();
        topSort();
    }
}
#include <bits/stdc++.h>

using namespace std;

const int MAX = 100000 + 1;
int N, M;
vector<int> graph[MAX];
int indegree[MAX];



void input()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int A, B;
        cin >> A >> B;

        // A < B 
        indegree[B]++;
        graph[A].push_back(B);  // A- > B
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}
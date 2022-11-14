#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii; // rename pair to pii

// 백준 범위 런타임에러 조심하기
const int MAX_N = 1e3 + 3;
const int MAX_M = 1e5 + 5;
const int INF = 1e9;

vector<pii> adj[MAX_N];   // make vector array of size of numCities
priority_queue<pii> pq;   // make priority queue to start (0)
int res[MAX_N];           // make cities array (by far shortest path to index city from start)

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int numCities, numBus;
  cin >> numCities;
  cin >> numBus;

  // add to vector
  for (int i =0; i<numBus; i ++)
  {
    int from, to, cost;
    cin >> from >> to >> cost;
    adj[from].push_back({cost,to}); // in city from, add pair {cost, adj city}
  }

  int start, end;
  cin >> start >> end;

  // initially as infinity
  for (int i = 0; i<numCities+1; i++)
      res[i] = INF;

  // DIJKSTRA algorithm
  pq.push({0,start});
  while (!pq.empty())
  {
    pii cur = pq.top(); pq.pop();
    int currNode = cur.second;
    int currWeight = (-1) * cur.first;

    if (res[currNode] < currWeight) continue; // existing shortest path is less than what is incoming

    // iterate through adjacent vector (for each)
    for (pii e : adj[currNode])
    {
      int nextNode = e.second;
      int nextWeight = currWeight + e.first;
      // change only when next weight is smaller than original weight
      if (nextWeight < res[nextNode])
      {
        res[nextNode] = nextWeight;
        pq.push({ (-1) * nextWeight, nextNode}); // add to priority queue <new weight, new node to check
      }

    }
  }

  cout << res[end]<<endl;

  return 0;
}

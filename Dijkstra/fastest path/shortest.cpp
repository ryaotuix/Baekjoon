#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> pii; // rename pair<int,int> to pii
const int INF = 1e9;

int main() // 백준 1753
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int V; // num nodes
  int E; // num edges

  int start;
  cin >> V >> E;
  cin >> start;

  int res[V+1]; // results array
  for (int i =0; i< V+1; i++) {
    res[i] = INF;
  }
  // filled with inf

  // initialize vector (node number for index and pairs inside) PAIRS are adjacent {weight til that, node number}
  vector<pii> adj[V+1]; // vector list of

  priority_queue<pii> pq;

  // loop through and add to the vectors
  for (int i = 0; i<E; i++) {
    int from;
    int to;
    int weight;
    cin >> from >> to >> weight;

    pii toadd = {weight, to};
    adj[from].push_back(toadd);
  }


  // Check if it enters into vectors
  /*
  for (int i=0; i<V+1; i++) {
    for(pii x:adj[i]) {
      cout << "node " << i << " goes to " << x.first << " has weight of " << x.second <<endl;
    }
  }
  */



  // DIJKSTRA MOTHERFUCKER
  pq.push({0,start}); // initialize in priority priority_queue
  res[start] = 0; // weight to the start position is 0

  while (!pq.empty())
  {
    pii curr = pq.top(); pq.pop(); // curr is top and then get pop
    int currNodNum = curr.second;
    int currWeight = (-1) * curr.first; // multiply by -1

    if (currWeight != res[currNodNum]) continue;

    for (pii elem : adj[currNodNum])
    {
      int next = elem.second; // next
      int nWeight = currWeight + elem.first; // new Weight
      if (nWeight < res[next])
      {
        res[next] = nWeight;
        pq.push({-1 * nWeight, next});
      }

    }
  }

  for (int i = 1; i<V+1; i++) {
    if (res[i] == INF) { // no route
      cout << "INF";
    } else {
      cout << res[i];
    }
    cout << endl;
  }

  return 0;
}

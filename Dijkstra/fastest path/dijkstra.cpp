#include <iostream>
#include <vector>
#include <queue>
#include <string.h>


using namespace std;

typedef pair<int, int> pii; // <weight , node #> which means the length goes first
const int INF = 1e9; // define int
const int numNode = 4 + 1; // +1 just in case. number of node for this case is 4

priority_queue<pii> pq; // it's going to have <weight, node #> in it
// sort by descending order (larger one pops first)

vector<pii> adj[numNode]; // this makes vector (array of arraylist for pii)
int res[numNode]; // it will have shortest weight of EACH NODE


int main() {
  // faster input output
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  // set all res[i] as inf
  for (int i =0; i<5; i++) {
    res[i] = INF;
    //cout << res[i] << endl;
  }

  // add info in vecotrs with pairs
  adj[1].push_back({10,2});
  adj[1].push_back({30,3});

  adj[2].push_back({15,3});
  adj[2].push_back({20,4});

  adj[3].push_back({40,4});


  // DIJKSTRA ALGORITHM
  pii start = {0,1}; // starting at first node as pair
  res[1] = 0;
  pq.push(start); // add it to priority queue

  while (!pq.empty()) {
    pii curr = pq.top(); // top pair
    pq.pop();

    int currWeight = -1 * (curr.first); // this is current node's weight

    int currNodenum = curr.second; // current node number

    for (pii edge: adj[currNodenum]) {
      int nextNode = edge.second; // connected node's number
      int nextWeight = currWeight + edge.first; // determine the weight til next node

      if (nextWeight < res[nextNode]) {
        res[nextNode] = nextWeight;
        pii toPush = {-1 * nextWeight, nextNode}; // priority queue as default pop the greatest first
        pq.push(toPush);
      }
    }
  }

  for (int i = 1; i<5; i++) {
    if (res[i] == 0) {
      cout << "Starting position";
    } else if (res[i] == INF){
      cout << "No Route";
    } else {
      cout << "the shortest weight to " << i << " is " << res[i];
    }
    cout << endl;
  }

  return 0;
}

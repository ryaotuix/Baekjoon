#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;
const int dis = 1; // all edge's distance is 1
const int INF = 1e9;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int numCity, numEdge, distance, start;
  cin >> numCity >> numEdge >> distance >> start;

  int res[numCity + 1]; // city 0, city 1, city 2... <DISTANCE TO THE CITY IN INT>
  for (int i=0; i< numCity+1; i++) {
    res[i] = INF;
  }
  // all distance to city are set as infinity

  vector<int> adj[numCity + 1]; // in an index city, add adjacent cities

  // Add adjacent cities
  for (int i=0; i< numEdge; i++)
  {
    int from, to;
    cin >> from >> to;

    adj[from].push_back(to);
  }

  // make priority queue (so that we can check what city we are at)
  queue<int> cities;
  cities.push(start); // now have as starting city
  res[start] = 0;// !!! IMPORTANT we would have to put start length as 0


  while (!cities.empty())
  {
    int thisCity = cities.front(); cities.pop(); // get the top
    int currWeight = res[thisCity]; // weight of this City by far

    // loop through that vector
    for (int e : adj[thisCity])
    {
      int length = currWeight + 1;
      if (length < res[e]) // length is less than original length
      {
        res[e] = length; // replace with current length
        cities.push(e); // add this element city to the queue
      }
    }
  }


  bool isPrinted = false;
  for (int i = 1; i<numCity+1; i++)
  {
    if (res[i] == distance)
    {
      isPrinted = true;
      cout << i << endl;
    }
  }

  if (!isPrinted) cout << -1 << endl;

  return 0;
}

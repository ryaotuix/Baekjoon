#include <bits/stdc++.h>

using namespace std;

// Materials
unordered_map<string, int> cityToInd;       // map city -> index
unordered_map<int, string> indToCity;       // map index -> city
// bool visited[10000] = {0};                  // boolean visited array 
bool inprogress[10000] = {0};               // boolean inprogress array



    // dfs traversal using adj Vector, and initial city index
void dfs(vector<vector<int>> & adjVector, int city, bool & cycle)
{
    inprogress[city] = true;                            // mark this city as inprogress

    int temp;
    // loop through adjacent nodes
    for (int adjCity : adjVector[city])                 // for all adjacent cities
    {
        temp = adjCity;
        if (inprogress[adjCity] == false)               // if the city is not inprogress
            dfs(adjVector, adjCity, cycle);             // call it again
        else 
        {
            cycle = true;                               // if the city is inprogress, this graph is cycle
            return;                                     // terminate
        }   
    }

    inprogress[city] = false;                           // Once it has gone through all the adjacent list, it is done out of inprogress
    // visited[city] = true;                               // now it is visited
}

int main()
{
    int n; cin >> n;                                    // max of n is 5000
    

    vector<vector<int>> adjVector (2*n, vector<int>()); // vector of vector strings
   

    int i = 0;
    for (int j = 0; j < n; j++)
    {
        string cityFrom, cityTo; 
        cin >> cityFrom >> cityTo;

        // if city coming from is not already in the map,
        if (cityToInd.find(cityFrom) == cityToInd.end())
        {
            cityToInd[cityFrom] = i;                    // make city -> index
            indToCity[i] = cityFrom;                    // make index -> city
            i++;
        }

        // if city going to is not already in 
        if (cityToInd.find(cityTo) == cityToInd.end())
        {
            cityToInd[cityTo] = i;                      // make city -> index
            indToCity[i] = cityTo;                      // make index -> city
            i++;
        }

        int indFrom = cityToInd.at(cityFrom);           // get index for city coming from
        int indTo = cityToInd.at(cityTo);               // get index for city going to

        adjVector.at(indFrom).push_back(indTo);         // and update adjacency Vector
    }


    string city;
    while (cin >> city) 
    {
        // memset(visited, 0, sizeof(visited));                // make the visited array false
        memset(inprogress, 0, sizeof(inprogress));          // make the progress array false    
        bool cycle = false;                                 // default : not cycle

        int indCity = cityToInd.at(city);                   // get city -> index    
        dfs(adjVector, indCity, cycle);                     // dfs to decide if it is a cycle

        // print information
        if (cycle == true) { cout << city << " " << "safe";}
        else cout << city << " "<<  "trapped";
        cout << endl;
    }

  
    
}
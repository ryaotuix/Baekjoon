#include <bits/stdc++.h>

using namespace std;

// Materials
unordered_map<string, int> cityToInd;
unordered_map<int, string> indToCity;
unordered_map<string, bool> visitedCity;
bool visited[1000] = {0};

void printUmap()
{
    cout << "Print UMAPS ====================================\n";
    for (auto i : cityToInd)
        cout << i.first << " " << i.second << endl;

    cout << endl;

    for (auto i : indToCity)
        cout << i.first << " " << i.second << endl;
    
    cout << endl;
}

void dfs(vector<vector<int>> & adjVector, int city, bool & cycle)
{
    visited[city] = true;

    // loop through adjacent nodes
    for (int adjCity : adjVector[city])
    {
        if (visited[adjCity] == false)
            dfs(adjVector, adjCity, cycle);
        else cycle = true; 
    }
}

int main()
{
    int n; cin >> n;        // max of n is 5000
    

    vector<vector<int>> adjVector (2*n, vector<int>()); // vector of vector strings
   

   
    

    int i = 0;
    // Make a 1 to 1 correspondence to integer (index) and city name
    for (int j = 0; j < n; j++)
    {
        string cityFrom, cityTo; 
        cin >> cityFrom >> cityTo;

        // if city coming from is not already in the map,
        if (cityToInd.find(cityFrom) == cityToInd.end())
        {
            cityToInd[cityFrom] = i;
            indToCity[i] = cityFrom;
            i++;
        }

        // if city going to is not already in 
        if (cityToInd.find(cityTo) == cityToInd.end())
        {
            cityToInd[cityTo] = i;
            indToCity[i] = cityTo;
            i++;
        }

        int indFrom = cityToInd.at(cityFrom);
        int indTo = cityToInd.at(cityTo);

        adjVector.at(indFrom).push_back(indTo);
    }


    string city;
    while (cin >> city) 
    {
        memset(visited, 0, sizeof(visited));
        bool cycle = false;

        int indCity = cityToInd.at(city);
        dfs(adjVector, indCity, cycle);
        if (cycle == true) { cout << city << " " << "safe";}
        else cout << city << " "<<  "trapped";
        cout << endl;
    }

  
    
}
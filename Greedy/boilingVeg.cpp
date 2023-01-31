#include <bits/stdc++.h>


using namespace std;

void print(auto * arr, int n)
{
    for (int i = 1; i <=n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    double ratio; cin >> ratio;
    int n; cin >> n;

    double weights[n]; // array to store information about weight
    double currWeights[n];
    int cut[n]; // array to store cut information
    double ultmin = 1E6;
    double ultmax = 0;
    int maxInd, minInd;

    // store weight information
    for (int i = 0; i <n; i++)
    {   
        double weight; cin >> weight;
        weights[i+1] = weight;
        currWeights[i+1] = weight;
        // update minimum
        if (weight < ultmin) 
        {
            ultmin = weight;
            minInd = i+1;
        }
        if (weight > ultmax) {
            ultmax = weight;
            maxInd = i+1;
        }
    }
    // set cut values as 1
    for (int i = 0; i <= n; i++)
        cut[i] = 1;
    

    int res = 0;


    while (true)
    {
        if (ultmin >= ultmax * ratio) break;

        cout << "CURRENT WEIGHTS: \n";
        print(currWeights, n);
        cout << "CURRENT CUTS: \n";
        print(cut, n);
        cout << "MAX : " << ultmax << endl;
        cout << "MIN : " << ultmin << endl;
        int cutInd = 1;
        double reducing = (weights[1]/ (cut[1])) - (weights[1] / (cut[1] + 1));
        for (int i = 2; i<=n; i++)
        {
            double currweight = weights[i] / cut[i];
            double afterweight = weights[i] / (cut[i]+1);
            double dif = currweight - afterweight;
            if (dif > reducing) 
            {
                cutInd = i;
                reducing = (weights[i]/ (cut[i])) - (weights[i] / (cut[i] + 1));
            } 
        }
        cout << "we are reducing " << reducing << " by cutting index " << cutInd << endl;
        cout << endl;

        cut[cutInd]++; // increment the cut number
        res++;
        
        // updated value is smaller than ultmin?
        double change = weights[cutInd]/cut[cutInd];
        currWeights[cutInd] = change;
        print(currWeights, n);


        ultmax = *max_element(currWeights+1, currWeights+n); // 최대값
        ultmin = *min_element(currWeights+1, currWeights+n); // 최소값
        cout << ultmax << " " << ultmin << "\n";
        cout << "===================================\n"; 
    }
    cout << res << endl;
    
    

    

    

}
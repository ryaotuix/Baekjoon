#include <bits/stdc++.h>


using namespace std;

struct fruit {
    int org;
    int cut = 1;

    // this is comparing the fruits (ex. curr weight = org/cut)
    // org1/cut1 < org2/cut2 ====> org1*cut2 < org2*cut1
    bool operator< (fruit& other) {return org*other.cut < other.org*cut;}
    bool operator== (fruit& other) {return (org==other.org) && (cut==other.cut);}
};


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
    string r; cin >> r;
    int ratio = stoi(r.substr(2)); // this change substring starting index of 2 into a ratio
    // cout << ratio;

    int n; cin >> n;
    fruit fruits[n+1];

    // store weight information
    for (int i = 0; i <n; i++)
    {   
        cin >> fruits[i+1].org;
    }
    

    int res = 0;
    fruit ultmax;
    fruit ultmin;


    // when to end? max * ratio <= min
    // max *mincut * ratio <= min * maxcut
    while (true)
    {
        ultmax = *max_element(fruits+1, fruits+n+1); // max fruit
        ultmin = *min_element(fruits+1, fruits+n+1); // min fruit
        int max = ultmax.org; int min = ultmin.org; int maxcut = ultmax.cut; int mincut = ultmin.cut;
        // cout << max << " " << maxcut << " " << min << " " << mincut << "\n";
        // cout << max * mincut * ratio << " " << 100* min * maxcut;
        if (max * mincut * ratio  <= 100* min * maxcut) break;

        for (int i =1; i<= n; i++)
        {
            if (fruits[i] == ultmax) 
            {
                fruits[i].cut = fruits[i].cut + 1;
                res++;
            }
        }
    }
    cout << res << endl;
    
    
}
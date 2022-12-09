#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int num_topping; cin >> num_topping;

    int dough_price, topping_price; cin >> dough_price >> topping_price;
    int dough_cal; cin >> dough_cal;
    
    int arr[num_topping]; // 토핑 칼로리 저장!
    for (int i = 0; i < num_topping; i++)
    {
        cin >> arr[i];
    }
    // sort arr in descending order
    sort(arr, arr+num_topping, greater<>());
   

    double curr_price = dough_price;
    double curr_cal = dough_cal;
    //cout << curr_price << " " << curr_cal << endl;


    int ind = 0;
    while (ind != num_topping)
    {
        double curr_eff = curr_cal / curr_price;
        double next_eff = (curr_cal + arr[ind]) / (curr_price + topping_price);

        //cout << curr_eff << " " << next_eff << endl;

        if (curr_eff > next_eff)
        {
            break;
        }
        else 
        {
            curr_cal += arr[ind];
            curr_price += topping_price;
        }
        ind++;
    }

    cout << (int) (curr_cal/curr_price);
    return 0;
}
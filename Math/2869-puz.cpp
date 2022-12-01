#include <iostream>

using namespace std;

int main()
{
    int A,B,V;
    cin >> A >> B >> V;

    int nominator = V -B;
    int denominator = A-B;
    if (nominator % denominator == 0)
    {
        cout << nominator/denominator << endl;
    } else {
        cout << nominator/denominator + 1 << endl;
    }
    return 0;



    /*
    // starting day 0, climb up 0
    int day = 0;
    int climb = 0;



    while (true)
    {
        day++; // increment the day
        climb += A; 
        if (climb >= V)
        {
            cout << day << endl;
            return 0 ;
        }
        climb -= B;
    }
    return 0;
    */
}
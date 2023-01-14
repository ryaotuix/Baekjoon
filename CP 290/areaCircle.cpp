#include <iostream>
#include <iomanip>
#include <math.h>


typedef pair<
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    double r; // <= 1000 <Radius>
    signed int m; // it is less than 10^5 <total marked points>
    signed int c; // <= m <# of marked points in the circle>

    const double PI = M_PI;


    while(true)
    {
        cin >> r >> m >> c;
        if(r== (double) 0 && m== 0 && c==0) return 1;

        double area = r * r * PI;
        double estimated = r * r * 4 * c / m;
        cout << setprecision(10);
        cout << area << " " << estimated << "\n";
    }
}
#include <stdio.h>
#include <iostream>

using namespace std;
int main() {
    int i = 0;
    int j = i; // does the DEEP COPY HMMM

    cout << i << " " << j;
    j = j-1;
    i = i +1;
    cout << endl;
    cout << i << " " << j;

}
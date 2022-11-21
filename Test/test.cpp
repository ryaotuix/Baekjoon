#include<iostream>
using namespace std;

bool s[10] = {true}; // 안됨!!
bool s[10]

int main()
{
    for(int u = 0 ; u < 10; ++u){
        cout << s[u] << " ";
    }
}
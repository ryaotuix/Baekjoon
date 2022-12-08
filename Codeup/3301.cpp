#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int arr [] = {50000, 10000, 5000, 1000, 500, 100, 50, 10};
 
int main()
{
    int cnt = 0;
    int money; cin>>money;
    // for (int i = 0; i < 8; i++)
    // {
    //     cnt += money/arr[i];
    //     money = money % arr[i];
    // }

    int i = 0;

    while (money != 0)
    {
        cnt += money / arr[i];
        money = money % arr[i];
        i++;
    }
    cout << cnt;

    return 0;
}



/*
int main()
{
    int cost; 
    scanf("%d", &cost);

    int cnt = cost / 50000;
    
    cost = cost % 50000;
    int manwon = cost / 10000;
    cnt += manwon;

    cost = cost % 10000;
    int ochon = cost / 5000;
    cnt += ochon;

    cost = cost % 5000;
    int cheonwon = cost /1000;
    cnt += cheonwon;

    cost = cost % 1000;
    cnt += (cost / 500);

    cost = cost % 500;
    cnt += (cost / 100);

    cost = cost % 100;
    cnt += (cost / 50);
    
    cost = cost % 50;
    cnt += cost / 10;

    cout << cnt;

    return 0;

}
*/
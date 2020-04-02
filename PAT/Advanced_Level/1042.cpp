/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;
int main(int argc, char const *argv[]) {
    int repeat;
    cin >> repeat;
    // total 54 cards
    int arr[55];
    for (int i = 1; i <= 54; i++)
        arr[i] = i;
    int shuffle[55];
    for (int i = 1; i <= 54; i++)
        scanf("%d", &shuffle[i]);
    
    int res[55];
    while (repeat)
    {   
        for (int i = 1; i <= 54; i++)
            res[shuffle[i]] = arr[i];
        for (int i = 1; i <= 54; i++) {
            arr[i] = res[i];
            //cout << arr[i] << " ";
        }
        //cout <<"end"<< endl;
        repeat--;
    }

    for (int i  = 1; i <= 54; i++) {
        if (res[i] <= 13)
            printf("S%d", res[i]);
        else if (res[i] <= 26)
            printf("H%d", res[i] - 13);
        else if (res[i] <= 39)
            printf("C%d", res[i] - 26);
        else if (res[i] <= 52)
            printf("D%d", res[i] - 39);
        else
            printf("J%d", res[i] - 52);
        if (i != 54)
            printf(" ");
    }
    
    return 0;
}


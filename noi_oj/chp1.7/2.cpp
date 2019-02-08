// // 这个方法只能得到9分，原因未知
// #include <iostream>
// #include <string>

// using namespace std;
// int main(int argc, char const *argv[])
// {
//     int arr[26] = {0};
//     string str;
//     getline(cin, str);

//     for (int i = 0; i < str.length(); ++i) {
//         arr[(int)str[i]-('a')]++;
//     }
//     int j;
//     for (j = 0; j < 26; ++j) {
//         if (arr[j] == 1) {
//             cout << (char)(j+'a') << endl;
//             break;
//         }
//     }
//     if (j == 26)
//         cout << "no" << endl;
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a;
    int k;
    getline(cin, a);
    for (int i = 0; i < a.size(); i++)
    {
        k = 0;
        for (int j = 0; j < a.size(); j++)
        {
            if (a[i] == a[j])
                k++;
        }
        if (k == 1)
        {
            cout << a[i];
            return 0;
        }
    }
    cout << "no";
    return 0;
}
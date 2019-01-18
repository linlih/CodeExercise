// #include <iostream>
// #include <string>
// #include <stack>

// using namespace std;
// int main(int argc, char const *argv[])
// {
//     char num[100] = {'\0'};
//     cin >> num;
//     stack<char> str;
//     int i = 0;
//     int flag = 0;
//     int negative = 0;
//     if (num[0] == '0')
//         cout << '0' << endl;
//     else {
//         if (num[0] == '-') {
//             i++;
//             negative = 1;
//         }
//         while (num[i] != '\0') {
//             str.push(num[i]);
//             i++;
//         }
//         if (negative) {
//             str.push('-');
//         }

//         while (!str.empty()) {
//             while (str.top() == '0') {
//                 str.pop();   
//             }
//             cout << str.top();
//             str.pop();
//         }
//         cout << endl;
//     }
//     return 0;
// }

#include <iostream>
using namespace std;
int main()
{
    int n, sum = 0;
    cin >> n;
    while (n) {
        sum = sum * 10 + n % 10;
        n /= 10;
    }
    cout << sum;
}
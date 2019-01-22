// 这道题的测试样例是错误，题目给的样例输入和样例输出是多组的，实际上要按照题目说的只有一组的形式

#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    int c;
    int tmp;
    cin >> c;
    if (c == 0) {
        cin >> tmp;
        cout << "0" << endl;
    }
    else {
        for (int j = c; j > 0; --j)
        {
            cin >> tmp;
            cin >> skipws;
            cout << tmp * j << " ";
        }
        cin >> tmp;
        cout << endl;
    }

    return 0;
}
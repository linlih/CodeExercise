#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    int cnt[26] = {0};
    string line;
    for (int i = 0; i < 4; ++i) {
        getline(cin, line);
        for (int j = 0; j < line.length(); ++j) {
            if (line[j] >= 'A' && line[j] <= 'Z')
                cnt[line[j] - 'A']++;
        }
    }
    int max = cnt[0];
    for (int i = 1; i < 26; ++i) {
        if (max < cnt[i])
            max = cnt[i];
    }

    // 这种实现方法会多打印一个空格，这里没有做处理
    for (int i = max; i > 0; --i) {
        for (int j = 0; j < 26; ++j) {
            if (cnt[j] < i) {
                cout << "  ";
            }
            else {
                cout << "* "; 
            }
        }
        cout << endl;
    }

    for (int i = 0; i < 26; ++i)
        cout << (char)('A' + i) << " ";
    cout << endl;

    return 0;
}
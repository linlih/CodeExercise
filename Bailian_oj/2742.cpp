#include <iostream>
#include <memory.h>

using namespace std;
int main(int argc, char const *argv[])
{
    int cnt[26] = {0};
    int n;
    cin >> n;
    string str;
    for (int i = 0; i < n; i++) {
        cin >> str;
        if (str == "\n") {
            i++;
            continue;
        }
        for (int j = 0; j < str.length(); ++j) {
            cnt[str[j] - 'a']++;
        }
        int index = 0;
        while (cnt[index] == 0)
            index++;
        int max = cnt[index];
        int max_i = index;
        for (int k = index + 1; k < 26; ++k) {
            if (cnt[k] != 0 && max < cnt[k]) {
                max = cnt[k];
                max_i = k;
            }
        }
        cout << (char)(max_i+'a') << " " << max << endl;
        memset(cnt, 0, sizeof(int)*26);
    }
    return 0;
}
#include <iostream>
#include <stdio.h>
#include <memory.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int characters[26];
    int n, m, p;
    int i, j;
    for (i = 0; i < 26; i++)
        characters[i] = 0;
    cin >> n >> m >> p;
    for (i = 0; i < n; i++) { // 记录每个字母出现的次数
        char str[11];
        memset(str, 0, sizeof(str));
        scanf("%s", str);
        for (j = 0; str[j]!='\0'; j++) 
            characters[str[j] - 'A']++;
    }
    for (i = 0; i < p; i++) {
        char str[200];
        memset(str, 0, sizeof(str));
        scanf("%s", str);
        for (j = 0; str[j]!='\0'; j++)
            characters[str[j] - 'A']--;
    }
    for (i = 0; i < 26; i++) {
        if (characters[i] != 0)
            for (j = 0; j < characters[i]; j++)
                printf("%c", i+'A');
    }
    cout << endl;

    return 0;
}
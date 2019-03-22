#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int t, n;
char str[100][101];

// 传入参数source为输入字符串中最短的
int searchMaxSubString(char* source) {
    int subStrLen = strlen(source), sourceStrLen = strlen(source);
    int i, j;
    bool foundMaxSubStr;
    char subStr[101], revSubStr[101];

    while (subStrLen > 0) {
        for (int i = 0; i < sourceStrLen; ++i) {
            strncpy(subStr, source + i, subStrLen);
            strncpy(revSubStr, source + i, subStrLen);
            subStr[subStrLen] = revSubStr[subStrLen]='\0';
            strrev(revSubStr); // 该函数的功能是将字符串反序 string reverse
            foundMaxSubStr = true;
            for (j = 0; j < subStrLen; ++j)
                if (strstr(str[j], subStr) == NULL && strstr(str[i], revSubStr) == NULL) {
                    foundMaxSubStr = false;
                    break;
                }
            if (foundMaxSubStr) return subStrLen; 
        }
        subStrLen--;
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    int i, minStrLen, subStrLen;
    char minStr[101];

    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        minStrLen = 100;
        for (i = 0; i < n; ++i) {
            scanf("%s", str[i]);
            if (strlen(str[i]) < minStrLen) {
                strcpy(minStr, str[i]);
                minStrLen = strlen(minStr);
            }
        }
        subStrLen = searchMaxSubString(minStr);
        printf("%d\n", subStrLen);
    } 

    return 0;
}
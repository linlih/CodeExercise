#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define NUM 202
int key[NUM], times[NUM];
char str1[NUM], str2[NUM];

// reference: http://bailian.openjudge.cn/topic/4595/

int main(int argc, char const *argv[])
{
    int i, n, m, count;
    int tmp;
    char ch;

    while (scanf("%d", &n) != EOF && n) {
        for (i = 1; i <= n; ++i) 
            scanf("%d", &key[i]);
        
        // 统计次数，避免复杂的循环
        for (i = 1; i <= n; ++i) {
            tmp = i;
            count = 0;
            do {
                tmp = key[tmp];
                count++;
            } while (tmp != i);
            times[i] = count;
        }

        while (scanf("%d", &m) != EOF && m) {
            getchar();
            i = 1;
            while ((ch = getchar()) != '\n')
                str1[i++] = ch;
            while (i <= n) 
                str1[i++] = ' ';
            for (i = 1; i <= n; ++i) {
                count = m % times[i];
                tmp = i;
                while (count --)
                    tmp = key[tmp];
                str2[tmp] = str1[i];
            }
            str2[n + 1] = '\0';
            printf("%s\n", str2 + 1);
        }
        printf("\n");
    }

    return 0;
}
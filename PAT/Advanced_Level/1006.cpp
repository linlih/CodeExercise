/*
 * 运行数据： ms  KB
 */
#include <bits/stdc++.h>
#include <stdio.h>

typedef struct person {
    char id[16];
    char sign_in[16];
    char sign_out[16];
}person;

using namespace std;
int main(int argc, char const *argv[])
{
    int M;
    cin >> M;
    person *persons = new person[M];
    for (int i = 0; i < M; ++i) {
        cin >> persons[i].id >> persons[i].sign_in >> persons[i].sign_out;
    }

    char in_id[100];
    // find the earliest id
    char tmp[2][7] = {0};
    for (int i = 0; i < M - 1; ++i) {
        long num_1 = 0, num_2 = 0;
        tmp[0][0] = persons[i].sign_in[0];
        tmp[0][1] = persons[i].sign_in[1];
        tmp[0][2] = persons[i].sign_in[3];
        tmp[0][3] = persons[i].sign_in[4];
        tmp[0][4] = persons[i].sign_in[6];
        tmp[0][5] = persons[i].sign_in[7];

        tmp[1][0] = persons[i+1].sign_in[0];
        tmp[1][1] = persons[i+1].sign_in[1];
        tmp[1][2] = persons[i+1].sign_in[3];
        tmp[1][3] = persons[i+1].sign_in[4];
        tmp[1][4] = persons[i+1].sign_in[6];
        tmp[1][5] = persons[i+1].sign_in[7];
        num_1 = atoi(tmp[0]);
        num_2 = atoi(tmp[1]);
        if (num_1 <= num_2) {
            strcpy(in_id, persons[i].id);
        }
        else {
            strcpy(in_id, persons[i+1].id);
        }
    }
    cout << in_id << " ";

    char out_id[100];
    for (int i = 0; i < M - 1; ++i) {
        long num_1 = 0, num_2 = 0;
        tmp[0][0] = persons[i].sign_in[0];
        tmp[0][1] = persons[i].sign_in[1];
        tmp[0][2] = persons[i].sign_in[3];
        tmp[0][3] = persons[i].sign_in[4];
        tmp[0][4] = persons[i].sign_in[6];
        tmp[0][5] = persons[i].sign_in[7];

        tmp[1][0] = persons[i+1].sign_in[0];
        tmp[1][1] = persons[i+1].sign_in[1];
        tmp[1][2] = persons[i+1].sign_in[3];
        tmp[1][3] = persons[i+1].sign_in[4];
        tmp[1][4] = persons[i+1].sign_in[6];
        tmp[1][5] = persons[i+1].sign_in[7];
        num_1 = atoi(tmp[0]);
        num_2 = atoi(tmp[1]);
        if (num_1 >= num_2) {
            strcpy(out_id, persons[i].id);
        }
        else {
            strcpy(out_id, persons[i+1].id);
        }
    }
    cout << out_id;

    return 0;
}


///////////////////////////////////////////////////////////
/* 
// reference:
#include <iostream>
#include <climits>
using namespace std;
int main() {
    int n, minn = INT_MAX, maxn = INT_MIN;
    scanf("%d", &n);
    string unlocked, locked;
    for(int i = 0; i < n; i++) {
        string t;
        cin >> t;
        int h1, m1, s1, h2, m2, s2;
         // 遇到格式化输入的优先考虑使用scanf
        scanf("%d:%d:%d %d:%d:%d", &h1, &m1, &s1, &h2, &m2, &s2);
        int tempIn = h1 * 3600 + m1 * 60 + s1;
        int tempOut = h2 * 3600 + m2 * 60 + s2;
        if (tempIn < minn) {
            minn = tempIn;
            unlocked = t;
        }
        if (tempOut > maxn) {
            maxn = tempOut;
            locked = t;
        }
    }
    cout << unlocked << " " << locked;
    return 0;
}

*////////////////////////////////////////////////////////////
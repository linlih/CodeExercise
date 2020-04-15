// /*
//    问题描述：
//    解题思路： 
//  */
// #include <bits/stdc++.h>

// using namespace std;

// struct  element
// {
//     int next;
//     int key;
// };

// element arr[10010];

// int main(int argc, char const *argv[]) {
//     int n, start;
//     cin >> n >> start;
//     int addr, key, next;

//     for (int i = 0; i < n; i++) {
//         cin >> addr >> key >> next;
//         arr[addr].next = next;
//         arr[addr].key = key;
//     }

//     // 选择排序
//     // addr = start;
//     // for (int i = 0; i < n; i++) {
//     //     int min = arr[addr].key;
//     //     next = arr[addr].next;
//     //     addr = next;
//     //     int min_addr;
//     //     while (arr[addr] != -1) {
//     //         addr = arr[addr].next;
//     //         if (min > arr[addr].key) {
//     //             min_addr = addr;
//     //             min = arr[addr].key;
//     //         }
//     //     }
//     //     // 最小值不是现在这个
//     //     arr[]
//     // }

//     return 0;
// }

/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

struct NODE {
    int addr, key, next;
    bool flag;
}node[100000];

int cmp1(NODE a, NODE b) {
    return !a.flag || !b.flag ? a.flag > b.flag : a.key < b.key;
}

using namespace std;
int main(int argc, char const *argv[]) {
    int n, cnt = 0, s, a, b, c;
    scanf("%d%d", &n, &s);
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &a, &b, &c);
        node[a] = {a, b, c, false};
    }
    for (int i = s; i != -1; i= node[i].next) {
        node[i].flag = true;
        cnt++;
    }
    if (cnt == 0) {
        printf("0 -1");
    } 
    else {
        sort(node, node + 100000, cmp1);
        printf("%d %05d\n", cnt, node[0].addr);
        for (int i = 0; i < cnt; i++) {
            printf("%05d %d ", node[i].addr, node[i].key);
            if (i!= cnt-1)
                printf("%05d\n", node[i+1].addr);
            else
                printf("-1\n");
        }
    }
    return 0;
}
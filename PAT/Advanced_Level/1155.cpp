// /*
//    问题描述：
//    解题思路： 这个方法不行，会出现错误，一个测试样例过不了。
//  */
// #include <bits/stdc++.h>

// using namespace std;
// vector<int> v(2010, -1);
// int n;
// bool maxheap = false;
// bool minheap = false;

// int flag = -1;
// set<int> s;
// void print_path(int i, vector<int> &path) {
//     if (i > n) return;
//     path.push_back(v[i]);
//     if (2*i <= n && (2*i) <= n && v[i] >= v[2*i] && v[i] >= v[2*i  + 1]) {
//         //maxheap = true; minheap = false;
//         //flag = -1;
//         s.insert(1);
//         //cout << "max: " << v[i] << " " << v[2 *i] << " " << v[2*i + 1] << endl;
//     }
//     if (2*i <= n && (2*i) <= n && v[i] <= v[2*i] && v[i] <= v[2*i  + 1]) {
//         //maxheap = false; minheap = true;
//         //flag = 1;
//         s.insert(-1);
//         //cout << "min: "<< v[i] << " " << v[2 *i] << " " << v[2*i + 1] << endl;
//     }
//     if ((2 * i > n) && ((2*i + 1) > n)) {
//         for (int j = 0; j < path.size(); ++j) {
//             if (j != 0) printf(" ");
//             //cout << path.size() << endl;
//             printf("%d", path[j]);
//         }
//         printf("\n");
//     }
//     print_path(2*i + 1, path);
//     print_path(2*i, path);
//     path.pop_back();
// }

// int main(int argc, char const *argv[]) {
//     freopen("input.txt","r",stdin);
//     scanf("%d", &n);
//     for (int i = 1; i <= n; ++i) {
//         scanf("%d", &v[i]);
//     }
//     vector<int> path;
//     print_path(1, path);
//     // if (minheap)
//     //     printf("Min Heap\n");
//     // else if (maxheap)
//     //     printf("Max Heap\n");
//     // else
//     //     printf("Not Heap\n");
//     if (s.size() > 1)
//         printf("Not Heap\n");
//     else 
//         if (*s.begin() == 1)
//             printf("Max Heap\n");
//         else 
//             printf("Min Heap\n");
    
//     return 0;
// }

/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;
vector<int> v;
int a[1009], n, isMin = 1, isMax = 1;
void dfs(int index) {
    if (index * 2 > n && index * 2 + 1 > n) {
        if (index <= n) {
            for (int i = 0; i < v.size(); ++i)
                printf("%d%s", v[i], i != v.size() - 1? " ":"\n");
        }
    }
    else {
        v.push_back(a[index * 2  + 1]);
        dfs(index * 2 + 1);
        v.pop_back();
        v.push_back(a[index * 2]);
        dfs(index * 2);
        v.pop_back();
    }
}

int main(int argc, char const *argv[]) {
    freopen("input.txt","r",stdin);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }   
    v.push_back(a[1]);
    dfs(1);
    for (int i = 2; i <= n; ++i) {
        if (a[i/2] > a[i]) isMin = 0;
        if (a[i/2] < a[i]) isMax = 0;
    }
    if (isMin == 1)
        printf("Min Heap\n");
    else 
        printf("%s", isMax == 1? "Max Heap\n":"Not Heap\n");
    return 0;
}
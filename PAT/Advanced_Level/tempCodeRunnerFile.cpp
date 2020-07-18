/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;
vector<int> v(2010, -1);
int n;
bool maxheap = false;
bool minheap = false;

int flag = -1;
set<int> s;
void print_path(int i, vector<int> &path) {
    if (i > n) return;
    path.push_back(v[i]);
    if (2*i <= n && (2*i) <= n && v[i] > v[2*i] && v[i] > v[2*i  + 1]) {
        //maxheap = true; minheap = false;
        //flag = -1;
        s.insert(1);
        //cout << "max: " << v[i] << " " << v[2 *i] << " " << v[2*i + 1] << endl;
    }
    if (2*i <= n && (2*i) <= n && v[i] < v[2*i] && v[i] < v[2*i  + 1]) {
        //maxheap = false; minheap = true;
        //flag = 1;
        s.insert(-1);
        //cout << "min: "<< v[i] << " " << v[2 *i] << " " << v[2*i + 1] << endl;
    }
    if ((2 * i > n) && ((2*i + 1) > n)) {
        for (int j = 0; j < path.size(); ++j) {
            if (j != 0) printf(" ");
            //cout << path.size() << endl;
            printf("%d", path[j]);
        }
        printf("\n");
    }
    print_path(2*i + 1, path);
    print_path(2*i, path);
    path.pop_back();
}

int main(int argc, char const *argv[]) {
    freopen("input.txt","r",stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &v[i]);
    }
    vector<int> path;
    print_path(1, path);
    // if (minheap)
    //     printf("Min Heap\n");
    // else if (maxheap)
    //     printf("Max Heap\n");
    // else
    //     printf("Not Heap\n");
    if (s.size() > 1)
        printf("Not Heap\n");
    else 
        if (*s.begin() == 1)
            printf("Max Heap\n");
        else 
            printf("Min Heap\n");
    return 0;
}
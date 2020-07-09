/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;
vector<int> in, pre, post;

bool uniq = true;
void getIn(int preLeft, int preRight, int postLeft, int postRight) {
    if (preLeft ==  preRight) {
        in.push_back(pre[preLeft]);
        return;
    }
    if (pre[preLeft] == post[postRight]) {
        int i = preLeft + 1;
        while(i <= preRight && pre[i] != post[postRight - 1]) i++;
        if (i - preLeft > 1)
            getIn(preLeft + 1, i - 1, postLeft, postLeft + (i - preLeft - 1) - 1);
        else 
            uniq = false;
        in.push_back(post[postRight]);
        getIn(i, preRight, postLeft + (i - preLeft -1), postRight - 1);
    }
}
int main(int argc, char const *argv[]) {
    freopen("input.txt","r",stdin);
    int n;
    cin >> n;
    int temp;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &temp);
        pre.push_back(temp);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &temp);
        post.push_back(temp);
    }
    getIn(0, n - 1, 0, n - 1);
    printf("%s\n%d", uniq == true? "Yes": "No", in[0]);
    for (int i = 1; i < in.size(); ++i) {
        cout << " " << in[i];
    }
    cout << endl;
    return 0;
}
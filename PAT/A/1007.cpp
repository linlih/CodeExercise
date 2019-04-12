#if 1

#else
/*
 * 参考自：https://www.nowcoder.com/questionTerminal/25c3ae17bc99425b99542802ee882377 作者：挥着牛鞭的男孩
 */
#include <bits/stdc++.h>

using namespace std;

int main(){
    string A,res;
    int B,d = 0;
    cin >> A >> B;
    for(int i = 0; i < A.size(); i++){
        int current = d * 10 + (A[i]-'0');
        res += (current / B+'0'); // 记录商 
        d = current % B; // 记录余数
        //cout << i << ": " << current << " " << d <<endl;
    }
    for(int i = (res[0] == '0' && res.size()!=1)?1:0; i < res.size(); i++)
        cout << res[i];
    cout << " " << d << endl;
    return 0;
}
#endif
#if 0
/*
 * 运行数据： ms  KB
 * 由于数据有100000个，所以这种方法需要100000 x 4 倍的数据空间,会导致栈错误
 */
#include <bits/stdc++.h>

using namespace std;

typedef struct stu {
    char num[10];
    int de;
    int cai;
}stu;

bool cmp(const stu& a, const stu& b) {
    if ((a.de+a.cai) > (b.de+b.cai))
        return true;
    else if ((a.de+a.cai) < (b.de+b.cai))
        return false;
    else {
        if (a.de > b.de)
            return true;
        else if (a.de < b.de)
            return false;
        else {
            if (strcmp(a.num, b.num) < 0)
                return true;
            else
                return false; 
        }
    }
}

int main(int argc, char const *argv[])
{
    stu L0[20000];
    stu L1[20000];
    stu L2[20000];
    stu L3[20000];
    stu temp;

    long N, L, H;
    cin >> N >> L >> H;
    long L0_i = 0;
    long L1_i = 0;
    long L2_i = 0;
    long L3_i = 0;
    //cout << "N" << N << "L" << L << "H" << H << endl;
    long total = 0;
    for (long i = 0; i < N; i++) {
        cin >> temp.num >> temp.de >> temp.cai;
        if (temp.de >= H && temp.cai >= H) {
            memcpy(L3[L3_i].num, temp.num, 10);
            L3[L3_i].de = temp.de;
            L3[L3_i].cai = temp.cai;
            L3_i++;
            total++;
        }
        else if (temp.cai < H && temp.cai >= L && temp.de > H) {
            memcpy(L2[L2_i].num, temp.num, 10);
            L2[L2_i].de = temp.de;
            L2[L2_i].cai = temp.cai;
            L2_i++;
            total++;
        }
        else if (temp.de < H && temp.cai < H && temp.de >= L && temp.cai >= L&& temp.de >= temp.cai) {
            memcpy(L1[L1_i].num, temp.num, 10);
            L1[L1_i].de = temp.de;
            L1[L1_i].cai = temp.cai;
            L1_i++;
            total++;
        }
        else if (temp.de >= L && temp.cai >= L) {
            memcpy(L0[L0_i].num, temp.num, 10);
            L0[L0_i].de = temp.de;
            L0[L0_i].cai = temp.cai;
            L0_i++;
            total++;
        }
    }

    cout << "\n=================\n\n";
    cout << "L0_i: " << L0_i << endl;
    cout << "L1_i: " << L1_i << endl;
    cout << "L2_i: " << L2_i << endl;
    cout << "L3_i: " << L3_i << endl;
    cout << endl;
    cout << L0_i+L1_i+L2_i+L3_i << endl;
    sort(L0, L0+L0_i, cmp);
    sort(L1, L1+L1_i, cmp);
    sort(L2, L2+L2_i, cmp);
    sort(L3, L3+L3_i, cmp);
    for (long i = 0; i < L3_i; i++) {
        cout << L3[i].num << " " << L3[i].de << " " << L3[i].cai << endl;
    }
    for (long i = 0; i < L2_i; i++) {
        cout << L2[i].num << " " << L2[i].de << " " << L2[i].cai << endl;
    }
    for (long i = 0; i < L1_i; i++) {
        cout << L1[i].num << " " << L1[i].de << " " << L1[i].cai << endl;
    }
    for (long i = 0; i < L0_i; i++) {
        cout << L0[i].num << " " << L0[i].de << " " << L0[i].cai << endl;
    }
    return 0;
}
#else 
// 参考链接：https://www.nowcoder.com/questionTerminal/97b6a49a85944650b2e3d0660b91c324，作者：Relaxing

/*
 * 运行数据：139 ms	2272 KB
 */
#include <bits/stdc++.h>

using namespace std;

typedef struct stu {
    int id;
    int de;
    int cai;
    int rank;
}stu;

bool cmp(const stu& a, const stu& b) {
    if(a.rank!=b.rank) return a.rank<b.rank;
    else if((a.de+a.cai)!=(b.de+b.cai)) return (a.de+a.cai)>(b.de+b.cai);
    else if(a.de!=b.de) return a.de>b.de;
    else return a.id<b.id;
}

int main(int argc, char const *argv[])
{
    stu s[100010];
    long N, L, H;
    cin >> N >> L >> H;
    int total_num = N;
    for (long i = 0; i < N; i++) {
        cin >> s[i].id >> s[i].de >> s[i].cai;
        if(s[i].de<L ||s[i].cai<L){
            total_num--;
            s[i].rank=5;
        }
        else{
            if(s[i].de>=H && s[i].cai>=H) s[i].rank=1;
            else if(s[i].de>=H && s[i].cai<H) s[i].rank=2;
            else if(s[i].de>=s[i].cai) s[i].rank=3;
            else s[i].rank=4;
        }
    }

    sort(s, s+N, cmp);

    cout << total_num << endl;
    for (long i = 0; i < total_num; i++) {
        cout << s[i].id << " " << s[i].de << " " <<s[i].cai << endl;
    }

    return 0;
}
 
#endif 
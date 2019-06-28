#if 1
/*
 * 运行数据： ms  KB
 */
#include <bits/stdc++.h>
#include <map>

using namespace std;

#define ROCK 'C'
#define PAPER 'B'
#define SCISSOR 'J'

#define WIN 0
#define TIE 1
#define LOSE 2


int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int win[2][3] = {0};
    char A, B;
    // int cnt[2][3] = {0}; //  PAPER ROCK SCISSOR
    map<char, int> cnt[2];
    cnt[0].insert(make_pair('B', 0));
    cnt[0].insert(make_pair('C', 0));
    cnt[0].insert(make_pair('J', 0));
    cnt[1].insert(make_pair('B', 0));
    cnt[1].insert(make_pair('C', 0));
    cnt[1].insert(make_pair('J', 0));

    for (int i = 0; i < n; ++i) {
        cin >> A >> B;
        if (A == ROCK) {
            if (B == ROCK) {
                win[0][TIE] ++;
                win[1][TIE] ++;
            }
            else if (B == PAPER) {
                win[0][LOSE] ++;
                win[1][WIN] ++;
                cnt[1][PAPER] ++;
            }
            else {
                win[0][WIN] ++;
                win[1][LOSE] ++;
                cnt[0][ROCK] ++;
            }
        }
        else if (A == PAPER) {
            if (B == ROCK) {
                win[0][WIN] ++;
                win[1][LOSE] ++;
                cnt[0][PAPER] ++;
            }
            else if (B == PAPER) {
                win[0][TIE] ++;
                win[1][TIE] ++;
            }
            else {
                win[0][LOSE] ++;
                win[1][WIN] ++;
                cnt[1][SCISSOR] ++;
            }
        }
        else {
            if (B == ROCK) {
                win[0][LOSE] ++;
                win[1][WIN] ++;
                cnt[1][ROCK] ++;
            }
            else if (B == PAPER) {
                win[0][WIN] ++;
                win[1][LOSE] ++;
                cnt[0][SCISSOR] ++;
            }
            else {
                win[0][TIE] ++;
                win[1][TIE] ++;
            }
        }
    }

    cout << win[0][0] << " " << win[0][1] << " " << win[0][2] << endl;
    cout << win[1][0] << " " << win[1][1] << " " << win[1][2] << endl;

    // 找出甲，乙哪种手势赢的次数最多
    char A_most = 'B', B_most = 'B';
    int A_max = cnt[0]['B'], B_max = cnt[1]['B'];
    for(map<char, int>::iterator it = cnt[0].begin(); it != cnt[0].end(); ++it)
    {
        if(it->second > A_max)
        {
            A_max = it->second;
            A_most = it->first;
        }
        else if(it->second == A_max && it->first < A_most)
            A_most = it->first;
    }
    for(map<char, int>::iterator it = cnt[1].begin(); it != cnt[1].end(); ++it)
    {
        if(it->second > B_max)
        {
            B_max = it->second;
            B_most = it->first;
        }
        else if(it->second == B_max && it->first < B_most)
            B_most = it->first;
    }
    cout << A_most << " " << B_most <<endl;
    return 0;
}
#else
// 参考自：https://www.nowcoder.com/profile/6143247/codeBookDetail?submissionId=12796295 作者：平淡的人
#include <iostream>
#include <map>

using namespace std;

int main()
{
    int N;
    cin >> N;
    map<char, int> jia{{'B', 0}, {'C', 0}, {'J', 0}},
                   yi{{'B', 0}, {'C', 0}, {'J', 0}};    // 记录各个手势赢的次数
    int jia_ying = 0, yi_ying = 0;
    for(int i = 0; i < N; ++i)
    {
        char jia_shou, yi_shou;
        cin >> jia_shou >> yi_shou;
        if(jia_shou == 'B' && yi_shou == 'C')
        {
            ++jia_ying;
            ++jia[jia_shou];
        }
        else if(jia_shou == 'B' && yi_shou == 'J')
        {
            ++yi_ying;
            ++yi[yi_shou];
        }
        else if(jia_shou == 'C' && yi_shou == 'J')
        {
            ++jia_ying;
            ++jia[jia_shou];
        }
        else if(jia_shou == 'C' && yi_shou == 'B')
        {
            ++yi_ying;
            ++yi[yi_shou];
        }
        else if(jia_shou == 'J' && yi_shou == 'B')
        {
            ++jia_ying;
            ++jia[jia_shou];
        }
        else if(jia_shou == 'J' && yi_shou == 'C')
        {
            ++yi_ying;
            ++yi[yi_shou];
        }
    }
 
    // 找出甲，乙哪种手势赢的次数最多
    char jia_win_most = 'B', yi_win_most = 'B';
    int jia_max = jia['B'], yi_max = yi['B'];
    for(auto it = jia.begin(); it != jia.end(); ++it)
    {
        if(it->second > jia_max)
        {
            jia_max = it->second;
            jia_win_most = it->first;
        }
        else if(it->second == jia_max && it->first < jia_win_most)
            jia_win_most = it->first;
    }
    for(auto it = yi.begin(); it != yi.end(); ++it)
    {
        if(it->second > yi_max)
        {
            yi_max = it->second;
            yi_win_most = it->first;
        }
        else if(it->second == yi_max && it->first < yi_win_most)
            yi_win_most = it->first;
    }
 
    cout << jia_ying << " " << N - jia_ying - yi_ying << " "
         << yi_ying << '\n';
    cout << yi_ying << " " << N - jia_ying - yi_ying << " "
         << jia_ying << '\n';
    cout << jia_win_most << " " << yi_win_most;
 
    return 0;
}

#endif
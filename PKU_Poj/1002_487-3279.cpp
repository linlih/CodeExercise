#include <iostream>
#include <string>

using namespace std;

// 将A~Z定义为0~25
int mapMatrix[26] = {
//  A  B  C  D  E  F  G  H  I  J  K  L  M  N 
    2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 
//  O  P  Q  R  S  T  U  V  W  X  Y  Z
    6, 7,-1, 7, 7, 8, 8, 8, 9, 9, 9, -1
};

int main(int argc, char const *argv[])
{
    int cnt = 0;
    int res_cnt = 0;
    cin >> cnt;
    string *str = new string[cnt];
    for (int i = 0; i < cnt; i++) {
        cin >> str[i];
    }  
    
    for (int j = 0; j < str[i].length(); j ++) {
        if ((str[i] - 65) >=0 && (str[i] - 65) <= 25)
            
    }
    return 0;
}
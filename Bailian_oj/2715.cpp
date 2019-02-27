#include <iostream>
#include <string.h>

using namespace std;

int compute_scholar(int fs, int cs, char stu, char west, int paper) {
    int tmp = 0;
    if (fs > 80 && paper >= 1)
        tmp += 8000;
    if (fs > 85 && cs > 80)
        tmp += 4000;
    if (fs > 90)
        tmp += 2000;
    if (fs > 85 && west == 'Y') 
        tmp += 1000;
    if (cs > 80 && stu == 'Y')
        tmp += 850;
    return tmp;
}


int main(int argc, char const *argv[])
{
    char name[32] = {0};
    int fs;
    int cs;
    char stu;
    char west;
    int paper;
    int n;
    cin >> n;

    int sum = 0;
    int max = 0;

    int tmp;
    char tmp_name[32] = {0};
    for (int i = 0; i < n; ++i) {
        cin >> tmp_name >> fs >> cs >> stu >> west >> paper;
        tmp = compute_scholar(fs, cs, stu, west, paper);
        sum += tmp;
        if (tmp > max) {
            max = tmp;
            // 使用下面这种写法，提交得到WA
            //strncpy(name, tmp_name, strlen(tmp_name));
            strcpy(name, tmp_name);
        }
    }

    cout << name << endl;
    cout << max << endl;
    cout << sum << endl;
    return 0;
}
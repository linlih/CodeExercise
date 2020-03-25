/*
   问题描述：
   解题思路： 
   一个样例错误:原因是NA的输出是要对应性别的，比如：
   少了女性：
   NA
   xxx
   少了男性：
   xxx
   NA

 */
#include <bits/stdc++.h>

using namespace std;

struct stu {
    char id[12];
    char name[12];
    char gender;
    int grade;
};

bool cmp1(stu& s1, stu& s2) {
    return s1.grade < s2.grade; // 从小到大排序
}

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    stu *arr = new stu[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i].name >> arr[i].gender >> arr[i].id >> arr[i].grade;
    }
    sort(arr, arr + n, cmp1);
    // for (int i = 0; i < n; i++) {
    //     cout << arr[i].gender << " " <<arr[i].name << endl;
    // }
    bool male_flag = false, female_flag = false;
    int male_grade = 0, female_grade = 0;
    vector<string> print;
    for (int i = 0; i < n; i++) {
        if (arr[i].gender == 'M') {
            male_flag = true;
            male_grade = arr[i].grade;
            print.push_back(string(arr[i].name) + ' ' + string(arr[i].id));
            //cout << arr[i].name << " " << arr[i].id << endl;
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i].gender == 'F') {
            female_flag = true;
            female_grade = arr[i].grade;
            print.push_back(string(arr[i].name) + ' ' + string(arr[i].id));
            //cout << arr[i].name << " " << arr[i].id << endl;
            break;
        }
    }
    
    if (print.size() < 2 && !female_flag) {
        cout << "Absent" << endl;
        cout << print[0] << endl;
    }
    else if (print.size() < 2 && !male_flag) {
        cout << print[0] << endl;
        cout << "Absent" << endl;
    }
    else {
        for (int i = print.size() - 1; i >= 0; i--) 
            cout << print[i] << endl;
    }

    if (male_flag == true && female_flag == true) {
        cout << female_grade - male_grade << endl;
    }
    else {
        cout << "NA" << endl;
    }

    return 0;
}

/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;
int main(int argc, char const *argv[]) {
    int n;
    scanf("%d", &n);
    string female, male;
    int femalescore = -1, malescore = 101;
    for (int i = 0; i < n; i++) {
        string name, sex, num;
        int score;
        cin >> name >> sex >> num >> score;
        if (sex == "F") {
            if (femalescore < score) {
                femalescore = score;
                female = name + " " + num;
            }
            else if (malescore > score) {
                malescore = score;
                male = name + " " + num;
            }
        } 
    }
    if (femalescore != -1)
        cout << female << endl;
    else 
        printf("Absent\n");
    if (malescore != 101)
        cout << male << endl;
    else 
        printf("Absent\n");
    if (femalescore != -1 && malescore != 101)
        printf("%d", femalescore - malescore);
    else 
        printf("NA");
    return 0;
}



/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;

struct student {
    long long int no;
    int score, finalrank, local, localrank;
};

bool cmp(student a, student b) {
    return a.score != b.score ? a.score > b.score : a.no < b.no;
}

int main(int argc, char const *argv[]) {
    int n, m;
    scanf("%d", &n);
    vector<student> fin;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &m);
        vector<student> v(m);
        for (int j = 0; j < m; j++) {
            scanf("%lld %d", &v[j].no, &v[j].score);
            v[j].local = i;
        }
        sort(v.begin(), v.end(), cmp);
        v[0].localrank = 1;
        fin.push_back(v[0]);
        for (int j = 1; j < m; j++) {
            v[j].localrank = (v[j].score == v[j - 1].score) ? (v[j - 1].localrank) : (j + 1);
            fin.push_back(v[j]);
        }
    }
    sort(fin.begin(), fin.end(), cmp);
    fin[0].finalrank = 1;
    for (int j = 1; j < fin.size(); j++) {
        fin[j].finalrank = (fin[j].score == fin[j - 1].score) ? fin[j - 1].finalrank : j + 1;
    }
    printf("%d\n", fin.size());
    for (int i = 0; i < fin.size(); i++) {
        printf("%013lld %d %d %d\n", fin[i].no, fin[i].finalrank,fin[i].local, fin[i].localrank);
    }
    return 0;
}


/*
   问题描述：
   解题思路： 部分正确
 */
#include <bits/stdc++.h>

using namespace std;
struct stu {
    string reg_num;
    int local_id;
    int local_rank;
    int total_rank;
    int grade;
};

bool cmp(stu a, stu b) {
    return a.grade > b.grade;
}

int main(int argc, char const *argv[]) {
    int n;
    int k;
    vector<stu> grade;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> k;
        vector<stu> tmp_grade;
        for (int j = 0; j < k; j++) {
            stu temp;
            cin >> temp.reg_num >> temp.grade;
            temp.local_id = i;
            tmp_grade.push_back(temp);
        }
        sort(tmp_grade.begin(), tmp_grade.end(), cmp);
        tmp_grade[0].local_rank = 1;
        for (int j = 1; j < k; j++) {
            tmp_grade[j].local_rank = (tmp_grade[j].grade == tmp_grade[j - 1].grade) ? tmp_grade[j - 1].local_rank : j + 1;
        }
        grade.insert(grade.end(), tmp_grade.begin(), tmp_grade.end());
        tmp_grade.clear();
    }
    sort(grade.begin(), grade.end(), cmp);

    grade[0].total_rank = 1;
    for (int j = 1; j < grade.size() ; j++) {
        grade[j].total_rank = (grade[j].grade == grade[j - 1].grade) ? grade[j - 1].total_rank : j + 1;
    }
    cout << grade.size() << endl;
    for (int i = 0; i < grade.size() ; i++) {
        cout << grade[i].reg_num << " " << grade[i].total_rank << " " << grade[i].local_id << " " << grade[i].local_rank << endl;
    }
    return 0;
}
#include <iostream>
#include <string>

using namespace std;

// 将A~Z定义为0~25
char mapMatrix[26] = {
//  A  B  C  D  E  F  G  H  I  J  K  L  M  N 
    '2', '2', '2', '3', '3', '3', '4', '4', '4', '5', '5', '5', '6', '6', 
//  O  P  Q  R  S  T  U  V  W  X  Y  Z
    '6', '7', 'n', '7', '7', '8', '8', '8', '9', '9', '9', 'n'
};

typedef struct res{
    string* str;
    struct res* next;
    int res_cnt;
}res;

int main(int argc, char const *argv[])
{
    int cnt = 0;
    cin >> cnt;
    string *str = new string[cnt];
    res* head = new res;
    head->next = NULL;
    head->res_cnt = 0;
    res* temp_res = head;
    res* temp3;
    string temp("\0", 10);
    temp.clear();
    int mark = 0;
    int k = 0;
    for (int i = 0; i < cnt; i++)
        cin >> str[i];
    for (int i = 0; i < cnt; i++) {
        for (int j = 0; j < str[i].length(); j ++) {
            if ((str[i][j] != 'Q') && (str[i][j] >= 'A') && (str[i][j] <= 'Y')) {
                temp += mapMatrix[(str[i][j] - 'A')];
            }
            if (str[i][j] == 'Q' || str[i][j] == 'Z') {
                temp += '*';
            }
            if (str[i][j] >= '0' && str[i][j] <= '9') {
                temp += str[i][j];
            }
        }
        res* temp2 = head;
        while (temp_res->next != NULL) {
            temp_res = temp_res->next;
            int k = temp_res->str->compare(temp);
            if (k == 0) {
                temp_res->res_cnt++;
                mark = 1;
            }
            else if (k < 0){
                temp2 = temp2->next;
            }
        }
        if (mark == 0) {
            temp3 = temp2->next;
            temp2->next = new res;
            temp2 = temp2->next;
            temp2->next = temp3;
            temp2->res_cnt = 1;
            temp2->str = new string(temp);
            k++;
        }
        // if (mark == 0) {
        //     temp_res->next = new res;
        //     temp_res = temp_res->next;
        //     temp_res->next = NULL;
        //     temp_res->res_cnt = 1;
        //     temp_res->str = new string(temp);
        //     k++;
        // }
        temp.clear();
        mark = 0;
        temp_res = head;
    }

    // temp_res = head;
    // while (temp_res->next != NULL) {
    //     temp_res = temp_res->next;
    //     cout << *temp_res->str << " : " << temp_res->res_cnt << endl;
    // }

    // res  * p1, * prep1, * p2, * prep2, * temp1;
    // prep1 = head -> next;
    // p1 = prep1 -> next;
    // bool flag; //prep1和p1是否需要手动后移

    // while(p1 != NULL)
    // {   
    //     flag = true;
    //     temp1 = p1; 
    //     //由于是单向链表，所以只能从头部开始检索
    //     for(prep2 = head, p2 = prep2->next; p2 != p1; prep2 = prep2->next, p2 = p2->next)
    //     {   
    //         //发现第一个较大值
    //         if(p2->str->compare(*(p1->str)) > 0) 
    //         {   
    //             p1 = p1 -> next;
    //             prep1 -> next = p1; 
    //             prep2 -> next = temp1;
    //             temp1 -> next = p2; 
    //             flag = false;
    //             break;
    //         }   
    //     }   
    //     //手动后移prep1和p1
    //     if(flag)
    //     {   
    //         prep1 = prep1 -> next;
    //         p1 = p1 -> next;
    //     }   
    // }  

    temp_res = head;
    while (temp_res->next != NULL) {
        temp_res = temp_res->next;
        if (temp_res->res_cnt > 1) {
            for (int i = 0; i < temp_res->str->length(); i++) {
                if (i == 3)
                    cout << '-';
                cout << (*temp_res->str)[i];
            }
            cout << " " << temp_res->res_cnt << endl;
        }
        //cout << *temp_res->str << " : " << temp_res->res_cnt << endl;
    }

    return 0;
}

     
/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if (head == NULL) return NULL;
        int length = 0;
        ListNode* tmp = head;
        while (tmp != NULL) {
            length ++;
            tmp = tmp->next;
        }

        int middle = length/2;
        tmp = head;
        while (middle != 0) {
            middle --;
            tmp = tmp->next;
        }
        return tmp;
    }
};

class Solution_Another {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *stp1,*stp2;
        stp1 = stp2 = head;
        
        while(stp2 != NULL && stp2->next != NULL) // 利用另外一个指针都走一步的方式，这样只要一次循环就可以，效率更高
        {
            stp1 = stp1->next;
            stp2 = (stp2->next)->next;
        }
        return stp1;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    ListNode *head;
    ListNode *tmp;
    head = (ListNode *)new ListNode(1);
    tmp = head;
    tmp->next = (ListNode *)new ListNode(2);
    tmp = tmp->next;
    tmp->next = (ListNode *)new ListNode(3);
    tmp = tmp->next;
    tmp->next = (ListNode *)new ListNode(4);
    tmp = tmp->next;
    tmp->next = (ListNode *)new ListNode(5);
    tmp = tmp->next;
    tmp->next = (ListNode *)new ListNode(6);

    // tmp = head;
    // while (tmp != NULL) {
    //     cout << tmp->val << endl;
    //     tmp = tmp->next;
    // }

    cout << sol.middleNode(head)->val << endl;
    return 0;
}
/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;

// ref: https://www.cnblogs.com/qwfand/p/12797429.html
class node {//双向链表
public:
	int a;
	node *pre;
	node *next;
};

class FirstUnique {
public:
	vector<int> num;//存储数据的vector
	map<int, node *> unique;//存储元素在双向链表中的位置
	set<int> s;//存储元素去重
	node* head, *rear;//存储双向链表的头和尾

public:
	FirstUnique(vector<int>& nums) {
		head = rear = new  node();//初始化一个dummy head
		head->next = head->pre = NULL;

		for (int i = 0; i < nums.size(); i++) {
			add(nums[i]);
		}
	}

	int showFirstUnique() {
		if (head->next == NULL)
			return -1;
		else
			return head->next->a;
	}

	void add(int value) {
		num.push_back(value);
		if (s.find(value) == s.end()) {//value元素第一次出现
			struct node * tmp = new struct node;
			tmp->a = value;
			tmp->next = NULL;
			tmp->pre = rear;
			rear->next = tmp;
			rear = tmp;

			unique[value] = tmp;
			s.insert(value);
		}
		else {//value元素已经存在，把双向链表中的元素酸楚
			node * tmp = unique[value];
			if (tmp == rear) {
				rear = rear->pre;
				rear->next = NULL;
			}
			else if (tmp != NULL) {
				tmp->pre->next = tmp->next;
				tmp->next->pre = tmp->pre;
			}
			unique[value] = NULL;
			delete tmp;
		}
	}
};

class FirstUnique_Best {
private:
    queue<int> q;
    unordered_map<int, int> count;
public:
    FirstUnique(vector<int>& nums) {
        for(int num: nums){
            count[num]++;
            q.push(num);
        }
    }
    
    int showFirstUnique() {
        while(!q.empty() && count[q.front()] > 1){
            q.pop();
        }
        if(q.empty()) {
            return -1;
        }
        else {
            return q.front();
        }
    }
    
    void add(int value) {
        if(++count[value] == 1){
            q.push(value);
        }
    }
};

int main(int argc, char const *argv[]) {
    
    return 0;
}
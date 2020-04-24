/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;

// ref: https://blog.csdn.net/u013700358/article/details/85873397
class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity, cur = 0; //cur表示已存放的容量
    }
    
    int get(int key) {
        vector<int>::iterator it = find(v.begin(), v.end(), key); //在vector中找对应的key
        if(it == v.end()) return -1; 
        v.erase(it); 
        v.emplace_back(key); //每次get都将该key置顶
        return m[key];
    }
    
    void put(int key, int value) {
        if(m[key])  //如果原先key中就有值，则覆盖原值，同时置顶该key
        {
            m[key] = value;
            vector<int>::iterator it = find(v.begin(), v.end(), key);
            v.erase(it);
            v.emplace_back(key);
            return;
        }
                
        if(cur == cap)
        {
            int p = v.front();
            m[p] = 0;
            v.erase(v.begin());
            m[key] = value;
            v.emplace_back(key);
        }
        else
        {
            cur++;
            v.emplace_back(key);
            m[key] = value;
        }
    }
    int cap, cur;
    vector<int> v;
    map<int, int> m;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// 创建一个双向链表
class LRUNode{
public:
    int key;
    int value;
    LRUNode * prev;
    LRUNode * next;
};

class LRUCache_Best {

public:
    unordered_map<int,LRUNode*> m_map;
    LRUNode * m_root;
    int m_capacity;
    LRUCache(int capacity) {
        m_capacity = capacity;
        m_root = nullptr;
    }

    inline LRUNode * findNode(int key )
    {
        auto it = m_map.find(key);
        return (it != m_map.end())? it->second : nullptr;
    }

    inline void moveNodeToHead(LRUNode * node)
    {
        // if node is head exit (nothing to do)
        if ( node == m_root)
            return;

        // remove node from list. stitching up list
        // if there is a prev link then its an exiting node
        if ( node->prev ) {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }

        // connect node to head
        node->next = m_root;
        node->prev = m_root->prev;
        m_root->prev->next = node;
        m_root->prev = node;
        m_root = node;
    }

    int get(int key) {
        LRUNode * node = findNode(key);

        if (!node)
            return -1;
        moveNodeToHead(node);
        return m_root->value;
    }


    void put(int key, int value) {
        // find key
        LRUNode * node = findNode(key);

        // if key found move to front and change value
        if(node) {
            moveNodeToHead(node);
            node->value = value;
        } else {
            // check if at cap. if so use oldest node as
            // new node. remove from hash table
            // else create new node
            if( m_map.size() >= m_capacity)
            {
                m_map.erase(m_root->prev->key);

                node = m_root->prev;
                node->key = key;
                node->value = value;
            } else {
                node = new LRUNode;
                node->key = key;
                node->value = value;
                if ( !m_root ) {
                    m_root = node;
                    m_root->next = m_root;
                    m_root->prev = m_root;
                } else {
                    node->next = m_root;
                    node->prev = m_root->prev;
                    node->prev->next = node;
                    m_root->prev = node;
                }

           }
            // add to hash map and set nodes value
            m_map[key] = node;
            m_root = node;
        }
        return;
    }

};


class LRUCache_1 {
public:
    unordered_map<int,list<pair<int,int>>::iterator> mymap;
    list<pair<int,int>> v_l;
    int cap;
    LRUCache(int capacity) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        cap=capacity;
    }
    
    int get(int key) {
        if(mymap.find(key)==mymap.end()) return -1;
        v_l.splice(v_l.end(),v_l,mymap[key]);
        return (--v_l.end())->second;
    }
    
    void put(int key, int value) {
        if(mymap.find(key)!=mymap.end())
        {
           mymap[key]->second=value;
           v_l.splice(v_l.end(),v_l,mymap[key]);
        }
        else if(mymap.size()==cap)
        {
            mymap.erase(v_l.begin()->first);
            v_l.erase(v_l.begin());
            v_l.push_back(make_pair(key,value));
            mymap[key]=--v_l.end();
        }
        else
        {
             v_l.push_back(make_pair(key,value));
             mymap[key]=--v_l.end();
        }
       
        
    }
};
int main(int argc, char const *argv[]) {

    return 0;
}
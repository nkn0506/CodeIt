/*
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.

 

Example 1:

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]
*/

#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<fstream>
#include<iomanip>
#include<bits/stdc++.h>
using namespace std;
class LRUCache {
public:
    
    
    class node{
        public:
            long key;
            long value;
            node *prev;
            node *next;
            node(long x,long y)
            {
                key = x;
                value = y;
            }
    };
    
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    int cap;
    
    unordered_map<int,node*> m;
    
    LRUCache(int capacity) {
        cap = capacity;
        //join head and tail;
        
        head->next = tail;
        tail->prev = head;
        
    }
    
    void addnode(node* newnode)
    {
        node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;

    }
    void deletenode(node* delnode){
        node* delprev = delnode->prev;
        node* delnext = delnode->next;
        
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    
    int get(int key_) {
        
        if(m.find(key_)!=m.end()){
            node* temp = m[key_];
            int ans = temp->value;
            m.erase(key_);
            deletenode(temp);
            addnode(temp);
            m[key_]=head->next;
            return ans;
            
        }
        return -1;
        
    }
    
    void put(int key_, int value_) {
        //if key already exist then delete that node delete from map also
        if(m.find(key_)!=m.end())
        {
            node* temp = m[key_];
            m.erase(key_);
            deletenode(temp);
        }
        if(m.size()==cap)
        {
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key_,value_));
        m[key_] = head->next;
        
    }
};



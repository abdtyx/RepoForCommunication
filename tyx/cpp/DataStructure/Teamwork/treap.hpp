#ifndef _TREAP_H
#define _TREAP_H

#include<bits/stdc++.h>
using namespace std;

#ifndef _COURSE_HPP
#include "Course.hpp"
#endif

#ifndef _STUDENT_HPP
#include "Student.hpp"
#endif

/**
 * @brief one fhq-treap that orderly stores items whose type is T
 * 
 * @tparam T
 */
template<class T>
class treap {
  private:
    int root=0;
    bool (*cmp)(T x,T y);
    vector<T> val;
    vector<int> rnd;
    vector<int> lson;
    vector<int> rson;
    vector<int> sz;
    void pushup(int t0);
    void split(int t0,T k,int &x,int &y);
    int merge(int x,int y);
    int newnode(T x);
    void print(int t0);
  public:
    treap() {}
    treap(bool (*func)(T x,T y));
    void insert(T z);
    void output();
};

/**
 * @brief Construct a new treap object with the given comparison
 * 
 * @param func the pointer to the compare function of two Ts
 */
template<class T>
treap<T>::treap(bool (*func)(T x,T y)) {
    cmp=func;
    T x0;
    val.push_back(x0);
    rnd.push_back(0);
    lson.push_back(0);
    rson.push_back(0);
    sz.push_back(0);
    return ;
}

/**
 * @brief maintain the size of the subtree of t0
 * 
 * @tparam T 
 * @param t0 root of subtree
 */
template<class T>
void treap<T>::pushup(int t0) {
    if(!t0) return ;
    sz[t0]=sz[lson[t0]]+sz[rson[t0]]+1;
	return ;
}

/**
 * @brief split of fhq-treap
 * 
 * @tparam T 
 * @param t0 root of subtree
 * @param k the T to be inserted
 * @param x root of one splited treap
 * @param y root of the other splited treap
 */
template<class T>
void treap<T>::split(int t0, T k,int &x,int &y) {
	if(!t0) x=y=0;
	else if(cmp(val[t0],k)) x=t0,split(rson[t0],k,rson[t0],y);
	else y=t0,split(lson[t0],k,x,lson[t0]);
	pushup(t0);
	return ;
}

/**
 * @brief merge two treaps
 * S
 * @tparam T 
 * @param x root of one treap to be merged
 * @param y root of the other treap to be merged
 * @return int root of the merged treap
 */
template<class T>
int treap<T>::merge(int x,int y) {
	if(!x||!y) return x+y;
	if(rnd[x]<rnd[y]) {rson[x]=merge(rson[x],y),pushup(x);return x;}
	else {lson[y]=merge(x,lson[y]),pushup(y);return y;}
}

/**
 * @brief add a new node to the treap
 * 
 * @tparam T 
 * @param x the T to be inserted
 * @return int the number of the new node
 */
template<class T>
int treap<T>::newnode(T x) {
	val.push_back(x);
	rnd.push_back(rand());
    lson.push_back(0);
    rson.push_back(0);
    sz.push_back(0);
	pushup(val.size()-1);
	return val.size()-1;
}

/**
 * @brief insert z to the treap by spliting and merging
 * 
 * @tparam T 
 * @param z to be inserted
 */
template<class T>
void treap<T>::insert(T z) {
    int x,y;
    split(root,z,x,y);
    root=merge(merge(x,newnode(z)),y);
    return ;
}

/**
 * @brief print the treap
 * 
 * @tparam T 
 * @param t0 root of the subtree
 */
template<class T>
void treap<T>::print(int t0) {
    if(!t0) return ;
    print(lson[t0]);
    cout<<val[t0].first;
    print(rson[t0]);
    return ;
}

/**
 * @brief output all Ts in order
 * 
 * @tparam T 
 */
template<class T>
void treap<T>::output() {
    print(root);
    return ;
}

#endif
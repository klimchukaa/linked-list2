#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

template<typename T>
class node{
public:
    T x;
    node* next;
    node* prev;
    //Constructors
    node(const T &x) : x(x) {
        next = nullptr;
    }
};


template<typename T>
class linked_list{
public:
    node<T>* head = nullptr;
    node<T>* tail = nullptr;
    node<T>* cur = nullptr;
    int s = 0;
    //Checkers
    bool empty();
    //Add
    void push_front(T x);
    void push_back(T x);
    void push_in(T x);
    //Delete
    void pop_front();
    void pop_back();
    void pop_in();
    //Operators
    template<typename Type> friend ostream& operator<<(ostream&, const linked_list<Type>&);
    //Shift
    void shift_left();
    void shift_right();
    //For game
    bool check();
    void shift_begin();
    int erase_same(T x);
};

template<typename T>
bool linked_list<T>::empty() {
    return (s == 0);
}

template<typename T>
void linked_list<T>::push_front(T x) {
    node<T>* vertex = new node<T>(x);
    s++;
    if (s == 1) {
        head = vertex;
        tail = vertex;
        cur = vertex;
        return;
    }
    head->prev = vertex;
    vertex->next = head;
    head = vertex;
}

template<typename T>
void linked_list<T>::push_back(T x) {
    node<T>* vertex = new node<T>(x);
    s++;
    if (s == 1) {
        head = vertex;
        tail = vertex;
        cur = vertex;
        return;
    }
    vertex->prev = tail;
    tail->next = vertex;
    tail = vertex;
}

template<typename T>
void linked_list<T>::push_in(T x) {
    if (cur == head || s == 0) {
        push_front(x);
        return;
    }
    node<T>* vertex = new node<T>(x);
    s++;
    vertex->prev = cur->prev;
    vertex->next = cur;
    cur->prev->next = vertex;
    cur->prev = vertex;
    cur = vertex;
}

template<typename T>
void linked_list<T>::pop_front() {
    if (s == 0) {
        throw::invalid_argument("The list is empty");
    }
    s--;
    if (s == 0) {
        cur = nullptr;
        head = nullptr;
        tail = nullptr;
        return;
    } else if (head == cur) {
        cur = head->next;
    }
    head = head->next;
    head->prev = nullptr;
}

template<typename T>
void linked_list<T>::pop_back() {
    if (s == 0) {
        throw::invalid_argument("The list is empty");
    }
    s--;
    if (s == 0) {
        head = nullptr;
        tail = nullptr;
        cur = nullptr;
        return;
    } else if (tail == cur) {
        cur = tail->prev;
    }
    tail = tail->prev;
    tail->next = nullptr;
}

template<typename T>
void linked_list<T>::pop_in() {
    if (cur == nullptr) {
        throw::invalid_argument("The list is empty");
    }
    if (cur == head) {
        pop_front();
        return;
    }
    if (cur == tail) {
        pop_back();
        return;
    }
    s--;
    cur->prev->next = cur->next;
    cur->next->prev = cur->prev;
    cur = cur->next;
}

template<typename T>
void linked_list<T>::shift_left() {
    if (head == cur) return;
    cur = cur->prev;
}

template<typename T>
void linked_list<T>::shift_right() {
    if (tail == cur) return;
    cur = cur->next;
}

template<typename T>
bool linked_list<T>::check() {
    if (cur != head) {
        if (cur->prev->prev != nullptr) {
            if (cur->x == cur->prev->x && cur->x == cur->prev->prev->x) {
                return 1;
            }
        }
    }
    if (cur != tail) {
        if (cur->next->next != nullptr) {
            if (cur->x == cur->next->x && cur->x == cur->next->next->x) {
                return 1;
            }
        }
    }
    if (cur != tail && cur != head) {
        if (cur->x == cur->next->x && cur->x == cur->prev->x) {
            return 1;
        }
    }
    return 0;
}

template<typename T>
void linked_list<T>::shift_begin() {
    while (cur != head && cur->prev->x == cur->x) {
        shift_left();
    }
}

template<typename T>
int linked_list<T>::erase_same(T x) {
    int del = 0;
    while (s > 0 && cur->x == x) {
        pop_in();
        del++;
    }
    return del;
}


template<typename Type>
ostream &operator<<(ostream &out, const linked_list<Type> &a) {
    node<Type>* now = a.head;
    while (now != nullptr) {
        cout << now->x << ' ';
        now = now->next;
    }
    cout << "\n";
    return out;
}

#endif // LINKED_LIST_H_INCLUDED

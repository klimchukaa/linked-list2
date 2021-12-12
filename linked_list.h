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
    int s = 0;
    //Checkers
    bool empty();
    //Get
    node<T>* get_node(int ind);
    //Add
    void push_front(T x);
    void push_back(T x);
    void push_in(T x, int ind);
    //Find
    int find_index(T x);
    //Delete
    void pop_front();
    void pop_back();
    void pop_in(int ind);
    void pop_value(T x);
    //Operators
    template<typename Type> friend ostream& operator<<(ostream&, const linked_list<Type>&);
    const T operator[](int ind);

};

template<typename T>
bool linked_list<T>::empty() {
    return (s == 0);
}

template<typename T>
node<T>* linked_list<T>::get_node(int ind) {
    if (ind < 1) {
        throw::invalid_argument("Invalid index");
    }
    node<T>* now = head;
    while (ind > 1) {
        if (now == nullptr) {
            throw::invalid_argument("List has a few elements");
        }
        now = now->next;
        ind--;
    }
    if (now == nullptr) {
        throw::invalid_argument("List has a few elements");
    }
    return now;
}

template<typename T>
void linked_list<T>::push_front(T x) {
    node<T>* vertex = new node<T>(x);
    s++;
    if (s == 1) {
        head = vertex;
        tail = vertex;
        return;
    }
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
        return;
    }
    tail->next = vertex;
    tail = vertex;
}

template<typename T>
void linked_list<T>::push_in(T x, int ind) {
    if (ind == 1) {
        push_front(x);
        return;
    }
    if (ind == s + 1) {
        push_back(x);
        return;
    }
    node<T>* now = get_node(ind - 1);
    node<T>* vertex = new node<T>(x);
    s++;
    vertex->next = now->next;
    now->next = vertex;
}

template<typename T>
int linked_list<T>::find_index(T x) {
    node<T>* now = head;
    int res = 1;
    while (now != nullptr) {
        if (now->x == x) {
            break;
        }
        now = now->next;
        res++;
    }
    if (now == nullptr) {
        throw::invalid_argument("There is not this element in the list");
    }
    return res;
}

template<typename T>
void linked_list<T>::pop_front() {
    if (s == 0) {
        throw::invalid_argument("The list is empty");
    }
    s--;
    head = head->next;
    if (head == nullptr) {
        tail = nullptr;
    }
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
        return;
    }
    node<T>* now = head;
    while (now->next != tail) {
        now = now->next;
    }
    tail = now;
    tail->next = nullptr;
}

template<typename T>
void linked_list<T>::pop_in(int ind) {
    if (ind < 1) {
        throw::invalid_argument("Invalid index");
    }
    if (ind > s) {
        throw::invalid_argument("The list is too small");
    }
    if (ind == 1) {
        pop_front();
        return;
    }
    if (ind == s) {
        pop_back();
        return;
    }
    node<T>* now = get_node(ind - 1);
    s--;
    now->next = now->next->next;
}

template<typename T>
void linked_list<T>::pop_value(T x) {
    int ind = find_index(x);
    pop_in(ind);
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

template<typename T>
const T linked_list<T>::operator[](int ind) {
    if (ind < 1) {
        throw::invalid_argument("Invalid index");
    }
    node<T>* now = head;
    while (ind > 1) {
        if (now == nullptr) {
            throw::invalid_argument("List has a few elements");
        }
        now = now->next;
        ind--;
    }
    if (now == nullptr) {
        throw::invalid_argument("List has a few elements");
    }
    return now->x;
}

#endif // LINKED_LIST_H_INCLUDED

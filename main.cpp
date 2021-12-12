#include <bits/stdc++.h>
#include "linked_list.h"

using namespace std;

signed main() {
    linked_list <int> a;
    string command;
    while (cin >> command) {
        if (command == "empty") {
            if (a.empty()) {
                cout << "yes\n";
            } else {
                cout << "no\n";
            }
        } else if (command == "add_end") {
            int x; cin >> x;
            a.push_back(x);
            cout << a;
        } else if (command == "add_begin") {
            int x; cin >> x;
            a.push_front(x);
            cout << a;
        } else if (command == "add_in") {
            int x, ind; cin >> x >> ind;
            try {
                a.push_in(x, ind);
                cout << a;
            } catch (const invalid_argument& e) {
                cout << e.what() << "\n";
            }
        } else if (command == "del_end") {
            try {
                a.pop_back();
                cout << a;
            } catch (const invalid_argument& e) {
                cout << e.what() << "\n";
            }
        } else if (command == "del_begin") {
            try {
                a.pop_front();
                cout << a;
            } catch (const invalid_argument& e) {
                cout << e.what() << "\n";
            }
        } else if (command == "del_in") {
            int ind; cin >> ind;
            try {
                a.pop_in(ind);
                cout << a;
            } catch (const invalid_argument& e) {
                cout << e.what() << "\n";
            }
        } else if (command == "del_value") {
            int x; cin >> x;
            try {
                a.pop_value(x);
                cout << a;
            } catch (const invalid_argument& e) {
                cout << e.what() << "\n";
            }
        } else if (command == "get") {
            int ind; cin >> ind;
            try {
                cout << a[ind] << "\n";
            } catch (const invalid_argument& e) {
                cout << e.what() << "\n";
            }
        } else if (command == "find") {
            int x; cin >> x;
            try {
                cout << a.find_index(x) << "\n";
            } catch (const invalid_argument& e) {
                cout << e.what() << "\n";
            }
        } else if (command == "print") {
            cout << a;
        } else {
            return 0;
        }
    }
}

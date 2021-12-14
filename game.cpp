#include <bits/stdc++.h>
#include "linked_list.h"

using namespace std;

signed main() {
    cout << "Pick the length: ";
    int n; cin >> n;
    cout << "Pick the number of the colors: ";
    int c; cin >> c;
    linked_list <int> f;
    for (int i = 0; i < n; ++i) {
        int x = rand() % c + 1;
        f.push_back(x);
    }
    cout << "Your game field: \n";
    cout << f;
    int score = 0, st = 0;
    while (!f.empty()) {
        int x = rand() % c + 1;
        cout << "Your new color: " << x << "\nShift cursor: ";
        int d; cin >> d;
        if (abs(d) > 5) {
            cout << "Your shift is too big!\n";
        } else {
            if (d > 0) {
                for (int i = 0; i < d; ++i) {
                    f.shift_right();
                }
            } else {
                for (int i = 0; i < abs(d); ++i) {
                    f.shift_left();
                }
            }
            f.push_in(x);
            while (f.check()) {
                f.shift_begin();
                score += f.erase_same(f.cur->x);
            }
            if (st == 10) {
                st = 0;
                cout << "Your score " << score << "\n";
                cout << "The field:\n" << f;
            }
            st++;
        }
    }
    cout << "Congratulations! You won!\nYour score is " << score << "\n";
    return 0;
}

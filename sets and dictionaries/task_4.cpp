//
// Created by Marat on 30.09.25.
//

#include <iostream>
#include <vector>
#include <unordered_set>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }

    bool repeat = false;
    std::unordered_set<int> s;
    for (int i = 0; i < n; ++i) {
        if (s.contains(v[i])) {
            repeat = true;
            break;
        }
        s.insert(v[i]);
        if (s.size() >= k) {
            s.erase(v[i - k]);
        }
    }

    std::cout << (repeat ? "YES" : "NO");
}
//
// Created by Marat on 30.09.25.
//

#include <iostream>
#include <set>
#include <unordered_map>
#include <unordered_set>

int main() {

    std::unordered_map<int, int> freq;
    for (int i = 0; i < 3; ++i) {
        int n;
        std::cin >> n;

        std::unordered_set<int> curr;
        for (int j = 0; j < n; ++j) {
            int x;
            std::cin >> x;
            curr.insert(x);
        }

        for (auto s : curr) {
            ++freq[s];
        }
    }

    std::set<int> output;
    for (auto &[x, cnt] : freq) {
        if (cnt >= 2) {
            output.insert(x);
        }
    }

    for (auto i : output) {
        std::cout << i << ' ';
    }
}
//
// Created by Marat on 30.09.25.
//

#include <iostream>
#include <set>

int main() {
    int n;
    std::cin >> n;

    int k;
    std::cin >> k;
    std::set<std::string> common;
    for (int i = 0; i < k; ++i) {
        std::string song;
        std::cin >> song;
        common.insert(song);
    }

    for (int i = 1; i < n; ++i) {
        std::cin >> k;
        std::set<std::string> curr;
        for (int j = 0; j < k; ++j) {
            std::string song;
            std::cin >> song;
            curr.insert(song);
        }

        for (auto it = common.begin(); it != common.end();) {
            if (curr.contains(*it)) {
                ++it;
            } else {
                it = common.erase(it);
            }
        }

        if (common.empty()) break;
    }

    std::cout << common.size() << '\n';
    for (const auto& i : common) {
        std::cout << i << ' ';
    }
}
//
// Created by Marat on 30.09.25.
//

#include <iostream>
#include <map>

int main() {
    std::string first, second;
    std::cin >> first >> second;

    if (first.size() != second.size()) {
        std::cout << "NO";
        return 0;
    }

    std::map<char, int> m1, m2;
    for (int i = 0; i < first.size(); ++i) {
        ++m1[first[i]];
        ++m2[second[i]];
    }

    if (m1.size() != m2.size()) {
        std::cout << "NO";
        return 0;
    }

    for (auto [ch, cnt] : m1) {
        if (m2[ch] != cnt) {
            std::cout << "NO";
            return 0;
        }
    }

    std::cout << "YES";
}
//
// Created by Marat on 30.09.25.
//

#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> freq(100001 + 1, 0);
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        ++freq[x];
    }

    int countDelete = 0;
    for (int i = 0; i <= 100000; ++i) {
        countDelete = std::max(countDelete, freq[i] + freq[i + 1]);
    }

    std::cout << n - countDelete;
}
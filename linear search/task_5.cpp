//
// Created by Marat on 29.09.25.
//

#include <iostream>
#include <vector>
#include <algorithm>

struct Berry {
    long long a, b;
    int index;
};

int main() {
    int n;
    std::cin >> n;

    std::vector<Berry> berries(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> berries[i].a >> berries[i].b;
        berries[i].index = i + 1;
    }

    std::sort(berries.begin(), berries.end(), [](const Berry& x, const Berry& y) {
        return std::min(x.a, y.b) > std::min(y.a, x.b);
    });

    long long maxHeight = 0;
    long long currentHeight = 0;
    for (int i = 0; i < n; ++i) {
        currentHeight += berries[i].a;
        maxHeight = std::max(maxHeight, currentHeight);
        currentHeight -= berries[i].b;
    }

    std::cout << maxHeight << '\n';
    for (auto& i : berries) {
        std::cout << i.index << ' ';
    }
}
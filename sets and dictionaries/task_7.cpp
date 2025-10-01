//
// Created by Marat on 30.09.25.
//

#include <iostream>
#include <vector>
#include <set>

int main() {
    int n;
    std::cin >> n;

    std::set<std::pair<int, int>> s;
    std::vector<std::pair<int, int>> original(n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        std::cin >> x >> y;
        s.insert({x, y});
        original[i] = {x, y};
    }

    int minAdd = 4;
    std::vector<std::pair<int, int>> bestAdd;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int x0 = original[i].first, y0 = original[i].second;
            int x1 = original[j].first, y1 = original[j].second;

            int dx = x1 - x0;
            int dy = y1 - y0;

            std::vector<std::vector<std::pair<int, int>>> squares = {
                {{x0, y0}, {x1, y1}, {x1 - dy, y1 + dx}, {x0 - dy, y0 + dx}},
                {{x0, y0}, {x1, y1}, {x1 + dy, y1 - dx}, {x0 + dy, y0 - dx}}
            };

            for (auto& sq : squares) {
                std::vector<std::pair<int, int>> add;
                for (auto& p : sq) {
                    if (!s.contains(p)) {
                        add.push_back(p);
                    }
                }
                if (add.size() < minAdd) {
                    minAdd = add.size();
                    bestAdd = add;
                }
            }
        }
    }

    if (minAdd == 4) {
        int x0 = original[0].first, y0 = original[0].second;
        bestAdd = {{x0 + 1,y0},{x0,y0 + 1},{x0 + 1,y0 + 1}};
        minAdd = 3;
    }

    std::cout << minAdd << '\n';
    for (auto& p : bestAdd) {
        std::cout << p.first << ' ' << p.second << '\n';
    }
}
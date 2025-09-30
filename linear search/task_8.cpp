//
// Created by Marat on 29.09.25.
//

#include <iostream>
#include <vector>
#include <tuple>

auto findMax(std::vector<std::vector<int>>& v, int bannedRow, int bannedCol) -> std::tuple<int, int, int> {
    int ans = 0;
    int row = 0, col = 0;

    for (int i = 0; i < v.size(); ++i) {
        if (i != bannedRow) {
            for (int j = 0; j < v[i].size(); ++j) {
                if (j != bannedCol && v[i][j] > ans) {
                    ans = v[i][j];
                    row = i;
                    col = j;
                }
            }
        }
    }

    return {row, col, ans};
}

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> v(n + 1, std::vector<int>(m + 1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> v[i][j];
        }
    }

    auto [globalRow, globalCol, maxVal] = findMax(v, -1, -1);
    auto [banRow, banCol, tempVal] = findMax(v, globalRow, -1);
    auto [tempRow, tempCol, banRowVal] = findMax(v, globalRow, banCol);
    auto [banColRow, banCikCol, tempValS] = findMax(v, -1, globalCol);
    auto [tempR, tempC, banColVal] = findMax(v, banColRow, globalCol);

    if (banRowVal < banColVal) {
        std::cout << globalRow + 1 << ' ' << banCol + 1;
    } else {
        std::cout << banColRow + 1 << ' ' << globalCol + 1;
    }
}
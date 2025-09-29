//
// Created by Marat on 29.09.25.
//

#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i].first >> v[i].second;
    }

    std::vector<std::vector<bool>> board(10, std::vector<bool>(10, false));
    for (size_t i = 0; i < v.size(); ++i) {
        board[v[i].first][v[i].second] = true;
    }

    int perimeter = 0;
    for (int i = 1; i <= 8; ++i) {
        for (int j = 1; j <= 8; ++j) {
            if (board[i][j] && !board[i][j - 1]) ++perimeter;
            if (board[i][j] && !board[i][j + 1]) ++perimeter;
            if (board[i][j] && !board[i - 1][j]) ++perimeter;
            if (board[i][j] && !board[i + 1][j]) ++perimeter;
        }
    }

    std::cout << perimeter;
}
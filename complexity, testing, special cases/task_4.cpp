//
// Created by Marat on 25.09.25.
//

#include <iostream>
#include <vector>
#include <string>

struct Figure {
    char type;
    int x;
    int y;
};

int main() {
    std::vector<std::string> board(8);
    std::vector<Figure> figures;
    for (int i = 0; i < 8; ++i) {
        std::cin >> board[i];
    }

    for (int i = 0; i < board.size(); ++i) {
        for (int c = 0; c < board[i].size(); ++c) {
            if (board[i][c] == 'R' || board[i][c] == 'B') {
                figures.push_back({board[i][c], i, c});
            }
        }
    }

    int bishopDirs[4][2] = {
        {-1, -1}, {-1, +1}, {+1, +1}, {+1, -1}
    };

    int rookDirs[4][2] = {
        {-1, 0}, {0, -1}, {0, +1}, {+1, 0}
    };

    std::vector<std::vector<bool>> attacked(8, std::vector<bool>(8, false));

    for (auto& [fig, x, y] : figures) {
        int xL = -1, yL = -1;
        if (fig == 'B') {
            for (int d = 0; d < 4; ++d) {
                int xS = x, yS = y;
                while (true) {
                    xS += bishopDirs[d][0];
                    yS += bishopDirs[d][1];
                    if (xS >= 8 || xS < 0 || yS >= 8 || yS < 0) break;
                    if (board[xS][yS] != '*') break;
                    attacked[xS][yS] = true;
                }
            }
        } else if (fig == 'R') {
            for (int d = 0; d < 4; ++d) {
                int xL = x, yL = y;
                while (true) {
                    xL += rookDirs[d][0];
                    yL += rookDirs[d][1];
                    if (xL >= 8 || xL < 0 || yL >= 8 || yL < 0) break;
                    if (board[xL][yL] != '*') break;
                    attacked[xL][yL] = true;
                }
            }
        }
    }

    int result = 0;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (board[i][j] == '*' && !attacked[i][j]) {
                result++;
            }
        }
    }
    std::cout << result;
}
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int solve() {
    std::ifstream file{"input.txt"};
    std::string s;
    std::vector<std::string> a;

    while (std::getline(file, s)) {
        a.push_back(s);
    }

    const int nRows = a.size();
    const int nCols = a[0].size();

    int result{};

    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            if (a[i][j] == '@') {
                int curr = 0;
                for (int di = -1; di <= 1; di++) {
                    for (int dj = -1; dj <= 1; dj++) {
                        if (di * di + dj * dj > 0) {
                            const int ni = i + di, nj = j + dj;
                            if (ni < 0 || ni >= nRows) continue;
                            if (nj < 0 || nj >= nCols) continue;
                            curr += (a[ni][nj] == '@');
                        }
                    }
                }
                result += (curr < 4);
            }
        }
    }
    return result;
}



int main() {
    std::cout << solve();

    return 0;
}
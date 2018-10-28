#include <bits/stdc++.h>


template <class Class>
void Print(Class instance) {
    std::cout << instance << std::endl;
}

void Print() {
    std::cout << std::endl;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    #ifdef LOCAL
        std::ifstream input("input.txt");
        std::ofstream output("output.txt");
    #else
        auto& input = std::cin;
        auto& output = std::cout;
    #endif
    size_t n;
    size_t m;
    input >> n >> m;
    std::vector<std::vector<uint64_t>> perm(m, std::vector<uint64_t>(n));
    std::vector<std::unordered_map<uint64_t, size_t>> maps(m);
    for (size_t index = 0; index < m; ++index) {
        for (size_t second = 0; second < n; ++second) {
            input >> perm[index][second];
            maps[index][perm[index][second]] = second;
        }
    }
    uint64_t first = 0;
    uint64_t result = 0;
    while (first < n) {
        uint64_t diff = 0;
        bool flag = true;
        uint64_t el = perm[0][first];
        while (flag) {
            ++diff;
            for (size_t index = 0; index < m; ++index) {
                if (maps[index][el] + diff >= n 
                        || perm[index][maps[index][el] + diff] != perm[0][maps[0][el] + diff])
                {
                    flag = false;
                    break;
                }
            }
            if (!flag) {
                break;
            }
        }
        result += diff * (diff + 1) / 2;
        first += diff;
    }
    output << result;
    return 0;
}

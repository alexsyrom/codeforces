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

    size_t n, m;
    input >> n >> m;
    std::vector<int32_t> vert(n);
    for (size_t index = 0; index < n; ++index) {
        input >> vert[index];
    }
    vert.push_back(1000 * 1000 * 1000);
    std::sort(vert.begin(), vert.end());
    std::vector<int32_t> hor;
    for (size_t index = 0; index < m; ++index) {
        int32_t x1, x2, y;
        input >> x1 >> x2 >> y;
        if (x1 != 1) {
            continue;
        }
        hor.push_back(x2);
    }
    std::sort(hor.begin(), hor.end());
    size_t answer = 1000 * 1000;
    size_t hor_index = 0;
    for (size_t index = 0; index < vert.size(); ++index) {
        while (hor_index < hor.size() && hor[hor_index] < vert[index]) {
            ++hor_index;
        }
        answer = std::min(answer, index + hor.size() - hor_index);
    }
    output << answer;

    return 0;
}

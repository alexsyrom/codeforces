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
    size_t x;
    input >> x;
    size_t a = 0;
    size_t b = 0;
    for (size_t first = 1; first <= x; ++first) {
        for (size_t second = 1; second <= first; ++second) {
            if (first % second == 0) {
                if (first / second < x && first * second > x) {
                    a = first;
                    b = second;
                    output << a << ' ' << b;
                    return 0;
                }
            }
        }
    }
    output << -1;

    return 0;
}

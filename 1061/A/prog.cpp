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
    size_t n, s;
    input >> n >> s;
    size_t answer = 0;
    size_t res = s;
    while (res > 0) {
        answer += res / n;
        res %= n;
        --n;
    }
    output << answer;

    return 0;
}

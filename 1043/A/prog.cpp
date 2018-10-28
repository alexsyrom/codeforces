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
    input >> n;
    std::vector<size_t> a(n);
    size_t sum = 0;
    size_t max = 0;
    for (size_t index = 0; index < n; ++index) {
        input >> a[index];
        sum += a[index];
        max = std::max(max, a[index]);
    }
    size_t result = std::max(max, 2 * sum / n + 1);
    output << result;
    return 0;
}

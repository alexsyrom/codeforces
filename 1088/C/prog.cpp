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
    std::vector<uint64_t> a(n + 1);
    for (size_t index = 1; index <= n; ++index) {
        input >> a[index];
    }
    uint64_t cur = 0;
    output << n + 1 << std::endl;
    for (size_t index = n; index > 0; --index) {
        a[index] = a[index] + cur;
        uint64_t r = a[index] % n;
        uint64_t add = index - 1 + n - r;
        output << "1 " << index << " " << add << std::endl;
        cur += add;
    }
    output << "2 " << n << " " << n;

    return 0;
}

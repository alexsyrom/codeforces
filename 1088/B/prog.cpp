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
    size_t n, k;
    input >> n >> k;
    std::set<int32_t> numbers; 
    for (size_t index = 0; index < n; ++index) {
        int32_t number;
        input >> number;
        numbers.insert(number);
    }
    int32_t cur = 0;
    for (size_t index = 0; index < k; ++index) {
        auto min_it = numbers.begin();
        if (min_it == numbers.end()) {
            output << 0 << std::endl;
        } else {
            output << *min_it - cur << std::endl;
            cur = *min_it;
            numbers.erase(min_it);
        }
    }

    return 0;
}

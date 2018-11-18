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
    std::vector<size_t> number_of_type(101);
    for (size_t index = 0; index < n; ++index) {
        size_t t;
        input >> t;
        number_of_type[t] += 1;
    }
    size_t times = 0;
    for (size_t index = 1; index < 101; ++index) {
        times = std::max(times, number_of_type[index] / k + (number_of_type[index] % k == 0 ? 0 : 1));
    }
    size_t answer = 0;
    for (size_t index = 1; index < 101; ++index) {
        if (number_of_type[index] > 0) {
            answer += times * k - number_of_type[index];
        }
    }
    output << answer;

    return 0;
}

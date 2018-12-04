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

    const uint64_t modulo = 1000 * 1000 * 1000 + 7;

    size_t n;
    input >> n;
    std::vector<size_t> a(n);
    for (size_t index = 0; index < n; ++index) {
        input >> a[index];
    }
    std::vector<uint64_t> answers(1000 * 1000 + 1);
    answers[0] = 1;
    
    for (size_t index = 0; index < n; ++index) {
        std::vector<size_t> delimiters;
        for (size_t sq = 1; sq <= std::sqrt(a[index]); ++sq) {
            if (a[index] % sq == 0) {
                delimiters.push_back(sq);
                if (sq * sq != a[index]) {
                    delimiters.push_back(a[index] / sq);
                }
            }
        }
        std::sort(delimiters.rbegin(), delimiters.rend());
        for (auto delimiter : delimiters) {
            answers[delimiter] = (answers[delimiter] + answers[delimiter - 1]) % modulo;
        }
    }

    uint64_t answer = 0;
    for (size_t index = 1; index <= n; ++index) {
        answer = (answer + answers[index]) % modulo;
    }
    output << answer;

    return 0;
}

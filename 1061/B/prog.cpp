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
    if (n == 1) {
        output << 0;
        return 0;
    }
    std::vector<size_t> a(n);
    for (size_t index = 0; index < n; ++index) {
        input >> a[index];
    }
    std::sort(a.rbegin(), a.rend());
    uint64_t answer = 0;
    for (size_t index = 1; index < n; ++index) {
        if (a[index - 1] < a[index]) {
            answer += a[index] - a[index - 1];
            a[index] = a[index - 1];
        }
        if (a[index - 1] <= 1) {
            continue;
        }
        if (a[index - 1] == a[index]) {
            answer++;
            a[index]--;
        }
        answer += a[index];
    }
    output << answer;

    return 0;
}

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
    size_t n, m, l;
    input >> n >> m >> l;
    std::vector<uint64_t> a(n + 2);
    for (size_t index = 0; index < n; ++index) {
        input >> a[index + 1];
    }
    size_t answer = 0;
    for (size_t index = 1; index <= n; ++index) {
        if (a[index] > l && a[index - 1] <= l) {
            ++answer;
        }
    }
    for (size_t index = 0; index < m; ++index) {
        size_t t;
        input >> t;
        if (t == 0) {
            output << answer << std::endl;
            continue;
        }
        size_t p, d;
        input >> p >> d;
        if (a[p] > l) {
            continue;
        }
        a[p] += d;
        if (a[p] <= l) {
            continue;
        }
        if (a[p - 1] > l && a[p + 1] > l) {
            answer--;
            continue;
        }
        if (a[p - 1] <= l && a[p + 1] <= l) {
            answer++;
            continue;
        }
    }
    return 0;
}

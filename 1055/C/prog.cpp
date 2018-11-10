#include <bits/stdc++.h>


template <class Class>
void Print(Class instance) {
    std::cout << instance << std::endl;
}

void Print() {
    std::cout << std::endl;
}

uint64_t common(int64_t l, int64_t r, int64_t L, int64_t R) {
    return std::max(0LL, 1LL + std::min(R, r) - std::max(L, l));
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
    int64_t l, r, t;
    input >> l >> r >> t;
    int64_t L, R, T;
    input >> L >> R >> T;
    if (t == T) {
        output << common(l, r, L, R);
        return 0;
    }
    if (l > L) {
        std::swap(l, L);
        std::swap(r, R);
        std::swap(t, T);
    }
    int64_t gcd = std::gcd(t, T);
    int64_t res = std::abs(L - l) % gcd;

    r -= l;
    l = 0;
    R = R - L + res;
    L = res;
        l -= 10000 * t;
    r -= 10000 * t;
    uint64_t answer = 0;
    int64_t tau = T - t;
    for (int index = -10000; index <= +10000; ++index) {
        int64_t kl = (l - L) / tau;
        int64_t kr = (r - R) / tau;
        std::vector<int64_t> ks{kl - 1, kl, kl + 1, kr - 1, kr, kr + 1};
        for (auto k : ks) {
            answer = std::max(answer, common(l, r, L + k * tau, R + k * tau));
        }
        l += t;
        r += t;
    }
    output << answer;

    return 0;
}

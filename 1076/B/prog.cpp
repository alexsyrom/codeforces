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
    uint64_t n;
    input >> n;
    uint64_t answer = 0;
    while (n != 0) {
        if (n % 2 == 0) {
            answer += n / 2;
            break;
        }
        bool flag = false;
        for (uint64_t index = 3; index < std::sqrt(n) + 1; ++index) {
            if (n % index == 0) {
                ++answer;
                n -= index;
                flag = true;
                break;
            }
        }
        if (flag) {
            continue;
        }
        ++answer;
        break;
    }
    output << answer;
    return 0;
}

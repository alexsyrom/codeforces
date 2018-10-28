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
    std::vector<size_t> b(n);
    for (size_t index = 0; index < n; ++index) {
        input >> a[index];
    }
    for (size_t index = 0; index < n; ++index) {
        input >> b[index];
    }
    std::unordered_set<size_t> was;
    size_t a_index = 0;
    for (size_t number : b) {
        size_t result = 0;
        if (was.find(number) == was.end()) {
            do {
                was.insert(a[a_index]);
                ++result;
                ++a_index;
            } while (number != a[a_index - 1]);
        }
        output << result << ' ';
    }

    return 0;
}

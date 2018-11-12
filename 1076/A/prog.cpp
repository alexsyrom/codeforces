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
    std::string string;
    input >> string;
    bool flag = false;
    for (size_t index = 0; index < n; ++index) {
        if (!flag && (index == n - 1 || string[index + 1] < string[index])) {
            flag = true;
        } else {
            output << string[index];
        }
    }
    return 0;
}

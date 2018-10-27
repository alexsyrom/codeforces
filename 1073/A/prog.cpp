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
    std::string string;
    input >> n;
    std::getline(input, string);
    std::getline(input, string);
    for (size_t index = 0; index < n - 1; ++index)  {
        if (string[index] != string[index + 1]) {
            output << "YES\n" << string.substr(index, 2);
            return 0;
        }
    }

    output << "NO";

    return 0;
}

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
    std::string name;
    input >> name;
    size_t L = name.length();
    if (L <= 20) {
        output << 1 << ' ' << L << std::endl;
        output << name;
        return 0;
    }
    size_t r = L / 20;
    if (L % 20 != 0) {
        r += 1;
    }
    size_t c = L / r; 
    size_t ast = 0;
    if (L % r != 0) {
        c += 1;
        ast = r * c - L;
    }
    output << r << ' ' << c << std::endl;
    size_t index = 0;
    for (size_t first = 0; first < r; ++first) {
        for (size_t second = 0; second < c; ++second) {
            if (ast > 0 && second == 0) {
                output << '*';
                --ast;
            } else {
                output << name[index];
                ++index;
            }
        }
        output << std::endl;
    }
    

    return 0;
}

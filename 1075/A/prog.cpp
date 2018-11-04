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
    uint64_t r, c;
    input >> r >> c; 
    uint64_t white = (r - 1) + (c - 1);
    uint64_t black = (n - r) + (n - c);
    if (white <= black) {
        output << "White";
    } else {
        output << "Black";
    }

    return 0;
}

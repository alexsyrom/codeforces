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
    output.precision(10);
    size_t t;
    input >> t;
    for (size_t index = 0; index < t; ++index) {
        uint32_t d;
        input >> d;
        if (d == 0) {
            output << "Y 0. 0." << std::endl;
            continue;
        }
        if (d < 4) {
            output << "N" << std::endl;
            continue;
        }
        double sD = std::sqrt(((double)(d)) * (d - 4));
        double a = (d - sD) / 2;
        double b = (d + sD) / 2;
        output << "Y " << a << " " << b << std::endl;
    }

    return 0;
}

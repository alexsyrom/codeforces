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
    size_t n, s;
    input >> n >> s;
    std::vector<size_t> a(n);
    std::vector<size_t> b(n);
    for (size_t index = 0; index < n; ++index) {
        input >> a[index];
    }
    for (size_t index = 0; index < n; ++index) {
        input >> b[index];
    }
    if (a[0] == 0) {
        output << "NO";
        return 0;
    }
    if (a[s - 1] == 0 && b[s - 1] == 0) {
        output << "NO";
        return 0;
    }
    if (a[s - 1] == 1) {
        output << "YES";
        return 0;
    }
    for (size_t index = s; index < n; ++index) {
        if (a[index] == 1 && b[index] == 1) {
            output << "YES";
            return 0;
        }
    }
    
    output << "NO";

    return 0;
}

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

    size_t n, m;
    input >> n >> m;
    std::vector<int32_t> x;
    std::vector<int32_t> tx;
    for (size_t index = 0; index < n + m; ++index) {
        int32_t coor;
        input >> coor;
        x.push_back(coor);
    }
    for (size_t index = 0; index < n + m; ++index) {
        int32_t is_taxi;
        input >> is_taxi;
        if (is_taxi == 1) {
            tx.push_back(x[index]);
        }
    }
    std::vector<size_t> a(m);
    size_t taxi_index = 0;
    for (size_t index = 0; index < n + m; ++index) {
        if (taxi_index != m - 1) {
            if (std::abs(x[index] - tx[taxi_index]) <= std::abs(x[index] - tx[taxi_index + 1])) {
                a[taxi_index] += 1;
            } else {
                while (taxi_index != m - 1 && 
                        std::abs(x[index] - tx[taxi_index]) > std::abs(x[index] - tx[taxi_index + 1]))
                {
                    ++taxi_index;
                }
                a[taxi_index] += 1;
            }
        } else {
            a[taxi_index] += 1;
        }
    }

    for (auto answer : a) {
        output << answer - 1 << ' ';
    }

    return 0;
}

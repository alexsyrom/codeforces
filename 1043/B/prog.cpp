#include <bits/stdc++.h>


template <class Class>
void Print(Class instance) {
    std::cout << instance << std::endl;
}

void Print() {
    std::cout << std::endl;
}

std::vector<size_t> ComputeZ(const std::vector<int64_t>& string) {
    std::vector<size_t> result(string.size());
    size_t left = 0;
    size_t right = 0;
    for (size_t index = 0; index < string.size(); ++index) {
        if (right > index) {
            result[index] = std::min(right - index, result[index - left]);
        } else {
            result[index] = 0;
        }
        while (index + result[index] < string.size()
                && string[index + result[index]] == string[result[index]])
        {
            ++result[index];
        }
        if (right < index + result[index]) {
            right = index + result[index];
            left = index;
        }
    }
    return result;
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
    std::vector<int64_t> x(n);
    int64_t prev = 0;
    for (size_t index = 0; index < n; ++index) {
        input >> x[index];
        int64_t prev_prev = prev;
        prev = x[index];
        x[index] -= prev_prev;
    }
    std::vector<size_t> z = ComputeZ(x);
    std::vector<size_t> answer;
    for (size_t index = 1; index < n; ++index) {
        if (z[index] + index == n) {
            answer.push_back(index);
        }
    }
    answer.push_back(n);

    output << answer.size() << std::endl;
    for (size_t index : answer) {
        output << index << ' ';
    }

    return 0;
}

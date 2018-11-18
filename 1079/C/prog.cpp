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
    for (size_t index = 0; index < n; ++index) {
        input >> a[index];
    }
    if (n == 1) {
        output << 1;
        return 0;
    }
    if (n == 2) {
        if (a[0] <= a[1]) {
            output << "1 2";
            return 0;
        } else {
            output << "2 1";
            return 0;
        }
    }
    size_t prev = 0;
    std::vector<size_t> answer;
    if (a[0] < a[1]) {
        answer.push_back(1);
    } else if (a[0] > a[1]) {
        answer.push_back(5);
    } else {
        answer.push_back(2);
    }
    for (size_t index = 1; index < n; ++index) {
        size_t prev = *answer.rbegin();
        if (index == n - 1) {
            if (a[index - 1] < a[index]) {
                if (prev == 5) {
                    output << "-1";
                    return 0;
                }
                answer.push_back(prev + 1);
                continue;
            } else if (a[index - 1] > a[index]) {
                if (prev == 1) {
                    output << "-1";
                    return 0;
                }
                answer.push_back(prev - 1);
                continue;
            } else {
                size_t cur = 2;
                if (cur == prev) {
                    cur = 3;
                }
                answer.push_back(cur);
                continue;
            }
        }
        if (a[index - 1] < a[index]) {
            if (prev == 5) {
                output << "-1";
                return 0;
            }
            if (a[index] <= a[index + 1]) {
                answer.push_back(prev + 1);
                continue;
            } else if (a[index] > a[index + 1]) {
                answer.push_back(5);
                continue;
            }
        } else if (a[index - 1] > a[index]) {
            if (prev == 1) {
                output << "-1";
                return 0;
            }
            if (a[index] < a[index + 1]) {
                answer.push_back(1);
            } else if (a[index] >= a[index + 1]) {
                answer.push_back(prev - 1);
                continue;
            }
        } else {
            if (a[index] < a[index + 1]) {
                if (prev == 1) {
                    answer.push_back(2);
                } else {
                    answer.push_back(1);
                }
                continue;
            } else if (a[index] > a[index + 1]) {
                if (prev == 5) {
                    answer.push_back(4);
                } else {
                    answer.push_back(5);
                }
            } else {
                if (prev == 2) {
                    answer.push_back(3);
                } else {
                    answer.push_back(2);
                }
            }
        }
    }
    for (auto el: answer) {
        output << el << ' ';
    }

    return 0;
}

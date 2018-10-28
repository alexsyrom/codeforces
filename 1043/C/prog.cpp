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
    std::string string;
    input >> string;
    std::vector<size_t> answer;
    bool a_first = true;
    for (auto iterator = string.rbegin(); iterator != string.rend(); ++iterator) {
        if (a_first == (*iterator == 'a')) {
            answer.push_back(1);
            a_first = !a_first;
        } else {
            answer.push_back(0);
        }
    }
    for (auto iterator = answer.rbegin(); iterator != answer.rend(); ++iterator) {
        output << *iterator << ' ';
    }
    return 0;
}

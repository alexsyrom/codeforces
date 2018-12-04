#include <bits/stdc++.h>


template <class Class>
void Print(Class instance) {
    std::cout << instance << std::endl;
}

void Print() {
    std::cout << std::endl;
}


int main() {
    auto& input = std::cin;
    auto& output = std::cout;

    size_t a = 0;
    size_t b = 0;
    for (int index = 30; index >= 0; --index) {
        size_t c = a + (1 << index);
        size_t d = b + (1 << index);
        output << "? " << c << " " << d << std::endl; 
        output.flush();
        int t;
        input >> t;
        if (t == 1) {
            b += (1 << index);
        } else if (t == -1) {
            a += (1 << index);
        } else {
            size_t c = a + (1 << index);
            size_t d = b;
            output << "? " << c << " " << d << std::endl; 
            output.flush();
            int t;
            input >> t;
            if (t == -1) {
                a += (1 << index);
                b += (1 << index);
            }
        }

    }
    output << "! " << a << " " << b << std::endl; 
    output.flush();

    return 0;
}

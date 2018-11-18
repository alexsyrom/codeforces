#include <bits/stdc++.h>


template <class Class>
void Print(Class instance) {
    std::cout << instance << std::endl;
}

void Print() {
    std::cout << std::endl;
}

struct Point {
    double x;
    double y;
};

double manh(Point first, Point second) {
    return std::abs(first.x - second.x) + std::abs(first.y - second.y);
}

double dist(Point first, Point second) {
    double x = first.x - second.x;
    double y = first.y - second.y;
    return std::sqrt(x * x + y * y);
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
    int64_t a, b, c;
    input >> a >> b >> c;
    double answer;
    std::vector<Point> points(2);
    for (size_t index = 0; index < 2; ++index) {
        input >> points[index].x;
        input >> points[index].y;
    }
    if (a == 0 || b == 0) {
        answer = manh(points[0], points[1]);
        output << answer;
        return 0;
    }
    if (points[0].x == points[1].x || points[0].y == points[1].y) {
        answer = manh(points[0], points[1]);
        output << answer;
        return 0;
    }
    std::vector<Point> adds;
    for (size_t index = 0; index < 2; ++index) {
        double x = points[index].x;
        double y = (-c - a * x) / b;
        adds.push_back(Point{x, y});
    }
    for (size_t index = 0; index < 2; ++index) {
        double y = points[index].y;
        double x = (-c - b * y) / a;
        adds.push_back(Point{x, y});
    }

    answer = manh(points[0], points[1]);
    for (size_t first = 0; first < adds.size(); ++first) {
        for (size_t second = 0; second < adds.size(); ++second) {
            if (first == second) {
                continue;
            }
            double d = 0;
            d += manh(points[0], adds[first]);
            d += dist(adds[first], adds[second]);
            d += manh(adds[second], points[1]);
            answer = std::min(answer, d);
        }
    }
    output << answer;
    return 0;
}

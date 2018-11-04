#include <bits/stdc++.h>


template <class Class>
void Print(Class instance) {
    std::cout << instance << std::endl;
}

void Print() {
    std::cout << std::endl;
}

struct Point {
    int64_t x;
    int64_t y;
};

uint64_t ComputeDistance(const Point& first, const Point& second) {
    return std::abs(first.x - second.x) + std::abs(first.y - second.y);
}

uint64_t ComputePerimeter(const std::vector<Point>& points) {
    if (points.empty()) {
        return 0;
    }
    uint64_t result = ComputeDistance(points[0], points[points.size() - 1]);
    for (size_t index = 0; index < points.size() - 1; ++index) {
        result += ComputeDistance(points[index], points[index + 1]);
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
    Point left{1000 * 1000 * 1000, 0};
    Point right{-1000 * 1000 * 1000, 0};
    Point top{0, -1000 * 1000 * 1000};
    Point bottom{0, 1000 * 1000 * 1000};
    for (size_t index = 0; index < n; ++index) {
        int64_t x, y;
        input >> x >> y;
        Point point{x, y};
        if (x < left.x) {
            left = point;
        }
        if (x > right.x) {
            right = point;
        }
        if (y < bottom.y) {
            bottom = point;
        }
        if (y > top.y) {
            top = point;
        }
    }
    uint64_t four = ComputePerimeter({left, top, right, bottom});
    uint64_t three = 0;
    three = std::max(three, ComputePerimeter({top, right, bottom}));
    three = std::max(three, ComputePerimeter({left, right, bottom}));
    three = std::max(three, ComputePerimeter({left, top, bottom}));
    three = std::max(three, ComputePerimeter({left, top, right}));
    output << three << ' ';
    for (size_t index = 4; index <= n; ++index) {
        output << four << ' ';
    }
    return 0;
}

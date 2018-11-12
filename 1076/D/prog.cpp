#include <bits/stdc++.h>


template <class Class>
void Print(Class instance) {
    std::cout << instance << std::endl;
}

void Print() {
    std::cout << std::endl;
}

struct Edge {
    size_t from;
    size_t to;
    size_t weight;
    size_t index;
};

struct To {
    size_t to;
    size_t index;
};

using Edges = std::vector<Edge>;


int main() {
    std::ios_base::sync_with_stdio(false);
    #ifdef LOCAL
        std::ifstream input("input.txt");
        std::ofstream output("output.txt");
    #else
        auto& input = std::cin;
        auto& output = std::cout;
    #endif
    size_t n, m, k;
    input >> n >> m >> k;
    k = std::min(k, n - 1);
    output << k << std::endl;
    std::vector<Edges> edges_list(n + 1);
    for (size_t index = 0; index < m; ++index) {
        size_t x, y, w;
        input >> x >> y >> w;
        edges_list[x].push_back(Edge{x, y, w, index + 1});
        edges_list[y].push_back(Edge{y, x, w, index + 1});
    }
    std::multimap<size_t, To> d_set;
    std::vector<std::multimap<size_t, To>::iterator> its(n + 1, d_set.end());
    std::vector<bool> was(n + 1, false);
    d_set.emplace(0, To{1, 0});
    for (size_t index = 0; index < k + 1; ++index) {
        auto best_it = d_set.begin();
        size_t dist = best_it->first;
        To to = best_it->second;
        was[to.to] = true;
        if (index != 0) {
            output << to.index << ' ';
        }
        d_set.erase(best_it);
        for (const auto& edge : edges_list[to.to]) {
            if (was[edge.to]) {
                continue;
            }
            if (its[edge.to] == d_set.end()) {
                its[edge.to] = d_set.emplace(dist + edge.weight, To{edge.to, edge.index});
            } else if (its[edge.to]->first > dist + edge.weight) {
                d_set.erase(its[edge.to]);
                its[edge.to] = d_set.emplace(dist + edge.weight, To{edge.to, edge.index});
            }
        }
    }

    return 0;
}

//
// Created by maksym on 01.11.22.
//

#ifndef ALGORITHMS_DSU_HPP
#define ALGORITHMS_DSU_HPP

#include <vector>
#include <stdexcept>

namespace Algorithm {
    class dsu {
    private:
        std::vector<int> parent;
        std::vector<int> _size;
        int _countOfSets;
        int _n;
    public:

        dsu() : _n(100000), parent(100000, -2), _size(100000, 0), _countOfSets(0) {}

        explicit dsu(int n) : _n(n), parent(n, -1), _size(n, -1), _countOfSets(0) {}


        void add(int x) {
            parent[x] = -1;
            _size[x] = 1;
            _countOfSets++;
        }

        int leader(int v) {
            if (v < 0 || v >= _n)
                throw std::out_of_range("not valuable element");
            if (parent[v] == -2)
                return -1;
            if (parent[v] == -1)
                return v;
            return parent[v] = leader(parent[v]);
        }

        int size(int v) {
            if (v < 0 || v >= _n)
                throw std::out_of_range("not valuable element");
            return _size[v = leader(v)];
        }

        [[nodiscard]] int countOfSets() const {
            return _countOfSets;
        }

// return false if two vertex are in the same sets
        bool merge(int a, int b) {
            if (a < 0 || a >= _n)
                throw std::out_of_range("a - not valuable element");
            if (b < 0 || b >= _n)
                throw std::out_of_range("b - not valuable element");
            a = leader(a);
            b = leader(b);
            if (a != b) {
                if (_size[a] < _size[b]) {
                    std::swap(a, b);
                }
                parent[b] = a;
                _size[a] += _size[b];
                _countOfSets--;
            } else {
                return false;
            }
        }

        bool same(int a, int b) {
            if (a < 0 || a >= _n)
                throw std::out_of_range("a - not valuable element");
            if (b < 0 || b >= _n)
                throw std::out_of_range("b - not valuable element");
            return leader(a) == leader(b);
        }
    };
}

#endif //ALGORITHMS_DSU_HPP

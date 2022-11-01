#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../DataStructures/SegmentTree.hpp"
#include <iostream>
#include "doctest.h"

int comb(int a, int b) {
//    blablabla
    return a + b;
}

TEST_CASE("Build Segment Tree") {
    std::vector<int> v = {1, 2, 3, 4, 5, 6};
    Algorithms::segment_tree<int> tree(v, comb);
    CHECK(tree.get(3, 2) == 7);
}


TEST_CASE("Update Segment Tree") {
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
    Algorithms::segment_tree<int> tree(v);
    CHECK(tree.get(3, 2) == 7);
    tree.update(2, 10);
    CHECK(tree.get(0, 2) == 13);
}

TEST_CASE("Check old version of Segment Tree") {
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
    Algorithms::segment_tree<int> tree(v);
    CHECK(tree.get(3, 2) == 7);
    tree.update(2, 10);
    CHECK(tree.get(0, 2, 0) == 6);
}
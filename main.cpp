#include <iostream>
#include "DataStructures/List.hpp"

using namespace std;

int mp(int x) {
    return x * 10;
}

signed main() {

    List<int> l(10);

    for (int i = 0; i < 10; i++)
        l[i] = i + 1;

    cout << l.size() << " ";

    return 0;
}

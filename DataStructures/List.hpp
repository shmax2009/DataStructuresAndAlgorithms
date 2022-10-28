//
// Created by maksym on 28.10.22.
//

#ifndef ALGORITHMS_LIST_HPP
#define ALGORITHMS_LIST_HPP

#include <deque>
#include <stdexcept>
#include <functional>

#define int long long
bool LIST_DISABLE_FEATURES = false;

template<class T>
class List {
    std::deque<T> list;
public:

    explicit List(size_t size) : list(size) {}

    List(size_t size, T x) : list(size, x) {}

    List() = default;

    /**  Returns a read/write iterator that points to the first element in the List. Iteration is done in ordinary
     * element order*/
    auto begin() { return list.begin(); }

    /**Returns a read/write iterator that points one past the last element in the List. Iteration is done in ordinary
     * element order. */
    auto end() { return list.end(); }

    /**
     *  Returns a read/write reverse iterator that points to the
     *  last element in the List.  Iteration is done in reverse
     *  element order.
     */
    auto rbegin() { return list.rbegin(); }

    /**
     *  Returns a read/write reverse iterator that points to one
     *  before the first element in the List.  Iteration is done
     *  in reverse element order.
     */
    auto rend() { return list.rend(); }

    /**
 *  @brief  Add data to the end of the List.
 *  @param  x  Data to be added.
 *
 *  This is a typical stack operation.  The function creates an
 *  element at the end of the List and assigns the given data
 *  to it.  Due to the nature of a List this operation can be
 *  done in constant time.
 */
    void push_back(const T &x) { list.push_back(x); }

    /**
 *  @brief  Add data to the front of the List.
 *  @param  x  Data to be added.
 *
 *  This is a typical stack operation.  The function creates an
 *  element at the front of the List and assigns the given
 *  data to it.  Due to the nature of a List this operation
 *  can be done in constant time.
 */
    void push_front(const T &x) { list.push_front(x); }

    /**
 *  @brief  Removes last element.
 *
 *  This is a typical stack operation.  It shrinks the List by one.
 *
 *  Note that no data is returned, and if the last element's data is
 *  needed, it should be retrieved before pop_back() is called.
 */
    void pop_back() { list.pop_back(); }

    /**
 *  @brief  Removes first element.
 *
 *  This is a typical stack operation.  It shrinks the List by one.
 *
 *  Note that no data is returned, and if the first element's data is
 *  needed, it should be retrieved before pop_front() is called.
 */
    void pop_front() { list.pop_front(); }

    /**  Returns the number of elements in the List.  */
    auto size() { return list.size(); }

    /**
 *  @brief  Resizes the List to the specified number of elements.
 *  @param  n  Number of elements the List should contain.
 *
 *  This function will %resize the List to the specified
 *  number of elements.  If the number is smaller than the
 *  List's current size the List is truncated, otherwise
 *  default constructed elements are appended.
 */
    void resize(size_t n) { list.resize(n); }

    /**
 *  @brief  Resizes the List to the specified number of elements.
 *  @param  n  Number of elements the List should contain.
 *  @param  x  Data with which new elements should be populated.
 *
 *  This function will %resize the List to the specified
 *  number of elements.  If the number is smaller than the
 *  List's current size the List is truncated, otherwise the
 *  List is extended and new elements are populated with given
 *  data.
 */
    void resize(size_t n, const T &x) { list.resize(n, x); }

    void erase(size_t id) { list.erase(list.begin() + id); }

    void erase(size_t s, size_t f) { list.erase(list.begin() + s, list.begin() + f); }

    T back() { return list.back(); }

    T front() { return list.front(); }

    bool empty() { return list.empty(); }

    void assign(const T &x) { list.assign(x); }

    void clear() { list.clear(); }

    T &operator[](int x) {
        if (list.empty())
            throw std::out_of_range("List is empty");
        if (!LIST_DISABLE_FEATURES)
            x = (x + (std::abs(x) / list.size() + 100) * list.size()) % list.size();
        return list[x];
    }

    List<T> &operator=(const List<T> &l) {
        list = l.list;
        return *this;
    }

    bool operator==(const List<T> &l) {
        if (l.size() != list.size())
            return false;
        for (int i = 0; i < l.size(); i++)
            if (l[i] != list[i])
                return false;

        return true;
    }



    void shiftLeft(int id = 1) {
        while (id--) {
            auto x = list.front();
            list.pop_front();
            list.push_back(x);
        }
    }

    //    1 2 3 4 ->  4 1 2 3
    void shiftRight(int id = 1) {
        while (id--) {
            auto x = list.back();
            list.pop_back();
            list.push_front(x);
        }
    }

    std::pair<int, size_t> findMin() {
        int min = INT64_MAX;
        size_t id = 0;
        for (size_t i = 0; i < size(); i++) {
            if (min > list[i]) {
                min = list[i];
                id = i;
            }
        }
        return {min, id};
    }

    std::pair<int, size_t> findMax() {
        int max = INT64_MIN;
        size_t id = 0;
        for (size_t i = 0; i < size(); i++) {
            if (max < list[i]) {
                max = list[i];
                id = i;
            }
        }
        return {max, id};
    }


    template<class F>
    List<F> map(std::function<F(T)> f) {
        List<F> ans;
        for (auto element: list) {
            ans.push_back(f(element));
        }
        return ans;
    }

    List<T> filter(std::function<bool(T)> f) {
        List<T> ans;
        for (auto element: list) {
            if (f(element))
                ans.push_back(element);
        }
        return ans;
    }

    void reverse() { std::reverse(begin(), end()); }

    void sort() { std::sort(begin(), end()); }

    void sort(std::function<bool(T, T)> cmp) { std::sort(begin(), end(), cmp); }

    List<T> part(size_t x, size_t y) {
        List<T> ans;
        if (x >= list.size() || y >= list.size())
            throw std::out_of_range("At least one of the borders is out of range");
        while (x <= y)
            ans.push_back(list[x]), x++;
        return ans;
    }

    size_t index(const T &x) {
        for (size_t i = 0; i < list.size(); ++i)
            if (list[i] == x)
                return i;
        return list.size();
    }

    bool exist(const T &x) {
        for (size_t i = 0; i < list.size(); ++i)
            if (list[i] == x)
                return true;
        return false;
    }

    int count(const T &x) {
        int k = 0;
        for (size_t i = 0; i < list.size(); ++i)
            k += list[i] == x;
        return k;
    }
};

#endif //ALGORITHMS_LIST_HPP

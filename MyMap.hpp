//
// Created by benzh on 2018-11-26.
//

#ifndef MIDTERM2_MYMAP_HPP
#define MIDTERM2_MYMAP_HPP

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

template <class K = string, class V = int>
class MyMap {

    vector<pair<K, V>> list;

public:
    void add(K key, V value) {
        bool exist = false;
        for(auto item: list) {
            if(item.first == key) {
                item.second = value;
                exist = true;
            }
        }
        if(!exist) {
            pair<K, V> temp(key, value);
            list.push_back(temp);
        }
        auto lambda = [] (auto a, auto b) {return a.first < b.first;};
        std::sort(list.begin(), list.end(), lambda);
    }

    friend ostream& operator<<(ostream& os, const MyMap& map) {
        for(auto item: map.list) {
            os << item.first << " " << item.second << "\n";
        }
        return os;
    }

    pair<K,V> operator[](int index) {
        if(index >= list.size()) {
            cout << "Array index out of bound";
            exit(0);
        }
        return list.at(index);
    }

    V operator[](K key) {
        bool found = false;
        V value;
        for(auto item: list) {
            if(item.first == key) {
                value = item.second;
                found = true;
            }
        }
        if(!found) {
            cout << "No value matching such key";
            exit(0);
        }
        return value;
    }

    /**
     * QUESTION 2
     */
    template <class InputIterator>
    auto standardDeviation(InputIterator first, InputIterator last) {
        double count = 0;
        double squaredTotal = 0;
        double total = 0;
        double variance;
        double standardDeviation;
        double mean;
        for(InputIterator i = first; i != last; i++) {
            count++;
            total += i->second;
        }
        mean = total / count;
        for(InputIterator i = first; i != last; i++) {
            squaredTotal += pow(i->second - mean, 2);
        }
        variance = squaredTotal / count;
        standardDeviation = sqrt(variance);
        return standardDeviation;
    }

    auto getFirstIter() {
        return list.begin();
    }

    auto getLastIter() {
        return list.end();
    }
};


#endif //MIDTERM2_MYMAP_HPP

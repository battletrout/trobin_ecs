/*

#include <iostream>
#include <vector>


using namespace std;

template <typename T>
T area_rect(T a, T b) {
    T result = a * b;
    return result;
}

void templatePrac() {
    int x1 = area_rect<int>(10.5, 5);
    float x2 = area_rect<float>(10.5, 5);
    double x3 = area_rect<double>(10.5, 5);

    cout << x1 << ", " << x2 << ", " << x3 << endl;
}

void iteratorBeginEnd() {
    vector<int> v = { 0, 1, 2, 3, 4, 5, 6 };

    cout << "v.begin() => " << *v.begin() << endl;

    // getting the pointer to the memory right after v[6], then setting it equal to -50
    // this is after the heap allocation... gives us an error
    int* x = &v[6];
    x++;
    *x = -50;

    // cout << "v.end() (undefined)=> " << *v.end() << endl;



    cout << "v.rbegin() => " << *v.rbegin() << endl;
    // cout << "v.rend() (undefined)=> " << *v.rend() << endl;
}

void iteratorInvalidation() {
    vector<int> v = { 0, 1, 2, 3, 4, 5, 6 };
    auto it = v.begin() + 4;

    cout << "*it => " << *it << endl;
    cout << "it - begin => " << it - v.begin() << endl;

    // vector.insert inserts at index and pushes the rest to right  
    // v.insert(it, 100);
    //Iterator invalidated... instead, we set it = v.insert, which returns the new pointer to 100

    it = v.insert(it, 100);


    cout << "it - begin => " << it - v.begin() << endl;
    cout << "*it => " << *it << endl;
}

*/
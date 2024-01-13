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


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

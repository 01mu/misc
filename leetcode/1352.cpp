#include <iostream>
#include <vector>

using namespace std;

class ProductOfNumbers {
private:
    vector<int> values;

public:
    ProductOfNumbers() {

    }

    void add(int num) {
        values.push_back(num);
    }

    int getProduct(int k) {
        int i, p = 1, sz = values.size();

        for(i = sz-1; i >= sz-k; i--) {
            p *= values[i];
        }

        return p;
    }
};

int main()
{
    int i;
    ProductOfNumbers * obj = new ProductOfNumbers();

    for(i = 0; i < 5; i++) {
        obj->add(i);
    }

    cout << obj->getProduct(3);
}

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
        if(num) {
            values.push_back(values[values.size()-1]*num);
        } else {
            values = {1};
        }
    }

    int getProduct(int k) {
        int v = 0;

        if(k < values.size()) {
            v = values.back() / values[values.size() - k - 1];
        }

        return v;
    }
};

int main()
{
    int i;
    ProductOfNumbers * obj = new ProductOfNumbers();

    for(i = 0; i < 5; i++) {
        obj->add(i);
    }

    cout << obj->getProduct(1);
}

#include <iostream>
#include <vector>

using namespace std;

class Cashier {
private:
    int count = 0;
    int n, discount;
    vector<int> products, prices;

public:
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        this->n = n;
        this->discount = discount;
        this->products = products;
        this->prices = prices;
    }

    double getBill(vector<int> product, vector<int> amount) {
        int i;
        double bill = 0;

        for(i = 0; i < product.size(); i++) {
            bill += prices[product[i]-1] * amount[i];
        }

        if(++count == n) {
            count = 0;
            bill = bill - (discount * bill) / 100;
        }

        return bill;
    }
};

int main()
{
    int n = 3, discount = 50;

    vector<int> products{1, 2, 3, 4, 5, 6, 7};
    vector<int> prices{100, 200, 300, 400, 300, 200, 100};

    Cashier * cashier = new Cashier(n, discount, products, prices);

    cout << cashier->getBill({1, 2}, {1, 2}) << endl;
    cout << cashier->getBill({3, 7}, {10, 10}) << endl;
    cout << cashier->getBill({1,2,3,4,5,6,7}, {1,1,1,1,1,1,1}) << endl;
    cout << cashier->getBill({4}, {10}) << endl;
}

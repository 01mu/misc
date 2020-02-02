#include <iostream>
#include <vector>

using namespace std;

class CombinationIterator {
private:
    int a, b;
    string ch;

public:
    CombinationIterator(string characters, int combinationLength) {
        int len = characters.length();
        string st;

        --combinationLength;

        for(int i = 0; i < len; i++) {
            for(int j = i+1; j < len; j += 1) {
                st = characters[i] + characters.substr(j, combinationLength);

                if(st.length() > combinationLength) {
                    cout << i << " " << st << endl;
                }
            }
        }
    }

    string next() {

    }

    bool hasNext() {

    }
};

int main()
{
    string c = "abcdefg";
    int cl = 3;

    CombinationIterator * obj = new CombinationIterator(c, cl);
}

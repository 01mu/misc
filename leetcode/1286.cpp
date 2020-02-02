#include <iostream>
#include <vector>

using namespace std;

class CombinationIterator {
private:
    vector<string> vals;
    int idx;

public:
    CombinationIterator(string characters, int combinationLength) {
        int len = characters.length(), i, j;
        string st;

        --combinationLength;

        for(i = 0; i < len; i++) {
            for(j = i+1; j < len; j += 1) {
                st = characters[i] + characters.substr(j, combinationLength);

                if(st.length() > combinationLength) {
                    vals.push_back(st);
                }
            }
        }
    }

    string next() {
        return vals[idx++];
    }

    bool hasNext() {
        return idx < vals.size();
    }
};

int main()
{
    string c = "abcdefgh";
    int cl = 3;

    CombinationIterator * obj = new CombinationIterator(c, cl);

    while(obj->hasNext()) {
        cout << obj->next() << endl;
    }
}

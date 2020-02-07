#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int dest) {
        int i, l = 0, r = 0, b = 0;

        for(i = 0; i < distance.size(); i++) {
            if(i >= start && i < dest) {
                b += distance[i];
            } else if(i >= dest && i < distance.size()) {
                r += distance[i];
            } else if(i >= 0 && i < start) {
                l += distance[i];
            }
        }

        return min(b, l+r);
    }
};

int main()
{
    Solution solution;

    vector<int> distance{1, 2, 3, 4};
    int start = 0, destination = 1;

    cout << solution.distanceBetweenBusStops(distance, start, destination);
}

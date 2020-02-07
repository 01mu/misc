#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int dest) {
        int i, l = 0, r = 0, b = 0;

        for(i = 0; i < start; i++) {
            l += distance[i];
        }

        for(i = dest; i < distance.size(); i++) {
            r += distance[i];
        }

        for(i = start; i < dest; i++) {
            b += distance[i];
        }

        return min(b, l+r);
    }
};

int main()
{
    Solution solution;

    vector<int> distance{1, 2, 3, 4};
    int start = 0, destination = 3;

    cout << solution.distanceBetweenBusStops(distance, start, destination);
}

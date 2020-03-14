#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int i, j = 0;
        string res;


        for(i = 0; i < votes[0].length(); i++) {
            while(j < votes.size()) {
                cout << votes[j++][i] << " ";
            }

            cout << endl;

            j = 0;
        }

        return res;
    }
};

int main()
{
    Solution solution;

    //vector<string> votes{"ABC", "ACB", "ABC", "ACB", "ACB"};
    vector<string> votes{"WXYZ", "XYZW"};

    cout << solution.rankTeams(votes);
}

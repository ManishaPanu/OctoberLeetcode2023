class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int n = people.size();
        int m = flowers.size();
        vector<int> res;
        vector<int> start(m), end(m);

        for(int i=0; i<m; i++) {
            start[i] = flowers[i][0];
            end[i] = flowers[i][1];
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        for(int i=0; i<n; i++) {
            int val = people[i];

            // just greater than val
            int bloomed = upper_bound(start.begin(), start.end(), val) - start.begin();
            //just greater than or equal to val
            int died = lower_bound(end.begin(), end.end(), val) - end.begin();

            res.push_back(abs(bloomed - died));
        }
        return res;
    }
};

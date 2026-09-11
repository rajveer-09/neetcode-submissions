class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int> ans;
        int n = heights.size();

        int maxi = -1;
        for(int i = n - 1; i >= 0; i--){
            if(heights[i] > maxi){
                ans.push_back(i);
                maxi = heights[i];
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};
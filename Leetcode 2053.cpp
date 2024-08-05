//Kth Distinct String in an array

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int>m;
        for(int i=0;i<arr.size();i++){
            m[arr[i]]++;
        }
        vector<string>ans;
        for(int i=0;i<arr.size();i++){
            if (m[arr[i]] == 1 && --k == 0)
            return arr[i];
    }
    return "";
    }
};

// Apple Redistribution into Boxes

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(),capacity.end(),greater<int>());
        int a = accumulate(apple.begin(), apple.end(), 0);
        int c = 0;
        int b = 0;
        for(int i = 0; i < capacity.size(); i++){
            b += capacity[i];
            c++;
            if(b >= a) return c;
        }
        return c;
    }
};
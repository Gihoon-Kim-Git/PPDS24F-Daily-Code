class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        vector<int> dol = stones;
        while(dol.size()>1){
            sort(dol.begin(), dol.end());
            int a = dol.back(); 
            dol.pop_back();
            int b = dol.back(); 
            dol.pop_back();
            int temp = a-b;
            dol.push_back(temp);
        }
        return dol[0];
    }
};
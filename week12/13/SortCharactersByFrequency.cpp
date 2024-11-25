class Solution {
public:
    string frequencySort(string s) {
        //아스키코드값
        //A=65 Z=90
        //a=97 z=122
        //0=48 9=57

        vector<int> array(100, 0);

        for(auto i=0; i<s.size(); i++){
            array[int(s[i])-48]++;
        }

        int cnt=0;
        int max=0;
        int cur=0;
        string output;

        while(cnt<s.size()){
            for(auto j=0; j<80; j++){
                if(array[j]>max){
                    max=array[j];
                    cur=j;
                }
            }
            
            for(auto k=0; k<max; k++){
                output+=char(cur+48);
            }
            array[cur]=0;
            cnt+=max;
            max=0;
        }
            



        return output;
    }
};
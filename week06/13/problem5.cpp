#include <vector>
#include <string>

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        //b, a, l, o, n
        std::vector<int> arr(5, 0);

        for(size_t i=0; i<text.size(); i++){
            if(text[i]=='b'){
                arr[0]++;
            }
            else if(text[i]=='a'){
                arr[1]++;
            }
            else if(text[i]=='l'){
                arr[2]++;
            }
            else if(text[i]=='o'){
                arr[3]++;
            }
            else if(text[i]=='n'){
                arr[4]++;
            }
        }

        int cnt=0;
        while(arr[0]>0 && arr[1]>0 && arr[2]>1 && arr[3]>1 && arr[4]>0){
            arr[0]--;
            arr[1]--;
            arr[4]--;
            arr[2]-=2;
            arr[3]-=2;
            cnt++;
        }

        return cnt;
    }
};
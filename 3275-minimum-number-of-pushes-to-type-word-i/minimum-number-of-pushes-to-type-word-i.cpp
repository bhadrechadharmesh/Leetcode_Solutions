class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();

        int ans = 0;
        int keys = 0;
        for(int i=0;i<n;i++){
            if(keys<8){
                ans++;
            }else if(keys<16){
                ans+=2;
            }else if(keys<24){
                ans+=3;
            }else{
                ans+=4;
            }
            keys++;
        }

        return ans;
    }
};
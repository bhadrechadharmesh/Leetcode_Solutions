class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();

        vector<pair<int,int>> count;

        for(int i=0;i<26;i++){
            count.push_back({i,0});
        }

        for(int i=0;i<n;i++){
            count[word[i]-'a'].second++;
        }

        sort(count.begin(),count.end(),[&](pair<int,int>& p1,pair<int,int>& p2){
            return p1.second>p2.second;
        });

        int ans = 0;

        for(int i=0;i<26;i++){
            if(i<8){
                ans+=count[i].second;
            }else if (i<16){
                ans += 2*count[i].second;
            }else if(i<24){
                ans += 3* count[i].second;
            }else{
                ans += 4* count[i].second;
            }
        }

        return ans;
    }
};
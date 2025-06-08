
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int cnt =0 , ssize = s.size() ;
        for(string word :words){
            int wsize = word.size();
            int j  = 0 , c=0;
            for(char ch : word){
                while(j<ssize){
                    if(ch==s[j]){
                        c++;
                        j++;
                        break;
                    }
                    j++;
                }
            }
            if(c==wsize){
                cnt++;
            }
        }
        return cnt;
    }
};
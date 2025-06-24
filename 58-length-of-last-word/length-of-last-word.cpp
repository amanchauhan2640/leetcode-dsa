class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.empty()) return 0;
        string ss ,last ;
        istringstream iss(s);
        while(getline(iss ,ss ,' ')){
            if(!ss.empty()) last = ss ;
        }
        return last.size() ;
        
    }
};
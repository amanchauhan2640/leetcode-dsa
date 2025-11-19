class Solution {
public:
    int reverse(int x) {
        long long p = 0 ; 
        while(x!=0){
        int q = x%10;
        p = p*10+q ;
        x = x/10;
         if (p > INT_MAX || p < INT_MIN)
                return 0;
        }
        return p;
        
    }
};
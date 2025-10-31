class Solution {
private:
    int reverse(int x){
        int rev=0;
        while(x>0){
            int d=x%10;
            x=x/10;
            if(rev>INT_MAX/10 || rev<INT_MIN/10){
                return 0;
            }else{
                rev=rev*10+d;
            }

        }
        return rev;
    }
public:
    
    bool isPalindrome(int x) {
        int out=reverse(x);
        if(out==x)  
            return true;
        else
            return false;
    }
};
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int f = 0, t = 0, tw = 0;

        for(int b : bills){
            if(b == 5){
                f++;
            }
            if(b == 10){
                if(f > 0){
                    f--;
                    t++;
                } else {
                    return false;
                }
            }
            if(b == 20){
                if(t > 0 && f > 0){
                    t--;
                    f--;
                    tw++;
                } else if(f >= 3){
                    f -= 3;
                    tw++;
                }
                else{
                    return false;
                }
            }
        }

        return true;
    }
};
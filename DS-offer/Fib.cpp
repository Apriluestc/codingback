class Solution {
public:
    int Fibonacci(int n) {
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return 1;
        }
        int a = 0,b = 1;
        int m = 0;
        int i;
        for(i = 2;i <= n;i++){
            m = a + b;
            a = b;
            b = m;
        }
        return m;
 
    }
};
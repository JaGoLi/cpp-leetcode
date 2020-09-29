class Solution {
public:
    int reverse(int x) {
        long new_int = 0; 
        int counter = 0, test_val = x;
        while(test_val) {
            test_val /= 10;
            counter++;
            }
        while (x) {
            new_int += ((x%10) * pow(10, --counter));
            x /= 10;
        }
        if (new_int > INT_MAX || new_int < INT_MIN)
            return 0;
        int final_int = (int) new_int;

        return final_int;
    }
};

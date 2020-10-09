class Solution {
public:
	double myPow(double x, int n) {
		return num_power(x, n);
	}


private:
	double num_power(double y, long i) {
		if (i < 0) {
			return num_power(1 / y, -i);
		}
		else {
			switch (i) {
				case 0:
					return 1;
				case 1: 
					return y;
			}
			if (i % 2 == 0) {
				return num_power(y * y, i / 2);
			}
			else {
				return y * num_power(y * y, (i - 1) / 2);
			}
		}
	}
};


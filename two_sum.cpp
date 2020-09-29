#include <iostream>
#include <vector>

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		int i = 0, n;
		bool solution_found = false;
		vector<int> print_solution;

		for (auto x = nums.begin(); x != nums.end(); x++) {
			n = i;
			for (auto y = x + 1; y != nums.end(); y++) {
				n++;
				if ((int) (*x + *y) == target) {
					solution_found = true;
					break;
				}
			}
			if (solution_found)
				break;
            		i++;
		}

		if (solution_found) {
			print_solution.push_back(i);
			print_solution.push_back(n);
		}

		return print_solution;
	}
};

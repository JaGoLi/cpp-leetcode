#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public: vector<int> nums_sort;

public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		bool empty_in = false;

		if (nums1.empty() && nums2.empty())
			return 0;
		
		if (nums1.empty()) {
			empty_in = true;
			nums_sort = nums2;
		}
		if (nums2.empty()) {
			empty_in = true;
			nums_sort = nums1;
		}

		if (!empty_in)
			nums_sort = mergeSortedArrays(nums1, nums2);

		int array_size = nums_sort.size();

		if (array_size % 2) 
			return nums_sort.at(array_size / 2);

		else {
			double first_val = nums_sort.at(array_size / 2 - 1);
			double second_val = nums_sort.at(array_size / 2);
			return (first_val + second_val) / 2;
		}

	}


private: vector<int> mergeSortedArrays(vector<int>& l1, vector<int>& l2) {
		vector<int> in_array;

		//counters
		int l1_pos = 0;
		int l2_pos = 0;

		vector<int>::iterator y;

		for (auto x = l2.begin(); x != l2.end(); x++) {
			y = l1.begin();
			advance(y, l1_pos);

			bool x_pushed = false;

			while (y != l1.end()) {
				if (*y > *x) {
					in_array.push_back(*x);
					x_pushed = true;
					break;
				}
				else {
					in_array.push_back(*y);
				}
				l1_pos++;
				y++;
			}
			if (!x_pushed)
				in_array.push_back(*x);

			l2_pos++;
		}

		while(y != l1.end()) {
			in_array.push_back(*y);
			y++;
		}

		return in_array;
	}
};

int main() {
	Solution test;

	vector<int> test1 = {1,2};
	vector<int> test2 = {3,4};

	double response = test.findMedianSortedArrays(test1, test2);

	for (auto i = test.nums_sort.begin(); i != test.nums_sort.end(); i++)
		cout << *i << " ";
	cout << endl;

	cout << test.nums_sort.size() << endl;
	cout << response << endl;
}

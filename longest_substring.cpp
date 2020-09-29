#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int max_length = 1;
		int beta_length = 1;
        
		if (s.empty())
		    return 0;

		for (int i = 0; i < s.length(); i++) {
			int ch = i + beta_length;
			beta_length--;

            		string::iterator x = s.begin();
            		advance(x, ch);

			while (x != s.end()) {

				bool same_char = false;
				string::iterator y = s.begin();
				advance(y, i);

				for (int z = 0; z <= beta_length; z++) {
					if (*x == *y) {
						same_char = true;
						break;
					}
					else y++;
				}
				if (same_char)
					break;

				else {
					beta_length++;
					x++;
				}
			}
			
			if (beta_length >= max_length) 
				max_length = beta_length + 1;
		}

		return max_length;
	}
};

int main() {
	Solution currSol;
	string input_string;
	ifstream curr_file ("ex_input.txt");

	if (curr_file.is_open()) {
		getline (curr_file, input_string);
		curr_file.close();
	}

	int answer = currSol.lengthOfLongestSubstring(input_string);

	cout << "Longest substring: " << answer << endl;

	return 1;
}

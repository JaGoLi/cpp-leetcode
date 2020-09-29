#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

class Solution {
public:
	int romanToInt(string s) {
		vector<char> cstr(s.c_str(), s.c_str() + s.size() + 1);
		int final_ans = 0;
		char prev_char;

		for (vector<char>::iterator x = cstr.begin(); x != cstr.end(); x++) {
			switch(*x) {
				case 'I':
					final_ans += 1;
					break;
				case 'V':
					if (prev_char == 'I') {
						final_ans += 3;
						break;
					}
					final_ans += 5;
					break;
				case 'X':
					if (prev_char == 'I') {
						final_ans += 8;
						break;
					}
					final_ans += 10;
					break;
				case 'L': 
					if (prev_char == 'X') {
						final_ans += 30;
						break;
					}
					final_ans += 50;
					break;
				case 'C': 
					if (prev_char == 'X') {
						final_ans += 80;
						break;
					}
					final_ans += 100;
					break;
				case 'D':
					if (prev_char == 'C') {
						final_ans += 300;
						break;
					}
					final_ans += 500;
					break;
				case 'M':
					if (prev_char == 'C') {
						final_ans += 800;
						break;
					}
					final_ans += 1000;
					break;
			}
			prev_char = *x;
		}
		return final_ans;
	}
};

int main() {
	string user_in;
	Solution currSol;

	cout << "Enter Roman numeral in capital cases: ";
	getline(cin, user_in);
	cout << "Decimal value: " << currSol.romanToInt(user_in) << endl;
	
	return 1;
}


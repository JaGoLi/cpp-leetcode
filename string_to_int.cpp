#include <iostream>

int main() {
	using namespace std;

	cout << "Enter number: ";
	string user_in;
	getline(cin, user_in);

	int result;
	try {
		result = stoi(user_in);
	}

	catch(...) {
		cout << "Not a valid input!" << endl;
		return 0;
	}

	cout << "Result: " << result << endl;
	return 1;
}

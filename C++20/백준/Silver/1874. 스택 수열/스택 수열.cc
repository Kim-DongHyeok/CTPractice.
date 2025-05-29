#include <iostream>
#include <stack>


using namespace std;

int main() {
	int arr[100000] = { 0 };
	int n;
	stack<int> make;
	string result;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}


	int index = 0, i=1;


	while (index!=n) {
		if (make.empty() == false) {
			if (make.top() == arr[index]) {
				result.append("-\n");
				make.pop();
				index++;
			}
			else if (make.top() > arr[index]) {
				cout << "NO";
				return 0;
			}
			else {
				make.push(i);
				result.append("+\n");
				i++;
			}
		}
		else {
			make.push(i);
			result.append("+\n");
			i++;
		}
	}

	cout << result;
}
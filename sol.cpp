#include <bits/stdc++.h>

using namespace std;
	
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int r;
		cin >> r;
		for (int j = 0; j < r; j++) {
			int x;
			cin >> x;
			// store the line stops in the vector
			v.emplace_back(x);
		}
	}
	// sort the vector in non-decreasing order
	sort(v.begin(), v.end());
	// create a counter vector with size of the maximum number of
	// the original vector + 1, and set all of it 0
	vector<int> counter((int) v[(int) v.size() - 1] + 1, 0);
	for (int i = 0; i < (int) v.size(); i++) {
		// count the number of occurrences of each number using the counter vector
		counter[v[i]]++;
	}
	// get the maximum number of occurrences of a number
	int mx = *max_element(counter.begin(), counter.end());
	// create a 'prev' variable to store the previous number
	// and check for duplicate values
	int prev = 0;
	for (int i = 0; i < (int) v.size(); i++) {
		// check if the number matches the maximum frequency
		// and if it did not repeat
		if (counter[v[i]] == mx && v[i] != prev) {
			// print the value
			cout << v[i] << " ";
			// store the value to be used for the next iteration
			prev = v[i];
		}
	}
	cout << '\n';
	return 0;
}

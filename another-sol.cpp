#include <bits/stdc++.h>

using namespace std;

int Factorial(int a) {
	if (a == 0) {
		return 1;
	}
	return a * Factorial(a - 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int x, n;
	cin >> x >> n;
	vector<string> s(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		// create a for-loop until 36 and create a last index with a value of 52
		// which is the corresponding two extra seats in every compartment
		// count the number of available seats in every compartment
		// if the number of available seats is greater than or equal to
		// the number of 'x' friends, then calculate the number of ways
		// that 'x' people can be placed in 'cnt' available seats (combination formula)
		// afterwards, alculate the sum of the total number of ways in every compartment
		// lastly, calculate the sum of the total number of ways in every car
		int last = 53;
		int cnt = 0;
		int ways = 0;
		for (int j = 0; j < 36; j++) {
			if ((j + 1) % 4 == 0) {
				for (int k = 3; k >= 0; k--) {
					cnt += s[i][j - k] == '0';
				}
				cnt += s[i][last] == '0';
				cnt += s[i][last - 1] == '0';
				if (cnt >= x) {
					ways += (Factorial(cnt) / (Factorial(x) * Factorial(cnt - x)));
				}
				cnt = 0;
				last -= 2;
			}
		}
		ans += ways;
	}
	cout << ans << '\n';
	return 0;
}

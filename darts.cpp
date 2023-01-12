#include <iostream>
#include <cmath>

using namespace std;
main()
{
	int n;
	int x, y;
	int score = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		double distance = sqrt(x * x + y * y);
		if (distance <= 2) {
			score += 5;
		}
		else if (distance <= 4) {
			score += 4;
		}
		else if (distance <= 6) {
			score += 3;
		}
		else if (distance <= 8) {
			score += 2;
		}
		else if (distance <= 10) {
			score += 1;
		}
		else {
			score += 0;
		}

	}
	cout << score << endl;
	return 0;
}
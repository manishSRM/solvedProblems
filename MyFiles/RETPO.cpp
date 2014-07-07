#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int main () {
	int T;
	scanf ("%d", &T);
	while (T--) {
		int x, y, ans = 0;
		scanf ("%d %d", &x, &y);
        
        x = abs (x);
        y = abs (y);

		int temp = min(x, y);
		ans += 2 * temp;
		x -= temp;
		y -= temp;

		if (x == 0) {
			if (y % 2 == 1)
				ans += (2 * y) - 1;
			else
				ans += 2 * y;
		} else {
			if (x % 2 == 1)
				ans += (2 * x) + 1;
			else
				ans += 2 * x;	
		}

		printf("%d\n", ans);
	}
 	return 0;
}
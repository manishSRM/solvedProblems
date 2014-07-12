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

		ans += (y * 2) - (y % 2) + (x * 2) + (x % 2);

		printf("%d\n", ans);
	}
 	return 0;
}
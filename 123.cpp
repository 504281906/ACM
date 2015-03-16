#include <stdio.h>
#include <string.h>
const int max_n = 105;
int card[max_n];

int main()
{
	int n, ans, ok;
	while(~scanf ("%d", &n),&&n){
		ok = 0;
		for (int i = 0; i < n; i ++){
			scanf ("%d", &card[i]);
			ok ^= card[i];
		}
		if(!ok)
			printf ("0\n");
		else{
			ans = 0;
			for (int i = 0; i < n; i ++)
				if(card[i] > (ok^card[i]))
					ans ++;
		}
		printf ("%d\n", ans);
	}
	return 0;
}


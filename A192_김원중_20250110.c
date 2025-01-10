#include <stdio.h>

/*
n이 주어졌을 때, 1부터 n까지의 합을 구해라

첫째 줄에 n이 주어짐(1보다 크거나 같고, 10,000보다 작거나 같음)
*/

int main(){
	int n = 0;

	scanf("%d", &n);

	int result = 0;
	for(int i = 1; i <= n; i++){
		result += i;
	}

	printf("%d", result);

	return 0;
}
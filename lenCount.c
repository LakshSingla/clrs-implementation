#include <stdio.h>
#include <string.h>

int main() {
	char c[100];
	int wasPrevSpace = 0;
	int len = 0;
	scanf("%[^\n]", c);
	getchar();
	for(int i = 0; i < strlen(c); i++) {
		if(c[i] != ' '){ len++; wasPrevSpace = 0; }
		if(c[i] == ' ' && !wasPrevSpace) { wasPrevSpace = 1; len++;}
	}
	printf("%d", len);
	return 0;
}

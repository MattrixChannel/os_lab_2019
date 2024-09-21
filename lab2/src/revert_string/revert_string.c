#include "revert_string.h"
#include <stdio.h>
#include <string.h>

void RevertString(char *str)
{
	int len = strlen(str);
//	printf("%i", len);
	char buf;

	printf("%s\n", str);

	for (int i = 0; i < len / 2; i++) {
		buf = str[i];
		str[i] = str[len - i];
		str[len - i] = buf;
	}
	printf("%s\n", str);
}


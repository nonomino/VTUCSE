#include <stdio.h>
#include <stdlib.h>
char str[100], pat[100], rep[100], ans[100];
int i, j, c, m, k, flag = 0;
void stringmatch()
{
	i = m = j = k = c = 0;
	while (str[c] != '\0')
	{
		if (str[m] == pat[i])
		{
			i++;
			m++;
			if (pat[i] == '\0')
			{
				flag = 1;
				for (k = 0; rep[k] != '\0'; k++, j++)
					ans[j] = rep[k];
				i = 0;
				c = m;
			}
		}
		else
		{
			ans[j] = str[c];
			j++;
			c++;
			m = c;
			i = 0;
		}
	}
	ans[j] = '\0';
}
int main()
{
	printf("\tEnter a main string\n");
	gets(str);
	printf("\tEnter the pattern;\n");
	gets(pat);
	printf("t\Enter a replace string\n");
	gets(rep);
	stringmatch();
	if (flag == 1)
		printf("\tThe resultant string is %s\n", ans);
	else
		printf("\tThe pattern string was not found!!\n");
	return 0;
}
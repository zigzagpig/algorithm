#include <stdio.h>
#include <string.h>

//最长公共子序列
int main(int argc, char const *argv[])
{
	char first_string[500] = "advantage", second_string[500] = "didactical"; //定义两个用于比较的字符串
	int solution_space[500][500] = { 0 } ;
	// int n, m; // n代表第一个字符串的长度 m代表第二个字符串的长度
	// printf("%ld\n", strlen(first_string));
	// printf("%ld\n", strlen(second_string));
	// printf("%s\n", first_string);
	// printf("%s\n", second_string);

	while(scanf("%s%s", first_string, second_string) != EOF)
	{
		for (int i = 1; i <= strlen(first_string); ++i)
			for (int j = 1; j <= strlen(second_string); ++j)
			{
				if (first_string[i-1] == second_string[j-1])
					solution_space[i][j] = solution_space[i-1][j-1] + 1;
				else
				{
					if (solution_space[i][j-1] > solution_space[i-1][j])
						solution_space[i][j] = solution_space[i][j-1];
					else
						solution_space[i][j] = solution_space[i-1][j];
				}
	
				// printf("%d%c%c ", solution_space[i][j], first_string[i-1], second_string[j-1]);
				// if (j == strlen(second_string))
				// 	printf("\n");
			}
	
		printf("%d\n", solution_space[strlen(first_string)][strlen(second_string)]);
	}	
	
	return 0;
}
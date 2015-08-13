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

	while(scanf("%s%s", first_string, second_string) != EOF) //一直读到文件末尾
	{
		for (int i = 1; i <= strlen(first_string); ++i)	//第一格字符串的每个字符
			for (int j = 1; j <= strlen(second_string); ++j) //依次跟第二个字符串的每个字符进行比较
			{
				if (first_string[i-1] == second_string[j-1])	//如果两串字符相同
					solution_space[i][j] = solution_space[i-1][j-1] + 1; //比上一个状态长度多1
				else
				{
					if (solution_space[i][j-1] > solution_space[i-1][j]) //字符串不同则上个状态最长的那一个状态
						solution_space[i][j] = solution_space[i][j-1];
					else
						solution_space[i][j] = solution_space[i-1][j];
				}
	
				// printf("%d%c%c ", solution_space[i][j], first_string[i-1], second_string[j-1]);
				// if (j == strlen(second_string))
				// 	printf("\n");
			}
	
		printf("%d\n", solution_space[strlen(first_string)][strlen(second_string)]); //最长公共子序列
	}	
	
	return 0;
}
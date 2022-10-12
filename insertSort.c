#include <stdio.h>

#define LEN 5
int a[LEN] = { 10, 5, 2, 4, 7 };

void insertSort(void)
{//不变式：在进行第j次循环之前，a[0..j-1]是排好序的。显然，在第一次循环之前，只有a[0]一个元素，它是排好序的
	int j;
	for (j = 1; j < LEN; ++j) //当退出循环时，j==LEN，则a[0..LEN-1]也是排好序的
	{
		int key = a[j];
		int i = j - 1;
		while (i >= 0 && a[i] > key)
		{
			a[i + 1] = a[i];//这时a[i]和a[i+1]里都存了a[i]的值，其中a[i]里的值已经不再需要，可以被别的值覆盖
			i--;// i--之后，就变成a[i+1]里的值可以被覆盖了。于是才有了下面的a[i + 1] = key;而不是a[i] = key;或者别的
		}
		a[i + 1] = key;
	}
}

int main(int argc, char *argv[])
{
	insertSort();
	printf("%d %d %d %d %d\n", a[0], a[1], a[2], a[3], a[4]);

	return 0;
}

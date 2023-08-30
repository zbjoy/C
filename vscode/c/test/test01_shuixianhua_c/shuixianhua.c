#include <stdio.h>

int weishu(int arr)
{
    int count = 1;
    while(arr/=10)
    {
        count++;
    }
    return count;
}

// int cifang(int* arr,int t)
// {
//     int temp = *arr;
//     while(--t)
//     {
//         *arr *= 10;
//     }
// }

int findmax(int arr,int t)
{
    while(--t)
    {
        arr /= 10;
    }
    return arr %= 10;
}

void test01()
{
    system("chcp 65001");
    int arr;
    printf("请输入一个数：");
    scanf("%d",&arr);
    int left = weishu(arr);
    int right = 1;
    while(left > right)
    {
        if(findmax(arr,left) != findmax(arr,right))
        {
            printf("不是水仙花数\n");
            return;
        }
        left--;
        right++;
    }
    printf("是水仙花数\n");


}

int main()
{
    test01();
    return 0;
}

// #include <stdio.h>
// #include <stdlib.h>
// int weishu(int x)
// {
// 	int count = 1;
// 	while (x/=10)
// 	{
// 		count++;
// 	}
// 	return count;
// }
// int cfjs(int x, int i)
// {
// 	int t = x;
// 	while (i-1)
// 	{
// 		x *= t;
// 		i--;
// 	}
// 	return x;
// }
// int cifangjisuan(int i, int n)//至少要是1次方（即n>0）
// {
// 	int j = 0;
// 	int t = i;
// 	if (n >= 2)
// 	{
// 		for (j = 2; j <= n; j++)
// 		{
// 			t = t * i;
// 		}
// 	}
// 	return t;
// }
// int main()
// {
// 	int n = 0;
// 	int i = 0;
// 	int t1 = 0;
// 	int t2 = 0;
// 	printf("请输入从第几个数字开始：");
// 	scanf("%d", &t1);
// 	printf("请输入到第几个数字结束：");
// 	scanf("%d", &t2);
// 	system("cls");
// 	printf("以下为%d到%d之间的自恋数\n", t1, t2);
// 	for (i = t1; i <= t2; i++)
// 	{
// 		n=weishu(i);
// 		int j = 0;
// 		int sum = 0;
// 		int ret = i;
// 		for (j = 1; j <= n; j++)
// 		{
// 			sum += cfjs(ret % 10,n);
// 			ret /= 10;
// 		}
// 		if (i == sum)
// 		{
// 			printf("自恋数：%d\n", i);
// 		}
// 	}
// 	return 0;
// }
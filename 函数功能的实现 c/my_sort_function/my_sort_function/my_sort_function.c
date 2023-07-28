#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
struct stu
{
	char name[10];
	int age;
	//char nub[3];
	int nub;
};
void Swap(char* e1, char* e2,int width)
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char tmp = *e1;
		*e1 = *e2;
		*e2 = tmp;
		e1++;
		e2++;
	}
}
int cmp_stu_by_age(const void* e1,const void* e2)
{
	return ((struct stu*)e1)->age -((struct stu*)e2)->age;
}
int cmp_stu_by_nub(void* e1, void* e2)
{
	return ((struct stu*)e1)->nub - ((struct stu*)e2)->nub;
}
//int cmp_stu_by_nub(const void* e1, const void* e2)
//{
//	char l = (((struct stu*)e1)->nub);
//	char k = (((struct stu*)e2)->nub);
//	int j = 'l' - 'k';//新思路，可以计算字符数字的大小(为什么错了？)
//	return j;
//}
void my_sort_bubble(void*p,int sz,int width,int(*cmp)(void* e1,void* e2))
{
	int i = 0;
	int j = 0;
	for (i = 0; i < sz - 1; i++)
	{
		for (j = 0; j < sz - 1 - i; j++)
		{
			if(cmp((char*)p+j*width,(char*)p+(j+1)*width)>0)
				Swap((char*)p+j*width,(char*)p+(j+1)*width,width);
		}
	}
}
int main()
{
	int i = 0;
	struct stu s[3] = { {"张三",30,2/*"2"*/},{"李四",20,3/*"3"*/},{"王五",10,1/*"1"*/} };
	int sz = sizeof(s) / sizeof(s[0]);
	my_sort_bubble(s, sz, sizeof(s[0]), cmp_stu_by_nub);
	for (i = 0; i < sz; i++)
	{
		printf("第%d位的信息：\n姓名：%s\n年龄：%d\n排名：%d\n\n", i+1,s[i].name, s[i].age,s[i].nub);
	}
	return 0;
}
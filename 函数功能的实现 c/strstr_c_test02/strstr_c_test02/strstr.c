#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>

char* my_Strstr(char* str1,char* str2)
{
	assert(str1 && str2);
	const char* s1 = str1;
	const char* s2 = str2;
	const char* t = str1;
	while (*t != '\0')
	{
		s1 = t;
		s2 = str2;
		//while (*s1 != '\0' && *s2 != '\0' && *s1 = *s2)
		while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')
		{
			//return str2;
			return (char*)t;
		}
		t++;
	}
	return NULL;
}

int main()
{
	char arr1[10] = "123456789";
	char arr2[3] = "56";
	char* temp = my_Strstr(arr1, arr2);
	printf("%s", temp);
	return 0;
}
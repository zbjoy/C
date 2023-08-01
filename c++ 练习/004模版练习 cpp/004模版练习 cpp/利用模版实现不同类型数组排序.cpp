#include <iostream>


using namespace std;


template <typename T>
void print(T arr[],int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
}

template <class T>
void sort_by_bubble(T arr[],int len)
{
	for (int i = 0; i < len-1; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				T temp;
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

template <typename T>
void myswap(T& a,T& b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template <typename T>
void sort_by_select(T arr[], int len)
{
	for (int i = 0; i < len-1; i++)
	{
		int max = i;
		for (int j = i+1; j < len ; j++)
		{
			if (arr[max] < arr[j])
			{
				max = j;
			}
		}
		if (max != i)
		{
			//T temp;
			//temp = arr[max];
			//arr[max] = arr[i];
			//arr[i] = temp;
			myswap(arr[max], arr[i]);
		  }
	}
}


int main()	 //警告	C4267	“ = ”: 从“size_t”转换到“int”，可能丢失数据
             //是什么意思

{
	int arr[5] = { 1,3,2,7,5 };
	int len = sizeof(arr) / sizeof(arr[0]);
	sort_by_bubble(arr,len);
	print(arr, len);
	char ch[6] = "abcde";
	len = strlen(ch);
	sort_by_select(ch, len);
	print(ch, len);
	//if ('a'-'b' < 91)
	//{
	//	cout << "test";
	//}
	return 0;
}
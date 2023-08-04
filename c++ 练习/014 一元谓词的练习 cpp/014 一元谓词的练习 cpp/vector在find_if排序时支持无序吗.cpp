#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


class MyGreaterFive
{
public:

	bool operator()(int a)
	{
		return a > 5;
	}
};

void test01()
{
	vector<int> v;
	for (int i = 10; i > 0; i--)
	{
		v.push_back(i);
	}
	vector<int>::iterator it=find_if(v.begin(), v.end(), MyGreaterFive());
	//_EXPORT_STD template <class _InIt, class _Pr>
	//_NODISCARD _CONSTEXPR20 _InIt find_if(_InIt _First, const _InIt _Last, _Pr _Pred) { // find first satisfying _Pred
	//	_Adl_verify_range(_First, _Last);
	//	auto _UFirst = _Get_unwrapped(_First);
	//	const auto _ULast = _Get_unwrapped(_Last);
	//	for (; _UFirst != _ULast; ++_UFirst) {
	//		if (_Pred(*_UFirst)) {
	//			break;
	//		}
	//	}

	//	_Seek_wrapped(_First, _UFirst);
	//	return _First; 返回的是迭代器停留（也就是找到的第一个使bool类型为真的迭代器位置
	//}
	if (it == v.end())
	{
		cout << "未找到\n";
	}
	else
	{
		cout << "找到了数字：" << *it;//如果是按0-9添加，则找到的是6，按10-1，则找到的是10
	}
}

int main()
{
	test01();
	return 0;
}
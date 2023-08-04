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
	//	return _First; ���ص��ǵ�����ͣ����Ҳ�����ҵ��ĵ�һ��ʹbool����Ϊ��ĵ�����λ��
	//}
	if (it == v.end())
	{
		cout << "δ�ҵ�\n";
	}
	else
	{
		cout << "�ҵ������֣�" << *it;//����ǰ�0-9��ӣ����ҵ�����6����10-1�����ҵ�����10
	}
}

int main()
{
	test01();
	return 0;
}
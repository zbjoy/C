#include "worker.h"



class Employee:public Worker
{
public:


	Employee(int id,string name,int dId);

	void ShowInFo();

	string GetDeptname();
};
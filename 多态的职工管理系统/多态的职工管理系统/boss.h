#include "worker.h"

class Boss :public Worker
{
public:

	Boss(int id,string name,int dId);

	void ShowInFo();

	string GetDeptname();
};
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

//ʵ�ֶ���ʽ���
typedef struct Term
{
	float coef;//��0���ϵ��
	int expm;//��0���ָ��
	struct Term* next;//�����һ����0��
}Term;

Term* CreatePolyn(Term* p, int m)
{
	Term* r;
	Term* t;
	int i;
	p = (Term*)malloc(sizeof(Term));
	r = p;
	printf("������ϵ����ָ��\n");
	for (i = 0; i < m; ++i)
	{
		t = (Term*)malloc(sizeof(Term));
		printf("������ϵ����");
		scanf("%f", &t->coef);
		printf("������ָ����");
		scanf("%d", &t->expm);
		r->next = t;
		r = t;
	}
	r->next = NULL;
	return p;
}

Term* AddPolyn(Term* pa, Term* pb)
{
	//��������ʲô�ã�����
	//Term* s;
	//Term* s1;
	//Term* s2;
	Term* qa = pa->next;
	Term* qb = pb->next;
	Term* qc = pa;
	float sumOfCoef;
	while (qa && qb)
	{
		if (qa->expm > qb->expm)
		{
			qc->next = qb;
			qc = qb;
			qb = qb->next;
		}
		else if (qa->expm < qb->expm)
		{
			qc->next = qa;
			qc = qa;
			qa = qa->next;
		}
		else
		{
			sumOfCoef = qa->coef + qb->coef;
			if (sumOfCoef != 0.0)//����д0��
			{
				qa->coef = sumOfCoef;
				qc->next = qa;
				qc = qa;
				qa = qa->next;
				qb = qb->next;
			}
			else
			{
				qc->next = qa->next;
				qa = qa->next;
				qb = qb->next;
			}
		}
	}
	qc->next = qa ? qa : qb;
	free(pb);
	return pa;
}

void test01()
{
	Term* p = (Term*)malloc(sizeof(Term));
	p = CreatePolyn(p, 5);
	Term* q = (Term*)malloc(sizeof(Term));
	q = CreatePolyn(q, 5);
	q = AddPolyn(p, q);
}

int main()
{
	//int* arr = (int*)malloc(sizeof(int));
	//int i = 12;
	//arr = &i;
	//*arr = 1;
	//int* temp = arr;
	////free(temp);
	//temp = NULL;
	//printf("%d", *arr);
	////printf("%d", *temp);
	
	

	//int i = 10;
	//int* p = &i;
	//int** t = &p;
	//t = NULL;
	//printf("%d", i);


	//Term temp;
	//temp.coef = 10;
	//temp.expm = 10;
	//Term* qa = (Term*)malloc(sizeof(Term));
	//qa = &temp;
	//qa->next = NULL;
	//Term* t = qa;
	//t->next = qa;


	test01();

	return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)  
struct
{
	int No[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int sum[9]  = {0};
	int quat[9] = {0};
	int aver[9] = {0};
}CLS;
struct student {
	char Id[14];
	char Name[7];
	int ScoTes;
	int ScoExp;
	int Score;
};
void Disp(struct student pStudents[], int num)
{
	int i,j=0;
	int cla;
	printf_s("\n学生信息:\n\n");
	printf_s("-----------------------------------------------------------------------\n");
	printf_s("序号	 姓名	    学号       班级    C成绩  C实验成绩	总成绩\n");
	for (i=0;i<num;i++)
	{
		cla= pStudents[i].Id[9]-48;
		printf_s("%d\t%s\t%s\t",i+1,pStudents[i].Name, pStudents[i].Id);
		printf_s("%d\t",cla);
		printf_s("%d\t  %d\t %d\t\n", pStudents[i].ScoTes, pStudents[i].ScoExp, pStudents[i].Score);
	}
	printf_s("\n统计信息:\n\n");
	printf_s("-----------------------------------------------------------------------\n");
	printf_s("序号    班级    学生人数   平均成绩\n");
	for (i = 0; i <9; i++)
	{
		if (CLS.aver[i]!=0)
		{
			printf_s("%d\t%d班", j + 1, i + 1);
			printf_s("\t  %d\t\t%d\n", CLS.quat[i], CLS.aver[i]);
			j++;
		}
	}
}
int PreCount(const char* filename)
{
	int StuNum = 0;
	int i;
	FILE* fpr;
	errno_t err;
	char temp[81];
	err = fopen_s(&fpr, filename, "rt");
		for (i = 0; !feof(fpr); i++)
		{
			fscanf_s(fpr, "%s", &temp, _countof(temp));
		}
		StuNum = (i - 5) / 4;
		return StuNum;
}
int Id2CLS(char id[])
{
	int cla;
	cla =id[9] - 48 ;
	return cla;
}
void Count(struct student pStudents[], int num)
{
	int i;
	int cla;
	for (i = 0; i < num; i++)
	{
		cla =Id2CLS(pStudents[i].Id)-1;
		if (cla > 0)
		{
			CLS.quat[cla]= CLS.quat[cla]+1;
			CLS.sum[cla] = CLS.sum[cla] + pStudents[i].Score;
		}
	}
	for (i = 0; i < 9; i++)
	{
		if (CLS.quat[i] != 0)
		{
			CLS.aver[i] = int(CLS.sum[i] / CLS.quat[i]);
		}
	}
}
int ReadStudentInfo(const char* filename, struct student** pStudents)
{
	int StuNum = PreCount(filename);
	int i;
	struct student* p;
	p = (struct student*)malloc(sizeof(struct student) * StuNum);
	*pStudents = p;
	FILE* fpr;
	errno_t err;
	err = fopen_s(&fpr, filename, "rt");
	if (!err)
	{
		fseek(fpr, 0, SEEK_SET);
		fscanf(fpr, "%*[^\n]");
		for (i = 0; i < StuNum; i++) {
			fscanf(fpr, "%s\t%s\t%d\t%d", (*pStudents + i)->Id, (*pStudents + i)->Name, &(*pStudents + i)->ScoTes, &(*pStudents + i)->ScoExp);
			(*pStudents + i)->Score = int(0.6*(*pStudents + i)->ScoTes + 0.4*(*pStudents + i)->ScoExp);
		}
		fclose(fpr);
		return StuNum;
	}
	else
	{
		printf("Failed to open the file!\n");
		return -1;
	}
}
int main()
{
	int num;
	struct student* Mat;
	num=ReadStudentInfo("D:\\data.txt",&Mat);
	Count(Mat, num);
	 Disp(Mat,num);
	 free(Mat);
	 return 0;
}




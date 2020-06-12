#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
struct Matrix
{
	double** mat;
	int row;
	int col;
};
void addrow(Matrix* T, int row, int rowtar, double a)
{
    int i;
    for (i = 0; i < T->col; i++)
    {
        T->mat[rowtar][i] = T->mat[rowtar][i] +a* T->mat[row][i];
    }
}
void mulrow(Matrix* T,  int rowtar, double a)
{
    int i;
    for (i = 0; i < T->col; i++)
    {
        T->mat[rowtar][i] = a * T->mat[rowtar][i];
    }
}
void InitialMatrix(Matrix* T, int row, int col) 
{
    int i;
    T->mat = (double**)malloc(row * sizeof(double*));
    for (i = 0; i < row; i++)
    {
        T->mat[i] = (double*)malloc(col * sizeof(double));
    }
    T->row = row;
    T->col = col;
}
void InitialMatrixZero(Matrix* T, int row, int col)
{
    int i, j;
    T->mat = (double**)malloc(row * sizeof(double*));
    for (i = 0; i < row; i++)
    {
        T->mat[i] = (double*)malloc(col * sizeof(double));
    }
    T->row = row;
    T->col = col;
        for (i = 0; i < row; i++)
        {
            for (j = 0; j < col; j++)
            {
                T->mat[i][j] = 0;
            }
        }
}
void InitialMatrixRand(Matrix* T, int row, int col)
{
    int i, j;
    T->mat = (double**)malloc(row * sizeof(double*));
    for (i = 0; i < row; i++)
    {
        T->mat[i] = (double*)malloc(col * sizeof(double));
    }
    T->row = row;
    T->col = col;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            T->mat[i][j] =int(rand())%50+1;
        }
    }
}
void InputMatrix(Matrix* T)
{
    int i, j;
    int row ;
    int col ;
   double temp;
    printf_s("��������������\n");
    scanf_s("%d", &row);
    printf_s("��������������\n");
    scanf_s("%d", &col);
    T->mat = (double**)malloc(row * sizeof(double*));
    for (i = 0; i < row; i++)
    {
        T->mat[i] = (double*)malloc(col * sizeof(double));
    }
    T->row = row;
    T->col = col;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf_s("�������%d�е�%d�еľ���ֵ\n",i+1,j+1);
            scanf_s("%lf", &temp);
            T->mat[i][j] =double(temp);

        }
    }

}
void DestroyMatrix(Matrix* T)
{
    int i;
    int row = T->row;
    for (i = 0; i <row; i++)
    {
        free(T->mat[i]);
    }
    free(T->mat);
}
void PrintfMatrix(Matrix* T)
{
    int i, j;
    int row = T->row;
    int col  = T-> col;
    
    printf_s("-----------------------------------------------\n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf_s("%.4f\t",T->mat[i][j]);
        }
        printf_s("\n");
    }
    printf_s("-----------------------------------------------\n");

}
int AddMatrix(Matrix* A, Matrix* B, Matrix* C)
{
    int i, j;
    int row = A->row;
    int col = A->col;
    int wrow = (A->row == B->row)&&(C->row == B->row);
    int wcol = (A->col == B->col)&&(C->col == B->col);
    if (!(wrow && wcol))
    {
        return -1;
    }
    else
    {
        for (i = 0; i < row; i++)
        {
            for (j = 0; j < col; j++)
            {
                C->mat[i][j] = A->mat[i][j] + B->mat[i][j];
            }
        }
        return 0;
    }
}
int MinusMatrix(Matrix* A, Matrix* B, Matrix* C)
{
    int i, j;
    int row = A->row;
    int col = A->col;
    int wrow = (A->row == B->row) && (C->row == B->row);
    int wcol = (A->col == B->col) && (C->col == B->col);
    if (!(wrow && wcol))
    {
        return -1;
    }
    else
    {
        for (i = 0; i < row; i++)
        {
            for (j = 0; j < col; j++)
            {
                C->mat[i][j] = A->mat[i][j] -B->mat[i][j];
            }
        }
        return 0;
    }
}
int MultiMatrix(Matrix* A, Matrix* B, Matrix* C)
{
    int i, j,k;
    double temp;
    if (!(A->col == B->row))
    {
        return -1;
    }
    else
    {
        for (i = 0; i <A->row; i++)
        {
            for (j = 0; j <B->col; j++)
            {
                temp = 0;

                for (k = 0; k < A->col; k++)
                {
                    temp += A->mat[i][k] * B->mat[k][j];
                }
                C->mat[i][j] = temp;
            }
        }

        return 0;
    }
}
double MeanMatrix(Matrix* T)
{
    int i, j;
    int row = T->row;
    int col = T->col;
    double sum=0;
    double mean;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            sum += T->mat[i][j];
        }
    }
    mean= sum / (double(row) * double(col));
    return mean;
}
int SubMatrix(Matrix* T1, Matrix* T2, int BeginRow, int BeginCol, int EndRow, int EndCol)
{
    bool wrrow = T2->row == (EndRow - BeginRow + 1);
    bool wrcol = T2->col == (EndCol - BeginCol + 1);
    int i, j;
    if (!(wrrow && wrcol))
    {
        return -1;
    }
    else
    {
        for (i = 0; i < T2->row; i++)
        {
            for (j = 0; j < T2->col; j++)
            {
                T2->mat[i][j] = T1->mat[i+ BeginRow-1][j+BeginCol-1];
            }
        }
        return 0;
    }

}
double MaxMatrix(Matrix* T)
{
    int i, j;
    int row = T->row;
    int col = T->col;
    double max = -1;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (T->mat[i][j] > max)
            {
                max = T->mat[i][j];
            }
        }
    }
    return max;
}
void TransMatrix(Matrix* T)
{
    int i, j;
    struct Matrix temp;
    int newrow = T->col;
    int newcol = T->row;
    InitialMatrix(&temp,newrow, newcol);
    for (i = 0; i < newrow; i++)
    {
        for (j = 0; j < newcol; j++)
        {
            temp.mat[i][j] = T->mat[j][i];
        }
    }
        DestroyMatrix(T);
        InitialMatrix(T, newrow, newcol);
        for (i = 0; i < newrow; i++)
        {
            for (j = 0; j < newcol; j++)
            {
                T->mat[i][j] = temp.mat[i][j];
            }
        }

    
}
void NormMatrix(Matrix* T)
{
    int i, j;
    int row = T->row;
    int col = T->col;
    double max= MaxMatrix(T);
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            T->mat[i][j] = T->mat[i][j] / max;
        }  

    }
}
void ReverseMatrix(Matrix* A, Matrix* B)
{
    int i, j;
    double a;
    for (i = 0; i < A->row; i++)
    {
        for (j = 0; j < A->col; j++)
        {
            if (i == j)
            {
                B->mat[i][j] = 1;
            }
            else
            {
                B->mat[i][j] = 0;
            }
        }

    }
    for (i =0 ; i < A->row-1;i++)
    {
        for (j = 1;j < A->row-i;j++)
        {
            a = -double(A->mat[i + j][i]) / double(A->mat[i][i]);
            addrow(A, i, i + j, a);
            addrow(B, i, i + j, a);
        }
    }
    for (i = A->row - 1; i >=0; i--)
    {
        for (j = i; j>0; j--)
        {
            a = -double(A->mat[i - j][i]) / double(A->mat[i][i]);
            addrow(A, i, i - j, a);
            addrow(B, i, i - j, a);
        }
    }
    for (i = 0; i < A->row ; i++)
    {
        a=1/ double(A->mat[i][i]);
           mulrow(A, i,a);
           mulrow(B, i, a);
    } 
}



int main()
{
    struct Matrix A, B, C;
	int opt = 18;
    int row;
    int col;
    int BeginRow, BeginCol, EndRow, EndCol;
    while (opt)
    {

        printf_s("\n\n���������ԣ���ѡ���ܣ������Ӧ�����֣�\n");
        printf_s("***************************************************\n");
        printf_s("1.����һ������������ֵ��\n");
        printf_s("2.����һ�����������������ֵ��\n");
        printf_s("3.�������������������ͣ�\n");
        printf_s("4.�������������������\n");
        printf_s("5.����������������������\n");
        printf_s("6.������������������������ͣ�\n");
        printf_s("7.������������������������\n");
        printf_s("8.���������������������������\n");
        printf_s("9.����������������2 - 4�У�1 - 3�е�����\n");
        printf_s("10.����һ�����������Ԫ�ص����ֵ��\n");
        printf_s("11.����һ����������������Ԫ�ص����ֵ��\n");
        printf_s("12.����һ�����������ת�ã�\n");
        printf_s("13.����һ����������������ת�ã�\n");
        printf_s("14.����һ������������һ����\n");
        printf_s("15.����һ�����������������һ����\n");
        printf_s("16.����һ�������������棻\n");
        printf_s("17.����һ������������������棻\n");
        printf_s("0������!\n");
        scanf_s("%d",&opt);
        switch (opt)
        {
        case 1:
            InputMatrix(&A);
            PrintfMatrix(&A);
            printf_s("�þ����ֵΪ%f\n", MeanMatrix(&A));
            DestroyMatrix(&A);
            break;
        case 2:
            printf_s("��������������\n");
            scanf_s("%d", &row);
            printf_s("��������������\n");
            scanf_s("%d", &col);
            InitialMatrixRand(&A,row,col);
            PrintfMatrix(&A);
            printf_s("�þ����ֵΪ%f\n", MeanMatrix(&A));
            DestroyMatrix(&A);
            break;
        case 3:
            printf_s("���������A\n");
            InputMatrix(&A);
            printf_s("���������B\n");
            InputMatrix(&B);
            InitialMatrix(&C, A.row, A.col);
            if (AddMatrix(&A, &B, &C))
            {
                printf_s("����ά�Ȳ�ͬ���޷�����\n");
            }
            else
            {
                printf_s("����AΪ\n");
                PrintfMatrix(&A);
                printf_s("����BΪ\n");
                PrintfMatrix(&B);
                printf_s("A+B���Ϊ\n");
                PrintfMatrix(&C);
            }
            break;
        case 4:
            printf_s("���������A\n");
            InputMatrix(&A);
            printf_s("���������B\n");
            InputMatrix(&B);
            InitialMatrix(&C, A.row, A.col);
            if (MinusMatrix(&A, &B, &C))
            {
                printf_s("����ά�Ȳ�ͬ���޷�����\n");
            }
            else
            {
                printf_s("����AΪ\n");
                PrintfMatrix(&A);
                printf_s("����BΪ\n");
                PrintfMatrix(&B);
                printf_s("A-B���Ϊ\n");
                PrintfMatrix(&C);
            }
            break;
        case 5:
            printf_s("���������A\n");
            InputMatrix(&A);
            printf_s("���������B\n");
            InputMatrix(&B);
            InitialMatrix(&C, A.row, B.col);
            if (MultiMatrix(&A, &B, &C))
            {
                printf_s("����ά�Ȳ�ͬ���޷�����\n");
            }
            else
            {
                printf_s("����AΪ\n");
                PrintfMatrix(&A);
                printf_s("����BΪ\n");
                PrintfMatrix(&B);
                printf_s("AxB���Ϊ\n");
                PrintfMatrix(&C);
            }
            break;
        case 6:
            printf_s("��������������\n");
            scanf_s("%d", &row);
            printf_s("��������������\n");
            scanf_s("%d", &col);
            InitialMatrixRand(&A, row, col);
            InitialMatrixRand(&B, row, col);
            InitialMatrix(&C, row, col);
            if (AddMatrix(&A, &B, &C))
            {
                printf_s("����ά�Ȳ�ͬ���޷�����\n");
            }
            else
            {
                printf_s("����AΪ\n");
                PrintfMatrix(&A);
                printf_s("����BΪ\n");
                PrintfMatrix(&B);
                printf_s("A+B���Ϊ\n");
                PrintfMatrix(&C);
            }
            break;
        case 7:
            printf_s("��������������\n");
            scanf_s("%d", &row);
            printf_s("��������������\n");
            scanf_s("%d", &col);
            InitialMatrixRand(&A, row, col);
            InitialMatrixRand(&B, row, col);
            InitialMatrix(&C, row, col);
            if (MinusMatrix(&A, &B, &C))
            {
                printf_s("����ά�Ȳ�ͬ���޷�����\n");
            }
            else
            {
                printf_s("����AΪ\n");
                PrintfMatrix(&A);
                printf_s("����BΪ\n");
                PrintfMatrix(&B);
                printf_s("A-B���Ϊ\n");
                PrintfMatrix(&C);
            }
            break;
        case 8:
            printf_s("���������A������\n");
            scanf_s("%d", &row);
            printf_s("���������A������\n");
            scanf_s("%d", &col);
            InitialMatrixRand(&A, row, col);
            printf_s("���������B������\n");
            scanf_s("%d", &row);
            printf_s("���������B������\n");
            scanf_s("%d", &col);
            InitialMatrixRand(&B, row, col);
            InitialMatrix(&C, A.row, B.col);
            if (MultiMatrix(&A, &B, &C))
            {
                printf_s("����ά�Ȳ�ͬ���޷�����\n");
            }
            else
            {
                printf_s("����AΪ\n");
                PrintfMatrix(&A);
                printf_s("����BΪ\n");
                PrintfMatrix(&B);
                printf_s("AxB���Ϊ\n");
                PrintfMatrix(&C);
            }
            break;
        case 9:
            printf_s("���������A������\n");
            scanf_s("%d", &row);
            printf_s("���������A������\n");
            scanf_s("%d", &col);
            InitialMatrixRand(&A, row, col);
            printf_s("��������ʼ������\n");
            scanf_s("%d", &BeginRow);
            printf_s("��������ʼ������\n");
            scanf_s("%d", &BeginCol);
            printf_s("��������ֹ������\n");
            scanf_s("%d", &EndRow);
            printf_s("��������ֹ������\n");
            scanf_s("%d", &EndCol);
            InitialMatrixRand(&B, EndRow-BeginRow+1, EndCol-BeginCol+1);
            if (SubMatrix(&A, &B, BeginRow, BeginCol, EndRow, EndCol))
            {
                printf_s("����ά�Ȳ�ͬ���޷�����\n");
            }
            else
            {
                PrintfMatrix(&A);
                printf_s("���Ӿ���Ϊ\n");
                PrintfMatrix(&B);
            }
            break;
        case 10:
            InputMatrix(&A);
            PrintfMatrix(&A);
            printf_s("�����Ԫ����%.2f", MaxMatrix(&A));
            break;
        case 11:
            printf_s("���������A������\n");
            scanf_s("%d", &row);
            printf_s("���������A������\n");
            scanf_s("%d", &col);
            InitialMatrixRand(&A, row, col);
            PrintfMatrix(&A);
            printf_s("�����Ԫ����%.2f", MaxMatrix(&A));
            break;
        case 12:
            InputMatrix(&A);
            printf_s("ԭ����Ϊ\n");
            PrintfMatrix(&A);
            printf_s("��ת��Ϊ\n"); 
            TransMatrix(&A);
            PrintfMatrix(&A);
            break;
        case 13:
            printf_s("���������A������\n");
            scanf_s("%d", &row);
            printf_s("���������A������\n");
            scanf_s("%d", &col);
            InitialMatrixRand(&A, row, col);
            printf_s("ԭ����Ϊ\n");
            PrintfMatrix(&A);
            printf_s("��ת��Ϊ\n");
            TransMatrix(&A);
            PrintfMatrix(&A);
            break;
        case 14:
            InputMatrix(&A);
            printf_s("ԭ����Ϊ\n");
            PrintfMatrix(&A);
            printf_s("���һ��Ϊ\n");
            NormMatrix(&A);
            PrintfMatrix(&A);
            break;
        case 15:
            printf_s("���������A������\n");
            scanf_s("%d", &row);
            printf_s("���������A������\n");
            scanf_s("%d", &col);
            InitialMatrixRand(&A, row, col);
            printf_s("ԭ����Ϊ\n");
            PrintfMatrix(&A);
            printf_s("���һ��Ϊ\n");
            NormMatrix(&A);
            PrintfMatrix(&A);
            break;
        case 16:
            InputMatrix(&A);
            InitialMatrix(&B, A.row, A.col);
            printf_s("ԭ����Ϊ\n");
            PrintfMatrix(&A);
            printf_s("����Ϊ\n");
            ReverseMatrix(&A,&B);
            PrintfMatrix(&B);
            break;
        case 17:
            printf_s("���������A������\n");
            scanf_s("%d", &row);
            printf_s("���������A������\n");
            scanf_s("%d", &col);
            InitialMatrixRand(&A, row, col);
            InitialMatrix(&B, A.row, A.col);
            printf_s("ԭ����Ϊ\n");
            PrintfMatrix(&A);
            printf_s("����Ϊ\n");
            ReverseMatrix(&A, &B);
            PrintfMatrix(&B);
            break;
        }
    }
}

function [a,symbols,p] = Symgen()
%%%%%%%%%%%%%%%%%%%%%%%% %����һ��10*5�ľ��󣬵�һ�У���ţ��ڶ��У�ԭʼ����
%%%%%%%%%%%%%%%%%%%%%%%% %�����У��ɱ���ʳأ������У����֣������У��볤
    sum =0;
    mat=zeros(10,5);
    for i=1:10
        mat(i,2)=rand();
        mat(i,3)=mat(i,2);
        sum=sum+mat(i,2);
    end
    a=mat/sum;
    a(:,1)=1:10; 
    symbols=a(:,1)';
    p=a(:,2)';
end
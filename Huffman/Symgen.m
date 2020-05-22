function [a,symbols,p] = Symgen()
%%%%%%%%%%%%%%%%%%%%%%%% %生成一个10*5的矩阵，第一列：序号，第二列：原始概率
%%%%%%%%%%%%%%%%%%%%%%%% %第三列：可变概率池，第四列：码字，第五列：码长
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
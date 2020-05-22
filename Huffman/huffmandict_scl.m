function mat =huffmandict_scl(x)
for i=1:9
    x=Sort(x,3,0);
    min=x(10,3);
    lessmin=min;
    mark=9;
    while lessmin==min
        lessmin=x(mark,3);
        mark=mark-1;
    end
    tsum=lessmin+min;
    for j=1:10
        if x(j,3)==min
            x(j,5)=x(j,5)+1;
            x(j,3)=tsum;
        end
        if x(j,3)==lessmin
            x(j,4)=x(j,4)+2^x(j,5);
            x(j,5)=x(j,5)+1;
            x(j,3)=tsum;
        end
    end
end  
x=Sort(x,1,1);
for i=1:10
mat(i,:)={x(i,1),dic(x(i,4),x(i,5))};
end


end
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
    symbols=a(:,1);
    p=a(:,2);
end
function mat=Sort(x,val,re)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% %通过对x矩阵第val列数值对矩阵进行排列
% transmat=zeros(1,3);
for i=1:9
    for j=1:10-i
        if xor(re,(x(j,val)<x(j+1,val)))
            transmat=x(j,:);
            x(j,:)=x(j+1,:);
            x(j+1,:)=transmat;
        end
    end
end
mat=x;
end
function f=dic(x,y)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% %根据码长与值分出码字
f=zeros(1,y);
tem=x;
for i=1:y
    f(i)=(tem-2^(y-i))>=0;
    tem=tem-f(i)*2^(y-i);
end
end

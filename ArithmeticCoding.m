%%������ɽ����������벢����ֵ��֤
format long
 x=[0.2 0.3 0.1 0.2 0.1 0.1];
 %�˴�������ʷֲ�
w=zeros(3,length(x));
block=0;
for i=1:length(x)
    w(1,i)=i;
    w(2,i)=block;
    w(3,i)=block+x(i);
    block=block+x(i);
end
w
code=[2 1 3 3 6];
%�˴�������������
res=[0 1];
for i=1:length(code)
    len=res(2)-res(1);
    res(2)=res(1)+len*w(3,code(i));
    res(1)=res(1)+len*w(2,code(i));
end
res
%��֤����
cod=0.23355;
if cod+eps>=res(1)&&cod<=res(2)+eps
    fprintf('%f�ڷ�Χ��\n',cod)
else
    fprintf('%f�����ڷ�Χ��\n',cod)
end
    
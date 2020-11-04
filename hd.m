clear
clc
b=imread('2.JPG');
for i=1:425
for j=1:319
    dr=((b(i,j,1)-70)+(70-b(i,j,1)))/6;
    dg=((b(i,j,2)-101)+(101-b(i,j,2)))/6;
    db=((b(i,j,3)-180)+(180-b(i,j,3)))/6;
    dis(i,j)=(dr^2+dg^2+db^2)/3;
    if dis(i,j)<85
    b(i,j,1)=255;
    b(i,j,2)=255;
    b(i,j,3)=255;
end
end
end

image(b);

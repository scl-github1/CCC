    timecus=zeros(1000,1);
    timeori=zeros(1000,1);
for k=1:1000
    info_cus
    elapsedTime = toc;
timecus(k)=elapsedTime*1000;
end
for k=1:1000
    info_ori
    elapsedTime = toc;
timeori(k)=elapsedTime*1000;
end
histogram(timecus)
hold
histogram(timeori)
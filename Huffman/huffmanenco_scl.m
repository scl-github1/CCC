function comp=huffmanenco_scl(sig,dict)
comp=[];
for i=1:length(sig)
    x=sig(i);
    comp=[comp;cell2mat(dict(x,2))'];
end
end

clear
clc
diff=zeros(1000,1);
eff=zeros(1000,1);
maxi=zeros(1000,1);
mini=zeros(1000,1);
stand=zeros(1000,1);
for i=1:1000
[a,symbols,p] = Symgen();
sig=randsrc(100,1,[symbols;p]);
dict=huffmandict_scl(a);
comp=huffmanenco_scl(sig,dict);
dsig=huffmandeco(comp,dict);

if(~isequal(sig,dsig))
   print('Error!');
else
L=sum(cellfun('length',dict(:,2))'.*p);
l=length(comp)/100;
H=-sum(p.*log2(p));
eta=H/L;
end
maxi(i)=max(p);
mini(i)=min(p);
diff(i)=var(p);
stand(i)=std(p);
eff(i)=eta*100;

end
cormaxi=corrcoef(maxi,eff)
scatter(maxi,eff)
title('maxi vs eff ')
figure
cormini=corrcoef(mini,eff)
scatter(mini,eff)
title('mini vs eff ')
figure
cordiff=corrcoef(diff,eff)
scatter(diff,eff)
title('diff vs eff ')
figure
corstand=corrcoef(stand,eff)
scatter(stand,eff)
title('stand vs eff ')
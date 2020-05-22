clc
clear
symbols=1:3;
p=[.45 .35 .2];
sig=randsrc(100,1,[symbols;p]);

tic
dict=huffmandict(symbols,p);
comp=huffmanenco(sig,dict);
toc

dsig=huffmandeco(comp,dict);

if(~isequal(sig,dsig))
   print('Error!');
else
L=sum(cellfun('length',dict(:,2))'.*p);
l=length(comp)/100;
H=-sum(p.*log2(p));
eta=H/L;
fprintf('Source Entropy:%1.2f,\nAverage Huffman code length:%1.2f,\nCoding efficiency:%3.1f.\n',...
    H,L,eta*100);
end
shu=zeros(5,100);
mm=zeros(5,1);
[z,mz,ry,sh,shh,cy]=textread('datas.txt','%d%d%d%d%d%d');
n=size(z);
for i=1:n
	shu(z(i),mz(i)-39641)=shu(z(i),mz(i)-39641)+1;
    if mz(i)-39641>mm(z(i),1)
        mm(z(i),1)=mz(i)-39641;
    end
end
for i=1:5
    [lmd(i),in(i,:)]=poissfit(shu(i,1:mm(i,1)));
end
    

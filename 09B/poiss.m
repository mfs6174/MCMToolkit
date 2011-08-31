shu=zeros(5,100);
mm=zeros(5,1);
[z,mz]=textread('data_2.txt','%d%d');
n=size(z);
for i=1:n
	shu(z(i),mz(i)-39641)=shu(z(i),mz(i)-39641)+1;
    if mz(i)-39641>mm(z(i),1)
        mm(z(i),1)=mz(i)-39641;
    end
end
for i=1:5
    [lmd(i),in(i,:)]=poissfit(shu(i,1:61));
    ren(i,:)=poissrnd(lmd(i),1,120);
end
lai=zeros(120,20);
c=0;
for i=1:120
   t=0;
   for j=1:5
       for k=1:ren(j,i)
           t=t+1;
           c=c+1;
           lai(i,t)=j;
       end
   end
   a=randperm(t);
   tt=lai(i,1:t);
   for j=1:t
       lai(i,a(j))=tt(j);
   end
   cc(i)=t;
end
fid=fopen('data3.txt','w');
fprintf(fid,'%d\n',c);
for i=1:120
    for j=1:cc(i)
        fprintf(fid,'%d   ',lai(i,j));
        fprintf(fid,'%d\n',i+39702);
    end
end


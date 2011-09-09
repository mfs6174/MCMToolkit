fid=fopen('rand.txt','w');
for i=1:1000
	a=randperm(72);
	for j=1:72
        a(j)=a(j)+20;
    end
	fprintf(fid,'%d ',a);
	fprintf(fid,'\n');
end

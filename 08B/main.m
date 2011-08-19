img=imread('datapic1.jpg');
img=rgb2gray(img);
[E,th,gv,gh]=EDGE(img,'sobel');
figure,imshow(E);
fid=fopen('data1.txt','w');
fid2=fopen('data2.txt','w');
[n,m]=size(E);
ee=uint8(E);
fprintf(fid,'%d\n',n,m);
for i=1:n
	fprintf(fid,'%d ',ee(i:i,:));
	fprintf(fid,'\n');
	fprintf(fid2,'%d',ee(i:i,:));
	fprintf(fid2,'\n');
end
fclose(fid);
fclose(fid2);
fl=0;
cc=0;
ff=zeros(1000,1000);
c=zeros(10);
rr=zeros(10,1000,2);
for i=1:n
	for j=1:m
		fl=1;
		floodfill(i,j);
	end
end
fid=fopen('data4.txt','w');
fprintf(fid,'%d\n',cc);		
for i=1:cc-1
	fprintf(fid,'%d\n',c(i));
	fprintf(fid,'%d ',rr(i:i,1:c(i),1:1));
	fprintf(fid,'\n');
	fprintf(fid,'%d ',rr(i:i,1:c(i),2:2));
	fprintf(fid,'\n\n');
end
fclose(fid);
for i=1:cc-1
	[uc,vc,ru,rv,tt]=fitellipse(rr(i:i,1:c(i),1:1),rr(i:i,1:c(i),2:2));
	res(1)=[uc,vc,ru,rv,tt];
end

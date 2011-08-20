img=imread('picture.bmp');
img=rgb2gray(img);
[E,th,gv,gh]=EDGE(img,'sobel');
figure,imshow(E);
fid=fopen('data1.txt','w');
fid2=fopen('data2.txt','w');
[n,m]=size(E);
global ee;
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
global fl;
fl=0;
global cc;
cc=0;
global ff;
ff=zeros(1200,1200);
global c;
c=zeros(10);
global rr;
rr=zeros(10,10000,2);
for i=1:n
	for j=1:m
		fl=1;
		floodfill(i,j);
	end
end
fid=fopen('data3.txt','w');
fprintf(fid,'%d\n',cc);		
for i=1:cc
	fprintf(fid,'%d\n',c(i));
	fprintf(fid,'%d ',rr(i:i,1:c(i),1:1));
	fprintf(fid,'\n');
	fprintf(fid,'%d ',rr(i:i,1:c(i),2:2));
	fprintf(fid,'\n\n');
end
fclose(fid);
res=zeros(10,5);
for i=1:cc
	res(i:i,:)=fitellipse(rr(i:i,1:c(i),1:1),rr(i:i,1:c(i),2:2));
end
fid=fopen('data4.txt','w');
for i=1:cc
    fprintf(fid,'%f ',res(i:i,:));
    fprintf(fid,'\n\n');
end
fclose(fid);
figure(2);
ellipse(res(1:1,3:3),res(1:1,4:4),res(1:1,5:5),res(1:1,1:1),res(1:1,2:2));
for i=2:cc
    ellipse(res(i:i,3:3),res(i:i,4:4),res(i:i,5:5),res(i:i,1:1),res(i:i,2:2));
end

[kk,bb]=textread('data5.txt','%f%f');
hold on;
xx=0:780;
for i=1:size(kk)
	plot(xx,kk(i)*xx+bb(i));
end


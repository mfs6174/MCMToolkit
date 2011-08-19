img=imread('datapic2.jpg');
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
ff=zeros(1000,1000);
global c;
c=zeros(10,1);
global rr;
rr=zeros(10,1000,2);
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
rl=zeros(10,10,2);
rh=rl;
o=0;p=0;q=0;
for i=1:5
	for j=i+1:5
		if i~=j
			[mm,o]=min(rr(i,1:c(i),2));[mm,p]=min(rr(j,1:c(j),2));
			fl=0;
			while fl==0
				fl=1;
				[k,b]=getline(rr(i:i,o:o,:),rr(j:j,p:p,:));
				for q=1:c(j)
					if (rr(j:j,q:q,1:1)-rr(j,p,1))*k+rr(j,p,2)<rr(j:j,q:q,2:2)
						p=q;fl=0;
						[k,b]=getline(rr(i:i,o:o,:),rr(j:j,p:p,:));
					end				
				end
				for q=1:c(i)
					if (rr(i:i,q:q,1:1)-rr(i,o,1))*k+rr(i,o,2)<rr(i:i,q:q,2:2)
						o=q;fl=0;
						[k,b]=getline(rr(i:i,o:o,:),rr(j:j,p:p,:));
					end
				end
			end
			rl(i:i,j:j,:)=[k,b];
		end
	end
end

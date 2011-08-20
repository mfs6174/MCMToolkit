img=imread('picture.bmp');
img=rgb2gray(img);
[E,th,gv,gh]=EDGE(img,'prewitt');
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


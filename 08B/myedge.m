img=imread('datapic1.jpg');
[E,th,gv,gh]=EDGE(img,'sobel');
figure,imshow(E);

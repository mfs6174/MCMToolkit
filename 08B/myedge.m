img=imread('datapic1.jpg');
img=rgb2gray(img);
[E,th,gv,gh]=EDGE(img,'sobel');
figure,imshow(E);

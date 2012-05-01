clear;
pnt=[
20 0; 
50 0;
160 0;
200 50;
120 100;
35 100;
10 100;
0 25;
60.000  70.000;
100.000  70.000;
];
[n,t]=size(pnt);
hold on;
for i=1:n
    scatter(pnt(i,1),pnt(i,2),'*');
end
myline=[
2 9;
3 10;
5 10;
6 9;
9 10;
3 4;
1 8;
];
[m,t]=size(myline);
for i=1:m
   plot([pnt(myline(i,1),1) pnt(myline(i,2),1)],[pnt(myline(i,1),2) pnt(myline(i,2),2)]);
end
for i=1:10
    plot([200/11*i 200/11*i],[0 100],'--');
    plot([0 200],[100/11*i 100/11*i],'--');
end
x=152.5 ;y=57.5;
yy=min(y+12.5,100);
plot([x-12.5 x+12.5],[yy yy]);
plot([x-12.5 x-12.5],[yy y-12.5]);
plot([x-12.5 x+12.5],[y-12.5 y-12.5]);
plot([x+12.5 x+12.5],[y-12.5 yy]);





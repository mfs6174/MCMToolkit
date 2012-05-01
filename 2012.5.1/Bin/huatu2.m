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
59.556 77.333;
172.667 43.889;
];
[n,t]=size(pnt);
hold on;
for i=1:n
    scatter(pnt(i,1),pnt(i,2),'*');
end
myline=[
2 9;
3 10;
5 9;
5 10;
6 9;
1 8;
10 4;
];
[m,t]=size(myline);
for i=1:m
   plot([pnt(myline(i,1),1) pnt(myline(i,2),1)],[pnt(myline(i,1),2) pnt(myline(i,2),2)]);
end
x=45.455 ;y=86.364;
yy=min(y+20,100);
plot([x-20 x+20],[yy yy]);
plot([x-20 x-20],[yy y-20]);
plot([x-20 x+20],[y-20 y-20]);
plot([x+20 x+20],[y-20 yy]);
x=172.727;y=40.909;
yy=min(y+20,100);
plot([x-20 x+20],[yy yy]);
plot([x-20 x-20],[yy y-20]);
plot([x-20 x+20],[y-20 y-20]);
plot([x+20 x+20],[y-20 yy]);




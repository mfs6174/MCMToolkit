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
62.000 78.000;
165.000 70.000;
181.000 48.000;
];
[n,t]=size(pnt);
hold on;
for i=1:n
    scatter(pnt(i,1),pnt(i,2),'*');
end
myline=[
2 9;
3 11;
5 9;
5 10;
6 9;
10 11;
8 1;
4 11;
];
[m,t]=size(myline);
for i=1:m
   plot([pnt(myline(i,1),1) pnt(myline(i,2),1)],[pnt(myline(i,1),2) pnt(myline(i,2),2)]);
end
%for i=1:10
%    plot([200/11*i 200/11*i],[0 100],'--');
%    plot([0 200],[100/11*i 100/11*i],'--');
%end
x=152.5 ;y=57.5;
yy=min(y+12.5,100);
plot([x-12.5 x+12.5],[yy yy]);
plot([x-12.5 x-12.5],[yy y-12.5]);
plot([x-12.5 x+12.5],[y-12.5 y-12.5]);
plot([x+12.5 x+12.5],[y-12.5 yy]);
x=60 ;y=70;
yy=min(y+20,100);
plot([x-20 x+20],[yy yy],'--');
plot([x-20 x-20],[yy y-20],'--');
plot([x-20 x+20],[y-20 y-20],'--');
plot([x+20 x+20],[y-20 yy],'--');
x=180 ;y=50;
yy=min(y+20,100);
plot([x-15 x+20],[yy yy],'--');
plot([x-15 x-15],[yy y-20],'--');
plot([x-15 x+20],[y-20 y-20],'--');
plot([x+20 x+20],[y-20 yy],'--');
x=165 ;y=70;
yy=min(y+5,100);
plot([x-5 x+5],[yy yy],'--');
plot([x-5 x-5],[yy y-5],'--');
plot([x-5 x+5],[y-5 y-5],'--');
plot([x+5 x+5],[y-5 yy],'--');




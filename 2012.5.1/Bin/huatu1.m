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
50 75;
40 40;
120 40;
115,70;
];
[n,t]=size(pnt);
hold on;
for i=1:n
    scatter(pnt(i,1),pnt(i,2),'*');
end
m=24;
c=0;
for i=9:12
    for j=1:3
        c=c+1;
        myline(c,:)=[i j];
    end
    for j=5:7
        c=c+1;
        myline(c,:)=[i j];
    end
end
for i=1:m
   plot([pnt(myline(i,1),1) pnt(myline(i,2),1)],[pnt(myline(i,1),2) pnt(myline(i,2),2)]);
end
m=0;
for i=9:12
    for j=i+1:12
        m=m+1;
        myline(m,:)=[i j];
    end
end
for i=1:m
   plot([pnt(myline(i,1),1) pnt(myline(i,2),1)],[pnt(myline(i,1),2) pnt(myline(i,2),2)],'-.');
end
m=0;
for i=1:3
    for j=5:7
        m=m+1;
        myline(m,:)=[i j];
    end
end
for i=1:m
   plot([pnt(myline(i,1),1) pnt(myline(i,2),1)],[pnt(myline(i,1),2) pnt(myline(i,2),2)],'--');
end





[xx,yy]=textread('data7.txt','%f%f');
[p,s]=polyfit(xx(1:3),yy(1:3),1);
[y,dta]=polyval(p,xx(1:3),s);
err=var(dta)
hold on;
plot(xx,yy,'r.');

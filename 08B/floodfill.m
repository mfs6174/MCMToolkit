function floodfill(x,y)
global ee;
global fl;
global cc;
global c;
global rr;
global ff;
if ee(x,y)==0
	return
end
if ff(x,y)~=0
	return
end
if fl==1
	cc=cc+1;
	fl=0;
end
ff(x,y)=cc;
c(cc)=c(cc)+1;
rr(cc,c(cc),1)=x;
rr(cc,c(cc),2)=y;
i=0;j=0;
for i=-1:1
	for j=-1:1
		floodfill(x+i,y+j);
	end
end


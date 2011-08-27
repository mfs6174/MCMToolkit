%syms t;
%syms y0;
f1=fittype('a+b*t+y0*exp(r*t)','independent',{'t'},'problem',{'y0'},'coefficients',{'a','b','r'});
f2=fittype('a+b*t+q*sin(w*t+o)','independent',{'t'},'coefficients',{'a','b','q','w','o'});
f3=fittype('a+b*t+k/(1+exp(c-r*t))','independent',{'t'},'coefficients',{'a','b','k','c','r'});
f4=fittype('y0*exp(r*t)+k/(1+exp(c-r*t))','independent',{'t'},'problem',{'y0'},'coefficients',{'r','k','c'});
f5=fittype('y0*exp(r*t)+q*sin(w*t+o)','independent',{'t'},'problem',{'y0'},'coefficients',{'r','q','w','o'});
f6=fittype('q*sin(w*t+o)+k/(1+exp(c-r*t))','independent',{'t'},'coefficients',{'q','w','o','k','c','r'});

x=2000:1:2009;
x=x';
[y(1,:),y(2,:),y(3,:),y(4,:)]=textread('data2.txt','%f%f%f%f');
%f1=fittype('a+b*t','independent',{'t'},'coefficients',{'a','b'});
i=1;
    d=(y(i,6)-y(i,3))/3;
    y(i,4)=y(i,3)+d;
    y(i,5)=y(i,4)+d;
    yy=y(i,1);
    i
    [fun,G]=fit(x,y(i,1:10)',f1,'problem',yy)
    [fun,G]=fit(x,y(i,1:10)',f2)
    [fun,G]=fit(x,y(i,1:10)',f3)
    [fun,G]=fit(x,y(i,1:10)',f4,'problem',yy)
    [fun,G]=fit(x,y(i,1:10)',f5,'problem',yy)
    [fun,G]=fit(x,y(i,1:10)',f6)
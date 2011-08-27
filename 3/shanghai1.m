%syms t;
%syms y0;
f1=fittype('a+b*t+y0*exp(r*t)','independent',{'t'},'coefficients',{'a','b','r','y0'});
f2=fittype('a+b*t+q*sin(w*t+o)','independent',{'t'},'coefficients',{'a','b','q','w','o'});
f3=fittype('a+b*t+k/(1+exp(c-r*t))','independent',{'t'},'coefficients',{'a','b','k','c','r'});
f4=fittype('y0*exp(r*t)+k/(1+exp(c-r*t))','independent',{'t'},'coefficients',{'r','k','c','y0'});
f5=fittype('y0*exp(r*t)+q*sin(w*t+o)','independent',{'t'},'coefficients',{'r','q','w','o','y0'});
f6=fittype('q*sin(w*t+o)+k/(1+exp(c-r*t))','independent',{'t'},'coefficients',{'q','w','o','k','c','r'});

x=(1:8)';
[y(1,:),y(2,:),y(3,:),y(4,:)]=textread('data2.txt','%f%f%f%f');
%f1=fittype('a+b*t','independent',{'t'},'coefficients',{'a','b'});
for i=1:1
    if y(i,4)<y(i,3)
        d=(y(i,6)-y(i,3))/3;
        y(i,4)=y(i,3)+d;
        y(i,5)=y(i,4)+d;
        flag=1
    end
    mr=-10;
    [fun,G]=fit(x,y(i,1:8)',f1);
        if G.rsquare>mr
            mfun=fun;mG=G;mr=G.rsquare;
        end
    
    [fun,G]=fit(x,y(i,1:8)',f2);
        if G.rsquare>mr
            mfun=fun;mG=G;mr=G.rsquare;
        end
    
    [fun,G]=fit(x,y(i,1:8)',f3);
        if G.rsquare>mr
            mfun=fun;mG=G;mr=G.rsquare;
        end
        
    [fun,G]=fit(x,y(i,1:8)',f4);
        if G.rsquare>mr
            mfun=fun;mG=G;mr=G.rsquare;
        end
        
    [fun,G]=fit(x,y(i,1:8)',f5);
        if G.rsquare>mr
            mfun=fun;mG=G;mr=G.rsquare;
        end
        
    [fun,G]=fit(x,y(i,1:8)',f6);
        if G.rsquare>mr
            mfun=fun;mG=G;mr=G.rsquare;
        end
    i
    mfun
    mG
    output_fig([x',9,10,11],y(i,:),mfun,'shanghai1');
end
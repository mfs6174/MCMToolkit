%syms t;
%syms y0;
f1=fittype('a+b*t+y0*exp(r*t)','independent',{'t'},'coefficients',{'a','b','r','y0'});
f2=fittype('a+b*t+q*sin(w*t+o)','independent',{'t'},'coefficients',{'a','b','q','w','o'});
f3=fittype('a+b*t+k/(1+exp(c-r*t))','independent',{'t'},'coefficients',{'a','b','k','c','r'});
f4=fittype('y0*exp(r*t)+k/(1+exp(c-r*t))','independent',{'t'},'coefficients',{'r','k','c','y0'});
f5=fittype('y0*exp(r*t)+q*sin(w*t+o)','independent',{'t'},'coefficients',{'r','q','w','o','y0'});
f6=fittype('q*sin(w*t+o)+k/(1+exp(c-r*t))','independent',{'t'},'coefficients',{'q','w','o','k','c','r'});

s='suzhou';
[y(1,:),y(2,:),y(3,:),y(4,:)]=textread(sprintf('%s.txt',s),'%f%f%f%f');
fid=fopen(sprintf('%s-result.txt',s),'w');
%f1=fittype('a+b*t','independent',{'t'},'coefficients',{'a','b'});
for i=4:4
    if y(i,1)==0
        n=2:10;
    else
        n=1:10;
    end
    x=n';
    fprintf(fid,'%d\n\n',i);
    if y(i,4)<y(i,3)
        d=(y(i,6)-y(i,3))/3;
        y(i,4)=y(i,3)+d;
        y(i,5)=y(i,4)+d;
        fprintf(fid,'经过插值\n');
        fprintf(fid,'%f ',y(i,:));
        fprintf(fid,'\n\n');
    end
    mr=-10;
    [fun,G]=fit(x,y(i,n)',f1,'Startpoint',[1,1,1,1]);
       if G.rsquare>mr
            mfun=fun;mG=G;mr=G.rsquare;
        end
    
    [fun,G]=fit(x,y(i,n)',f2,'Startpoint',[1,1,1,0.01,1]);
        if G.rsquare>mr
            mfun=fun;mG=G;mr=G.rsquare;
        end
    
    [fun,G]=fit(x,y(i,n)',f3,'Startpoint',[1,1,1,1,1]);
        if G.rsquare>mr
            mfun=fun;mG=G;mr=G.rsquare;
        end
        
    [fun,G]=fit(x,y(i,n)',f4,'Startpoint',[1,1,1,1]);
        if G.rsquare>mr
            mfun=fun;mG=G;mr=G.rsquare;
        end
        
    [fun,G]=fit(x,y(i,n)',f5,'Startpoint',[1,0.5,0.01,0,1]);
        if G.rsquare>mr
            mfun=fun;mG=G;mr=G.rsquare;
        end
  
    if length(n)>6
    [fun,G]=fit(x,y(i,n)',f6,'Startpoint',[1,0.1,1,1,1,1]);
        if G.rsquare>mr
            mfun=fun;mG=G;mr=G.rsquare;
        end
    end
    fprintf(fid,'%f\n',mfun(11));
    fprintf(fid,'%f\n',y(i,11)-mfun(11));
    i
    mfun
    mG
    if y(i,1)~=0
        output_fig(1:11,y(i,:),mfun,sprintf('%s%d',s,i),2000);
    else
        output_fig(2:11,y(i,2:11),mfun,sprintf('%s%d',s,i),2001);
    end
end
fclose(fid);

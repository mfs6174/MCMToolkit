clear;
clc;
sig=0.025;
x0=[1,1];
maxiter=100;
syms x;
syms y;
f=x^4+y^4-0.2*x^2-4*y^2+2*x*y;
iter=0;
dd=fun1(x0);
while iter<=maxiter && dd(1,1)^2+dd(1,2)^2>=sig
    tk=0.1;
    x0=x0+tk*dd;
    dd=fun1(x0);
    iter=iter+1;
end
x0
subs(f,{x,y},x0)
iter


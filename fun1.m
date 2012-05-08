function Ra=fun1(X)
    syms x;
    syms y;
    f=x^4+y^4-0.2*x^2-4*y^2+2*x*y;
    df=jacobian(f);
    Ra=-subs(df,{x,y},{X});
end

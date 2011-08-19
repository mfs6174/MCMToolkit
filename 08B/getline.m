function [k,b]=getline(x,y)
k=(y(1)-y(2))/(x(1)-x(2));
b=y(1)-k*x(1);

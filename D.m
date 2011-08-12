%ode23 ode45 ode113 ode15s ode23s
%y1=y y2=y' y3=y''
%dy=[y';y''...] 表达式 写成函数fun 自变量t
%[T,Y]=ode45('fun',t范围向量(闭区间或散点),各个y的t=0初值向量)

%y'=t y''=y' y'''=5
function dy=fun(t,y)
	dy=[t,y(2),5];

ts=[0,100];
y0=[1,2,3,5];
[T,Y]=ode45('fun',ts,y0);

%解析解
dsolve('方程等式 Dy D2y x','初值等式','x');
[X,Y]=dsolve('方程1','方程2');



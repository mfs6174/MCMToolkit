%ode23 ode45 ode113 ode15s ode23s
%y1=y y2=y' y3=y''
%dy=[y';y''...] ���ʽ д�ɺ���fun �Ա���t
%[T,Y]=ode45('fun',t��Χ����(�������ɢ��),����y��t=0��ֵ����)

%y'=t y''=y' y'''=5
function dy=fun(t,y)
	dy=[t,y(2),5];

ts=[0,100];
y0=[1,2,3,5];
[T,Y]=ode45('fun',ts,y0);

%������
dsolve('���̵�ʽ Dy D2y x','��ֵ��ʽ','x');
[X,Y]=dsolve('����1','����2');



%层次分析法的matlab程序  
disp('A(n)');% 在屏幕显示这句话
A=input('A=');% 从屏幕接收判断矩阵
[n,n]=size(A);% 计算A的维度，这里是方阵，这么写不太好
x=ones(n,100);% x为n行100列全1的矩阵
y=ones(n,100);% y同x
m=zeros(1,100);% m为1行100列全0的向量
m(1)=max(x(:,1));% x第一列中最大的值赋给m的第一个分量
y(:,1)=x(:,1);% x的第一列赋予y的第一列
x(:,2)=A*y(:,1);% x的第二列为矩阵A*y(:,1)
m(2)=max(x(:,2));% x第二列中最大的值赋给m的第二个分量
y(:,2)=x(:,2)/m(2);% x的第二列除以m(2)后赋给y的第二列
p=0.0001;i=2;k=abs(m(2)-m(1));% 初始化p，i，k为m(2)-m(1)的绝对值
while  k>p% 当k>p是执行循环体
  i=i+1;% i自加1
  x(:,i)=A*y(:,i-1);% x的第i列等于A*y的第i-1列
  m(i)=max(x(:,i));% m的第i个分量等于x第i列中最大的值
  y(:,i)=x(:,i)/m(i);% y的第i列等于x的第i列除以m的第i个分量
  k=abs(m(i)-m(i-1));% k等于m(i)-m(i-1)的绝对值
end
a=sum(y(:,i));% y的第i列的和赋予a
w=y(:,i)/a;% y的第i列除以a
t=m(i);% m的第i个分量赋给t
disp('w');disp(w);% 显示权向量w
disp('lamda');disp(t);% 显示最大特征值t


%以下是一致性检验
CI=(t-n)/(n-1);% t-维度再除以维度-1的值赋给CI
RI=[0 0 0.52 0.89 1.12 1.26 1.36 1.41 1.46 1.49 1.52 1.54 1.56 1.58 1.59];% 计算的标准
CR=CI/RI(n);% 计算一致性
if CR<0.10
    disp('Yes!');
    disp('CI=');disp(CI);
    disp('CR=');disp(CR);
else 
    disp('No!');
end

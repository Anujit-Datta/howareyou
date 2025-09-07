Bisection Method
clc;
clear all;
fx = input('Enter the function ,F(x) = ','s');
f = eval(['@(x)',fx]) ;
a = input('Enter a=');
b = input('Enter b=');
v = b;
while(f(b)<0)
    b = a;
    a = v;
    break;
end
s = 1;
fprintf('N\t\ta\t\t b\t\t x\t\t f(x)\t\t\t Error\n');
for k = 1:100;
    it(k) = abs(k);
    x(k) = (a+b)/2;
    c = f(x(k));
    fprintf('%g %f %f %f %f %f\n',k,a,b,x(k),c,s);
    if c > 0
        b = x(k);
    else
        a = x(k);
    end
    x(k+1) = (a+b)/2;
    s = ((abs(x(k+1)-x(k)))/abs(x(k+1)))*100;
    if s <= .01
        break;
    end
end
fprintf('\n\n Hence the root is %f ',x(k));





bisection-2
clear
fx = input('Enter the function ,F(x) = ','s');
f = eval(['@(x)',fx]) ;
a = input('Enter a=');
b = input('Enter b=');
tol = 1e-5;
if f(a)*f(b) > 0
    disp('Please change the value of a and b');
    return
end
kmax = 30;
fprintf('N\t \ta\t\t b\t\t c\t\t f(c)\t\t\t Error\n');
for k = 1:kmax
    c = (a+b)/2;
    if f(c) == 0
        break
    end
    fprintf('%5i %10.6f %10.6f %10.6f %11.7f \n',k,a,b,c,abs(f(c)))
    if abs(f(c)) <= tol
        break
    end
    if f(b)*f(c) > 0
        b = c;
    else
        a = c;
    end
end
fprintf('\n\n Hence the root is %f ', c);






False Position
clc;
clear all;
fx = input('Enter the function ,F(x) = ','s');
f = eval(['@(x)',fx]) ;
a = input('Enter a=');
b = input('Enter b=');
s = 1;
fprintf('N\t \ta\t\t b\t\t x\t\t f(x)\t\t\t Error\n' );
for k = 1:100;
    x(k) = a-(f(a)*(b-a))/(f(b)-f(a));
    c = f(x(k));
    fprintf('%g %f %f %f %f %f \n',k,a,b,x(k),c,s);
    if c > 0
        b = x(k);
    else
        a = x(k);
    end
    x(k+1) = a-(f(a)*(b-a))/(f(b)-f(a));
    s = ((abs(x(k+1)-x(k)))/abs(x(k+1)))*100;
    if s <= 0.01
        break;
    end
end
fprintf('\n\nThe root is =%f',x(k));








Newton-Raphson Method
% Clearing Screen
clc
% Setting x as symbolic variable
syms x;
% Input Section
y = input('Enter non-linear equations: ');
a = input('Enter initial guess: ');
e = input('Tolerable error: ');
N = input('Enter maximum number of steps: ');
% Initializing step counter
step = 1;
% Finding derivate of given function
g = diff(y,x);
% Finding Functional Value
fa = eval(subs(y,x,a));
while abs(fa) > e
    fa = eval(subs(y,x,a));
    ga = eval(subs(g,x,a));
    if ga == 0
        disp('Division by zero.');
        break;
    end
    b = a - fa/ga;
    fprintf('step=%d\ta=%f\tf(a)=%f\n',step,a,fa);
    a = b;
    if step > N
        disp('Not convergent');
        break;
    end
    step = step + 1;
end
fprintf('Root is %f\n', a);








Secant Method
clc;
clear all;
fx = input('Enter the function ,F(x) = ','s');
f = eval(['@(x)',fx]) ;
a = input('Enter a=');
b = input('Enter b=');
x(1) = a;
x(2) = b;
s = 1;
fprintf('N\t\t x(i-1)\t\t x(i)\t\t x(i+1)\t\t f(x)\t\t Error\n');
for k = 3:103;
    it(k) = abs(k-2);
    x(k) = x(k-1)-(f(x(k-1))*(x(k-1)-x(k-2)))/(f(x(k-1))-f(x(k-2)));
    c = f(x(k));
    fprintf('%g %f %f %f %f %f\n\n',it(k),x(k-2),x(k-1),x(k),c,s);
    s = ((abs(x(k)-x(k-1)))/abs(x(k)))*100;
    if s <= .001
        break;
    end
end
fprintf('\n\nThe root is =%f',x(k));









Gaussian Elimination method
clc;
clear all;
a = input('Enter matrix A = ');
b = input('Enter matrix B = ');
[m,n] = size(a);
for k = 1:m-1
    for i = k+1:m
        fact = a(i,k)/a(k,k);
        for j = 1:n
            a(i,j) = a(i,j)-a(k,j)*fact;
        end
        b(i,1) = b(i,1)-b(k,1)*fact;
    end
end
x(m) = b(m,1)/a(m,n);
for i = m-1:-1:1
    sum = 0;
    for j = i+1:n
        sum = sum+a(i,j)*x(j);
    end
    x(i) = (b(i,1)-sum)/a(i,i);
end
disp('After forward elimination the matrix [A B] :');
disp([a b]); %%Shows a & b in matrix form
fprintf('\nThe Required solution : ');
for i = 1:n
    fprintf('\nx(%d) = %f',i,x(i));
end









Trapezoidal Rule method
clc
clear all
n = input('Enter the value n= ');
h = input('Enter the value h= ');
for i = 1:n+1
    f(i) = input('Enter the value f(i)= ');
end
sum = (f(1)+f(n+1))/2;
for j = 2:n
    sum = sum+f(j);
end
Integral = h*sum;
Integral







Simpsons Rule
clc
clear all
n = input('Enter the value of n= ');
h = input('Enter the value of h= ');
for i = 1:n+1
    f(i) = input('Enter the value of f(i)= ');
end
sum = (f(1)+f(n+1));
for i = 2:n
    sum = sum+4*f(i);
end
for i = 3:n-1
    sum = sum+2*f(i);
end
Integral = h*(sum/3);
Integral







Runge-Kutta
clc
clear all
fx = input('Enter the function ,dx/dy = ','s');
f = eval(['@(x,y)',fx]) ;
x1 = input('initial value of x1= ');
y1 = input('initial value of y1= ');
xp = input('input x at which y is required xp= ');
h = input('input step size h= ');
n = (xp-x1)/h;
for i = 1:n
    m1 = f(x1,y1);
    x2 = x1+h;
    y2 = y1+h*m1;
    m2 = f(x2,y2);
    y2 = y1+((h/2)*(m1+m2));
    x1 = x2;
    y1 = y2;
end
fprintf('At x=%g the value of y(%g)=%f',xp,xp,y2);
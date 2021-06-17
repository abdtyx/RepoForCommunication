%单应矩阵 选点
clear
clc;
image1=imread('firstView000000.jpg');
image2=imread('secondView000000.jpg');
figure(1);
imshow(image1);
[xx,yy]=ginput(4);
figure(2);
imshow(image2);
[xa,ya]=ginput(4);
P1=[xx(1) yy(1);
    xx(2) yy(2);
    xx(3) yy(3);
    xx(4) yy(4)];
P2=[xa(1) ya(1);
    xa(2) ya(2);
    xa(3) ya(3);
    xa(4) ya(4)];
Point_H=[P1,P2];
 
H_Initial.img1=image1;
H_Initial.img2=image2;
H_Initial.Point=Point_H;
save H.mat H_Initial;

clear;clc;
load H;
H_Initial.img1=imread('firstView000300.jpg');
H_Initial.img2=imread('secondView000300.jpg');
 
 
P1=H_Initial.Point(:,1:2);P2=H_Initial.Point(:,3:4);
H = CalcH(P1, P2);
 
% 测试单应性矩阵
 
figure(1);imshow(H_Initial.img1);hold on;plot(P1(:,1),P1(:,2),'r.');
[P11x, P11y] = ginput(1);
P11 = [P11x, P11y];hold on;plot(P11(1),P11(2),'gp','MarkerSize', 12);
% 计算1中的点在2中对应的单应性点
P22 = WarpH(P11,H);
figure(2)
imshow(H_Initial.img2);hold on;plot(P2(:,1),P2(:,2),'r.');
hold on;
plot(P22(1), P22(2), 'gp', 'MarkerSize', 12);
 
 
% 所需子函数
function H = CalcH(P1, P2)
x = P1(:, 1);
y = P1(:, 2);
X = P2(:, 1);
Y = P2(:, 2);
A = zeros(length(x(:))*2,9);
for i = 1:length(x(:)),
    a = [x(i),y(i),1];
    b = [0 0 0];
    c = [X(i);Y(i)];
    d = -c*a;
    A((i-1)*2+1:(i-1)*2+2,1:9) = [[a b;b a] d];
end
[U S V] = svd(A);
h = V(:,9);
H = reshape(h,3,3)';
end
% 子函数
function P2 = WarpH(P1, H);
x = P1(:, 1);
y = P1(:, 2);
p1 = [x'; y'; ones(1, length(x))];
q1 = H*p1;
q1 = q1./[q1(3, :); q1(3,:); q1(3, :)];
 
P2 = q1';
end
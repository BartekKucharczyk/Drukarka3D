
% X=[200 -200 5000 3000 -5000 1000];
% Y=[-200 -200 5000 3000 -5000 1000];
% Z=[-200 -200 -5000 3000 5000 1000];

t=0:0.1:4*pi;
Xt = floor(100*sin(t+2*pi/3));
Yt = floor(100*sin(t+3*pi/3));
Zt = floor(100*sin(t+4*pi/3));

X = Xt(2:end) - Xt(1:end-1);
Y = Yt(2:end) - Yt(1:end-1);
Z = Zt(2:end) - Zt(1:end-1);

for i=1:length(X)

fprintf(s,'x %d y %d z %d \n',[X(i) Y(i) Z(i)])
while s.BytesAvailable == 0
end
while s.BytesAvailable >0
    answ = fscanf(s)
        
end 
%pause(0.3)
end

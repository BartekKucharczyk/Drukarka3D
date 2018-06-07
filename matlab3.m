figure(3)
x1=0;
y1=0;
z1=0;
x2=0;
y2=28;
z2=0;
x3=24;
y3=14;
z3=0;
kol1 = line([x1 x1],[y1 y1],[0 60])
kol2 = line([x2 x2],[y2 y2],[0 60])
kol3 = line([x3 x3],[y3 y3],[0 60])

view(-30,30)
axis([-10 50 -10 50 0 60])
axis square


xc = 12;
yc= 14;
zc =30;
r=20;
zsilnik1 = zc+sqrt(r^2-(x1-xc)^2-(y1-yc)^2);
zsilnik2 = zc+sqrt(r^2-(x2-xc)^2-(y2-yc)^2);
zsilnik3 = zc+sqrt(r^2-(x3-xc)^2-(y3-yc)^2);


ramie1 = line([xc x1],[yc y1],[zc zsilnik1])
get(ramie1)
ramie1.ZData

ramie2 = line([xc x2],[yc y2],[zc zsilnik2])
get(ramie2)
ramie2.ZData

ramie3 = line([xc x3],[yc y3],[zc zsilnik3])
get(ramie3)
ramie3.ZData

for t =0:0.1:2*pi
xc = 12+sin(t);
yc= 14+cos(t);
zc =30;

zsilnik1 = zc+sqrt(r^2-(x1-xc)^2-(y1-yc)^2);
zsilnik2 = zc+sqrt(r^2-(x2-xc)^2-(y2-yc)^2);
zsilnik3 = zc+sqrt(r^2-(x3-xc)^2-(y3-yc)^2);

ramie1.XData = [xc x1];
ramie1.YData = [yc y1];
ramie1.ZData = [zc zsilnik1];

ramie2.XData = [xc x2];
ramie2.YData = [yc y2];
ramie2.ZData = [zc zsilnik2];


ramie3.XData = [xc x3];
ramie3.YData = [yc y3];
ramie3.ZData = [zc zsilnik3];

if (t>0)
kroki1 = round(200*(zsilnik1-stare1));
kroki2 = round(200*(zsilnik2-stare2));
kroki3 = round(200*(zsilnik3-stare3));

fprintf(s,'x %d y %d z %d \n',[kroki1 kroki2 kroki3])

while s.BytesAvailable == 0
end
while s.BytesAvailable >0
    answ = fscanf(s)
        
end 
end
stare1 = zsilnik1;
stare2 = zsilnik2;
stare3 = zsilnik3;
drawnow;  % wymuszenie wizualizacji w czasie rzeczywistym
end



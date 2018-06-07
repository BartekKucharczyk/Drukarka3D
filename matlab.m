
if ~ exist('s' , 'var')
s = serial('/dev/ttyUSB0');
s.BaudRate=57600;
end

if s.statfus(1)=='c'
%s.newline=CR;
fopen(s);
end


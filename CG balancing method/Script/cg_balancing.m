
clear all
clc

Xgboard = 0;
Zgboard = 0;
mboard = 2190;

Xghold = 0;
Zghold = 0;
mhold = 644;

Xgsphere = 0;
Zgsphere = 0;
msphere = 229;

Xgplat = 23.02;
Zgplat = 63.94;
mplat = 2300;

XgIRfront = 5.51;
ZgIRfront = -140.78;
mIRfront = 327;

XgIRside = -140.78;
ZgIRside = -5.51;
mIRside = 327;

Xglick = -104.65;
Zglick = 45.90;
mlick = 307;

Xghead = 0.47;
Zghead = 111.03;
mhead = 523;

Xgcam = 123.63;
Zgcam = 32.30;
mcam = 347;

Xgpostextra1 = 98.46;
Zgpostextra1 = -66.09;
mpostextra1 = 599;

Xgpostextra2 = -48.65;
Zgpostextra2 = -129.21;
mpostextra2 = 599;

mpostextra3 = 599;

vm = [mboard, mhold, msphere, mplat, mIRfront, mIRside, mlick, mhead, mcam, mpostextra1, mpostextra2];
x_coor = [Xgboard, Xghold, Xgsphere, Xgplat, XgIRfront, XgIRside, Xglick, Xghead, Xgcam, Xgpostextra1, Xgpostextra2];
z_coor = [Zgboard, Zghold, Zgsphere, Zgplat, ZgIRfront, ZgIRside, Zglick, Zghead, Zgcam, Zgpostextra1,Zgpostextra2];


% Calculate the initial values for the x coordinates

sumatoryx = x_coor.*vm;
sumatoryx2 = sum(sumatoryx);
Xgpostextra3 = -sumatoryx2/mpostextra3;

% Calculate the initial values for the y coordinates

sumatoryz = z_coor.*vm;
sumatoryz2 = sum(sumatoryz);
Zgpostextra3 = -sumatoryz2/mpostextra3;

% Display the result 

x=0;
y=0;
r=149;
th = 0:pi/100:2*pi;
a = r*cos(th)+x;
b = r*sin(th)+y;
plot(a,b, 'g');
hold on
plot(Xgpostextra3,-Zgpostextra3,'bo'); %The Z coordinate is negative because the solidworks coordinates system is inverted
xlabel('mm')
ylabel('mm')
axis equal

Xgpostextra3
Zgpostextra3
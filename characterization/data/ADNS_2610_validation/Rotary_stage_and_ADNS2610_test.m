clc
clear all

% Import data from the test1.txt file
data = importdata('TEST1.txt');
SQUAL = data(:,1);
mouse_internal_units = data(:,2);
desired_position = data(:,3);
actual_position = data(:,4);
t_millis = data (:,5);
t_s = t_millis/1000;

% Derivative of the signal to count the revolutions
d_mouse_units = gradient(mouse_internal_units(5857:26546));
plot(d_mouse_units);
rev = 30;

% Mouse units per revolution
mouse_units_revolution = mouse_internal_units(26546)/rev;


% Histogram go the SQUAL value distribution
histogram(SQUAL);
title('ADNS 2610 SQUAL value distribution')
xlabel('Samples')
ylabel('SQUAL value')
xlim([0,130]);

% SQUAL value vs delta

delta = diff(mouse_internal_units);
SQUAL = SQUAL(1:32431);
s = scatter(abs(delta),SQUAL);
title('ADNS 2610 SQUAL value vs relative optical sensor masurements')
xlabel('relative displacement(mouse interna units)')
ylabel('SQUAL value')
ylim([0,130]);
s.LineWidth = 0.4;
s.MarkerEdgeColor = 'b';
s.MarkerFaceColor = [0 0.5 0.5];

%SQUAL value average

av_SQUAL = mean(SQUAL);
SD_SQUAL = std(SQUAL);



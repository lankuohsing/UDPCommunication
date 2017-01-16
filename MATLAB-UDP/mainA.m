clear all;
close all
clc;

%% Define computer-specific variables
ipA = '166.111.74.115';   portA = 9090;   % Modify these values to be those of your first computer.
ipB = '10.200.129.151';  portB = 9091;  % Modify these values to be those of your second computer.
%% Create UDP Object
udpA = udp(ipB,portB,'LocalPort',portA);
%% Connect to UDP Object
fopen(udpA)
%%
fprintf(udpA,'This is test message number one.')
fprintf(udpA,'This is test message number two.')
fprintf(udpA,'doremifasolatido')
function varargout = receive(varargin)
%RECEIVE M-file for receive.fig
%      RECEIVE, by itself, creates a new RECEIVE or raises the existing
%      singleton*.
%
%      H = RECEIVE returns the handle to a new RECEIVE or the handle to
%      the existing singleton*.
%
%      RECEIVE('Property','Value',...) creates a new RECEIVE using the
%      given property value pairs. Unrecognized properties are passed via
%      varargin to receive_OpeningFcn.  This calling syntax produces a
%      warning when there is an existing singleton*.
%
%      RECEIVE('CALLBACK') and RECEIVE('CALLBACK',hObject,...) call the
%      local function named CALLBACK in RECEIVE.M with the given input
%      arguments.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help receive

% Last Modified by GUIDE v2.5 23-Apr-2010 16:17:18

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @receive_OpeningFcn, ...
                   'gui_OutputFcn',  @receive_OutputFcn, ...
                   'gui_LayoutFcn',  [], ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
   gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before receive is made visible.
function receive_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   unrecognized PropertyName/PropertyValue pairs from the
%            command line (see VARARGIN)

% Choose default command line output for receive
handles.output = hObject;
global zh r
zh=0;
r=0;
ipA='127.0.0.1'; 
portA=9090;
ipB='127.0.0.1';
portB=9091;
handles.udpB=udp(ipA,portA,'LocalPort',portB);
set(handles.udpB,'TimeOut',100);
 set(handles.udpB,'InputBufferSize',8192);
fopen(handles.udpB);
% Update handles structure
guidata(hObject, handles);

% UIWAIT makes receive wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = receive_OutputFcn(hObject, eventdata, handles)
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on button press in pushbutton1.
function pushbutton1_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global  zh r
n=zh+1;
 r=get(handles.udpB,'BytesAvailable')
for t=1:20

a1=str2num(fscanf(handles.udpB));
a2=str2num(fscanf(handles.udpB));
a3=str2num(fscanf(handles.udpB));
a4=str2num(fscanf(handles.udpB));
a5=str2num(fscanf(handles.udpB));
a6=str2num(fscanf(handles.udpB));
set(handles.text1,'string',a1);
set(handles.text3,'string',a2);
set(handles.text4,'string',a3);
set(handles.text5,'string',a4);
set(handles.text6,'string',a5);
set(handles.text7,'string',a6);
zh=t;
pause(0.05);
%fprintf(handles.udpB,a1);
%fprintf(handles.udpB,a2);
%fprintf(handles.udpB,a3);
%fprintf(handles.udpB,a4);
%fprintf(handles.udpB,a5);
%fprintf(handles.udpB,a6);
end
% --- Executes on button press in pushbutton2.
function pushbutton2_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global zh r
zh=0;
r=0;
fclose(handles.udpB);
delete(handles.udpB);
clear ipA portA ipB portB
close();


% --- Executes on button press in re.
function re_Callback(hObject, eventdata, handles)
% hObject    handle to re (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


#pragma once
#include<stdio.h>
#include<windows.h>
#include<mmsystem.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include<unistd.h>


/*【定义一些地图显示】 
* @sleepTime: 等待时间 
* @autoPlay：是否自动播放 
* @wall: 墙 
* @pillar：柱子 
* @hanoiLeft：汉诺塔圆盘左边显示 
* @hanoiRight：汉诺塔圆盘右边显示 
* @hanoiAir：汉诺塔圆盘中间镂空部分显示 
*/  
int sleepTime = 30; //默认一倍速 
const char wall = '*';  
const char pillar = '|'; 
const char hanoiLeft = '['; 
const char hanoiRight = ']'; 
const char hanoiAir = '-'; 
const int up = 0,down = 1,left = 2,right = 3; 

const char red[] = "\033[31m";   // 红色
const char blue[] = "\033[34m";  // 蓝色
const char reset[] = "\033[0m";  // 重置颜色

/*【控制移动】 
* @next_go 下一次移动方向 上0下1左2右3；
*/ 
int next_go[4][2] = {{0,-1},{0,1},{-1,0},{1,0}}; 
int autoPlay= 1;//默认自动播放 ,autoPlay 设置为 1

/*【系统变量】 
* @abc_pillar[3][1000] 当前柱子放置的圆盘数
	[i][0]存放第i个柱子当前高度 
*   [i][j]表示第i个柱子第j层存放的圆盘大小 
*   @abc_x[3] abc柱子的坐标 
*  数组可以直接通过 ABC - 'A' 直接获取下标取值
 
*/  
int loop = 1;//主菜单循环打印条件 
int N=3;//默认圆盘为3;
int option;
int abc_pillar[3][1000] = {{0},{0},{0}};
int abc_x[3] = {0,0,0}; 
int mapHeight,mapWidth; 
int deep;
int coloreset;
int steps;

//code —密码
// key —钥匙 
//1.用来统计功能使用次数
//2.用于开始键，确定是否输出“请按回车键开始 ” 
//3.在测试期间 可测试某一功能运行的开始与结束
//4.粗略模仿网络安全密钥的方式，当密码与钥匙对应时，才打印开始键 
//5.使主函数尽可能简单，并且保证在多次运行后 
int code1=0; 
int key1=0; 
int code2=0;
int key2=0;
int code3=0; 
int key3=0; 
int code4=0;
int key4=0; 

//MAIN.cpp文件函数声明
void dectction();
void gotoxy(int x,int y);
void HideCursor();
void drawHanoi(int &x,int &y,int n,int next);
void init();
void clearPillar(int pillarIndex);
void move(char from,char to);
void hanoi(int n,char from ,char temp,char to);
void pillarhanoi(int n, char source, char temp, char goal);

//Color.h文件函数声明
void drawColor(int &x,int &y, int n,int next);
void colorinit();
void colormove(char from,char to);
void colorhanoi(int n,char from ,char temp,char to);
void parityinit();
void paritymove(int n, char source, char temp, char target);
void parityhanoi(int n, char source, char temp, char target);

//Menu.h文件函数声明
void start_up();
void beginner();
int menu();
int speedMenu();
void Help();
int scaHelp();
void printAbout();
void conclusion();
void printBlank(int n);

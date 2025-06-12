#pragma once
#include<stdio.h>
#include<windows.h>
#include<mmsystem.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include<unistd.h>


/*������һЩ��ͼ��ʾ�� 
* @sleepTime: �ȴ�ʱ�� 
* @autoPlay���Ƿ��Զ����� 
* @wall: ǽ 
* @pillar������ 
* @hanoiLeft����ŵ��Բ�������ʾ 
* @hanoiRight����ŵ��Բ���ұ���ʾ 
* @hanoiAir����ŵ��Բ���м��οղ�����ʾ 
*/  
int sleepTime = 30; //Ĭ��һ���� 
const char wall = '*';  
const char pillar = '|'; 
const char hanoiLeft = '['; 
const char hanoiRight = ']'; 
const char hanoiAir = '-'; 
const int up = 0,down = 1,left = 2,right = 3; 

const char red[] = "\033[31m";   // ��ɫ
const char blue[] = "\033[34m";  // ��ɫ
const char reset[] = "\033[0m";  // ������ɫ

/*�������ƶ��� 
* @next_go ��һ���ƶ����� ��0��1��2��3��
*/ 
int next_go[4][2] = {{0,-1},{0,1},{-1,0},{1,0}}; 
int autoPlay= 1;//Ĭ���Զ����� ,autoPlay ����Ϊ 1

/*��ϵͳ������ 
* @abc_pillar[3][1000] ��ǰ���ӷ��õ�Բ����
	[i][0]��ŵ�i�����ӵ�ǰ�߶� 
*   [i][j]��ʾ��i�����ӵ�j���ŵ�Բ�̴�С 
*   @abc_x[3] abc���ӵ����� 
*  �������ֱ��ͨ�� ABC - 'A' ֱ�ӻ�ȡ�±�ȡֵ
 
*/  
int loop = 1;//���˵�ѭ����ӡ���� 
int N=3;//Ĭ��Բ��Ϊ3;
int option;
int abc_pillar[3][1000] = {{0},{0},{0}};
int abc_x[3] = {0,0,0}; 
int mapHeight,mapWidth; 
int deep;
int coloreset;
int steps;

//code ������
// key ��Կ�� 
//1.����ͳ�ƹ���ʹ�ô���
//2.���ڿ�ʼ����ȷ���Ƿ�������밴�س�����ʼ �� 
//3.�ڲ����ڼ� �ɲ���ĳһ�������еĿ�ʼ�����
//4.����ģ�����簲ȫ��Կ�ķ�ʽ����������Կ�׶�Ӧʱ���Ŵ�ӡ��ʼ�� 
//5.ʹ�����������ܼ򵥣����ұ�֤�ڶ�����к� 
int code1=0; 
int key1=0; 
int code2=0;
int key2=0;
int code3=0; 
int key3=0; 
int code4=0;
int key4=0; 

//MAIN.cpp�ļ���������
void dectction();
void gotoxy(int x,int y);
void HideCursor();
void drawHanoi(int &x,int &y,int n,int next);
void init();
void clearPillar(int pillarIndex);
void move(char from,char to);
void hanoi(int n,char from ,char temp,char to);
void pillarhanoi(int n, char source, char temp, char goal);

//Color.h�ļ���������
void drawColor(int &x,int &y, int n,int next);
void colorinit();
void colormove(char from,char to);
void colorhanoi(int n,char from ,char temp,char to);
void parityinit();
void paritymove(int n, char source, char temp, char target);
void parityhanoi(int n, char source, char temp, char target);

//Menu.h�ļ���������
void start_up();
void beginner();
int menu();
int speedMenu();
void Help();
int scaHelp();
void printAbout();
void conclusion();
void printBlank(int n);

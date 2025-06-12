/*------------------------------------
项目 ： 汉诺塔演示软件实现最少的移动次数 
目标 ： 设计算法 用最少的移动次数将塔座 A 上的 n 个圆盘移到塔座 C 上，并仍按同样顺序叠置。 
编译环境 ： Dev-C++ 5.11
文件 ：主程序共包括MAIN.cpp， Color.h，menu.h ，variable.h四个文件 
开发人 ：绳金塔小组 （3人） 
-------------------------------------*/ 
#include"variable.h"//头文件、全局变量与函数声明 
#include"menu.h"    //菜单文件 
#include"Color.h"   //颜色绘制文件 


int main()
{
	start_up();
	beginner(); 
    while (loop) {
        system("cls");
        option=menu();
        switch (option) {
        case 1:
            HideCursor();
            do{
			printf("需要叠的层数:");
            scanf("%d", &N);
            if(N<=0) {
            	printf("输入错误!\n\n");
            	// 清除输入缓冲区，避免无效输入影响下一次循环
            	while (getchar() != '\n') continue;
				}
            }while(N<=0);
            break;
            
        case 2:
            int mode;
			do {
        	printf("请输入你要选择的模式,[1]手动[2]自动\n");
        	scanf("%d", &mode);
        	if (mode == 1) autoPlay = 0; 	  // 用户选择手动模式，autoPlay 设置为 0
        	else if (mode == 2) autoPlay = 1; // 用户选择自动模式，autoPlay 设置为 1
        	else {
            	printf("输入错误!\n\n");
            	// 清除输入缓冲区，避免无效输入影响下一次循环
            	while (getchar() != '\n') continue;
        		}
    		} while (mode != 1 && mode != 2);
            break;
            
		case 3:
    		init();
    		getchar();
    		hanoi(N, 'A', 'B', 'C');
    		break;
    		
        case 4:
            init();
            getchar();
			pillarhanoi(N, 'A', 'B', 'C');
            break;

        case 5:
            coloreset=0;// 重置颜色
            colorinit();
            getchar();
            colorhanoi(N, 'A', 'B','C');
            break;
            
        case 6:
        	dectction();//判断盘数是否正确 
            coloreset=0;// 重置颜色		
            parityinit();
            getchar();
            parityhanoi(N, 'A', 'B','C');
            break; 
            
        case 7:
        	speedMenu();
        	getchar();
        	break;
        	
        case 8:
        	Help();
            break;
            
        case 9:
        	printAbout();
        	break;
        
        case 0:
        	conclusion();
            break;
            
        default:
        	break;

        }
    }
    return 0;
}


void dectction(){
	if(N % 2 == 1) {
		getchar();
		printf("该模式下，您的圆盘数必须为偶数,详细信息请看“规则说明”\n\n");
		do{
			printf("修改需要叠的层数:");
            scanf("%d", &N);
            if(N<=0||N % 2 == 1) {
            	printf("输入错误!\n\n");
            	// 清除输入缓冲区，避免无效输入影响下一次循环
            	while (getchar() != '\n') continue;
			}
        }while(N<=0||N % 2 == 1);
	}
}

// 指定光标跳转到x，y的坐标处
// 水平x，竖直y 
void gotoxy(int x,int y)  
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle,pos);
} 


//定义隐藏光标函数
void HideCursor()
{
    CONSOLE_CURSOR_INFO cursor;    
    cursor.bVisible = FALSE;    
    cursor.dwSize = sizeof(cursor);    
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);    
    SetConsoleCursorInfo(handle, &cursor);
}


//清空x，y地方的绘制
//并且绘制下一处 长度为n 的汉诺塔 
void drawHanoi(int &x,int &y,int n,int next)
{
    // 清空原来的 
    char replace[2*n+1] = ""; 
    for(int i = 0; i < 2*n + 1; i++){
        replace[i] = ' ';
        if(i == n && y != 1){
            replace[i] = pillar;
        }
        if(i == 2*n){
            replace[i+1] = '\0';
        }
    }
    gotoxy(x - n,y);
    printf("%s",replace); 
    // 绘制新的 
    if(next != -1){
        x += next_go[next][0];
        y += next_go[next][1];	
    }
    for(int i = 0; i < 2*n + 1; i++){
        if(i == n && y != 1){
            replace[i] = pillar;
        }else if(i == 0){
            replace[i] = hanoiLeft;
        }else if(i == 2*n){
            replace[i] = hanoiRight;
        }else{
            replace[i] = hanoiAir;
        }
        if(i == 2*n){
            replace[i+1] = '\0';
        }
    }
    gotoxy(x - n,y);
    printf("%s",replace); 
    Sleep(sleepTime);
}

void init()
{
	steps=0;
	system("cls");
   	HideCursor();
    // 初始化柱子信息 
    abc_pillar[0][0] = N;
    for(int i = 1; i <= N; i++ ){
        abc_pillar[0][i] = N + 1 - i;
    }
    //高度 = 上下墙(2) + deep(4) + 上空行(1) 
    //宽度 = 左右墙(2) + 3个区块[3*(deep*2+1)] + 两个中间空行(2)
    mapHeight = 2 + N + 1;
    mapWidth = 2 + 3 * (N * 2 + 1) + 2;
    
    //柱子0(a)水平坐标 = 左边墙(1) + deep(4) 
    //柱子1(b)水平坐标 = 柱子1 + 2*deep + 2 
    //柱子2(c)水平坐标 = 柱子2 + 2*deep + 2 
    abc_x[0] = 1 + N;
    abc_x[1] = abc_x[0] + 2* N + 2;
    abc_x[2] = abc_x[1] + 2* N + 2;
    
    // 绘制地图
    for(int i = 0; i < mapHeight; i++){
        for(int j = 0; j < mapWidth; j++){
            //墙体绘制 
            if(i == 0 || i == mapHeight - 1 || j == 0 || j == mapWidth - 1){
                gotoxy(j,i);
                printf("%c",wall);
            }
            //绘制柱子
            else if( i > 1 && i < mapHeight - 1){
                if(j == abc_x[0] || j == abc_x[1] || j == abc_x[2]){
                    //初始化绘制圆盘
                    int abc_x_index = 0;
                    if(j == abc_x[0]) abc_x_index = 0;
                    else if(j == abc_x[1]) abc_x_index = 1;
                    else if(j == abc_x[2]) abc_x_index = 2;
                    drawHanoi(j,i,abc_pillar[abc_x_index][N - i + 2],-1);
                }
            }
        }
    } 
}




// a ==> c 
// startx starty == > toX toY

void move(char from,char to)
{
    gotoxy(0,mapHeight+1); 
    printf("%c--->%c\n",from,to); 
    // 获取from的柱子有多少高定位从哪开始 
    int fromHeight = abc_pillar[from-'A'][0];
    int n = abc_pillar[from-'A'][fromHeight];
    int x = abc_x[from-'A'];
    int y = 2 + N - fromHeight;
    abc_pillar[from-'A'][0]--;
    // 获取to 的柱子有多高 定位到哪结束 
    abc_pillar[to-'A'][0]++;
    int toHeight = abc_pillar[to-'A'][0];
    abc_pillar[to-'A'][toHeight] = n;
    int toX = abc_x[to-'A'];
    int toY = 2 + N - toHeight;
    // 取出盘 ==> 上升至顶部 
    while(y > 1){
        drawHanoi(x,y,n,up);
    }
    // 移动盘 ==> 移动至指定盘 
    if(x < toX){
        while(x < toX){
            drawHanoi(x,y,n,right);
        }
    }else if(x > toX){
        while(x > toX){
            drawHanoi(x,y,n,left);
        }
    }
    // 放置盘 ==> 下降到上面 
    while(y < toY){
        drawHanoi(x,y,n,down);
    }
    //手动播放 
    if(autoPlay == 0){
        gotoxy(0,mapHeight+3); 
        printf("请按回车进行下一步. . ."); 
        getchar(); 
    } 
    steps++;
}


/**
* from 从哪开始 
* temp 暂时经过 
* to   移动到哪  
*/
void hanoi(int n,char from ,char temp,char to)
{
    if(n==1){           // from到to只有一个需要移动就直接移动 
    	if(key1== code1){
        gotoxy(0,mapHeight+3);
        printBlank(50);
        gotoxy(0,mapHeight+3);
        printf("请按回车键开始\n");
        getchar();
        gotoxy(0,mapHeight+3);
        printBlank(30);
        key1++;
    	} 
        move(from, to); //递归截止条件
    }
    else{
        hanoi(n-1,from ,to,temp); //移动from 上面的n-1 ==> temp 暂存 
        move(from,to);            //移动from 剩下的1   ==> to   目的地 
        hanoi(n-1,temp,from,to);  //移动temp 暂存的n-1 ==> to   目的地 
    }
    // 动画结束后清除所有柱子上的圆盘
   if(n==N){
   	code1++;
    clearPillar(0);// 清除A柱子
    clearPillar(1);// 清除B柱子
    clearPillar(2);// 清除C柱子
    gotoxy(0, mapHeight + 3);
    printf("  动画结束,共移动了%d步。\n按R重复播放，按任意键退出. . .",steps);
	char choice = getch(); // 获取用户的选择
        if (choice == 'R' || choice == 'r') {
        	system("cls");
    		HideCursor();
    		init();
    		hanoi(N, 'A', 'B', 'C');
    		
        }    
	} 
}

void pillarhanoi(int n, char source, char temp, char goal)
{
	
    if (n == 1) {
    	if(key2== code2){
        gotoxy(0,mapHeight+3); 
        printf("请按回车键开始\n");
        getchar();
        gotoxy(0,mapHeight+3);
        printBlank(30);
		key2++;
    	} 
        move( source, temp);
        move( temp, goal);
        
    }
    else {
        pillarhanoi(n - 1, source, temp, goal);
        move( source, temp);
        pillarhanoi(n - 1, goal, temp, source);
        move(temp, goal);
        pillarhanoi(n - 1, source, temp, goal);
    }
    // 动画结束后清除所有柱子上的圆盘
	if(n==N){
		code2++;
		clearPillar(0); // 清除A柱子
    	clearPillar(1); // 清除B柱子
    	clearPillar(2); // 清除C柱子
    	gotoxy(0, mapHeight + 3);
    	printf("  动画结束,共移动了%d步。\n按R重复播放，按任意键退出. . .",steps);
		char choice = getch(); // 获取用户的选择
        if (choice == 'R' || choice == 'r') {
        	system("cls");
    		HideCursor();
    		init();
    		pillarhanoi(N, 'A', 'B', 'C');
    		
        }    
	}  
}

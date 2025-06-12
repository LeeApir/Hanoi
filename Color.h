#pragma once
#include"variable.h"

// 清除指定柱子上的所有圆盘
void clearPillar(int pillarIndex)
{
    for (int i = 0; i <= N; i++) {
        abc_pillar[pillarIndex][i] = 0;
    }
    abc_pillar[pillarIndex][0] = 0; // 重置柱子的高度
}

void drawColor(int &x,int &y, int n,int next){
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
	if(option == 6 && n % 2 == 0){	
	//当功能6时，偶数盘的大小减一    
    	for(int i = 1; i < 2*n + 0; i++){
        	if(i == n && y != 1){
            	replace[i] = pillar;
        	}else if(i == 0+1){
           		replace[i] = hanoiLeft;
        	}else if(i == 2*n-1){
            	replace[i] = hanoiRight;
        	}else{
            	replace[i] = hanoiAir;
        	}
        	if(i == 2*n){
            	replace[i+1] = '\0';
        	}
    	}
	}else{
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
	}
	
    // 根据圆盘编号决定颜色
    if(n % 2 == 0) { // 偶数号圆盘着红色
        printf("%s", red);
    } 
	else { // 奇数号圆盘着蓝色
        printf("%s", blue);
    }
	
    gotoxy(x - n,y);
    printf("%s",replace); 
    printf("%s", reset); // 重置颜色
	// 重置柱子B和柱子C的颜色
    if(coloreset<=N*3){
    	
		for(int i = 1; i < mapHeight - 2; i++) {
        	gotoxy(abc_x[1], i+1);
        	printf("%c", pillar); // 重置柱子B
        	gotoxy(abc_x[2], i+1);
        	printf("%c", pillar); // 重置柱子C
    	}
	coloreset++;
	
	}
    Sleep(sleepTime);
    
}

void colorinit(){
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
                    drawColor(j,i,abc_pillar[abc_x_index][N - i + 2],-1);
                }
            }
        }
    } 
}


void colormove(char from,char to){
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
        drawColor(x,y,n,up);
    }
    // 移动盘 ==> 移动至指定盘 
    if(x < toX){
        while(x < toX){
            drawColor(x,y,n,right);
        }
    }else if(x > toX){
        while(x > toX){
            drawColor(x,y,n,left);
        }
    }
    // 放置盘 ==> 下降到上面 
    while(y < toY){
        drawColor(x,y,n,down);
    }
    //手动播放 
    if(autoPlay == 0){
        gotoxy(0,mapHeight+3); 
        printf("请按回车进行下一步"); 
        getchar(); 
    } 
    steps++; 
}

/*
* from 从哪开始 
* temp 暂时经过 
* to   移动到哪 
*/
void colorhanoi(int n,char from ,char temp,char to){
    if(n==1){           // from到to只有一个需要移动就直接移动 
    	if(key3== code3){
    		gotoxy(0,mapHeight+3);
        	printBlank(50);
        	gotoxy(0,mapHeight+3);
        	printf("请按回车键开始\n");
        	getchar();
        	gotoxy(0,mapHeight+3);
        	printBlank(30);
        	key3++;
    	} 
        colormove(from, to); //递归截止条件
    }
    else{
        colorhanoi(n-1,from ,to,temp); //移动from 上面的n-1 ==> temp 暂存 
        colormove(from,to);            //移动from 剩下的1   ==> to   目的地 
        colorhanoi(n-1,temp,from,to);  //移动temp 暂存的n-1 ==> to   目的地 
    }
    // 动画结束后清除所有柱子上的圆盘
   if(n==N){
   		code3++;
    	clearPillar(0);// 清除A柱子
    	clearPillar(1);// 清除B柱子
    	clearPillar(2);// 清除C柱子
    	gotoxy(0, mapHeight + 3);
    	printf("  动画结束,共移动了%d步。\n按R重复播放，按任意键退出. . .",steps);
		char choice = getch(); // 获取用户的选择
        if (choice == 'R' || choice == 'r') {
        	system("cls");
    		coloreset=0;//重置后两个柱子的颜色 
    		colorinit();
    		colorhanoi(N, 'A', 'B', 'C');
    		
        }    
	} 
}

void parityinit(){
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
                    drawColor(j,i,abc_pillar[abc_x_index][N - i + 2],-1);
                }
            }
        }
    } 
}


//借助递归思想进行递回-移动
void paritymove(int n, char source, char temp, char target){ 
    if (n == 1){
    	if(key4== code4){
    		gotoxy(0,mapHeight+3);
        	printBlank(50);
        	gotoxy(0,mapHeight+3);
        	printf("请按回车键开始\n");
        	getchar();
        	gotoxy(0,mapHeight+3);
        	printBlank(30);
        	key4++;
    	}
    	colormove(source, target);
    	colormove(source, target);
    }else {
        paritymove(n-1, source, target, temp); 
        paritymove(1, source, temp, target); 
        paritymove(n-1, temp, source, target);
    	} 
	
}

void parityhanoi(int n, char source, char temp, char target){ 
    for(int i = n / 2; i > 1; i--){
        paritymove(i-1, source, temp, target);
        colormove(source, temp);
    	colormove(source, temp);
        paritymove(i-1, target, temp, source);
        colormove(temp, target);
    }
	colormove(source, temp);
    colormove(source, target);
    //动画结束 
   	code4++;
    clearPillar(0);// 清除A柱子
    clearPillar(1);// 清除B柱子
    clearPillar(2);// 清除C柱子
    gotoxy(0, mapHeight + 3);
    printf("  动画结束,共移动了%d步。\n按R重复播放，按任意键退出. . .",steps);
	char choice = getch(); // 获取用户的选择
    if (choice == 'R' || choice == 'r') {
        system("cls");
    	coloreset=0;
    	parityinit();
    	parityhanoi(N, 'A', 'B', 'C');
    }
    	
}


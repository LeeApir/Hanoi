  #pragma once
#include"variable.h"

void start_up()
{
	HideCursor();
	printBlank(30);
    printf("  *                           *       *    *    *    \n");
    printBlank(30);
    printf("   *   *********   *      *   **      *    *    *    \n");
    printBlank(30);
    printf("   *   *      *    **     *   *       *  ************\n");
    printBlank(30);
    printf("      * *     *     *  ***** ******   *    *    *    \n");
    printBlank(30);
    printf("*    *  *     *           * * *       *    *  * *    \n");
    printBlank(30);
    printf(" *   *  *    *            * ****    *****    **      \n");
    printBlank(30);
    printf("  * *   *    *    ***      **         *     ** *     \n");
    printBlank(30);
    printf("    *    *   *      *  ************   *     *   *    \n");
    printBlank(30);
    printf("    *    *  *       *      *          *    *     **  \n");
    printBlank(30);
    printf("   *     *  *       *     *           *   ***********\n");
    printBlank(30);
    printf("   *      **        *     *******     *  *         * \n");
    printBlank(30);
    printf(" **       **        *    **     *     *              \n");
    printBlank(30);
    printf("  *      ** *       * * ***     *     * ** *******   \n");
    printBlank(30);
    printf("  *     **  **      **  * *     *    ***   *     *   \n");
    printBlank(30);
    printf("  *    *     ***    *  *  *     *  **      *     *   \n");
    printBlank(30);
    printf("  *  **        ***  * *   *******          *******   \n");
    printBlank(30);
    printf("*                                                    \n");
    int total = 100; // 总进度
    int current = 0; // 当前进度
    int bar_length = 50; // 进度条的长度

    printf("Progress: [");

    for (int i = 0; i < total; i++) {
        usleep(10000); // 模拟进度更新
        current++;
        // 将光标回移到原始位置后打印进度条
        COORD coord;
        coord.X = 0; // 设置 X 坐标为 0 (假设 ASCII 艺术从列 0 开始)
        coord.Y = 17; // 设置 Y 坐标为 1 (假设 ASCII 艺术在当前行的下一行)
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		printBlank(25);
        printf("Progress: [");
        for (int j = 0; j < bar_length; j++) {
            if (j * (total / bar_length) <= current) {
                printf("-"); // 填充进度条
            } else {
                printf(" "); // 留空格
            }
        }
        printf("] %d%%\r", current);
        if(current==10){
        	gotoxy(0,20);
        	printBlank(44);
        	printf("此程序由绳金塔小组精心制作");
		}
        else if(current==45){
        	gotoxy(0,22); 
        	printBlank(43);
        	printf("制作人员：刘世仁 胡峻铭 冯鑫");
		}
        fflush(stdout);
    }
    
}

// 新手指南函数
void beginner() {
	system("cls");
	printBlank(45);
    printf("《新手指南》\n\n");
    printf("【软件介绍】\n");
    printf("汉诺塔是一个经典的递归问题，目标是在遵守特定规则的情况下，将所有圆盘从一个柱子移动到另一个柱子。本软件旨在通过动画演示，帮助您理解汉诺塔问题的解决方案。\n\n");
    printf("【如何开始】\n");
    printf("- 设置圆盘层数：在主菜单选择“设置圆盘层数”，输入您想要挑战的层数。\n");
    printf("- 选择播放方式：在主菜单选择“播放方式”，然后选择“手动”或“自动”模式。\n");
    printf("- 选择汉诺塔模式：在主菜单选择观看模式，然后选择想要观看的限制模式。\n\n");
    printf("【游戏玩法】\n");
    printf("- 游戏目标：将所有圆盘从起始柱子移动到目标柱子。\n- 游戏规则：每次只能移动一个圆盘，且不能将较大的圆盘放在较小的圆盘上面。\n");
    printf("- 基本操作：在手动模式下，您需要按回车键来执行移动一次圆盘。\n\n");
    printf("【动画演示】\n");
    printf("- 观察动画演示，了解圆盘的移动过程。在自动模式下，动画将自动播放；在手动模式下，您可以通过按回车键控制动画的播放。\n\n");
    printf("【退出游戏】\n");
    printf("- 要退出游戏，请在主菜单选择“结束使用”。\n\n");
    printf("【反馈和支持】\n");
    printf("- 如果您有任何问题或建议，请通过“关于”[反馈渠道]联系我们。\n\n");
    printBlank(40);
    printf("按任意键开始,祝您游戏愉快！\n");
    HideCursor();
    getch(); // 等待用户按键继续
}


int menu() {
	system("cls");
	printBlank(32);
	printf("这里是绳金塔组的汉诺塔实验,欢迎您的使用\n");
	printBlank(25);
	printf("******************************************************\n");
	printBlank(35);
	printf("[1]:设置圆盘层数\n");
	printBlank(35);
	printf("[2]:选择播放方式\n\n");
	printBlank(38);
	printf("欣 赏 汉 诺 塔 动 画\n");
	printBlank(35);
	printf("[3]:一般模式\n");
	printBlank(35);
	printf("[4]:不跨柱制模式\n");
	printBlank(35);
	printf("[5]:颜色限制模式\n");
	printBlank(35);
	printf("[6]:奇偶盘分离模式\n\n");
	printBlank(35);
	printf("[7]:调整播放速度\n");
	printBlank(35);
	printf("[8]:规则说明\n");
	printBlank(35);
	printf("[9]:关于程序\n");
	printBlank(35);
	printf("[0]:结束使用\n");
	printBlank(25);
	printf("******************************************************\n");
	printBlank(35);
	printf("请输入选项\n\b\b\b");
	printf("功能:");
	do{
		scanf("%d", &option);
		if(option<0||option>9){  //输入错误，数字必须在0到9之间
			printf("输入错误!\n\n");
			printf("请重新输入功能:");
		}
	}while(option<0||option>9);
	return option;
}

int speedMenu(){

	int speed;
	printBlank(30);
    printf("\n选择想要的播放速度：\n");
    printBlank(36);
    printf("1. 0.5倍速\n");
    printBlank(36);
    printf("2. 1.0倍速（默认）\n");
    printBlank(36);
    printf("3. 2.0倍速\n");
    printBlank(36);
    printf("4. 3.0倍速\n");
    printBlank(36);
    printf("5. 5.0倍速\n");
    printBlank(36);
    printf("6. 非常快(不建议)\n");
    printBlank(36);
    printf("0. 退出\n");
    printBlank(30);
    printf("请输入选项（0-6）：");
    
    do {
    	scanf("%d", &speed);
    	switch (speed) {
            case 1:
                sleepTime = 60;
                break;
            case 2:
                sleepTime = 30;
                break;
            case 3:
                sleepTime = 10;
                break;
            case 4:
                sleepTime = 5;
                break;
            case 5:
                sleepTime = 1;
                break;
            case 6:
            	sleepTime = 0;
                break;
            case 0:
                printf("退出程序。\n");
                break;
            default:
            	printBlank(30);
                printf("无效选项，请重新选择:");
                break;
        }
    } while (speed < 0||speed > 6);
}

void Help(){
	int x;
	int flag=1;
    system("cls");
    while (flag){
		system("cls");
        x=scaHelp();
        switch (x) {
            case 1:
            	system("cls");
            	HideCursor();
            	getchar();
                printf("【问题描述】\n\n");
    			printf("设 A、B、C 是 3 个塔座。开始时，在塔座 A 上有一叠共 n 个圆盘，这些圆盘自下而上，由大到小地叠在一起。\n");
    			printf("各圆盘从小到大编号为 1，2，……，n，奇数号圆盘着蓝色，偶数号圆盘着红色。\n\n");
    			printf("现要求将塔座 A 上的这一叠圆盘移到塔座 C 上，并仍按同样顺序叠置。在移动圆盘时应遵守以下移动规则：\n\n");
    			printf("规则(1)：每次只能移动 1 个圆盘；\n\n");
    			printf("规则(2)：任何时刻都不允许将较大的圆盘压在较小的圆盘之上；\n\n");
    			printf("规则(3)：在满足移动规则(1)-(2)的前提下，可将圆盘移至 A，B，C 中任一塔座上。\n\n");
    			printf("\n按回车键返回上一级 . . .");
    			getchar();
                break;
            case 2:
            	system("cls");
            	HideCursor();
            	getchar();
            	printf("【问题描述】\n\n");
            	printf("设 A、B、C 是 3 个塔座。开始时，在塔座 A 上有一叠共 n 个圆盘，这些圆盘自下而上，由大到小地叠在一起。\n");
            	printf("现要求将塔座 A 上的这一叠圆盘移到塔座 C 上，并仍按同样顺序叠置。在移动圆盘时应遵守以下移动规则：\n\n");
                printf("规则(1)：每次只能移动 1 个圆盘；\n\n");
                printf("规则(2)：任何时刻都不允许将较大的圆盘压在较小的圆盘之上；\n\n");
                printf("规则(3)：要求盘子只能在相邻的柱子之间移动，而不能直接从第一个柱子移动盘子到第三个柱子上，或从第三个柱子上直接移动到第一个柱子上\n\n");
                printf("规则(4)：在满足移动规则(1)-(3)的前提下，可将圆盘移至 A，B，C 中任一塔座上。\n\n");
                printf("\n按回车键返回上一级 . . .");
				getchar();
				break;
            case 3:
            	system("cls");
            	HideCursor();
            	getchar();
                printf("【问题描述】\n\n");
    			printf("设 A、B、C 是 3 个塔座。开始时，在塔座 A 上有一叠共 n 个圆盘，这些圆盘自下而上，由大到小地叠在一起。\n");
    			printf("各圆盘从小到大编号为 1，2，……，n，奇数号圆盘着蓝色，偶数号圆盘着红色。\n\n");
    			printf("现要求将塔座 A 上的这一叠圆盘移到塔座 C 上，并仍按同样顺序叠置。在移动圆盘时应遵守以下移动规则：\n\n");
    			printf("规则(1)：每次只能移动 1 个圆盘；\n\n");
    			printf("规则(2)：任何时刻都不允许将较大的圆盘压在较小的圆盘之上；\n\n");
    			printf("规则(3)：任何时刻都不允许将同色圆盘叠在一起；\n\n");
    			printf("规则(4)：在满足移动规则(1)-(3)的前提下，可将圆盘移至 A，B，C 中任一塔座上。\n\n");
    			printf("\n按回车键返回上一级 . . ."); 
				getchar();
                break;
            case 4:
            	system("cls");
            	HideCursor();
            	getchar();
                printf("【问题描述】\n\n");
    			printf("设 A、B、C 是 3 个塔座。开始时，在塔座 A 上有一叠共 2n 个圆盘，这些圆盘自下而上，两个圆盘为一组，由大到小地叠在一起。\n");
    			printf("各圆盘从小到大编号为 1，2，……，2n，奇数号圆盘着代表蓝色，偶数号代表圆盘着红色。\n\n");
    			printf("现要求将塔座 A 上的奇数圆盘移到塔座 B 上，而偶数圆盘移到塔座 C 上，并仍按同样顺序叠置。在移动圆盘时应遵守以下移动规则：\n\n");
    			printf("规则(1)：每次只能移动 1 个圆盘；\n\n");
    			printf("规则(2)：任何时刻都不允许将较大的圆盘压在较小的圆盘之上；\n\n");
    			printf("规则(4)：在满足移动规则(1)-(3)的前提下，可将圆盘移至 A，B，C 中任一塔座上。\n");
    			printf("\n按回车键返回上一级 . . ."); 
				getchar();
                break;
            case 0:
    			flag=0;
    			break;
            default:
                printf("无效选项，请重新选择。\n");
                break;
        }
   }
   
}

int scaHelp(){
	int x;
	system("cls");
    printBlank(35);
    printf("   汉诺塔实验规则说明\n");
    printBlank(25);
    printf("******************************************************\n");
    printBlank(30);
    printf("[1]:一般模式规则\n");
    printBlank(30);
    printf("[2]:跨柱限制模式规则\n");
    printBlank(30);
    printf("[3]:颜色限制模式规则\n");
    printBlank(30);
    printf("[4]:奇偶盘分离模式规则\n");
    printBlank(30);
    printf("[0]:返回主菜单\n");
    printBlank(25);
    printf("******************************************************\n");
    printBlank(30);
    printf("请输入选项\n\b\b\b");
    printf("选项:");
	scanf("%d", &x);
	while(x < 0 || x > 4) {
        //printf("输入错误!\n\n");
        printf("无效选项，请重新选择:");
        scanf("%d", &x);
    }
    return x;
}

void printAbout() {
	HideCursor();
	system("cls");
    printf("程序名称：汉诺塔演示软件\n");
    printf("版本信息：v6.0\n");
    printf("开发时间：2024年\n");
    printf("开发者信息：\n");
    printf(" 刘世仁 - 学号：202426704047 - 专业：软件工程 - 班级：数智2班\n");
    printf(" 胡峻铭 - 学号：202426704048 - 专业：软件工程 - 班级：数智2班\n");
    printf(" 冯  鑫 - 学号：202426704046 - 专业：软件工程 - 班级：数智2班\n");
    printf("反馈渠道： 如有任何问题或建议，请通过该邮箱联系我们 lsr13437917740@163.com\n") ;
    // 添加更多开发者信息...
    printf("\n按任意键返回主菜单. . .");
    getch();
}


void conclusion(){
	 int key;
	 system("cls");
	 getchar();
   	 HideCursor();
	 gotoxy(49,12);
     printf("确定退出程序？\n\n");
     printBlank(36);
     printf("按[Y]键确定");
     printBlank(16);
     printf("按其他键取消\n");
     char end = getch(); // 获取用户的选择
     if (end == 'Y' || end == 'y') {
        	system("cls");
        	gotoxy(49,6);
     		printf("【程序回顾】\n\n");
     		printBlank(42);
     		printf("  各功能使用次数如下：\n\n");
     		printBlank(42);
     		printf("使用 一般模式 功能 %d 次\n\n",key1);
     		printBlank(42);
     		printf("使用 跨柱限制模式 功能 %d 次\n\n",key2);
     		printBlank(42);
     		printf("使用 颜色限制模式 功能 %d 次\n\n",key3);
     		printBlank(42);
     		printf("使用 奇偶分离模式 功能 %d 次\n\n\n",key4);        	
        	loop=0;//结束程序 
        	printBlank(18);
    		printf("感谢您体验这场逻辑思维与递归魅力的旅程，愿您带着今天的收获，继续在编程的道路上勇往直前！\n");//感谢您的使用!
    		getchar();
     } 
     
}

//打印空格函数
void printBlank(int n) { 
	for (int i = 1; i <= n; i++) {
		putchar(' ');
	}
}


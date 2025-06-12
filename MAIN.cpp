/*------------------------------------
��Ŀ �� ��ŵ����ʾ���ʵ�����ٵ��ƶ����� 
Ŀ�� �� ����㷨 �����ٵ��ƶ����������� A �ϵ� n ��Բ���Ƶ����� C �ϣ����԰�ͬ��˳����á� 
���뻷�� �� Dev-C++ 5.11
�ļ� �������򹲰���MAIN.cpp�� Color.h��menu.h ��variable.h�ĸ��ļ� 
������ ��������С�� ��3�ˣ� 
-------------------------------------*/ 
#include"variable.h"//ͷ�ļ���ȫ�ֱ����뺯������ 
#include"menu.h"    //�˵��ļ� 
#include"Color.h"   //��ɫ�����ļ� 


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
			printf("��Ҫ���Ĳ���:");
            scanf("%d", &N);
            if(N<=0) {
            	printf("�������!\n\n");
            	// ������뻺������������Ч����Ӱ����һ��ѭ��
            	while (getchar() != '\n') continue;
				}
            }while(N<=0);
            break;
            
        case 2:
            int mode;
			do {
        	printf("��������Ҫѡ���ģʽ,[1]�ֶ�[2]�Զ�\n");
        	scanf("%d", &mode);
        	if (mode == 1) autoPlay = 0; 	  // �û�ѡ���ֶ�ģʽ��autoPlay ����Ϊ 0
        	else if (mode == 2) autoPlay = 1; // �û�ѡ���Զ�ģʽ��autoPlay ����Ϊ 1
        	else {
            	printf("�������!\n\n");
            	// ������뻺������������Ч����Ӱ����һ��ѭ��
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
            coloreset=0;// ������ɫ
            colorinit();
            getchar();
            colorhanoi(N, 'A', 'B','C');
            break;
            
        case 6:
        	dectction();//�ж������Ƿ���ȷ 
            coloreset=0;// ������ɫ		
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
		printf("��ģʽ�£�����Բ��������Ϊż��,��ϸ��Ϣ�뿴������˵����\n\n");
		do{
			printf("�޸���Ҫ���Ĳ���:");
            scanf("%d", &N);
            if(N<=0||N % 2 == 1) {
            	printf("�������!\n\n");
            	// ������뻺������������Ч����Ӱ����һ��ѭ��
            	while (getchar() != '\n') continue;
			}
        }while(N<=0||N % 2 == 1);
	}
}

// ָ�������ת��x��y�����괦
// ˮƽx����ֱy 
void gotoxy(int x,int y)  
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle,pos);
} 


//�������ع�꺯��
void HideCursor()
{
    CONSOLE_CURSOR_INFO cursor;    
    cursor.bVisible = FALSE;    
    cursor.dwSize = sizeof(cursor);    
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);    
    SetConsoleCursorInfo(handle, &cursor);
}


//���x��y�ط��Ļ���
//���һ�����һ�� ����Ϊn �ĺ�ŵ�� 
void drawHanoi(int &x,int &y,int n,int next)
{
    // ���ԭ���� 
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
    // �����µ� 
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
    // ��ʼ��������Ϣ 
    abc_pillar[0][0] = N;
    for(int i = 1; i <= N; i++ ){
        abc_pillar[0][i] = N + 1 - i;
    }
    //�߶� = ����ǽ(2) + deep(4) + �Ͽ���(1) 
    //��� = ����ǽ(2) + 3������[3*(deep*2+1)] + �����м����(2)
    mapHeight = 2 + N + 1;
    mapWidth = 2 + 3 * (N * 2 + 1) + 2;
    
    //����0(a)ˮƽ���� = ���ǽ(1) + deep(4) 
    //����1(b)ˮƽ���� = ����1 + 2*deep + 2 
    //����2(c)ˮƽ���� = ����2 + 2*deep + 2 
    abc_x[0] = 1 + N;
    abc_x[1] = abc_x[0] + 2* N + 2;
    abc_x[2] = abc_x[1] + 2* N + 2;
    
    // ���Ƶ�ͼ
    for(int i = 0; i < mapHeight; i++){
        for(int j = 0; j < mapWidth; j++){
            //ǽ����� 
            if(i == 0 || i == mapHeight - 1 || j == 0 || j == mapWidth - 1){
                gotoxy(j,i);
                printf("%c",wall);
            }
            //��������
            else if( i > 1 && i < mapHeight - 1){
                if(j == abc_x[0] || j == abc_x[1] || j == abc_x[2]){
                    //��ʼ������Բ��
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
    // ��ȡfrom�������ж��ٸ߶�λ���Ŀ�ʼ 
    int fromHeight = abc_pillar[from-'A'][0];
    int n = abc_pillar[from-'A'][fromHeight];
    int x = abc_x[from-'A'];
    int y = 2 + N - fromHeight;
    abc_pillar[from-'A'][0]--;
    // ��ȡto �������ж�� ��λ���Ľ��� 
    abc_pillar[to-'A'][0]++;
    int toHeight = abc_pillar[to-'A'][0];
    abc_pillar[to-'A'][toHeight] = n;
    int toX = abc_x[to-'A'];
    int toY = 2 + N - toHeight;
    // ȡ���� ==> ���������� 
    while(y > 1){
        drawHanoi(x,y,n,up);
    }
    // �ƶ��� ==> �ƶ���ָ���� 
    if(x < toX){
        while(x < toX){
            drawHanoi(x,y,n,right);
        }
    }else if(x > toX){
        while(x > toX){
            drawHanoi(x,y,n,left);
        }
    }
    // ������ ==> �½������� 
    while(y < toY){
        drawHanoi(x,y,n,down);
    }
    //�ֶ����� 
    if(autoPlay == 0){
        gotoxy(0,mapHeight+3); 
        printf("�밴�س�������һ��. . ."); 
        getchar(); 
    } 
    steps++;
}


/**
* from ���Ŀ�ʼ 
* temp ��ʱ���� 
* to   �ƶ�����  
*/
void hanoi(int n,char from ,char temp,char to)
{
    if(n==1){           // from��toֻ��һ����Ҫ�ƶ���ֱ���ƶ� 
    	if(key1== code1){
        gotoxy(0,mapHeight+3);
        printBlank(50);
        gotoxy(0,mapHeight+3);
        printf("�밴�س�����ʼ\n");
        getchar();
        gotoxy(0,mapHeight+3);
        printBlank(30);
        key1++;
    	} 
        move(from, to); //�ݹ��ֹ����
    }
    else{
        hanoi(n-1,from ,to,temp); //�ƶ�from �����n-1 ==> temp �ݴ� 
        move(from,to);            //�ƶ�from ʣ�µ�1   ==> to   Ŀ�ĵ� 
        hanoi(n-1,temp,from,to);  //�ƶ�temp �ݴ��n-1 ==> to   Ŀ�ĵ� 
    }
    // ����������������������ϵ�Բ��
   if(n==N){
   	code1++;
    clearPillar(0);// ���A����
    clearPillar(1);// ���B����
    clearPillar(2);// ���C����
    gotoxy(0, mapHeight + 3);
    printf("  ��������,���ƶ���%d����\n��R�ظ����ţ���������˳�. . .",steps);
	char choice = getch(); // ��ȡ�û���ѡ��
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
        printf("�밴�س�����ʼ\n");
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
    // ����������������������ϵ�Բ��
	if(n==N){
		code2++;
		clearPillar(0); // ���A����
    	clearPillar(1); // ���B����
    	clearPillar(2); // ���C����
    	gotoxy(0, mapHeight + 3);
    	printf("  ��������,���ƶ���%d����\n��R�ظ����ţ���������˳�. . .",steps);
		char choice = getch(); // ��ȡ�û���ѡ��
        if (choice == 'R' || choice == 'r') {
        	system("cls");
    		HideCursor();
    		init();
    		pillarhanoi(N, 'A', 'B', 'C');
    		
        }    
	}  
}

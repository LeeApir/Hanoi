#pragma once
#include"variable.h"

// ���ָ�������ϵ�����Բ��
void clearPillar(int pillarIndex)
{
    for (int i = 0; i <= N; i++) {
        abc_pillar[pillarIndex][i] = 0;
    }
    abc_pillar[pillarIndex][0] = 0; // �������ӵĸ߶�
}

void drawColor(int &x,int &y, int n,int next){
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
	if(option == 6 && n % 2 == 0){	
	//������6ʱ��ż���̵Ĵ�С��һ    
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
	
    // ����Բ�̱�ž�����ɫ
    if(n % 2 == 0) { // ż����Բ���ź�ɫ
        printf("%s", red);
    } 
	else { // ������Բ������ɫ
        printf("%s", blue);
    }
	
    gotoxy(x - n,y);
    printf("%s",replace); 
    printf("%s", reset); // ������ɫ
	// ��������B������C����ɫ
    if(coloreset<=N*3){
    	
		for(int i = 1; i < mapHeight - 2; i++) {
        	gotoxy(abc_x[1], i+1);
        	printf("%c", pillar); // ��������B
        	gotoxy(abc_x[2], i+1);
        	printf("%c", pillar); // ��������C
    	}
	coloreset++;
	
	}
    Sleep(sleepTime);
    
}

void colorinit(){
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
                    drawColor(j,i,abc_pillar[abc_x_index][N - i + 2],-1);
                }
            }
        }
    } 
}


void colormove(char from,char to){
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
        drawColor(x,y,n,up);
    }
    // �ƶ��� ==> �ƶ���ָ���� 
    if(x < toX){
        while(x < toX){
            drawColor(x,y,n,right);
        }
    }else if(x > toX){
        while(x > toX){
            drawColor(x,y,n,left);
        }
    }
    // ������ ==> �½������� 
    while(y < toY){
        drawColor(x,y,n,down);
    }
    //�ֶ����� 
    if(autoPlay == 0){
        gotoxy(0,mapHeight+3); 
        printf("�밴�س�������һ��"); 
        getchar(); 
    } 
    steps++; 
}

/*
* from ���Ŀ�ʼ 
* temp ��ʱ���� 
* to   �ƶ����� 
*/
void colorhanoi(int n,char from ,char temp,char to){
    if(n==1){           // from��toֻ��һ����Ҫ�ƶ���ֱ���ƶ� 
    	if(key3== code3){
    		gotoxy(0,mapHeight+3);
        	printBlank(50);
        	gotoxy(0,mapHeight+3);
        	printf("�밴�س�����ʼ\n");
        	getchar();
        	gotoxy(0,mapHeight+3);
        	printBlank(30);
        	key3++;
    	} 
        colormove(from, to); //�ݹ��ֹ����
    }
    else{
        colorhanoi(n-1,from ,to,temp); //�ƶ�from �����n-1 ==> temp �ݴ� 
        colormove(from,to);            //�ƶ�from ʣ�µ�1   ==> to   Ŀ�ĵ� 
        colorhanoi(n-1,temp,from,to);  //�ƶ�temp �ݴ��n-1 ==> to   Ŀ�ĵ� 
    }
    // ����������������������ϵ�Բ��
   if(n==N){
   		code3++;
    	clearPillar(0);// ���A����
    	clearPillar(1);// ���B����
    	clearPillar(2);// ���C����
    	gotoxy(0, mapHeight + 3);
    	printf("  ��������,���ƶ���%d����\n��R�ظ����ţ���������˳�. . .",steps);
		char choice = getch(); // ��ȡ�û���ѡ��
        if (choice == 'R' || choice == 'r') {
        	system("cls");
    		coloreset=0;//���ú��������ӵ���ɫ 
    		colorinit();
    		colorhanoi(N, 'A', 'B', 'C');
    		
        }    
	} 
}

void parityinit(){
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
                    drawColor(j,i,abc_pillar[abc_x_index][N - i + 2],-1);
                }
            }
        }
    } 
}


//�����ݹ�˼����еݻ�-�ƶ�
void paritymove(int n, char source, char temp, char target){ 
    if (n == 1){
    	if(key4== code4){
    		gotoxy(0,mapHeight+3);
        	printBlank(50);
        	gotoxy(0,mapHeight+3);
        	printf("�밴�س�����ʼ\n");
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
    //�������� 
   	code4++;
    clearPillar(0);// ���A����
    clearPillar(1);// ���B����
    clearPillar(2);// ���C����
    gotoxy(0, mapHeight + 3);
    printf("  ��������,���ƶ���%d����\n��R�ظ����ţ���������˳�. . .",steps);
	char choice = getch(); // ��ȡ�û���ѡ��
    if (choice == 'R' || choice == 'r') {
        system("cls");
    	coloreset=0;
    	parityinit();
    	parityhanoi(N, 'A', 'B', 'C');
    }
    	
}


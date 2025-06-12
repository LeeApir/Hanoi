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
    int total = 100; // �ܽ���
    int current = 0; // ��ǰ����
    int bar_length = 50; // �������ĳ���

    printf("Progress: [");

    for (int i = 0; i < total; i++) {
        usleep(10000); // ģ����ȸ���
        current++;
        // �������Ƶ�ԭʼλ�ú��ӡ������
        COORD coord;
        coord.X = 0; // ���� X ����Ϊ 0 (���� ASCII �������� 0 ��ʼ)
        coord.Y = 17; // ���� Y ����Ϊ 1 (���� ASCII �����ڵ�ǰ�е���һ��)
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		printBlank(25);
        printf("Progress: [");
        for (int j = 0; j < bar_length; j++) {
            if (j * (total / bar_length) <= current) {
                printf("-"); // ��������
            } else {
                printf(" "); // ���ո�
            }
        }
        printf("] %d%%\r", current);
        if(current==10){
        	gotoxy(0,20);
        	printBlank(44);
        	printf("�˳�����������С�龫������");
		}
        else if(current==45){
        	gotoxy(0,22); 
        	printBlank(43);
        	printf("������Ա�������� ������ ����");
		}
        fflush(stdout);
    }
    
}

// ����ָ�Ϻ���
void beginner() {
	system("cls");
	printBlank(45);
    printf("������ָ�ϡ�\n\n");
    printf("��������ܡ�\n");
    printf("��ŵ����һ������ĵݹ����⣬Ŀ�����������ض����������£�������Բ�̴�һ�������ƶ�����һ�����ӡ������ּ��ͨ��������ʾ����������⺺ŵ������Ľ��������\n\n");
    printf("����ο�ʼ��\n");
    printf("- ����Բ�̲����������˵�ѡ������Բ�̲���������������Ҫ��ս�Ĳ�����\n");
    printf("- ѡ�񲥷ŷ�ʽ�������˵�ѡ�񡰲��ŷ�ʽ����Ȼ��ѡ���ֶ������Զ���ģʽ��\n");
    printf("- ѡ��ŵ��ģʽ�������˵�ѡ��ۿ�ģʽ��Ȼ��ѡ����Ҫ�ۿ�������ģʽ��\n\n");
    printf("����Ϸ�淨��\n");
    printf("- ��ϷĿ�꣺������Բ�̴���ʼ�����ƶ���Ŀ�����ӡ�\n- ��Ϸ����ÿ��ֻ���ƶ�һ��Բ�̣��Ҳ��ܽ��ϴ��Բ�̷��ڽ�С��Բ�����档\n");
    printf("- �������������ֶ�ģʽ�£�����Ҫ���س�����ִ���ƶ�һ��Բ�̡�\n\n");
    printf("��������ʾ��\n");
    printf("- �۲춯����ʾ���˽�Բ�̵��ƶ����̡����Զ�ģʽ�£��������Զ����ţ����ֶ�ģʽ�£�������ͨ�����س������ƶ����Ĳ��š�\n\n");
    printf("���˳���Ϸ��\n");
    printf("- Ҫ�˳���Ϸ���������˵�ѡ�񡰽���ʹ�á���\n\n");
    printf("��������֧�֡�\n");
    printf("- ��������κ�������飬��ͨ�������ڡ�[��������]��ϵ���ǡ�\n\n");
    printBlank(40);
    printf("���������ʼ,ף����Ϸ��죡\n");
    HideCursor();
    getch(); // �ȴ��û���������
}


int menu() {
	system("cls");
	printBlank(32);
	printf("��������������ĺ�ŵ��ʵ��,��ӭ����ʹ��\n");
	printBlank(25);
	printf("******************************************************\n");
	printBlank(35);
	printf("[1]:����Բ�̲���\n");
	printBlank(35);
	printf("[2]:ѡ�񲥷ŷ�ʽ\n\n");
	printBlank(38);
	printf("�� �� �� ŵ �� �� ��\n");
	printBlank(35);
	printf("[3]:һ��ģʽ\n");
	printBlank(35);
	printf("[4]:��������ģʽ\n");
	printBlank(35);
	printf("[5]:��ɫ����ģʽ\n");
	printBlank(35);
	printf("[6]:��ż�̷���ģʽ\n\n");
	printBlank(35);
	printf("[7]:���������ٶ�\n");
	printBlank(35);
	printf("[8]:����˵��\n");
	printBlank(35);
	printf("[9]:���ڳ���\n");
	printBlank(35);
	printf("[0]:����ʹ��\n");
	printBlank(25);
	printf("******************************************************\n");
	printBlank(35);
	printf("������ѡ��\n\b\b\b");
	printf("����:");
	do{
		scanf("%d", &option);
		if(option<0||option>9){  //����������ֱ�����0��9֮��
			printf("�������!\n\n");
			printf("���������빦��:");
		}
	}while(option<0||option>9);
	return option;
}

int speedMenu(){

	int speed;
	printBlank(30);
    printf("\nѡ����Ҫ�Ĳ����ٶȣ�\n");
    printBlank(36);
    printf("1. 0.5����\n");
    printBlank(36);
    printf("2. 1.0���٣�Ĭ�ϣ�\n");
    printBlank(36);
    printf("3. 2.0����\n");
    printBlank(36);
    printf("4. 3.0����\n");
    printBlank(36);
    printf("5. 5.0����\n");
    printBlank(36);
    printf("6. �ǳ���(������)\n");
    printBlank(36);
    printf("0. �˳�\n");
    printBlank(30);
    printf("������ѡ�0-6����");
    
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
                printf("�˳�����\n");
                break;
            default:
            	printBlank(30);
                printf("��Чѡ�������ѡ��:");
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
                printf("������������\n\n");
    			printf("�� A��B��C �� 3 ����������ʼʱ�������� A ����һ���� n ��Բ�̣���ЩԲ�����¶��ϣ��ɴ�С�ص���һ��\n");
    			printf("��Բ�̴�С������Ϊ 1��2��������n��������Բ������ɫ��ż����Բ���ź�ɫ��\n\n");
    			printf("��Ҫ������ A �ϵ���һ��Բ���Ƶ����� C �ϣ����԰�ͬ��˳����á����ƶ�Բ��ʱӦ���������ƶ�����\n\n");
    			printf("����(1)��ÿ��ֻ���ƶ� 1 ��Բ�̣�\n\n");
    			printf("����(2)���κ�ʱ�̶��������ϴ��Բ��ѹ�ڽ�С��Բ��֮�ϣ�\n\n");
    			printf("����(3)���������ƶ�����(1)-(2)��ǰ���£��ɽ�Բ������ A��B��C ����һ�����ϡ�\n\n");
    			printf("\n���س���������һ�� . . .");
    			getchar();
                break;
            case 2:
            	system("cls");
            	HideCursor();
            	getchar();
            	printf("������������\n\n");
            	printf("�� A��B��C �� 3 ����������ʼʱ�������� A ����һ���� n ��Բ�̣���ЩԲ�����¶��ϣ��ɴ�С�ص���һ��\n");
            	printf("��Ҫ������ A �ϵ���һ��Բ���Ƶ����� C �ϣ����԰�ͬ��˳����á����ƶ�Բ��ʱӦ���������ƶ�����\n\n");
                printf("����(1)��ÿ��ֻ���ƶ� 1 ��Բ�̣�\n\n");
                printf("����(2)���κ�ʱ�̶��������ϴ��Բ��ѹ�ڽ�С��Բ��֮�ϣ�\n\n");
                printf("����(3)��Ҫ������ֻ�������ڵ�����֮���ƶ���������ֱ�Ӵӵ�һ�������ƶ����ӵ������������ϣ���ӵ�����������ֱ���ƶ�����һ��������\n\n");
                printf("����(4)���������ƶ�����(1)-(3)��ǰ���£��ɽ�Բ������ A��B��C ����һ�����ϡ�\n\n");
                printf("\n���س���������һ�� . . .");
				getchar();
				break;
            case 3:
            	system("cls");
            	HideCursor();
            	getchar();
                printf("������������\n\n");
    			printf("�� A��B��C �� 3 ����������ʼʱ�������� A ����һ���� n ��Բ�̣���ЩԲ�����¶��ϣ��ɴ�С�ص���һ��\n");
    			printf("��Բ�̴�С������Ϊ 1��2��������n��������Բ������ɫ��ż����Բ���ź�ɫ��\n\n");
    			printf("��Ҫ������ A �ϵ���һ��Բ���Ƶ����� C �ϣ����԰�ͬ��˳����á����ƶ�Բ��ʱӦ���������ƶ�����\n\n");
    			printf("����(1)��ÿ��ֻ���ƶ� 1 ��Բ�̣�\n\n");
    			printf("����(2)���κ�ʱ�̶��������ϴ��Բ��ѹ�ڽ�С��Բ��֮�ϣ�\n\n");
    			printf("����(3)���κ�ʱ�̶�������ͬɫԲ�̵���һ��\n\n");
    			printf("����(4)���������ƶ�����(1)-(3)��ǰ���£��ɽ�Բ������ A��B��C ����һ�����ϡ�\n\n");
    			printf("\n���س���������һ�� . . ."); 
				getchar();
                break;
            case 4:
            	system("cls");
            	HideCursor();
            	getchar();
                printf("������������\n\n");
    			printf("�� A��B��C �� 3 ����������ʼʱ�������� A ����һ���� 2n ��Բ�̣���ЩԲ�����¶��ϣ�����Բ��Ϊһ�飬�ɴ�С�ص���һ��\n");
    			printf("��Բ�̴�С������Ϊ 1��2��������2n��������Բ���Ŵ�����ɫ��ż���Ŵ���Բ���ź�ɫ��\n\n");
    			printf("��Ҫ������ A �ϵ�����Բ���Ƶ����� B �ϣ���ż��Բ���Ƶ����� C �ϣ����԰�ͬ��˳����á����ƶ�Բ��ʱӦ���������ƶ�����\n\n");
    			printf("����(1)��ÿ��ֻ���ƶ� 1 ��Բ�̣�\n\n");
    			printf("����(2)���κ�ʱ�̶��������ϴ��Բ��ѹ�ڽ�С��Բ��֮�ϣ�\n\n");
    			printf("����(4)���������ƶ�����(1)-(3)��ǰ���£��ɽ�Բ������ A��B��C ����һ�����ϡ�\n");
    			printf("\n���س���������һ�� . . ."); 
				getchar();
                break;
            case 0:
    			flag=0;
    			break;
            default:
                printf("��Чѡ�������ѡ��\n");
                break;
        }
   }
   
}

int scaHelp(){
	int x;
	system("cls");
    printBlank(35);
    printf("   ��ŵ��ʵ�����˵��\n");
    printBlank(25);
    printf("******************************************************\n");
    printBlank(30);
    printf("[1]:һ��ģʽ����\n");
    printBlank(30);
    printf("[2]:��������ģʽ����\n");
    printBlank(30);
    printf("[3]:��ɫ����ģʽ����\n");
    printBlank(30);
    printf("[4]:��ż�̷���ģʽ����\n");
    printBlank(30);
    printf("[0]:�������˵�\n");
    printBlank(25);
    printf("******************************************************\n");
    printBlank(30);
    printf("������ѡ��\n\b\b\b");
    printf("ѡ��:");
	scanf("%d", &x);
	while(x < 0 || x > 4) {
        //printf("�������!\n\n");
        printf("��Чѡ�������ѡ��:");
        scanf("%d", &x);
    }
    return x;
}

void printAbout() {
	HideCursor();
	system("cls");
    printf("�������ƣ���ŵ����ʾ���\n");
    printf("�汾��Ϣ��v6.0\n");
    printf("����ʱ�䣺2024��\n");
    printf("��������Ϣ��\n");
    printf(" ������ - ѧ�ţ�202426704047 - רҵ��������� - �༶������2��\n");
    printf(" ������ - ѧ�ţ�202426704048 - רҵ��������� - �༶������2��\n");
    printf(" ��  �� - ѧ�ţ�202426704046 - רҵ��������� - �༶������2��\n");
    printf("���������� �����κ�������飬��ͨ����������ϵ���� lsr13437917740@163.com\n") ;
    // ��Ӹ��࿪������Ϣ...
    printf("\n��������������˵�. . .");
    getch();
}


void conclusion(){
	 int key;
	 system("cls");
	 getchar();
   	 HideCursor();
	 gotoxy(49,12);
     printf("ȷ���˳�����\n\n");
     printBlank(36);
     printf("��[Y]��ȷ��");
     printBlank(16);
     printf("��������ȡ��\n");
     char end = getch(); // ��ȡ�û���ѡ��
     if (end == 'Y' || end == 'y') {
        	system("cls");
        	gotoxy(49,6);
     		printf("������عˡ�\n\n");
     		printBlank(42);
     		printf("  ������ʹ�ô������£�\n\n");
     		printBlank(42);
     		printf("ʹ�� һ��ģʽ ���� %d ��\n\n",key1);
     		printBlank(42);
     		printf("ʹ�� ��������ģʽ ���� %d ��\n\n",key2);
     		printBlank(42);
     		printf("ʹ�� ��ɫ����ģʽ ���� %d ��\n\n",key3);
     		printBlank(42);
     		printf("ʹ�� ��ż����ģʽ ���� %d ��\n\n\n",key4);        	
        	loop=0;//�������� 
        	printBlank(18);
    		printf("��л�������ⳡ�߼�˼ά��ݹ��������ọ́�Ը�����Ž�����ջ񣬼����ڱ�̵ĵ�·������ֱǰ��\n");//��л����ʹ��!
    		getchar();
     } 
     
}

//��ӡ�ո���
void printBlank(int n) { 
	for (int i = 1; i <= n; i++) {
		putchar(' ');
	}
}


#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <windows.h>

time_t Cur_Time;
struct tm*Now;
char Time_Handel[80];

//=====================================================

//����ΪĬ�ϴ洢·����
char Env_Path_02[]="C:\\Users\\kali\\tmp1.txt";
char Env_Path_03[]="C:\\Users\\kali\\tmp2.txt";
char Env_Path_04[]="C:\\Users\\Public\\tmp22.txt";
char Log_Path_01[]="C:\\Users\\Public\\History\\Command.txt";
char Log_Path_02[]="C:\\Users\\Public\\History\\Result.txt";

//=====================================================

main(int argc, char *argv[])
{
	HWND hwnd = GetForegroundWindow();
	int cx = GetSystemMetrics(SM_CXSCREEN);
	int cy = GetSystemMetrics(SM_CYSCREEN);

	LONG l_WinStyle = GetWindowLong(hwnd,GWL_STYLE);
	SetWindowLong(hwnd,GWL_STYLE,(l_WinStyle | WS_POPUP | WS_MAXIMIZE) & ~WS_CAPTION & ~WS_THICKFRAME & ~WS_BORDER);
	SetWindowPos(hwnd, HWND_TOP, 0, 0, cx, cy, 0);
	system("cls");
	
	Sleep(2000); 
	printf("                                                               ���ϳ�Ʒ\n\n");
	printf("                                                                          \033[31m            |         \033[0m\n");
	printf("                                                                          \033[31m          '~|~.       \033[0m\n");
	printf("                                                                          \033[31m       __   .   __    \033[0m\033[1;41m  .-=-.  \033[0m   \033[1;42m __  __  \033[0m  \n");
	printf("                                                                          \033[31m     .'  '-'| .'  .   \033[0m\033[1;41m : |[] : \033[0m   \033[1;42m ||  ||  \033[0m  \n");
	printf("     \033[1;33m___         __  \033[0m\033[1m   [Bacsh]  \033[1;33m ______           __\033[0m                 ");
	printf("    \033[31m    ' .-._.'.'.'; |   \033[0m\033[1;41m : |\\\\ : \033[0m   \033[1;42m ||__||  \033[0m  \n");
	printf("     \033[1;33m\\ \\         |\033[0m\033[31m[\033[7;31m=\033[0m\033[0m\033[31m]\033[0m             \033[1;33m|  _  \\         _\\|\033[0m");
	printf("                     \033[31m    |/  .'-: |  | |   \033[0m\033[1;41m  '-=-'  \033[0m   \033[1;42m '__:'.| \033[0m  \n");
	printf("      \033[1;33m\\ \\    _   |\033[0m\033[31m___\033[0m\033[1;33m_____        | <_> |  ___  //|||\033[0m");
	printf("                     \033[31m       : | ; | . :    \033[0m\n");
	printf("       \033[1;33m\\ \\  / \\  |\033[0m\033[31m|\033[7;31m \033[0m\033[31m|\033[0m\033[1;33m ___ \\       |  __  \\/ _ \\//__||__\033[0m");
	printf("                   \033[31m      .; | ; |. :.    \033[0m\n");
	printf("     ***\033[1;33m\\ \\/ _ \\/ \033[0m\033[31m|\033[7;31m \033[0m\033[31m|\033[0m\033[1;33m |  \\ |\033[0m******\033[1;33m| [__] | <_> \\ //||��\\\\\033[0m***");
	printf("              \033[31m    .: ; | ; |'.  :   \033[0m\033[1;44m    ____ \033[0m   \033[1;43m _______ \033[0m  \n");
	printf("  -------\033[1;33m\\__/\033[0m-\033[1;33m\\__/\033[0m\033[31m|\033[7;31m_\033[0m\033[31m|\033[0m\033[1;33m_|\033[0m--\033[1;33m|_|\033[0m------\033[1;33m\\_______\\___/\\|/\033[0m-\033[1;33m||\033[0m--\033[1;33m||\033[0m---     ");
	printf("         \033[31m      .; | ; |  : |   \033[0m\033[1;44m  .'___/ \033[0m   \033[1;43m |__|__| \033[0m  \n");
	printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	printf("           \033[31m    .: ; | | :  | |   \033[0m\033[1;44m  '___.  \033[0m   \033[1;43m   |||   \033[0m  \n");
	printf("=====================================================================");
	printf("     \033[31m       | :-.'   : '.. \033[0m\033[1;44m /____.' \033[0m   \033[1;43m   |_|   \033[0m  \n");
	printf("                                                                          \033[31m      -.'_.--._  : /  \033[0m                         \n");
	printf("                \033[35m[ Bash Shell for Windows ]\033[0m                                \033[31m      .:;.:_   '. ' \033[0m\033[35m[ Rust Engine for Windows ]\033[0m \n");
	printf("                       \033[35m[ �ڲ⣺6.2 ]\033[0m                                      \033[31m    .''     ':/'      \033[0m      \033[35m[�ڲ⣺1.4]\033[0m        \n");
	printf("                                                                          \033[31m            |         \033[0m                         \n");
	printf("                       \033[1;30mJessarin000 ��\033[0m                                     \033[31m            |         \033[0m     \033[1;30mJessarin000 ��\033[0m      \n");
	printf("                                                                          \033[31m            |         \033[0m                         \n");
	printf("\n\033[1;30m/*\033[0m\033[1mWindows SSH�۹޿��ƽ���\033[0m\033[1;30m*/\033[0m\n\n");
	printf("\033[1;30m���� �� Jessarin000\n");
	printf("ʱ�� �� 2023-10-23\033[0m\n\n");
	printf("\033[34m���� Windows11 ƽ̨������ SSH �۹� ( �汾 �� ����1.4 ) ��\n");
	printf("��������Խ�϶��ַ�ʽ��̬��������߶��򣬸߶ȸ��� Linux �۹޳�����\n\n\033[0m");
	printf("    [\033[32m+\033[0m] \033[36mLinux �۹���Ŀ�������Github�� < \033[4mhttps://github.com/kjx52/ssh-honeypot-new\033[0m\033[36m >\033[0m\n");
	printf("    [\033[32m+\033[0m] \033[33m�й�Linux�۹޵���ϸ��Ϣ�� < \033[4mhttps://xz.aliyun.com/t/12884\033[0m\033[33m >\033[0m\n");
	printf("    [\033[32m+\033[0m] \033[32m���κ������������ϵ���� < \033[4mkjx52@outlook.com\033[0m\033[32m >��\033[0m\n\n");
	printf("\033[1;35m* ������Ӧ���Bacsh�ն�ʹ�á�\n");
	printf("* Ҫ�� Windows ƽ̨�汾���� 7 ��\n");
	printf("* ������Ҫ������ֹ���̣����Թ���Ա��������д˳���\n");
	printf("* ���κ������������ϵ���ߡ�\033[0m\n\n");
	Sleep(5000);
	
	system("cls");
	
	char FnW[50];
	char *FnM=argv[0];
	char ANS;
	char Buffer_X[1024];
	char From[6]="from ";
	char Tmp_Flag_01[6];
	char Att_IP[16],Cat_Command[3];
	int Tmp_Flag_02,Tmp_Flag_03,Tmp_Flag_04,Tmp_Flag_05,Tmp_Flag_06,Tmp_Flag_07,Tmp_Flag_08;
	int Remove_Code;
	
	if((access(Env_Path_02,F_OK))!=-1)
	{
		FILE*Env_Tmp_Pipe_01;
		Env_Tmp_Pipe_01=fopen(Env_Path_02, "w");
		fprintf(Env_Tmp_Pipe_01,"0");
		fclose(Env_Tmp_Pipe_01);
		memset(Buffer_X,0,sizeof(Buffer_X));
	}
	else
	{
		printf("\033[1m[\033[31m-\033[0m\033[1m]\033[0m \033[1;31m�����ļ��쳣���������б�����֮ǰ��������SSH�۹�ȫ�沿����� Critical Code 01\033[0m");
		Sleep(4000); 
		return 0x001;
	}
	
	memset(Buffer_X,0,sizeof(Buffer_X));
	
	Tmp_Flag_03=1;
	Sleep(300);printf("\033[1;34mWaiting.");
	Sleep(200);printf(".");Sleep(200);printf(".");Sleep(200);printf(".");Sleep(200);printf(".");Sleep(200);printf("\033[0m\n\n");
	
	time(&Cur_Time);
	Now=gmtime(&Cur_Time);
	snprintf(Time_Handel,20,"%d:%d:%d",8+Now->tm_hour,Now->tm_min,Now->tm_sec);
	
	printf("[\033[32m+\033[0m] \033[1m%s\033[0m\t\033[1;34mУ���ļ�������...\033[s",Time_Handel);
	strcpy(FnW,"powershell -c \"Get-FileHash ");
	strcat(FnW,FnM);
	strcat(FnW," -Algorithm SHA256 | fl\"");
	Sleep(50);
	system(FnW);
	printf("\033[u�ɹ���\033[0m\n\n\n\n\n\n");
	
	time(&Cur_Time);
	Now=gmtime(&Cur_Time);
	snprintf(Time_Handel,20,"%d:%d:%d",8+Now->tm_hour,Now->tm_min,Now->tm_sec);

	printf("[\033[32m+\033[0m] \033[1m%s\033[0m\t\033[1;34m����ն�״̬-",Time_Handel);
	Sleep(600);printf(".");Sleep(600);printf(".");Sleep(600);printf(".");Sleep(600);
	printf("\b \b\b \b\b \b");
	if((access("C:\\Users\\kali\\Shell\\home\\kali",F_OK))!=-1 && (access("C:\\Users\\kali\\Shell\\etc",F_OK))!=-1 && (access("C:\\Users\\kali\\Shell\\bin",F_OK))!=-1)
	{
		Tmp_Flag_02=1;
	}
	else
	{
		Tmp_Flag_02=0;
	}
	Sleep(600);printf(".");Sleep(600);printf(".");
	printf("\b \b\b \b-��ɡ�\033[0m");
	printf("\033[0m\n");
	
	time(&Cur_Time);
	Now=gmtime(&Cur_Time);
	snprintf(Time_Handel,20,"%d:%d:%d",8+Now->tm_hour,Now->tm_min,Now->tm_sec);
	
	printf("\033[1m[\033[1;32m+\033[0m\033[1m]\033[0m \033[1m%s\033[0m\t\033[34m���ڳ�ʼ��...\033[0m\n",Time_Handel);
	
	if(Tmp_Flag_02==1)
	{
		printf("\033[1;7;34;43m  ");
		for(Tmp_Flag_06=0;Tmp_Flag_06<20;Tmp_Flag_06++)
		{
			printf("_");
		}
		printf("     .-==-.   ����һ��  \n");
		printf("+[");
		for(Tmp_Flag_06=0;Tmp_Flag_06<20;Tmp_Flag_06++)
		{
			printf("_");
		}
		printf("]@  \033[s.[=##=]. �������ڵ� \033[0m\n");
		printf("\033[1;7;34;43m  ");
		for(Tmp_Flag_06=0;Tmp_Flag_06<20;Tmp_Flag_06++)
		{
			printf(" ");
		}
		printf("     \\-__-/     ����    \033[0m\n\033[u");
		for(Tmp_Flag_06=0;Tmp_Flag_06<24;Tmp_Flag_06++)
		{
			printf("\b");
		}
		printf("\033[?25l\033[1;7;34;43m");
		for(Tmp_Flag_06=0;Tmp_Flag_06<101;Tmp_Flag_06++)
		{
			for(Tmp_Flag_07=0;Tmp_Flag_07<((Tmp_Flag_06-1)/5)+1;Tmp_Flag_07++)
			{
				printf("=");
			}
			for(Tmp_Flag_08=0;Tmp_Flag_08<20-Tmp_Flag_07;Tmp_Flag_08++)
			{
				printf("_");
			}
			for(Tmp_Flag_08=0;Tmp_Flag_08<12;Tmp_Flag_08++)
			{
				printf("\b");
			}
			if(Tmp_Flag_06<10)
			{
				printf(":0%d%%:",Tmp_Flag_06);
			}
			else
			{
				printf(":%d%%:",Tmp_Flag_06);
			}
			Sleep(50);
			for(Tmp_Flag_08=0;Tmp_Flag_08<13;Tmp_Flag_08++)
			{
				printf("\b");
			}
			Sleep(100);
		}
		printf("\033[0m\n\n");
		Sleep(400);
		for(Tmp_Flag_07=0;Tmp_Flag_07<2;Tmp_Flag_07++)
		{
			for(Tmp_Flag_06=0;Tmp_Flag_06<52;Tmp_Flag_06++)
			{
				printf("\b \b");
			}
			printf("\033[A                                              \033[A");
		}
		for(Tmp_Flag_06=0;Tmp_Flag_06<17;Tmp_Flag_06++)
		{
			printf("\b \b");
		}
		printf("\033[34m��ɡ�\033[0m\n\33[?25h");
	}
	else
	{
		printf("\033[1;7;34;43m  ");
		for(Tmp_Flag_06=0;Tmp_Flag_06<101;Tmp_Flag_06++)
		{
			printf("_");
		}
		printf("     .-==-.   ����һ��  \n");
		printf("+[");
		for(Tmp_Flag_06=0;Tmp_Flag_06<101;Tmp_Flag_06++)
		{
			printf("_");
		}
		printf("]@  \033[s.[=##=]. �������ڵ� \033[0m\n");
		printf("\033[1;7;34;43m  ");
		for(Tmp_Flag_06=0;Tmp_Flag_06<101;Tmp_Flag_06++)
		{
			printf(" ");
		}
		printf("     \\-__-/     ����    \033[0m\n\033[u");
		for(Tmp_Flag_06=0;Tmp_Flag_06<105;Tmp_Flag_06++)
		{
			printf("\b");
		}
		printf("\033[?25l\033[1;7;34;43m");
		for(Tmp_Flag_06=0;Tmp_Flag_06<101;Tmp_Flag_06++)
		{
			for(Tmp_Flag_07=0;Tmp_Flag_07<Tmp_Flag_06+1;Tmp_Flag_07++)
			{
				printf("=");
			}
			for(Tmp_Flag_08=0;Tmp_Flag_08<(101-Tmp_Flag_07);Tmp_Flag_08++)
			{
				printf("_");
			}
			for(Tmp_Flag_08=0;Tmp_Flag_08<51;Tmp_Flag_08++)
			{
				printf("\b");
			}
			if(Tmp_Flag_06<10)
			{
				printf(":0%d%%:",Tmp_Flag_06);
			}
			else
			{
				printf(":%d%%:",Tmp_Flag_06);
			}
			Sleep(50);
			for(Tmp_Flag_08=0;Tmp_Flag_08<55;Tmp_Flag_08++)
			{
				printf("\b");
			}
			Sleep(100);
		}
		printf("\033[0m\n\n");
		Sleep(400);
		for(Tmp_Flag_07=0;Tmp_Flag_07<2;Tmp_Flag_07++)
		{
			for(Tmp_Flag_06=0;Tmp_Flag_06<132;Tmp_Flag_06++)
			{
				printf("\b \b");
			}
			printf("\033[A                                                                                                                                              \033[A");
		}
		for(Tmp_Flag_06=0;Tmp_Flag_06<122;Tmp_Flag_06++)
		{
			printf("\b \b");
		}
		printf("\033[34m.��ɡ�\033[0m\n\33[?25h");
		if((access("C:\\Users\\kali\\Shell\\home\\kali",F_OK))==-1)
		{
			if((access("C:\\Users\\kali\\Shell\\home",F_OK))==-1)
			{
				if((access("C:\\Users\\kali\\Shell",F_OK))==-1)
				{
					mkdir("C:\\Users\\kali\\Shell");
				}
				mkdir("C:\\Users\\kali\\Shell\\home");
			}
			mkdir("C:\\Users\\kali\\Shell\\home\\kali");
		}
		if((access("C:\\Users\\kali\\Shell\\bin",F_OK))==-1)
		{
			mkdir("C:\\Users\\kali\\Shell\\bin");
		}
		if((access("C:\\Users\\kali\\Shell\\etc",F_OK))==-1)
		{
			mkdir("C:\\Users\\kali\\Shell\\etc");
		}
	}
	
	time(&Cur_Time);
	Now=gmtime(&Cur_Time);
	snprintf(Time_Handel,20,"%d:%d:%d",8+Now->tm_hour,Now->tm_min,Now->tm_sec);
	
	printf("[\033[32m+\033[0m] \033[1m%s\033[0m\t\033[1;34m���֧�ֻ���...",Time_Handel);
	FILE*Command01;
	Command01=popen("sc.exe query state= all |findstr SERVICE_NAME |findstr sshd","r");
	fgets(Buffer_X,sizeof(Buffer_X),Command01);
	fclose(Command01);
	if(Buffer_X!=NULL)
	{
		printf("��ɡ�\033[0m\n");
	}
	else
	{
		time(&Cur_Time);
		Now=gmtime(&Cur_Time);
		snprintf(Time_Handel,20,"%d:%d:%d",8+Now->tm_hour,Now->tm_min,Now->tm_sec);
		
		printf("\033[0m\n\033[1m[\033[0m\033[31m-\033[0m\033[1m]\033[0m \033[1m%s\033[0m\t\033[31mδ��⵽Windows_OpenSSH���񣬽���ֹͣ��Critical Code 02\n\033[0m",Time_Handel);
		Sleep(3000);
		return 0x002;
	}
	
	time(&Cur_Time);
	Now=gmtime(&Cur_Time);
	snprintf(Time_Handel,20,"%d:%d:%d",8+Now->tm_hour,Now->tm_min,Now->tm_sec);
	
	printf("[\033[32m+\033[0m] \033[1m%s\033[0m\t\033[34m���֧���ļ�...",Time_Handel);
	if((access(Log_Path_01,F_OK))!=-1 || (access(Log_Path_02,F_OK))!=-1)
	{
		printf("\033[0m\n[\033[32m+\033[0m] \033[1m%s\033[0m\t\033[34m��⵽��ʷ�ļ���\n\033[0m",Time_Handel);
		printf("[?] Ҫɾ��������Y/n����");
		ANS=getchar();
		switch(ANS)
		{
			case 'Y'|'y':
				if((access(Log_Path_01,F_OK))!=-1)
				{
					time(&Cur_Time);
					Now=gmtime(&Cur_Time);
					snprintf(Time_Handel,20,"%d:%d:%d",8+Now->tm_hour,Now->tm_min,Now->tm_sec);

					Remove_Code=remove(Log_Path_01);
					if(Remove_Code == 0) 
					{
						printf("[\033[32m+\033[0m] \033[1m%s\033[0m\t\033[34m�ļ�Command.txtɾ���ɹ���\n\033[0m",Time_Handel);
					}
					else 
					{
						printf("[\033[33m!\033[0m] \033[1m%s\033[0m\t\033[33m�޷�ɾ���ļ�Command.txt��\n\033[0m",Time_Handel);
					}
				}
				
				if((access(Log_Path_02,F_OK))!=-1)
				{
					time(&Cur_Time);
					Now=gmtime(&Cur_Time);
					snprintf(Time_Handel,20,"%d:%d:%d",8+Now->tm_hour,Now->tm_min,Now->tm_sec);

					Remove_Code=remove(Log_Path_02);
					if(Remove_Code == 0) 
					{
						printf("[\033[32m+\033[0m] \033[1m%s\033[0m\t\033[34m�ļ�Result.txtɾ���ɹ���\n\033[0m",Time_Handel);
					}
					else 
					{
						printf("[\033[33m!\033[0m] \033[1m%s\033[0m\t\033[33m�޷�ɾ���ļ�Result.txt��\n\033[0m",Time_Handel);
					}
				}
				break;
				
			case 'N'|'n':
				break;
				
			default:
				if((access(Log_Path_01,F_OK))!=-1)
				{
					time(&Cur_Time);
					Now=gmtime(&Cur_Time);
					snprintf(Time_Handel,20,"%d:%d:%d",8+Now->tm_hour,Now->tm_min,Now->tm_sec);

					Remove_Code=remove(Log_Path_01);
					if(Remove_Code == 0) 
					{
						printf("[\033[32m+\033[0m] \033[1m%s\033[0m\t\033[34m�ļ� Command.txt ɾ���ɹ���\n\033[0m",Time_Handel);
					}
					else 
					{
						printf("[\033[33m!\033[0m] \033[1m%s\033[0m\t\033[33m�޷�ɾ���ļ� Command.txt��\n\033[0m",Time_Handel);
					}
				}
				
				if((access(Log_Path_02,F_OK))!=-1)
				{
					time(&Cur_Time);
					Now=gmtime(&Cur_Time);
					snprintf(Time_Handel,20,"%d:%d:%d",8+Now->tm_hour,Now->tm_min,Now->tm_sec);

					Remove_Code=remove(Log_Path_02);
					if(Remove_Code == 0) 
					{
						printf("[\033[32m+\033[0m] \033[1m%s\033[0m\t\033[34m�ļ� Result.txt ɾ���ɹ���\n\033[0m",Time_Handel);
					}
					else 
					{
						printf("[\033[33m!\033[0m] \033[1m%s\033[0m\t\033[33m�޷�ɾ���ļ� Result.txt��\n\033[0m",Time_Handel);
					}
				}
				break;
		}
	}
	else
	{
		printf("��ɡ�\033[0m\n");
	}
	memset(Buffer_X,0,sizeof(Buffer_X));
	
	time(&Cur_Time);
	Now=gmtime(&Cur_Time);
	snprintf(Time_Handel,20,"%d:%d:%d",8+Now->tm_hour,Now->tm_min,Now->tm_sec);
	
	printf("[\033[32m+\033[0m] \033[1m%s\033[0m\t\033[34m����ػ�����...",Time_Handel);
	if((access("C:\\Users\\Public\\SSHShell\\vshost.exe",X_OK))!=-1)
	{
		printf("��ɡ�\033[0m\n");
	}
	else
	{
		time(&Cur_Time);
		Now=gmtime(&Cur_Time);
		snprintf(Time_Handel,20,"%d:%d:%d",8+Now->tm_hour,Now->tm_min,Now->tm_sec);

		printf("\033[0m\n\033[1m[\033[0m\033[31m-\033[0m\033[1m]\033[0m \033[1m%s\033[0m\t\033[31m�ػ������쳣������ֹͣ��Critical Code 03\n\033[0m",Time_Handel);
		Sleep(3000);
		return 0x003;
	}
	
	time(&Cur_Time);
	Now=gmtime(&Cur_Time);
	snprintf(Time_Handel,20,"%d:%d:%d",8+Now->tm_hour,Now->tm_min,Now->tm_sec);
	
	FILE*Command02;
	Command02=popen("net start |findstr SSH","r");
	fgets(Buffer_X,sizeof(Buffer_X),Command02);
	fclose(Command02);
	
	if(strlen(Buffer_X)==0)
	{
		printf("[\033[32m+\033[0m] \033[1m%s\033[0m\t\033[1;34m���� SSH ����...",Time_Handel);
		if(system("net start sshd 1>$null 2>&1")!=-1)
		{
			printf("��ɡ�\033[0m\n");
		}
		else
		{
			time(&Cur_Time);
			Now=gmtime(&Cur_Time);
			snprintf(Time_Handel,20,"%d:%d:%d",8+Now->tm_hour,Now->tm_min,Now->tm_sec);
			
			printf("\033[0m\n\033[1m[\033[1;31m-\033[0m\033[1m]\033[0m \033[1m%s\033[0m\t\033[1;31mSSH�������쳣��\033[0m",Time_Handel); 
			Sleep(3000);
			return 0x004;
		}
	}
	else
	{
		printf("[\033[32m+\033[0m] \033[1m%s\033[0m\t\033[1;34m��⵽ SSH �����ѿ�����\033[0m\n",Time_Handel);
	}
	
	memset(Buffer_X,0,sizeof(Buffer_X));
	SetWindowLong(hwnd,GWL_STYLE,(l_WinStyle | WS_POPUP | WS_MAXIMIZE) & ~WS_CAPTION & ~WS_THICKFRAME & ~WS_BORDER);
	SetWindowPos(hwnd, HWND_TOP, cx/2, 0, cx/2, cy/2, 0);
	
	FILE*Env_Tmp_Pipe_02;
	Env_Tmp_Pipe_02=fopen(Env_Path_03, "w+");
	fprintf(Env_Tmp_Pipe_02,"0");
	fclose(Env_Tmp_Pipe_02);
	
	FILE*Env_Tmp_Pipe_03;
	Env_Tmp_Pipe_03=fopen(Env_Path_04,"w+");
	fprintf(Env_Tmp_Pipe_03,"1");
	fclose(Env_Tmp_Pipe_03);
	
	Sleep(100); 
	system("start /i C:\\Users\\Public\\SSHShell\\SSHDMonitor.exe");
	Sleep(1200);
	system("start /i C:\\Users\\Public\\SSHShell\\CommandMonitor.exe");
	Sleep(1200);
	system("start /i C:\\Users\\Public\\SSHShell\\ResultMonitor.exe");

	Sleep(1200); 
	Node_01:
	time(&Cur_Time);
	Now=gmtime(&Cur_Time);
	snprintf(Time_Handel,20,"%d:%d:%d",8+Now->tm_hour,Now->tm_min,Now->tm_sec);
	
	printf("[\033[32m+\033[0m] \033[1m%s\033[0m\t\033[34m����pipe�ܵ�...",Time_Handel);
	while(Tmp_Flag_03==1)
	{
		FILE*Command03;
		Command03=popen("tasklist -v |findstr kali |findstr sshd.exe","r");
		fgets(Buffer_X,sizeof(Buffer_X),Command03); 
		pclose(Command03);
		if(strlen(Buffer_X)>85)
		{
			printf("��ɡ�\033[0m\n");
			break;
		}
		else
		{
			Sleep(1000);
		}
		memset(Buffer_X,0,sizeof(Buffer_X));
		
		if(Cat_Command[0]=='1')
		{
			time(&Cur_Time);
			Now=gmtime(&Cur_Time);
			snprintf(Time_Handel,20,"%d:%d:%d",8+Now->tm_hour,Now->tm_min,Now->tm_sec);
			
			printf("\033[0m\n[\033[33m!\033[0m] \033[1m%s\033[0m\t\033[33mδ��⵽�۹޽��̣����û������ƺ��ѽ����������Ƿ���ڴ�������Լ��������Ƿ��Թ���Ա���������\033[0m\n",Time_Handel);
			Tmp_Flag_03=0;
		} 
		FILE*Command04;
		Command04=popen("type C:\\Users\\kali\\tmp1.txt 2>$null","r");
		fgets(Cat_Command,2,Command04);
		pclose(Command04);
	}
	memset(Buffer_X,0,sizeof(Buffer_X));
	
	time(&Cur_Time);
	Now=gmtime(&Cur_Time);
	snprintf(Time_Handel,20,"%d:%d:%d",8+Now->tm_hour,Now->tm_min,Now->tm_sec);
	
	printf("[\033[32m+\033[0m] \033[1m%s\033[0m\t\033[34m���ڼ���������...",Time_Handel);
	Sleep(2000);
	while(Tmp_Flag_03==1)
	{
		FILE*Command05;
		Command05=popen("tasklist -v |findstr kali |findstr Winbacsh.exe","r");
		fgets(Buffer_X,sizeof(Buffer_X),Command05);
		pclose(Command05);
		if(strlen(Buffer_X)>10)
		{
			printf("��ɡ�\033[0m\n\n");
			break;
		}
		else
		{
			Sleep(1000);
		}
		memset(Buffer_X,0,sizeof(Buffer_X));
	}
	if(Tmp_Flag_03==0)
	{
		printf("��ɡ�\033[0m\n");
	}
	system("start \"�ն˼����\" /i /min C:\\Users\\Public\\SSHShell\\vshost.exe");
	memset(Buffer_X,0,sizeof(Buffer_X));
	
	time(&Cur_Time);
	Now=gmtime(&Cur_Time);
	snprintf(Time_Handel,20,"%d:%d:%d",8+Now->tm_hour,Now->tm_min,Now->tm_sec);
	
	printf("[\033[32m+\033[0m] \033[1m%s\033[0m\t\033[34m�������� \033[0m\033[31mWinbash...\033[0m\n",Time_Handel);
	Sleep(100);
	
	FILE*Command06;
	Command06=popen("type C:\\ProgramData\\ssh\\logs\\sshd.log 2>$null|findstr \"Accepted password for kali\" 1>tmp00.txt & powershell -c \"cat tmp00.txt -Tail 1 2>$null\"","r");
	fgets(Buffer_X,sizeof(Buffer_X),Command06);
	pclose(Command06);
	remove("tmp00.txt");

	Tmp_Flag_03=0;
	Tmp_Flag_04=1;
	Tmp_Flag_05=0;
	
	while(1)
	{
		if(Buffer_X[Tmp_Flag_03+Tmp_Flag_05]==From[Tmp_Flag_03])
		{
			strncpy(Tmp_Flag_01,Buffer_X+Tmp_Flag_03+Tmp_Flag_05,strlen(From));
			for(;Tmp_Flag_03<strlen(From) && Tmp_Flag_04==1;Tmp_Flag_03++)
			{
				if(Tmp_Flag_01[Tmp_Flag_03]!=From[Tmp_Flag_03])
				{
					Tmp_Flag_04=0;
				}
			}

			if(Tmp_Flag_04==0)
			{
				Tmp_Flag_03=0;
				Tmp_Flag_05++;
				Tmp_Flag_04=1;
			}
			else
			{
				for(Tmp_Flag_04=0;;Tmp_Flag_04++)
				{
					Att_IP[Tmp_Flag_04]=Buffer_X[Tmp_Flag_03+Tmp_Flag_05+Tmp_Flag_04];
					if(Buffer_X[Tmp_Flag_03+Tmp_Flag_05+Tmp_Flag_04]==' ')
					{
						break;
					}
				}
				time(&Cur_Time);
				Now=gmtime(&Cur_Time);
				snprintf(Time_Handel,20,"%d:%d:%d",8+Now->tm_hour,Now->tm_min,Now->tm_sec);
				
				printf("\033[1m[\033[1;32m+\033[0m\033[1m]\033[0m \033[1m%s\033[0m\t\033[1;34m��⵽��IP��%s��SSH�����ѽ����� localhost<---%s��\033[0m\n",Time_Handel,Att_IP,Att_IP);
				break;
			}
		}
		else
		{
			Tmp_Flag_05++;
		}
	}	
	memset(Buffer_X,0,sizeof(Buffer_X));
	
	time(&Cur_Time);
	Now=gmtime(&Cur_Time);
	snprintf(Time_Handel,20,"%d:%d:%d",8+Now->tm_hour,Now->tm_min,Now->tm_sec);
	
	printf("[\033[32m+\033[0m] \033[1m%s\033[0m\t\033[34m��ʼ��ء�\n\033[0m",Time_Handel);
	
	FILE*Env_Tmp_Pipe_04;
	Env_Tmp_Pipe_04=fopen(Env_Path_03, "w+");
	fprintf(Env_Tmp_Pipe_04,"1");
	fclose(Env_Tmp_Pipe_04);
	
	while(1)
	{
		FILE*Command07;
		Command07=popen("tasklist -v |findstr kali |findstr Winbacsh.exe","r");
		fgets(Buffer_X,sizeof(Buffer_X),Command07);
		pclose(Command07);
		if(strlen(Buffer_X)<10)
		{
			time(&Cur_Time);
			Now=gmtime(&Cur_Time);
			snprintf(Time_Handel,20,"%d:%d:%d",8+Now->tm_hour,Now->tm_min,Now->tm_sec);
			
			printf("[\033[32m+\033[0m] \033[1m%s\033[0m\t\033[34m��⵽�����ѶϿ���\033[0m\n",Time_Handel);
			break;
		}
		else
		{
			Sleep(1000);
		}
		memset(Buffer_X,0,sizeof(Buffer_X));
	}
		
	printf("[?] Ҫ��ֹ�۹��𣺣�Y/n����");
	ANS=getchar();
	
	time(&Cur_Time);
	Now=gmtime(&Cur_Time);
	snprintf(Time_Handel,20,"%d:%d:%d",8+Now->tm_hour,Now->tm_min,Now->tm_sec);

	switch(ANS)
	{
		case 'Y'|'y' :
			Tmp_Flag_04=0;
			remove(Env_Path_04); 
			FILE*Env_Tmp_Pipe_05;
			Env_Tmp_Pipe_05=fopen(Env_Path_03, "w");
			fprintf(Env_Tmp_Pipe_05,"0");
			fclose(Env_Tmp_Pipe_05);
			printf("[\033[32m+\033[0m] \033[1m%s\033[0m\t\033[34m��ֹ��\n\033[0m",Time_Handel);
			break;
			
		case 'n'|'N' :
			printf("[\033[32m+\033[0m] \033[1m%s\033[0m\t\033[34m��������SSH���ӡ�\n\033[0m",Time_Handel); 
			goto Node_01;
			
		default:
			Tmp_Flag_04=0;
			remove(Env_Path_04);
			FILE*Env_Tmp_Pipe_06;
			Env_Tmp_Pipe_06=fopen(Env_Path_03, "w");
			fprintf(Env_Tmp_Pipe_06,"0");
			fclose(Env_Tmp_Pipe_06);
			printf("[\033[32m+\033[0m] \033[1m%s\033[0m\t\033[34m��ֹ��\n\033[0m",Time_Handel);
			break;
	}
	Sleep(5100);
	SetWindowLong(hwnd,GWL_STYLE,(l_WinStyle | WS_POPUP | WS_MAXIMIZE) & ~WS_CAPTION & ~WS_THICKFRAME & ~WS_BORDER);
	SetWindowPos(hwnd, HWND_TOP, 0, 0, cx, cy, 0);
	
	time(&Cur_Time);
	Now=gmtime(&Cur_Time);
	snprintf(Time_Handel,20,"%d:%d:%d",8+Now->tm_hour,Now->tm_min,Now->tm_sec);
	
	printf("[\033[32m+\033[0m] \033[1m%s\033[0m\t\033[1;34m����ֹͣSSH����...",Time_Handel);
	if(system("net stop sshd 1>$null")!=-1)
	{
		printf("��ɡ�\033[0m\n");
	}
	else
	{
		time(&Cur_Time);
		Now=gmtime(&Cur_Time);
		snprintf(Time_Handel,20,"%d:%d:%d",8+Now->tm_hour,Now->tm_min,Now->tm_sec);
		
		printf("\033[0m\n[\033[31m-\033[0m] \033[1m%s\033[0m\t\033[31mSSH����ر��쳣��\033[0m",Time_Handel); 
		FILE*Env_Tmp_Pipe_07;
		Env_Tmp_Pipe_07=fopen(Env_Path_03, "w");
		fprintf(Env_Tmp_Pipe_07,"0");
		fclose(Env_Tmp_Pipe_07);
		
		return 0x005;
	}
	
	time(&Cur_Time);
	Now=gmtime(&Cur_Time);
	snprintf(Time_Handel,20,"%d:%d:%d",8+Now->tm_hour,Now->tm_min,Now->tm_sec);
	
	printf("[\033[32m+\033[0m] \033[1m%s\033[0m\t\033[34m��������ļ�...",Time_Handel);
	Sleep(900);
	remove(Env_Path_03);
	printf("��ɡ�\033[0m\n");
	
	time(&Cur_Time);
	Now=gmtime(&Cur_Time);
	snprintf(Time_Handel,20,"%d:%d:%d",8+Now->tm_hour,Now->tm_min,Now->tm_sec);
	
	printf("[\033[32m+\033[0m] \033[1m%s\033[0m\t\033[34m��ɡ�\033[0m\n",Time_Handel);
	Sleep(2000);
	
	printf("��лʹ�ã�����ENTER�˳�����\n==================================\n");
	getch();getch();
	
	return 0x000;
	
}

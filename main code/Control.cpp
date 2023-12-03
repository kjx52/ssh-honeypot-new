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

//以下为默认存储路径。
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
	printf("                                                               联合出品\n\n");
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
	printf("     ***\033[1;33m\\ \\/ _ \\/ \033[0m\033[31m|\033[7;31m \033[0m\033[31m|\033[0m\033[1;33m |  \\ |\033[0m******\033[1;33m| [__] | <_> \\ //||—\\\\\033[0m***");
	printf("              \033[31m    .: ; | ; |'.  :   \033[0m\033[1;44m    ____ \033[0m   \033[1;43m _______ \033[0m  \n");
	printf("  -------\033[1;33m\\__/\033[0m-\033[1;33m\\__/\033[0m\033[31m|\033[7;31m_\033[0m\033[31m|\033[0m\033[1;33m_|\033[0m--\033[1;33m|_|\033[0m------\033[1;33m\\_______\\___/\\|/\033[0m-\033[1;33m||\033[0m--\033[1;33m||\033[0m---     ");
	printf("         \033[31m      .; | ; |  : |   \033[0m\033[1;44m  .'___/ \033[0m   \033[1;43m |__|__| \033[0m  \n");
	printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	printf("           \033[31m    .: ; | | :  | |   \033[0m\033[1;44m  '___.  \033[0m   \033[1;43m   |||   \033[0m  \n");
	printf("=====================================================================");
	printf("     \033[31m       | :-.'   : '.. \033[0m\033[1;44m /____.' \033[0m   \033[1;43m   |_|   \033[0m  \n");
	printf("                                                                          \033[31m      -.'_.--._  : /  \033[0m                         \n");
	printf("                \033[35m[ Bash Shell for Windows ]\033[0m                                \033[31m      .:;.:_   '. ' \033[0m\033[35m[ Rust Engine for Windows ]\033[0m \n");
	printf("                       \033[35m[ 内测：6.2 ]\033[0m                                      \033[31m    .''     ':/'      \033[0m      \033[35m[内测：1.4]\033[0m        \n");
	printf("                                                                          \033[31m            |         \033[0m                         \n");
	printf("                       \033[1;30mJessarin000 作\033[0m                                     \033[31m            |         \033[0m     \033[1;30mJessarin000 作\033[0m      \n");
	printf("                                                                          \033[31m            |         \033[0m                         \n");
	printf("\n\033[1;30m/*\033[0m\033[1mWindows SSH蜜罐控制进程\033[0m\033[1;30m*/\033[0m\n\n");
	printf("\033[1;30m作者 ： Jessarin000\n");
	printf("时间 ： 2023-10-23\033[0m\n\n");
	printf("\033[34m基于 Windows11 平台开发的 SSH 蜜罐 ( 版本 ： 公测1.4 ) 。\n");
	printf("本程序可以结合多种方式动态监测入侵者动向，高度复现 Linux 蜜罐场景！\n\n\033[0m");
	printf("    [\033[32m+\033[0m] \033[36mLinux 蜜罐项目详见本人Github库 < \033[4mhttps://github.com/kjx52/ssh-honeypot-new\033[0m\033[36m >\033[0m\n");
	printf("    [\033[32m+\033[0m] \033[33m有关Linux蜜罐的详细信息见 < \033[4mhttps://xz.aliyun.com/t/12884\033[0m\033[33m >\033[0m\n");
	printf("    [\033[32m+\033[0m] \033[32m有任何意见或建议请联系作者 < \033[4mkjx52@outlook.com\033[0m\033[32m >。\033[0m\n\n");
	printf("\033[1;35m* 本程序应配合Bacsh终端使用。\n");
	printf("* 要求 Windows 平台版本大于 7 。\n");
	printf("* 由于需要检查或终止进程，请以管理员的身份运行此程序。\n");
	printf("* 有任何意见或建议请联系作者。\033[0m\n\n");
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
		printf("\033[1m[\033[31m-\033[0m\033[1m]\033[0m \033[1;31m核心文件异常，请在运行本程序之前首先运行SSH蜜罐全面部署程序。 Critical Code 01\033[0m");
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
	
	printf("[\033[32m+\033[0m] \033[1m%s\033[0m\t\033[1;34m校验文件完整性...\033[s",Time_Handel);
	strcpy(FnW,"powershell -c \"Get-FileHash ");
	strcat(FnW,FnM);
	strcat(FnW," -Algorithm SHA256 | fl\"");
	Sleep(50);
	system(FnW);
	printf("\033[u成功。\033[0m\n\n\n\n\n\n");
	
	time(&Cur_Time);
	Now=gmtime(&Cur_Time);
	snprintf(Time_Handel,20,"%d:%d:%d",8+Now->tm_hour,Now->tm_min,Now->tm_sec);

	printf("[\033[32m+\033[0m] \033[1m%s\033[0m\t\033[1;34m检查终端状态-",Time_Handel);
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
	printf("\b \b\b \b-完成。\033[0m");
	printf("\033[0m\n");
	
	time(&Cur_Time);
	Now=gmtime(&Cur_Time);
	snprintf(Time_Handel,20,"%d:%d:%d",8+Now->tm_hour,Now->tm_min,Now->tm_sec);
	
	printf("\033[1m[\033[1;32m+\033[0m\033[1m]\033[0m \033[1m%s\033[0m\t\033[34m正在初始化...\033[0m\n",Time_Handel);
	
	if(Tmp_Flag_02==1)
	{
		printf("\033[1;7;34;43m  ");
		for(Tmp_Flag_06=0;Tmp_Flag_06<20;Tmp_Flag_06++)
		{
			printf("_");
		}
		printf("     .-==-.   这是一个  \n");
		printf("+[");
		for(Tmp_Flag_06=0;Tmp_Flag_06<20;Tmp_Flag_06++)
		{
			printf("_");
		}
		printf("]@  \033[s.[=##=]. 等离子馅的 \033[0m\n");
		printf("\033[1;7;34;43m  ");
		for(Tmp_Flag_06=0;Tmp_Flag_06<20;Tmp_Flag_06++)
		{
			printf(" ");
		}
		printf("     \\-__-/     汉堡    \033[0m\n\033[u");
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
		printf("\033[34m完成。\033[0m\n\33[?25h");
	}
	else
	{
		printf("\033[1;7;34;43m  ");
		for(Tmp_Flag_06=0;Tmp_Flag_06<101;Tmp_Flag_06++)
		{
			printf("_");
		}
		printf("     .-==-.   这是一个  \n");
		printf("+[");
		for(Tmp_Flag_06=0;Tmp_Flag_06<101;Tmp_Flag_06++)
		{
			printf("_");
		}
		printf("]@  \033[s.[=##=]. 等离子馅的 \033[0m\n");
		printf("\033[1;7;34;43m  ");
		for(Tmp_Flag_06=0;Tmp_Flag_06<101;Tmp_Flag_06++)
		{
			printf(" ");
		}
		printf("     \\-__-/     汉堡    \033[0m\n\033[u");
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
		printf("\033[34m.完成。\033[0m\n\33[?25h");
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
	
	printf("[\033[32m+\033[0m] \033[1m%s\033[0m\t\033[1;34m检查支持环境...",Time_Handel);
	FILE*Command01;
	Command01=popen("sc.exe query state= all |findstr SERVICE_NAME |findstr sshd","r");
	fgets(Buffer_X,sizeof(Buffer_X),Command01);
	fclose(Command01);
	if(Buffer_X!=NULL)
	{
		printf("完成。\033[0m\n");
	}
	else
	{
		time(&Cur_Time);
		Now=gmtime(&Cur_Time);
		snprintf(Time_Handel,20,"%d:%d:%d",8+Now->tm_hour,Now->tm_min,Now->tm_sec);
		
		printf("\033[0m\n\033[1m[\033[0m\033[31m-\033[0m\033[1m]\033[0m \033[1m%s\033[0m\t\033[31m未检测到Windows_OpenSSH服务，紧急停止！Critical Code 02\n\033[0m",Time_Handel);
		Sleep(3000);
		return 0x002;
	}
	
	time(&Cur_Time);
	Now=gmtime(&Cur_Time);
	snprintf(Time_Handel,20,"%d:%d:%d",8+Now->tm_hour,Now->tm_min,Now->tm_sec);
	
	printf("[\033[32m+\033[0m] \033[1m%s\033[0m\t\033[34m检查支持文件...",Time_Handel);
	if((access(Log_Path_01,F_OK))!=-1 || (access(Log_Path_02,F_OK))!=-1)
	{
		printf("\033[0m\n[\033[32m+\033[0m] \033[1m%s\033[0m\t\033[34m检测到历史文件。\n\033[0m",Time_Handel);
		printf("[?] 要删除它们吗（Y/n）：");
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
						printf("[\033[32m+\033[0m] \033[1m%s\033[0m\t\033[34m文件Command.txt删除成功。\n\033[0m",Time_Handel);
					}
					else 
					{
						printf("[\033[33m!\033[0m] \033[1m%s\033[0m\t\033[33m无法删除文件Command.txt。\n\033[0m",Time_Handel);
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
						printf("[\033[32m+\033[0m] \033[1m%s\033[0m\t\033[34m文件Result.txt删除成功。\n\033[0m",Time_Handel);
					}
					else 
					{
						printf("[\033[33m!\033[0m] \033[1m%s\033[0m\t\033[33m无法删除文件Result.txt。\n\033[0m",Time_Handel);
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
						printf("[\033[32m+\033[0m] \033[1m%s\033[0m\t\033[34m文件 Command.txt 删除成功。\n\033[0m",Time_Handel);
					}
					else 
					{
						printf("[\033[33m!\033[0m] \033[1m%s\033[0m\t\033[33m无法删除文件 Command.txt。\n\033[0m",Time_Handel);
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
						printf("[\033[32m+\033[0m] \033[1m%s\033[0m\t\033[34m文件 Result.txt 删除成功。\n\033[0m",Time_Handel);
					}
					else 
					{
						printf("[\033[33m!\033[0m] \033[1m%s\033[0m\t\033[33m无法删除文件 Result.txt。\n\033[0m",Time_Handel);
					}
				}
				break;
		}
	}
	else
	{
		printf("完成。\033[0m\n");
	}
	memset(Buffer_X,0,sizeof(Buffer_X));
	
	time(&Cur_Time);
	Now=gmtime(&Cur_Time);
	snprintf(Time_Handel,20,"%d:%d:%d",8+Now->tm_hour,Now->tm_min,Now->tm_sec);
	
	printf("[\033[32m+\033[0m] \033[1m%s\033[0m\t\033[34m检查守护进程...",Time_Handel);
	if((access("C:\\Users\\Public\\SSHShell\\vshost.exe",X_OK))!=-1)
	{
		printf("完成。\033[0m\n");
	}
	else
	{
		time(&Cur_Time);
		Now=gmtime(&Cur_Time);
		snprintf(Time_Handel,20,"%d:%d:%d",8+Now->tm_hour,Now->tm_min,Now->tm_sec);

		printf("\033[0m\n\033[1m[\033[0m\033[31m-\033[0m\033[1m]\033[0m \033[1m%s\033[0m\t\033[31m守护进程异常，紧急停止！Critical Code 03\n\033[0m",Time_Handel);
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
		printf("[\033[32m+\033[0m] \033[1m%s\033[0m\t\033[1;34m开启 SSH 服务...",Time_Handel);
		if(system("net start sshd 1>$null 2>&1")!=-1)
		{
			printf("完成。\033[0m\n");
		}
		else
		{
			time(&Cur_Time);
			Now=gmtime(&Cur_Time);
			snprintf(Time_Handel,20,"%d:%d:%d",8+Now->tm_hour,Now->tm_min,Now->tm_sec);
			
			printf("\033[0m\n\033[1m[\033[1;31m-\033[0m\033[1m]\033[0m \033[1m%s\033[0m\t\033[1;31mSSH服务开启异常。\033[0m",Time_Handel); 
			Sleep(3000);
			return 0x004;
		}
	}
	else
	{
		printf("[\033[32m+\033[0m] \033[1m%s\033[0m\t\033[1;34m检测到 SSH 服务已开启。\033[0m\n",Time_Handel);
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
	
	printf("[\033[32m+\033[0m] \033[1m%s\033[0m\t\033[34m启动pipe管道...",Time_Handel);
	while(Tmp_Flag_03==1)
	{
		FILE*Command03;
		Command03=popen("tasklist -v |findstr kali |findstr sshd.exe","r");
		fgets(Buffer_X,sizeof(Buffer_X),Command03); 
		pclose(Command03);
		if(strlen(Buffer_X)>85)
		{
			printf("完成。\033[0m\n");
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
			
			printf("\033[0m\n[\033[33m!\033[0m] \033[1m%s\033[0m\t\033[33m未检测到蜜罐进程，但用户连接似乎已建立。请检查是否存在错误操作以及本程序是否以管理员身份启动。\033[0m\n",Time_Handel);
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
	
	printf("[\033[32m+\033[0m] \033[1m%s\033[0m\t\033[34m正在加密数据流...",Time_Handel);
	Sleep(2000);
	while(Tmp_Flag_03==1)
	{
		FILE*Command05;
		Command05=popen("tasklist -v |findstr kali |findstr Winbacsh.exe","r");
		fgets(Buffer_X,sizeof(Buffer_X),Command05);
		pclose(Command05);
		if(strlen(Buffer_X)>10)
		{
			printf("完成。\033[0m\n\n");
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
		printf("完成。\033[0m\n");
	}
	system("start \"终端检测仪\" /i /min C:\\Users\\Public\\SSHShell\\vshost.exe");
	memset(Buffer_X,0,sizeof(Buffer_X));
	
	time(&Cur_Time);
	Now=gmtime(&Cur_Time);
	snprintf(Time_Handel,20,"%d:%d:%d",8+Now->tm_hour,Now->tm_min,Now->tm_sec);
	
	printf("[\033[32m+\033[0m] \033[1m%s\033[0m\t\033[34m正在启动 \033[0m\033[31mWinbash...\033[0m\n",Time_Handel);
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
				
				printf("\033[1m[\033[1;32m+\033[0m\033[1m]\033[0m \033[1m%s\033[0m\t\033[1;34m检测到与IP：%s的SSH连接已建立。 localhost<---%s。\033[0m\n",Time_Handel,Att_IP,Att_IP);
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
	
	printf("[\033[32m+\033[0m] \033[1m%s\033[0m\t\033[34m开始监控。\n\033[0m",Time_Handel);
	
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
			
			printf("[\033[32m+\033[0m] \033[1m%s\033[0m\t\033[34m检测到连接已断开。\033[0m\n",Time_Handel);
			break;
		}
		else
		{
			Sleep(1000);
		}
		memset(Buffer_X,0,sizeof(Buffer_X));
	}
		
	printf("[?] 要终止蜜罐吗：（Y/n）：");
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
			printf("[\033[32m+\033[0m] \033[1m%s\033[0m\t\033[34m终止。\n\033[0m",Time_Handel);
			break;
			
		case 'n'|'N' :
			printf("[\033[32m+\033[0m] \033[1m%s\033[0m\t\033[34m继续监听SSH连接。\n\033[0m",Time_Handel); 
			goto Node_01;
			
		default:
			Tmp_Flag_04=0;
			remove(Env_Path_04);
			FILE*Env_Tmp_Pipe_06;
			Env_Tmp_Pipe_06=fopen(Env_Path_03, "w");
			fprintf(Env_Tmp_Pipe_06,"0");
			fclose(Env_Tmp_Pipe_06);
			printf("[\033[32m+\033[0m] \033[1m%s\033[0m\t\033[34m终止。\n\033[0m",Time_Handel);
			break;
	}
	Sleep(5100);
	SetWindowLong(hwnd,GWL_STYLE,(l_WinStyle | WS_POPUP | WS_MAXIMIZE) & ~WS_CAPTION & ~WS_THICKFRAME & ~WS_BORDER);
	SetWindowPos(hwnd, HWND_TOP, 0, 0, cx, cy, 0);
	
	time(&Cur_Time);
	Now=gmtime(&Cur_Time);
	snprintf(Time_Handel,20,"%d:%d:%d",8+Now->tm_hour,Now->tm_min,Now->tm_sec);
	
	printf("[\033[32m+\033[0m] \033[1m%s\033[0m\t\033[1;34m正在停止SSH服务...",Time_Handel);
	if(system("net stop sshd 1>$null")!=-1)
	{
		printf("完成。\033[0m\n");
	}
	else
	{
		time(&Cur_Time);
		Now=gmtime(&Cur_Time);
		snprintf(Time_Handel,20,"%d:%d:%d",8+Now->tm_hour,Now->tm_min,Now->tm_sec);
		
		printf("\033[0m\n[\033[31m-\033[0m] \033[1m%s\033[0m\t\033[31mSSH服务关闭异常。\033[0m",Time_Handel); 
		FILE*Env_Tmp_Pipe_07;
		Env_Tmp_Pipe_07=fopen(Env_Path_03, "w");
		fprintf(Env_Tmp_Pipe_07,"0");
		fclose(Env_Tmp_Pipe_07);
		
		return 0x005;
	}
	
	time(&Cur_Time);
	Now=gmtime(&Cur_Time);
	snprintf(Time_Handel,20,"%d:%d:%d",8+Now->tm_hour,Now->tm_min,Now->tm_sec);
	
	printf("[\033[32m+\033[0m] \033[1m%s\033[0m\t\033[34m清除缓存文件...",Time_Handel);
	Sleep(900);
	remove(Env_Path_03);
	printf("完成。\033[0m\n");
	
	time(&Cur_Time);
	Now=gmtime(&Cur_Time);
	snprintf(Time_Handel,20,"%d:%d:%d",8+Now->tm_hour,Now->tm_min,Now->tm_sec);
	
	printf("[\033[32m+\033[0m] \033[1m%s\033[0m\t\033[34m完成。\033[0m\n",Time_Handel);
	Sleep(2000);
	
	printf("感谢使用，键入ENTER退出程序。\n==================================\n");
	getch();getch();
	
	return 0x000;
	
}

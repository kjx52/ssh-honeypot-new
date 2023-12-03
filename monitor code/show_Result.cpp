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

main()
{
	Sleep(300); 
	HWND hwnd = GetForegroundWindow();
	int cx = GetSystemMetrics(SM_CXSCREEN);
	int cy = GetSystemMetrics(SM_CYSCREEN);

	LONG l_WinStyle = GetWindowLong(hwnd,GWL_STYLE);
	SetWindowLong(hwnd,GWL_STYLE,(l_WinStyle | WS_POPUP | WS_MAXIMIZE) & ~WS_CAPTION & ~WS_THICKFRAME & ~WS_BORDER);
	SetWindowPos(hwnd, HWND_TOP, 0, cy/2, cx/2, cy/2, 0);
	system("cls"); 
	
	int BufSize_X=MAX_COMPUTERNAME_LENGTH + 1;
	char Tmp_Flag_01[3];
	char Computer_Name[BufSize_X];
	char Type_Command[]="type C:\\Users\\kali\\tmp2.txt 2>$null";
	
	FILE*Command_02;
	Command_02=popen(Type_Command,"r");
	fgets(Tmp_Flag_01,2,Command_02);
	pclose(Command_02);

	while((access("C:\\Users\\Public\\tmp22.txt",F_OK))!=-1)
	{
		while(Tmp_Flag_01[0]=='1')
		{
			system("cls");
			FILE*Command_01;
			Command_01=popen(Type_Command,"r");
			fgets(Tmp_Flag_01,2,Command_01);
			pclose(Command_01);
			
			DWORD BufSize_Y = BufSize_X;
			GetComputerName(Computer_Name, &BufSize_Y);
			
			time(&Cur_Time);
			Now=gmtime(&Cur_Time);
			snprintf(Time_Handel,20,"%d-%d-%d %d:%d:%d",1900+Now->tm_year,1+Now->tm_mon,Now->tm_mday,8+Now->tm_hour,Now->tm_min,Now->tm_sec);
			
			printf("\t\033[1m[\033[1;32m+\033[0m\033[1m]\033[0m \033[1;34mCMD 模拟执行用户输入的结果：\033[0m\n");
			printf("Every 1.0s: cat C:\\Users\\Public\\History\\Result.txt -Tail 10\n");
			printf("    %s:%s\n\n",Computer_Name,Time_Handel);
			system("powershell -c \"cat C:\\Users\\Public\\History\\Result.txt -Tail 10 2>$null\"");
			Sleep(1000);
		}
		system("cls");
		printf("  Waiting....");
		Sleep(1000);
		
		FILE*Command_03;
		Command_03=popen(Type_Command,"r");
		fgets(Tmp_Flag_01,2,Command_03);
		pclose(Command_03);
	}
	
	printf("\n\n[+] 检测到终止信号，停止监测。\n"); 
	Sleep(5000);
	return 0; 
}

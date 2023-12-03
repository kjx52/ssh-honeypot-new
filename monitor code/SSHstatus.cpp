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
	Sleep(200); 
	HWND hwnd = GetForegroundWindow();
	int cx = GetSystemMetrics(SM_CXSCREEN);
	int cy = GetSystemMetrics(SM_CYSCREEN);

	LONG l_WinStyle = GetWindowLong(hwnd,GWL_STYLE);
	SetWindowLong(hwnd,GWL_STYLE,(l_WinStyle | WS_POPUP | WS_MAXIMIZE) & ~WS_CAPTION & ~WS_THICKFRAME & ~WS_BORDER);
	SetWindowPos(hwnd, HWND_TOP, cx/2, cy/2, cx/2, cy/2, 0);
	system("cls"); 
	
	int BufSize_X=MAX_COMPUTERNAME_LENGTH + 1;
	char Computer_Name[BufSize_X];
	
	Sleep(5000);
	while((access("C:\\Users\\Public\\tmp22.txt",F_OK))!=-1)
	{
		DWORD BufSize_Y=BufSize_X;
		GetComputerName(Computer_Name, &BufSize_Y);
		
		time(&Cur_Time);
		Now=gmtime(&Cur_Time);
		snprintf(Time_Handel,20,"%d-%d-%d %d:%d:%d",1900+Now->tm_year,1+Now->tm_mon,Now->tm_mday,8+Now->tm_hour,Now->tm_min,Now->tm_sec);
		
		printf("\t\033[1m[\033[1;32m+\033[0m\033[1m]\033[0m \033[1;34mSSHD ·þÎñ×´Ì¬£º\033[0m\n");
		printf("Every 1.0s: systemctl status sshd\n");
		printf("    %s:%s\n\n",Computer_Name,Time_Handel);
		system("sc.exe query SSHD");
		Sleep(1000);
		system("cls");	
	}
	
	printf("\n\n[+] ¼ì²âµ½ÖÕÖ¹ÐÅºÅ£¬Í£Ö¹¼à²â¡£\n"); 
	Sleep(5000);
	return 0; 
}

#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <windows.h>

main()
{
	int OS;
	OS=1;
	 
	#ifdef _WIN32
		#ifdef _WIN64
			OS=12864;
		#else 
			OS=12832;
		#endif
	#elif __linux__
		OS=64
	#elif __unix__
		OS=254
	#else
		OS=999;
	#endif
	
	Sleep(2000);
	system("cls");
	printf(" +---=[ Try Harder(F) ]:||:=-----------------------------------------+\n");
	printf(" |   \033[1;32m__  __  __   _                    ______    ______   __   __\033[0m    |\n");
	printf(" |   \033[1;32m|\033[0m\033[1;42m00\033[0m \033[1;32m|\033[0m\033[1;42m00\033[0m \033[1;32m|\033[0m\033[1;42m00\033[0m \033[1;32m[\033[0m\033[1;42m000\033[0m                 \033[1;32m| \033[0m\033[1;42m000000\033[0m  \033[1;32m| \033[0m\033[1;42m000000\033[0m  \033[1;32m|\033[0m\033[1;42m00\033[0m  \033[1;32m|\033[0m\033[1;42m00\033[0m   |\n");
	printf(" |   \033[1;32m|\033[0m\033[1;42m00\033[0m \033[1;32m|\033[0m\033[1;42m00\033[0m \033[1;32m|\033[0m\033[1;42m00\033[0m \033[1;32m___  \033[1;32m______  _____\033[0m   \033[1;32m|\033[0m\033[1;42m0000000\033[0m  \033[1;32m|\033[0m\033[1;42m0000000\033[0m  \033[1;32m|\033[0m\033[1;42m00\033[0m\033[1;32m__|\033[0m\033[1;42m00\033[0m   |\n");
	printf(" |   \033[1;32m|\033[0m\033[1;42m00\033[0m \033[1;32m|\033[0m\033[1;42m00\033[0m \033[1;32m|\033[0m\033[1;42m00\033[0m \033[1;32m|\033[0m\033[1;42m000\033[0m \033[1;32m|\033[0m\033[1;42m000000\033[0m \033[1;32m|\033[0m\033[1;42m00000\033[0m  \033[1;32m|\033[0m\033[1;42m000\033[0m\033[1;32m____  |\033[0m\033[1;42m000\033[0m\033[1;32m____  |\033[0m\033[1;42m0000000\033[0m   |\n");
	printf(" |   \033[1;32m|\033[0m\033[1;42m00\033[0m \033[1;32m|\033[0m\033[1;42m00\033[0m \033[1;32m|\033[0m\033[1;42m00\033[0m \033[1;32m|\033[0m\033[1;42m000\033[0m \033[1;32m|\033[0m\033[1;42m000000\033[0m  \033[1;42m00000\033[0m  \033[1;32m|\033[0m\033[1;42m00000000\033[0m \033[1;32m|\033[0m\033[1;42m00000000\033[0m \033[1;32m|\033[0m\033[1;42m0000000\033[0m   |\n");
	printf(" |   \033[1;32m|\033[0m\033[1;42m00\033[0m\033[1;32m_|\033[0m\033[1;42m00\033[0m\033[1;32m_|\033[0m\033[1;42m00\033[0m \033[1;32m|\033[0m\033[1;42m000\033[0m \033[1;32m|\033[0m\033[1;42m00\033[0m \033[1;32m|\033[0m\033[1;42m00\033[0m          \033[1;32m____|\033[0m\033[1;42m000\033[0m  \033[1;32m____|\033[0m\033[1;42m000\033[0m \033[1;32m|\033[0m\033[1;42m00\033[0m  \033[1;32m|\033[0m\033[1;42m00\033[0m   |\n");
	printf(" |    \033[1;42m0000000000\033[0m \033[1;32m|\033[0m\033[1;42m000\033[0m \033[1;32m|\033[0m\033[1;42m00\033[0m \033[1;32m|\033[0m\033[1;42m00\033[0m         \033[1;32m|\033[0m\033[1;42m00000000\033[0m \033[1;32m|\033[0m\033[1;42m00000000\033[0m \033[1;32m|\033[0m\033[1;42m00\033[0m  \033[1;32m|\033[0m\033[1;42m00\033[0m   |\n");
	printf(" |     \033[1;42m00000000\033[0m                        \033[1;42m00000000\033[0m  \033[1;42m00000000\033[0m  \033[1;42m00\033[0m   \033[1;42m00\033[0m   |\n");
	printf(" |                 \033[34m _ _ ___ _ _ ___ _ _ __  ___ ___ \033[0m                 |\n");
	printf(" |              \033[34m-=# | | | | |.| |   | | | | | |  |  #=-\033[0m              |\n");
	printf(" \033[1m|=================\033[0m\033[35m--=:|[ Made By Jessarin000 ]|:=--\033[0m\033[1m=================|\033[0m\n");
	printf("                  \033[34m+ | | |_| | | |__  |  |   |_|  |  +\033[0m                 \n");
	printf("\n\033[1;34m/*SSH 蜜罐全面部署程序*/\n");
	printf(" 作者：Jessarin000\n");
	printf(" 日期：2023-10-25\n");
	printf(" 版本：1.0\033[0m\n\n");
	printf("    本项目为 Linux SSH 蜜罐的分支，用于在 Windows 环境下自动化部署 SSH 弱口令蜜罐项目。\n");
	printf("本项目原理为修改原SSH 默认连接终端 CMD 为指定伪终端Bacsh（Winbash），从而模拟Linux\n");
	printf("下的 Chroot 环境，从而限制攻击者的路径变迁以及代码执行。\n\n");
	printf("    本项目：\n");
	printf("        默认创建账户为 kali，密码为 kjx00000；\n");
	printf("        默认创建目录为 C:\\Users\\kali\\Shell\n");
	printf("        默认无法创建文件。\n");
	printf("        默认蜜罐终端为 Bacsh。\n");
	printf("        （\033[1;31m注意：本项目的正常执行与配套终端 Bacsh 有着直接联系，除非你确定你已经有了更好的选择，否则强烈不建议修改 SSHD 终端配置！\033[0m）\n");
	printf("        默认情况下，攻击者在蜜罐中可使用的命令为：cd，ls，cat，cls以及它们的别名。\n\n");
	printf("    \033[32m*本项目将在未来版本中逐步发布其他命令的补丁，从而让用户可以向 Bacsh 中自行添加所需函数。\033[0m\n\n");
	printf("    \033[35m*有任何意见或建议请联系作者：< \033[4mkjx52@outlook.com\033[0m\033[35m >\033[0m\n\n");
	printf("\033[33m@注意：· 请在默认活动编码为936（中文-简体）的终端环境下启动本项目终端Bacsh，否则可能引发乱码问题，更多语言版本请联系作者。\n");
	printf("@      · 本项目需修改用户变量（添加 SSH 弱口令用户）以及注册表项（ SSH 默认终端），故请以管理员身份运行此程序。\n"); 
	printf("@      · 遇到任何问题或错误请联系作者。\033[0m\n\n");
	Sleep(5000);
	
	char new_line[40] = "SyslogFacility LOCAL0";
    char buf[1024];
	char buffer[1024]="# Logging";
	char *pathvar;
	char pathvar3[50]="net user ";
	char pathvar2[]=" |findstr Administrators";
	char xbuffer[1024];
	char ybuffer[1024]; 
	char key;
	int i;
	system("cls");
	
	i=0;
	pathvar=getenv("USERNAME");
	strcat(pathvar3,pathvar);
	strcat(pathvar3,pathvar2);
	FILE*fp;
	fp = popen(pathvar3,"r");
	fgets(xbuffer,sizeof(xbuffer),fp);
	pclose(fp);
	if(strlen(xbuffer)<14)
	{
		printf("\033[1;31m");
		printf("####################################################\n");
		printf("##                  %% WARNING- %%                  ##\n");
		printf("##    %% THE EXECUTING USER WAS DETECTED THAT %%    ##\n");
		printf("##              %% DOES NOT HAVE THE %%             ##\n");
		printf("##          %% ADMINISTRATOR PRIVILEGES %%          ##\n");
		printf("##                                                ##\n");
		printf("##                    %% 警告 %%                    ##\n");
		printf("##       %% 检测到执行用户不具有管理员权限 %%       ##\n");
		printf("##                                                ##\n");
		printf("##                Critical Code 01                ##\n");
		printf("####################################################\n");
		printf("\033[0m");
		printf("\033[1m[\033[1;31m-\033[0m\033[1m]\033[0m \033[1;31m中止蜜罐部署进程吗（Y/n）：\033[0m");
		scanf("%c",&key);
		switch(key)
		{
			case 'Y'|'y' :
				printf("中止。\n");
				Sleep(2000);
				return 0x369860;
				
			case 'N'|'n' :
				printf("[.] 很好很好，精神可嘉。(@__@)\n");
				break;
			
			default:
				printf("中止。\n");
				Sleep(2000);
				return 0x369860;
		}
	}
	else
	{
		printf("[\033[32m+\033[0m] \033[34m权限校验完成。\033[0m\n");
	}
	memset(xbuffer,0,sizeof(xbuffer));
	Sleep(3000);
	
	printf("[\033[32m+\033[0m] \033[34m检查支持环境【1】...");
	if( OS==12864 || OS==12832 )
	{
		if(OS==12864)
		{
			printf("完成。(检测到的OS：Windows_x64)\033[0m\n");
		}
		if(OS==12832)
		{
			printf("完成。(检测到的OS：Windows_x86)\033[0m\n");
		}
	}
	else
	{
		if(OS==64)
		{
			printf("\033[0m\n[\033[31m-\033[0m] \033[31m抱歉，本程序仅能在 Windows 环境下运行。(检测到的OS：GNU/Linux )\033[0m\n");
			printf("[\033[32m+\033[0m] \033[34m若要部署同类型 Linux 环境下的 SSH 蜜罐项目，请访问 < \033[4mhttps://github.com/kjx52/ssh-honeypot-new\033[0m\033[34m >\033[0m\n");
			Sleep(2000);
			return 0x771904;
		}
		if(OS==254)
		{
			printf("\033[0m\n[\033[31m-\033[0m] \033[31m抱歉，本程序仅能在 Windows 环境下运行。(检测到的OS：Other UNIX OS )\033[0m\n");
			Sleep(2000);
			return 0x965633;
		}
		if(OS==999)
		{
			printf("\033[0m\n[\033[31m-\033[0m] \033[31m抱歉，本程序仅能在 Windows 环境下运行。(检测到的OS：Unidentified OS )\033[0m\n");
			Sleep(2000);
			return 0x779326;
		}
	}
	Sleep(3000);
	
	printf("[\033[32m+\033[0m] \033[34m检查支持环境【2】...");
	FILE*fp3;
	fp3 = popen("sc.exe query state= all |findstr SERVICE_NAME |findstr sshd","r");
	fgets(ybuffer,sizeof(ybuffer),fp3);
	fclose(fp3);
	if(ybuffer!=NULL)
	{
		FILE*fp4;
		fp4 = popen("sshd -v 2>&1 |findstr \"OpenSSH_for_Windows\" |findstr -v \"findstr\"","r");
		fgets(xbuffer,sizeof(xbuffer),fp4);
		fclose(fp4);
		printf("完成。检测到的 OpenSSH 版本：%s\033[0m",xbuffer);
	}
	else
	{
		printf("\033[0m\n\033[1m[\033[31m-\033[0m\033[1m]\033[0m \033[31m未检测到支持环境，紧急停止！Critical Code 02\n\033[0m");
		Sleep(2000);
		return 0x336952;
	}
	memset(ybuffer,0,sizeof(ybuffer));
	memset(xbuffer,0,sizeof(xbuffer));
	Sleep(3000);
	
	printf("[\033[32m+\033[0m] \033[34m尝试向Windows环境中添加弱口令用户...");
	if(system("net user /add kali kjx00000 1>$null 2>&1")!=-1)
	{
		printf("完成。\033[0m\n");
	}
	else
	{
		printf("\033[0m\n[\033[31m-\033[0m] \033[31m添加失败。返回值（-1）。Error Code 01\033[0m");
	}
	Sleep(3000);
	
	printf("[\033[32m+\033[0m] \033[34m尝试修改 ssh_config 以改写日志路径...");
	FILE *fp1;
	fp1 = fopen("C:\\ProgramData\\ssh\\sshd_config", "r+");
	if(fp1 == NULL)
	{
		printf("\033[0m\n[\033[31m-\033[0m] \033[31m操作被拒绝。Error Code 02\033[0m\n");
	}
	else
	{
		while(fgets(buf,sizeof(buf),fp1)!= NULL)
		{
			if(memcmp(new_line,buf,21)!=0)
			{
				if (memcmp(buffer,buf,9)==0)
				{
					fgets(buf,sizeof(buf),fp1);
					fseek(fp1, -strlen(buf)-2, SEEK_CUR);
					break;
				}
			}
			else
			{
				printf("\033[0m\n[\033[32m+\033[0m] \033[34m检测到日志路径已修改。如若二次运行本程序可能造成不必要的缓存文件堆积。\033[0m\n");
				i=1;
				break;
			}
		}
		if(i==0)
		{
			fputs(new_line, fp1);
			printf("完成。\033[0m\n");
		}
	}
	fclose(fp1);
	Sleep(3000);
	
	printf("[\033[32m+\033[0m] \033[34m尝试修改 SSHD 默认终端...");
	if((access("C:\\Users\\Public\\SSHShell\\Winbacsh.exe",F_OK))!=-1)
	{
		if(system("powershell -c \"New-ItemProperty -Path \'HKLM:\\SOFTWARE\\OpenSSH\' -Name DefaultShell -Value \'C:\\Users\\Public\\SSHShell\\Winbacsh.exe\' -PropertyType String -Force 1>$null 2>&1\"")!=-1)
		{
			printf("完成。\033[0m\n");
		}
		else
		{
			printf("\033[0m\n\033[1m[\033[0m\033[1;31m-\033[0m\033[1m]\033[0m \033[1;31m注册表写入失败。返回值（-1）。Critical Code 04\033[0m\n");
			printf("\033[0m\n\033[1m[\033[0m\033[1;31m-\033[0m\033[1m]\033[0m \033[1;31m紧急中止！\033[0m\n");
		}
	}
	else
	{
		printf("\033[0m\n\033[1m[\033[0m\033[1;31m-\033[0m\033[1m]\033[0m \033[1;31m无法定位终端 Bacsh ，请确认已正确安装本程序。Critical Code 03\033[0m\n");
		printf("\033[0m\n\033[1m[\033[0m\033[1;31m-\033[0m\033[1m]\033[0m \033[1;31m紧急中止！\033[0m\n");
		Sleep(2000);
		return 0x695588;
	}
	Sleep(3000);
	
	printf("[\033[32m+\033[0m] \033[34m尝试创建核心文件...");
	if((access("C:\\Users\\kali\\tmp1.txt",F_OK))!=-1)
	{
		printf("\033[0m\n[\033[32m+\033[0m] \033[34m检测到核心文件已存在。跳过步骤。\033[0m\n");
	}
	else
	{
		FILE*fp2;
		fp2=fopen ("C:\\Users\\kali\\tmp1.txt", "w+");
		fprintf(fp2,"0");
		fclose(fp2);
		printf("完成。\033[0m\n");
	}
	Sleep(3000);
	
	i=0;
	printf("[\033[32m+\033[0m] \033[34m尝试修改文件权限...");
	if(system("Icacls \"C:\\Users\\Public\\SSHShell\\Winbacsh.exe\" /grant  kali:RX 2>$null 1>&2")==-1)
	{
		i=1;
		printf("\033[0m\n\033[1m[\033[0m\033[1;31m-\033[0m\033[1m]\033[0m \033[1;31m Bacsh 权限修改失败。返回值（-1）。Critical Code 05\033[0m\n");
		printf("\033[0m\n\033[1m[\033[0m\033[1;31m-\033[0m\033[1m]\033[0m \033[1;31m紧急中止！\033[0m\n");
		return 0x091966;
	}
	Sleep(1000);
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
	if(system("Icacls \"C:\\Users\\kali\\Shell\\home\" /grant  kali:R 2>$null 1>&2")==-1)
	{
		i=1;
		printf("\033[0m\n[\033[33m!\033[0m] \033[33m /home目录 权限修改失败。返回值（-1）。Warning Code 01\033[0m\n");
	}
	if(system("Icacls \"C:\\Users\\kali\\Shell\\home\\kali\" /grant  kali:F 2>$null 1>&2")==-1)
	{
		i=1;
		printf("\033[0m\n[\033[33m!\033[0m] \033[33m /home/kali目录 权限修改失败。返回值（-1）。Warning Code 02\033[0m\n");
	}
	if(system("Icacls \"C:\\Users\\kali\\Shell\\etc\" /grant  kali:N 2>$null 1>&2")==-1)
	{
		i=1;
		printf("\033[0m\n[\033[33m!\033[0m] \033[33m /etc目录 权限修改失败。返回值（-1）。Warning Code 03\033[0m\n");
	}
	if(system("Icacls \"C:\\Users\\kali\\Shell\\bin\" /grant  kali:N 2>$null 1>&2")==-1)
	{
		i=1;
		printf("\033[0m\n[\033[33m!\033[0m] \033[33m /bin目录 权限修改失败。返回值（-1）。Warning Code 04\033[0m\n");
	}
	Sleep(1000);
	FILE*fp5;
	fp5=fopen ("C:\\Users\\kali\\Shell\\Lookhere", "w+");
	fprintf(fp5,"\"Great! Let's Rock!\"");
	fclose(fp5);
	if(system("Icacls \"C:\\Users\\kali\\Shell\\Lookhere\" /grant  kali:R 2>$null 1>&2")==-1)
	{
		i=1;
		printf("\033[0m\n[\033[33m!\033[0m] \033[33m /Lookhere 权限修改失败。返回值（-1）。Warning Code 05\033[0m\n");
	}
	if(system("Icacls \"C:\\Users\\kali\\Shell\" /grant  kali:R 2>$null 1>&2")==-1)
	{
		i=1;
		printf("\033[0m\n[\033[33m!\033[0m] \033[33m 根目录 权限修改失败。返回值（-1）。Warning Code 06\033[0m\n");
	}
	if(i==0)
	{
		printf("完成。\033[0m\n");
	}
	else
	{
		printf("[\033[32m+\033[0m] \033[34m完成。\033[0m\n");
	}
	Sleep(3000);
	
	printf("\n");
	printf("\033[1m[\033[1;32m+\033[0m\033[1m]\033[0m \033[1;34m完成。\033[0m\n\n");
	
	printf("\033[1m[\033[1;32m+\033[0m\033[1m]\033[0m \033[1m    如果没有任何警告或错误，那么现在Windows SSH 蜜罐应该已经在您的计算机下部署完成了。\n");
	printf("        如在使用过程中遇到任何问题或错误请联系作者。\n感谢使用，键入ENTER退出程序。\n==================================\n\033[0m");
	getch();getch();
	
	return 0;
	
} 

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
	printf("\n\033[1;34m/*SSH �۹�ȫ�沿�����*/\n");
	printf(" ���ߣ�Jessarin000\n");
	printf(" ���ڣ�2023-10-25\n");
	printf(" �汾��1.0\033[0m\n\n");
	printf("    ����ĿΪ Linux SSH �۹޵ķ�֧�������� Windows �������Զ������� SSH �������۹���Ŀ��\n");
	printf("����Ŀԭ��Ϊ�޸�ԭSSH Ĭ�������ն� CMD Ϊָ��α�ն�Bacsh��Winbash�����Ӷ�ģ��Linux\n");
	printf("�µ� Chroot �������Ӷ����ƹ����ߵ�·����Ǩ�Լ�����ִ�С�\n\n");
	printf("    ����Ŀ��\n");
	printf("        Ĭ�ϴ����˻�Ϊ kali������Ϊ kjx00000��\n");
	printf("        Ĭ�ϴ���Ŀ¼Ϊ C:\\Users\\kali\\Shell\n");
	printf("        Ĭ���޷������ļ���\n");
	printf("        Ĭ���۹��ն�Ϊ Bacsh��\n");
	printf("        ��\033[1;31mע�⣺����Ŀ������ִ���������ն� Bacsh ����ֱ����ϵ��������ȷ�����Ѿ����˸��õ�ѡ�񣬷���ǿ�Ҳ������޸� SSHD �ն����ã�\033[0m��\n");
	printf("        Ĭ������£����������۹��п�ʹ�õ�����Ϊ��cd��ls��cat��cls�Լ����ǵı�����\n\n");
	printf("    \033[32m*����Ŀ����δ���汾���𲽷�����������Ĳ������Ӷ����û������� Bacsh ������������躯����\033[0m\n\n");
	printf("    \033[35m*���κ������������ϵ���ߣ�< \033[4mkjx52@outlook.com\033[0m\033[35m >\033[0m\n\n");
	printf("\033[33m@ע�⣺�� ����Ĭ�ϻ����Ϊ936������-���壩���ն˻�������������Ŀ�ն�Bacsh��������������������⣬�������԰汾����ϵ���ߡ�\n");
	printf("@      �� ����Ŀ���޸��û���������� SSH �������û����Լ�ע���� SSH Ĭ���նˣ��������Թ���Ա������д˳���\n"); 
	printf("@      �� �����κ�������������ϵ���ߡ�\033[0m\n\n");
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
		printf("##                    %% ���� %%                    ##\n");
		printf("##       %% ��⵽ִ���û������й���ԱȨ�� %%       ##\n");
		printf("##                                                ##\n");
		printf("##                Critical Code 01                ##\n");
		printf("####################################################\n");
		printf("\033[0m");
		printf("\033[1m[\033[1;31m-\033[0m\033[1m]\033[0m \033[1;31m��ֹ�۹޲��������Y/n����\033[0m");
		scanf("%c",&key);
		switch(key)
		{
			case 'Y'|'y' :
				printf("��ֹ��\n");
				Sleep(2000);
				return 0x369860;
				
			case 'N'|'n' :
				printf("[.] �ܺúܺã�����ɼΡ�(@__@)\n");
				break;
			
			default:
				printf("��ֹ��\n");
				Sleep(2000);
				return 0x369860;
		}
	}
	else
	{
		printf("[\033[32m+\033[0m] \033[34mȨ��У����ɡ�\033[0m\n");
	}
	memset(xbuffer,0,sizeof(xbuffer));
	Sleep(3000);
	
	printf("[\033[32m+\033[0m] \033[34m���֧�ֻ�����1��...");
	if( OS==12864 || OS==12832 )
	{
		if(OS==12864)
		{
			printf("��ɡ�(��⵽��OS��Windows_x64)\033[0m\n");
		}
		if(OS==12832)
		{
			printf("��ɡ�(��⵽��OS��Windows_x86)\033[0m\n");
		}
	}
	else
	{
		if(OS==64)
		{
			printf("\033[0m\n[\033[31m-\033[0m] \033[31m��Ǹ������������� Windows ���������С�(��⵽��OS��GNU/Linux )\033[0m\n");
			printf("[\033[32m+\033[0m] \033[34m��Ҫ����ͬ���� Linux �����µ� SSH �۹���Ŀ������� < \033[4mhttps://github.com/kjx52/ssh-honeypot-new\033[0m\033[34m >\033[0m\n");
			Sleep(2000);
			return 0x771904;
		}
		if(OS==254)
		{
			printf("\033[0m\n[\033[31m-\033[0m] \033[31m��Ǹ������������� Windows ���������С�(��⵽��OS��Other UNIX OS )\033[0m\n");
			Sleep(2000);
			return 0x965633;
		}
		if(OS==999)
		{
			printf("\033[0m\n[\033[31m-\033[0m] \033[31m��Ǹ������������� Windows ���������С�(��⵽��OS��Unidentified OS )\033[0m\n");
			Sleep(2000);
			return 0x779326;
		}
	}
	Sleep(3000);
	
	printf("[\033[32m+\033[0m] \033[34m���֧�ֻ�����2��...");
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
		printf("��ɡ���⵽�� OpenSSH �汾��%s\033[0m",xbuffer);
	}
	else
	{
		printf("\033[0m\n\033[1m[\033[31m-\033[0m\033[1m]\033[0m \033[31mδ��⵽֧�ֻ���������ֹͣ��Critical Code 02\n\033[0m");
		Sleep(2000);
		return 0x336952;
	}
	memset(ybuffer,0,sizeof(ybuffer));
	memset(xbuffer,0,sizeof(xbuffer));
	Sleep(3000);
	
	printf("[\033[32m+\033[0m] \033[34m������Windows����������������û�...");
	if(system("net user /add kali kjx00000 1>$null 2>&1")!=-1)
	{
		printf("��ɡ�\033[0m\n");
	}
	else
	{
		printf("\033[0m\n[\033[31m-\033[0m] \033[31m���ʧ�ܡ�����ֵ��-1����Error Code 01\033[0m");
	}
	Sleep(3000);
	
	printf("[\033[32m+\033[0m] \033[34m�����޸� ssh_config �Ը�д��־·��...");
	FILE *fp1;
	fp1 = fopen("C:\\ProgramData\\ssh\\sshd_config", "r+");
	if(fp1 == NULL)
	{
		printf("\033[0m\n[\033[31m-\033[0m] \033[31m�������ܾ���Error Code 02\033[0m\n");
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
				printf("\033[0m\n[\033[32m+\033[0m] \033[34m��⵽��־·�����޸ġ������������б����������ɲ���Ҫ�Ļ����ļ��ѻ���\033[0m\n");
				i=1;
				break;
			}
		}
		if(i==0)
		{
			fputs(new_line, fp1);
			printf("��ɡ�\033[0m\n");
		}
	}
	fclose(fp1);
	Sleep(3000);
	
	printf("[\033[32m+\033[0m] \033[34m�����޸� SSHD Ĭ���ն�...");
	if((access("C:\\Users\\Public\\SSHShell\\Winbacsh.exe",F_OK))!=-1)
	{
		if(system("powershell -c \"New-ItemProperty -Path \'HKLM:\\SOFTWARE\\OpenSSH\' -Name DefaultShell -Value \'C:\\Users\\Public\\SSHShell\\Winbacsh.exe\' -PropertyType String -Force 1>$null 2>&1\"")!=-1)
		{
			printf("��ɡ�\033[0m\n");
		}
		else
		{
			printf("\033[0m\n\033[1m[\033[0m\033[1;31m-\033[0m\033[1m]\033[0m \033[1;31mע���д��ʧ�ܡ�����ֵ��-1����Critical Code 04\033[0m\n");
			printf("\033[0m\n\033[1m[\033[0m\033[1;31m-\033[0m\033[1m]\033[0m \033[1;31m������ֹ��\033[0m\n");
		}
	}
	else
	{
		printf("\033[0m\n\033[1m[\033[0m\033[1;31m-\033[0m\033[1m]\033[0m \033[1;31m�޷���λ�ն� Bacsh ����ȷ������ȷ��װ������Critical Code 03\033[0m\n");
		printf("\033[0m\n\033[1m[\033[0m\033[1;31m-\033[0m\033[1m]\033[0m \033[1;31m������ֹ��\033[0m\n");
		Sleep(2000);
		return 0x695588;
	}
	Sleep(3000);
	
	printf("[\033[32m+\033[0m] \033[34m���Դ��������ļ�...");
	if((access("C:\\Users\\kali\\tmp1.txt",F_OK))!=-1)
	{
		printf("\033[0m\n[\033[32m+\033[0m] \033[34m��⵽�����ļ��Ѵ��ڡ��������衣\033[0m\n");
	}
	else
	{
		FILE*fp2;
		fp2=fopen ("C:\\Users\\kali\\tmp1.txt", "w+");
		fprintf(fp2,"0");
		fclose(fp2);
		printf("��ɡ�\033[0m\n");
	}
	Sleep(3000);
	
	i=0;
	printf("[\033[32m+\033[0m] \033[34m�����޸��ļ�Ȩ��...");
	if(system("Icacls \"C:\\Users\\Public\\SSHShell\\Winbacsh.exe\" /grant  kali:RX 2>$null 1>&2")==-1)
	{
		i=1;
		printf("\033[0m\n\033[1m[\033[0m\033[1;31m-\033[0m\033[1m]\033[0m \033[1;31m Bacsh Ȩ���޸�ʧ�ܡ�����ֵ��-1����Critical Code 05\033[0m\n");
		printf("\033[0m\n\033[1m[\033[0m\033[1;31m-\033[0m\033[1m]\033[0m \033[1;31m������ֹ��\033[0m\n");
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
		printf("\033[0m\n[\033[33m!\033[0m] \033[33m /homeĿ¼ Ȩ���޸�ʧ�ܡ�����ֵ��-1����Warning Code 01\033[0m\n");
	}
	if(system("Icacls \"C:\\Users\\kali\\Shell\\home\\kali\" /grant  kali:F 2>$null 1>&2")==-1)
	{
		i=1;
		printf("\033[0m\n[\033[33m!\033[0m] \033[33m /home/kaliĿ¼ Ȩ���޸�ʧ�ܡ�����ֵ��-1����Warning Code 02\033[0m\n");
	}
	if(system("Icacls \"C:\\Users\\kali\\Shell\\etc\" /grant  kali:N 2>$null 1>&2")==-1)
	{
		i=1;
		printf("\033[0m\n[\033[33m!\033[0m] \033[33m /etcĿ¼ Ȩ���޸�ʧ�ܡ�����ֵ��-1����Warning Code 03\033[0m\n");
	}
	if(system("Icacls \"C:\\Users\\kali\\Shell\\bin\" /grant  kali:N 2>$null 1>&2")==-1)
	{
		i=1;
		printf("\033[0m\n[\033[33m!\033[0m] \033[33m /binĿ¼ Ȩ���޸�ʧ�ܡ�����ֵ��-1����Warning Code 04\033[0m\n");
	}
	Sleep(1000);
	FILE*fp5;
	fp5=fopen ("C:\\Users\\kali\\Shell\\Lookhere", "w+");
	fprintf(fp5,"\"Great! Let's Rock!\"");
	fclose(fp5);
	if(system("Icacls \"C:\\Users\\kali\\Shell\\Lookhere\" /grant  kali:R 2>$null 1>&2")==-1)
	{
		i=1;
		printf("\033[0m\n[\033[33m!\033[0m] \033[33m /Lookhere Ȩ���޸�ʧ�ܡ�����ֵ��-1����Warning Code 05\033[0m\n");
	}
	if(system("Icacls \"C:\\Users\\kali\\Shell\" /grant  kali:R 2>$null 1>&2")==-1)
	{
		i=1;
		printf("\033[0m\n[\033[33m!\033[0m] \033[33m ��Ŀ¼ Ȩ���޸�ʧ�ܡ�����ֵ��-1����Warning Code 06\033[0m\n");
	}
	if(i==0)
	{
		printf("��ɡ�\033[0m\n");
	}
	else
	{
		printf("[\033[32m+\033[0m] \033[34m��ɡ�\033[0m\n");
	}
	Sleep(3000);
	
	printf("\n");
	printf("\033[1m[\033[1;32m+\033[0m\033[1m]\033[0m \033[1;34m��ɡ�\033[0m\n\n");
	
	printf("\033[1m[\033[1;32m+\033[0m\033[1m]\033[0m \033[1m    ���û���κξ���������ô����Windows SSH �۹�Ӧ���Ѿ������ļ�����²�������ˡ�\n");
	printf("        ����ʹ�ù����������κ�������������ϵ���ߡ�\n��лʹ�ã�����ENTER�˳�����\n==================================\n\033[0m");
	getch();getch();
	
	return 0;
	
} 

#include <conio.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>
#include <windows.h>

/*
 Bacsh 6.3
 作者： Jessarin000
 日期： 2024-01-07 
*/

/*
 默认可使用命令为：“cat”、“cd”、“cls”、“ls” 和 “pwd” 以及它们的别名。 
*/

time_t Cur_Time;
struct tm*Now;
char Time_Handel[80];

//=====================================================

//以下为默认存储路径。
char Env_Path[]="C:\\Users\\kali\\tmp1.txt";
char Cmd_Log_Path[]="C:\\Users\\Public\\History\\Command.txt";
char Res_Log_Path[]="C:\\Users\\Public\\History\\Result.txt";

//=====================================================

int Equal_Case_String(const char *Command,const char *Key_String)
{
	int Counter_02=0;
	
	for(Counter_02=0;Counter_02<strlen(Key_String);Counter_02++)
	{
		if(Command[Counter_02]!=Key_String[Counter_02] && Command[Counter_02]!=Key_String[Counter_02]-32)
		{
			return 0;
		}
	}
	return 1;
}

int Chroot(char *Path_Flag_02,char *Path_Flag_03,char *Command,char *Function_String,int Path_Flag_01,char *Isolate_Path_02)
{
	int Counter_07,Counter_03,Tmp_Flag_01,Tmp_Flag_02;
	char Tmp_Flag_08[20];
	char Isolate_Path[53]="C:\\Users\\kali\\Shell\\";
	char Root_Path[]="C:\\";
	
	memset(Tmp_Flag_08,0,sizeof(Tmp_Flag_08));
	
	Counter_07=0;
	Counter_03=0;
	Tmp_Flag_01=1;
	Tmp_Flag_02=0;
	
	strcpy(Path_Flag_02,"");
	
	Node_03:
	for(Counter_03=0;Tmp_Flag_01==1 && Counter_03+strlen(Function_String)+Counter_07<strlen(Command);Counter_03++)
	{
		if(Command[Counter_03+strlen(Function_String)+Counter_07]==' ' || Command[Counter_03+strlen(Function_String)+Counter_07]=='\r' || Command[Counter_03+strlen(Function_String)+Counter_07]==':')
		{
			if(Command[Counter_03+strlen(Function_String)+Counter_07]==' ' && Counter_03==0)
			{
				Counter_07++;
				goto Node_03;
			}
			if(Command[Counter_03+strlen(Function_String)+Counter_07]==':' && Counter_03==1)
			{
				Path_Flag_02[Counter_03]=Command[Counter_03+strlen(Function_String)+Counter_07];
				continue;
			}
			Tmp_Flag_01=0;
		}
		else
		{
			Path_Flag_02[Counter_03]=Command[Counter_03+strlen(Function_String)+Counter_07];
		}
	}
	if(strlen(Path_Flag_02)==1)
	{
		if(Path_Flag_02[0]=='/')
		{
			chdir("C:\\Users\\kali\\Shell\\");
			Tmp_Flag_01=2;
			printf("[\033[32m+\033[0m] \033[32m当前工作目录： C:\\\033[0m\n");
			strcpy(Path_Flag_03,Root_Path);
			Path_Flag_01=1;
		}
		
		if(Path_Flag_02[0]=='~')
		{
			chdir("C:\\Users\\kali\\Shell\\home\\kali");
			Tmp_Flag_01=2;
			
			printf("[\033[32m+\033[0m] \033[32m当前工作目录： C:\\home\\kali\033[0m\n");
			strcpy(Path_Flag_03,Root_Path);
			Path_Flag_01=1;
		}
	}
	if(Tmp_Flag_01!=2)
	{
		if(Path_Flag_02[1]!=':')
		{
			printf("[\033[33m!\033[0m] \033[33m请输入绝对路径。 WarningCode:05\n\033[0m");
		}
		else
		{
			if(Path_Flag_02[0]!='c' && Path_Flag_02[0]!='C')
			{
				printf("[\033[33m!\033[0m] \033[33m仅可以输入C盘绝对路径。 WarningCode:14\n\033[0m"); 
			}
			else
			{
				if(strlen(Path_Flag_02)==2)
				{
					chdir("C:\\Users\\kali\\Shell\\");
					Tmp_Flag_01=2;
					
					printf("[\033[32m+\033[0m] \033[32m当前工作目录： C:\\\033[0m\n");
					char Root_Path[]="C:\\";
					strcpy(Path_Flag_03,Root_Path);
					Path_Flag_01=1;
				}
				else
				{
					memset(Tmp_Flag_08,0,sizeof(Tmp_Flag_08));
					for(Tmp_Flag_02=2;Tmp_Flag_02<strlen(Path_Flag_02);Tmp_Flag_02++)
					{
						Tmp_Flag_08[Tmp_Flag_02-2]=Path_Flag_02[Tmp_Flag_02];
					}
					strcat(Isolate_Path,Tmp_Flag_08);
					
					if((access(Isolate_Path,F_OK))!=-1)
					{
						if((access(Isolate_Path,R_OK))!=-1)
						{
							printf("[\033[32m+\033[0m] \033[32m当前工作目录：%s\033[0m\n",Path_Flag_02);
							chdir(Isolate_Path);
							memset(Isolate_Path_02,0,sizeof(Isolate_Path_02));
							strcpy(Isolate_Path_02,Isolate_Path);
							memset(Path_Flag_03,0,sizeof(Path_Flag_03));
							strcpy(Path_Flag_03,Path_Flag_02);
							Path_Flag_01=2;
						}
						else
						{
							printf("[\033[31m-\033[0m] 拒绝访问。\n");
							if(Path_Flag_03==NULL)
							{
								printf("[\033[32m+\033[0m] \033[32m当前工作目录：%s\033[0m\n",getcwd(NULL,NULL));
							}
							else
							{
								printf("[\033[32m+\033[0m] \033[32m当前工作目录：%s\033[0m\n",Path_Flag_03);
							}
						}
					}
					else
					{
						printf("[\033[31m-\033[0m] 系统找不到指定路径。\n");
						if(Path_Flag_03==NULL)
						{
							printf("[\033[32m+\033[0m] \033[32m当前工作目录：%s\033[0m\n",getcwd(NULL,NULL));
						}
						else
						{
							printf("[\033[32m+\033[0m] \033[32m当前工作目录：%s\033[0m\n",Path_Flag_03);
						}
					}
				}
			}
		}
	}
	time(&Cur_Time);
	Now=gmtime(&Cur_Time);
	snprintf(Time_Handel,20,"%d-%d-%d %d:%d:%d",1900+Now->tm_year,1+Now->tm_mon,Now->tm_mday,8+Now->tm_hour,Now->tm_min,Now->tm_sec);
	
	FILE*Command2;
	Command2=fopen(Cmd_Log_Path,"a");
	fprintf(Command2,"[%s]\t# %s : %s \n",Time_Handel,getcwd(NULL,NULL),Command);
	fclose(Command2);
	
	FILE*Result2;
	Result2=fopen(Res_Log_Path,"a");
	fprintf(Result2,"[%s]\t# %s : \n",Time_Handel,getcwd(NULL,NULL));
	fclose(Result2);
	return Path_Flag_01;
}

int Reset(int Char_Key_Flag_04,int Counter_04)
{
	if(Char_Key_Flag_04!=Counter_04)
	{
		for(;Char_Key_Flag_04<Counter_04;Char_Key_Flag_04++)
		{
			printf(" ");
		}
		for(;Counter_04>0;Counter_04--)
		{
			printf("\b \b");
		}
		Char_Key_Flag_04=0;
	}
	else
	{
		for(;Counter_04>0;Counter_04--)
		{
			printf("\b \b");
		}
		Char_Key_Flag_04=0;
	}
	
	return 0;
}

int Cat_Detect(char *Function_String,char *Command,char *Path_Flag_02)
{
	int Counter_08,Counter_09,Tmp_Flag_05,Tmp_Flag_06;
	char Arrays[20];
	char Buffer_Z[1024];
	char Isolate_Path[60]="C:\\Users\\kali\\Shell";
	char Cat_Command[100]="powershell -c \"cat ";
	bool Open = true;
	Counter_09=0;
	Tmp_Flag_05=1; 
	
    memset(Arrays,0,sizeof(Arrays));
	Node_03:
	for(Counter_08=0;Tmp_Flag_05==1 && Counter_08+strlen(Function_String)+Counter_09<strlen(Command);Counter_08++)
	{
		if(Command[Counter_08+strlen(Function_String)+Counter_09]==' ' || Command[Counter_08+strlen(Function_String)+Counter_09]=='\r' || Command[Counter_08+strlen(Function_String)+Counter_09]==':')
		{
			if(Command[Counter_08+strlen(Function_String)+Counter_09]==' ' && Counter_08==0)
			{
				Counter_09++;
				goto Node_03;
			}
			if(Command[Counter_08+strlen(Function_String)+Counter_09]==':' && Counter_08==1)
			{
				Path_Flag_02[Counter_08]=Command[Counter_08+strlen(Function_String)+Counter_09];
				Open=false;
				continue;
			}
			Tmp_Flag_05=0;
		}
		else
		{
			Path_Flag_02[Counter_08]=Command[Counter_08+strlen(Function_String)+Counter_09];
		}
	}
	if(Open)
	{
		printf("[\033[33m!\033[0m] \033[33m请输入绝对路径。 WarningCode:06\n\033[0m"); 
		return 001;
	}
	if(Path_Flag_02[1]!=':')
	{
		printf("[\033[33m!\033[0m] \033[33m请输入绝对路径。 WarningCode:07\n\033[0m"); 
		return 001;
	}
	
	for(Tmp_Flag_06=2;Tmp_Flag_06<strlen(Path_Flag_02);Tmp_Flag_06++)
	{
		Arrays[Tmp_Flag_06-2]=Path_Flag_02[Tmp_Flag_06];
	}
	
	strcat(Isolate_Path,Arrays);
	if((access(Isolate_Path,F_OK))!=-1)
	{
		if((access(Isolate_Path,R_OK))!=-1)
		{
			strcat(Cat_Command,Isolate_Path);
			strcat(Cat_Command,"\"");
			system(Cat_Command);
		}
		else
		{
			printf("[\033[31m-\033[0m] 拒绝访问。\n");
		}
	}
	else
	{
		printf("[\033[31m-\033[0m] 系统找不到指定的文件。\n");
	}
	
	time(&Cur_Time);
    Now=gmtime(&Cur_Time);
    snprintf(Time_Handel,20,"%d-%d-%d %d:%d:%d",1900+Now->tm_year,1+Now->tm_mon,Now->tm_mday,8+Now->tm_hour,Now->tm_min,Now->tm_sec);
	
	FILE*Command_Log;
	Command_Log=fopen(Cmd_Log_Path,"a");
	fprintf(Command_Log,"[%s]\t# %s :(cat) %s \n",Time_Handel,getcwd(NULL,NULL),Command);
	fclose(Command_Log);
	
	FILE*Result_Cmd;
	Result_Cmd=popen(Cat_Command,"r");
	fgets(Buffer_Z,sizeof(Buffer_Z),Result_Cmd);
	fclose(Result_Cmd);
	
	FILE*Result_Log;
	Result_Log=fopen(Res_Log_Path,"a");
	fprintf(Result_Log,"[%s]\t# %s :(cat)  %s \n",Time_Handel,getcwd(NULL,NULL),Buffer_Z);
	fclose(Result_Log);

	memset(Path_Flag_02,0,sizeof(Path_Flag_02));
	return 000;
}

int Target(char *str1, char *str2)
{
	int Tmp_Flag_04,Counter_05,Tmp_Flag_01;
	char Tmp_Flag_07[11];
	Tmp_Flag_04=0;
	Counter_05=1;
	Tmp_Flag_01=0;
	
	memset(Tmp_Flag_07,0,sizeof(Tmp_Flag_07));
	while(1)
	{
		if(Tmp_Flag_01==strlen(str1))
		{
			return 0;
		}
		if(str1[Tmp_Flag_04+Tmp_Flag_01]==str2[Tmp_Flag_04] || str1[Tmp_Flag_04+Tmp_Flag_01]==str2[Tmp_Flag_04]-32)
		{
			if(47<str1[Tmp_Flag_04+Tmp_Flag_01-1] && str1[Tmp_Flag_04+Tmp_Flag_01-1]<58)
			{
				Tmp_Flag_01++;
				continue;
			}
			if(64<str1[Tmp_Flag_04+Tmp_Flag_01-1] && str1[Tmp_Flag_04+Tmp_Flag_01-1]<91)
			{
				Tmp_Flag_01++;
				continue;
			}
			if(96<str1[Tmp_Flag_04+Tmp_Flag_01-1] && str1[Tmp_Flag_04+Tmp_Flag_01-1]<123)
			{
				Tmp_Flag_01++;
				continue;
			}
			if(str1[Tmp_Flag_04+Tmp_Flag_01-1]==47 || str1[Tmp_Flag_04+Tmp_Flag_01-1]==45 || str1[Tmp_Flag_04+Tmp_Flag_01-1]==58)
			{
				Tmp_Flag_01++;
				continue;
			}
			strncpy(Tmp_Flag_07,str1+Tmp_Flag_04+Tmp_Flag_01,strlen(str2));
			for(;Tmp_Flag_04<strlen(str2) && Counter_05==1;Tmp_Flag_04++)
			{
				if(Tmp_Flag_07[Tmp_Flag_04]!=str2[Tmp_Flag_04] && Tmp_Flag_07[Tmp_Flag_04]!=str2[Tmp_Flag_04]-32)
				{
					Counter_05=0;
				}
			}
			if(Counter_05==0)
			{
				Tmp_Flag_04=0;
				Tmp_Flag_01++;
				Counter_05=1;
			}
			else
			{
				if(47<str1[Tmp_Flag_04+Tmp_Flag_01] && str1[Tmp_Flag_04+Tmp_Flag_01]<58)
				{
					Tmp_Flag_04=0;
					Tmp_Flag_01++;
					continue;
				}
				if(64<str1[Tmp_Flag_04+Tmp_Flag_01] && str1[Tmp_Flag_04+Tmp_Flag_01]<91)
				{
					Tmp_Flag_04=0;
					Tmp_Flag_01++;
					continue;
				}
				if(96<str1[Tmp_Flag_04+Tmp_Flag_01] && str1[Tmp_Flag_04+Tmp_Flag_01]<123)
				{
					Tmp_Flag_04=0;
					Tmp_Flag_01++;
					continue;
				}
				if(str1[Tmp_Flag_04+Tmp_Flag_01]==47 || str1[Tmp_Flag_04+Tmp_Flag_01]==45 || str1[Tmp_Flag_04+Tmp_Flag_01]==58)
				{
					Tmp_Flag_04=0; 
					Tmp_Flag_01++;
					continue;
				}
				return 1;
			}
		}
		else
		{
			Tmp_Flag_01++;
		}
	}
}





int main(int argc, char *argv[])
{
	FILE*Env_Tmp_Pipe_01;
	Env_Tmp_Pipe_01=fopen(Env_Path,"w+");
	fprintf(Env_Tmp_Pipe_01,"1");
	fclose(Env_Tmp_Pipe_01);
	
	char *FnM=argv[0];
	char *Env_User;
	int Counter_01,Counter_02,Counter_03;
	int Char_Key_Flag_01,Char_Key_Flag_02,Char_Key_Flag_03;
	int Path_Flag_01,Tmp_Flag_03;
	int BufSize_X=MAX_COMPUTERNAME_LENGTH + 1;
	int Time_Monitor_01,Time_Monitor_02;
	char Ac_Character;
	char Key_Word_01;
	char Ac_Command[21];
	char Buffer_X[1024];
	char Buffer_Y[1024];
	char Computer_Name[BufSize_X];
	char Creat_File_Path[15][50];
	char Env_Admin[]=" |findstr Administrators";
	char Exit_Command_02[53];
	char Home_Path[53]="C:\\Users\\kali\\Shell\\home\\kali";
	char Isolate_Path[53]="C:\\Users\\kali\\Shell\\";
	char OS_Shell_Flag_01[11]="powershell";
	char OS_Shell_Flag_02[4]="cmd";
	char OS_Shell_Flag_03[4]="exe";
	char Path_Flag_02[100];
	char Path_Flag_03[100]="C:/home/kali";
	
	bool NeedNextKey = false;
	
	memset(Ac_Command,0,sizeof(Ac_Command));
	memset(Buffer_X,0,sizeof(Buffer_X));
	memset(Buffer_Y,0,sizeof(Buffer_Y));
	memset(Creat_File_Path,0,sizeof(Creat_File_Path));
	memset(Computer_Name,0,sizeof(Computer_Name));
	memset(Exit_Command_02,0,sizeof(Exit_Command_02));
	memset(Path_Flag_02,0,sizeof(Path_Flag_02));
	
	Counter_01=0;
	Counter_02=0;
	Counter_03=0;
	Char_Key_Flag_01=0;
	Char_Key_Flag_02=0;
	Char_Key_Flag_03=0;
	Path_Flag_01=0;
	Tmp_Flag_03=0;
	Time_Monitor_01=0;
	Time_Monitor_02=0;
	
	Ac_Character=0;
	Key_Word_01=0;
	Path_Flag_01=3;
	
	Sleep(100);
	chdir("C:\\Users\\kali\\Shell\\home\\kali");
	system("cls");
	printf("Windows Bacsh\n版权所有 (C) GNU/Linux Bourne Again Compile Shell。保留所有权利。\n\n尝试新的跨平台 Bacsh https://www.gnu.org/\n\n");
	
//=========================================== 交互及动态字符过滤模块
	Node_01:
	memset(Path_Flag_02,0,sizeof(Path_Flag_02));
	memset(Ac_Command,0,sizeof(Ac_Command));
	DWORD BufSize_Y = BufSize_X;
	GetComputerName(Computer_Name, &BufSize_Y);
	Env_User=getenv("USERNAME");
	char User_Info[40]="net user ";
	strcat(User_Info,Env_User);
	strcat(User_Info,Env_Admin);
	FILE*Env_Tmp_Pipe_02;
	Env_Tmp_Pipe_02 = popen(User_Info,"r");
	fgets(Buffer_X,sizeof(Buffer_X),Env_Tmp_Pipe_02);
	pclose(Env_Tmp_Pipe_02);
	char Home_Path_02[36]="C:/home/kali";
	char Home_Path_03[36]="c:/home/kali";
	if(strlen(Buffer_X)<14)
	{
		if(Path_Flag_01==1)
		{
			printf("\n\033[32m┌──(\033[0m\033[34m %s@%s \033[0m\033[32m)-[\033[0m C:\\ \033[32m]\033[0m\n",Env_User,Computer_Name);
			printf("\033[32m└─\033[0m\033[34m$\033[0m ") ;
		}
		else
		{
			if(Path_Flag_01==2)
			{
				if(memcmp(Path_Flag_03,Home_Path_02,sizeof(Home_Path_02))==0 || memcmp(Path_Flag_03,Home_Path_03,sizeof(Home_Path_03))==0)
				{
					printf("\n\033[32m┌──(\033[0m\033[34m %s@%s \033[0m\033[32m)-[\033[0m ~ \033[32m]\033[0m\n",Env_User,Computer_Name);
					printf("\033[32m└─\033[0m\033[34m$\033[0m ");
				}
				else
				{
					printf("\n\033[32m┌──(\033[0m\033[34m %s@%s \033[0m\033[32m)-[\033[0m %s \033[32m]\033[0m\n",Env_User,Computer_Name,Path_Flag_03);
					printf("\033[32m└─\033[0m\033[34m$\033[0m ");
				}
			}
			else
			{
				printf("\n\033[32m┌──(\033[0m\033[34m %s@%s \033[0m\033[32m)-[\033[0m ~ \033[32m]\033[0m\n",Env_User,Computer_Name);
				printf("\033[32m└─\033[0m\033[34m$\033[0m ");
			}
		}
	}
	else
	{
		if(Path_Flag_01==1)
		{
			printf("\n\033[34m┌──(\033[0m\033[31m %s@%s \033[0m\033[34m)-[\033[0m C:\\ \033[34m]\033[0m\n",Env_User,Computer_Name);
			printf("\033[34m└─\033[0m\033[31m#\033[0m ") ;
		}
		else
		{
			if(Path_Flag_01==2)
			{
				if(memcmp(Path_Flag_03,Home_Path_02,sizeof(Home_Path_02))==0 || memcmp(Path_Flag_03,Home_Path_03,sizeof(Home_Path_03))==0)
				{
					printf("\n\033[34m┌──(\033[0m\033[31m %s@%s \033[0m\033[34m)-[\033[0m ~ \033[34m]\033[0m\n",Env_User,Computer_Name);
					printf("\033[34m└─\033[0m\033[31m#\033[0m ");
				}
				else
				{
					printf("\n\033[34m┌──(\033[0m\033[31m %s@%s \033[0m\033[34m)-[\033[0m %s \033[34m]\033[0m\n",Env_User,Computer_Name,Path_Flag_03);
					printf("\033[34m└─\033[0m\033[31m#\033[0m ");
				}
			}
			else
			{
				printf("\n\033[34m┌──(\033[0m\033[31m %s@%s \033[0m\033[34m)-[\033[0m ~ \033[34m]\033[0m\n",Env_User,Computer_Name);
				printf("\033[34m└─\033[0m\033[31m#\033[0m ");
			}
		}
	}
	memset(Buffer_X,0,sizeof(Buffer_X));
	 
	Node_02:
	printf("\033[1;34m");
	Counter_01=0;
	Char_Key_Flag_01=0;
	Char_Key_Flag_02=0;
	Char_Key_Flag_03=0;
	memset(Ac_Command,0,sizeof(Ac_Command));
	while((Ac_Character=getch())!=111111)
	{
		if(Ac_Character==0)
		{
			printf("\n\n\n\033[;5;31m");
			printf("######################################\n");
			printf("#               %%警告%%               #\n");
			printf("#        %%Bacsh 核心进程受阻%%        #\n");
			printf("#           %%！紧急终止！%%           #\n");
			printf("#          Critical Code 03          #\n");
			printf("######################################\n");
			printf("\033[0m\n");
			FILE*Env_Tmp_Pipe_03;
			Env_Tmp_Pipe_03=fopen(Env_Path,"w+");
			fprintf(Env_Tmp_Pipe_03,"0");
			fclose(Env_Tmp_Pipe_03);
			Sleep(3000);
			return 0x001;
		}
		if(Ac_Character=='\r')
		{
			if(Counter_01==0)
			{
				printf("\033[0m\n");
				goto Node_01;
			}
			printf("\033[0m\n");
			break;
		}
		if(Ac_Character==' '&&Counter_01==0)
		{
			Reset(Char_Key_Flag_01,Counter_01);
			goto Node_02;
		}
		if(Ac_Character=='\t'&&Counter_01==0)
		{
			Reset(Char_Key_Flag_01,Counter_01);
			goto Node_01;
		}
		if(Ac_Character==' '&&Counter_01!=0)
		{
			if(Char_Key_Flag_03==0)
			{
				Char_Key_Flag_03=Char_Key_Flag_01;
			}
			printf("\033[0m");
		}
		if(Ac_Character=='\"')
		{
			Reset(Char_Key_Flag_01,Counter_01);
			goto Node_02;
		}
		if(Ac_Character=='\'')
		{
			Reset(Char_Key_Flag_01,Counter_01);
			goto Node_02;
		}
		if(Ac_Character=='\\')
		{
			Reset(Char_Key_Flag_01,Counter_01);
			goto Node_02;
		}
		if(Ac_Character=='[')
		{
			Reset(Char_Key_Flag_01,Counter_01);
			goto Node_02;
		}
		if(Ac_Character==']')
		{
			Reset(Char_Key_Flag_01,Counter_01);
			goto Node_02;
		}
		if(Ac_Character=='{')
		{
			Reset(Char_Key_Flag_01,Counter_01);
			goto Node_02;
		}
		if(Ac_Character=='}')
		{
			Reset(Char_Key_Flag_01,Counter_01);
			goto Node_02;
		}
		if(Ac_Character=='(')
		{
			Reset(Char_Key_Flag_01,Counter_01);
			goto Node_02;
		}
		if(Ac_Character==')')
		{
			Reset(Char_Key_Flag_01,Counter_01);
			goto Node_02;
		}
		if(Ac_Character=='<')
		{
			Reset(Char_Key_Flag_01,Counter_01);
			goto Node_02;
		}
		if(Ac_Character=='>')
		{
			Reset(Char_Key_Flag_01,Counter_01);
			goto Node_02;
		}
		if(Ac_Character=='!')
		{
			Reset(Char_Key_Flag_01,Counter_01);
			goto Node_02;
		}
		if(Ac_Character=='@')
		{
			Reset(Char_Key_Flag_01,Counter_01);
			goto Node_02;
		}
		if(Ac_Character=='#')
		{
			Reset(Char_Key_Flag_01,Counter_01);
			goto Node_02;
		}
		if(Ac_Character=='$')
		{
			Reset(Char_Key_Flag_01,Counter_01);
			goto Node_02;
		}
		if(Ac_Character=='%')
		{
			Reset(Char_Key_Flag_01,Counter_01);
			goto Node_02;
		}
		if(Ac_Character=='^')
		{
			Reset(Char_Key_Flag_01,Counter_01);
			goto Node_02;
		}
		if(Ac_Character=='&')
		{
			Reset(Char_Key_Flag_01,Counter_01);
			goto Node_02;
		}
		if(Ac_Character=='*')
		{
			Reset(Char_Key_Flag_01,Counter_01);
			goto Node_02;
		}
		if(Ac_Character=='=')
		{
			Reset(Char_Key_Flag_01,Counter_01);
			goto Node_02;
		}
		if(Ac_Character=='+')
		{
			Reset(Char_Key_Flag_01,Counter_01);
			goto Node_02;
		}
		if(Ac_Character=='`')
		{
			Reset(Char_Key_Flag_01,Counter_01);
			goto Node_02;
		}
		if(Ac_Character=='~')
		{
			Reset(Char_Key_Flag_01,Counter_01);
			goto Node_02;
		}
		if(Ac_Character=='.')
		{
			Reset(Char_Key_Flag_01,Counter_01);
			goto Node_02;
		}
		if(Ac_Character==',')
		{
			Reset(Char_Key_Flag_01,Counter_01);
			goto Node_02;
		}
		if(Ac_Character=='_')
		{
			Reset(Char_Key_Flag_01,Counter_01);
			goto Node_02;
		}
		if(Ac_Character==';')
		{
			Reset(Char_Key_Flag_01,Counter_01);
			goto Node_02;
		}
		if(Ac_Character=='&')
		{
			Reset(Char_Key_Flag_01,Counter_01);
			goto Node_02;
		}
		if(Ac_Character=='|')
		{
			Reset(Char_Key_Flag_01,Counter_01);
			goto Node_02;
		}
		if(Ac_Character=='?')
		{
			Reset(Char_Key_Flag_01,Counter_01);
			goto Node_02;
		}
		if(Ac_Character=='\b')
		{
			if(Char_Key_Flag_01>0)
			{
				if(Char_Key_Flag_01!=Counter_01)
				{
					if(Char_Key_Flag_03!=0)
					{
						Char_Key_Flag_02=Char_Key_Flag_01;
						if(Ac_Command[Char_Key_Flag_01-2]!=' ' && Ac_Command[Char_Key_Flag_01]!=' ')
						{
							if(Ac_Command[Char_Key_Flag_01-1]==' ')
							{
								Char_Key_Flag_03=20;
							}
						}
						for(;Char_Key_Flag_01<Counter_01;Char_Key_Flag_01++)
						{
							Ac_Command[Char_Key_Flag_01-1]=Ac_Command[Char_Key_Flag_01];
						}
						Ac_Command[Char_Key_Flag_01-1]='\0';
						printf("\b \b");
						Counter_01--;
						Char_Key_Flag_02--;
						Char_Key_Flag_01=Char_Key_Flag_02;
						for(;Char_Key_Flag_01<Counter_01;Char_Key_Flag_01++)
						{
							if(Char_Key_Flag_01<Char_Key_Flag_03+1)
							{
								if(Ac_Command[Char_Key_Flag_01]==' ')
								{
									printf(" ");
									Char_Key_Flag_03=Char_Key_Flag_01;
								}
								else
								{
									printf("\033[1;34m%c\033[0m",Ac_Command[Char_Key_Flag_01]);
								}
							}
							else
							{
								printf("%c",Ac_Command[Char_Key_Flag_01]);
							}
						}
						Char_Key_Flag_03--;
						printf(" ");
						for(;Char_Key_Flag_01>Char_Key_Flag_02-1;Char_Key_Flag_01--)
						{
							printf("\b");
						}
						Char_Key_Flag_02=0;
						Char_Key_Flag_01++;
						if(Char_Key_Flag_03==19)
						{
							Char_Key_Flag_03=0;
						}
						continue;
					}
					else
					{
						Char_Key_Flag_02=Char_Key_Flag_01;
						for(;Char_Key_Flag_01<Counter_01;Char_Key_Flag_01++)
						{
							Ac_Command[Char_Key_Flag_01-1]=Ac_Command[Char_Key_Flag_01];
						}
						Ac_Command[Char_Key_Flag_01-1]='\0';
						printf("\b \b");
						Counter_01--;
						Char_Key_Flag_02--;
						Char_Key_Flag_01=Char_Key_Flag_02;
						for(;Char_Key_Flag_01<Counter_01;Char_Key_Flag_01++)
						{
							printf("\033[1;34m%c\033[0m",Ac_Command[Char_Key_Flag_01]);
						}
						printf(" ");
						for(;Char_Key_Flag_01>Char_Key_Flag_02-1;Char_Key_Flag_01--)
						{
							printf("\b");
						}
						Char_Key_Flag_02=0;
						Char_Key_Flag_01++;
						continue;
					}
				}
				else
				{
					if(Ac_Command[Counter_01-1]==' ')
					{
						for(Tmp_Flag_03=0;Tmp_Flag_03<Counter_01-1;Tmp_Flag_03++)
						{
							if(Ac_Command[Tmp_Flag_03]==' ')
							{
								Tmp_Flag_03=163;
								break;
							}
						}
						if(Tmp_Flag_03!=163)
						{
							Char_Key_Flag_03=0;
						}
					}
					printf("\b \b");
					Counter_01--;
					Char_Key_Flag_01--;
					Ac_Command[Counter_01]='\0';
					continue;
				}
			}
			continue;
		}
		if(Ac_Character==3)
		{
			printf("\033[0m\n");
			goto Node_01;
		}
		if(!(isprint(Ac_Character)) && Ac_Character!='\t' && Ac_Character!=-32)
		{
			if(Char_Key_Flag_01!=Counter_01)
			{
				for(;Char_Key_Flag_01<Counter_01;Char_Key_Flag_01++)
				{
					printf(" ");
				}
				for(;Counter_01>0;Counter_01--)
				{
					printf("\b \b");
				}
				Char_Key_Flag_01=0;
			}
			else
			{
				for(;Counter_01>0;Counter_01--)
				{
					printf("\b \b");
				}
				Char_Key_Flag_01=0;
			}
			goto Node_02;
		}
		if(NeedNextKey)
		{
			if(Key_Word_01==-32)
			{
				if(Ac_Character==75)
				{
					if(Char_Key_Flag_01>0)
					{
						printf("\033[D");
						Char_Key_Flag_01--;
					}
				}
				else if(Ac_Character==77)
				{
					if(Char_Key_Flag_01<Counter_01)
					{
						printf("\033[C");
						Char_Key_Flag_01++;
					}
				}
			}
			else
			{
				printf("\033[0m");
				goto Node_01;
			}
			NeedNextKey=false;
		}
		else
		{
			if(Ac_Character>0)
			{
				if(Char_Key_Flag_01!=Counter_01)
				{
					if(Char_Key_Flag_03!=0)
					{
						Char_Key_Flag_02=Char_Key_Flag_01;
						Char_Key_Flag_01=Counter_01;
						for(;Char_Key_Flag_01>Char_Key_Flag_02;Char_Key_Flag_01--)
						{
							Ac_Command[Char_Key_Flag_01]=Ac_Command[Char_Key_Flag_01-1];
						}
						Ac_Command[Char_Key_Flag_01]=Ac_Character;
						if(Char_Key_Flag_01<Char_Key_Flag_03+1)
						{
							if(Ac_Command[Char_Key_Flag_01]==' ')
							{
								if(Char_Key_Flag_01==0)
								{
									Reset(Char_Key_Flag_01,Counter_01);
									goto Node_02;
								}
								printf(" ");
								Char_Key_Flag_03=Char_Key_Flag_01;
							}
							else
							{
								printf("\033[1;34m%c\033[0m",Ac_Command[Char_Key_Flag_01]);
								Char_Key_Flag_03++;
							}
						}
						else
						{
							printf("%c",Ac_Character);
						}
						Counter_01++;
						Char_Key_Flag_02++;
						Char_Key_Flag_01=Char_Key_Flag_02;
						for(;Char_Key_Flag_01<Char_Key_Flag_03+1;Char_Key_Flag_01++)
						{
							printf("\033[1;34m%c\033[0m",Ac_Command[Char_Key_Flag_01]);
						}
						for(;Char_Key_Flag_01<Counter_01;Char_Key_Flag_01++)
						{
							printf("%c",Ac_Command[Char_Key_Flag_01]);
						}
						for(;Char_Key_Flag_01>Char_Key_Flag_02;Char_Key_Flag_01--)
						{
							printf("\b");
						}
						Char_Key_Flag_02=0;
					}
					else
					{
						Char_Key_Flag_02=Char_Key_Flag_01;
						Char_Key_Flag_01=Counter_01;
						for(;Char_Key_Flag_01>Char_Key_Flag_02;Char_Key_Flag_01--)
						{
							Ac_Command[Char_Key_Flag_01]=Ac_Command[Char_Key_Flag_01-1];
						}
						Ac_Command[Char_Key_Flag_01]=Ac_Character;
						if(Ac_Command[Char_Key_Flag_01]==' ' && Char_Key_Flag_01==0)
						{
							Reset(Char_Key_Flag_01,Counter_01);
							goto Node_02;
						}
						printf("\033[1;34m%c\033[0m",Ac_Command[Char_Key_Flag_01]);
						Counter_01++;
						Char_Key_Flag_02++;
						Char_Key_Flag_01=Char_Key_Flag_02;
						for(;Char_Key_Flag_01<Counter_01;Char_Key_Flag_01++)
						{
							printf("\033[1;34m%c\033[0m",Ac_Command[Char_Key_Flag_01]);
						}
						for(;Char_Key_Flag_01>Char_Key_Flag_02;Char_Key_Flag_01--)
						{
							printf("\b");
						}
						Char_Key_Flag_02=0;
					}
				}
				else
				{
					Ac_Command[Counter_01]=Ac_Character;
					if(Char_Key_Flag_03==0)
					{
						printf("\033[1;34m%c\033[0m",Ac_Character);
					}
					else
					{
						printf("%c",Ac_Character);
					}
					Counter_01++;
					Char_Key_Flag_01++;
				}
			}
		}
		if(Ac_Character<0)
		{
			Key_Word_01=Ac_Character;
			NeedNextKey=true;
		}
		
		//退出函数 
		if(Ac_Character=='Z')
		{
			printf("\033[0m");
			FILE*Env_Tmp_Pipe_04;
			Env_Tmp_Pipe_04=fopen(Env_Path,"w+");
			fprintf(Env_Tmp_Pipe_04,"0");
			fclose(Env_Tmp_Pipe_04);
			printf("\n退出登录。\n");
			Sleep(3000);
			return 0x000;
		}
		
		if(Counter_01>20)
		{
			printf("\033[0m\n");
			printf("[\033[33m!\033[0m] \033[33m命令最大长度：20字节。 WarningCode:04\033[0m\n");
			goto Node_01;
		}
	}
	
	memset(Path_Flag_02,0,sizeof(Path_Flag_02));
	
//=========================================== 函数过滤模块
	// OS_Shell 过滤 
	time(&Cur_Time);
	Now=gmtime(&Cur_Time);
	snprintf(Time_Handel,20,"%d-%d-%d %d:%d:%d",1900+Now->tm_year,1+Now->tm_mon,Now->tm_mday,8+Now->tm_hour,Now->tm_min,Now->tm_sec);
	if(Target(Ac_Command,OS_Shell_Flag_01)==1)
	{
		printf("\033[1m[\033[1;31m-\033[0m\033[1m] \033[1;31m访问被拒绝。 ErrorCode:01\033[0m\n");
		
		FILE*Command5;
		Command5=fopen(Cmd_Log_Path,"a");
		fprintf(Command5,"[%s]\t# %s :(pwsh) %s \n",Time_Handel,getcwd(NULL,NULL),Ac_Command);
		fclose(Command5);
		
		FILE*Result5;
		Result5=fopen(Res_Log_Path,"a");
		fprintf(Result5,"[%s]\t# %s :(pwsh) 访问被拒绝。 ErrorCode:01 \n",Time_Handel,getcwd(NULL,NULL));
		fclose(Result5);
		
		goto Node_01;
	}
	if(Target(Ac_Command,OS_Shell_Flag_02)==1)
	{
		printf("\033[1m[\033[1;31m-\033[0m\033[1m] \033[1;31m访问被拒绝。 ErrorCode:02\033[0m\n");
		
		FILE*Command6;
		Command6=fopen(Cmd_Log_Path,"a");
		fprintf(Command6,"[%s]\t# %s :(cmd) %s \n",Time_Handel,getcwd(NULL,NULL),Ac_Command);
		fclose(Command6);
		
		FILE*Result6;
		Result6=fopen(Res_Log_Path,"a");
		fprintf(Result6,"[%s]\t# %s :(cmd) 访问被拒绝。 ErrorCode:02 \n",Time_Handel,getcwd(NULL,NULL));
		fclose(Result6);
		
		goto Node_01;
	}
	if(Target(Ac_Command,OS_Shell_Flag_03)==1)
	{
		printf("\033[1m[\033[1;31m-\033[0m\033[1m] \033[1;31m访问被拒绝。 ErrorCode:03\033[0m\n");
		
		FILE*Command7;
		Command7=fopen(Cmd_Log_Path,"a");
		fprintf(Command7,"[%s]\t# %s :(exe) %s \n",Time_Handel,getcwd(NULL,NULL),Ac_Command);
		fclose(Command7);
		
		FILE*Result7;
		Result7=fopen(Res_Log_Path,"a");
		fprintf(Result7,"[%s]\t# %s :(exe) 访问被拒绝。 ErrorCode:03 \n",Time_Handel,getcwd(NULL,NULL));
		fclose(Result7);
		
		goto Node_01;
	}
	
//=========================================== 作用模块
	//=====================================================
	//以下为内置函数组
	
	char Built_In_Function_011[4]="pwd",Built_In_Function_012[13]="Get-Location",Built_In_Function_013[3]="gl";
	char Built_In_Function_021[4]="dir",Built_In_Function_022[4]="gci",Built_In_Function_023[3]="ls",Built_In_Function_024[14]="Get-ChildItem";
	char Built_In_Function_031[4]="cat",Built_In_Function_032[3]="gc",Built_In_Function_033[5]="type",Built_In_Function_034[12]="Get-Content";
	char Built_In_Function_041[4]="cls",Built_In_Function_042[6]="clear",Built_In_Function_043[11]="Clear-Host";
	char Built_In_Function_051[40]="cd ",Built_In_Function_052[40]="Set-Location ",Built_In_Function_053[40]="chdir ",Built_In_Function_054[40]="sl ";
	
	//=====================================================
	
	// cd 命令
	if(Equal_Case_String(Ac_Command,Built_In_Function_051)==1)
	{
		Path_Flag_01=Chroot(Path_Flag_02,Path_Flag_03,Ac_Command,Built_In_Function_051,Path_Flag_01,Home_Path);
		goto Node_01;
	}
	if(Equal_Case_String(Ac_Command,Built_In_Function_052)==1)
	{
		Path_Flag_01=Chroot(Path_Flag_02,Path_Flag_03,Ac_Command,Built_In_Function_052,Path_Flag_01,Home_Path);
		goto Node_01;
	}
	if(Equal_Case_String(Ac_Command,Built_In_Function_053)==1)
	{
		Path_Flag_01=Chroot(Path_Flag_02,Path_Flag_03,Ac_Command,Built_In_Function_053,Path_Flag_01,Home_Path);
		goto Node_01;
	}
	if(Equal_Case_String(Ac_Command,Built_In_Function_054)==1)
	{
		Path_Flag_01=Chroot(Path_Flag_02,Path_Flag_03,Ac_Command,Built_In_Function_054,Path_Flag_01,Home_Path);
		goto Node_01;
	}
	
	// pwd 命令
	if(Target(Ac_Command,Built_In_Function_011)==1 || Target(Ac_Command,Built_In_Function_012)==1 || Target(Ac_Command,Built_In_Function_013)==1)
	{
		if(Path_Flag_01!=0)
		{
			printf("\nPath\n----\n%s\n\n",Path_Flag_03);
		}
		else
		{
			printf("\nPath\n----\nC:\\home\\kali\n\n");
		}
		
		FILE*Command8;
		Command8=fopen(Cmd_Log_Path,"a");
		fprintf(Command8,"[%s]\t# %s :(pwd) %s \n",Time_Handel,getcwd(NULL,NULL),Ac_Command);
		fclose(Command8);
		
		FILE*Result8;
		Result8=fopen(Res_Log_Path,"a");
		fprintf(Result8,"[%s]\t# %s :(pwd) Path: %s \n",Time_Handel,getcwd(NULL,NULL),Path_Flag_03);
		fclose(Result8);
		
		goto Node_01;
	}

	// ls 命令
	if(Target(Ac_Command,Built_In_Function_021)==1 || Target(Ac_Command,Built_In_Function_022)==1 || Target(Ac_Command,Built_In_Function_023)==1 || Target(Ac_Command,Built_In_Function_024)==1)
	{
		if(Path_Flag_01!=0)
		{
			//printf("\n    Directory of %s\n",Path_Flag_03);
			if((access(Home_Path,F_OK))!=-1)
			{
				if((access(Home_Path,R_OK))!=-1)
				{
					//printf("\e[2A");
					system("powershell -c \"ls |findstr -v \'C:\' |findstr -v \'\\\'\"");
				}
				else
				{
					printf("\n[\033[31m-\033[0m] 拒绝访问。\n");
				}
			}
			else
			{
				printf("\n[\033[31m-\033[0m] 系统找不到指定路径。\n");
			}
		}
		
		FILE*Command9;
		Command9=fopen(Cmd_Log_Path,"a");
		fprintf(Command9,"[%s]\t# %s :(ls)  %s \n",Time_Handel,getcwd(NULL,NULL),Ac_Command);
		fclose(Command9);
		
		FILE*Result91;
		Result91=popen("powershell -c \"ls |findstr -v \'C:\' |findstr -v \'\\\'\"","r");
		fgets(Buffer_Y,sizeof(Buffer_Y),Result91);
		fclose(Result91);
		
		FILE*Result9;
		Result9=fopen(Res_Log_Path,"a");
		fprintf(Result9,"[%s]\t# %s :(ls)  %s \n",Time_Handel,getcwd(NULL,NULL),Buffer_Y);
		fclose(Result9);
		
		memset(Buffer_Y,0,sizeof(Buffer_Y));
		goto Node_01;
	}

	// cat 命令
	if(Target(Ac_Command,Built_In_Function_031)==1)
	{
		Cat_Detect(Built_In_Function_031,Ac_Command,Path_Flag_02);
		goto Node_01;
	}
	if(Target(Ac_Command,Built_In_Function_032)==1)
	{
		Cat_Detect(Built_In_Function_032,Ac_Command,Path_Flag_02);
		goto Node_01;
	}
	if(Target(Ac_Command,Built_In_Function_033)==1)
	{
		Cat_Detect(Built_In_Function_033,Ac_Command,Path_Flag_02);
		goto Node_01;
	}
	if(Target(Ac_Command,Built_In_Function_034)==1)
	{
		Cat_Detect(Built_In_Function_034,Ac_Command,Path_Flag_02);
		goto Node_01;
	}

	// cls 命令
	if(Target(Ac_Command,Built_In_Function_041)==1 || Target(Ac_Command,Built_In_Function_042)==1 || Target(Ac_Command,Built_In_Function_043)==1)
	{
		system("cls");

		FILE*Command14;
		Command14=fopen(Cmd_Log_Path,"a");
		fprintf(Command14,"[%s]\t# %s :(cls) %s \n",Time_Handel,getcwd(NULL,NULL),Ac_Command);
		fclose(Command14);
		
		FILE*Result14;
		Result14=fopen(Res_Log_Path,"a");
		fprintf(Result14,"[%s]\t# %s :(cls)\n",Time_Handel,getcwd(NULL,NULL));
		fclose(Result14);
				
		goto Node_01;
	}
	
//=========================================== 丢弃模块 
	// 其他命令
	printf("\033[1;31m");
	printf("%s :无法将“%s”项识别为 cmdlet、函数、脚本文件或可运行程序的名称。请检查名称的拼写，如果包括路径，请确保路径正确，然后再试一次。\n",Ac_Command,Ac_Command);
	printf("所在位置 行:1 字符: 1\n");
	printf("+ %s\n",Ac_Command);
	printf("+ ");
	for(Tmp_Flag_03=0;Tmp_Flag_03<strlen(Ac_Command);Tmp_Flag_03++)
	{
		printf("~");
	}
	printf("\n");
	printf("    + CategoryInfo          : ObjectNotFound: (%s:String) [], CommandNotFoundException\n",Ac_Command);
	printf("    + FullyQualifiedErrorId : CommandNotFoundException\n\n");
	printf("\033[0m");
	
	FILE*Command15;
	Command15=fopen(Cmd_Log_Path,"a");
	fprintf(Command15,"[%s]\t# %s : %s \n",Time_Handel,getcwd(NULL,NULL),Ac_Command);
	fclose(Command15);
		
	FILE*Result15;
	Result15=fopen(Res_Log_Path,"a");
	fprintf(Result15,"[%s]\t# %s : \"%s\"未在函数组中。 \n",Time_Handel,getcwd(NULL,NULL),Ac_Command);
	fclose(Result15);
		
	memset(Ac_Command,0,sizeof(Ac_Command));
	goto Node_01;
	
}

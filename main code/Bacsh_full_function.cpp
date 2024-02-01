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
 Bacsh 6.5
 作者： Jessarin000
 日期： 2024-02-01 
*/

/*
 本程序已使用命令补丁。
 默认可使用命令为：“cat”、“cd”、“cls”、“ls” 和 “pwd” 以及它们的别名。 
 补丁添加的命令为：“whoami”、“hostname”、“id”、“touch”、“mkdir”和“rm”。 
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

int Touch_File(char *Ac_Command,char *Function_String,char *Home_Path,char (*Creat_File_Path)[50])
{
	int Counter_10,Counter_11,Counter_12,Counter_13,Counter_14;
	int Tmp_Flag_01,Tmp_Flag_02,Tmp_Flag_03,Tmp_Flag_04;
	int Return_Code_01;
	char Path_Flag_02[20];
	char Tmp_Flag_08[20];
	char Tmp_Flag_09[20];
	char *Env_Path;
	char *Env_Path_02;
	char Env_Path_03[70];
	char Command[50];
	char Isolate_Path[53];
	char Error_C[]="-";
	
	memset(Command,0,sizeof(Command));
	memset(Path_Flag_02,0,sizeof(Path_Flag_02));
	memset(Tmp_Flag_08,0,sizeof(Tmp_Flag_08));
	memset(Tmp_Flag_09,0,sizeof(Tmp_Flag_09));
	memset(Env_Path_03,0,sizeof(Env_Path_03));
	memset(Isolate_Path,0,sizeof(Isolate_Path));
	
	strcpy(Isolate_Path,Home_Path);
	strcpy(Command,Ac_Command);
	Command[strlen(Ac_Command)]=0;
	
	Env_Path_02=getcwd(NULL,NULL);
	Counter_10=0;
	Counter_11=0;
	Counter_12=0;
	Counter_13=0;
	Counter_14=0;
	Tmp_Flag_01=1;
	Tmp_Flag_02=0;
	Tmp_Flag_03=-2;
	Tmp_Flag_04=0;
	Return_Code_01=0;
	
	Node_04:
	for(Counter_11=0;Tmp_Flag_01==1 && Counter_11+strlen(Function_String)+Counter_10<strlen(Command);Counter_11++)
	{
		if(Command[Counter_11+strlen(Function_String)+Counter_10]==' ' || Command[Counter_11+strlen(Function_String)+Counter_10]=='\r' || Command[Counter_11+strlen(Function_String)+Counter_10]==':')
		{
			if(Command[Counter_11+strlen(Function_String)+Counter_10]==' ' && Counter_11==0)
			{
				Counter_10++;
				goto Node_04;
			}
			if(Command[Counter_11+strlen(Function_String)+Counter_10]==':')
			{
				Path_Flag_02[Counter_11]=Command[Counter_11+strlen(Function_String)+Counter_10];
				if(Tmp_Flag_02==0)
				{
					Tmp_Flag_02=1;
				}
				else
				{
					Tmp_Flag_02=2;
				}
				continue;
			}
			Tmp_Flag_01=0;
		}
		else
		{
			if(Command[Counter_11+strlen(Function_String)+Counter_10]=='/')
			{
				if(Command[Counter_11+strlen(Function_String)+Counter_10+1]=='\r' || Command[Counter_11+strlen(Function_String)+Counter_10+1]==0)
				{
					Tmp_Flag_04=3;
				}
				else
				{
					Tmp_Flag_03=-1;
					memset(Tmp_Flag_09,0,sizeof(Tmp_Flag_09));
				}
			}
			Path_Flag_02[Counter_11]=Command[Counter_11+strlen(Function_String)+Counter_10];
			if(Tmp_Flag_03>=0)
			{
				Tmp_Flag_09[Tmp_Flag_03]=Command[Counter_11+strlen(Function_String)+Counter_10];
			}
		}
		if(Tmp_Flag_03!=-2)
		{
			Tmp_Flag_03++;
		}
	}
	Tmp_Flag_01=0;
	if(Path_Flag_02[0]==0 || sizeof(Path_Flag_02)==0)
	{
		printf("[\033[31m-\033[0m] touch ： 无效参数。\n");
		printf("[?] 请使用 touch -h 显示帮助。\n");
		Tmp_Flag_01=2;
		Return_Code_01=13;
	}
	if(memcmp(Path_Flag_02,"-h",2)==0 && Tmp_Flag_01!=2)
	{
		printf("[\033[32m+\033[0m] 用法：touch [命令参数]... 文件名...\n");
		printf("本命令用于将指定文件的访问和修改时间更新为当前时间。\n\n");
		printf("若指定文件不存在，则会新建一个同文件名的空文件。\n"); 
		printf("  参数：\n");
		printf("\t-h\t显示此帮助并退出。\n");
		printf("\t-v\t显示版本信息并退出。\n\n");
		printf("有任何意见或建议请联系作者 <\033[1;4mkjx52@outlook.com\033[0m>。\n");
		
		Tmp_Flag_01=2;
		Return_Code_01=0;
	}
	if(memcmp(Path_Flag_02,"-v",2)==0 && Tmp_Flag_01!=2)
	{
		printf("touch 1.02\n");
		printf("版权所有 (C) 2023 Indie developers, Inc.\n\n");
		printf("Written by Jessarin\n");
		Tmp_Flag_01=2;
		Return_Code_01=0;
	}
	if(Target(Path_Flag_02,Error_C)==1 && Tmp_Flag_01!=2)
	{
		printf("[\033[31m-\033[0m] touch ： 无效参数。\n");
		printf("[?] 请使用 touch -h 显示帮助。\n");
		Tmp_Flag_01=2;
		Return_Code_01=13;
	}
	if(strlen(Path_Flag_02)==1 && Path_Flag_02[0]=='/' && Tmp_Flag_01!=2)
	{
		printf("[\033[31m-\033[0m] 无效输入。\n");
		Tmp_Flag_01=2;
		Return_Code_01=4;
	}
	if(Tmp_Flag_02==2 && Tmp_Flag_01!=2)
	{
		printf("[\033[31m-\033[0m] 无效输入。\n");
		Tmp_Flag_01=2;
		Return_Code_01=3;
	}
	if(Path_Flag_02[0]==':' && Tmp_Flag_01!=2)
	{
		printf("[\033[31m-\033[0m] 无效输入。\n");
		Tmp_Flag_01=2;
		Return_Code_01=3;
	}
	if(Tmp_Flag_01!=2)
	{
		if(Tmp_Flag_04==3 || Path_Flag_02[strlen(Path_Flag_02)-1]=='/')
		{
		    printf("[\033[31m-\033[0m]\033[31m touch : 请求无法完成，\"%s\" 是一个目录。\n\033[0m",Path_Flag_02);
		    Tmp_Flag_01=2;
		    Return_Code_01=1;
		}
	}
	if(Tmp_Flag_01!=2)
	{
		if(Tmp_Flag_03==-2)
		{
			memcpy(Tmp_Flag_09,Path_Flag_02,strlen(Path_Flag_02));
		}
		for(Tmp_Flag_04=0;Tmp_Flag_04<strlen(Tmp_Flag_09);Tmp_Flag_04++)
		{
			if(Tmp_Flag_09[Tmp_Flag_04]==':' || Tmp_Flag_09[Tmp_Flag_04]=='/')
			{
				printf("[\033[31m-\033[0m]\033[31m touch : 请求无法完成，因为文件名中不能包含以下任一字符：\n\t  “/” “\\” “:” “*” “\?” “\"” “<” “>” “|”\n\033[0m");
				Tmp_Flag_01=2;
				Return_Code_01=11;
			}
		}
	}
	if(Tmp_Flag_01!=2)
	{
		if(Tmp_Flag_02==1)
		{
			if(Path_Flag_02[1]!=':')
			{
				printf("[\033[31m-\033[0m] 无效输入。\n");
				Return_Code_01=5;
			}
			else
			{
				if(Path_Flag_02[0]!='c' && Path_Flag_02[0]!='C')
				{
					printf("[\033[31m-\033[0m]\033[31m 系统找不到指定路径。\n\033[0m");
					Return_Code_01=6;
				}
				else
				{
					if(strlen(Path_Flag_02)==2)
					{
						printf("[\033[31m-\033[0m] 无效输入。\n");
						Return_Code_01=7;
					}
					else
					{
						memset(Tmp_Flag_08,0,sizeof(Tmp_Flag_08));
						for(Tmp_Flag_02=2+strlen(Tmp_Flag_09);Tmp_Flag_02<strlen(Path_Flag_02);Tmp_Flag_02++)
						{
							Tmp_Flag_08[Tmp_Flag_02-2-strlen(Tmp_Flag_09)]=Path_Flag_02[Tmp_Flag_02-strlen(Tmp_Flag_09)];
						}
						strcat(Isolate_Path,Tmp_Flag_08);
						if((access(Isolate_Path,R_OK))!=-1)
						{
							if((access(Isolate_Path,W_OK))!=-1)
							{
								chdir(Isolate_Path);
								
								if((access(Tmp_Flag_09,F_OK))==-1)
								{
									FILE *Touch_File = NULL;
									Touch_File = fopen(Tmp_Flag_09, "w+");
									fclose(Touch_File);
									
									Env_Path=getcwd(NULL,NULL);
									strcpy(Env_Path_03,Env_Path);
									strcat(Env_Path_03,"\\");
									strcat(Env_Path_03,Tmp_Flag_09);
									
									for(Counter_13=0;Counter_13<15 && Creat_File_Path[Counter_13][0]!=0;Counter_13++);								
									for(Counter_12=0;Counter_12<strlen(Env_Path_03);Counter_12++)
									{
										Creat_File_Path[Counter_13][Counter_12]=Env_Path_03[Counter_12];
									}
									
									memset(Env_Path_03,0,sizeof(Env_Path_03));
									printf("[\033[32m+\033[0m] 文件创建成功：%s 。\n",Tmp_Flag_09);
									Return_Code_01=0;
								}
								else
								{
									Return_Code_01=12;
								}
							}
							else
							{
								printf("[\033[31m-\033[0m] 拒绝访问。\n");
								Return_Code_01=7;
							}
						}
						else
						{
							printf("[\033[31m-\033[0m] 系统找不到指定路径。\n");
							Return_Code_01=8;
						}
					}
				}
			}
		}
		else
		{
			if(Path_Flag_02[0]=='/')
			{
				memset(Tmp_Flag_08,0,sizeof(Tmp_Flag_08));
				for(Tmp_Flag_02=strlen(Tmp_Flag_09);Tmp_Flag_02<strlen(Path_Flag_02);Tmp_Flag_02++)
				{
					Tmp_Flag_08[Tmp_Flag_02-strlen(Tmp_Flag_09)]=Path_Flag_02[Tmp_Flag_02-strlen(Tmp_Flag_09)];
				}
				strcat(Isolate_Path,Tmp_Flag_08);
				if((access(Isolate_Path,R_OK))!=-1)
				{
					if((access(Isolate_Path,W_OK))!=-1)
					{
						chdir(Isolate_Path);
						
						if((access(Tmp_Flag_09,F_OK))==-1)
						{
							FILE *Touch_File_02 = NULL;
							Touch_File_02 = fopen(Tmp_Flag_09, "w+");
							fclose(Touch_File_02);
							
							Env_Path=getcwd(NULL,NULL);
							strcpy(Env_Path_03,Env_Path);
							strcat(Env_Path_03,"\\");
							strcat(Env_Path_03,Tmp_Flag_09);
							
							for(Counter_13=0;Counter_13<15 && Creat_File_Path[Counter_13][0]!=0;Counter_13++);
							for(Counter_12=0;Counter_12<strlen(Env_Path_03);Counter_12++)
							{
								Creat_File_Path[Counter_13][Counter_12]=Env_Path_03[Counter_12];
							}
							
							memset(Env_Path_03,0,sizeof(Env_Path_03));
							printf("[\033[32m+\033[0m] 文件创建成功：%s 。\n",Tmp_Flag_09);
							Return_Code_01=0;
						}
						else
						{
							Return_Code_01=12;
						}
					}
					else
					{
						printf("[\033[31m-\033[0m] 拒绝访问。\n");
						Return_Code_01=7;
					}
				}
				else
				{
					printf("[\033[31m-\033[0m] 系统找不到指定路径。\n");
					Return_Code_01=8;
				}
			}
			else
			{
				Env_Path=getcwd(NULL,NULL);
				
				memset(Tmp_Flag_08,0,sizeof(Tmp_Flag_08));
				for(Tmp_Flag_02=strlen(Tmp_Flag_09);Tmp_Flag_02<strlen(Path_Flag_02);Tmp_Flag_02++)
				{
					Tmp_Flag_08[Tmp_Flag_02-strlen(Tmp_Flag_09)]=Path_Flag_02[Tmp_Flag_02-strlen(Tmp_Flag_09)];
				}
				strcpy(Env_Path_03,Env_Path);
				strcat(Env_Path_03,"\\");
				strcat(Env_Path_03,Tmp_Flag_08);
				if((access(Env_Path_03,R_OK))!=-1)
				{
					if((access(Env_Path_03,W_OK))!=-1)
					{
						chdir(Env_Path_03);
						 
						if((access(Tmp_Flag_09,F_OK))==-1)
						{
							FILE *Touch_File_03 = NULL;
							Touch_File_03 = fopen(Tmp_Flag_09, "w+");
							fclose(Touch_File_03);
							
							memset(Env_Path_03,0,sizeof(Env_Path_03));
							Env_Path=getcwd(NULL,NULL);
							strcpy(Env_Path_03,Env_Path);
							strcat(Env_Path_03,"\\");
							strcat(Env_Path_03,Tmp_Flag_09);
							
							for(Counter_13=0;Counter_13<15 && Creat_File_Path[Counter_13][0]!=0;Counter_13++);								
							for(Counter_12=0;Counter_12<strlen(Env_Path_03);Counter_12++)
							{
								Creat_File_Path[Counter_13][Counter_12]=Env_Path_03[Counter_12];
							}
							
							memset(Env_Path_03,0,sizeof(Env_Path_03));
							printf("[\033[32m+\033[0m] 文件创建成功：%s 。\n",Tmp_Flag_09);
							Return_Code_01=0;
						}
						else
						{
							Return_Code_01=12;
						}
					}
					else
					{
						printf("[\033[31m-\033[0m] 拒绝访问。\n");
						Return_Code_01=9;
					}
				}
				else
				{
					printf("[\033[31m-\033[0m] 系统找不到指定路径。\n");
					Return_Code_01=10;
				}
			}
		} 
	}
	Env_Path=getcwd(NULL,NULL);
	chdir(Env_Path_02);
	
	time(&Cur_Time);
	Now=gmtime(&Cur_Time);
	snprintf(Time_Handel,20,"%d-%d-%d %d:%d:%d",1900+Now->tm_year,1+Now->tm_mon,Now->tm_mday,8+Now->tm_hour,Now->tm_min,Now->tm_sec);

	FILE*Touch_Command1;
	Touch_Command1=fopen(Cmd_Log_Path,"a");
	fprintf(Touch_Command1,"[%s]\t# %s : %s \n",Time_Handel,getcwd(NULL,NULL),Command);
	fclose(Touch_Command1);
	
	if(Return_Code_01==0)
	{
		FILE*Touch_Result1;
		Touch_Result1=fopen(Res_Log_Path,"a");
		fprintf(Touch_Result1,"[%s]\t# %s :(touch) %s \n",Time_Handel,Env_Path,Tmp_Flag_09);
		fclose(Touch_Result1);
	}
	else
	{
		if(Return_Code_01==12)
		{
			FILE*Touch_Result2;
			Touch_Result2=fopen(Res_Log_Path,"a");
			fprintf(Touch_Result2,"[%s]\t# %s :(touch) 文件更新。返回值：12\n",Time_Handel,getcwd(NULL,NULL));
			fclose(Touch_Result2);
		}
		else
		{
			FILE*Touch_Result2;
			Touch_Result2=fopen(Res_Log_Path,"a");
			fprintf(Touch_Result2,"[%s]\t# %s :(touch) 文件创建失败。返回值：%d\n",Time_Handel,getcwd(NULL,NULL),Return_Code_01);
			fclose(Touch_Result2);
		}
	}
	
	memset(Command,0,sizeof(Command));
	memset(Path_Flag_02,0,sizeof(Path_Flag_02));
	memset(Tmp_Flag_08,0,sizeof(Tmp_Flag_08));
	memset(Tmp_Flag_09,0,sizeof(Tmp_Flag_09));
	memset(Env_Path_03,0,sizeof(Env_Path_03));
	
	return Return_Code_01;
}

int Make_Directories(char *Ac_Command,char *Function_String,char *Home_Path,char (*Creat_File_Path)[50])
{
	int Counter_12,Counter_13,Counter_14,Counter_15,Counter_16;
	int Tmp_Flag_05,Tmp_Flag_06,Tmp_Flag_07,Tmp_Flag_12;
	int Return_Code_02;
	char Path_Flag_03[20];
	char Tmp_Flag_10[20];
	char Tmp_Flag_11[20];
	char *Env_Path_04;
	char *Env_Path_05;
	char Env_Path_06[70];
	char Command_01[50];
	char Isolate_Path[53];
	char Error_C[]="-";
	
	memset(Command_01,0,sizeof(Command_01));
	memset(Path_Flag_03,0,sizeof(Path_Flag_03));
	memset(Tmp_Flag_10,0,sizeof(Tmp_Flag_10));
	memset(Tmp_Flag_11,0,sizeof(Tmp_Flag_11));
	memset(Env_Path_06,0,sizeof(Env_Path_06));
	memset(Isolate_Path,0,sizeof(Isolate_Path));
	
	strcpy(Isolate_Path,Home_Path);
	strcpy(Command_01,Ac_Command);
	Command_01[strlen(Ac_Command)]=0;
	
	Env_Path_05=getcwd(NULL,NULL);
	Counter_12=0;
	Counter_13=0;
	Counter_14=0;
	Counter_15=0;
	Tmp_Flag_05=1;
	Tmp_Flag_06=0;
	Tmp_Flag_07=-2;
	Tmp_Flag_12=0;
	Return_Code_02=0;
	
	Node_05:
	for(Counter_13=0;Tmp_Flag_05==1 && Counter_13+strlen(Function_String)+Counter_12<strlen(Command_01);Counter_13++)
	{
		if(Command_01[Counter_13+strlen(Function_String)+Counter_12]==' ' || Command_01[Counter_13+strlen(Function_String)+Counter_12]=='\r' || Command_01[Counter_13+strlen(Function_String)+Counter_12]==':')
		{
			if(Command_01[Counter_13+strlen(Function_String)+Counter_12]==' ' && Counter_13==0)
			{
				Counter_12++;
				goto Node_05;
			}
			if(Command_01[Counter_13+strlen(Function_String)+Counter_12]==':')
			{
				Path_Flag_03[Counter_13]=Command_01[Counter_13+strlen(Function_String)+Counter_12];
				if(Tmp_Flag_06==0)
				{
					Tmp_Flag_06=1;
				}
				else
				{
					Tmp_Flag_06=2;
				}
				continue;
			}
			Tmp_Flag_05=0;
		}
		else
		{
			if(Command_01[Counter_13+strlen(Function_String)+Counter_12]=='/')
			{
				Tmp_Flag_07=-1;
				memset(Tmp_Flag_11,0,sizeof(Tmp_Flag_11));
			}
			Path_Flag_03[Counter_13]=Command_01[Counter_13+strlen(Function_String)+Counter_12];
			if(Tmp_Flag_07>=0)
			{
				Tmp_Flag_11[Tmp_Flag_07]=Command_01[Counter_13+strlen(Function_String)+Counter_12];
			}
		}
		if(Tmp_Flag_07!=-2)
		{
			Tmp_Flag_07++;
		}
	}
	Tmp_Flag_05=0;
	if(Path_Flag_03[0]==0 || sizeof(Path_Flag_03)==0)
	{
		printf("[\033[31m-\033[0m] mkdir ： 无效参数。\n");
		printf("[?] 请使用 mkdir -h 显示帮助。\n");
		Tmp_Flag_05=2;
		Return_Code_02=15;
	}
	if(memcmp(Path_Flag_03,"-h",2)==0 && Tmp_Flag_05!=2)
	{
		printf("[\033[32m+\033[0m] 用法：mkdir [命令参数]... 目录名...\n");
		printf("本命令用于在目标文件夹不存在的情况下创建文件夹。\n");
		printf("  参数：\n");
		printf("\t-h\t显示此帮助并退出。\n");
		printf("\t-v\t显示版本信息并退出。\n\n");
		printf("有任何意见或建议请联系作者 <\033[1;4mkjx52@outlook.com\033[0m>。\n");
		
		Tmp_Flag_05=2;
		Return_Code_02=0;
	}
	if(memcmp(Path_Flag_03,"-v",2)==0 && Tmp_Flag_05!=2)
	{
		printf("mkdir 1.04\n");
		printf("版权所有 (C) 2023 Indie developers, Inc.\n\n");
		printf("Written by Jessarin\n");
		Tmp_Flag_05=2;
		Return_Code_02=0;
	}
	if(Target(Path_Flag_03,Error_C) && Tmp_Flag_05!=2)
	{
		printf("[\033[31m-\033[0m] mkdir ： 无效参数。\n");
		printf("[?] 请使用 mkdir -h 显示帮助。\n");
		Tmp_Flag_05=2;
		Return_Code_02=15;
	}
	if(strlen(Path_Flag_03)==1 && Path_Flag_03[0]=='/' && Tmp_Flag_05!=2)
	{
		printf("[\033[31m-\033[0m] 无效输入。\n");
		Tmp_Flag_05=2;
		Return_Code_02=4;
	}
	if(Tmp_Flag_06==2 && Tmp_Flag_05!=2)
	{
		printf("[\033[31m-\033[0m] 无效输入。\n");
		Tmp_Flag_05=2;
		Return_Code_02=3;
	}
	if(Path_Flag_03[0]==':' && Tmp_Flag_05!=2)
	{
		printf("[\033[31m-\033[0m] 无效输入。\n");
		Tmp_Flag_05=2;
		Return_Code_02=3;
	}
	if(Tmp_Flag_05!=2)
	{
		if(Tmp_Flag_07==-2)
		{
			memcpy(Tmp_Flag_11,Path_Flag_03,strlen(Path_Flag_03));
		}
		for(Tmp_Flag_12=0;Tmp_Flag_12<strlen(Tmp_Flag_11);Tmp_Flag_12++)
		{
			if(Tmp_Flag_11[Tmp_Flag_12]==':' || Tmp_Flag_11[Tmp_Flag_12]=='/')
			{
				printf("[\033[31m-\033[0m]\033[31m mkdir : 请求无法完成，因为目录名中不能包含以下任一字符：\n\t  “/” “\\” “:” “*” “\?” “\"” “<” “>” “|”\n\033[0m");
				Tmp_Flag_05=2;
				Return_Code_02=11;
			}
		}
	}
	
	if(Tmp_Flag_05!=2)
	{
		if(Tmp_Flag_06==1)
		{
			if(Path_Flag_03[1]!=':')
			{
				printf("[\033[31m-\033[0m] 无效输入。\n");
				Return_Code_02=5;
			}
			else
			{
				if(Path_Flag_03[0]!='c' && Path_Flag_03[0]!='C')
				{
					printf("[\033[31m-\033[0m]\033[31m 系统找不到指定路径。\n\033[0m");
					Return_Code_02=6;
				}
				else
				{
					if(strlen(Path_Flag_03)==2)
					{
						printf("[\033[31m-\033[0m] 无效输入。\n");
						Return_Code_02=7;
					}
					else
					{
						memset(Tmp_Flag_10,0,sizeof(Tmp_Flag_10));
						for(Tmp_Flag_06=2+strlen(Tmp_Flag_11);Tmp_Flag_06<strlen(Path_Flag_03);Tmp_Flag_06++)
						{
							Tmp_Flag_10[Tmp_Flag_06-2-strlen(Tmp_Flag_11)]=Path_Flag_03[Tmp_Flag_06-strlen(Tmp_Flag_11)];
						}
						strcat(Isolate_Path,Tmp_Flag_10);
						if((access(Isolate_Path,R_OK))!=-1)
						{
							if((access(Isolate_Path,W_OK))!=-1)
							{
								chdir(Isolate_Path);
								if((access(Tmp_Flag_11,F_OK))==-1)
								{
									mkdir(Tmp_Flag_11);
									
									Env_Path_04=getcwd(NULL,NULL);
									strcpy(Env_Path_06,Env_Path_04);
									strcat(Env_Path_06,"\\");
									strcat(Env_Path_06,Tmp_Flag_11);
									
									for(Counter_14=0;Counter_14<15 && Creat_File_Path[Counter_14][0]!=0;Counter_14++);								
									for(Counter_13=0;Counter_13<strlen(Env_Path_06);Counter_13++)
									{
										Creat_File_Path[Counter_14][Counter_13]=Env_Path_06[Counter_13];
									}
									
									memset(Env_Path_06,0,sizeof(Env_Path_06));
									printf("[\033[32m+\033[0m] 目录创建成功：%s 。\n",Tmp_Flag_11);
									Return_Code_02=0;
								}
								else
								{
									printf("[\033[31m-\033[0m] mkdir : 请求无法完成，因为文件夹“%s”已存在。\n",Tmp_Flag_11);
									Return_Code_02=14;
								}
							}
							else
							{
								printf("[\033[31m-\033[0m] 拒绝访问。\n");
								Return_Code_02=7;
							}
						}
						else
						{
							printf("[\033[31m-\033[0m] 系统找不到指定路径。\n");
							Return_Code_02=8;
						}
					}
				}
			}
		}
		else
		{
			if(Path_Flag_03[0]=='/')
			{
				memset(Tmp_Flag_10,0,sizeof(Tmp_Flag_10));
				for(Tmp_Flag_06=strlen(Tmp_Flag_11);Tmp_Flag_06<strlen(Path_Flag_03);Tmp_Flag_06++)
				{
					Tmp_Flag_10[Tmp_Flag_06-strlen(Tmp_Flag_11)]=Path_Flag_03[Tmp_Flag_06-strlen(Tmp_Flag_11)];
				}
				strcat(Isolate_Path,Tmp_Flag_10);
				if((access(Isolate_Path,R_OK))!=-1)
				{
					if((access(Isolate_Path,W_OK))!=-1)
					{
						chdir(Isolate_Path);
						if((access(Tmp_Flag_11,F_OK))==-1)
						{
							mkdir(Tmp_Flag_11);
							
							Env_Path_04=getcwd(NULL,NULL);
							strcpy(Env_Path_06,Env_Path_04);
							strcat(Env_Path_06,"\\");
							strcat(Env_Path_06,Tmp_Flag_11);
							
							for(Counter_14=0;Counter_14<15 && Creat_File_Path[Counter_14][0]!=0;Counter_14++);								
							for(Counter_13=0;Counter_13<strlen(Env_Path_06);Counter_13++)
							{
								Creat_File_Path[Counter_14][Counter_13]=Env_Path_06[Counter_13];
							}
							
							memset(Env_Path_06,0,sizeof(Env_Path_06));
							printf("[\033[32m+\033[0m] 目录创建成功：%s 。\n",Tmp_Flag_11);
							Return_Code_02=0;
						}
						else
						{
							printf("[\033[31m-\033[0m] mkdir : 请求无法完成，因为文件夹“%s”已存在。\n",Tmp_Flag_11);
							Return_Code_02=14;
						}
					}
					else
					{
						printf("[\033[31m-\033[0m] 拒绝访问。\n");
						Return_Code_02=7;
					}
				}
				else
				{
					printf("[\033[31m-\033[0m] 系统找不到指定路径。\n");
					Return_Code_02=8;
				}
			}
			else
			{
				Env_Path_04=getcwd(NULL,NULL);
				
				memset(Tmp_Flag_10,0,sizeof(Tmp_Flag_10));
				for(Tmp_Flag_06=strlen(Tmp_Flag_11);Tmp_Flag_06<strlen(Path_Flag_03);Tmp_Flag_06++)
				{
					Tmp_Flag_10[Tmp_Flag_06-strlen(Tmp_Flag_11)]=Path_Flag_03[Tmp_Flag_06-strlen(Tmp_Flag_11)];
				}
				strcpy(Env_Path_06,Env_Path_04);
				strcat(Env_Path_06,"\\");
				strcat(Env_Path_06,Tmp_Flag_10);
				if((access(Env_Path_06,R_OK))!=-1)
				{
					if((access(Env_Path_06,W_OK))!=-1)
					{
						chdir(Env_Path_06);
						if((access(Tmp_Flag_11,F_OK))==-1)
						{
							mkdir(Tmp_Flag_11);
							
							memset(Env_Path_06,0,sizeof(Env_Path_06));
							Env_Path_04=getcwd(NULL,NULL);
							strcpy(Env_Path_06,Env_Path_04);
							strcat(Env_Path_06,"\\");
							strcat(Env_Path_06,Tmp_Flag_11);
							
							for(Counter_14=0;Counter_14<15 && Creat_File_Path[Counter_14][0]!=0;Counter_14++);								
							for(Counter_13=0;Counter_13<strlen(Env_Path_06);Counter_13++)
							{
								Creat_File_Path[Counter_14][Counter_13]=Env_Path_06[Counter_13];
							}
							
							memset(Env_Path_06,0,sizeof(Env_Path_06));
							printf("[\033[32m+\033[0m] 目录创建成功：%s 。\n",Tmp_Flag_11);
							Return_Code_02=0;
						}
						else
						{
							printf("[\033[31m-\033[0m] mkdir : 请求无法完成，因为文件夹“%s”已存在。\n",Tmp_Flag_11);
							Return_Code_02=14;
						}
					}
					else
					{
						printf("[\033[31m-\033[0m] 拒绝访问。\n");
						Return_Code_02=9;
					}
				}
				else
				{
					printf("[\033[31m-\033[0m] 系统找不到指定路径。\n");
					Return_Code_02=10;
				}
			}
		} 
	}
	Env_Path_04=getcwd(NULL,NULL);
	chdir(Env_Path_05);
	
	time(&Cur_Time);
	Now=gmtime(&Cur_Time);
	snprintf(Time_Handel,20,"%d-%d-%d %d:%d:%d",1900+Now->tm_year,1+Now->tm_mon,Now->tm_mday,8+Now->tm_hour,Now->tm_min,Now->tm_sec);

	FILE*Touch_Command1;
	Touch_Command1=fopen(Cmd_Log_Path,"a");
	fprintf(Touch_Command1,"[%s]\t# %s : %s \n",Time_Handel,getcwd(NULL,NULL),Command_01);
	fclose(Touch_Command1);
	
	if(Return_Code_02==0)
	{
		FILE*Touch_Result1;
		Touch_Result1=fopen(Res_Log_Path,"a");
		fprintf(Touch_Result1,"[%s]\t# %s :(mkdir) %s \n",Time_Handel,Env_Path_04,Tmp_Flag_11);
		fclose(Touch_Result1);
	}
	else
	{
		if(Return_Code_02==14)
		{
			FILE*Touch_Result2;
			Touch_Result2=fopen(Res_Log_Path,"a");
			fprintf(Touch_Result2,"[%s]\t# %s :(mkdir) 目录已存在。返回值：14\n",Time_Handel,getcwd(NULL,NULL));
			fclose(Touch_Result2);
		}
		else
		{
			FILE*Touch_Result2;
			Touch_Result2=fopen(Res_Log_Path,"a");
			fprintf(Touch_Result2,"[%s]\t# %s :(mkdir) 目录创建失败。返回值：%d\n",Time_Handel,getcwd(NULL,NULL),Return_Code_02);
			fclose(Touch_Result2);
		}
	}
	
	memset(Command_01,0,sizeof(Command_01));
	memset(Path_Flag_03,0,sizeof(Path_Flag_03));
	memset(Tmp_Flag_10,0,sizeof(Tmp_Flag_10));
	memset(Tmp_Flag_11,0,sizeof(Tmp_Flag_11));
	memset(Env_Path_06,0,sizeof(Env_Path_06));
	
	return Return_Code_02;
}

int Remove_Dir(const char *Dir)
{
	int Re_Code_01;
	char Current_Dir[2] = ".";
	char Up_Dir[3] = "..";
	char Dir_Name[50];
	struct dirent *Dir_02;
	struct stat Buffer_02;
	
	memset(Dir_Name,0,sizeof(Dir_Name));
	Re_Code_01=0;
	
	if(access(Dir,F_OK)!=0)
	{
		return 0;
	}
	if(stat(Dir,&Buffer_02)<0)
	{
		return 1;
	}
	if(S_ISREG(Buffer_02.st_mode))
	{
		Re_Code_01=remove(Dir);
		return Re_Code_01;
	}
	else
	{
		if(S_ISDIR(Buffer_02.st_mode))
		{
			DIR *Dir_01;
			Dir_01=opendir(Dir);
			while((Dir_02=readdir(Dir_01))!=NULL)
			{
				if((strcmp(Current_Dir,Dir_02->d_name))==0 || (strcmp(Up_Dir,Dir_02->d_name))==0)
				{
					continue;
				}
				sprintf(Dir_Name,"%s/%s",Dir,Dir_02->d_name);
				Re_Code_01=Remove_Dir(Dir_Name);
				if(Re_Code_01!=0)
				{
					return Re_Code_01;
				}
			}
			closedir(Dir_01);
			rmdir(Dir);
			
			return 0;
		}
		else
		{
			return 2;  
		}
	}
}

int Integrate_Arrays(char (*Creat_File_Path)[50],int Counter_14,int Counter_15)
{
	int Re_Code_02;
	int Counter_17;
	Re_Code_02=0;
	Counter_17=0;
	
	if(Creat_File_Path[Counter_15+1][0]!=0 && Counter_15+1<Counter_14)
	{
		for(Counter_17=0;Counter_17<50;Counter_17++)
		{
			Creat_File_Path[Counter_15][Counter_17]=Creat_File_Path[Counter_15+1][Counter_17];
			Creat_File_Path[Counter_15+1][Counter_17]=0;
		}
		
		return 0;
	}
	else
	{
		if(Creat_File_Path[Counter_15+1][0]==0 && Counter_15+1<Counter_14)
		{
			Re_Code_02=Integrate_Arrays(Creat_File_Path,Counter_14,Counter_15+1);
			if(Re_Code_02==0)
			{
				for(Counter_17=0;Counter_17<50;Counter_17++)
				{
					Creat_File_Path[Counter_15][Counter_17]=Creat_File_Path[Counter_15+1][Counter_17];
					Creat_File_Path[Counter_15+1][Counter_17]=0;
				}
				
				return 0;
			}
			else
			{
				return Re_Code_02;
			}
		}
		else
		{
			return 1;
		}
	}
}

int Remove(char *Ac_Command,char *Function_String,char *Home_Path,char (*Creat_File_Path)[50],int Time_Monitor_01,int Time_Monitor_02)
{
	int Counter_12,Counter_13,Counter_14,Counter_15,Counter_16,Counter_17;
	int Tmp_Flag_05,Tmp_Flag_06,Tmp_Flag_07,Tmp_Flag_12;
	int Return_Code_02,Re_Code_03;
	int Stat_Res;
	char Path_Flag_04[20];
	char Tmp_Flag_10[20];
	char Tmp_Flag_11[20];
	char *Env_Path_04;
	char *Env_Path_05;
	char Env_Path_06[70];
	char Env_Path_07[70];
	char Command_01[50];
	char File_Path_02[50];
	char File_Path_03[50];
	char Isolate_Path[53];
	char Error_C[]="-";
	struct stat Buffer_01;
	
	memset(File_Path_03,0,sizeof(File_Path_03));	
	memset(File_Path_02,0,sizeof(File_Path_02));
	memset(Tmp_Flag_10,0,sizeof(Tmp_Flag_10));
	memset(Tmp_Flag_11,0,sizeof(Tmp_Flag_11));
	memset(Command_01,0,sizeof(Command_01));
	memset(Path_Flag_04,0,sizeof(Path_Flag_04));
	memset(Env_Path_06,0,sizeof(Env_Path_06));
	memset(Isolate_Path,0,sizeof(Isolate_Path));
	
	strcpy(Isolate_Path,Home_Path);
	strcpy(Command_01,Ac_Command);
	Command_01[strlen(Ac_Command)]=0;
	
	Env_Path_05=getcwd(NULL,NULL);
	Stat_Res=0;
	Counter_12=0;
	Counter_13=0;
	Counter_14=0;
	Counter_15=0;
	Counter_16=0;
	Counter_17=0;
	Tmp_Flag_05=1;
	Tmp_Flag_06=0;
	Tmp_Flag_07=-2;
	Tmp_Flag_12=0;
	Return_Code_02=0;
	Re_Code_03=0;
	
	Node_06:
	for(Counter_13=0;Tmp_Flag_05==1 && Counter_13+strlen(Function_String)+Counter_12<strlen(Command_01);Counter_13++)
	{
		if(Command_01[Counter_13+strlen(Function_String)+Counter_12]==' ' || Command_01[Counter_13+strlen(Function_String)+Counter_12]=='\r' || Command_01[Counter_13+strlen(Function_String)+Counter_12]==':')
		{
			if(Command_01[Counter_13+strlen(Function_String)+Counter_12]==' ' && Counter_13==0)
			{
				Counter_12++;
				goto Node_06;
			}
			if(Command_01[Counter_13+strlen(Function_String)+Counter_12]==':')
			{
				Path_Flag_04[Counter_13]=Command_01[Counter_13+strlen(Function_String)+Counter_12];
				if(Tmp_Flag_06==0)
				{
					Tmp_Flag_06=1;
				}
				else
				{
					Tmp_Flag_06=2;
				}
				continue;
			}
			Tmp_Flag_05=0;
		}
		else
		{
			if(Command_01[Counter_13+strlen(Function_String)+Counter_12]=='/')
			{
				Tmp_Flag_07=-1;
				memset(Tmp_Flag_11,0,sizeof(Tmp_Flag_11));
			}
			Path_Flag_04[Counter_13]=Command_01[Counter_13+strlen(Function_String)+Counter_12];
			if(Tmp_Flag_07>=0)
			{
				Tmp_Flag_11[Tmp_Flag_07]=Command_01[Counter_13+strlen(Function_String)+Counter_12];
			}
		}
		if(Tmp_Flag_07!=-2)
		{
			Tmp_Flag_07++;
		}
	}
	Tmp_Flag_05=0;
	if(Path_Flag_04[0]==0 || sizeof(Path_Flag_04)==0)
	{
		printf("[\033[31m-\033[0m] rm ： 无效参数。\n");
		printf("[?] 请使用 rm -h 显示帮助。\n");
		Tmp_Flag_05=2;
		Return_Code_02=18;
	}
	if(memcmp(Path_Flag_04,"-h",2)==0 && Tmp_Flag_05!=2)
	{
		printf("[\033[32m+\033[0m] 用法：rm [命令参数]... [文件名]...\n");
		printf("本命令用于删除（解绑）文件或文件链接。\n");
		printf("  参数：\n");
		printf("\t-h\t显示此帮助并退出。\n");
		printf("\t-v\t显示版本信息并退出。\n\n");
		printf("  默认情况下，本命令可自动识别数据类型（文件/文件夹），不需要额外参数或标记。\n\n"); 
		printf("  注意:\n");
		printf("  1.此命令不支持删除环境文件。若的确需要更改环境文件，请考虑使用 \033[1;4mwipe\033[0m 命令。\n");
		printf("  2.请注意，如果使用 rm 删除文件，则在有足够的专业知识和/或时间的情况下，可能会恢复其中的某些内容。\n");
		printf("    为了更好地确保内容确实不可恢复，请考虑使用 \033[1;4mshred\033[0m 命令。\n\n");
		printf("有任何意见或建议请联系作者 <\033[1;4mkjx52@outlook.com\033[0m>。\n");
		
		Tmp_Flag_05=2;
		Return_Code_02=0;
	}
	if(memcmp(Path_Flag_04,"-v",2)==0 && Tmp_Flag_05!=2)
	{
		printf("rm 1.12\n");
		printf("版权所有 (C) 2023 Indie developers, Inc.\n\n");
		printf("Written by Jessarin\n");
		Tmp_Flag_05=2;
		Return_Code_02=0;
	}
	if(Target(Path_Flag_04,Error_C) && Tmp_Flag_05!=2)
	{
		printf("[\033[31m-\033[0m] rm ： 无效参数。\n");
		printf("[?] 请使用 rm -h 显示帮助。\n");
		Tmp_Flag_05=2;
		Return_Code_02=18;
	}
	if(strlen(Path_Flag_04)==1 && Path_Flag_04[0]=='/' && Tmp_Flag_05!=2)
	{
		printf("[\033[31m-\033[0m] 无效输入。\n");
		Tmp_Flag_05=2;
		Return_Code_02=4;
	}
	if(Tmp_Flag_06==2 && Tmp_Flag_05!=2)
	{
		printf("[\033[31m-\033[0m] 无效输入。\n");
		Tmp_Flag_05=2;
		Return_Code_02=3;
	}
	if(Path_Flag_04[0]==':' && Tmp_Flag_05!=2)
	{
		printf("[\033[31m-\033[0m] 无效输入。\n");
		Tmp_Flag_05=2;
		Return_Code_02=3;
	}
	if(Tmp_Flag_05!=2)
	{
		if(Tmp_Flag_07==-2)
		{
			memcpy(Tmp_Flag_11,Path_Flag_04,strlen(Path_Flag_04));
		}
		for(Tmp_Flag_12=0;Tmp_Flag_12<strlen(Tmp_Flag_11);Tmp_Flag_12++)
		{
			if(Tmp_Flag_11[Tmp_Flag_12]==':' || Tmp_Flag_11[Tmp_Flag_12]=='/')
			{
				printf("[\033[31m-\033[0m]\033[31m rm : 请求无法完成，因为目录名中不能包含以下任一字符：\n\t  “/” “\\” “:” “*” “\?” “\"” “<” “>” “|”\n\033[0m");
				Tmp_Flag_05=2;
				Return_Code_02=11;
			}
		}
	}
	
	if(Tmp_Flag_05!=2)
	{
		if(Tmp_Flag_06==1)
		{
			if(Path_Flag_04[1]!=':')
			{
				printf("[\033[31m-\033[0m] 无效输入。\n");
				Return_Code_02=5;
			}
			else
			{
				if(Path_Flag_04[0]!='c' && Path_Flag_04[0]!='C')
				{
					printf("[\033[31m-\033[0m]\033[31m 系统找不到指定路径。\n\033[0m");
					Return_Code_02=6;
				}
				else
				{
					if(strlen(Path_Flag_04)==2)
					{
						printf("[\033[31m-\033[0m] 无效输入。\n");
						Return_Code_02=7;
					}
					else
					{
						memset(Tmp_Flag_10,0,sizeof(Tmp_Flag_10));
						for(Tmp_Flag_06=2+strlen(Tmp_Flag_11);Tmp_Flag_06<strlen(Path_Flag_04);Tmp_Flag_06++)
						{
							Tmp_Flag_10[Tmp_Flag_06-2-strlen(Tmp_Flag_11)]=Path_Flag_04[Tmp_Flag_06-strlen(Tmp_Flag_11)];
						}
						strcat(Isolate_Path,Tmp_Flag_10);
						
						if((access(Isolate_Path,R_OK))!=-1)
						{
							if((access(Isolate_Path,W_OK))!=-1)
							{
								chdir(Isolate_Path);
								
								if((access(Tmp_Flag_11,F_OK))!=-1)
								{
									
									Env_Path_04=getcwd(NULL,NULL);
									strcpy(Env_Path_06,Env_Path_04);
									strcat(Env_Path_06,"\\");
									strcat(Env_Path_06,Tmp_Flag_11);
									for(Counter_14=0;Counter_14<15 && Creat_File_Path[Counter_14][0]!=0;Counter_14++);
									for(Tmp_Flag_12=0;Tmp_Flag_12<Counter_14;Tmp_Flag_12++)
									{
										for(Counter_15=0;Counter_15<50;Counter_15++)
										{
											File_Path_02[Counter_15]=Creat_File_Path[Tmp_Flag_12][Counter_15];
										}
										if(strcmp(Env_Path_06,File_Path_02)==0)
										{
											Counter_16=1;
											break;
										}
									}
									
									if(Counter_16==1)
									{
										Stat_Res=stat(Env_Path_06,&Buffer_01);
										if(Stat_Res>0 || Stat_Res==0)
										{
											if(S_IFDIR & Buffer_01.st_mode)
											{
												Stat_Res=1;
											}
											else
											{
												if(S_IFREG & Buffer_01.st_mode)
												{
													Stat_Res=0;
												}
												else
												{
													Stat_Res=3;
												}
											}
											switch(Stat_Res)
											{
												case 1 :
													Tmp_Flag_12=Remove_Dir(Tmp_Flag_11);
													switch(Tmp_Flag_12)
													{
														case 0 :
															printf("[\033[32m+\033[0m] 文件删除成功。\n");
															
															Node_07:
															for(Counter_15=0;Counter_15<Counter_14;Counter_15++)
															{
																if(Creat_File_Path[Counter_15][0]!=0)
																{
																	for(Counter_17=0;Counter_17<strlen(File_Path_02);Counter_17++)
																	{
																		File_Path_03[Counter_17]=Creat_File_Path[Counter_15][Counter_17];
																	}
																	printf("Creat_File_Path[Counter_15][Counter_17]=%c\n",Creat_File_Path[Counter_15][Counter_17]);
																	if(strcmp(File_Path_02,File_Path_03)==0 && (Creat_File_Path[Counter_15][strlen(File_Path_02)]==0 || Creat_File_Path[Counter_15][strlen(File_Path_02)]=='\\' || Creat_File_Path[Counter_15][strlen(File_Path_02)]=='/'))
																	{
																		for(Counter_17=0;Counter_17<50;Counter_17++)
																		{
																			//printf("+==+\n");
																			Creat_File_Path[Counter_15][Counter_17]=0;
																			Creat_File_Path[Counter_15][Counter_17]=Creat_File_Path[Counter_15+1][Counter_17];
																			Creat_File_Path[Counter_15+1][Counter_17]=0;
																		}
																		memset(File_Path_03,0,sizeof(File_Path_03));
																		goto Node_07;
																	}
																	memset(File_Path_03,0,sizeof(File_Path_03));
																}
																else
																{
																	if(Counter_14<15)
																	{
																		Re_Code_03=Integrate_Arrays(Creat_File_Path,Counter_14,Counter_15);
																	}
																	else
																	{
																		Re_Code_03=Integrate_Arrays(Creat_File_Path,Counter_14-1,Counter_15);
																		for(Counter_17=0;Counter_17<50;Counter_17++)
																		{
																			Creat_File_Path[14][Counter_17]=0;
																		}
																	}
																	if(Re_Code_03==0)
																	{
																		goto Node_07;
																	}
																}
															}
															
															Time_Monitor_02--;
															Return_Code_02=0;
															break;
														
														case 1 || -1 :
															printf("[\033[31m-\033[0m] rm : 请求无法完成，访问被拒绝。\n");
															Return_Code_02=14;
															break;
														
														case 2 :
															printf("[\033[31m-\033[0m] rm : 请求无法完成，数据结构类型未知。此事件将被报告。\n");
															Return_Code_02=16;
															break;
														
														default:
															printf("[\033[31m?\033[0m] rm : 未知错误，此事件将被报告。\n");
															Return_Code_02=17;
															break;
													}
													break;
												
												case 0 :
													Tmp_Flag_12=remove(Tmp_Flag_11);
													
													if(Tmp_Flag_12==0)
													{
														printf("[\033[32m+\033[0m] 文件删除成功。\n");
														
														Node_08:
														for(Counter_15=0;Counter_15<Counter_14;Counter_15++)
														{
															if(Creat_File_Path[Counter_15][0]!=0)
															{
																for(Counter_17=0;Counter_17<50;Counter_17++)
																{
																	File_Path_03[Counter_17]=Creat_File_Path[Counter_15][Counter_17];
																}
																if(strcmp(File_Path_02,File_Path_03)==0)
																{
																	for(Counter_17=0;Counter_17<50;Counter_17++)
																	{
																		Creat_File_Path[Counter_15][Counter_17]=0;
																		Creat_File_Path[Counter_15][Counter_17]=Creat_File_Path[Counter_15+1][Counter_17];
																		Creat_File_Path[Counter_15+1][Counter_17]=0;
																	}
																	memset(File_Path_03,0,sizeof(File_Path_03));
																	goto Node_08;
																}
																memset(File_Path_03,0,sizeof(File_Path_03));
															}
															else
															{
																if(Counter_14<15)
																{
																	Re_Code_03=Integrate_Arrays(Creat_File_Path,Counter_14,Counter_15);
																}
																else
																{
																	Re_Code_03=Integrate_Arrays(Creat_File_Path,Counter_14-1,Counter_15);
																	for(Counter_17=0;Counter_17<50;Counter_17++)
																	{
																		Creat_File_Path[14][Counter_17]=0;
																	}
																}
																if(Re_Code_03==0)
																{
																	goto Node_08;
																}
															}
														}
														
														Time_Monitor_01--;
														Return_Code_02=0;
													}
													else
													{
														printf("[\033[31m-\033[0m] rm : 请求无法完成，访问被拒绝。\n");
														Return_Code_02=14;
													}
													
													break;
												
												default:
													printf("[\033[31m-\033[0m] rm : 请求无法完成，数据结构类型未知。此事件将被报告。\n");
													Return_Code_02=16;
													
													break;
											}
											Stat_Res=0;
										}
										else
										{
											printf("[\033[31m-\033[0m] rm : 请求无法完成，访问被拒绝。\n");
											Return_Code_02=14;
										}
									}
									else
									{
										printf("[\033[31m-\033[0m] rm : 请求无法完成，因为此命令不支持删除环境文件。\n");
										printf("    若的确需要更改环境文件，请使用 \033[1;4mwipe\033[0m 命令。\n");
										Return_Code_02=15;
									}
								}
								else
								{
									printf("[\033[31m-\033[0m] 系统找不到指定路径。\n");
									Return_Code_02=12;
								}
							}
							else
							{
								printf("[\033[31m-\033[0m] rm : 请求无法完成，访问被拒绝。\n");
								Return_Code_02=7;
							}
						}
						else
						{
							printf("[\033[31m-\033[0m] 系统找不到指定路径。\n");
							Return_Code_02=8;
						}
					}
				}
			}
		}
		else
		{
			if(Path_Flag_04[0]=='/')
			{
				memset(Tmp_Flag_10,0,sizeof(Tmp_Flag_10));
				for(Tmp_Flag_06=strlen(Tmp_Flag_11);Tmp_Flag_06<strlen(Path_Flag_04);Tmp_Flag_06++)
				{
					Tmp_Flag_10[Tmp_Flag_06-strlen(Tmp_Flag_11)]=Path_Flag_04[Tmp_Flag_06-strlen(Tmp_Flag_11)];
				}
				strcat(Isolate_Path,Tmp_Flag_10);
				if((access(Isolate_Path,R_OK))!=-1)
				{
					if((access(Isolate_Path,W_OK))!=-1)
					{
						chdir(Isolate_Path);
						
						if((access(Tmp_Flag_11,F_OK))!=-1)
						{
							Env_Path_04=getcwd(NULL,NULL);
							strcpy(Env_Path_06,Env_Path_04);
							strcat(Env_Path_06,"\\");
							strcat(Env_Path_06,Tmp_Flag_11);
							for(Counter_14=0;Counter_14<15 && Creat_File_Path[Counter_14][0]!=0;Counter_14++);
							for(Tmp_Flag_12=0;Tmp_Flag_12<Counter_14;Tmp_Flag_12++)
							{
								for(Counter_15=0;Counter_15<50;Counter_15++)
								{
									File_Path_02[Counter_15]=Creat_File_Path[Tmp_Flag_12][Counter_15];
								}
								if(strcmp(Env_Path_06,File_Path_02)==0)
								{
									Counter_16=1;
									break;
								}
							}
							if(Counter_16==1)
							{
								Stat_Res=stat(Env_Path_06,&Buffer_01);
								if(Stat_Res>0 || Stat_Res==0)
								{
									if(S_IFDIR & Buffer_01.st_mode)
									{
										Stat_Res=1;
									}
									else
									{
										if(S_IFREG & Buffer_01.st_mode)
										{
											Stat_Res=0;
										}
										else
										{
											Stat_Res=3;
										}
									}
									switch(Stat_Res)
									{
										case 1 :
											Tmp_Flag_12=Remove_Dir(Tmp_Flag_11);
											switch(Tmp_Flag_12)
											{
												case 0 :
													printf("[\033[32m+\033[0m] 文件删除成功。\n");
													
													Node_09:
													for(Counter_15=0;Counter_15<Counter_14;Counter_15++)
													{
														if(Creat_File_Path[Counter_15][0]!=0)
														{
															for(Counter_17=0;Counter_17<strlen(File_Path_02);Counter_17++)
															{
																File_Path_03[Counter_17]=Creat_File_Path[Counter_15][Counter_17];
															}
															if(strcmp(File_Path_02,File_Path_03)==0 && (Creat_File_Path[Counter_15][Counter_17]==0 || Creat_File_Path[Counter_15][Counter_17]=='\\' || Creat_File_Path[Counter_15][Counter_17]=='/'))
															{
																for(Counter_17=0;Counter_17<50;Counter_17++)
																{
																	Creat_File_Path[Counter_15][Counter_17]=0;
																	Creat_File_Path[Counter_15][Counter_17]=Creat_File_Path[Counter_15+1][Counter_17];
																	Creat_File_Path[Counter_15+1][Counter_17]=0;
																}
																memset(File_Path_03,0,sizeof(File_Path_03));
																goto Node_09;
															}
															memset(File_Path_03,0,sizeof(File_Path_03));
														}
														else
														{
															if(Counter_14<15)
															{
																Re_Code_03=Integrate_Arrays(Creat_File_Path,Counter_14,Counter_15);
															}
															else
															{
																Re_Code_03=Integrate_Arrays(Creat_File_Path,Counter_14-1,Counter_15);
																for(Counter_17=0;Counter_17<50;Counter_17++)
																{
																	Creat_File_Path[14][Counter_17]=0;
																}
															}
															if(Re_Code_03==0)
															{
																goto Node_09;
															}
														}
													}
													
													Time_Monitor_02--;
													Return_Code_02=0;
													break;
												
												case 1 || -1 :
													printf("[\033[31m-\033[0m] rm : 请求无法完成，访问被拒绝。\n");
													Return_Code_02=14;
													break;
												
												case 2 :
													printf("[\033[31m-\033[0m] rm : 请求无法完成，数据结构类型未知。此事件将被报告。\n");
													Return_Code_02=16;
													break;
												
												default:
													printf("[\033[31m?\033[0m] rm : 未知错误，此事件将被报告。\n");
													Return_Code_02=17;
													break;
											}
											break;
										
										case 0 :
											Tmp_Flag_12=remove(Tmp_Flag_11);
											
											if(Tmp_Flag_12==0)
											{
												printf("[\033[32m+\033[0m] 文件删除成功。\n");
												
												Node_10:
												for(Counter_15=0;Counter_15<Counter_14;Counter_15++)
												{
													if(Creat_File_Path[Counter_15][0]!=0)
													{
														for(Counter_17=0;Counter_17<50;Counter_17++)
														{
															File_Path_03[Counter_17]=Creat_File_Path[Counter_15][Counter_17];
														}
														if(strcmp(File_Path_02,File_Path_03)==0)
														{
															for(Counter_17=0;Counter_17<50;Counter_17++)
															{
																Creat_File_Path[Counter_15][Counter_17]=0;
																Creat_File_Path[Counter_15][Counter_17]=Creat_File_Path[Counter_15+1][Counter_17];
																Creat_File_Path[Counter_15+1][Counter_17]=0;
															}
															memset(File_Path_03,0,sizeof(File_Path_03));
															goto Node_10;
														}
														memset(File_Path_03,0,sizeof(File_Path_03));
													}
													else
													{
														if(Counter_14<15)
														{
															Re_Code_03=Integrate_Arrays(Creat_File_Path,Counter_14,Counter_15);
														}
														else
														{
															Re_Code_03=Integrate_Arrays(Creat_File_Path,Counter_14-1,Counter_15);
															for(Counter_17=0;Counter_17<50;Counter_17++)
															{
																Creat_File_Path[14][Counter_17]=0;
															}
														}
														if(Re_Code_03==0)
														{
															goto Node_10;
														}
													}
												}
												
												Time_Monitor_01--;
												Return_Code_02=0;
											}
											else
											{
												printf("[\033[31m-\033[0m] rm : 请求无法完成，访问被拒绝。\n");
												Return_Code_02=14;
											}
											
											break;
										
										default:
											printf("[\033[31m-\033[0m] rm : 请求无法完成，数据结构类型未知。此事件将被报告。\n");
											Return_Code_02=16;
											
											break;
									}
									Stat_Res=0;
								}
								else
								{
									printf("[\033[31m-\033[0m] rm : 请求无法完成，访问被拒绝。\n");
									Return_Code_02=14;
								}
							}
							else
							{
								printf("[\033[31m-\033[0m] rm : 请求无法完成，因为此命令不支持删除环境文件。\n");
								printf("    若的确需要更改环境文件，请使用 \033[1;4mwipe\033[0m 命令。\n");
								Return_Code_02=15;
							}
						}
						else
						{
							printf("[\033[31m-\033[0m] 系统找不到指定路径。\n");
							Return_Code_02=12;
						}
					}
					else
					{
						printf("[\033[31m-\033[0m] rm : 请求无法完成，访问被拒绝。\n");
						Return_Code_02=7;
					}
				}
				else
				{
					printf("[\033[31m-\033[0m] 系统找不到指定路径。\n");
					Return_Code_02=8;
				}
			}
			else
			{
				Env_Path_04=getcwd(NULL,NULL);
				
				memset(Tmp_Flag_10,0,sizeof(Tmp_Flag_10));
				for(Tmp_Flag_06=strlen(Tmp_Flag_11);Tmp_Flag_06<strlen(Path_Flag_04);Tmp_Flag_06++)
				{
					Tmp_Flag_10[Tmp_Flag_06-strlen(Tmp_Flag_11)]=Path_Flag_04[Tmp_Flag_06-strlen(Tmp_Flag_11)];
				}
				strcpy(Env_Path_06,Env_Path_04);
				strcat(Env_Path_06,"\\");
				strcat(Env_Path_06,Tmp_Flag_10);
				
				if((access(Env_Path_06,R_OK))!=-1)
				{
					if((access(Env_Path_06,W_OK))!=-1)
					{
						chdir(Env_Path_06);
						
						if((access(Tmp_Flag_11,F_OK))!=-1)
						{
							Env_Path_04=getcwd(NULL,NULL);
							memset(Env_Path_06,0,sizeof(Env_Path_06));
							strcpy(Env_Path_06,Env_Path_04);
							strcat(Env_Path_06,"\\");
							strcat(Env_Path_06,Tmp_Flag_11);
							for(Counter_14=0;Counter_14<15 && Creat_File_Path[Counter_14][0]!=0;Counter_14++);
							for(Tmp_Flag_12=0;Tmp_Flag_12<Counter_14;Tmp_Flag_12++)
							{
								for(Counter_15=0;Counter_15<50;Counter_15++)
								{
									File_Path_02[Counter_15]=Creat_File_Path[Tmp_Flag_12][Counter_15];
								}
								if(strcmp(Env_Path_06,File_Path_02)==0)
								{
									Counter_16=1;
									break;
								}
							}
							if(Counter_16==1)
							{
								Stat_Res=stat(Env_Path_06,&Buffer_01);
								if(Stat_Res>0 || Stat_Res==0)
								{
									if(S_IFDIR & Buffer_01.st_mode)
									{
										Stat_Res=1;
									}
									else
									{
										if(S_IFREG & Buffer_01.st_mode)
										{
											Stat_Res=0;
										}
										else
										{
											Stat_Res=3;
										}
									}
									switch(Stat_Res)
									{
										case 1 :
											Tmp_Flag_12=Remove_Dir(Tmp_Flag_11);
											switch(Tmp_Flag_12)
											{
												case 0 :
													printf("[\033[32m+\033[0m] 文件删除成功。\n");
													
													Node_11:
													for(Counter_15=0;Counter_15<Counter_14;Counter_15++)
													{
														if(Creat_File_Path[Counter_15][0]!=0)
														{
															for(Counter_17=0;Counter_17<strlen(File_Path_02);Counter_17++)
															{
																File_Path_03[Counter_17]=Creat_File_Path[Counter_15][Counter_17];
															}
															if(strcmp(File_Path_02,File_Path_03)==0 && (Creat_File_Path[Counter_15][Counter_17]==0 || Creat_File_Path[Counter_15][Counter_17]=='\\' || Creat_File_Path[Counter_15][Counter_17]=='/'))
															{
																for(Counter_17=0;Counter_17<50;Counter_17++)
																{
																	Creat_File_Path[Counter_15][Counter_17]=0;
																	Creat_File_Path[Counter_15][Counter_17]=Creat_File_Path[Counter_15+1][Counter_17];
																	Creat_File_Path[Counter_15+1][Counter_17]=0;
																}
																memset(File_Path_03,0,sizeof(File_Path_03));
																goto Node_11;
															}
															memset(File_Path_03,0,sizeof(File_Path_03));
														}
														else
														{
															if(Counter_14<15)
															{
																Re_Code_03=Integrate_Arrays(Creat_File_Path,Counter_14,Counter_15);
															}
															else
															{
																Re_Code_03=Integrate_Arrays(Creat_File_Path,Counter_14-1,Counter_15);
																for(Counter_17=0;Counter_17<50;Counter_17++)
																{
																	Creat_File_Path[14][Counter_17]=0;
																}
															}
															if(Re_Code_03==0)
															{
																goto Node_11;
															}
														}
													}
													
													Time_Monitor_02--;
													Return_Code_02=0;
													break;
												
												case 1 || -1 :
													printf("[\033[31m-\033[0m] rm : 请求无法完成，访问被拒绝。\n");
													Return_Code_02=14;
													break;
												
												case 2 :
													printf("[\033[31m-\033[0m] rm : 请求无法完成，数据结构类型未知。此事件将被报告。\n");
													Return_Code_02=16;
													break;
												
												default:
													printf("[\033[31m?\033[0m] rm : 未知错误，此事件将被报告。\n");
													Return_Code_02=17;
													break;
											}
											break;
										
										case 0 :
											Tmp_Flag_12=remove(Tmp_Flag_11);
											
											if(Tmp_Flag_12==0)
											{
												printf("[\033[32m+\033[0m] 文件删除成功。\n");
												
												Node_12:
												for(Counter_15=0;Counter_15<Counter_14;Counter_15++)
												{
													if(Creat_File_Path[Counter_15][0]!=0)
													{
														for(Counter_17=0;Counter_17<50;Counter_17++)
														{
															File_Path_03[Counter_17]=Creat_File_Path[Counter_15][Counter_17];
														}
														if(strcmp(File_Path_02,File_Path_03)==0)
														{
															for(Counter_17=0;Counter_17<50;Counter_17++)
															{
																Creat_File_Path[Counter_15][Counter_17]=0;
																Creat_File_Path[Counter_15][Counter_17]=Creat_File_Path[Counter_15+1][Counter_17];
																Creat_File_Path[Counter_15+1][Counter_17]=0;
															}
															memset(File_Path_03,0,sizeof(File_Path_03));
															goto Node_12;
														}
														memset(File_Path_03,0,sizeof(File_Path_03));
													}
													else
													{
														if(Counter_14<15)
														{
															Re_Code_03=Integrate_Arrays(Creat_File_Path,Counter_14,Counter_15);
														}
														else
														{
															Re_Code_03=Integrate_Arrays(Creat_File_Path,Counter_14-1,Counter_15);
															for(Counter_17=0;Counter_17<50;Counter_17++)
															{
																Creat_File_Path[14][Counter_17]=0;
															}
														}
														if(Re_Code_03==0)
														{
															goto Node_12;
														}
													}
												}
												
												Time_Monitor_02--;
												Return_Code_02=0;
											}
											else
											{
												printf("[\033[31m-\033[0m] rm : 请求无法完成，访问被拒绝。\n");
												Return_Code_02=14;
											}
											
											break;
										
										default:
											printf("[\033[31m-\033[0m] rm : 请求无法完成，数据结构类型未知。此事件将被报告。\n");
											Return_Code_02=16;
											
											break;
									}
									Stat_Res=0;
								}
								else
								{
									printf("[\033[31m-\033[0m] rm : 请求无法完成，访问被拒绝。\n");
									Return_Code_02=14;
								}
							}
							else
							{
								printf("[\033[31m-\033[0m] rm : 请求无法完成，因为此命令不支持删除环境文件。\n");
								printf("    若的确需要更改环境文件，请使用 \033[1;4mwipe\033[0m 命令。\n");
								Return_Code_02=15;
							}
						}
						else
						{
							printf("[\033[31m-\033[0m] 系统找不到指定路径。\n");
							Return_Code_02=12;
						}
					}
					else
					{
						printf("[\033[31m-\033[0m] rm : 请求无法完成，访问被拒绝。\n");
						Return_Code_02=9;
					}
				}
				else
				{
					printf("[\033[31m-\033[0m] 系统找不到指定路径。\n");
					Return_Code_02=10;
				}
			}
		} 
	}
	Env_Path_04=getcwd(NULL,NULL);
	chdir(Env_Path_05);
	
	time(&Cur_Time);
	Now=gmtime(&Cur_Time);
	snprintf(Time_Handel,20,"%d-%d-%d %d:%d:%d",1900+Now->tm_year,1+Now->tm_mon,Now->tm_mday,8+Now->tm_hour,Now->tm_min,Now->tm_sec);
	
	FILE*Touch_Command1;
	Touch_Command1=fopen(Cmd_Log_Path,"a");
	fprintf(Touch_Command1,"[%s]\t# %s : %s \n",Time_Handel,getcwd(NULL,NULL),Command_01);
	fclose(Touch_Command1);
	
	switch(Return_Code_02)
	{
		case 0 :
			FILE*Touch_Result1;
			Touch_Result1=fopen(Res_Log_Path,"a");
			fprintf(Touch_Result1,"[%s]\t# %s :(rm) %s \n",Time_Handel,Env_Path_04,Tmp_Flag_11);
			fclose(Touch_Result1);
			break;
		
		case 15 :
			FILE*Touch_Result2;
			Touch_Result2=fopen(Res_Log_Path,"a");
			fprintf(Touch_Result2,"[%s]\t# %s :(rm) 警告：尝试删除环境文件。返回值：15。\n",Time_Handel,getcwd(NULL,NULL));
			fclose(Touch_Result2);
			break;
		
		case 16 :
			FILE*Touch_Result3;
			Touch_Result3=fopen(Res_Log_Path,"a");
			fprintf(Touch_Result3,"[%s]\t# %s :(rm) 警告：尝试删除未知类型的数据结构。返回值：16。\n",Time_Handel,getcwd(NULL,NULL));
			fclose(Touch_Result3);
			break;
		
		case 17 :
			FILE*Touch_Result4;
			Touch_Result4=fopen(Res_Log_Path,"a");
			fprintf(Touch_Result4,"[%s]\t# %s :(rm) 警告：出现未知错误。返回值：17。\n",Time_Handel,getcwd(NULL,NULL));
			fclose(Touch_Result4);
			break;
		
		default:
			FILE*Touch_Result5;
			Touch_Result5=fopen(Res_Log_Path,"a");
			fprintf(Touch_Result5,"[%s]\t# %s :(rm) 文件删除失败。返回值：%d。\n",Time_Handel,getcwd(NULL,NULL),Return_Code_02);
			fclose(Touch_Result5);
			break;
	}
	
	memset(File_Path_02,0,sizeof(File_Path_02));
	memset(Tmp_Flag_10,0,sizeof(Tmp_Flag_10));
	memset(Tmp_Flag_11,0,sizeof(Tmp_Flag_11));
	memset(Command_01,0,sizeof(Command_01));
	memset(Path_Flag_04,0,sizeof(Path_Flag_04));
	memset(Env_Path_06,0,sizeof(Env_Path_06));
	
	return Return_Code_02;
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
			chdir("C:\\Users\\kali\\Shell\\home\\kali");
			for(Counter_01=0;Counter_01<15 && Creat_File_Path[Counter_01][0]!=0;Counter_01++);
			for(;Counter_01>0;Counter_01--)
			{
				char Exit_Command_01[100]="powershell -c \"del \'";
				for(Counter_03=0;Counter_03<50;Counter_03++)
				{
					Exit_Command_02[Counter_03]=Creat_File_Path[Counter_01-1][Counter_03];
				}
				strcat(Exit_Command_01,Exit_Command_02);
				strcat(Exit_Command_01,"\' 2>\'C:\\Users\\Public\\null\'\"");
				system(Exit_Command_01);
				memset(Exit_Command_01,0,sizeof(Exit_Command_01));
			}
			Counter_01=0;
			Counter_03=0;
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
	char Built_In_Function_061[7]="whoami";
	char Built_In_Function_071[10]="hostname";
	char Built_In_Function_081[3]="id";
	char Built_In_Function_091[8]="touch";
	char Built_In_Function_101[8]="mkdir",Built_In_Function_102[8]="md";
	char Built_In_Function_111[3]="rm";
	
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
	
	// whoami 命令 
	if(Target(Ac_Command,Built_In_Function_061)==1)
	{
		printf("Kali\n");

		FILE*Command16;
		Command16=fopen(Cmd_Log_Path,"a");
		fprintf(Command16,"[%s]\t# %s :(whoami) %s \n",Time_Handel,getcwd(NULL,NULL),Ac_Command);
		fclose(Command16);

		FILE*Result16;
		Result16=fopen(Res_Log_Path,"a");
		fprintf(Result16,"[%s]\t# %s :(whoami)\n",Time_Handel,getcwd(NULL,NULL));
		fclose(Result16);

		goto Node_01;
	}
	
	// hostname 命令
	if(Target(Ac_Command,Built_In_Function_071)==1)
	{
		printf("%s\n",Computer_Name);

		FILE*Command17;
		Command17=fopen(Cmd_Log_Path,"a");
		fprintf(Command17,"[%s]\t# %s :(hostname) %s \n",Time_Handel,getcwd(NULL,NULL),Ac_Command);
		fclose(Command17);

		FILE*Result17;
		Result17=fopen(Res_Log_Path,"a");
		fprintf(Result17,"[%s]\t# %s :(hostname)\n",Time_Handel,getcwd(NULL,NULL));
		fclose(Result17);

		goto Node_01;
	}
	
	// id 命令
	if(Target(Ac_Command,Built_In_Function_081)==1)
	{
		printf("uid=1001(kali) gid=1001(kali) groups=1001(kali),100(users)\n");
		
		FILE*Command18;
		Command18=fopen(Cmd_Log_Path,"a");
		fprintf(Command18,"[%s]\t# %s :(id) %s \n",Time_Handel,getcwd(NULL,NULL),Ac_Command);
		fclose(Command18);

		FILE*Result18;
		Result18=fopen(Res_Log_Path,"a");
		fprintf(Result18,"[%s]\t# %s :(id)\n",Time_Handel,getcwd(NULL,NULL));
		fclose(Result18);

		goto Node_01;
	}
	
	/*
	以下命令会与磁盘交互，须限制命令使用次数。
	 默认可创建文件夹数目：5 个。
	 默认可创建文件数目：8 个。
	*/
	
	// touch 命令
	if(Target(Ac_Command,Built_In_Function_091)==1)
	{
		if(Time_Monitor_01<8)
		{
			Touch_File(Ac_Command,Built_In_Function_091,Isolate_Path,Creat_File_Path);
			Time_Monitor_01++;
			
			goto Node_01;
		}
		else
		{
			printf("[\033[31m-\033[0m] %s : 请求无法完成，因为可创建文件数量已达上线（文件*8）。\n",Built_In_Function_091);
			
			goto Node_01;
		}
	}
	
	// mkdir 命令
	if(Target(Ac_Command,Built_In_Function_101)==1)
	{
		if(Time_Monitor_02<5)
		{
			Make_Directories(Ac_Command,Built_In_Function_101,Isolate_Path,Creat_File_Path);
			Time_Monitor_02++;
			
			goto Node_01;
		}
		else
		{
			printf("[\033[31m-\033[0m] %s : 请求无法完成，因为可创建文件数量已达上线（文件夹*5）。\n",Built_In_Function_101);
			
			goto Node_01;
		}
	}
	if(Target(Ac_Command,Built_In_Function_102)==1)
	{
		if(Time_Monitor_02<5)
		{
			Make_Directories(Ac_Command,Built_In_Function_102,Isolate_Path,Creat_File_Path);
			Time_Monitor_02++;
			
			goto Node_01;
		}
		else
		{
			printf("[\033[31m-\033[0m] %s : 请求无法完成，因为可创建文件数量已达上线（文件夹*5）。\n",Built_In_Function_102);
			
			goto Node_01;
		}
	}
	
	// rm 命令
	if(Target(Ac_Command,Built_In_Function_111)==1)
	{
		if(Time_Monitor_01>0 || Time_Monitor_02>0)
		{
			Remove(Ac_Command,Built_In_Function_111,Isolate_Path,Creat_File_Path,Time_Monitor_01,Time_Monitor_02);
			
			goto Node_01;
		}
		else
		{
			printf("[\033[31m-\033[0m] rm : 请求无法完成，因为此命令不支持删除环境文件。\n");
			printf("    若的确需要更改环境文件，请使用 \033[1;4mwipe\033[0m 命令。\n");
			
			goto Node_01;
		}
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

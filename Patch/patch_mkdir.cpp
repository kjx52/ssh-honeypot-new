
/*
 Bacsh 补丁源代码 1.0 
 作者： Jessarin000
 日期： 2023-12-18 
*/

/*
 本程序为原 Bacsh 终端命令补丁。
 适配版本： Bacsh 6.3 及以上。 
 本补丁添加的命令为：“mkdir”。 
 请按照提示将源码添加至 Bacsh.cpp 中的指定位置，编译并使用。 
*/

//若未包含，则将下面的头文件添加至源码头部。
#include <dirent.h>
#include <fcntl.h>
#include <sys/stat.h>

//将下列的函数添加至主函数前面。 
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

//将下列语句添加至 作用模块 -> 内置函数组 
char Built_In_Function_101[8]="mkdir",Built_In_Function_102[8]="md";

//将下列语句添加至 作用模块。

	/*
	以下命令会与磁盘交互，须限制命令使用次数。
	 默认可创建文件夹数目：5 个。
	*/

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



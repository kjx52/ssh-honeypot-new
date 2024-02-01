
/*
 Bacsh 补丁源代码 1.0 
 作者： Jessarin000
 日期： 2023-12-18 
*/

/*
 本程序为原 Bacsh 终端命令补丁。
 适配版本： Bacsh 6.3 及以上。 
 本补丁添加的命令为：“touch”。 
 请按照提示将源码添加至 Bacsh.cpp 中的指定位置，编译并使用。 
*/

//若未包含，则将下面的头文件添加至源码头部。
#include <dirent.h>
#include <fcntl.h>
#include <sys/stat.h>

//将下列的函数添加至主函数前面。 
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

//将下列语句添加至 作用模块 -> 内置函数组
char Built_In_Function_091[8]="touch";

//将下列语句添加至 作用模块。

	/*
	以下命令会与磁盘交互，须限制命令使用次数。
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



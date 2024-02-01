
/*
 Bacsh 补丁源代码 1.0 
 作者： Jessarin000
 日期： 2023-12-18 
*/

/*
 本程序为原 Bacsh 终端命令补丁。
 适配版本： Bacsh 6.3 及以上。 
 本补丁添加的命令为：“rm”。 
 请按照提示将源码添加至 Bacsh.cpp 中的指定位置，编译并使用。 
*/

//若未包含，则将下面的头文件添加至源码头部。
#include <dirent.h>
#include <fcntl.h>
#include <sys/stat.h>

//将下列的函数添加至主函数前面。 
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

//将下列语句添加至 作用模块 -> 内置函数组 
char Built_In_Function_111[3]="rm";

//使用下面的函数更换原 交互及动态字符过滤模块 -> 退出函数 
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
//将下列语句添加至 作用模块。

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



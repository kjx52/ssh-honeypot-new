
/*
 Bacsh ����Դ���� 1.0 
 ���ߣ� Jessarin000
 ���ڣ� 2023-12-18 
*/

/*
 ������Ϊԭ Bacsh �ն��������
 ����汾�� Bacsh 6.3 �����ϡ� 
 ��������ӵ�����Ϊ����touch���� 
 �밴����ʾ��Դ������� Bacsh.cpp �е�ָ��λ�ã����벢ʹ�á� 
*/

//��δ�������������ͷ�ļ������Դ��ͷ����
#include <dirent.h>
#include <fcntl.h>
#include <sys/stat.h>

//�����еĺ��������������ǰ�档 
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
		printf("[\033[31m-\033[0m] touch �� ��Ч������\n");
		printf("[?] ��ʹ�� touch -h ��ʾ������\n");
		Tmp_Flag_01=2;
		Return_Code_01=13;
	}
	if(memcmp(Path_Flag_02,"-h",2)==0 && Tmp_Flag_01!=2)
	{
		printf("[\033[32m+\033[0m] �÷���touch [�������]... �ļ���...\n");
		printf("���������ڽ�ָ���ļ��ķ��ʺ��޸�ʱ�����Ϊ��ǰʱ�䡣\n\n");
		printf("��ָ���ļ������ڣ�����½�һ��ͬ�ļ����Ŀ��ļ���\n"); 
		printf("  ������\n");
		printf("\t-h\t��ʾ�˰������˳���\n");
		printf("\t-v\t��ʾ�汾��Ϣ���˳���\n\n");
		printf("���κ������������ϵ���� <\033[1;4mkjx52@outlook.com\033[0m>��\n");
		
		Tmp_Flag_01=2;
		Return_Code_01=0;
	}
	if(memcmp(Path_Flag_02,"-v",2)==0 && Tmp_Flag_01!=2)
	{
		printf("touch 1.02\n");
		printf("��Ȩ���� (C) 2023 Indie developers, Inc.\n\n");
		printf("Written by Jessarin\n");
		Tmp_Flag_01=2;
		Return_Code_01=0;
	}
	if(Target(Path_Flag_02,Error_C)==1 && Tmp_Flag_01!=2)
	{
		printf("[\033[31m-\033[0m] touch �� ��Ч������\n");
		printf("[?] ��ʹ�� touch -h ��ʾ������\n");
		Tmp_Flag_01=2;
		Return_Code_01=13;
	}
	if(strlen(Path_Flag_02)==1 && Path_Flag_02[0]=='/' && Tmp_Flag_01!=2)
	{
		printf("[\033[31m-\033[0m] ��Ч���롣\n");
		Tmp_Flag_01=2;
		Return_Code_01=4;
	}
	if(Tmp_Flag_02==2 && Tmp_Flag_01!=2)
	{
		printf("[\033[31m-\033[0m] ��Ч���롣\n");
		Tmp_Flag_01=2;
		Return_Code_01=3;
	}
	if(Path_Flag_02[0]==':' && Tmp_Flag_01!=2)
	{
		printf("[\033[31m-\033[0m] ��Ч���롣\n");
		Tmp_Flag_01=2;
		Return_Code_01=3;
	}
	if(Tmp_Flag_01!=2)
	{
		if(Tmp_Flag_04==3 || Path_Flag_02[strlen(Path_Flag_02)-1]=='/')
		{
		    printf("[\033[31m-\033[0m]\033[31m touch : �����޷���ɣ�\"%s\" ��һ��Ŀ¼��\n\033[0m",Path_Flag_02);
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
				printf("[\033[31m-\033[0m]\033[31m touch : �����޷���ɣ���Ϊ�ļ����в��ܰ���������һ�ַ���\n\t  ��/�� ��\\�� ��:�� ��*�� ��\?�� ��\"�� ��<�� ��>�� ��|��\n\033[0m");
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
				printf("[\033[31m-\033[0m] ��Ч���롣\n");
				Return_Code_01=5;
			}
			else
			{
				if(Path_Flag_02[0]!='c' && Path_Flag_02[0]!='C')
				{
					printf("[\033[31m-\033[0m]\033[31m ϵͳ�Ҳ���ָ��·����\n\033[0m");
					Return_Code_01=6;
				}
				else
				{
					if(strlen(Path_Flag_02)==2)
					{
						printf("[\033[31m-\033[0m] ��Ч���롣\n");
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
									printf("[\033[32m+\033[0m] �ļ������ɹ���%s ��\n",Tmp_Flag_09);
									Return_Code_01=0;
								}
								else
								{
									Return_Code_01=12;
								}
							}
							else
							{
								printf("[\033[31m-\033[0m] �ܾ����ʡ�\n");
								Return_Code_01=7;
							}
						}
						else
						{
							printf("[\033[31m-\033[0m] ϵͳ�Ҳ���ָ��·����\n");
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
							printf("[\033[32m+\033[0m] �ļ������ɹ���%s ��\n",Tmp_Flag_09);
							Return_Code_01=0;
						}
						else
						{
							Return_Code_01=12;
						}
					}
					else
					{
						printf("[\033[31m-\033[0m] �ܾ����ʡ�\n");
						Return_Code_01=7;
					}
				}
				else
				{
					printf("[\033[31m-\033[0m] ϵͳ�Ҳ���ָ��·����\n");
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
							printf("[\033[32m+\033[0m] �ļ������ɹ���%s ��\n",Tmp_Flag_09);
							Return_Code_01=0;
						}
						else
						{
							Return_Code_01=12;
						}
					}
					else
					{
						printf("[\033[31m-\033[0m] �ܾ����ʡ�\n");
						Return_Code_01=9;
					}
				}
				else
				{
					printf("[\033[31m-\033[0m] ϵͳ�Ҳ���ָ��·����\n");
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
			fprintf(Touch_Result2,"[%s]\t# %s :(touch) �ļ����¡�����ֵ��12\n",Time_Handel,getcwd(NULL,NULL));
			fclose(Touch_Result2);
		}
		else
		{
			FILE*Touch_Result2;
			Touch_Result2=fopen(Res_Log_Path,"a");
			fprintf(Touch_Result2,"[%s]\t# %s :(touch) �ļ�����ʧ�ܡ�����ֵ��%d\n",Time_Handel,getcwd(NULL,NULL),Return_Code_01);
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

//�������������� ����ģ�� -> ���ú�����
char Built_In_Function_091[8]="touch";

//�������������� ����ģ�顣

	/*
	�������������̽���������������ʹ�ô�����
	 Ĭ�Ͽɴ����ļ���Ŀ��8 ����
	*/

	// touch ����
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
			printf("[\033[31m-\033[0m] %s : �����޷���ɣ���Ϊ�ɴ����ļ������Ѵ����ߣ��ļ�*8����\n",Built_In_Function_091);
			
			goto Node_01;
		}
	}



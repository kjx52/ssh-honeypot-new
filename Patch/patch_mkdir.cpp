
/*
 Bacsh ����Դ���� 1.0 
 ���ߣ� Jessarin000
 ���ڣ� 2023-12-18 
*/

/*
 ������Ϊԭ Bacsh �ն��������
 ����汾�� Bacsh 6.3 �����ϡ� 
 ��������ӵ�����Ϊ����mkdir���� 
 �밴����ʾ��Դ������� Bacsh.cpp �е�ָ��λ�ã����벢ʹ�á� 
*/

//��δ�������������ͷ�ļ������Դ��ͷ����
#include <dirent.h>
#include <fcntl.h>
#include <sys/stat.h>

//�����еĺ��������������ǰ�档 
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
		printf("[\033[31m-\033[0m] mkdir �� ��Ч������\n");
		printf("[?] ��ʹ�� mkdir -h ��ʾ������\n");
		Tmp_Flag_05=2;
		Return_Code_02=15;
	}
	if(memcmp(Path_Flag_03,"-h",2)==0 && Tmp_Flag_05!=2)
	{
		printf("[\033[32m+\033[0m] �÷���mkdir [�������]... Ŀ¼��...\n");
		printf("������������Ŀ���ļ��в����ڵ�����´����ļ��С�\n");
		printf("  ������\n");
		printf("\t-h\t��ʾ�˰������˳���\n");
		printf("\t-v\t��ʾ�汾��Ϣ���˳���\n\n");
		printf("���κ������������ϵ���� <\033[1;4mkjx52@outlook.com\033[0m>��\n");
		
		Tmp_Flag_05=2;
		Return_Code_02=0;
	}
	if(memcmp(Path_Flag_03,"-v",2)==0 && Tmp_Flag_05!=2)
	{
		printf("mkdir 1.04\n");
		printf("��Ȩ���� (C) 2023 Indie developers, Inc.\n\n");
		printf("Written by Jessarin\n");
		Tmp_Flag_05=2;
		Return_Code_02=0;
	}
	if(Target(Path_Flag_03,Error_C) && Tmp_Flag_05!=2)
	{
		printf("[\033[31m-\033[0m] mkdir �� ��Ч������\n");
		printf("[?] ��ʹ�� mkdir -h ��ʾ������\n");
		Tmp_Flag_05=2;
		Return_Code_02=15;
	}
	if(strlen(Path_Flag_03)==1 && Path_Flag_03[0]=='/' && Tmp_Flag_05!=2)
	{
		printf("[\033[31m-\033[0m] ��Ч���롣\n");
		Tmp_Flag_05=2;
		Return_Code_02=4;
	}
	if(Tmp_Flag_06==2 && Tmp_Flag_05!=2)
	{
		printf("[\033[31m-\033[0m] ��Ч���롣\n");
		Tmp_Flag_05=2;
		Return_Code_02=3;
	}
	if(Path_Flag_03[0]==':' && Tmp_Flag_05!=2)
	{
		printf("[\033[31m-\033[0m] ��Ч���롣\n");
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
				printf("[\033[31m-\033[0m]\033[31m mkdir : �����޷���ɣ���ΪĿ¼���в��ܰ���������һ�ַ���\n\t  ��/�� ��\\�� ��:�� ��*�� ��\?�� ��\"�� ��<�� ��>�� ��|��\n\033[0m");
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
				printf("[\033[31m-\033[0m] ��Ч���롣\n");
				Return_Code_02=5;
			}
			else
			{
				if(Path_Flag_03[0]!='c' && Path_Flag_03[0]!='C')
				{
					printf("[\033[31m-\033[0m]\033[31m ϵͳ�Ҳ���ָ��·����\n\033[0m");
					Return_Code_02=6;
				}
				else
				{
					if(strlen(Path_Flag_03)==2)
					{
						printf("[\033[31m-\033[0m] ��Ч���롣\n");
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
									printf("[\033[32m+\033[0m] Ŀ¼�����ɹ���%s ��\n",Tmp_Flag_11);
									Return_Code_02=0;
								}
								else
								{
									printf("[\033[31m-\033[0m] mkdir : �����޷���ɣ���Ϊ�ļ��С�%s���Ѵ��ڡ�\n",Tmp_Flag_11);
									Return_Code_02=14;
								}
							}
							else
							{
								printf("[\033[31m-\033[0m] �ܾ����ʡ�\n");
								Return_Code_02=7;
							}
						}
						else
						{
							printf("[\033[31m-\033[0m] ϵͳ�Ҳ���ָ��·����\n");
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
							printf("[\033[32m+\033[0m] Ŀ¼�����ɹ���%s ��\n",Tmp_Flag_11);
							Return_Code_02=0;
						}
						else
						{
							printf("[\033[31m-\033[0m] mkdir : �����޷���ɣ���Ϊ�ļ��С�%s���Ѵ��ڡ�\n",Tmp_Flag_11);
							Return_Code_02=14;
						}
					}
					else
					{
						printf("[\033[31m-\033[0m] �ܾ����ʡ�\n");
						Return_Code_02=7;
					}
				}
				else
				{
					printf("[\033[31m-\033[0m] ϵͳ�Ҳ���ָ��·����\n");
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
							printf("[\033[32m+\033[0m] Ŀ¼�����ɹ���%s ��\n",Tmp_Flag_11);
							Return_Code_02=0;
						}
						else
						{
							printf("[\033[31m-\033[0m] mkdir : �����޷���ɣ���Ϊ�ļ��С�%s���Ѵ��ڡ�\n",Tmp_Flag_11);
							Return_Code_02=14;
						}
					}
					else
					{
						printf("[\033[31m-\033[0m] �ܾ����ʡ�\n");
						Return_Code_02=9;
					}
				}
				else
				{
					printf("[\033[31m-\033[0m] ϵͳ�Ҳ���ָ��·����\n");
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
			fprintf(Touch_Result2,"[%s]\t# %s :(mkdir) Ŀ¼�Ѵ��ڡ�����ֵ��14\n",Time_Handel,getcwd(NULL,NULL));
			fclose(Touch_Result2);
		}
		else
		{
			FILE*Touch_Result2;
			Touch_Result2=fopen(Res_Log_Path,"a");
			fprintf(Touch_Result2,"[%s]\t# %s :(mkdir) Ŀ¼����ʧ�ܡ�����ֵ��%d\n",Time_Handel,getcwd(NULL,NULL),Return_Code_02);
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

//�������������� ����ģ�� -> ���ú����� 
char Built_In_Function_101[8]="mkdir",Built_In_Function_102[8]="md";

//�������������� ����ģ�顣

	/*
	�������������̽���������������ʹ�ô�����
	 Ĭ�Ͽɴ����ļ�����Ŀ��5 ����
	*/

	// mkdir ����
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
			printf("[\033[31m-\033[0m] %s : �����޷���ɣ���Ϊ�ɴ����ļ������Ѵ����ߣ��ļ���*5����\n",Built_In_Function_101);
			
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
			printf("[\033[31m-\033[0m] %s : �����޷���ɣ���Ϊ�ɴ����ļ������Ѵ����ߣ��ļ���*5����\n",Built_In_Function_102);
			
			goto Node_01;
		}
	}



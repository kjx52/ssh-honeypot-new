
/*
 Bacsh ����Դ���� 1.0 
 ���ߣ� Jessarin000
 ���ڣ� 2023-12-18 
*/

/*
 ������Ϊԭ Bacsh �ն��������
 ����汾�� Bacsh 6.3 �����ϡ� 
 ��������ӵ�����Ϊ����whoami���� 
 �밴����ʾ��Դ������� Bacsh.cpp �е�ָ��λ�ã����벢ʹ�á� 
*/

//�������������� ����ģ�� -> ���ú����� 
char Built_In_Function_061[7]="whoami";

//�������������� ����ģ�顣

	//whoami 
	if(Target(Ac_Command,Built_In_Function_061)==1)
	{
		printf("Kali2023\n");

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



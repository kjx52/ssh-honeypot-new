
/*
 Bacsh ����Դ���� 1.0 
 ���ߣ� Jessarin000
 ���ڣ� 2023-12-18 
*/

/*
 ������Ϊԭ Bacsh �ն��������
 ����汾�� Bacsh 6.3 �����ϡ� 
 ��������ӵ�����Ϊ����hostname���� 
 �밴����ʾ��Դ������� Bacsh.cpp �е�ָ��λ�ã����벢ʹ�á� 
*/

//�������������� ����ģ�� -> ���ú����� 
char Built_In_Function_071[10]="hostname";

//�������������� ����ģ�顣

	// hostname ����
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



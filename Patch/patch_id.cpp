
/*
 Bacsh ����Դ���� 1.0 
 ���ߣ� Jessarin000
 ���ڣ� 2023-12-18 
*/

/*
 ������Ϊԭ Bacsh �ն��������
 ����汾�� Bacsh 6.3 �����ϡ� 
 ��������ӵ�����Ϊ����id���� 
 �밴����ʾ��Դ������� Bacsh.cpp �е�ָ��λ�ã����벢ʹ�á� 
*/

//�������������� ����ģ�� -> ���ú����� 
char Built_In_Function_081[3]="id";

//�������������� ����ģ�顣

	// id ����
	if(Target(Ac_Command,Built_In_Function_081)==1)
	{
		printf("uid=1001(kali2023) gid=1001(kali2023) groups=1001(kali2023),100(users)\n");
		
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



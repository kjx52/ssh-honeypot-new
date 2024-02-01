
/*
 Bacsh 补丁源代码 1.0 
 作者： Jessarin000
 日期： 2023-12-18 
*/

/*
 本程序为原 Bacsh 终端命令补丁。
 适配版本： Bacsh 6.3 及以上。 
 本补丁添加的命令为：“id”。 
 请按照提示将源码添加至 Bacsh.cpp 中的指定位置，编译并使用。 
*/

//将下列语句添加至 作用模块 -> 内置函数组 
char Built_In_Function_081[3]="id";

//将下列语句添加至 作用模块。

	// id 命令
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



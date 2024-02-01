
/*
 Bacsh 补丁源代码 1.0 
 作者： Jessarin000
 日期： 2023-12-18 
*/

/*
 本程序为原 Bacsh 终端命令补丁。
 适配版本： Bacsh 6.3 及以上。 
 本补丁添加的命令为：“hostname”。 
 请按照提示将源码添加至 Bacsh.cpp 中的指定位置，编译并使用。 
*/

//将下列语句添加至 作用模块 -> 内置函数组 
char Built_In_Function_071[10]="hostname";

//将下列语句添加至 作用模块。

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



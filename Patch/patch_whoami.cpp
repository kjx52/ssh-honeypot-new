
/*
 Bacsh 补丁源代码 1.0 
 作者： Jessarin000
 日期： 2023-12-18 
*/

/*
 本程序为原 Bacsh 终端命令补丁。
 适配版本： Bacsh 6.3 及以上。 
 本补丁添加的命令为：“whoami”。 
 请按照提示将源码添加至 Bacsh.cpp 中的指定位置，编译并使用。 
*/

//将下列语句添加至 作用模块 -> 内置函数组 
char Built_In_Function_061[7]="whoami";

//将下列语句添加至 作用模块。

	//whoami 
	if(Target(Ac_Command,Built_In_Function_061)==1)
	{
		printf("Kali\n");

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



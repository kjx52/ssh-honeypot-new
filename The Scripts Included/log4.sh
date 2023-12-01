#!/bin/bash
# -*- coding: utf-8 -*-
#/*SSH 蜜罐集成启动脚本*/
# 作者 ： Jessarin000
# 日期 ： 2023-12-02
# 版本 ： 4.2
#
##注意：·本程序需要 zsh Shell。
##     ·本脚本需配合 shsh 伪终端脚本 0.7或以上版本使用。
##     ·本脚本需配合 netmonitor 网络检测脚本 monitor.sh 使用。
##     ·本脚本需配合 testEmail.py 邮件发送脚本使用。
##     ·本脚本需在联网状态下使用，若强制受限，请移除 1236行～1238行 Python启动脚本部分。
##     ·若出现权限问题，请使用 sudo 提权运行或使用配套的启动器。
##     ·遇到任何问题或错误请联系作者。
#
#######################################################################
##                %警告：可能对系统产生非预期的影响！%                     ##
##              %建议在虚拟环境（VM或Docker）下运行！%                    ##
##                                                                   ##
##    %Warning: There may be an unexpected impact on the system!%    ##
##      %It is recommended to run under a virtual environment %      ##
##                     %!(VM or Docker)!%                            ##
#######################################################################
#                                                          ______________________________________________________________
#                         .;lxO0KXXXK0Oxl:.               |    __   __  _  _   _  _  __  _  _ ____ _  _  __   __  ____   |   +
#                     ,o0WMMMMMMMMMMMMMMMMMMKd,.....      |   |__' |__' |__|   |__| |  | |. | |__  | .' |__| |  |  ||    +====
#                  'xNMMMMMMMMMMMMMMMMMMMMMMMMMWx,........|   .__| .__| |  |   |  | |__| | '| |___  |   |    |__|  ||    +====
#                :KMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMK:................................_____________________________________|   +
#              .KMMMMMMMMMMMMMMMWNNNWMMMMMMMMMMMMMMMX,................    ___----------___                                   |
#             lWMMMMMMMMMMMXd:..     ..;dKMMMMMMMMMMMMo                II==II=I=IIII=I=II==II      <Jessarin 于2023.09.18作>
#            xMMMMMMMMMMWd.               .oNMMMMMMMMMMk           .NL=M::M--..........--M::M=JN.
#           oMMMMMMMMMMx.        ____        dMMMMMMMMMMx          VS '   .T'   'ii'   'T.   ' SV
#          .WMMMMMMMMM:         :   .'        :MMMMMMMMMM,   __     VT. cT  cT.ccTTcc.Tc  Tc .TV     __
#          xMMMMMMMMMo         :  .'__         lMMMMMMMMMO (:++:).  ()'T'..  .A.iwwi.A.  ..'T'()  .(:++:).
#          NMMMMMMMMW         '.__   .'  ,cccccoMMMMMMMMMWlccccc; )()[[[ [[ [[ [ {} ] ]] ]] ]]]()(:'    ':)
#          MMMMMMMMMX            : .'     ;KMMMMMMMMMMMMMMMMMMX:  .)[[[ [[ [[ [ o{}o ] ]] ]] ]]](.        :)
#          NMMMMMMMMW.          :.'         ;KMMMMMMMMMMMMMMX:   ()[[[ [[[ [[ [ i{}i ] ]] ]]] ]]]()      .:)
#          xMMMMMMMMMd         .'             ,0MMMMMMMMMMK;..............[[  [ o{}o ]  ]] ]]] ]]](.___.:)'
#          .WMMMMMMMMMc                         'OMMMMMM0,.............................. ]]] ]]] ]]'():'
#           lMMMMMMMMMMk.                         .kMMO'       ()[ [[  [[[  [    {}    ]  ]]]  ]] ]()
#            dMMMMMMMMMMWd'                         .. ________()[_[[__[[[             ]  ]]]  ]] ]() 
#             cWMMMMMMMMMMMNxc'.                ##########   ##########   ###    ###.......... ]] ]() 
#              .0MMMMMMMMMMMMMMMMWc            #+#    #+#   #+#    #+#   #+#    #+#....................
#                ;0MMMMMMMMMMMMMMMo.          +:+          +:+          +:+    +:+.....     ]  ]] ]()
#                  .dNMMMMMMMMMMMMo          +#++:++#+    +#++:++#+    +#++::++#+................................
#                     'oOWMMMMMMMMo                +:+          +:+   +:+    +:+         ]]] 	] ()    
#                         .,cdkO0K;        :+:    :+:   :+:    :+:   :+:    :+:  {}.  ]]]  ]]  _='
#                                          :::::::+:    :::::::+:    :::   :+:...... _____.:=-'
#      ==================================================================.::'................=================================
#                                                ====================.::'........=============
#                                                        ========.::'......================================
####




printf "
                                                          \033[1;35m______________________________________________________________\033[0m
                         \033[1;31m.;lxO0KXXXK0Oxl:.\033[0m               \033[1;35m|    __   __  _  _   _  _  __  _  _ ____ _  _  __   __  ____   |   +\033[0m
                     \033[1;31m,o0WMMMMMMMMMMMMMMMMMMKd,.....\033[0m      \033[1;35m|   |__' |__' |__|   |__| |  | |. | |__  | .' |__| |  |  ||    +====\033[0m
                  \033[1;31m'xNMMMMMMMMMMMMMMMMMMMMMMMMMWx,........\033[0m\033[1;35m|   .__| .__| |  |   |  | |__| | '| |___  |   |    |__|  ||    +====\033[0m
                \033[1;31m:KMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMK:................................\033[0m\033[1;35m_____________________________________|   +\033[0m
              \033[1;31m.KMMMMMMMMMMMMMMMWNNNWMMMMMMMMMMMMMMMX,................\033[0m    \033[1;33m___----------___\033[0m                                   \033[1;35m|\033[0m
             \033[1;31mlWMMMMMMMMMMMXd:..     ..;dKMMMMMMMMMMMMo\033[0m                \033[1;33mII==II=I=IIII=I=II==II\033[0m      \033[1;31m<Jessarin 于2023.09.18作>\033[0m
            \033[1;31mxMMMMMMMMMMWd.               .oNMMMMMMMMMMk\033[0m           \033[1;33m.NL=M::M--..........--M::M=JN.\033[0m
           \033[1;31moMMMMMMMMMMx.        \033[1;5;34m____\033[0m        \033[1;31mdMMMMMMMMMMx\033[0m          \033[1;33mVS '   .T'   'ii'   'T.   ' SV\033[0m
          \033[1;31m.WMMMMMMMMM:         \033[1;5;34m:   .'\033[0m        \033[1;31m:MMMMMMMMMM,\033[0m   \033[1;33m__     VT. cT  cT.ccTTcc.Tc  Tc .TV     __\033[0m
          \033[1;31mxMMMMMMMMMo         \033[1;5;34m:  .'__\033[0m         \033[1;31mlMMMMMMMMMO\033[0m \033[1;33m(:++:).  ()'T'..  .A.iwwi.A.  ..'T'()  .(:++:).\033[0m
          \033[1;31mNMMMMMMMMW         \033[1;5;34m'.__   .'\033[0m  \033[1;31m,cccccoMMMMMMMMMWlccccc;\033[0m \033[1;33m)()[[[ [[ [[ [ {} ] ]] ]] ]]]()(:'    ':)\033[0m
          \033[1;31mMMMMMMMMMX            \033[1;5;34m: .'\033[0m     \033[1;31m;KMMMMMMMMMMMMMMMMMMX:\033[0m  \033[1;33m.)[[[ [[ [[ [ o{}o ] ]] ]] ]]](.        :)\033[0m
          \033[1;31mNMMMMMMMMW.          \033[1;5;34m:.'\033[0m         \033[1;31m;KMMMMMMMMMMMMMMX:\033[0m   \033[1;33m()[[[ [[[ [[ [ i{}i ] ]] ]]] ]]]()      .:)\033[0m
          \033[1;31mxMMMMMMMMMd         \033[1;5;34m.'\033[0m             \033[1;31m,0MMMMMMMMMMK;..............\033[0m\033[1;33m[[  [ o{}o ]  ]] ]]] ]]](.___.:)'\033[0m
          \033[1;31m.WMMMMMMMMMc                         'OMMMMMM0,..............................\033[0m \033[1;33m]]] ]]] ]]'():'\033[0m
           \033[1;31mlMMMMMMMMMMk.                         .kMMO'\033[0m       \033[1;33m()[ [[  [[[  [    {}    ]  ]]]  ]] ]()\033[0m
            \033[1;31mdMMMMMMMMMMWd'                         ..\033[0m \033[1;33m________()[_[[__[[[             ]  ]]]  ]] ]() \033[0m
             \033[1;31mcWMMMMMMMMMMMNxc'.\033[0m                \033[1;32m##########   ##########   ###    ###..........\033[0m\033[1;33m ]] ]() \033[0m
              \033[1;31m.0MMMMMMMMMMMMMMMMWc\033[0m            \033[1;32m#+#    #+#   #+#    #+#   #+#    #+#....................\033[0m
                \033[1;31m;0MMMMMMMMMMMMMMMo.\033[0m          \033[1;32m+:+          +:+          +:+    +:+.....\033[0m\033[1;33m     ]  ]] ]()\033[0m
                  \033[1;31m.dNMMMMMMMMMMMMo\033[0m          \033[1;32m+#++:++#+    +#++:++#+    +#++::++#+................................\033[0m
                     \033[1;31m'oOWMMMMMMMMo\033[0m                \033[1;32m+:+          +:+   +:+    +:+\033[0m         \033[1;33m]]] 	] ()   \033[0m 
                         \033[1;31m.,cdkO0K;\033[0m        \033[1;32m:+:    :+:   :+:    :+:   :+:    :+:\033[0m  \033[1;33m{}.  ]]]  ]]  _='\033[0m
                                          \033[1;32m:::::::+:    :::::::+:    :::   :+:......\033[0m \033[1;33m_____.:=-'\033[0m
      \033[34m==================================================================\033[0m\033[1;32m.::'................\033[0m\033[34m=================================\033[0m
                                                \033[34m====================\033[0m\033[1;32m.::'........\033[0m\033[34m=============\033[0m
                                                        \033[34m========\033[0m\033[1;32m.::'......\033[0m\033[34m================================\033[0m
                                                        
\033[34m
/*SSH 蜜罐集成启动脚本*/
 作者 ： Jessarin000
 日期 ： 2023-12-02
 版本 ： 4.2\033[0m
 
  
    本脚本用于自动化SSH弱口令蜜罐流程。\033[31m在启动此脚本前请查看并配置脚本以适应您的系统。\033[0m
本脚本可以结合多种方式在攻击者进入蜜罐后动态监测其各种行为。

    \033[1;32m*本脚本将在未来版本中试着加入客户端攻击。\033[0m

    \033[1;35m有任何意见或建议请联系作者：<kjx52@outlook.com>\033[0m

\033[33m@注意：·本程序需要 zsh Shell。\033[0m
\033[33m@      ·本脚本需配合 shsh 伪终端脚本 0.7或以上版本使用。\033[0m
\033[33m@      ·本脚本需配合 testEmail.py 邮件发送脚本使用。\033[0m
\033[33m@      ·本脚本需在联网状态下使用，若强制受限，请移除 1236行～1238行 Python启动脚本部分。\033[0m
\033[33m@      ·若出现权限问题，请使用 sudo 提权运行或使用配套的启动器。\033[0m
\033[33m@      ·遇到任何问题或错误请联系作者。\033[0m\n\n";

if [ "$(systemd-detect-virt)" = "none" ];then
	echo -e "\033[1m
	#######################################################################
	##              % 警告：可能对系统产生非预期的影响! %                ##
	##             % 建议在虚拟环境（VM或Docker）下运行！ %              ##
	##                                                                   ##
	##    %Warning: There may be an unexpected impact on the system! %   ##
	##       %It is recommended to run under a virtual environment%      ##
	##                     % !(VM or Docker)! %                          ##
	#######################################################################\033[0m";
fi

#>    960 0
#<    0 0
#1/2  950 490
#1/3  950 336.666

#1/3> 960
#<1/3 0 336.666
#\>   960 585
#</   0 585

#set -euf -o pipefail;

#=====================================================

#以下为默认储存路径：
KALI_BIN_PATH="/home/kali/bin";
SUPPORT_FILE_01="/tmp/num01";
SUPPORT_FILE_02="/tmp/num02";
#TMP_FILE="$(mktemp -t Tonyhere.XXXXXXX)" || exit 021;
TMP_FILE_02="/tmp/SSH_state.sh";
TMP_FILE_03="/tmp/Monitor.sh)";
TMP_FILE_04="/tmp/Watch_Commands.sh)";
TMP_FILE_05="/tmp/Watch_Result.sh)";

#=====================================================

#if ! touch "$TMP_FILE_02" && chmod 700 "$TMP_FILE_02";then exit 022;fi
{ touch "$TMP_FILE_02" && chmod 700 "$TMP_FILE_02"; } || exit 022;
{ touch "$TMP_FILE_03" && chmod 700 "$TMP_FILE_03"; } || exit 023;
{ touch "$TMP_FILE_04" && chmod 700 "$TMP_FILE_04"; } || exit 024;
{ touch "$TMP_FILE_05" && chmod 700 "$TMP_FILE_05"; } || exit 025;

trap 'printf "\n\n[X] 中止。\n"; rm -f "$TMP_FILE_04" 2>/dev/null; rm -f "$TMP_FILE_05" 2>/dev/null; rm -f "$TMP_FILE_02" 2>/dev/null; rm -f "$TMP_FILE_03" 2>/dev/null; rm -f /tmp/num01 2>/dev/null; rm -f /tmp/num02 2>/dev/null;
 sleep 5s; exit 020' SIGINT SIGTERM;

sleep 5s;
clear;

TIME="$(date +"%H:%M:%S")";

xdotool windowsize "$(xdotool getactivewindow)" 950 500;
xdotool windowmove "$(xdotool getactivewindow)" 965 0;

#<LABEL>                           <F>  <S>  <UID>          <PID>     <PPID>  <C>  <PRI>   <NI>  <ADDR>  <SZ>  <WCHAN>    <RSS>  <PSR>  <STIME>  <TTY>          <TIME>     <CMD>
# unconfined                        4    S    kali           88868     88867   0    80      0     -       645   wait_w     884    0      16:17    pts/1          00:00:00   sh

if [ -d "/home/kali" ];then
	printf "「\033[32mINFO\033[0m」\033[34m启动环境检查正常。\033[0m\n";
	sleep 0.2s;
else
	printf "「\033[1;31mCRITICAL\033[0m」\033[31m未检测到启动环境，紧急终止！\033[0m\n";
	printf "「\033[34mINFO\033[0m」\033[34m返回代码：\033[1;31mCRITICALCode 01\033[0m\n";
	sleep 5s;
	rm -f "$TMP_FILE_04" 2>/dev/null;
	rm -f "$TMP_FILE_05" 2>/dev/null;
	rm -f "$TMP_FILE_02" 2>/dev/null;
	rm -f "$TMP_FILE_03" 2>/dev/null;
	rm -f "$SUPPORT_FILE_01" 2>/dev/null;
	rm -f "$SUPPORT_FILE_02" 2>/dev/null;
	exit 001;
fi

if [ "$(df -i 2>/dev/null|grep "/dev/loop0")" != "" ];then
	printf "「\033[32mINFO\033[0m」\033[34m受控隔离环境检查正常。\033[0m\n";
	sleep 0.2s;
else
	printf "「\033[1;31mCRITICAL\033[0m」\033[31m启动环境未受限制，紧急终止！\033[0m\n";
	printf "「\033[34mINFO\033[0m」\033[34m返回代码：\033[1;31mCRITICALCode 02\033[0m\n";
	sleep 5s;
	rm -f "$TMP_FILE_04" 2>/dev/null;
	rm -f "$TMP_FILE_05" 2>/dev/null;
	rm -f "$TMP_FILE_02" 2>/dev/null;
	rm -f "$TMP_FILE_03" 2>/dev/null;
	rm -f "$SUPPORT_FILE_01" 2>/dev/null;
	rm -f "$SUPPORT_FILE_02" 2>/dev/null;
	exit 002;
fi

if [ "$(ls -lah "$KALI_BIN_PATH/sh" |awk '{ print $1 }')" = "-r-xr--r--" ] \
&& [ "$(ls -la "$KALI_BIN_PATH/sh" |awk '{ print $3,$4,$5 }')" = "kali kali 2546" ];then
	printf "「\033[32mINFO\033[0m」\033[34m伪终端脚本检查正常。\033[0m\n";
	sleep 0.3s;
else
	printf "「\033[31mERRO\033[0m」\033[31m伪终端脚本检查异常。\033[0m\n";
	printf "「\033[34mINFO\033[0m」\033[34m返回代码：\033[31mErrorCode 01\033[0m\n";
	sleep 5s;
	rm -f "$TMP_FILE_04" 2>/dev/null;
	rm -f "$TMP_FILE_05" 2>/dev/null;
	rm -f "$TMP_FILE_02" 2>/dev/null;
	rm -f "$TMP_FILE_03" 2>/dev/null;
	rm -f "$SUPPORT_FILE_01" 2>/dev/null;
	rm -f "$SUPPORT_FILE_02" 2>/dev/null;
	exit 011;
fi

if [ "$(ls -lah "$KALI_BIN_PATH"/{cat,ls,sh2,touch} |awk '{ print $1 }')" = "-rwx--x--x
-rwx--x--x
-rwx--x--x
-rwx--x--x" ];then
	# && [ "$(ls -la /home/kali/bin/{cat,ls,sh2,touch} |awk '{ print $3,$4,$5 }')" = "root root 44016
	#root root 151344
	#root root 125640
	#root root 109616" ];then
	printf "「\033[32mINFO\033[0m」\033[34m可执行文件校验正常。(exc)\033[0m\n";
	sleep 0.4s;
else
	printf "「\033[33mWARN\033[0m」\033[33m可执行文件校验异常。(exc)\033[0m\n「\033[34mINFO\033[0m」\033[34m返回代码：\033[33mWarningCode 01\033[0m\n";
	printf "[\033[34m?\033[0m] 要中止蜜罐启动吗[Y/n]:";
	read -r "PASS";
	case $PASS in 
		Y | y )
			printf "「\033[34mINFO\033[0m」中止。\n";
			sleep 5s;
			rm -f "$TMP_FILE_04" 2>/dev/null;
			rm -f "$TMP_FILE_05" 2>/dev/null;
			rm -f "$TMP_FILE_02" 2>/dev/null;
			rm -f "$TMP_FILE_03" 2>/dev/null;
			rm -f "$SUPPORT_FILE_01" 2>/dev/null;
			rm -f "$SUPPORT_FILE_02" 2>/dev/null;
			exit 026;
		;;
		N | n )
		;;
		*)
			printf "「\033[34mINFO\033[0m」中止。\n";
			sleep 5s;
			rm -f "$TMP_FILE_04" 2>/dev/null;
			rm -f "$TMP_FILE_05" 2>/dev/null;
			rm -f "$TMP_FILE_02" 2>/dev/null;
			rm -f "$TMP_FILE_03" 2>/dev/null;
			rm -f "$SUPPORT_FILE_01" 2>/dev/null;
			rm -f "$SUPPORT_FILE_02" 2>/dev/null;
			exit 026;
		;;
	esac
fi

if [ "$(ls -la "$KALI_BIN_PATH"/{cat,ls,sh2,touch} |awk '{ print $3,$4,$5 }')" = "root root 44016
root root 151344
root root 125640
root root 109616" ];then
	printf "「\033[32mINFO\033[0m」\033[34m可执行文件校验正常。(own)\033[0m\n";
	sleep 0.4s;
else
	printf "「\033[33mWARN\033[0m」\033[33m可执行文件校验异常。(own)\033[0m\n「\033[34mINFO\033[0m」\033[34m返回代码：\033[33mWarningCode 02\033[0m\n";
	printf "[\033[34m?\033[0m] 要中止蜜罐启动吗[Y/n]:";
	read -r "PASS";
	case $PASS in 
		Y | y )
			printf "「\033[34mINFO\033[0m」中止。\n";
			rm -f "$TMP_FILE_04" 2>/dev/null;
			rm -f "$TMP_FILE_05" 2>/dev/null;
			rm -f "$TMP_FILE_02" 2>/dev/null;
			rm -f "$TMP_FILE_03" 2>/dev/null;
			rm -f "$SUPPORT_FILE_01" 2>/dev/null;
			rm -f "$SUPPORT_FILE_02" 2>/dev/null;
			exit 026;
		;;
		N | n )
		;;
		*)
			printf "「\033[34mINFO\033[0m」中止。\n";
			rm -f "$TMP_FILE_04" 2>/dev/null;
			rm -f "$TMP_FILE_05" 2>/dev/null;
			rm -f "$TMP_FILE_02" 2>/dev/null;
			rm -f "$TMP_FILE_03" 2>/dev/null;
			rm -f "$SUPPORT_FILE_01" 2>/dev/null;
			rm -f "$SUPPORT_FILE_02" 2>/dev/null;
			exit 026;
		;;
	esac
fi


if [ "$(ls -la "$KALI_BIN_PATH"/{.sh_commandhistory.txt,.sh_result.txt} |awk '{ print $1,$3,$4 }')" = "-rwx--x-w- root root
-rwx--x-w- root root" ];then
	printf "「\033[32mINFO\033[0m」\033[34m中继文件校验正常。(pipe)\033[0m\n";
	sleep 0.4s;
	for i in {1..3}
	do
		printf "[\033[34m?\033[0m] 要将中继文件重置为原始状态吗[y/n]:";
		read -r "PASS";
		case $PASS in 
			Y | y )
				cat /dev/null >"$KALI_BIN_PATH/.sh_commandhistory.txt";
				cat /dev/null >"$KALI_BIN_PATH/.sh_result.txt";
				printf "「\033[32mINFO\033[0m」\033[34m中继文件重置成功。(pipe)\033[0m\n";
				sleep 0.5s;
				break;
			;;
			N | n )
				break;
			;;
			*)
				printf "「\033[33mWARN\033[0m」\033[33m不合法的输入，只能输入 y（是）和 n（否）。\033[0m\n";
			;;
		esac
		if [ "$i" == 3 ];then
			echo -e "「\033[32mINFO\033[0m」跳过。\n";
		fi
	done
else
	printf "「\033[33mWARN\033[0m」\033[33m中继文件校验异常。(pipe)\033[0m\n「\033[34mINFO\033[0m」\033[34m返回代码：\033[33mWarningCode 03\033[0m\n";
	printf "[\033[34m?\033[0m] 要中止蜜罐启动吗[Y/n]:";
	read -r "PASS";
	case $PASS in 
		Y | y )
			printf "「\033[34mINFO\033[0m」中止。\n";
			rm -f "$TMP_FILE_04" 2>/dev/null;
			rm -f "$TMP_FILE_05" 2>/dev/null;
			rm -f "$TMP_FILE_02" 2>/dev/null;
			rm -f "$TMP_FILE_03" 2>/dev/null;
			rm -f "$SUPPORT_FILE_01" 2>/dev/null;
			rm -f "$SUPPORT_FILE_02" 2>/dev/null;
			exit 026;
		;;
		N | n )
		;;
		*)
			printf "「\033[34mINFO\033[0m」中止。\n";
			rm -f "$TMP_FILE_04" 2>/dev/null;
			rm -f "$TMP_FILE_05" 2>/dev/null;
			rm -f "$TMP_FILE_02" 2>/dev/null;
			rm -f "$TMP_FILE_03" 2>/dev/null;
			rm -f "$SUPPORT_FILE_01" 2>/dev/null;
			rm -f "$SUPPORT_FILE_02" 2>/dev/null;
			exit 026;
		;;
	esac
fi

# SSHD服务 状态监控脚本
echo '#!/bin/zsh

while [ "$(cat "/tmp/num01")" -eq 1 ]
do
	clear;
	printf "\t \033[1m「\033[1;32mINFO\033[1;37m」\033[34mSSHD 服务状态：\033[0m\n";
	printf "Every 1.0s: systemctl status ssh\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t     %s:%s\n\n" "$(hostname)" "$(date +%x%X)";
	#echo -e "$(systemctl status ssh)";
	#systemctl status ssh < $SUPPORT_FILE_01;
	SSH_STATE="$(systemctl status ssh)"
	echo "$SSH_STATE" |head -n 13;
	echo "$SSH_STATE" |tail -n 7;
	sleep 1s;
done' >"$TMP_FILE_02";

# Monitor 监控脚本
echo 'IyEvYmluL2Jhc2gKIyAtKi0gY29kaW5nOiB1dGYtOCAtKi0KIy8qU1NIIOe9kee7nOebkea1i+iE
muacrCovCiMg5L2c6ICFIO+8miBKZXNzYXJpbjAwMAojIOaXpeacnyDvvJogMjAyMy0xMi0wMgoj
IOeJiOacrCDvvJogNS4zCiMKIyPms6jmhI/vvJrCt+acrOiEmuacrOW6lOmFjeWQiCBsb2cuc2gg
5L2/55So44CCCiMjICAgICDCt+mBh+WIsOS7u+S9lemXrumimOaIlumUmeivr+ivt+iBlOezu+S9
nOiAheOAggojCiMxMDAxMDAwMTAxMDAxMDEwMDExMTEwMTAwMTAxMDEwMSAgICAgICAgICBfICAg
ICAgICAgIDEwMDEwMDAxMDEwMDEwMTAwMTExMTAxMDAxMDEwMTAxMQojMTAxMDEwMTAxMDAwMDEx
MTAxMTAxMDEwMTExMTAgICAgICBfLi09OjonICc6Oj0tLl8gICAgICAxMDEwMTAxMDEwMDAwMTEx
MDExMDEwMTAxMTExMDAKIzAwMDAwMTExMTEwMTAxMDEwIDEwMDAxMTEwICAgICAuLTonOiAgICc7
ICAgOycgICA6JzotLiAgICAgMDAwMDAxMTExMTAxMDEwMTAgMTAwMDExMTAxCiMxMTAxMDAxMDAw
MTAwMTAxMDEwMDEwMSAgICAgLjo6ICAgIDsuICAnIDsgOyAnICAuOyAgLiA6Oi4gICAgIDExMDEw
MDEwMDAxMDAxMDEwMTAwMTAxMQojMTAwMDEwMDEwMDEwMDExMTEwMDEwICAgIC46JyAgOiAgLiA7
LiA6ICAgOiAgIDogLjsgOyAgOiAgJzouICAgIDEwMDAxMDAxMDAxMDAxMTExMDAxMDAKIzEwIDAx
MDEwMTAxMDEwMTExMSAgICAuOiAgOiAgOicuIDo7IDogICAgICAgICA6IDsgOy4nOiAgOiAgOi4g
ICAgICAxMCAwMTAxMDEwMTAxMDExMTExCiMxMDEwMTAxMDEwMTAxMTEwICAgLi4uJyA6LiA6Jy4n
ICcuIDsgICAgICBfICAgICAgOzouJyAnLic6IC46ICcuLi4gICAxMDEwMTAxMDEwMTAxMTEwMAoj
MTEwMDEwMTAwMDAxMTExMTAgICAnLiA6LiAnLCAgJyAgJy47ICAuLT0nfCc9LS4gIDsuJyAgJyAg
LCcgLjogLicgICAxMTAwMTAxMDAwMDExMTExMDEKIzEwMDAxMDEwMTEwMTExMTEwICAgICAnOi46
LiAgICAgICAnOy4nJy06LXwtOi0nJy47JyAgICAgICAuOi46JyAgICAgMTAwMDEwMTAxMTAxMTEx
MTAwCiMxMTEwMDAxMTAxMDEwIDEwMSAgIC4gICAgICAgICAgICAgIDo6ICA6ICB8ICA6ICA6OiAg
ICAgICAgICAgICAgLiAgIDExMTAwMDExMDEwMTAgMTAxMQojMTExMDEwMTAwMTAxMDAwMCAgIDo6
IC4gICAgICAgIDsgIHw6LS0tOi0tfC0tOi0tLTp8ICA7ICAgICAgICAuIDo6ICAgMTExMDEwMTAw
MTAxMDAwMDEKIzEwMTAwMDAwMDAxMTExMSAgIDogOi46ICAgICAgIC46ICAgOjogIDogIHwgIDog
IDo6ICAgOi4gICAgICAgOi46IDogICAxMDEwMDAwMDAwMTExMTEwCiMwMDAwMDExMTExMDAxMDEw
ICAgOiA6IDogICcgIC4gJyAgICAnLi4tOi18LTotLi4nICAgICcgLiAgJyAgOiA6IDogICAwMDAw
MDExMTExMDAxMDEwMAojMTEwMDAwMTAwMDAxMTAxMDEgICAnOiAgOjogOiA6IDo6ICAgIC4nLT0u
fC49LScuICAgIDogIDogOiA6OiAgOicgICAxMTAwMDAxMDAwMDExMDEwMTEKIzExMDAwMDAwMTEx
MTExMDAxMCAgICAnLic6ICAuOiAnIDogIDo6ICAgIDogICAgOjogIDogIDo6LiAgOicuJycgICAx
MTAwMDAwMDExMTExMTAwMTAxCiMwMDAxMTEgMTAxMDAxMDEwMDAwICAgICAgJzouIDo6IC4gOi46
IDogIDogOiAgOiA6LjogLiA6OiAuOicqLiAgICAwMDAxMTEgMTAxMDAxMDEwMDAwMAojMTEwMTAw
MDAxMDEwMTAwMDAxMDEgICAgICAgJycuJyAgOiAgOyAgOjogICA6OiAgOyAgOiAgJzonKi46JyAg
ICAxMTAxMDAwMDEwMTAxMDAwMDEwMTAKIzExMDEwMTAwMTAxMDEwMDAwMDAxMTEgICAgICAnKiou
LTouXyA7ICA6ICAgOiAgOyBfLjotJyoqLjonICAgIDExMDEwMTAwMTAxMDEwMDAwMDAxMTExCiMw
MDExMTAxMDEwMSAwMDAwMDEwMDEwMDEgICAgIDo6ICAgICAgJy09OjpfOjo9LScnLioqKioqOiAg
ICAgMDAxMTEwMTAxMDEgMDAwMDAxMDAxMDAxMQojICAgICBfXyAgIF9fICBfX19fXyAgX19fX19f
XyA6Ol8gICBfICAgX19fX18gIF9fICA6X18qWz1dIF9fX19fX18gIF9fX19fICAgX19fX18KIyAg
ICAgfHw6ICB8fCB8fCAgICAnICAgfHx8ICAgOnwuJ18nLnwgfHwgICB8fCB8fDogOnx8Ki0tLSAg
IHx8fCAgIHx8ICAgfHwgfHxfX198fAojICAgICB8fCA6IHx8IHx8LS0tfCAgICB8fHwgICAnfHwn
LSd8fCB8fF9fX3x8IHx8IDonfHwqfCB8ICAgfHx8ICAgfHxfX198fCB8fCc6LS0nCiMgIC4gIHx8
X186fHwgfHxfX19fLiBfLnx8fC4uJyp8fCoqKnx8LnxfX19fX3wufHwnKjp8fC58X3wuLi58fHwu
Ll98X19fX198X3x8ICAnOi4gIC4KIyAgICstLScuKioqLi0tLioqKioqKioqLictLS0tLS0nLioq
KiouICctLS0tLS0tLS0tJy4qKioqKioqKioqKioqKioqKioqKioqKi4nLS0tLS0rCiMgICAgICAg
IDsqJyAgICAnLioqKi4nJyAgICAgICAgICA6KicgICAgICAgICAgICAgICAgOioqKioqKioqKioq
KiouJy4qKioqKicKIyAgICAgICAgIDouICAgICA6KiouICAgICAgICAgICAgIDo6ICAgICAgICAg
ICAgICAgICAnLioqKioqXy0tLSoqOiAgIDoqKio6CiMgICAgICAgICA6LiAgICAgICcnICAgICAg
ICAgICAgICA6OiAgICAgICAgICAgICAgICAgICA6Ll8qLiAgICAgICAgICA6Kio6CiMgICAgICAg
LicqOiAgICAgICAgICAgICAgICAgICAgIC4nOiAgICAgICAgICAgICAgICAgICAgICAgICAgICAg
ICAgIDoqKio6CiMgICAgIDonKioqJy4gICAgICAgICAgICAgICAgIC4uJyoqLiAgICAgICAgICAg
ICAgICAgICAgICAgICAgICAgICAgOioqKioqJy4KIyAgICAgICAgICAgICAgICAgICAgICAgICAg
ICAgICAgIAojIyMjCgpwcmludGYgIgoxMDAxMDAwMTAxMDAxMDEwMDExMTEwMTAwMTAxMDEwMSAg
ICAgICAgICBcMDMzWzE7MzFtX1wwMzNbMG0gICAgICAgICAgMTAwMTAwMDEwMTAwMTAxMDAxMTEx
MDEwMDEwMTAxMDExCjEwMTAxMDEwMTAwMDAxMTEwMTEwMTAxMDExMTEwICAgICAgXDAzM1sxOzMx
bV8uLT06OicgJzo6PS0uX1wwMzNbMG0gICAgICAxMDEwMTAxMDEwMDAwMTExMDExMDEwMTAxMTEx
MDAKMDAwMDAxMTExMTAxMDEwMTAgMTAwMDExMTAgICAgIFwwMzNbMTszMW0uLTonXDAzM1swbVww
MzNbMW06ICAgJzsgICA7JyAgIDpcMDMzWzE7MzFtJzotLlwwMzNbMG0gICAgIDAwMDAwMTExMTEw
MTAxMDEwIDEwMDAxMTEwMQoxMTAxMDAxMDAwMTAwMTAxMDEwMDEwMSAgICAgXDAzM1sxOzMxbS46
OlwwMzNbMG1cMDMzWzFtICAgIDsuICAnIFwwMzNbMTszMW07IDtcMDMzWzBtXDAzM1sxbSAnICAu
OyAgXDAzM1sxOzMxbS4gOjouXDAzM1swbSAgICAgMTEwMTAwMTAwMDEwMDEwMTAxMDAxMDExCjEw
MDAxMDAxMDAxMDAxMTExMDAxMCAgICBcMDMzWzE7MzFtLjonXDAzM1swbVwwMzNbMW0gIDogIFww
MzNbMTszMW0uXDAzM1swbVwwMzNbMW0gOy4gOiAgIFwwMzNbMTszMW06XDAzM1swbSAgIDogLjsg
XDAzM1sxOzMxbTtcMDMzWzBtXDAzM1sxbSAgOiAgXDAzM1sxOzMxbSc6LlwwMzNbMG0gICAgMTAw
MDEwMDEwMDEwMDExMTEwMDEwMAoxMCAwMTAxMDEwMTAxMDExMTEgICAgXDAzM1sxOzMxbS46XDAz
M1swbVwwMzNbMW0gIDogIDonLiBcMDMzWzE7MzFtOlwwMzNbMG1cMDMzWzFtOyA6ICAgICAgICAg
OiBcMDMzWzE7MzFtOyA7XDAzM1swbVwwMzNbMW0uJzogIDogIFwwMzNbMTszMW06LlwwMzNbMG0g
ICAgICAxMCAwMTAxMDEwMTAxMDExMTExCjEwMTAxMDEwMTAxMDExMTAgICBcMDMzWzE7MzFtLi4u
J1wwMzNbMG1cMDMzWzFtIDouIDonLicgXDAzM1sxOzMxbScuIDtcMDMzWzBtXDAzM1sxbSAgICAg
IFwwMzNbMTszNG1fXDAzM1swbSAgICAgIFwwMzNbMTszMW07Oi4nXDAzM1swbVwwMzNbMW0gJy4n
OiAuOiBcMDMzWzE7MzFtJy4uLlwwMzNbMG0gICAxMDEwMTAxMDEwMTAxMTEwMAoxMTAwMTAxMDAw
MDExMTExMCAgICcuIDouICcsICAnICBcMDMzWzE7MzFtJy47XDAzM1swbVwwMzNbMW0gIFwwMzNb
MTszNG0uLT0nfCc9LS5cMDMzWzBtICBcMDMzWzE7MzFtOy4nXDAzM1swbVwwMzNbMW0gICcgICwn
IC46IC4nXDAzM1swbSAgIDExMDAxMDEwMDAwMTExMTEwMQoxMDAwMTAxMDExMDExMTExMCAgICAg
JzpcMDMzWzE7MzFtLjouICAgICAgICc7XDAzM1swbVwwMzNbMW1cMDMzWzE7MzRtLicnLTotfC06
LScnLlwwMzNbMG1cMDMzWzE7MzFtOydcMDMzWzBtXDAzM1sxbSAgICAgICAuOi46JyBcMDMzWzBt
ICAgIDEwMDAxMDEwMTEwMTExMTEwMAoxMTEwMDAxMTAxMDEwIDEwMSAgIFwwMzNbMTszMW0uXDAz
M1swbSAgICAgICAgICAgICAgXDAzM1sxOzM0bTo6ICA6ICB8ICA6ICA6OlwwMzNbMG0gICAgICAg
ICAgICAgIFwwMzNbMW0uXDAzM1swbSAgIDExMTAwMDExMDEwMTAgMTAxMQoxMTEwMTAxMDAxMDEw
MDAwICAgXDAzM1sxOzMxbTo6XDAzM1swbVwwMzNbMW0gLiAgICAgICAgXDAzM1sxOzMxbTtcMDMz
WzBtXDAzM1sxbSAgXDAzM1sxOzM0bXw6LS0tOi0tfC0tOi0tLTp8XDAzM1swbSAgXDAzM1sxOzMx
bTtcMDMzWzBtXDAzM1sxbSAgICAgICAgXDAzM1sxOzMxbS5cMDMzWzBtXDAzM1sxbSA6OlwwMzNb
MG0gICAxMTEwMTAxMDAxMDEwMDAwMQoxMDEwMDAwMDAwMTExMTEgICBcMDMzWzE7MzFtOlwwMzNb
MG1cMDMzWzFtIDouOiAgICAgICBcMDMzWzE7MzFtLjpcMDMzWzBtXDAzM1sxbSAgIFwwMzNbMTsz
NG06OiAgOiAgfCAgOiAgOjpcMDMzWzBtICAgXDAzM1sxOzMxbTouXDAzM1swbVwwMzNbMW0gICAg
ICAgXDAzM1sxOzMxbTouXDAzM1swbVwwMzNbMW06IFwwMzNbMTszMW06XDAzM1swbSAgIDEwMTAw
MDAwMDAxMTExMTAKMDAwMDAxMTExMTAwMTAxMCAgIFwwMzNbMTszMW06XDAzM1swbVwwMzNbMW0g
XDAzM1sxOzMxbTpcMDMzWzBtXDAzM1sxbSA6ICAnICBcMDMzWzE7MzFtLiAnXDAzM1swbVwwMzNb
MW0gICAgXDAzM1sxOzM0bScuLi06LXwtOi0uLidcMDMzWzBtICAgIFwwMzNbMTszMW0nIC5cMDMz
WzBtXDAzM1sxbSAgJyAgOiA6IFwwMzNbMTszMW06XDAzM1swbSAgIDAwMDAwMTExMTEwMDEwMTAw
CjExMDAwMDEwMDAwMTEwMTAxICAgXDAzM1sxOzMxbSc6XDAzM1swbVwwMzNbMW0gIDo6IDogOiBc
MDMzWzE7MzFtOlwwMzNbMTszMW06XDAzM1swbVwwMzNbMW0gICAgLlwwMzNbMTszNG0nLT0ufC49
LSdcMDMzWzBtXDAzM1sxbS4gICAgXDAzM1sxOzMxbTogIDpcMDMzWzBtXDAzM1sxbSA6IDo6ICBc
MDMzWzE7MzFtOidcMDMzWzBtICAgMTEwMDAwMTAwMDAxMTAxMDExCjExMDAwMDAwMTExMTExMDAx
MCAgICBcMDMzWzE7MzFtJy5cMDMzWzBtXDAzM1sxbSc6ICAuOiBcMDMzWzE7MzFtJyBcMDMzWzE7
MzFtOlwwMzNbMG1cMDMzWzFtICA6OiAgICA6ICAgIDo6ICA6ICBcMDMzWzE7MzFtOjouXDAzM1sw
bVwwMzNbMW0gIDonXDAzM1sxOzMxbS4nJ1wwMzNbMG0gICAxMTAwMDAwMDExMTExMTAwMTAxCjAw
MDExMSAxMDEwMDEwMTAwMDAgICAgICBcMDMzWzE7MzFtJzouXDAzM1swbVwwMzNbMW0gOjogXDAz
M1sxOzMxbS4gXDAzM1sxOzMxbTpcMDMzWzBtXDAzM1sxbS46IDogIDogOiAgOiA6LjogXDAzM1sx
OzMxbS5cMDMzWzBtXDAzM1sxbSA6OiBcMDMzWzE7MzFtLjonKi5cMDMzWzBtICAgIDAwMDExMSAx
MDEwMDEwMTAwMDAwCjExMDEwMDAwMTAxMDEwMDAwMTAxICAgICAgIFwwMzNbMTszMW0nJy5cMDMz
WzBtXDAzM1sxbScgIFwwMzNbMTszMW06XDAzM1swbVwwMzNbMW0gIDsgIDo6ICAgOjogIDsgIFww
MzNbMTszMW06ICAnOicqLjonXDAzM1swbSAgICAxMTAxMDAwMDEwMTAxMDAwMDEwMTAKMTEwMTAx
MDAxMDEwMTAwMDAwMDExMSAgICAgIFwwMzNbMTszMW0nKiouLTouX1wwMzNbMG1cMDMzWzFtIDsg
IDogICA6ICA7IFwwMzNbMTszMW1fLjotJyoqLjonXDAzM1swbSAgICAxMTAxMDEwMDEwMTAxMDAw
MDAwMTExMQowMDExMTAxMDEwMSAwMDAwMDEwMDEwMDEgICAgIFwwMzNbMTszMW06OiAgICAgICct
PTo6Xzo6PS0nJy4qKioqKjpcMDMzWzBtICAgICAwMDExMTAxMDEwMSAwMDAwMDEwMDEwMDExCiAg
ICAgXDAzM1sxOzM0bV9fICAgX18gIF9fX19fICBfX19fX19fIFwwMzNbMG1cMDMzWzE7MzFtOjpc
MDMzWzE7MzRtXyAgIF8gICBfX19fXyAgX18gIFwwMzNbMG1cMDMzWzE7MzFtOlwwMzNbMTszNG1f
X1wwMzNbMG1cMDMzWzE7MzFtKlwwMzNbMTszNG1bPV0gX19fX19fXyAgX19fX18gICBfX19fX1ww
MzNbMG0KICAgICBcMDMzWzE7MzRtfHw6ICB8fCB8fCAgICAnICAgfHx8ICAgXDAzM1sxOzMxbTpc
MDMzWzBtXDAzM1sxOzM0bXwuJ18nLnwgfHwgICB8fCB8fDogXDAzM1swbVwwMzNbMTszMW06XDAz
M1swbVwwMzNbMTszNG18fFwwMzNbMG1cMDMzWzE7MzFtKlwwMzNbMG1cMDMzWzE7MzRtLS0tICAg
fHx8ICAgfHwgICB8fCB8fF9fX3x8XDAzM1swbQogICAgIFwwMzNbMTszNG18fCA6IHx8IHx8LS0t
fCAgICB8fHwgICBcMDMzWzE7MzFtJ1wwMzNbMG1cMDMzWzE7MzRtfHwnLSd8fCB8fF9fX3x8IHx8
IDpcMDMzWzBtXDAzM1sxOzMxbSdcMDMzWzBtXDAzM1sxOzM0bXx8XDAzM1swbVwwMzNbMTszMW0q
XDAzM1swbVwwMzNbMTszNG18IHwgICB8fHwgICB8fF9fX3x8IHx8JzotLSdcMDMzWzBtCiAgXDAz
M1sxOzMxbS5cMDMzWzBtICBcMDMzWzE7MzRtfHxcMDMzWzE7MzFtX19cMDMzWzBtXDAzM1swbVww
MzNbMTszNG06fHwgfHxfX19fLlwwMzNbMG1cMDMzWzE7MzFtIF8uXDAzM1swbVwwMzNbMTszNG18
fHxcMDMzWzBtXDAzM1sxOzMxbS4uJypcMDMzWzBtXDAzM1sxOzM0bXx8XDAzM1swbVwwMzNbMTsz
MW0qKipcMDMzWzBtXDAzM1sxOzM0bXx8XDAzM1swbVwwMzNbMTszMW0uXDAzM1swbVwwMzNbMTsz
NG18X19fX198XDAzM1swbVwwMzNbMTszNG0uXDAzM1swbVwwMzNbMTszNG18fFwwMzNbMG1cMDMz
WzE7MzFtJypcMDMzWzBtXDAzM1sxOzM0bTp8fFwwMzNbMG1cMDMzWzE7MzFtLlwwMzNbMG1cMDMz
WzE7MzRtfF98XDAzM1swbVwwMzNbMTszMW0uLi5cMDMzWzBtXDAzM1sxOzM0bXx8fFwwMzNbMG1c
MDMzWzE7MzFtLi5fXDAzM1swbVwwMzNbMTszNG18X19fX198XDAzM1swbVwwMzNbMTszMW1fXDAz
M1swbVwwMzNbMTszNG18fCAgJzouXDAzM1swbVwwMzNbMTszMW0gIC4KICAgKy0tJy4qKiouLS0u
KioqKioqKiouJy0tLS0tLScuKioqKi4gJy0tLS0tLS0tLS0nLioqKioqKioqKioqKioqKioqKioq
KioqLictLS0tLSsKICAgICAgICA7KicgICAgJy4qKiouJycgICAgICAgICAgOionICAgICAgICAg
ICAgICAgIDoqKioqKioqKioqKioqLicuKioqKionCiAgICAgICAgIDouICAgICA6KiouICAgICAg
ICAgICAgIDo6ICAgICAgICAgICAgICAgICAnLioqKioqXy0tLSoqOiAgIDoqKio6CiAgICAgICAg
IDouICAgICAgJycgICAgICAgICAgICAgIDo6ICAgICAgICAgICAgICAgICAgIDouXyouICAgICAg
ICAgIDoqKjoKICAgICAgIC4nKjogICAgICAgICAgICAgICAgICAgICAuJzogICAgICAgICAgICAg
ICAgICAgICAgICAgICAgICAgICA6KioqOgogICAgIDonKioqJy4gICAgICAgICAgICAgICAgIC4u
JyoqLiAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgOioqKioqJy5cMDMzWzBtCgpcMDMz
WzM0bQovKlNTSCDnvZHnu5znm5HmtYvohJrmnKwqLwog5L2c6ICFIO+8miBKZXNzYXJpbjAwMAog
5pel5pyfIO+8miAyMDIzLTEyLTAyCiDniYjmnKwg77yaIDUuM1wwMzNbMG0KIAogIAogICAg5pys
6ISa5pys55So5LqO6Ieq5Yqo5YyW55uR5rWLIFNTSCDnvZHnu5zmlLvlh7vvvIjlpoLlnKjnur/l
r4bnoIHniIbnoLTvvIxObWFwIOaJq+aPj++8ieOAglwwMzNbMzFt5Zyo5ZCv5Yqo5q2k6ISa5pys
5YmN6K+35p+l55yL5bm26YWN572u6ISa5pys5Lul6YCC5bqU5oKo55qE57O757uf44CCXDAzM1sw
bQrmnKzohJrmnKzlj6/ku6Xnu5PlkIjlpJrnp43mlrnlvI/lnKjmlLvlh7vogIXov5vlhaXonJzn
vZDliY3liqjmgIHnm5HmtYvlhbblnKggU1NIIOi/nuaOpeerr+WPo+eahOWQhOenjeihjOS4uuOA
ggoKICAgIFwwMzNbMTszNW3mnInku7vkvZXmhI/op4HmiJblu7rorq7or7fogZTns7vkvZzogIXv
vJo8a2p4NTJAb3V0bG9vay5jb20+XDAzM1swbQoKXDAzM1szM21A5rOo5oSP77yawrfmnKzohJrm
nKzlupTphY3lkIggbG9nLnNoIOS9v+eUqOOAglwwMzNbMG0KXDAzM1szM21AICAgICAgwrfpgYfl
iLDku7vkvZXpl67popjmiJbplJnor6/or7fogZTns7vkvZzogIXjgIJcMDMzWzBtXG5cbgoiOwoK
VVNFUl9MRVZFTD0iJCh3aG9hbWkpIjsKaWYgWyAiJFVTRVJfTEVWRUwiID0gInJvb3QiIF07dGhl
bgoJI+S9oOeUqOeahOaYr3Jvb3TvvJ/lvZPnnJ/vvJ/kvaDlgrvkuoblkJfvvJ8KCXByaW50ZiAi
44CMXDAzM1szM21XQVJOXDAzM1swbeOAjVwwMzNbMzNt5qOA5rWL5Yiw5L2/55SoIHJvb3Qg6LSm
5oi36L+Q6KGM77yM6L+Z5Y+v6IO95Ye6546w6Z2e6aKE5pyf55qE5Y2x6Zmp44CCXDAzM1swbVxu
IjsKCVVTRVJfTEVWRUw9Ii9yb290IjsKZWxpZiBbICIkVVNFUl9MRVZFTCIgPSAia2FsaSIgXTt0
aGVuCglwcmludGYgIuOAjO+8n++8n++8n+OAjeS9oOeUqOicnOe9kOi0puaIt+i/kOihjO+8n+W9
k+ecn++8n+S9oOWCu+S6huWQlygwIF8gMCk/XG4iOwoJc2xlZXAgMnM7CglleGl0IDAwMTsKZWxz
ZQoJI+S9oOWxheeEtuS4jeaPkOadg++8n+W9k+ecn++8n+S9oOWCu+S6huWQl++8nzpECglVU0VS
X0xFVkVMPSIvaG9tZS8kKHdob2FtaSkiOwpmaQoKc2xlZXAgNXM7CmNsZWFyOwoKI3NldCAtZXVm
IC1vIHBpcGVmYWlsOwoKVE1QX0ZJTEU9IiQobWt0ZW1wIC10IFRvbnloZXJlLlhYWFhYWFgpIiB8
fCBleGl0IDAyMTsKdHJhcCAncHJpbnRmICJcblxuW1hdIOS4reatouOAglxuIjsgcm0gLWYgIiRU
TVBfRklMRSI7IHNsZWVwIDVzOyBleGl0IDAyMCcgU0lHSU5UIFNJR1RFUk07CgppZiBbICEgLWYg
Ii90bXAvbnVtMDIiIF07dGhlbgoJcHJpbnRmICJcMDMzWzFt44CMXDAzM1sxOzMxbUNSSVRJQ0FM
XDAzM1swbVwwMzNbMW3jgI1cMDMzWzBtXDAzM1sxOzMxbeacquajgOa1i+WIsOaUr+aMgeeOr+Wi
g++8jOe0p+aApee7iOatou+8gVwwMzNbMG1cbiI7CglwcmludGYgIuOAjFwwMzNbMzRtSU5GT1ww
MzNbMG3jgI1cMDMzWzM0bei/lOWbnuS7o+egge+8mlwwMzNbMTszMW1DUklUSUNBTENvZGUgMDFc
MDMzWzBtXG4iOwoJc2xlZXAgMnM7CglleGl0IDAwMjsKZWxzZQoJcHJpbnRmICLjgIxcMDMzWzMy
bUlORk9cMDMzWzBt44CNXDAzM1szNG3mlK/mjIHnjq/looPmo4Dmn6XmraPluLjjgIJcMDMzWzBt
XG4iOwpmaQoKaWYgWyAiJChzeXN0ZW1jdGwgc3RhdHVzIHNzaCB8Z3JlcCAiQWN0aXZlIiB8YXdr
ICd7IHByaW50ICQyIH0nKSIgPSAiaW5hY3RpdmUiIF07dGhlbgoJcHJpbnRmICJcMDMzWzFt44CM
XDAzM1sxOzMxbUNSSVRJQ0FMXDAzM1swbVwwMzNbMW3jgI1cMDMzWzBtXDAzM1sxOzMxbeacquaj
gOa1i+WIsOWQr+WKqOeOr+Wig++8jOe0p+aApee7iOatou+8gVwwMzNbMG1cbiI7CglwcmludGYg
IuOAjFwwMzNbMzRtSU5GT1wwMzNbMG3jgI1cMDMzWzM0bei/lOWbnuS7o+egge+8mlwwMzNbMTsz
MW1DUklUSUNBTENvZGUgMDJcMDMzWzBtXG4iOwoJc2xlZXAgMnM7CglleGl0IDAwMzsKZWxzZQoJ
cHJpbnRmICLjgIxcMDMzWzMybUlORk9cMDMzWzBt44CNXDAzM1szNG3lkK/liqjnjq/looPmo4Dm
n6XmraPluLjjgIJcMDMzWzBtXG4iOwpmaQoKIz09PT09PT09PT09PT09PT09PT09PT09PT09PT09
PT09PT09PT09PT09PT09PT09PT09PT09Cgoj5Lul5LiL5piv5pys56iL5bqP6ZyA6KaB55qE54m5
5q6K5Y+v5omn6KGM5paH5Lu277yaCkVYRUNVVEFCTEVfRklMRVswXT0ianEiOwpFWEVDVVRBQkxF
X0ZJTEVbMV09InhtbHN0YXJsZXQiOwpFWEVDVVRBQkxFX0ZJTEVbMl09ImNzdmZvcm1hdCI7Cgoj
PT09PT09PT09PT09PT09PT09PT09PT09PT09PT09PT09PT09PT09PT09PT09PT09PT09PT0KCkxB
Q0s9IiI7CkVYRVswXT0iIjsKRVhFWzFdPSIiOwpFWEVbMl09IiI7CkxFTj0keyNFWEVDVVRBQkxF
X0ZJTEVbQF19OwpFWEVfTEFDSz0wOwoKZWNobyAiJFBBVEgiIHxhd2sgJ3tzcGxpdCgkMCxwYXRo
LCI6Iik7Zm9yIChpIGluIHBhdGgpIHByaW50IHBhdGhbaV0iXG4iIH0nID4iJFRNUF9GSUxFIjsK
d2hpbGUgcmVhZCAtciBFWEVDVVRBQkxFX0ZJTEVfUEFUSDsgZG8KCVtbIC16ICIkRVhFQ1VUQUJM
RV9GSUxFX1BBVEgiIF1dIFwKCSYmIGNvbnRpbnVlOwoJZm9yICgoaT0wIDsgaTxMRU4gOyBpKysp
KQoJZG8KCQlpZiBbICIkKGxzICIkRVhFQ1VUQUJMRV9GSUxFX1BBVEgvJHtFWEVDVVRBQkxFX0ZJ
TEVbaV19IiAyPi9kZXYvbnVsbCApIiA9ICIiIF0gXAoJCSYmIFsgIiR7RVhFW2ldfSIgIT0gIjAi
IF07dGhlbgoJCQlFWEVbaV09MTsKCQllbHNlCgkJCUVYRVtpXT0wOwoJCWZpCglkb25lCmRvbmUg
PCAiJFRNUF9GSUxFIgpmb3IgKChpPTAgOyBpPExFTiA7IGkrKykpCmRvCglpZiBbICIke0VYRVtp
XX0iICE9ICIwIiBdO3RoZW4KCQlMQUNLPSIkTEFDS1x0JHtFWEVDVVRBQkxFX0ZJTEVbaV19ICxc
biI7CglmaQpkb25lCgppZiBbICIkTEFDSyIgIT0gIiIgXTt0aGVuCglwcmludGYgIuOAjFwwMzNb
MzNtV0FSTlwwMzNbMG3jgI1cMDMzWzMzbeajgOa1i+WIsOS6jOi/m+WItuaWh+S7tue8uuWkse+8
jOWIl+ihqOWmguS4i++8mlxuJExBQ0sg6buY6K6k5oOF5Ya15LiL77yM6L+Z5bCG6YCg5oiQ5pys
56iL5bqP5pel5b+X5paH5Lu25peg5rOV6L2s5o2i5qC85byP44CCXDAzM1swbVxuIjsKCXByaW50
ZiAiW1wwMzNbMzRtP1wwMzNbMG1dIOimgeS4reatouebkea1i+WQl1tZL25dOiI7CglyZWFkIC1y
IEFOUzsKCWNhc2UgJEFOUyBpbgoJCXkgfCBZICkKCQkJcHJpbnRmICLkuK3mraLjgIJcbiI7CgkJ
CXNsZWVwIDJzOwoJCQlleGl0IDAyMjsKCQk7OwoJCQoJCW4gfCBOICkKCQkJRVhFX0xBQ0s9MTsK
CQk7OwoJCQoJCSopCgkJCXByaW50ZiAi5Lit5q2i44CCXG4iOwoJCQlzbGVlcCAyczsKCQkJZXhp
dCAwMjI7CgkJOzsKCQkKCWVzYWMKZWxzZQoJcHJpbnRmICLjgIxcMDMzWzMybUlORk9cMDMzWzBt
44CNXDAzM1szNG3lj6/miafooYzmlofku7bmoKHpqozmraPluLjjgIJcMDMzWzBtXG4iOwpmaQoK
ZWNobyAiIjsKCmlmIFsgIiQoc3NoZCAtdiAyPiYxIHxoZWFkIC1uIDIgfHRhaWwgLW4gMSB8YXdr
ICd7IHByaW50ICQxLCQyIH0nIHxhd2sgLUYsICd7IHByaW50ICQxIH0nKSIgIT0gIk9wZW5TU0hf
Mi4zcDEgVWJ1bnR1LTciIF07dGhlbgoJcHJpbnRmICLjgIxcMDMzWzMzbVdBUk5cMDMzWzBt44CN
XDAzM1szM23mo4DmtYvliLAgU1NIIOacjeWKoeeJiOacrOWPt+acquabtOaUueOAglxuXDAzM1sw
bSI7CmZpCgpBRERfSVA9IiQoaXAgYSB8Z3JlcCAiLzIxIiB8YXdrIC1GJyAnICd7IHByaW50ICQy
IH0nIHxhd2sgLUYnLycgJ3sgcHJpbnQgJDEgfScpIjsKaWYgWyAiJEFERF9JUCIgPSAiIiBdO3Ro
ZW4KCUFERF9JUD0iJChpcCBhIHxncmVwICIvMjQiIHxhd2sgLUYnICcgJ3sgcHJpbnQgJDIgfScg
fGF3ayAtRicvJyAneyBwcmludCAkMSB9JykiOwoJaWYgWyAiJEFERF9JUCIgPSAiIiBdO3RoZW4K
CQlBRERfSVA9IiQoaXAgYSB8Z3JlcCAiYnJkIiB8Z3JlcCAiaW5ldCIgfGF3ayAtRicgJyAneyBw
cmludCAkMiB9JyB8YXdrIC1GJy8nICd7IHByaW50ICQxIH0nKSI7CglmaQpmaQoKU1RBUlRfRkxB
Rz0xOwpFUlJPUl8wMT0wOwpFUlJPUl8wMj0wOwpFUlJPUl8wMz0wOwpGQUlMVVJFPTA7CkFUVEFD
S0VSPTA7CldBUk5JTkdfVENQPTA7CldBUk5JTkdfU1JWPTA7CkNSSVRJQ0FMX1NIVVRET1dOPTA7
CgpOTUFQX1NWPTA7Ck5NQVBfU1Q9MDsKTk1BUF9TQ1JJUFQ9MDsKTk1BUF9BTEw9MDsKCnVuc2V0
IEhPU1RfMDsKdW5zZXQgSE9TVF8xOwp1bnNldCBIT1NUXzI7CnVuc2V0IEhPU1RfMzsKdW5zZXQg
SE9TVF80OwoKIz09PT09PT09PT09PT09PT09PT09PT09PT09PT09PT09PT09PT09PT09PT09PT09
PT09PT09Cgoj5Lul5LiL5Li66buY6K6k5YKo5a2Y6Lev5b6E77yaCkxPR19GSUxFX0RJUj0iJFVT
RVJfTEVWRUwv5qGM6Z2iL1NTSC1ob25leXBvdCI7CkhZRFJBX0ZJTEVfTUFJTj0iJFVTRVJfTEVW
RUwv5qGM6Z2iL1NTSC1ob25leXBvdC9TU0hfYXR0YWNrZXIudHh0IjsKTk1BUF9GSUxFX01BSU49
IiRVU0VSX0xFVkVML+ahjOmdoi9TU0gtaG9uZXlwb3QvU1NIX25tYXBfaG9zdC50eHQiOwpTVE9S
RV9GSUxFX0RJUj0iL3Zhci9sb2cvc3NoLWhvbmV5cG90IjsKCiM9PT09PT09PT09PT09PT09PT09
PT09PT09PT09PT09PT09PT09PT09PT09PT09PT09PT09PQoKREFURT0iJChkYXRlICsiJVktJW0t
JWQiKSI7CklQX0ZJTEU9IiRTVE9SRV9GSUxFX0RJUi8kREFURS5pcCI7CgpmdW5jdGlvbiBqc29u
X3RvX3htbCgpCnsKCWpxIC1yICd0b19lbnRyaWVzIHwgbWFwKHsoLmtleSk6IC52YWx1ZX0pIHwg
LltdJyAiJDEiIHwgeG1sc3RhcmxldCBmbzsKfQoKZnVuY3Rpb24ganNvbl90b19jc3YoKSAgI+iZ
veeEtuaIkeiupOS4uuayoeacieW/heimge+8jOS9huaYr+aIkeeahCBBSSDliqnmiYsgUmlXIOWd
muaMgeimgeWKoOi/meS4quWHveaVsOOAguS7luiupOS4uuWuouaIt+acieWPr+iDveS8muWwhuaX
peW/l+i9rOWCqOW5tueUqOS6juWIhuaekOOAggp7CglqcSAtciAndG9fZW50cmllcyB8IG1hcChb
LmtleSwgLnZhbHVlXSkgfCAuW10gfCBAY3N2JyAiJDEiIHwgY3N2Zm9ybWF0IC1IOwp9Cgpwcmlu
dGYgIuOAjFwwMzNbMzJtSU5GT1wwMzNbMG3jgI1cMDMzWzM0beS9oOW4jOacm+aXpeW/l+aWh+S7
tui+k+WHuuS4uuS7peS4i+WTquenjeagvOW8j++8mlxuMe+8iWpzb24gX+m7mOiupF9cbjLvvIl4
bWxcbjPvvIljc3Zcblxu6K+36L6T5YWl6YCJ6aG55a+55bqU55qE5pWw5a2X77yaXDAzM1swbSI7
CnJlYWQgLXIgSU5UX0ZPUk1BVDsKRk9STUFUPSIke0lOVF9GT1JNQVQ6LWpzb259IjsKCmZ1bmN0
aW9uIFRpbWVfQ29udHJhc3QoKQp7CgkjICQxID0gJFNUQVJUX0ZMQUdfMDIgOyAkMiA9IOWFs+mU
ruivjTEuIDsgJDMgPSAkQ1VSUkVOVF9USU1FIDsgJDQgPSDlhbPplK7or40yLiA7ICQ1ID0gLXYg
5YWz6ZSu6K+NMwoJCglsb2NhbCBEQVRFXzAyOwoJbG9jYWwgS0VZX1dPUkQxOwoJbG9jYWwgS0VZ
X1dPUkQyOwoJbG9jYWwgTlVNXzAwMjsKCWxvY2FsIE5VTV8wMDM7Cglsb2NhbCBUSU1FXzAwMjsK
CQoJREFURV8wMj0iJChkYXRlICslYlwgJWQpIjsKCUtFWV9XT1JEMT0iJHs0Oi19IjsKCUtFWV9X
T1JEMj0iJHs1Oi1WQUxPUl9QUkVERVRFUk1JTkFET30iOwoJVE1QX0hBTkdfMDE9MDsKCQoJaWYg
WyAiJDEiIC1lcSAxIF07dGhlbgoJCU5VTV8wMDI9IiQoam91cm5hbGN0bCAtdSBzc2ggfGdyZXAg
IiREQVRFXzAyIiB8Z3JlcCAiJDIiIHxncmVwICIkS0VZX1dPUkQxIiB8Z3JlcCAtdiAiJEtFWV9X
T1JEMiIgfGF3ayAnRU5Ee3ByaW50IE5SfScpIjsKCQlpZiBbICIkTlVNXzAwMiIgLWd0IDEgXTt0
aGVuCgkJCWZvciAoKGk9MSA7IGk8PU5VTV8wMDIgOyBpKyspKQoJCQlkbwoJCQkJVElNRV8wMDI9
IiQoam91cm5hbGN0bCAtdSBzc2ggfGdyZXAgIiREQVRFXzAyIiB8Z3JlcCAiJDIiIHxncmVwICIk
S0VZX1dPUkQxIiB8Z3JlcCAtdiAiJEtFWV9XT1JEMiIgfHRhaWwgLW4gIiRpIiB8aGVhZCAtbiAx
IHxhd2sgJ3sgcHJpbnQgJDMgfScgfGF3ayAtRjogJ3sgcHJpbnQgJDEkMiQzIH0nKSI7CgkJCQlp
ZiBbICIkVElNRV8wMDIiIC1sdCAiJDMiIF07dGhlbgoJCQkJCVRNUF9IQU5HXzAxPSIkKChpLTEp
KSI7CgkJCQkJYnJlYWs7CgkJCQlmaSAgCgkJCWRvbmUKCQllbHNlCgkJCU5VTV8wMDM9IiQoam91
cm5hbGN0bCAtdSBzc2ggfGdyZXAgIiREQVRFXzAyIiB8Z3JlcCAiJDIiIHxncmVwICIkS0VZX1dP
UkQxIiB8Z3JlcCAtdiAiJEtFWV9XT1JEMiIgfGF3ayAneyBwcmludCAkMyB9JyB8YXdrIC1GOiAn
eyBwcmludCAkMSQyJDMgfScpIjsKCQkJaWYgWyAiJE5VTV8wMDMiICE9ICIiIF0gXAoJCQkmJiBb
ICIkTlVNXzAwMyIgLWdlICIkMyIgXTt0aGVuCgkJCQlUTVBfSEFOR18wMT0xOwoJCQllbHNlCgkJ
CQlUTVBfSEFOR18wMT0wOwoJCQlmaQoJCWZpCglmaQp9CgpmdW5jdGlvbiBUaW1lX0NvbnRyYXN0
XzIoKQp7CgkjICQxID0gJFNUQVJUX0ZMQUdfMDIgOyAkMiA9IOWFs+mUruivjS4gOyAkMyA9ICRD
VVJSRU5UX1RJTUUKCQoJbG9jYWwgREFURV8wMzsKCWxvY2FsIE5VTV8wMDE7Cglsb2NhbCBOVU1f
MDA0OwoJbG9jYWwgVElNRV8wMDE7CgkKCURBVEVfMDM9IiQoZGF0ZSArJWJcICVkKSI7CglUTVBf
SEFOR18wMz0wOwoJCglpZiBbICIkMSIgLWVxIDEgXTt0aGVuCgkJTlVNXzAwMT0iJChqb3VybmFs
Y3RsIC11IHNzaCB8Z3JlcCAiJERBVEVfMDMiIHxncmVwICIkMiIgfGF3ayAnRU5Ee3ByaW50IE5S
fScpIjsKCQlpZiBbICIkTlVNXzAwMSIgLWd0IDEgXTt0aGVuCgkJCWZvciAoKGk9MSA7IGk8PU5V
TV8wMDEgOyBpKyspKQoJCQlkbwoJCQkJVElNRV8wMDE9IiQoam91cm5hbGN0bCAtdSBzc2ggfGdy
ZXAgIiREQVRFXzAzIiB8Z3JlcCAiJDIiIHx0YWlsIC1uICIkaSIgfGhlYWQgLW4gMSB8YXdrICd7
IHByaW50ICQzIH0nIHxhd2sgLUY6ICd7IHByaW50ICQxJDIkMyB9JykiOwoJCQkJaWYgWyAiJFRJ
TUVfMDAxIiAtbHQgIiQzIiBdO3RoZW4KCQkJCQlUTVBfSEFOR18wMz0iJCgoaS0xKSkiOwoJCQkJ
CWJyZWFrOwoJCQkJZmkKCQkJZG9uZQoJCWVsc2UKCQkJTlVNXzAwND0iJChqb3VybmFsY3RsIC11
IHNzaCB8Z3JlcCAiJERBVEVfMDMiIHxncmVwICIkMiIgfGF3ayAneyBwcmludCAkMyB9JyB8YXdr
IC1GOiAneyBwcmludCAkMSQyJDMgfScpIjsKCQkJaWYgWyAiJE5VTV8wMDQiICE9ICIiIF0gXAoJ
CQkmJiBbICIkTlVNXzAwNCIgLWdlICIkMyIgXTt0aGVuCgkJCQlUTVBfSEFOR18wMz0xOwoJCQll
bHNlCgkJCQlUTVBfSEFOR18wMz0wOwoJCQlmaQoJCWZpCglmaQp9CgpFUlJPUl9USU1FUz01OwpE
QVRFXzAxPSIkKGRhdGUgKyIlYiAlZCIpIjsKQ1VSX1RJTUU9IiQoZGF0ZSArIiVUIikiOwpDVVJS
RU5UX1RJTUU9IiQoZGF0ZSArIiVIJU0lUyIpIjsKU1RBUlRfRkxBR18wMj0wOwoKaWYgWyAhIC1k
ICIkTE9HX0ZJTEVfRElSIiBdO3RoZW4KCW1rZGlyIC1wICIkTE9HX0ZJTEVfRElSIjsKZmkKCmlm
IFsgISAtZCAiJFNUT1JFX0ZJTEVfRElSIiBdO3RoZW4KCW1rZGlyIC1wICIkU1RPUkVfRklMRV9E
SVIiOwpmaQoKaWYgWyAiJChjYXQgL3RtcC9udW0wMikiIC1lcSAxIF07dGhlbgoJd2hpbGUgWyAi
JChjYXQgL3RtcC9udW0wMikiIC1lcSAxIF0KCWRvCgkJCgkJaWYgWyAiJFNUQVJUX0ZMQUciIC1l
cSAxIF07dGhlbgoJCQlwcmludGYgIuOAjFwwMzNbMzJtSU5GT1wwMzNbMG3jgI0gJENVUl9USU1F
OiDlvIDlp4vnm5HmjqcgICVzIOerr+WPo+OAglxuXDAzM1swbSIgIiQoZ3JlcCAiUG9ydCAiIC9l
dGMvc3NoL3NzaGRfY29uZmlnIHxhd2sgJ3sgcHJpbnQgJDIgfScpIjsKCQkJU1RBUlRfRkxBRz0w
OwoJCWZpCgoJCVNTSF9TVEFURT0iJChqb3VybmFsY3RsIC11IHNzaCB8Z3JlcCAiJERBVEVfMDEi
IHxncmVwICJTdG9wcGVkIHNzaC5zZXJ2aWNlIiB8YXdrICd7IHByaW50ICQzIH0nIHxhd2sgLUY6
ICd7IHByaW50ICQxJDIkMyB9JyB8dGFpbCAtbiAxKSI7CgkJaWYgWyAiJFNTSF9TVEFURSIgIT0g
IiIgXSBcCgkJJiYgWyAiJFNTSF9TVEFURSIgLWdlICIkQ1VSUkVOVF9USU1FIiBdO3RoZW4KCQkJ
cHJpbnRmICLjgIxcMDMzWzMzbVdBUk5cMDMzWzBt44CNICVzOiBcMDMzWzMzbeajgOa1i+WIsCBT
U0gg5pyN5Yqh5Ly85LmO6KKr5YWz6Zet5LqG77yM6K+356Gu6K6k5piv5ZCm5Ye6546w6Z2e6aKE
5pyf55qE5byC5bi444CCXG5cMDMzWzBtIiAiJENVUl9USU1FIjsKCQkJc2xlZXAgMnM7CgkJCWV4
aXQgMDIzOwoJCWZpCgoJCUFDQ0VQVF9JTj0iJChqb3VybmFsY3RsIC11IHNzaCB8Z3JlcCAiJERB
VEVfMDEiIHxncmVwIC12ICJBY2NlcHRlZCBwYXNzd29yZCIgfGdyZXAgLXYgJ1N0W2FvXVtycF1b
dHBdW2llXScgfGdyZXAgLXYgImxpc3RlbmluZyBvbiIpIjsKCQlpZiBbICIkKGVjaG8gIiRBQ0NF
UFRfSU4iIHx0YWlsIC1uIDEpIiAhPSAiIiBdO3RoZW4KCQkJaWYgWyAiJChlY2hvICIkQUNDRVBU
X0lOIiB8YXdrICd7IHByaW50ICQzIH0nIHxhd2sgLUY6ICd7IHByaW50ICQxJDIkMyB9JyB8dGFp
bCAtbiAxKSIgLWdlICIkQ1VSUkVOVF9USU1FIiBdO3RoZW4KCQkJCWlmIFsgIiRFUlJPUl9USU1F
UyIgLWdlIDUwIF07dGhlbgoJCQkJCXByaW50ZiAiXG7jgIxcMDMzWzMybUlORk9cMDMzWzBt44CN
ICVzOiDmo4DmtYvliLDmtYHph4/jgIJcblwwMzNbMG0iICIkQ1VSX1RJTUUiOwoJCQkJCUVSUk9S
X1RJTUVTPTA7CgkJCQlmaQoJCQkJU1RBUlRfRkxBR18wMj0xOwoJCQkJCgkJCQkjIEh5ZHJhIOe9
kee7nOeIhuegtOS7quebkea1iwoJCQkJaWYgWyAhIC1mICIkSFlEUkFfRklMRV9NQUlOIiBdO3Ro
ZW4KCQkJCQllY2hvIC1lICIjIOajgOa1i+WIsOeahCBIeWRyYSDnvZHnu5zniIbnoLTku6ogSVDv
vJpcbiIgPiIkSFlEUkFfRklMRV9NQUlOIjsKCQkJCWZpCgkJCQlpZiBbICIkKGpvdXJuYWxjdGwg
LXUgc3NoIHxncmVwICIkREFURV8wMSIgfGdyZXAgIkZhaWxlZCBwYXNzd29yZCBmb3IiIHx0YWls
IC1uIDEpIiAhPSAiIiBdIFwKCQkJCXx8IFsgIiQoam91cm5hbGN0bCAtdSBzc2ggfGdyZXAgIiRE
QVRFXzAxIiB8Z3JlcCAiYXV0aGVudGljYXRpb24gZmFpbHVyZSIgfHRhaWwgLW4gMSkiICE9ICIi
IF07dGhlbgoJCQkJCVRpbWVfQ29udHJhc3QgIiRTVEFSVF9GTEFHXzAyIiAiRmFpbGVkIHBhc3N3
b3JkIGZvciIgIiRDVVJSRU5UX1RJTUUiOwoJCQkJCVRpbWVfQ29udHJhc3RfMiAiJFNUQVJUX0ZM
QUdfMDIiICJhdXRoZW50aWNhdGlvbiBmYWlsdXJlIiAiJENVUlJFTlRfVElNRSI7CgkJCQkJaWYg
WyAiJFRNUF9IQU5HXzAxIiAhPSAwIF0gXAoJCQkJCXx8IFsgIiRUTVBfSEFOR18wMyIgIT0gMCBd
O3RoZW4KCQkJCQkJaWYgWyAiJFRNUF9IQU5HXzAxIiAtZ2UgMjAgXTt0aGVuCgkJCQkJCQlUTVBf
RkFJTF8wMT0iJChqb3VybmFsY3RsIC11IHNzaCB8Z3JlcCAiJERBVEVfMDEiIHxncmVwICJGYWls
ZWQgcGFzc3dvcmQgZm9yIiB8dGFpbCAtbiAiJFRNUF9IQU5HXzAxIiB8YXdrICd7IHByaW50ICQx
MSB9JyB8YXdrICchdmlzaXRlZFskMF0rKycgfGdyZXAgLXYgJ14kJykiOwoJCQkJCQkJRkFJTFVS
RT0xOwoJCQkJCQlmaQoJCQkJCQlpZiBbICIkVE1QX0hBTkdfMDMiIC1nZSAyMCBdO3RoZW4KCQkJ
CQkJCVRNUF9GQUlMXzAyPSIkKGpvdXJuYWxjdGwgLXUgc3NoIHxncmVwICIkREFURV8wMSIgIHxn
cmVwICJhdXRoZW50aWNhdGlvbiBmYWlsdXJlIiB8dGFpbCAtbiAiJFRNUF9IQU5HXzAzIiB8YXdr
IC1GJyByaG9zdD0nICd7IHByaW50ICQyIH0nIHxhd2sgJ3sgcHJpbnQgJDEgfScgfGF3ayAnIXZp
c2l0ZWRbJDBdKysnIHxncmVwIC12ICdeJCcpIjsKCQkJCQkJCUZBSUxVUkU9MTsKCQkJCQkJZmkK
CQkJCQkJaWYgWyAiJChqb3VybmFsY3RsIC11IHNzaCB8Z3JlcCAiJERBVEVfMDEiIHxncmVwICJl
cnJvcjogbWF4aW11bSBhdXRoZW50aWNhdGlvbiIgfHRhaWwgLW4gMSkiICE9ICIiIF07dGhlbgoJ
CQkJCQkJVGltZV9Db250cmFzdCAiJFNUQVJUX0ZMQUdfMDIiICJlcnJvcjogbWF4aW11bSBhdXRo
ZW50aWNhdGlvbiIgIiRDVVJSRU5UX1RJTUUiOwoJCQkJCQkJaWYgWyAiJFRNUF9IQU5HXzAxIiAt
Z2UgMTAgXTt0aGVuCgkJCQkJCQkJVE1QX0FUVEFDS18wMT0iJChqb3VybmFsY3RsIC11IHNzaCB8
Z3JlcCAiJERBVEVfMDEiIHxncmVwICJlcnJvcjogbWF4aW11bSBhdXRoZW50aWNhdGlvbiIgfHRh
aWwgLW4gIiRUTVBfSEFOR18wMSIgfGF3ayAneyBwcmludCAkMTQgfScgfGF3ayAnIXZpc2l0ZWRb
JDBdKysnIHxncmVwIC12ICdeJCcpIjsKCQkJCQkJCQlBVFRBQ0tFUj0xOwoJCQkJCQkJZmkKCQkJ
CQkJZmkKCQkJCQkJaWYgWyAiJEFUVEFDS0VSIiAtZXEgMSBdIFwKCQkJCQkJJiYgWyAiJEZBSUxV
UkUiIC1lcSAxIF07dGhlbgoJCQkJCQkJaWYgWyAiJFRNUF9GQUlMXzAxIiAhPSAiIiBdIFwKCQkJ
CQkJCSYmIFsgIiQoZWNobyAiJFRNUF9BVFRBQ0tfMDEiIHxncmVwIC12ICdeJCcgfGF3ayAnRU5E
e3ByaW50IE5SfScpIiAtZXEgIiQoZWNobyAiJFRNUF9GQUlMXzAxIiB8Z3JlcCAtdiAnXiQnIHxh
d2sgJ0VORHtwcmludCBOUn0nKSIgXTt0aGVuCgkJCQkJCQkJaWYgWyAiJFRNUF9GQUlMXzAxIiAh
PSAiIiBdIFwKCQkJCQkJCQkmJiBbICIkVE1QX0FUVEFDS18wMSIgPSAiJFRNUF9GQUlMXzAxIiBd
O3RoZW4KCQkJCQkJCQkJRVhJU1RFRF9BVFRBQ0tFUj0iJChncmVwIC12ICdeJCcgIiRIWURSQV9G
SUxFX01BSU4iKSI7CgkJCQkJCQkJCWlmIFsgIiQoZWNobyAiJEVYSVNURURfQVRUQUNLRVIiIHxn
cmVwIC12ICdeJCcgfGF3ayAnIXZpc2l0ZWRbJDBdKysnIHxhd2sgJ0VORHtwcmludCBOUn0nKSIg
LWVxICIkKGVjaG8gLWUgIiRFWElTVEVEX0FUVEFDS0VSXG4kVE1QX0FUVEFDS18wMSIgfGdyZXAg
LXYgJ14kJyB8YXdrICchdmlzaXRlZFskMF0rKycgfGF3ayAnRU5Ee3ByaW50IE5SfScpIiBdO3Ro
ZW4KCQkJCQkJCQkJCXByaW50ZiAiXDAzM1sxbeOAjFwwMzNbMTszMm1JTkZPXDAzM1sxOzM3beOA
jSAlczogXDAzM1szNG3mo4DmtYvliLDmnaXoh6ogJXMg55qE572R57uc54iG56C05pS75Ye777yI
MDHvvInjgIJcMDMzWzBtXG4iICIkQ1VSX1RJTUUiICIkVE1QX0FUVEFDS18wMSI7IAoJCQkJCQkJ
CQkJRVJST1JfMDE9MTsKCQkJCQkJCQkJZWxzZQoJCQkJCQkJCQkJcHJpbnRmICJcMDMzWzFt44CM
XDAzM1sxOzMybUlORk9cMDMzWzE7Mzdt44CNICVzOiBcMDMzWzM0beajgOa1i+WIsOadpeiHqiAl
cyDnmoTnvZHnu5zniIbnoLTmlLvlh7vvvIgwMe+8ieOAguW3suWwhuaUu+WHu+iAhWlw6K6w5b2V
5a2Y5qGj6IezJXPjgIJcMDMzWzBtXG4iICIkQ1VSX1RJTUUiICIkVE1QX0FUVEFDS18wMSIgIiRI
WURSQV9GSUxFX01BSU4iOwoJCQkJCQkJCQkJZWNobyAtZSAiJFRNUF9BVFRBQ0tfMDEiIHxncmVw
IC12ICIkRVhJU1RFRF9BVFRBQ0tFUiIgPj4iJEhZRFJBX0ZJTEVfTUFJTiI7CgkJCQkJCQkJCQlF
UlJPUl8wMT0xOwoJCQkJCQkJCQlmaQoJCQkJCQkJCQl1bnNldCBFWElTVEVEX0FUVEFDS0VSOwoJ
CQkJCQkJCWVsaWYgWyAiJFRNUF9GQUlMXzAxIiAhPSAiIiBdO3RoZW4KCQkJCQkJCQkJRVhJU1RF
RF9BVFRBQ0tFUj0iJChncmVwIC12ICdeJCcgIiRIWURSQV9GSUxFX01BSU4iKSI7CgkJCQkJCQkJ
CVNUQVJUX0ZMQUdfMDM9MDsKCQkJCQkJCQkJaWYgWyAiJChlY2hvICIkRVhJU1RFRF9BVFRBQ0tF
UiIgfGF3ayAnIXZpc2l0ZWRbJDBdKysnIHxhd2sgJ0VORHtwcmludCBOUn0nKSIgLWVxICIkKGVj
aG8gLWUgIiRFWElTVEVEX0FUVEFDS0VSXG4kVE1QX0FUVEFDS18wMSIgfGF3ayAnIXZpc2l0ZWRb
JDBdKysnIHxhd2sgJ0VORHtwcmludCBOUn0nKSIgXTt0aGVuCgkJCQkJCQkJCQlTVEFSVF9GTEFH
XzAzPSIkKChTVEFSVF9GTEFHXzAzKzEpKSI7CgkJCQkJCQkJCWZpCgkJCQkJCQkJCWlmIFsgIiQo
ZWNobyAiJEVYSVNURURfQVRUQUNLRVIiIHxhd2sgJyF2aXNpdGVkWyQwXSsrJyB8YXdrICdFTkR7
cHJpbnQgTlJ9JykiIC1lcSAiJChlY2hvIC1lICIkRVhJU1RFRF9BVFRBQ0tFUlxuJFRNUF9GQUlM
XzAxIiB8YXdrICchdmlzaXRlZFskMF0rKycgfGF3ayAnRU5Ee3ByaW50IE5SfScpIiBdO3RoZW4K
CQkJCQkJCQkJCVNUQVJUX0ZMQUdfMDM9IiQoKFNUQVJUX0ZMQUdfMDMrMikpIjsKCQkJCQkJCQkJ
ZmkKCQkJCQkJCQkJY2FzZSAkU1RBUlRfRkxBR18wMyBpbiAKCQkJCQkJCQkJCTApCgkJCQkJCQkJ
CQkJcHJpbnRmICJcMDMzWzFt44CMXDAzM1sxOzMybUlORk9cMDMzWzE7Mzdt44CNICVzOiBcMDMz
WzM0beajgOa1i+WIsOadpeiHqiAlcyDlkowgJXMg55qE572R57uc54iG56C05pS75Ye777yIMDLv
vInjgILlt7LlsIbmlLvlh7vogIVpcOiusOW9leWtmOaho+iHsyVz44CCXDAzM1swbVxuIiAiJENV
Ul9USU1FIiAiJFRNUF9BVFRBQ0tfMDEiICIkVE1QX0ZBSUxfMDEiICIkSFlEUkFfRklMRV9NQUlO
IjsKCQkJCQkJCQkJCQllY2hvIC1lICIkVE1QX0FUVEFDS18wMSIgfGdyZXAgLXYgIiRFWElTVEVE
X0FUVEFDS0VSIiA+PiIkSFlEUkFfRklMRV9NQUlOIjsKCQkJCQkJCQkJCQllY2hvIC1lICIkVE1Q
X0ZBSUxfMDEiIHxncmVwIC12ICIkRVhJU1RFRF9BVFRBQ0tFUiIgPj4iJEhZRFJBX0ZJTEVfTUFJ
TiI7CgkJCQkJCQkJCQkJRVJST1JfMDE9MTsKCQkJCQkJCQkJCTs7CgkJCQkJCQkJCQkKCQkJCQkJ
CQkJCTEpCgkJCQkJCQkJCQkJcHJpbnRmICJcMDMzWzFt44CMXDAzM1sxOzMybUlORk9cMDMzWzE7
Mzdt44CNICVzOiBcMDMzWzM0beajgOa1i+WIsOadpeiHqiAlcyDlkowgJXMg55qE572R57uc54iG
56C05pS75Ye777yIMDLvvInjgILlt7LlsIbmlLvlh7vogIVpcO+8iCVz77yJ6K6w5b2V5a2Y5qGj
6IezJXPjgIJcMDMzWzBtXG4iICIkQ1VSX1RJTUUiICIkVE1QX0FUVEFDS18wMSIgIiRUTVBfRkFJ
TF8wMSIgIiRUTVBfRkFJTF8wMSIgIiRIWURSQV9GSUxFX01BSU4iOwoJCQkJCQkJCQkJCWVjaG8g
LWUgIiRUTVBfRkFJTF8wMSIgfGdyZXAgLXYgIiRFWElTVEVEX0FUVEFDS0VSIiA+PiIkSFlEUkFf
RklMRV9NQUlOIjsKCQkJCQkJCQkJCQlFUlJPUl8wMT0xOwoJCQkJCQkJCQkJOzsKCQkJCQkJCQkJ
CQoJCQkJCQkJCQkJMikKCQkJCQkJCQkJCSAgcHJpbnRmICJcMDMzWzFt44CMXDAzM1sxOzMybUlO
Rk9cMDMzWzE7Mzdt44CNICVzOiBcMDMzWzM0beajgOa1i+WIsOadpeiHqiAlcyDlkowgJXMg55qE
572R57uc54iG56C05pS75Ye777yIMDLvvInjgILlt7LlsIbmlLvlh7vogIVpcO+8iCVz77yJ6K6w
5b2V5a2Y5qGj6IezJXPjgIJcMDMzWzBtXG4iICIkQ1VSX1RJTUUiICIkVE1QX0FUVEFDS18wMSIg
IiRUTVBfRkFJTF8wMSIgIiRUTVBfQVRUQUNLXzAxIiAiJEhZRFJBX0ZJTEVfTUFJTiI7CgkJCQkJ
CQkJCQkJZWNobyAtZSAiJFRNUF9BVFRBQ0tfMDEiIHxncmVwIC12ICIkRVhJU1RFRF9BVFRBQ0tF
UiIgPj4iJEhZRFJBX0ZJTEVfTUFJTiI7CgkJCQkJCQkJCQkJRVJST1JfMDE9MTsKCQkJCQkJCQkJ
CTs7CgkJCQkJCQkJCQkKCQkJCQkJCQkJCTMpCgkJCQkJCQkJCQkgIHByaW50ZiAiXDAzM1sxbeOA
jFwwMzNbMTszMm1JTkZPXDAzM1sxOzM3beOAjSAlczogXDAzM1szNG3mo4DmtYvliLDmnaXoh6og
JXMg5ZKMICVzIOeahOe9kee7nOeIhuegtOaUu+WHu++8iDAy77yJ44CCXDAzM1swbVxuIiAiJENV
Ul9USU1FIiAiJFRNUF9BVFRBQ0tfMDEiICIkVE1QX0ZBSUxfMDEiOwoJCQkJCQkJCQkJCUVSUk9S
XzAxPTE7CgkJCQkJCQkJCQk7OwoJCQkJCQkJCQkJCgkJCQkJCQkJCQkqKQoJCQkJCQkJCQkJCXBy
aW50ZiAiQW1hemluZy4uLiI7CgkJCQkJCQkJCQk7OwoJCQkJCQkJCQkJCgkJCQkJCQkJCWVzYWMK
CQkJCQkJCQkJdW5zZXQgRVhJU1RFRF9BVFRBQ0tFUjsKCQkJCQkJCQlmaQoJCQkJCQkJZWxpZiBb
ICIkVE1QX0ZBSUxfMDIiICE9ICIiIF0gXAoJCQkJCQkJJiYgWyAiJChlY2hvICIkVE1QX0FUVEFD
S18wMSIgfGdyZXAgLXYgJ14kJyB8YXdrICdFTkR7cHJpbnQgTlJ9JykiIC1lcSAiJChlY2hvICIk
VE1QX0ZBSUxfMDIiIHxncmVwIC12ICdeJCcgfGF3ayAnRU5Ee3ByaW50IE5SfScpIiBdO3RoZW4K
CQkJCQkJCQlpZiBbICIkVE1QX0ZBSUxfMDIiICE9ICIiIF0gXAoJCQkJCQkJCSYmIFsgIiRUTVBf
QVRUQUNLXzAxIiA9ICIkVE1QX0ZBSUxfMDIiIF07dGhlbgoJCQkJCQkJCQlFWElTVEVEX0FUVEFD
S0VSPSIkKGdyZXAgLXYgJ14kJyAiJEhZRFJBX0ZJTEVfTUFJTiIpIjsKCQkJCQkJCQkJaWYgWyAi
JChlY2hvICIkRVhJU1RFRF9BVFRBQ0tFUiIgfGdyZXAgLXYgJ14kJyB8YXdrICchdmlzaXRlZFsk
MF0rKycgfGF3ayAnRU5Ee3ByaW50IE5SfScpIiAtZXEgIiQoZWNobyAtZSAiJEVYSVNURURfQVRU
QUNLRVJcbiRUTVBfQVRUQUNLXzAxIiB8Z3JlcCAtdiAnXiQnIHxhd2sgJyF2aXNpdGVkWyQwXSsr
JyB8YXdrICdFTkR7cHJpbnQgTlJ9JykiIF07dGhlbgoJCQkJCQkJCQkJcHJpbnRmICJcMDMzWzFt
44CMXDAzM1sxOzMybUlORk9cMDMzWzE7Mzdt44CNICVzOiBcMDMzWzM0beajgOa1i+WIsOadpeiH
qiAlcyDnmoTnvZHnu5zniIbnoLTmlLvlh7vvvIgwM++8ieOAglwwMzNbMG1cbiIgIiRDVVJfVElN
RSIgIiRUTVBfQVRUQUNLXzAxIjsKCQkJCQkJCQkJCUVSUk9SXzAxPTE7CgkJCQkJCQkJCWVsc2UK
CQkJCQkJCQkJCXByaW50ZiAiXDAzM1sxbeOAjFwwMzNbMTszMm1JTkZPXDAzM1sxOzM3beOAjSAl
czogXDAzM1szNG3mo4DmtYvliLDmnaXoh6ogJXMg55qE572R57uc54iG56C05pS75Ye777yIMDPv
vInjgILlt7LlsIbmlLvlh7vogIVpcOiusOW9leWtmOaho+iHsyVz44CCXDAzM1swbVxuIiAiJENV
Ul9USU1FIiAiJFRNUF9BVFRBQ0tfMDEiICIkSFlEUkFfRklMRV9NQUlOIjsKCQkJCQkJCQkJCWVj
aG8gLWUgIiRUTVBfQVRUQUNLXzAxIiB8Z3JlcCAtdiAiJEVYSVNURURfQVRUQUNLRVIiID4+IiRI
WURSQV9GSUxFX01BSU4iOwoJCQkJCQkJCQkJRVJST1JfMDE9MTsKCQkJCQkJCQkJZmkKCQkJCQkJ
CQkJdW5zZXQgRVhJU1RFRF9BVFRBQ0tFUjsKCQkJCQkJCQllbGlmIFsgIiRUTVBfRkFJTF8wMiIg
IT0gIiIgXTt0aGVuCgkJCQkJCQkJCUVYSVNURURfQVRUQUNLRVI9IiQoZ3JlcCAtdiAnXiQnICIk
SFlEUkFfRklMRV9NQUlOIikiOwoJCQkJCQkJCQlTVEFSVF9GTEFHXzAzPTA7CgkJCQkJCQkJCWlm
IFsgIiQoZWNobyAiJEVYSVNURURfQVRUQUNLRVIiIHxhd2sgJyF2aXNpdGVkWyQwXSsrJyB8YXdr
ICdFTkR7cHJpbnQgTlJ9JykiIC1lcSAiJChlY2hvIC1lICIkRVhJU1RFRF9BVFRBQ0tFUlxuJFRN
UF9BVFRBQ0tfMDEiIHxhd2sgJyF2aXNpdGVkWyQwXSsrJyB8YXdrICdFTkR7cHJpbnQgTlJ9Jyki
IF07dGhlbgoJCQkJCQkJCQkJU1RBUlRfRkxBR18wMz0iJCgoU1RBUlRfRkxBR18wMysxKSkiOwoJ
CQkJCQkJCQlmaQoJCQkJCQkJCQlpZiBbICIkKGVjaG8gIiRFWElTVEVEX0FUVEFDS0VSIiB8YXdr
ICchdmlzaXRlZFskMF0rKycgfGF3ayAnRU5Ee3ByaW50IE5SfScpIiAtZXEgIiQoZWNobyAtZSAi
JEVYSVNURURfQVRUQUNLRVJcbiRUTVBfRkFJTF8wMiIgfGF3ayAnIXZpc2l0ZWRbJDBdKysnIHxh
d2sgJ0VORHtwcmludCBOUn0nKSIgXTt0aGVuCgkJCQkJCQkJCQlTVEFSVF9GTEFHXzAzPSIkKChT
VEFSVF9GTEFHXzAzKzIpKSI7CgkJCQkJCQkJCWZpCgkJCQkJCQkJCWNhc2UgJFNUQVJUX0ZMQUdf
MDMgaW4gCgkJCQkJCQkJCQkwKQoJCQkJCQkJCQkJCXByaW50ZiAiXDAzM1sxbeOAjFwwMzNbMTsz
Mm1JTkZPXDAzM1sxOzM3beOAjSAlczogXDAzM1szNG3mo4DmtYvliLDmnaXoh6ogJXMg5ZKMICVz
IOeahOe9kee7nOeIhuegtOaUu+WHu++8iDA077yJ44CC5bey5bCG5pS75Ye76ICFaXDorrDlvZXl
rZjmoaPoh7Mlc+OAglwwMzNbMG1cbiIgIiRDVVJfVElNRSIgIiRUTVBfQVRUQUNLXzAxIiAiJFRN
UF9GQUlMXzAyIiAiJEhZRFJBX0ZJTEVfTUFJTiI7CgkJCQkJCQkJCQkJZWNobyAtZSAiJFRNUF9B
VFRBQ0tfMDEiIHxncmVwIC12ICIkRVhJU1RFRF9BVFRBQ0tFUiIgPj4iJEhZRFJBX0ZJTEVfTUFJ
TiI7CgkJCQkJCQkJCQkJZWNobyAtZSAiJFRNUF9GQUlMXzAyIiB8Z3JlcCAtdiAiJEVYSVNURURf
QVRUQUNLRVIiID4+IiRIWURSQV9GSUxFX01BSU4iOwoJCQkJCQkJCQkJCUVSUk9SXzAxPTE7CgkJ
CQkJCQkJCQk7OwoJCQkJCQkJCQkJCgkJCQkJCQkJCQkxKQoJCQkJCQkJCQkJCXByaW50ZiAiXDAz
M1sxbeOAjFwwMzNbMTszMm1JTkZPXDAzM1sxOzM3beOAjSAlczogXDAzM1szNG3mo4DmtYvliLDm
naXoh6ogJXMg5ZKMICVzIOeahOe9kee7nOeIhuegtOaUu+WHu++8iDA077yJ44CC5bey5bCG5pS7
5Ye76ICFaXDvvIglc++8ieiusOW9leWtmOaho+iHsyVz44CCXDAzM1swbVxuIiAiJENVUl9USU1F
IiAiJFRNUF9BVFRBQ0tfMDEiICIkVE1QX0ZBSUxfMDIiICIkVE1QX0ZBSUxfMDIiICIkSFlEUkFf
RklMRV9NQUlOIjsKCQkJCQkJCQkJCQllY2hvIC1lICIkVE1QX0ZBSUxfMDIiIHxncmVwIC12ICIk
RVhJU1RFRF9BVFRBQ0tFUiIgPj4iJEhZRFJBX0ZJTEVfTUFJTiI7CgkJCQkJCQkJCQkJRVJST1Jf
MDE9MTsKCQkJCQkJCQkJCTs7CgkJCQkJCQkJCQkKCQkJCQkJCQkJCTIpCgkJCQkJCQkJCQkgIHBy
aW50ZiAiXDAzM1sxbeOAjFwwMzNbMTszMm1JTkZPXDAzM1sxOzM3beOAjSAlczogXDAzM1szNG3m
o4DmtYvliLDmnaXoh6ogJXMg5ZKMICVzIOeahOe9kee7nOeIhuegtOaUu+WHu++8iDA077yJ44CC
5bey5bCG5pS75Ye76ICFaXDvvIglc++8ieiusOW9leWtmOaho+iHsyVz44CCXDAzM1swbVxuIiAi
JENVUl9USU1FIiAiJFRNUF9BVFRBQ0tfMDEiICIkVE1QX0ZBSUxfMDIiICIkVE1QX0FUVEFDS18w
MSIgIiRIWURSQV9GSUxFX01BSU4iOwoJCQkJCQkJCQkJCWVjaG8gLWUgIiRUTVBfQVRUQUNLXzAx
IiB8Z3JlcCAtdiAiJEVYSVNURURfQVRUQUNLRVIiID4+IiRIWURSQV9GSUxFX01BSU4iOwoJCQkJ
CQkJCQkJCUVSUk9SXzAxPTE7CgkJCQkJCQkJCQk7OwoJCQkJCQkJCQkJCgkJCQkJCQkJCQkzKQoJ
CQkJCQkJCQkJCXByaW50ZiAiXDAzM1sxbeOAjFwwMzNbMTszMm1JTkZPXDAzM1sxOzM3beOAjSAl
czogXDAzM1szNG3mo4DmtYvliLDmnaXoh6ogJXMg5ZKMICVzIOeahOe9kee7nOeIhuegtOaUu+WH
u++8iDA077yJ44CCXDAzM1swbVxuIiAiJENVUl9USU1FIiAiJFRNUF9BVFRBQ0tfMDEiICIkVE1Q
X0ZBSUxfMDIiOwoJCQkJCQkJCQkJCUVSUk9SXzAxPTE7CgkJCQkJCQkJCQk7OwoJCQkJCQkJCQkJ
CgkJCQkJCQkJCQkqKQoJCQkJCQkJCQkJCXByaW50ZiAiQW1hemluZy4uLiI7CgkJCQkJCQkJCQk7
OwoJCQkJCQkJCQkJCgkJCQkJCQkJCWVzYWMKCQkJCQkJCQkJdW5zZXQgRVhJU1RFRF9BVFRBQ0tF
UjsKCQkJCQkJCQlmaQoJCQkJCQkJZWxpZiBbICIkKGVjaG8gIiRUTVBfQVRUQUNLXzAxIiB8Z3Jl
cCAtdiAnXiQnIHxhd2sgJ0VORHtwcmludCBOUn0nKSIgLWVxIDAgXSBcCgkJCQkJCQkmJiBbICIk
KGVjaG8gIiRUTVBfRkFJTF8wMSIgfGdyZXAgLXYgJ14kJyB8YXdrICdFTkR7cHJpbnQgTlJ9Jyki
IC1lcSAwIF0gXAoJCQkJCQkJJiYgWyAiJChlY2hvICIkVE1QX0ZBSUxfMDIiIHxncmVwIC12ICde
JCcgfGF3ayAnRU5Ee3ByaW50IE5SfScpIiAtZXEgMCBdO3RoZW4KCQkJCQkJCQlwcmludGYgIuOA
jFwwMzNbMzNtV0FSTlwwMzNbMG3jgI0gJXM6IFwwMzNbMzNt5qOA5rWL5Yiw572R57uc54iG56C0
5pS75Ye777yM5L2G5peg5rOV56Gu5a6a5pS75Ye76ICF77yIMDXvvInjgIJcMDMzWzBtXG4iICIk
Q1VSX1RJTUUiOwoJCQkJCQkJCUVSUk9SXzAxPTE7CgkJCQkJCQllbHNlCgkJCQkJCQkJaWYgWyAi
JFRNUF9GQUlMXzAxIiAhPSAiIiBdO3RoZW4KCQkJCQkJCQkJRVhJU1RFRF9BVFRBQ0tFUj0iJChn
cmVwIC12ICdeJCcgIiRIWURSQV9GSUxFX01BSU4iKSI7CgkJCQkJCQkJCWlmIFsgIiQoZWNobyAi
JEVYSVNURURfQVRUQUNLRVIiIHxncmVwIC12ICdeJCcgfGF3ayAnIXZpc2l0ZWRbJDBdKysnIHxh
d2sgJ0VORHtwcmludCBOUn0nKSIgLWVxICIkKGVjaG8gLWUgIiRFWElTVEVEX0FUVEFDS0VSXG4k
VE1QX0ZBSUxfMDEiIHxncmVwIC12ICdeJCcgfGF3ayAnIXZpc2l0ZWRbJDBdKysnIHxhd2sgJ0VO
RHtwcmludCBOUn0nKSIgXTt0aGVuCgkJCQkJCQkJCQlwcmludGYgIuOAjFwwMzNbMzJtSU5GT1ww
MzNbMG3jgI0gJXM6IFwwMzNbMzRt5qOA5rWL5Yiw5p2l6IeqICVzIOeahOe9kee7nOeIhuegtOaU
u+WHu++8iDA277yJ44CCXDAzM1swbVxuIiAiJENVUl9USU1FIiAiJFRNUF9GQUlMXzAxIjsKCQkJ
CQkJCQkJCUVSUk9SXzAxPTE7CgkJCQkJCQkJCWVsc2UKCQkJCQkJCQkJCXByaW50ZiAi44CMXDAz
M1szMm1JTkZPXDAzM1swbeOAjSAlczogXDAzM1szNG3mo4DmtYvliLDmnaXoh6ogJXMg55qE572R
57uc54iG56C05pS75Ye777yIMDbvvInjgILlt7LlsIbmlLvlh7vogIVpcOiusOW9leWtmOaho+iH
syVz44CCXDAzM1swbVxuIiAiJENVUl9USU1FIiAiJFRNUF9GQUlMXzAxIiAiJEhZRFJBX0ZJTEVf
TUFJTiI7CgkJCQkJCQkJCQllY2hvIC1lICIkVE1QX0ZBSUxfMDEiIHxncmVwIC12ICIkRVhJU1RF
RF9BVFRBQ0tFUiIgPj4iJEhZRFJBX0ZJTEVfTUFJTiI7CgkJCQkJCQkJCQlFUlJPUl8wMT0xOwoJ
CQkJCQkJCQlmaQoJCQkJCQkJCQl1bnNldCBFWElTVEVEX0FUVEFDS0VSOwoJCQkJCQkJCWVsaWYg
WyAiJFRNUF9GQUlMXzAyIiAhPSAiIiBdO3RoZW4KCQkJCQkJCQkJRVhJU1RFRF9BVFRBQ0tFUj0i
JChncmVwIC12ICdeJCcgIiRIWURSQV9GSUxFX01BSU4iKSI7CgkJCQkJCQkJCWlmIFsgIiQoZWNo
byAiJEVYSVNURURfQVRUQUNLRVIiIHxncmVwIC12ICdeJCcgfGF3ayAnIXZpc2l0ZWRbJDBdKysn
IHxhd2sgJ0VORHtwcmludCBOUn0nKSIgLWVxICIkKGVjaG8gLWUgIiRFWElTVEVEX0FUVEFDS0VS
XG4kVE1QX0ZBSUxfMDIiIHxncmVwIC12ICdeJCcgfGF3ayAnIXZpc2l0ZWRbJDBdKysnIHxhd2sg
J0VORHtwcmludCBOUn0nKSIgXTt0aGVuCgkJCQkJCQkJCQlwcmludGYgIuOAjFwwMzNbMzJtSU5G
T1wwMzNbMG3jgI0gJXM6IFwwMzNbMzRt5qOA5rWL5Yiw5p2l6IeqICVzIOeahOe9kee7nOeIhueg
tOaUu+WHu++8iDA377yJ44CCXDAzM1swbVxuIiAiJENVUl9USU1FIiAiJFRNUF9GQUlMXzAyIjsK
CQkJCQkJCQkJCUVSUk9SXzAxPTE7CgkJCQkJCQkJCWVsc2UKCQkJCQkJCQkJCXByaW50ZiAi44CM
XDAzM1szMm1JTkZPXDAzM1swbeOAjSAlczogXDAzM1szNG3mo4DmtYvliLDmnaXoh6ogJXMg55qE
572R57uc54iG56C05pS75Ye777yIMDfvvInjgILlt7LlsIbmlLvlh7vogIVpcOiusOW9leWtmOah
o+iHsyVz44CCXDAzM1swbVxuIiAiJENVUl9USU1FIiAiJFRNUF9GQUlMXzAyIiAiJEhZRFJBX0ZJ
TEVfTUFJTiI7CgkJCQkJCQkJCQllY2hvIC1lICIkVE1QX0ZBSUxfMDIiIHxncmVwIC12ICIkRVhJ
U1RFRF9BVFRBQ0tFUiIgPj4iJEhZRFJBX0ZJTEVfTUFJTiI7CgkJCQkJCQkJCQlFUlJPUl8wMT0x
OwoJCQkJCQkJCQlmaQoJCQkJCQkJCQl1bnNldCBFWElTVEVEX0FUVEFDS0VSOwoJCQkJCQkJCWVs
aWYgWyAiJFRNUF9GQUlMXzAyIiAhPSAiIiBdIFwKCQkJCQkJCQkmJiBbICIkVE1QX0ZBSUxfMDEi
ICE9ICIiIF07dGhlbgoJCQkJCQkJCQlFWElTVEVEX0FUVEFDS0VSPSIkKGdyZXAgLXYgJ14kJyAi
JEhZRFJBX0ZJTEVfTUFJTiIpIjsKCQkJCQkJCQkJU1RBUlRfRkxBR18wMz0wOwoJCQkJCQkJCQlp
ZiBbICIkKGVjaG8gIiRFWElTVEVEX0FUVEFDS0VSIiB8Z3JlcCAtdiAnXiQnIHxhd2sgJyF2aXNp
dGVkWyQwXSsrJyB8YXdrICdFTkR7cHJpbnQgTlJ9JykiIC1lcSAiJChlY2hvIC1lICIkRVhJU1RF
RF9BVFRBQ0tFUlxuJFRNUF9GQUlMXzAxIiB8Z3JlcCAtdiAnXiQnIHxhd2sgJyF2aXNpdGVkWyQw
XSsrJyB8YXdrICdFTkR7cHJpbnQgTlJ9JykiIF07dGhlbgoJCQkJCQkJCQkJU1RBUlRfRkxBR18w
Mz0iJCgoU1RBUlRfRkxBR18wMysxKSkiOwoJCQkJCQkJCQlmaQoJCQkJCQkJCQlpZiBbICIkKGVj
aG8gIiRFWElTVEVEX0FUVEFDS0VSIiB8Z3JlcCAtdiAnXiQnIHxhd2sgJyF2aXNpdGVkWyQwXSsr
JyB8YXdrICdFTkR7cHJpbnQgTlJ9JykiIC1lcSAiJChlY2hvIC1lICIkRVhJU1RFRF9BVFRBQ0tF
UlxuJFRNUF9GQUlMXzAyIiB8Z3JlcCAtdiAnXiQnIHxhd2sgJyF2aXNpdGVkWyQwXSsrJyB8YXdr
ICdFTkR7cHJpbnQgTlJ9JykiIF07dGhlbgoJCQkJCQkJCQkJU1RBUlRfRkxBR18wMz0iJCgoU1RB
UlRfRkxBR18wMysyKSkiOwoJCQkJCQkJCQlmaQoJCQkJCQkJCQlpZiBbICIkKGVjaG8gIiRUTVBf
RkFJTF8wMSIgfGdyZXAgLXYgJ14kJyB8YXdrICchdmlzaXRlZFskMF0rKycgfGF3ayAnRU5Ee3By
aW50IE5SfScpIiAtZXEgIiQoZWNobyAtZSAiJFRNUF9GQUlMXzAxXG4kVE1QX0ZBSUxfMDIiIHxn
cmVwIC12ICdeJCcgfGF3ayAnIXZpc2l0ZWRbJDBdKysnIHxhd2sgJ0VORHtwcmludCBOUn0nKSIg
XTt0aGVuCgkJCQkJCQkJCQlTVEFSVF9GTEFHXzAzPSIkKChTVEFSVF9GTEFHXzAzKzQpKSI7CgkJ
CQkJCQkJCWZpCgkJCQkJCQkJCWNhc2UgJFNUQVJUX0ZMQUdfMDMgaW4gCgkJCQkJCQkJCQkwKQoJ
CQkJCQkJCQkJCXByaW50ZiAiXDAzM1sxbeOAjFwwMzNbMTszMm1JTkZPXDAzM1sxOzM3beOAjSAl
czogXDAzM1szNG3mo4DmtYvliLDmnaXoh6ogJXMg5ZKMICVzIOeahOe9kee7nOeIhuegtOaUu+WH
u++8iDA477yJ44CC5bey5bCG5pS75Ye76ICFaXDorrDlvZXlrZjmoaPoh7Mlc+OAglwwMzNbMG1c
biIgIiRDVVJfVElNRSIgIiRUTVBfRkFJTF8wMSIgIiRUTVBfRkFJTF8wMiIgIiRIWURSQV9GSUxF
X01BSU4iOwoJCQkJCQkJCQkJCWVjaG8gLWUgIiRUTVBfRkFJTF8wMSJ8Z3JlcCAtdiAiJEVYSVNU
RURfQVRUQUNLRVIiID4+IiRIWURSQV9GSUxFX01BSU4iOwoJCQkJCQkJCQkJCWVjaG8gLWUgIiRU
TVBfRkFJTF8wMiIgfGdyZXAgLXYgIiRFWElTVEVEX0FUVEFDS0VSIiA+PiIkSFlEUkFfRklMRV9N
QUlOIjsKCQkJCQkJCQkJCQlFUlJPUl8wMT0xOwoJCQkJCQkJCQkJOzsKCQkJCQkJCQkJCQoJCQkJ
CQkJCQkJMSkKCQkJCQkJCQkJCQlwcmludGYgIlwwMzNbMW3jgIxcMDMzWzE7MzJtSU5GT1wwMzNb
MTszN23jgI0gJXM6IFwwMzNbMzRt5qOA5rWL5Yiw5p2l6IeqICVzIOWSjCAlcyDnmoTnvZHnu5zn
iIbnoLTmlLvlh7vvvIgwOO+8ieOAguW3suWwhuaUu+WHu+iAhWlw77yIJXPvvInorrDlvZXlrZjm
oaPoh7Mlc+OAglwwMzNbMG1cbiIgIiRDVVJfVElNRSIgIiRUTVBfRkFJTF8wMSIgIiRUTVBfRkFJ
TF8wMiIgIiRUTVBfRkFJTF8wMiIgIiRIWURSQV9GSUxFX01BSU4iOwoJCQkJCQkJCQkJCWVjaG8g
LWUgIiRUTVBfRkFJTF8wMiIgfGdyZXAgLXYgIiRFWElTVEVEX0FUVEFDS0VSIiA+PiIkSFlEUkFf
RklMRV9NQUlOIjsKCQkJCQkJCQkJCQlFUlJPUl8wMT0xOwoJCQkJCQkJCQkJOzsKCQkJCQkJCQkJ
CQoJCQkJCQkJCQkJMikKCQkJCQkJCQkJCQlwcmludGYgIlwwMzNbMW3jgIxcMDMzWzE7MzJtSU5G
T1wwMzNbMTszN23jgI0gJXM6IFwwMzNbMzRt5qOA5rWL5Yiw5p2l6IeqICVzIOWSjCAlcyDnmoTn
vZHnu5zniIbnoLTmlLvlh7vvvIgwOO+8ieOAguW3suWwhuaUu+WHu+iAhWlw77yIJXPvvInorrDl
vZXlrZjmoaPoh7Mlc+OAglwwMzNbMG1cbiIgIiRDVVJfVElNRSIgIiRUTVBfRkFJTF8wMSIgIiRU
TVBfRkFJTF8wMiIgIiRUTVBfRkFJTF8wMSIgIiRIWURSQV9GSUxFX01BSU4iOwoJCQkJCQkJCQkJ
CWVjaG8gLWUgIiRUTVBfRkFJTF8wMSIgfGdyZXAgLXYgIiRFWElTVEVEX0FUVEFDS0VSIiA+PiIk
SFlEUkFfRklMRV9NQUlOIjsKCQkJCQkJCQkJCQlFUlJPUl8wMT0xOwoJCQkJCQkJCQkJOzsKCQkJ
CQkJCQkJCQoJCQkJCQkJCQkJIzMpCgkJCQkJCQkJCQkjCXByaW50ZiAiXDAzM1sxbeOAjFwwMzNb
MTszMm1JTkZPXDAzM1sxOzM3beOAjSAlczogXDAzM1szNG3mo4DmtYvliLDmnaXoh6ogJXMg5ZKM
ICVzIOeahOe9kee7nOeIhuegtOaUu+WHu+OAglwwMzNbMG1cbiIgIiRDVVJfVElNRSIgIiRUTVBf
RkFJTF8wMSIgIiRUTVBfRkFJTF8wMiI7CgkJCQkJCQkJCQkjCUVSUk9SXzAxPTE7CgkJCQkJCQkJ
CQkjOzsKCQkJCQkJCQkJCQoJCQkJCQkJCQkJNCkKCQkJCQkJCQkJCQlwcmludGYgIlwwMzNbMW3j
gIxcMDMzWzE7MzJtSU5GT1wwMzNbMTszN23jgI0gJXM6IFwwMzNbMzRt5qOA5rWL5Yiw5p2l6Ieq
ICVzIOeahOe9kee7nOeIhuegtOaUu+WHu++8iDA477yJ44CC5bey5bCG5pS75Ye76ICFaXDorrDl
vZXlrZjmoaPoh7Mlc+OAglwwMzNbMG1cbiIgIiRDVVJfVElNRSIgIiRUTVBfRkFJTF8wMSIgIiRI
WURSQV9GSUxFX01BSU4iOwoJCQkJCQkJCQkJCWVjaG8gLWUgIiRUTVBfRkFJTF8wMSJ8Z3JlcCAt
diAiJEVYSVNURURfQVRUQUNLRVIiID4+IiRIWURSQV9GSUxFX01BSU4iOwoJCQkJCQkJCQkJCUVS
Uk9SXzAxPTE7CgkJCQkJCQkJCQk7OwoJCQkJCQkJCQkJCgkJCQkJCQkJCQkjNSkKCQkJCQkJCQkJ
CSMJcHJpbnRmICJcMDMzWzFt44CMXDAzM1sxOzMybUlORk9cMDMzWzE7Mzdt44CNICVzOiBcMDMz
WzM0beajgOa1i+WIsOadpeiHqiAlcyDlkowgJXMg55qE572R57uc54iG56C05pS75Ye744CCXDAz
M1swbVxuIiAiJENVUl9USU1FIiAiJFRNUF9GQUlMXzAxIiAiJFRNUF9GQUlMXzAyIjsKCQkJCQkJ
CQkJCSMJRVJST1JfMDE9MTsKCQkJCQkJCQkJCSM7OwoJCQkJCQkJCQkJCgkJCQkJCQkJCQkjNikK
CQkJCQkJCQkJCSMJcHJpbnRmICJcMDMzWzFt44CMXDAzM1sxOzMybUlORk9cMDMzWzE7Mzdt44CN
ICVzOiBcMDMzWzM0beajgOa1i+WIsOadpeiHqiAlcyDlkowgJXMg55qE572R57uc54iG56C05pS7
5Ye744CCXDAzM1swbVxuIiAiJENVUl9USU1FIiAiJFRNUF9GQUlMXzAxIiAiJFRNUF9GQUlMXzAy
IjsKCQkJCQkJCQkJCSMgRVJST1JfMDE9MTsKCQkJCQkJCQkJCSM7OwoJCQkJCQkJCQkJCgkJCQkJ
CQkJCQk3KQoJCQkJCQkJCQkJCXByaW50ZiAiXDAzM1sxbeOAjFwwMzNbMTszMm1JTkZPXDAzM1sx
OzM3beOAjSAlczogXDAzM1szNG3mo4DmtYvliLDmnaXoh6ogJXMg55qE572R57uc54iG56C05pS7
5Ye777yIMDjvvInjgIJcMDMzWzBtXG4iICIkQ1VSX1RJTUUiICIkVE1QX0ZBSUxfMDEiOwoJCQkJ
CQkJCQkJCUVSUk9SXzAxPTE7CgkJCQkJCQkJCQk7OwoJCQkJCQkJCQkJCgkJCQkJCQkJCQkqKQoJ
CQkJCQkJCQkJCXByaW50ZiAiQW1hemluZy4uLiI7CgkJCQkJCQkJCQk7OwoJCQkJCQkJCQkJCgkJ
CQkJCQkJCWVzYWMKCQkJCQkJCQkJdW5zZXQgRVhJU1RFRF9BVFRBQ0tFUjsKCQkJCQkJCQlmaQoJ
CQkJCQkJZmkKCQkJCQkJZWxpZiBbICIkQVRUQUNLRVIiIC1lcSAwIF0gXAoJCQkJCQkmJiBbICIk
RkFJTFVSRSIgLWVxIDEgXTt0aGVuCgkJCQkJCQlFWElTVEVEX0FUVEFDS0VSPSIkKGdyZXAgLXYg
J14kJyAiJEhZRFJBX0ZJTEVfTUFJTiIpIjsKCQkJCQkJCWlmIFsgIiRUTVBfRkFJTF8wMSIgIT0g
IiIgXTt0aGVuCgkJCQkJCQkJaWYgWyAiJChlY2hvICIkRVhJU1RFRF9BVFRBQ0tFUiIgfGdyZXAg
LXYgJ14kJyB8YXdrICchdmlzaXRlZFskMF0rKycgfGF3ayAnRU5Ee3ByaW50IE5SfScpIiAtZXEg
IiQoZWNobyAtZSAiJEVYSVNURURfQVRUQUNLRVJcbiRUTVBfRkFJTF8wMSIgfGdyZXAgLXYgJ14k
JyB8YXdrICchdmlzaXRlZFskMF0rKycgfGF3ayAnRU5Ee3ByaW50IE5SfScpIiBdO3RoZW4KCQkJ
CQkJCQkJcHJpbnRmICLjgIxcMDMzWzMybUlORk9cMDMzWzBt44CNICVzOiBcMDMzWzM0beajgOa1
i+WIsOadpeiHqiAlcyDnmoTnvZHnu5zniIbnoLTmlLvlh7vvvIgwOe+8ieOAglwwMzNbMG1cbiIg
IiRDVVJfVElNRSIgIiRUTVBfRkFJTF8wMSI7CgkJCQkJCQkJCUVSUk9SXzAxPTE7CgkJCQkJCQkJ
ZWxzZQoJCQkJCQkJCQlwcmludGYgIuOAjFwwMzNbMzJtSU5GT1wwMzNbMG3jgI0gJXM6IFwwMzNb
MzRt5qOA5rWL5Yiw5p2l6IeqICVzIOeahOe9kee7nOeIhuegtOaUu+WHu++8iDA577yJ44CC5bey
5bCG5pS75Ye76ICFaXDorrDlvZXlrZjmoaPoh7Mlc+OAglwwMzNbMG1cbiIgIiRDVVJfVElNRSIg
IiRUTVBfRkFJTF8wMSIgIiRIWURSQV9GSUxFX01BSU4iOwoJCQkJCQkJCQllY2hvIC1lICIkVE1Q
X0ZBSUxfMDEiIHxncmVwIC12ICIkRVhJU1RFRF9BVFRBQ0tFUiIgPj4iJEhZRFJBX0ZJTEVfTUFJ
TiI7CgkJCQkJCQkJCUVSUk9SXzAxPTE7CgkJCQkJCQkJZmkKCQkJCQkJCWVsaWYgWyAiJFRNUF9G
QUlMXzAyIiAhPSAiIiBdO3RoZW4KCQkJCQkJCQlpZiBbICIkKGVjaG8gIiRFWElTVEVEX0FUVEFD
S0VSIiB8Z3JlcCAtdiAnXiQnIHxhd2sgJyF2aXNpdGVkWyQwXSsrJyB8YXdrICdFTkR7cHJpbnQg
TlJ9JykiIC1lcSAiJChlY2hvIC1lICIkRVhJU1RFRF9BVFRBQ0tFUlxuJFRNUF9GQUlMXzAyIiB8
Z3JlcCAtdiAnXiQnIHxhd2sgJyF2aXNpdGVkWyQwXSsrJyB8YXdrICdFTkR7cHJpbnQgTlJ9Jyki
IF07dGhlbgoJCQkJCQkJCQlwcmludGYgIuOAjFwwMzNbMzJtSU5GT1wwMzNbMG3jgI0gJXM6IFww
MzNbMzRt5qOA5rWL5Yiw5p2l6IeqICVzIOeahOe9kee7nOeIhuegtOaUu+WHu++8iDEw77yJ44CC
XDAzM1swbVxuIiAiJENVUl9USU1FIiAiJFRNUF9GQUlMXzAyIjsKCQkJCQkJCQkJRVJST1JfMDE9
MTsKCQkJCQkJCQllbHNlCgkJCQkJCQkJCXByaW50ZiAi44CMXDAzM1szMm1JTkZPXDAzM1swbeOA
jSAlczogXDAzM1szNG3mo4DmtYvliLDmnaXoh6ogJXMg55qE572R57uc54iG56C05pS75Ye777yI
MTDvvInjgILlt7LlsIbmlLvlh7vogIVpcOiusOW9leWtmOaho+iHsyVz44CCXDAzM1swbVxuIiAi
JENVUl9USU1FIiAiJFRNUF9GQUlMXzAyIiAiJEhZRFJBX0ZJTEVfTUFJTiI7CgkJCQkJCQkJCWVj
aG8gLWUgIiRUTVBfRkFJTF8wMiIgfGdyZXAgLXYgIiRFWElTVEVEX0FUVEFDS0VSIiA+PiIkSFlE
UkFfRklMRV9NQUlOIjsKCQkJCQkJCQkJRVJST1JfMDE9MTsKCQkJCQkJCQlmaQoJCQkJCQkJZmkK
CQkJCQkJCXVuc2V0IEVYSVNURURfQVRUQUNLRVI7CgkJCQkJCWVsc2UKCQkJCQkJCXByaW50ZiAi
44CMXDAzM1szMm1JTkZPXDAzM1swbeOAjSAlczogXDAzM1szNG3mo4DmtYvliLDmtYHph4/mibDl
iqjvvIhTU0gg6K6k6K+B5aSx6LSl77yJ77yIMTHvvInjgIJcMDMzWzBtXG4iICIkQ1VSX1RJTUUi
OwoJCQkJCQkJRVJST1JfMDI9IiQoKEVSUk9SXzAyKzEpKSI7CgkJCQkJCQlpZiBbICIkRVJST1Jf
MDIiIC1nZSA0IF07dGhlbgoJCQkJCQkJCVRpbWVfQ29udHJhc3QgIiRTVEFSVF9GTEFHXzAyIiAi
RmFpbGVkIHBhc3N3b3JkIGZvciIgIiRDVVJSRU5UX1RJTUUiOwoJCQkJCQkJCVRpbWVfQ29udHJh
c3RfMiAiJFNUQVJUX0ZMQUdfMDIiICJhdXRoZW50aWNhdGlvbiBmYWlsdXJlIiAiJENVUlJFTlRf
VElNRSI7CgkJCQkJCQkJRkFJTF8zPSIkKGpvdXJuYWxjdGwgLXUgc3NoIHxncmVwICIkREFURV8w
MSIgfGdyZXAgIkZhaWxlZCBwYXNzd29yZCBmb3IiIHx0YWlsIC1uICIkVE1QX0hBTkdfMDEiIHxh
d2sgJ3sgcHJpbnQgJDExIH0nIHxhd2sgJyF2aXNpdGVkWyQwXSsrJyB8Z3JlcCAtdiAnXiQnKSI7
CgkJCQkJCQkJRkFJTF80PSIkKGpvdXJuYWxjdGwgLXUgc3NoIHxncmVwICIkREFURV8wMSIgIHxn
cmVwICJhdXRoZW50aWNhdGlvbiBmYWlsdXJlIiB8dGFpbCAtbiAiJFRNUF9IQU5HXzAzIiB8YXdr
IC1GJyByaG9zdD0nICd7IHByaW50ICQyIH0nIHxhd2sgJ3sgcHJpbnQgJDEgfScgfGF3ayAnIXZp
c2l0ZWRbJDBdKysnIHxncmVwIC12ICdeJCcpIjsKCQkJCQkJCQlpZiBbICIkRkFJTF8zIiAhPSAi
IiBdIFwKCQkJCQkJCQkmJiBbICIkRkFJTF80IiAhPSAiIiBdO3RoZW4KCQkJCQkJCQkJRVhJU1RF
RF9BVFRBQ0tFUj0iJChncmVwIC12ICdeJCcgIiRIWURSQV9GSUxFX01BSU4iKSI7CgkJCQkJCQkJ
CUZBSUxfNj0kKGVjaG8gLWUgIiRGQUlMXzNcbiRGQUlMXzQiIHxhd2sgJyF2aXNpdGVkWyQwXSsr
JyB8Z3JlcCAtdiAnXiQnKTsKCQkJCQkJCQkJI2VjaG8gIiRGQUlMXzYiOwoJCQkJCQkJCQkjZWNo
byAiJEVYSVNURURfQVRUQUNLRVIiOwoJCQkJCQkJCQlpZiBbICIkKGVjaG8gIiRFWElTVEVEX0FU
VEFDS0VSIiB8Z3JlcCAtdiAnXiQnIHxhd2sgJyF2aXNpdGVkWyQwXSsrJyB8YXdrICdFTkR7cHJp
bnQgTlJ9JykiIC1lcSAiJChlY2hvIC1lICIkRVhJU1RFRF9BVFRBQ0tFUlxuJEZBSUxfNiIgfGdy
ZXAgLXYgJ14kJyB8YXdrICchdmlzaXRlZFskMF0rKycgfGF3ayAnRU5Ee3ByaW50IE5SfScpIiBd
O3RoZW4KCQkJCQkJCQkJCXByaW50ZiAiXDAzM1sxbeOAjFwwMzNbMTszMm1JTkZPXDAzM1sxOzM3
beOAjSAlczogXDAzM1szNG3mo4DmtYvliLDmnaXoh6ogJXMg55qE572R57uc54iG56C05pS75Ye7
77yIMTLvvInjgIJcMDMzWzBtXG4iICIkQ1VSX1RJTUUiICIkRkFJTF82IjsKCQkJCQkJCQkJCUVS
Uk9SXzAxPTE7CgkJCQkJCQkJCWVsc2UKCQkJCQkJCQkJCXByaW50ZiAiXDAzM1sxbeOAjFwwMzNb
MTszMm1JTkZPXDAzM1sxOzM3beOAjSAlczogXDAzM1szNG3mo4DmtYvliLDmnaXoh6ogJXMg55qE
572R57uc54iG56C05pS75Ye777yIMTLvvInjgILlt7LlsIbmlLvlh7vogIVpcOiusOW9leWtmOah
o+iHsyVz44CCXDAzM1swbVxuIiAiJENVUl9USU1FIiAiJEZBSUxfNiIgIiRIWURSQV9GSUxFX01B
SU4iOwoJCQkJCQkJCQkJZWNobyAtZSAiJEZBSUxfNiIgfGdyZXAgLXYgIiRFWElTVEVEX0FUVEFD
S0VSIiA+PiIkSFlEUkFfRklMRV9NQUlOIjsKCQkJCQkJCQkJCUVSUk9SXzAxPTE7CgkJCQkJCQkJ
CWZpCgkJCQkJCQkJCXVuc2V0IEVYSVNURURfQVRUQUNLRVI7CgkJCQkJCQkJZWxpZiBbICIkRkFJ
TF8zIiAhPSAiIiBdIFwKCQkJCQkJCQkmJiBbICIkRkFJTF80IiA9ICIiIF07dGhlbgoJCQkJCQkJ
CQlFWElTVEVEX0FUVEFDS0VSPSIkKGdyZXAgLXYgJ14kJyAiJEhZRFJBX0ZJTEVfTUFJTiIpIjsK
CQkJCQkJCQkJaWYgWyAiJChlY2hvICIkRVhJU1RFRF9BVFRBQ0tFUiIgfGdyZXAgLXYgJ14kJyB8
YXdrICchdmlzaXRlZFskMF0rKycgfGF3ayAnRU5Ee3ByaW50IE5SfScpIiAtZXEgIiQoZWNobyAt
ZSAiJEVYSVNURURfQVRUQUNLRVJcbiRGQUlMXzMiIHxncmVwIC12ICdeJCcgfGF3ayAnIXZpc2l0
ZWRbJDBdKysnIHxhd2sgJ0VORHtwcmludCBOUn0nKSIgXTt0aGVuCgkJCQkJCQkJCQlwcmludGYg
IlwwMzNbMW3jgIxcMDMzWzE7MzJtSU5GT1wwMzNbMTszN23jgI0gJXM6IFwwMzNbMzRt5qOA5rWL
5Yiw5p2l6IeqICVzIOeahOe9kee7nOeIhuegtOaUu+WHu++8iDEz77yJ44CCXDAzM1swbVxuIiAi
JENVUl9USU1FIiAiJEZBSUxfMyI7CgkJCQkJCQkJCQlFUlJPUl8wMT0xOwoJCQkJCQkJCQllbHNl
CgkJCQkJCQkJCQlwcmludGYgIlwwMzNbMW3jgIxcMDMzWzE7MzJtSU5GT1wwMzNbMTszN23jgI0g
JXM6IFwwMzNbMzRt5qOA5rWL5Yiw5p2l6IeqICVzIOeahOe9kee7nOeIhuegtOaUu+WHu++8iDEz
77yJ44CC5bey5bCG5pS75Ye76ICFaXDorrDlvZXlrZjmoaPoh7Mlc+OAglwwMzNbMG1cbiIgIiRD
VVJfVElNRSIgIiRGQUlMXzMiICIkSFlEUkFfRklMRV9NQUlOIjsKCQkJCQkJCQkJCWVjaG8gLWUg
IiRGQUlMXzMiIHxncmVwIC12ICIkRVhJU1RFRF9BVFRBQ0tFUiIgPj4iJEhZRFJBX0ZJTEVfTUFJ
TiI7CgkJCQkJCQkJCQlFUlJPUl8wMT0xOwoJCQkJCQkJCQlmaQoJCQkJCQkJCQl1bnNldCBFWElT
VEVEX0FUVEFDS0VSOwoJCQkJCQkJCWVsaWYgWyAiJEZBSUxfMyIgPSAiIiBdIFwKCQkJCQkJCQkm
JiBbICIkRkFJTF80IiAhPSAiIiBdO3RoZW4KCQkJCQkJCQkJRVhJU1RFRF9BVFRBQ0tFUj0iJChn
cmVwIC12ICdeJCcgIiRIWURSQV9GSUxFX01BSU4iKSI7CgkJCQkJCQkJCWlmIFsgIiQoZWNobyAi
JEVYSVNURURfQVRUQUNLRVIiIHxncmVwIC12ICdeJCcgfGF3ayAnIXZpc2l0ZWRbJDBdKysnIHxh
d2sgJ0VORHtwcmludCBOUn0nKSIgLWVxICIkKGVjaG8gLWUgIiRFWElTVEVEX0FUVEFDS0VSXG4k
RkFJTF80IiB8Z3JlcCAtdiAnXiQnIHxhd2sgJyF2aXNpdGVkWyQwXSsrJyB8YXdrICdFTkR7cHJp
bnQgTlJ9JykiIF07dGhlbgoJCQkJCQkJCQkJcHJpbnRmICJcMDMzWzFt44CMXDAzM1sxOzMybUlO
Rk9cMDMzWzE7Mzdt44CNICVzOiBcMDMzWzM0beajgOa1i+WIsOadpeiHqiAlcyDnmoTnvZHnu5zn
iIbnoLTmlLvlh7vvvIgxNO+8ieOAglwwMzNbMG1cbiIgIiRDVVJfVElNRSIgIiRGQUlMXzQiOwoJ
CQkJCQkJCQkJRVJST1JfMDE9MTsKCQkJCQkJCQkJZWxzZQoJCQkJCQkJCQkJcHJpbnRmICJcMDMz
WzFt44CMXDAzM1sxOzMybUlORk9cMDMzWzE7Mzdt44CNICVzOiBcMDMzWzM0beajgOa1i+WIsOad
peiHqiAlcyDnmoTnvZHnu5zniIbnoLTmlLvlh7vvvIgxNO+8ieOAguW3suWwhuaUu+WHu+iAhWlw
6K6w5b2V5a2Y5qGj6IezJXPjgIJcMDMzWzBtXG4iICIkQ1VSX1RJTUUiICIkRkFJTF80IiAiJEhZ
RFJBX0ZJTEVfTUFJTiI7CgkJCQkJCQkJCQllY2hvIC1lICIkRkFJTF80IiB8Z3JlcCAtdiAiJEVY
SVNURURfQVRUQUNLRVIiID4+IiRIWURSQV9GSUxFX01BSU4iOwoJCQkJCQkJCQkJRVJST1JfMDE9
MTsKCQkJCQkJCQkJZmkKCQkJCQkJCQkJdW5zZXQgRVhJU1RFRF9BVFRBQ0tFUjsKCQkJCQkJCQll
bHNlCgkJCQkJCQkJCXByaW50ZiAi44CMXDAzM1szM21XQVJOXDAzM1swbeOAjSAlczogXDAzM1sz
M23mo4DmtYvliLDnvZHnu5zniIbnoLTmlLvlh7vvvIzkvYbml6Dms5Xnoa7lrprmlLvlh7vogIXj
gILvvIgxNe+8iVwwMzNbMG1cbiIgIiRDVVJfVElNRSI7CgkJCQkJCQkJCUVSUk9SXzAxPTE7CgkJ
CQkJCQkJZmkKCQkJCQkJCQlFUlJPUl8wMj0wOwoJCQkJCQkJCUVSUk9SXzAzPTE7CgkJCQkJCQlm
aQoJCQkJCQkJaWYgWyAiJEVSUk9SXzAzIiAtZXEgMCBdO3RoZW4KCQkJCQkJCQlFUlJPUl8wMT0y
OwoJCQkJCQkJZWxzZQoJCQkJCQkJCUVSUk9SXzAxPTE7CgkJCQkJCQlmaQoJCQkJCQlmaQoJCQkJ
CWZpCgkJCQlmaQoJCQkJCgkJCQl1bnNldCBUTVBfRkFJTF8wMTsKCQkJCXVuc2V0IFRNUF9BVFRB
Q0tfMDE7CgkJCQl1bnNldCBFWElTVEVEX0FUVEFDS0VSOwoJCQkJRkFJTFVSRT0wOwoJCQkJQVRU
QUNLRVI9MDsKCQkJCVNUQVJUX0ZMQUdfMDM9MDsKCQkJCQoJCQkJIyBObWFwIOe9kee7nOaJq+aP
j+S7quebkea1iwoJCQkJaWYgWyAhIC1mICIkTk1BUF9GSUxFX01BSU4iIF07dGhlbgoJCQkJCWVj
aG8gLWUgIiMg5qOA5rWL5Yiw55qEIE5tYXAg572R57uc5omr5o+P5LuqIElQ77yaXG4iID4iJE5N
QVBfRklMRV9NQUlOIjsKCQkJCWZpCgkJCQlpZiBbICIkKGpvdXJuYWxjdGwgLXUgc3NoIHxncmVw
ICIkREFURV8wMSIgfGdyZXAgImVycm9yOiBrZXhfZXhjaGFuZ2VfaWRlbnRpZmljYXRpb24iKSIg
IT0gIiIgXTt0aGVuCgkJCQkJVGltZV9Db250cmFzdCAiJFNUQVJUX0ZMQUdfMDIiICJlcnJvcjog
a2V4X2V4Y2hhbmdlX2lkZW50aWZpY2F0aW9uIiAiJENVUlJFTlRfVElNRSI7CgkJCQkJaWYgWyAi
JFRNUF9IQU5HXzAxIiAtZ2UgMSBdO3RoZW4KCQkJCQkJaWYgWyAiJChqb3VybmFsY3RsIC11IHNz
aCB8Z3JlcCAiJERBVEVfMDEiIHxncmVwICJlcnJvcjoga2V4X2V4Y2hhbmdlX2lkZW50aWZpY2F0
aW9uIiB8Z3JlcCAiQ29ubmVjdGlvbiBjbG9zZWQgYnkgcmVtb3RlIGhvc3QiKSIgIT0gIiIgXTt0
aGVuCgkJCQkJCQlUaW1lX0NvbnRyYXN0ICIkU1RBUlRfRkxBR18wMiIgImVycm9yOiBrZXhfZXhj
aGFuZ2VfaWRlbnRpZmljYXRpb24iICIkQ1VSUkVOVF9USU1FIiAiQ29ubmVjdGlvbiBjbG9zZWQg
YnkgcmVtb3RlIGhvc3QiOwoJCQkJCQkJaWYgWyAiJFRNUF9IQU5HXzAxIiAhPSAwIF07dGhlbgoJ
CQkJCQkJCUhPU1RfMT0iJChqb3VybmFsY3RsIC11IHNzaCB8Z3JlcCAiJERBVEVfMDEiIHxncmVw
ICJDb25uZWN0aW9uIGNsb3NlZCBieSIgfGdyZXAgInBvcnQiIHxncmVwIC12ICJwcmVhdXRoIiB8
dGFpbCAtbiAiJFRNUF9IQU5HXzAxIiB8YXdrICd7IHByaW50ICQ5IH0nIHxhd2sgJyF2aXNpdGVk
WyQwXSsrJykiOwoJCQkJCQkJCU5NQVBfU1Y9MTsKCQkJCQkJCQlTVEFSVF9GTEFHXzAzPSIkKChT
VEFSVF9GTEFHXzAzKzEpKSI7CgkJCQkJCQkJRVJST1JfMDE9MTsKCQkJCQkJCWZpCgkJCQkJCWZp
CgkJCQkJCWlmIFsgIiQoam91cm5hbGN0bCAtdSBzc2ggfGdyZXAgIiREQVRFXzAxIiB8Z3JlcCAi
ZXJyb3I6IGtleF9leGNoYW5nZV9pZGVudGlmaWNhdGlvbiIgfGdyZXAgInJlYWQ6IENvbm5lY3Rp
b24gcmVzZXQgYnkgcGVlciIpIiAhPSAiIiBdO3RoZW4KCQkJCQkJCVRpbWVfQ29udHJhc3QgIiRT
VEFSVF9GTEFHXzAyIiAiQ29ubmVjdGlvbiByZXNldCBieSIgIiRDVVJSRU5UX1RJTUUiICJwb3J0
IiAiYXV0aGVudGljYXRpbmciOwoJCQkJCQkJaWYgWyAiJFRNUF9IQU5HXzAxIiAhPSAwIF07dGhl
bgoJCQkJCQkJCUhPU1RfMj0iJChqb3VybmFsY3RsIC11IHNzaCB8Z3JlcCAiJERBVEVfMDEiIHxn
cmVwICJDb25uZWN0aW9uIHJlc2V0IGJ5IiB8Z3JlcCAicG9ydCIgfHRhaWwgLW4gIiRUTVBfSEFO
R18wMSIgfGF3ayAneyBwcmludCAkOSB9JyB8YXdrICchdmlzaXRlZFskMF0rKycpIjsKCQkJCQkJ
CQlOTUFQX1NUPTE7CgkJCQkJCQkJU1RBUlRfRkxBR18wMz0iJCgoU1RBUlRfRkxBR18wMysyKSki
OwoJCQkJCQkJCUVSUk9SXzAxPTE7CgkJCQkJCQlmaQoJCQkJCQlmaQoJCQkJCQlpZiBbICIkKGpv
dXJuYWxjdGwgLXUgc3NoIHxncmVwICIkREFURV8wMSIgfGdyZXAgImVycm9yOiBrZXhfZXhjaGFu
Z2VfaWRlbnRpZmljYXRpb24iIHxncmVwICJiYW5uZXIgbGluZSBjb250YWlucyBpbnZhbGlkIGNo
YXJhY3RlcnMiKSIgIT0gIiIgXTt0aGVuCgkJCQkJCQlUaW1lX0NvbnRyYXN0ICIkU1RBUlRfRkxB
R18wMiIgImJhbm5lciBleGNoYW5nZTogQ29ubmVjdGlvbiBmcm9tIiAiJENVUlJFTlRfVElNRSIg
ImludmFsaWQgZm9ybWF0IjsKCQkJCQkJCWlmIFsgIiRUTVBfSEFOR18wMSIgIT0gMCBdO3RoZW4K
CQkJCQkJCQlIT1NUXzM9IiQoam91cm5hbGN0bCAtdSBzc2ggfGdyZXAgIiREQVRFXzAxIiB8Z3Jl
cCAiYmFubmVyIGV4Y2hhbmdlOiBDb25uZWN0aW9uIGZyb20iIHxncmVwICJpbnZhbGlkIGZvcm1h
dCIgfHRhaWwgLW4gIiRUTVBfSEFOR18wMSIgfGF3ayAneyBwcmludCAkMTAgfScgfGF3ayAnIXZp
c2l0ZWRbJDBdKysnKSI7CgkJCQkJCQkJTk1BUF9TQ1JJUFQ9MTsKCQkJCQkJCQlTVEFSVF9GTEFH
XzAzPSIkKChTVEFSVF9GTEFHXzAzKzQpKSI7CgkJCQkJCQkJRVJST1JfMDE9MTsKCQkJCQkJCWZp
CgkJCQkJCWZpCgkJCQkJZmkKCQkJCWZpCgkJCQlpZiBbICIkKGpvdXJuYWxjdGwgLXUgc3NoIHxn
cmVwICIkREFURV8wMSIgfGdyZXAgIlVuYWJsZSB0byBuZWdvdGlhdGUgd2l0aCIgKSIgIT0gIiIg
XSBcCgkJCQl8fCBbICIkKGpvdXJuYWxjdGwgLXUgc3NoIHxncmVwICIkREFURV8wMSIgfGdyZXAg
ImVycm9yOiBQcm90b2NvbCBtYWpvciB2ZXJzaW9ucyBkaWZmZXIiKSIgIT0gIiIgXTt0aGVuCgkJ
CQkJVGltZV9Db250cmFzdCAiJFNUQVJUX0ZMQUdfMDIiICJVbmFibGUgdG8gbmVnb3RpYXRlIHdp
dGgiICIkQ1VSUkVOVF9USU1FIiAibm8gbWF0Y2hpbmcgaG9zdCBrZXkgdHlwZSBmb3VuZC4gVGhl
aXIgb2ZmZXIiOwoJCQkJCWlmIFsgIiRUTVBfSEFOR18wMSIgIT0gMCBdO3RoZW4KCQkJCQkJSE9T
VF80PSIkKGpvdXJuYWxjdGwgLXUgc3NoIHxncmVwICIkREFURV8wMSIgfGdyZXAgIlVuYWJsZSB0
byBuZWdvdGlhdGUgd2l0aCIgfGdyZXAgIm5vIG1hdGNoaW5nIGhvc3Qga2V5IHR5cGUgZm91bmQu
IFRoZWlyIG9mZmVyIiB8dGFpbCAtbiAiJFRNUF9IQU5HXzAxIiB8YXdrICd7IHByaW50ICQxMCB9
JyB8YXdrICchdmlzaXRlZFskMF0rKycpIjsKCQkJCQkJTk1BUF9BTEw9MTsKCQkJCQkJU1RBUlRf
RkxBR18wMz0iJCgoU1RBUlRfRkxBR18wMys4KSkiOwoJCQkJCQlFUlJPUl8wMT0xOwoJCQkJCWZp
CgkJCQlmaQoJCQkJCgkJCQlpZiBbICIkTk1BUF9TViIgIT0gMCBdIFwKCQkJCXx8IFsgIiROTUFQ
X1NUIiAhPSAwIF0gXAoJCQkJfHwgWyAiJE5NQVBfU0NSSVBUIiAhPSAwIF0gXAoJCQkJfHwgWyAi
JE5NQVBfQUxMIiAhPSAwIF07dGhlbgoJCQkJCUhPU1RfMD0iJChwcmludGYgIiRIT1NUXzFcbiRI
T1NUXzJcbiRIT1NUXzNcbiRIT1NUXzQiIHxncmVwIC12ICdeJCcgfGF3ayAnIXZpc2l0ZWRbJDBd
KysnKSI7CgkJCQkJRVhJU1RFRF9IT1NUPSIkKGdyZXAgLXYgJ14kJyAiJE5NQVBfRklMRV9NQUlO
IikiOwoJCQkJCWlmIFsgIiQoZWNobyAiJEVYSVNURURfSE9TVCIgfGdyZXAgLXYgJ14kJyB8YXdr
ICchdmlzaXRlZFskMF0rKycgfGF3ayAnRU5Ee3ByaW50IE5SfScpIiAtZXEgIiQoZWNobyAtZSAi
JEVYSVNURURfSE9TVFxuJEhPU1RfMCIgfGdyZXAgLXYgJ14kJyB8YXdrICchdmlzaXRlZFskMF0r
KycgfGF3ayAnRU5Ee3ByaW50IE5SfScpIiBdO3RoZW4KCQkJCQkJcHJpbnRmICJcMDMzWzFt44CM
XDAzM1sxOzMybUlORk9cMDMzWzE7Mzdt44CNICVzOiBcMDMzWzM0beajgOa1i+WIsOe9kee7nC/n
q6/lj6Pmiavmj4/ku6rmtYHph4/vvIjkvLzkuY7mmK8gTm1hcO+8ie+8jOadpea6kO+8miAlcyDv
vIgwMe+8ieOAglwwMzNbMG1cbiIgIiRDVVJfVElNRSIgIiRIT1NUXzAiOwoJCQkJCQlFUlJPUl8w
MT0xOwoJCQkJCWVsaWYgWyAiJEhPU1RfMCIgIT0gIiIgXTt0aGVuCgkJCQkJCXByaW50ZiAiXDAz
M1sxbeOAjFwwMzNbMTszMm1JTkZPXDAzM1sxOzM3beOAjSAlczogXDAzM1szNG3mo4DmtYvliLDn
vZHnu5wv56uv5Y+j5omr5o+P5Luq5rWB6YeP77yI5Ly85LmO5pivIE5tYXDvvInvvIzmnaXmupDv
vJogJXMg77yIMDHvvInjgILlt7LlsIbmlLvlh7vogIVpcOiusOW9leWtmOaho+iHsyVz44CCXDAz
M1swbVxuIiAiJENVUl9USU1FIiAiJEhPU1RfMCIgIiROTUFQX0ZJTEVfTUFJTiI7CgkJCQkJCWVj
aG8gLWUgIiRIT1NUXzAiID4+IiROTUFQX0ZJTEVfTUFJTiI7CgkJCQkJCUVSUk9SXzAxPTE7CgkJ
CQkJZmkKCQkJCQkKCQkJCQl1bnNldCBIT1NUXzA7CgkJCQkJdW5zZXQgSE9TVF8xOwoJCQkJCXVu
c2V0IEhPU1RfMjsKCQkJCQl1bnNldCBIT1NUXzM7CgkJCQkJdW5zZXQgSE9TVF80OwoJCQkJCWNh
c2UgJFNUQVJUX0ZMQUdfMDMgaW4gCgkJCQkJCTApCgkJCQkJCQlwcmludGYgIlwwMzNbMW3jgIxc
MDMzWzE7MzJtSU5GT1wwMzNbMTszN23jgI0gICAgICAgICAgfOWPr+iDveeahOWRveS7pO+8miBu
bWFwIDwgLXAgMjAyMz4gJXMgXG5cMDMzWzBtIiAiJEFERF9JUCI7CgkJCQkJCQlwcmludGYgIuOA
jFwwMzNbMzJtSU5GT1wwMzNbMG3jgI0gICAgICAgICAgXFzov5nkvLzkuY7lj6rmmK/nroDljZXn
moQgbm1hcCAtc1Mg5Z+65pys5omr5o+P44CCXG4iOwoJCQkJCQkJRVJST1JfMDE9MTsKCQkJCQkJ
OzsKCQkJCQkJCgkJCQkJCTEpCgkJCQkJCQlwcmludGYgIlwwMzNbMW3jgIxcMDMzWzE7MzJtSU5G
T1wwMzNbMTszN23jgI0gICAgICAgICAgfOWPr+iDveeahOWRveS7pO+8miBubWFwIC1zViA8IC1z
VD4gPCAtcCAyMDIzPiAgJXMgXG5cMDMzWzBtIiAiJEFERF9JUCI7CgkJCQkJCQlwcmludGYgIuOA
jFwwMzNbMzJtSU5GT1wwMzNbMG3jgI0gICAgICAgICAgXFznm5HmtYvliLDnmoTmiavmj4/nsbvl
novvvJrmma7pgJrmnI3liqHmiavmj4/vvIjlm6AgLXNWIOaJq+aPj+aYr+W7uueri+WcqCBUQ1Ag
56uv5Y+j5omr5o+P55qE5Z+656GA5LiK55qE77yM5pWF5peg5rOV5Yik5pat5piv5ZCm5L2/55So
5LqGIC1zVCDpgInpobnvvInjgIJcbiI7CgkJCQkJCQlFUlJPUl8wMT0xOwoJCQkJCQk7OwoJCQkJ
CQkKCQkJCQkJMikKCQkJCQkJCXByaW50ZiAiXDAzM1sxbeOAjFwwMzNbMTszMm1JTkZPXDAzM1sx
OzM3beOAjSAgICAgICAgICB85Y+v6IO955qE5ZG95Luk77yaIG5tYXAgLXNUIDwgLXAgMjAyMz4g
ICVzIFxuXDAzM1swbSIgIiRBRERfSVAiOwoJCQkJCQkJcHJpbnRmICLjgIxcMDMzWzMybUlORk9c
MDMzWzBt44CNICAgICAgICAgIFxc55uR5rWL5Yiw55qE5omr5o+P57G75Z6L77yaVENQIOerr+WP
o+aJq+aPj+OAglxuIjsKCQkJCQkJCUVSUk9SXzAxPTE7CgkJCQkJCTs7CgkJCQkJCQoJCQkJCQkz
KQoJCQkJCQkJcHJpbnRmICJcMDMzWzFt44CMXDAzM1sxOzMybUlORk9cMDMzWzE7Mzdt44CNICAg
ICAgICAgIHzlj6/og73nmoTlkb3ku6TvvJogbm1hcCAtc1YgLXNUIDwgLXAgMjAyMz4gICVzIFxu
XDAzM1swbSIgIiRBRERfSVAiOwoJCQkJCQkJcHJpbnRmICLjgIxcMDMzWzMybUlORk9cMDMzWzBt
44CNICAgICAgICAgIFxc55uR5rWL5Yiw55qE5omr5o+P57G75Z6L77ya5pmu6YCa5pyN5Yqh5omr
5o+P77yMVENQIOerr+WPo+aJq+aPj1xuIjsKCQkJCQkJCUVSUk9SXzAxPTE7CgkJCQkJCTs7CgkJ
CQkJCQoJCQkJCQk0KQoJCQkJCQkJcHJpbnRmICJcMDMzWzFt44CMXDAzM1sxOzMybUlORk9cMDMz
WzE7Mzdt44CNICAgICAgICAgIHzlj6/og73nmoTlkb3ku6TvvJogbm1hcCB7LXNDIOaIli1zY3Jp
cHQ9XCI86ISa5pys57G75Z6LPlwiIC4uLn0gPCAtcCAyMDIzPiAgJXMgXG5cMDMzWzBtIiAiJEFE
RF9JUCI7CgkJCQkJCQlwcmludGYgIuOAjFwwMzNbMzJtSU5GT1wwMzNbMG3jgI0gICAgICAgICAg
XFznm5HmtYvliLDnmoTmiavmj4/nsbvlnovvvJpOU0Ug6ISa5pys5omr5o+P44CCXG4iOwoJCQkJ
CQkJRVJST1JfMDE9MTsKCQkJCQkJOzsKCQkJCQkJCgkJCQkJCTUpCgkJCQkJCQlwcmludGYgIlww
MzNbMW3jgIxcMDMzWzE7MzJtSU5GT1wwMzNbMTszN23jgI0gICAgICAgICAgfOWPr+iDveeahOWR
veS7pO+8miBubWFwIC1zViB7LXNDIOaIli1zY3JpcHQ9XCI86ISa5pys57G75Z6LPlwiIC4uLn0g
PCAtcCAyMDIzPiAgJXMgXG5cMDMzWzBtIiAiJEFERF9JUCI7CgkJCQkJCQlwcmludGYgIuOAjFww
MzNbMzJtSU5GT1wwMzNbMG3jgI0gICAgICAgICAgXFznm5HmtYvliLDnmoTmiavmj4/nsbvlnovv
vJrmma7pgJrmnI3liqHmiavmj4/vvIxOU0Ug6ISa5pys5omr5o+P44CCXG4iOwoJCQkJCQkJRVJS
T1JfMDE9MTsKCQkJCQkJOzsKCQkJCQkJCgkJCQkJCTYpCgkJCQkJCQlwcmludGYgIlwwMzNbMW3j
gIxcMDMzWzE7MzJtSU5GT1wwMzNbMTszN23jgI0gICAgICAgICAgfOWPr+iDveeahOWRveS7pO+8
miBubWFwIC1zVCB7LXNDIOaIli1zY3JpcHQ9XCI86ISa5pys57G75Z6LPlwiIC4uLn0gPCAtcCAy
MDIzPiAgJXMgXG5cMDMzWzBtIiAiJEFERF9JUCI7CgkJCQkJCQlwcmludGYgIuOAjFwwMzNbMzJt
SU5GT1wwMzNbMG3jgI0gICAgICAgICAgXFznm5HmtYvliLDnmoTmiavmj4/nsbvlnovvvJpUQ1Ag
56uv5Y+j5omr5o+P77yMTlNFIOiEmuacrOaJq+aPj+OAglxuIjsKCQkJCQkJCUVSUk9SXzAxPTE7
CgkJCQkJCTs7CgkJCQkJCQoJCQkJCQk3KQoJCQkJCQkJcHJpbnRmICJcMDMzWzFt44CMXDAzM1sx
OzMybUlORk9cMDMzWzE7Mzdt44CNICAgICAgICAgIHzlj6/og73nmoTlkb3ku6TvvJogbm1hcCAt
c1QgLXNWIHstc0Mg5oiWLXNjcmlwdD1cIjzohJrmnKznsbvlnos+XCIgLi4ufSA8IC1wIDIwMjM+
ICAlcyBcblwwMzNbMG0iICIkQUREX0lQIjsKCQkJCQkJCXByaW50ZiAi44CMXDAzM1szMm1JTkZP
XDAzM1swbeOAjSAgICAgICAgICBcXOebkea1i+WIsOeahOaJq+aPj+exu+Wei++8mlRDUCDnq6/l
j6Pmiavmj4/vvIzmma7pgJrmnI3liqHmiavmj4/vvIxOU0Ug6ISa5pys5omr5o+P44CCXG4iOwoJ
CQkJCQkJRVJST1JfMDE9MTsKCQkJCQkJOzsKCQkJCQkJCgkJCQkJCTgpCgkJCQkJCQlwcmludGYg
IlwwMzNbMW3jgIxcMDMzWzE7MzJtSU5GT1wwMzNbMTszN23jgI0gICAgICAgICAgfOWPr+iDveea
hOWRveS7pO+8miBubWFwIC1BIDwgLXAgMjAyMz4gICVzIFxuXDAzM1swbSIgIiRBRERfSVAiOwoJ
CQkJCQkJcHJpbnRmICLjgIxcMDMzWzMybUlORk9cMDMzWzBt44CNICAgICAgICAgIFxc55uR5rWL
5Yiw55qE5omr5o+P57G75Z6L77yaLUEg57u85ZCI5omr5o+P44CCXG4iOwoJCQkJCQkJRVJST1Jf
MDE9MTsKCQkJCQkJOzsKCQkJCQkJCgkJCQkJCTkpCgkJCQkJCQlwcmludGYgIlwwMzNbMW3jgIxc
MDMzWzE7MzJtSU5GT1wwMzNbMTszN23jgI0gICAgICAgICAgfOWPr+iDveeahOWRveS7pO+8miBu
bWFwIC1zViB7LXNDIOaIli1zY3JpcHQ9XCI86ISa5pys57G75Z6LPlwiIOaIli1BIC4uLn0gPCAt
cCAyMDIzPiAgJXMgXG5cMDMzWzBtIiAiJEFERF9JUCI7CgkJCQkJCQlwcmludGYgIuOAjFwwMzNb
MzJtSU5GT1wwMzNbMG3jgI0gICAgICAgICAgXFznm5HmtYvliLDnmoTmiavmj4/nsbvlnovvvJrm
ma7pgJrmnI3liqHmiavmj4/vvIjlm6AgLXNWIOaJq+aPj+aYr+W7uueri+WcqCBUQ1Ag56uv5Y+j
5omr5o+P55qE5Z+656GA5LiK55qE77yM5pWF5peg5rOV5Yik5pat5piv5ZCm5L2/55So5LqGIC1z
VCDpgInpobnvvInvvIznu7zlkIjmiJYgTlNFIOiEmuacrOaJq+aPj+OAglxuIjsKCQkJCQkJCUVS
Uk9SXzAxPTE7CgkJCQkJCTs7CgkJCQkJCQoJCQkJCQkxMCkKCQkJCQkJCXByaW50ZiAiXDAzM1sx
beOAjFwwMzNbMTszMm1JTkZPXDAzM1sxOzM3beOAjSAgICAgICAgICB85Y+v6IO955qE5ZG95Luk
77yaIG5tYXAgLXNUIHstc0Mg5oiWLXNjcmlwdD1cIjzohJrmnKznsbvlnos+XCIg5oiWLUEgLi4u
fSA8IC1wIDIwMjM+ICAlcyBcblwwMzNbMG0iICIkQUREX0lQIjsKCQkJCQkJCXByaW50ZiAi44CM
XDAzM1szMm1JTkZPXDAzM1swbeOAjSAgICAgICAgICBcXOebkea1i+WIsOeahOaJq+aPj+exu+We
i++8mlRDUCDnq6/lj6Pmiavmj4/vvIznu7zlkIjmiJYgTlNFIOiEmuacrOaJq+aPj+OAglxuIjsK
CQkJCQkJCUVSUk9SXzAxPTE7CgkJCQkJCTs7CgkJCQkJCQoJCQkJCQkxMSkKCQkJCQkJCXByaW50
ZiAiXDAzM1sxbeOAjFwwMzNbMTszMm1JTkZPXDAzM1sxOzM3beOAjSAgICAgICAgICB85Y+v6IO9
55qE5ZG95Luk77yaIG5tYXAgLXNUIC1zViB7LXNDIOaIli1zY3JpcHQ9XCI86ISa5pys57G75Z6L
PlwiIOaIli1BIC4uLn0gPCAtcCAyMDIzPiAgJXMgXG5cMDMzWzBtIiAiJEFERF9JUCI7CgkJCQkJ
CQlwcmludGYgIuOAjFwwMzNbMzJtSU5GT1wwMzNbMG3jgI0gICAgICAgICAgXFznm5HmtYvliLDn
moTmiavmj4/nsbvlnovvvJpUQ1Ag56uv5Y+j5omr5o+P77yM5pmu6YCa5pyN5Yqh5omr5o+P77yM
57u85ZCI5oiWIE5TRSDohJrmnKzmiavmj4/jgIJcbiI7CgkJCQkJCQlFUlJPUl8wMT0xOwoJCQkJ
CQk7OwoJCQkJCQkKCQkJCQkJMTIpCgkJCQkJCQlwcmludGYgIlwwMzNbMW3jgIxcMDMzWzE7MzJt
SU5GT1wwMzNbMTszN23jgI0gICAgICAgICAgfOWPr+iDveeahOWRveS7pO+8miBubWFwIC1BIHst
c0Mg5oiWLXNjcmlwdD1cIjzohJrmnKznsbvlnos+XCIgLi4ufSA8IC1wIDIwMjM+ICAlcyBcblww
MzNbMG0iICIkQUREX0lQIjsKCQkJCQkJCXByaW50ZiAi44CMXDAzM1szMm1JTkZPXDAzM1swbeOA
jSAgICAgICAgICBcXOebkea1i+WIsOeahOaJq+aPj+exu+Wei++8mk5TRSDohJrmnKzmiavmj4/v
vIznu7zlkIjmiavmj4/jgIJcbiI7CgkJCQkJCQlFUlJPUl8wMT0xOwoJCQkJCQk7OwoJCQkJCQkK
CQkJCQkJMTMpCgkJCQkJCQlwcmludGYgIlwwMzNbMW3jgIxcMDMzWzE7MzJtSU5GT1wwMzNbMTsz
N23jgI0gICAgICAgICAgfOWPr+iDveeahOWRveS7pO+8miBubWFwIC1zViAtQSB7LXNDIOaIli1z
Y3JpcHQ9XCI86ISa5pys57G75Z6LPlwiIC4uLn0gPCAtcCAyMDIzPiAgJXMgXG5cMDMzWzBtIiAi
JEFERF9JUCI7CgkJCQkJCQlwcmludGYgIuOAjFwwMzNbMzJtSU5GT1wwMzNbMG3jgI0gICAgICAg
ICAgXFznm5HmtYvliLDnmoTmiavmj4/nsbvlnovvvJrmma7pgJrmnI3liqHmiavmj4/vvIxOU0Ug
6ISa5pys5omr5o+P77yM57u85ZCI5omr5o+P44CCXG4iOwoJCQkJCQkJRVJST1JfMDE9MTsKCQkJ
CQkJOzsKCQkJCQkJCgkJCQkJCTE0KQoJCQkJCQkJcHJpbnRmICJcMDMzWzFt44CMXDAzM1sxOzMy
bUlORk9cMDMzWzE7Mzdt44CNICAgICAgICAgIHzlj6/og73nmoTlkb3ku6TvvJogbm1hcCAtc1Qg
LUEgey1zQyDmiJYtc2NyaXB0PVwiPOiEmuacrOexu+Weiz5cIiAuLi59IDwgLXAgMjAyMz4gICVz
IFxuXDAzM1swbSIgIiRBRERfSVAiOwoJCQkJCQkJcHJpbnRmICLjgIxcMDMzWzMybUlORk9cMDMz
WzBt44CNICAgICAgICAgIFxc55uR5rWL5Yiw55qE5omr5o+P57G75Z6L77yaVENQIOerr+WPo+aJ
q+aPj++8jE5TRSDohJrmnKzmiavmj4/vvIznu7zlkIjmiavmj4/jgIJcbiI7CgkJCQkJCQlFUlJP
Ul8wMT0xOwoJCQkJCQk7OwoJCQkJCQkKCQkJCQkJMTUpCgkJCQkJCQlwcmludGYgIlwwMzNbMW3j
gIxcMDMzWzE7MzJtSU5GT1wwMzNbMTszN23jgI0gICAgICAgICAgfOWPr+iDveeahOWRveS7pO+8
miBubWFwIC1zVCAtc1YgLUEgey1zQyDmiJYtc2NyaXB0PVwiPOiEmuacrOexu+Weiz5cIiAuLi59
IDwgLXAgMjAyMz4gICVzIFxuXDAzM1swbSIgIiRBRERfSVAiOwoJCQkJCQkJcHJpbnRmICLjgIxc
MDMzWzMybUlORk9cMDMzWzBt44CNICAgICAgICAgIFxc55uR5rWL5Yiw55qE5omr5o+P57G75Z6L
77yaVENQIOerr+WPo+aJq+aPj++8jOaZrumAmuacjeWKoeaJq+aPj++8jE5TRSDohJrmnKzmiavm
j4/vvIznu7zlkIjmiavmj4/jgIJcbiI7CgkJCQkJCQlFUlJPUl8wMT0xOwoJCQkJCQk7OwoJCQkJ
CQkKCQkJCQkJKikKCQkJCQkJCXByaW50ZiAiQW1hemluZy4uLjAyIjsKCQkJCQkJOzsKCQkJCQkJ
CgkJCQkJZXNhYwoJCQkJCVNUQVJUX0ZMQUdfMDM9MDsKCQkJCQl1bnNldCBFWElTVEVEX0hPU1Q7
CgkJCQlmaQoJCQkJCgkJCQkjIE5ldGNhdCDlkowgV2luZG93cyBUZXN0LU5ldENvbm5lY3Rpb27l
h73mlbAg55uR5rWLCgkJCQlpZiBbICIkV0FSTklOR19TUlYiIC1sdCAyIF07dGhlbgoJCQkJCWlm
IFsgIiROTUFQX1NWIiAhPSAwIF0gXAoJCQkJCSYmIFsgIiROTUFQX1NUIiAtZXEgMCBdIFwKCQkJ
CQkmJiBbICIkTk1BUF9TQ1JJUFQiIC1lcSAwIF0gXAoJCQkJCSYmIFsgIiROTUFQX0FMTCIgLWVx
IDAgXTt0aGVuCgkJCQkJCXByaW50ZiAiXG4iOwoJCQkJCQlwcmludGYgIuOAjFwwMzNbMzRtSU5G
T1wwMzNbMG3jgI0gXDAzM1szM23or7fms6jmhI9cMDMzWzBt77yaXDAzM1sxbeS7hSAtc1Yg5pmu
6YCa5pyN5Yqh5omr5o+PXDAzM1swbeS4jeaYryBObWFwIOeahOm7mOiupOaJq+aPj+mAiemhueOA
guaIluiuuOW6lOivpeiAg+iZkSBOZXRjYXQg55qEIC16IOmAiemhueaIluiAhSBXaW5kb3dzIOea
hCBUZXN0LU5ldENvbm5lY3Rpb24g5Ye95pWw77yfXG4iOwoJCQkJCQlwcmludGYgIuOAjFwwMzNb
MzRtSU5GT1wwMzNbMG3jgI0gICAgICAgIHzlj6/og73nmoQgTmV0Y2F0IOWRveS7pO+8mmZvciBp
IGluIFwkKHNlcSAyMDIwIDIwMzApOyBkbyBuYyAtenYgLXcgMSAlcyBcJGk7IGRvbmVcbiIgIiRB
RERfSVAiOwoJCQkJCQlwcmludGYgIuOAjFwwMzNbMzRtSU5GT1wwMzNbMG3jgI0gICAgICAgIHzl
j6/og73nmoQgVGVzdC1OZXRDb25uZWN0aW9uIOWRveS7pO+8mlRlc3QtTmV0Q29ubmVjdGlvbiAt
LXBvcnQgMjAyMyAlc1xuIiAiJEFERF9JUCI7CgkJCQkgICAgICAgICAgICAgICAgcHJpbnRmICLj
gIxcMDMzWzM0bUlORk9cMDMzWzBt44CNICAgICAgICBcXOaIlu+8mmZvcmVhY2ggKFwkcG9ydCBp
biAxLi4xMDI0KSB7SWYgKChcJGE9VGVzdC1OZXRDb25uZWN0aW9uIDE5Mi4xNjguNTAuMTUxIC1Q
b3J0IFwkcG9ydCAtV2FybmluZ0FjdGlvbiBTaWxlbnRseUNvbnRpbnVlKS50Y3BUZXN0U3VjY2Vl
ZGVkIC1lcSBcJHRydWUpeyBcIlRDUCBwb3J0IFwkcG9ydCBpcyBvcGVuXCJ9fVxuIjsKCQkJCQkJ
V0FSTklOR19TUlY9IiQoKFdBUk5JTkdfU1JWKzEpKSI7CgkJCQkJZmkKCQkJCWZpCgkJCQkKCQkJ
CSMgV2luZG93cyBUY3BDbGllbnQgU29ja2V05a+56LGhIOebkea1iwoJCQkJaWYgWyAiJFdBUk5J
TkdfVENQIiAtbHQgMiBdO3RoZW4KCQkJCQlpZiBbICIkTk1BUF9TViIgLWVxIDAgXSBcCgkJCQkJ
JiYgWyAiJE5NQVBfU1QiICE9IDAgXSBcCgkJCQkJJiYgWyAiJE5NQVBfU0NSSVBUIiAtZXEgMCBd
IFwKCQkJCQkmJiBbICIkTk1BUF9BTEwiIC1lcSAwIF07dGhlbgoJCQkJCQlwcmludGYgIlxuIjsK
CQkJCQkJcHJpbnRmICLjgIxcMDMzWzM0bUlORk9cMDMzWzBt44CNIFwwMzNbMzNt6K+35rOo5oSP
XDAzM1swbe+8mlwwMzNbMW3ku4UgVENQIOerr+WPo+aJq+aPj1wwMzNbMG3kuI3mmK8gTm1hcCDn
moTpu5jorqTmiavmj4/pgInpobnvvIzkuqbkuI3mmK/luLjnlKjpgInpobnjgILmiJborrjlupTo
r6XogIPomZEgV2luZG93cyDnmoQgVGNwQ2xpZW50IFNvY2tldOWvueixoe+8n1xuIjsKCQkJCQkJ
cHJpbnRmICLjgIxcMDMzWzM0bUlORk9cMDMzWzBt44CNICAgICAgICB85Y+v6IO955qEIFRjcENs
aWVudCDlkb3ku6TvvJoxLi4xMDI0IHwgJSUge2VjaG8gKChOZXctT2JqZWN0IE5ldC5Tb2NrZXRz
LlRjcENsaWVudCkuQ29ubmVjdChcIjE5Mi4xNjguNTAuMTUxXCIsIFwkXyApKSBcIlRDUCBwb3J0
IFwkXyBpcyBvcGVuXCJ9IDI+XCRudWxsXG4iOwoJCQkJCQlXQVJOSU5HX1RDUD0iJCgoV0FSTklO
R19UQ1ArMSkpIjsKCQkJCQlmaQoJCQkJZmkKCQkJCQoJCQkJTk1BUF9TVj0wOwoJCQkJTk1BUF9T
VD0wOwoJCQkJTk1BUF9TQ1JJUFQ9MDsKCQkJCU5NQVBfQUxMPTA7CgkJCQkKCQkJCUVSUk9SX1RJ
TUVTPTA7CgkJCQkKCQkJCWlmIFsgIiQoam91cm5hbGN0bCAtdSBzc2ggfGdyZXAgIiREQVRFXzAx
IiB8Z3JlcCAiQWNjZXB0ZWQgcGFzc3dvcmQiKSIgIT0gIiIgXSBcCgkJCQkmJiBbICIkKGpvdXJu
YWxjdGwgLXUgc3NoIHxncmVwICIkREFURV8wMSIgfGdyZXAgIkFjY2VwdGVkIHBhc3N3b3JkIiB8
YXdrICd7IHByaW50ICQzIH0nIHxhd2sgLUY6ICd7IHByaW50ICQxJDIkMyB9JyB8dGFpbCAtbiAx
KSIgLWdlICIkQ1VSUkVOVF9USU1FIiBdO3RoZW4KCQkJCQlpZiBbICIkRVJST1JfMDEiIC1lcSAw
IF07dGhlbgoJCQkJCQlybSAtZiAiJFRNUF9GSUxFIjsKCQkJCQkJcHJpbnRmICLjgIxcMDMzWzMz
bVdBUk5cMDMzWzBt44CNICVzOiBcMDMzWzMzbeS8vOS5juacquebkea1i+WIsOW8guW4uOaUu+WH
u+a1gemHj++8jOS9hiBTU0gg6L+e5o6l5Ly85LmO5bey5bu656uL77yM5Lit5q2i55uR5rWL44CC
6K+35qOA5p+l5piv5ZCm5Li65YaF6YOo5Lq65ZGY55m75b2V5oiW6ICF5LqM5qyh5pS75Ye744CC
XDAzM1swbVxuIiAiJENVUl9USU1FIjsKCQkJCQkJc2xlZXAgMnM7CgkJCQkJCWV4aXQgMDI0OwoJ
CQkJCWVsaWYgWyAiJEVSUk9SXzAxIiAtZXEgMiBdO3RoZW4KCQkJCQkJcHJpbnRmICJcMDMzWzFt
44CMXDAzM1sxOzMybUlORk9cMDMzWzE7Mzdt44CNICVzOiBcMDMzWzE7MzRt6Jm954S255yL6LW3
5p2l5LiN5aSq5Y+v6IO977yM5L2G5piv5pS75Ye76ICF5Ly85LmO5bey5oiQ5Yqf54iG56C0IFNT
SCDlvLHlj6Pku6Tlr4bnoIHjgIJcMDMzWzBtXG4iICIkQ1VSX1RJTUUiOwoJCQkJCQlwcmludGYg
IlwwMzNbMW3jgIxcMDMzWzE7MzJtSU5GT1wwMzNbMTszN23jgI1cMDMzWzE7MzNtICAgICAgICAg
IHzvvIjov5nmnoHmnInlj6/og73mmK/kvb/nlKjnpL7lt6XnsbvlrZflhbjnmoTlr4bnoIHniIbn
oLTmlLvlh7vvvIzor7flr7nlhoXpg6jkurrlkZjov5vooYzlrqHmn6XjgILvvIlcMDMzWzBtXG4i
OwoJCQkJCQlzbGVlcCAwLjVzOwoJCQkJCWVsc2UKCQkJCQkJcHJpbnRmICJcMDMzWzFt44CMXDAz
M1sxOzMybUlORk9cMDMzWzE7Mzdt44CNICVzOiBcMDMzWzE7MzVt5pS75Ye76ICF5Ly85LmO5bey
5oiQ5Yqf6I635b6XIFNTSCDlvLHlj6Pku6Tlr4bnoIHjgIJcMDMzWzBtXG4iICIkQ1VSX1RJTUUi
OwoJCQkJCQlzbGVlcCAwLjVzOwoJCQkJCWZpCgkJCQlmaQoJCQkJCgkJCQlpZiBbICIkKHBzIC1V
IGthbGkgLUMgc2ggLUYgLWwgLU0gfGdyZXAga2FsaSB8Z3JlcCAic3NoZDoiIHxncmVwIC12IGdy
ZXApIiAhPSAiIiBdO3RoZW4KCQkJCQlwcmludGYgIlxuXDAzM1sxbeOAjFwwMzNbMTszMm1JTkZP
XDAzM1swbVwwMzNbMW3jgI0gJXM6IFwwMzNbMG1cMDMzWzE7MzJt5qOA5rWL5YiwIFNTSCDov57m
jqXlt7Llu7rnq4vvvIgwMe+8ieOAglwwMzNbMG1cbiIgIiRDVVJfVElNRSI7CgkJCQkJc2xlZXAg
MC41czsKCQkJCQlDUklUSUNBTF9TSFVURE9XTj0xOwoJCQkJZmkKCQkJZWxzZQoJCQkJaWYgWyAi
JFNUQVJUX0ZMQUdfMDIiIC1lcSAwIF07dGhlbgoJCQkJCXNsZWVwIDAuNXM7CgkJCQlmaQoJCQkJ
RVJST1JfVElNRVM9IiQoKEVSUk9SX1RJTUVTKzEpKSI7CgkJCWZpCgkJZmkKCQkKCQlpZiBbICIk
U1RBUlRfRkxBR18wMiIgLWVxIDEgXTt0aGVuCgkJCXNsZWVwIDAuMXM7CgkJCUNVUl9USU1FPSIk
KGRhdGUgKyIlVCIpIjsKCQkJQ1VSUkVOVF9USU1FPSIkKGRhdGUgKyIlSCVNJVMiKSI7CgkJZmkK
CQkKCQlpZiBbICIkU1RBUlRfRkxBR18wMiIgLWVxIDAgXTt0aGVuCgkJCXNsZWVwIDAuNXM7CgkJ
ZmkKCQkKCQlpZiBbICIkQ1JJVElDQUxfU0hVVERPV04iIC1nZSAxIF07dGhlbgoJCQlDUklUSUNB
TF9TSFVURE9XTj0iJCgoQ1JJVElDQUxfU0hVVERPV04rMSkpIjsKCQkJc2xlZXAgMC41czsKCQlm
aQoJCWlmIFsgIiRDUklUSUNBTF9TSFVURE9XTiIgLWdlIDEwIF07dGhlbgoJCQlwcmludGYgIuOA
jFwwMzNbMzFtRVJST1JcMDMzWzBt44CN5pSv5oyB546v5aKD5pyq5ZON5bqU77yB57uI5q2i55uR
5rWL77yBXG4iOwoJCQlwcmludGYgIuOAjFwwMzNbMzRtSU5GT1wwMzNbMG3jgI1cMDMzWzM0bei/
lOWbnuS7o+egge+8mlwwMzNbMzFtRXJyb3JDb2RlIDAxXDAzM1swbVxuIjsKCQkJc3lzdGVtY3Rs
IHN0b3Agc3NoOwoJCQlybSAtZiAiJFRNUF9GSUxFIjsKCQkJZWNobyAtZSAiXDAzM1sxOzU7MzFt
IyMjIyMjIyMjIyMjIyMjIyMjIyMjIyMjIyMjIyMjIyMjIyMjIyMjIyMjIyMjIyMjIyMjIyMjIyMj
IyMjIyMjIyNcMDMzWzBtIjsKCQkJcHJpbnRmICJcMDMzWzE7NTszMW0jIyDjgIxDUklUSUNBTOOA
jSBTU0gg6Jyc572Q5qC45b+D6L+b56iL5byC5bi477yB77yB57Sn5oCl57uI5q2iIFNTSCDmnI3l
iqHvvIHvvIEgICMjXDAzM1swbVxuIjsKCQkJcHJpbnRmICJcMDMzWzE7NTszMW0jIyDjgIxDUklU
SUNBTOOAjSDov5Tlm57ku6PnoIHvvJpDUklUSUNBTENvZGUgMDQgICAgICAgICAgICAgICAgICAg
ICAgIyNcMDMzWzBtXG4iOwoJCQllY2hvIC1lICJcMDMzWzE7NTszMW0jIyMjIyMjIyMjIyMjIyMj
IyMjIyMjIyMjIyMjIyMjIyMjIyMjIyMjIyMjIyMjIyMjIyMjIyMjIyMjIyMjIyMjI1wwMzNbMG0i
OwoJCQlzbGVlcCAyczsKCQkJZXhpdCAwMDU7CgkJZmkKCWRvbmUKCXByaW50ZiAiXG5cMDMzWzFt
44CMXDAzM1sxOzMybUlORk9cMDMzWzBtXDAzM1sxbeOAjSAlczogXDAzM1swbVwwMzNbMTszMm3m
o4DmtYvliLAgU1NIIOi/nuaOpeW3suW7uueri++8iDAw77yJ77yM5Lit5q2i55uR5rWL44CCXDAz
M1swbVxuIiAiJENVUl9USU1FIjsKCWNwICIkTk1BUF9GSUxFX01BSU4iICIkSVBfRklMRSI7Cglj
YXQgIiRIWURSQV9GSUxFX01BSU4iID4+ICIkSVBfRklMRSI7CglpZiBbIC1zICIkSVBfRklMRSIg
XTt0aGVuCgkJc29ydCAtdSAiJElQX0ZJTEUiID4gIiRUTVBfRklMRSI7CgkJbXYgIiRUTVBfRklM
RSIgIiRJUF9GSUxFIjsKCWZpCgljYXNlICIkRk9STUFUIiBpbgoJCWpzb24pCgkJCTs7CgkJCQoJ
CXhtbCkKCQkJaWYgWyAiJEVYRV9MQUNLIiAtZ2UgMSBdO3RoZW4KCQkJCXByaW50ZiAiXG7jgIxc
MDMzWzMzbVdBUk5cMDMzWzBt44CNICVzOiBcMDMzWzMzbeitpuWRiu+8muS6jOi/m+WItuaWh+S7
tue8uuWkse+8jOWPr+iDveaXoOazlei/m+ihjOagvOW8j+i9rOaNouOAglwwMzNbMG1cbiIgIiI7
CgkJCWZpCgkJCWpzb25fdG9feG1sICIkSVBfRklMRSIgPiAiJFRNUF9GSUxFIjsKCQkJbXYgIiRU
TVBfRklMRSIgIiRJUF9GSUxFIjsKCQkJOzsKCQkJCgkJY3N2KQoJCQlpZiBbICIkRVhFX0xBQ0si
IC1nZSAxIF07dGhlbgoJCQkJcHJpbnRmICJcbuOAjFwwMzNbMzNtV0FSTlwwMzNbMG3jgI0gJXM6
IFwwMzNbMzNt6K2m5ZGK77ya5LqM6L+b5Yi25paH5Lu257y65aSx77yM5Y+v6IO95peg5rOV6L+b
6KGM5qC85byP6L2s5o2i44CCXDAzM1swbVxuIiAiIjsKCQkJZmkKCQkJanNvbl90b19jc3YgIiRJ
UF9GSUxFIiA+ICIkVE1QX0ZJTEUiOwoJCQltdiAiJFRNUF9GSUxFIiAiJElQX0ZJTEUiOwoJCQk7
OwoJCQkKCQkqKQoJCQk7OwoJCQkKCWVzYWMKCXJtIC1mICIkVE1QX0ZJTEUiOwoJc2xlZXAgMnM7
CglleGl0IDAwMDsKZWxzZQoJcm0gLWYgIiRUTVBfRklMRSI7CglwcmludGYgIlwwMzNbMW3jgIxc
MDMzWzE7MzFtQ1JJVElDQUxcMDMzWzBtXDAzM1sxbeOAjVwwMzNbMG1cMDMzWzE7MzFt5pSv5oyB
546v5aKD5byC5bi477yM57Sn5oCl57uI5q2i77yBXDAzM1swbVxuIjsKCXByaW50ZiAi44CMXDAz
M1szNG1JTkZPXDAzM1swbeOAjVwwMzNbMzRt6L+U5Zue5Luj56CB77yaXDAzM1sxOzMxbUNSSVRJ
Q0FMQ29kZSAwM1wwMzNbMG1cbiI7CglzbGVlcCAyczsKCWV4aXQgMDA0OwpmaQoKcHJpbnRmICLm
ga3llpzop6PplIHlvanom4sg4oCU4oCUIOKAlOKAlCDkvZzogIXnmoTnsr7npZ7nirbmgIHvvJoo
Kk8qKVxuIjtzbGVlcCAyczsKcHJpbnRmICIgICAgICAgICAgICAgIF9fX19fICAgICAgICAgICAg
ICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAg
ICAgICAgX19fX18gXG4iOwpwcmludGYgIiAgICAgICAgICAgICB8IF9fX198ICAgICAgICAgICAg
ICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAg
ICAgIHxfX19fIHxcbiI7CnByaW50ZiAiICAgICAgICAgICAgIHx8ICAgICAgICBfX19fX19fX19f
X19fICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICBfX19fX19fX19fX19fICAgICAg
ICAgICAgICB8fFxuIjsKcHJpbnRmICIgICAgICAgICAgICAgfHwgICAgICBffCAgX19fX19fX19f
ICB8XyAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICBffCAgX19fX19fX19fICB8XyAgICAg
ICAgICAgIHx8XG4iOwpwcmludGYgIiAgICAgICAgICAgICB8fCAgICAgfCAgX3wgIF9fX18gICB8
XyAgfCAgICAgICAgICAgICAgICAgICAgICAgICAgICAgfCAgX3wgIF9fX18gICB8XyAgfCAgICAg
ICAgICAgfHxcbiI7CnByaW50ZiAiICAgICAgICAgICAgIHx8ICAgICB8IHwgIF98IF9fIHxfICAg
fCB8ICAgICAgICAgICAgICAgICAgICAgICAgICAgICB8IHwgIF98IF9fIHxfICAgfCB8ICAgICAg
ICAgICB8fFxuIjsKcHJpbnRmICIgICAgICAgICAgICAgfHwgICAgIHwgfCB8IC0gICAgLSB8ICB8
IHwgICAgICAgICAgICAgICAgICAgICAgICAgICAgIHwgfCB8IC0gICAgLSB8ICB8IHwgICAgICAg
ICAgIHx8XG4iOwpwcmludGYgIiAgICAgICAgICAgICB8fCAgICAgfCB8IHx8ICAgICAgfHwgIHwg
fCAgICAgICAgICAgICAgICAgICAgICAgICAgICAgfCB8IHx8ICAgICAgfHwgIHwgfCAgICAgICAg
ICAgfHxcbiI7CnByaW50ZiAiICAgICAgICAgICAgIHx8ICAgICB8IHwgfF8tIF9fIC1fLV8gfCB8
ICAgICAgICAgICAgICAgICAgICAgICAgICAgICB8IHwgfF8tIF9fIC1fLV8gfCB8ICAgICAgICAg
ICB8fFxuIjsKcHJpbnRmICIgICAgICAgICAgICAgfHwgICAgIHwgfF8gIHxfX19ffCAtX198X3wg
ICAgICAgICAgICAgICAgICAgICAgICAgICAgIHwgfF8gIHxfX19ffCAtX198X3wgICAgICAgICAg
IHx8XG4iOwpwcmludGYgIiAgICAgICAgICAgICB8fCAgICAgfF8gIHxfX19fX19fX18gICAgICAg
ICAgICAgICAgICAgICAgICAgICAgICAgICAgfF8gIHxfX19fX19fX18gICAgICAgICAgICAgICAg
fHxcbiI7CnByaW50ZiAiICAgICAgICAgICAgIHx8ICAgICAgIHxfX19fX19fX19fX3wgICAgICAg
ICAgICAgICAgICAgICAgICAgICAgICAgICAgIHxfX19fX19fX19fX3wgICAgICAgICAgICAgICB8
fFxuIjsKcHJpbnRmICIgICAgICAgICAgICAgfHwgICAgICAgICAgICAgICAgICAgICAgIF9fX19f
X19fX19fX19fX19fX19fX19fX19fX19fICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIHx8
XG4iOwpwcmludGYgIiAgICAgICAgICAgICB8fF9fX18gICAgICAgICAgICAgICAgICB8X19fX19f
X19fX19fX19fX19fX19fX19fXyAgICB8ICAgICAgICAgICAgICAgICAgICAgICAgICBfX19ffHxc
biI7CnByaW50ZiAiICAgICAgICAgICAgIHxfX19fX3wgICAgICAgICAgICAgICAgICAgICAgICAg
ICAgICAgICAgICAgICAgICAgfF9fX3wgICAgICAgICAgICAgICAgICAgICAgICAgfF9fX19ffFxu
IjsKcHJpbnRmICJcZVsxNEFcMDMzWz8yNWxcMDMzWzFtIjsKcHJpbnRmICIgIOWRnO+9nuWTiOWT
iFxuIjtzbGVlcCAwLjlzOwpwcmludGYgIlx05ZGA5ZOI5ZOI5ZOIXG4iO3NsZWVwIDEuMnM7CnBy
aW50ZiAiIOWTpuWTiOWTiOWTiOWTiFxuIjtzbGVlcCAxczsKcHJpbnRmICJcdOWViuWTiOWTiOWT
iFxuIjtzbGVlcCAxLjVzOwpwcmludGYgIiAg5ZGA772e772e772eXG4iO3NsZWVwIDIuMXM7CnBy
aW50ZiAiXHQg5ZCQ5rCU772eXG4iO3NsZWVwIDEuNXM7CnByaW50ZiAiIOWWneWPo+awtOWOi+WO
i+aDilxuIjtzbGVlcCAwLjdzOwpwcmludGYgIlx054K55Liq6JqK6aaZ5bqG56Wd5LiA5LiLXG4i
O3NsZWVwIDAuOXM7CnByaW50ZiAiICAgIOaIke+9nuaTpu+8ge+8gVxuIjtzbGVlcCAxLjRzOwpw
cmludGYgIlx05bCx6L+Z77yfXG4iO3NsZWVwIDEuOXM7CnByaW50ZiAi5Zi/772eXG4iO3NsZWVw
IDAuM3M7CnByaW50ZiAiXHQgICDlsI/moLfvvZ5cbiI7c2xlZXAgMS42czsKcHJpbnRmICIgIOi/
meS4jei9u+i9u+advuadvuWYm++8gVxuIjtzbGVlcCA1czsKcHJpbnRmICJcMDMzWz8yNWhcMDMz
WzBtXG5cblxuIjsKCnByaW50ZiAiUFM6IOiDveino+mUgei/meS4quW9qeibi+WwseihqOaYjuS9
oOWPkeeOsOS6huS4gOS4quebuOW9k+elnuWlh+eahCBCdWcg44CC6K+35Yqh5b+F5ZGK55+l5pys
5Lq677yB77yI5pyJ6YWs77yJXG4iOwpwcmludGYgIiAg5L2c6ICF6YKu566xIO+8miA8IGtqeDUy
QG91dGxvb2suY29tID4gXG5cbiI7CnByaW50ZiAi5oSf6LCi5L2/55So44CCXG4iOwpzbGVlcCAx
MHM7CgpleGl0IDA7Cgo=' |base64 -d >"$TMP_FILE_03";
printf "1" >"$SUPPORT_FILE_01";
printf "1" >"$SUPPORT_FILE_02";
SSH_STATE="$(systemctl start ssh)";
if [ "$SSH_STATE" = "" ];then
	printf "「\033[32mINFO\033[0m」\033[34m已开启SSH服务。\033[0m\n\n";
	exo-open --launch TerminalEmulator "zsh $TMP_FILE_02" 2>/dev/null;
	sleep 0.2s;
	#xdotool type --window $(xdotool search "Shell No." 2>/dev/null |tail -n 1) q;
	xdotool windowsize "$(xdotool search "Shell No." 2>/dev/null |tail -n 1)" 950 475;
	xdotool windowmove "$(xdotool search "Shell No." 2>/dev/null |tail -n 1)" 965 600;
	sleep 0.2s;
	exo-open --launch TerminalEmulator "bash $TMP_FILE_03" 2>/dev/null;
	sleep 0.2s;
	xdotool windowsize "$(xdotool search "Shell No." 2>/dev/null |tail -n 1)" 950 1010;
else
	printf "「\033[31mERRO\033[0m」\033[31mSSH服务开启失败。\033[0m\n";
	printf "「\033[34mINFO\033[0m」\033[34m返回代码：\033[31mErroCode 02\033[0m\n\n";
	sleep 5s;
	rm -f "$TMP_FILE_04" 2>/dev/null;
	rm -f "$TMP_FILE_05" 2>/dev/null;
	rm -f "$TMP_FILE_02" 2>/dev/null;
	rm -f "$TMP_FILE_03" 2>/dev/null;
	rm -f "$SUPPORT_FILE_01" 2>/dev/null;
	rm -f "$SUPPORT_FILE_02" 2>/dev/null;
	exit 012;
fi

#<LABEL>                           <F>  <S>  <UID>          <PID>     <PPID>  <C>  <PRI>   <NI>  <ADDR>  <SZ>  <WCHAN>    <RSS>  <PSR>  <STIME>  <TTY>          <TIME>     <CMD>
# unconfined                        4    S    kali           88868     88867   0    80      0     -       645   wait_w     884    0      16:17    pts/1          00:00:00   sh
WARNING=3;
OPEN=1;
INFO=1;
#xdotool search "Shell No." 2>/dev/null |tail -n 1

#命令监控脚本
echo '#!/bin/bash

while [ "$(cat "/tmp/num01")" -eq 1 ]
do
	clear;
	printf "\t \033[1m「\033[1;32mINFO\033[1;37m」\033[34m开始监测用户输入：\033[0m\n";
	printf "Every 1.0s: cat /home/kali/bin/.sh_commandhistory.txt\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t     %s:%s\n\n" "$(hostname)" "$(date +%x%X)";
	tail "/home/kali/bin/.sh_commandhistory.txt";
	sleep 1s;
done' >"$TMP_FILE_04";

#命令结果监控脚本
echo '#!/bin/bash

while [ "$(cat "/tmp/num01")" -eq 1 ]
do
	clear;
	printf "\t \033[1m「\033[1;32mINFO\033[1;37m」\033[34msh 模拟执行用户输入的结果：\033[0m\n";
	printf "Every 1.0s: cat /home/kali/bin/.sh_result.txt\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t     %s:%s\n\n" "$(hostname)" "$(date +%x%X)";
	tail -n 20 "/home/kali/bin/.sh_result.txt";
	sleep 1s;
done' >"$TMP_FILE_05";

#echo '#!/bin/bash
#
#xdotool windowsize $(xdotool search "Result01" 2>/dev/null |tail -n 1) 950 490;
#xdotool windowmove $(xdotool search "Result01" 2>/dev/null |tail -n 1) 0 557.5;
#exit;'>/tmp/check.sh;
printf "「\033[32mINFO\033[0m」\033[34m成功写入监控脚本。\033[0m\n";

L_PORT="$(grep "Port " "/etc/ssh/sshd_config" |grep -v "#" |awk '{ print $2 }')";
while true
do
	IF_PROCESS="$(ps -U kali -C sh -F -l -M |grep kali |grep "sshd:" |grep -v grep)";
	if [ "$IF_PROCESS" == "" ];then
		sleep 1s;
	else
		IP="$(systemctl status ssh |grep "Accepted password" |tail -n 1 |awk '{ print $11 }')";
		PORT="$(systemctl status ssh |grep "Accepted password" |tail -n 1 |awk '{ print $13 }')";
		printf "\033[1m「\033[1;32mINFO\033[1;37m」\033[34m检测到来自 %s:%s 的 SSH 连接 。%s:%s --> lhost:%s\033[0m\n" "$IP" "$PORT" "$IP" "$PORT" "$L_PORT";
		echo 0 >"$SUPPORT_FILE_02";
		sleep 2s;
		if [ "$WARNING" -ge 3 ];then
			ADD_IP="$(ip a |grep /21 |awk -F' ' '{ print $2 }' |awk -F'/' '{ print $1 }')";
			if [ "$ADD_IP" = "" ];then
				ADD_IP="$(ip a |grep /24 |awk -F' ' '{ print $2 }' |awk -F'/' '{ print $1 }')";
				if [ "$ADD_IP" = "" ];then
					ADD_IP="$(ip a |grep brd |grep inet |awk -F' ' '{ print $2 }' |awk -F'/' '{ print $1 }')";
				fi
			fi
			TIME="$(date +"%x%X")";
			HOST="$(hostname)";
			USER="$(systemctl status ssh |grep "session opened for" |tail -n 1 |awk '{ print $11 }' |awk -F'(' '{ print $1"\\("$2 }' |awk -F')' '{ print $1"\\)" }')";
			if [ "$IP" != "$ADD_IP" ] \
			&& [ "$IP" != 127.0.0.1 ];then
				printf "「\033[33mWARN\033[0m」\033[33m非本机登录！\033[0m\n"
				bash -c "python3 /etc/ssh/testEmail.py $TIME $USER $IP $HOST 1>&/dev/null";
				printf "「\033[33mWARN\033[0m」\033[33m警告邮件已发送。\033[0m\n"
			fi
		fi
		WARNING=1;
		INFO=1;
		sleep 1s;
	fi
	while [ "$WARNING" -eq 1 ]
	do
		if [ "$INFO" -eq 1 ];then
			chown root:root "$KALI_BIN_PATH/sh";
			chmod 0711 "$KALI_BIN_PATH/sh";
			printf "「\033[32mINFO\033[0m」\033[34m成功隔离伪终端脚本。\033[0m\n";
			chmod 0700 "$KALI_BIN_PATH/sh2";
			printf "「\033[32mINFO\033[0m」\033[34m成功隔离终端脚本。\033[0m\n";
			INFO=0;
			sleep 0.2s;
		fi
		if [ "$OPEN" -ge 1 ];then
			exo-open --launch TerminalEmulator "bash $TMP_FILE_04" 2>/dev/null;
			sleep 0.2s;
			xdotool windowsize "$(xdotool search "Shell No." 2>/dev/null |tail -n 1)" 950 490;
			exo-open --launch TerminalEmulator "bash $TMP_FILE_05" 2>/dev/null;
			sleep 0.2s;
			#exo-open --launch TerminalEmulator 'bash /tmp/check.sh' 2>/dev/null;
			#sleep 0.2s;
			xdotool windowsize "$(xdotool getactivewindow)" 950 485;
			xdotool windowmove "$(xdotool getactivewindow)" 5 591;
			printf "「\033[32mINFO\033[0m」\033[34m开启监控。\033[0m\n";
			OPEN=0;
		fi
		IF_PROCESS="$(ps -U kali -C sh -F -l -M |grep kali |grep "sshd:" |grep -v grep)";
		if [ "$IF_PROCESS" = "" ];then
			printf "「\033[32mINFO\033[37m」\033[34m %s:%s --> lhost:%s SSH连接已断开。\033[0m\n" "$IP" "$PORT" "$L_PORT";
			chown kali:kali "$KALI_BIN_PATH/sh";
			chmod 0544 "$KALI_BIN_PATH/sh";
			chmod 0711 "$KALI_BIN_PATH/sh2";
			printf "[\033[34m?\033[0m] 要停止蜜罐吗[Y/n]:";
			read -r "POWER_OFF";
			case "$POWER_OFF" in 
				Y | y )
					WARNING=0;
				;;
				N | n )
					printf "「\033[32mINFO\033[0m」\033[34m继续监测SSH服务。\033[0m\n";
					WARNING=2;
				;;
				*)
					WARNING=0;
				;;
			esac
		else
			sleep 1s;
		fi
		if [ "$WARNING" -eq 0 ];then
			chown kali:kali "$KALI_BIN_PATH/sh";
			chmod 0544 "$KALI_BIN_PATH/sh";
			printf "「\033[32mINFO\033[0m」\033[34m成功释放伪终端脚本。\033[0m\n";
			chmod 0711 "$KALI_BIN_PATH/sh2";
			printf "「\033[32mINFO\033[0m」\033[34m成功释放终端脚本。\033[0m\n";
			sleep 0.5s;
			echo 0 >"$SUPPORT_FILE_01";
			xdotool windowsize "$(xdotool getactivewindow)" 1910 1010;
			xdotool windowmove "$(xdotool getactivewindow)" 0 0;
			break;
		fi
	done
	if [ "$WARNING" -eq 0 ];then
		rm -f "$TMP_FILE_04" 2>/dev/null;
		#rm /tmp/check.sh;
		rm -f "$TMP_FILE_05" 2>/dev/null;
		rm -f "$TMP_FILE_02" 2>/dev/null;
		rm -f "$TMP_FILE_03" 2>/dev/null;
		rm -f "$SUPPORT_FILE_01" 2>/dev/null;
		rm -f "$SUPPORT_FILE_02" 2>/dev/null;
		printf "「\033[32mINFO\033[0m」\033[34m成功删除监控脚本。\033[0m\n";
		sleep 0.5s;
		break;
	fi
done

SSH_DONE="$(systemctl stop ssh)";
if [ "$SSH_DONE" = "" ];then
	printf "「\033[32mINFO\033[0m」\033[34m已关闭SSH服务。\033[0m\n";
	sleep 2s;
else
	printf "「\033[31mERRO\033[0m」\033[31mSSH 服务关闭异常。\033[0m\n";
	printf "[\033[31m-\033[0m] 错误代码为：\n %s" "$SSH_DONE";
	printf "「\033[34mINFO\033[0m」\033[34m返回代码：\033[31mErroCode 03\033[0m\n";
	sleep 5s;
	exit 013;
fi

printf "「\033[34mINFO\033[0m」完成。\n";

printf "============================================================================================================================+\n";
printf "「\033[34mINFO\033[0m」感谢使用。按 回车ENTER 退出。\n";
read -r "PASS";
exit 000;


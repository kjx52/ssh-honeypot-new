#!/bin/bash
# -*- coding: utf-8 -*-
#/*SSH 网络监测脚本*/
# 作者 ： Jessarin000
# 日期 ： 2023-12-02
# 版本 ： 5.3
#
##注意：·本脚本应配合 log.sh 使用。
##     ·遇到任何问题或错误请联系作者。
#
#10010001010010100111101001010101          _          100100010100101001111010010101011
#10101010100001110110101011110      _.-=::' '::=-._      101010101000011101101010111100
#00000111110101010 10001110     .-:':   ';   ;'   :':-.     00000111110101010 100011101
#11010010001001010100101     .::    ;.  ' ; ; '  .;  . ::.     110100100010010101001011
#100010010010011110010    .:'  :  . ;. :   :   : .; ;  :  ':.    1000100100100111100100
#10 010101010101111    .:  :  :'. :; :         : ; ;.':  :  :.      10 0101010101011111
#1010101010101110   ...' :. :'.' '. ;      _      ;:.' '.': .: '...   10101010101011100
#11001010000111110   '. :. ',  '  '.;  .-='|'=-.  ;.'  '  ,' .: .'   110010100001111101
#10001010110111110     ':.:.       ';.''-:-|-:-''.;'       .:.:'     100010101101111100
#1110001101010 101   .              ::  :  |  :  ::              .   1110001101010 1011
#1110101001010000   :: .        ;  |:---:--|--:---:|  ;        . ::   11101010010100001
#101000000011111   : :.:       .:   ::  :  |  :  ::   :.       :.: :   1010000000111110
#0000011111001010   : : :  '  . '    '..-:-|-:-..'    ' .  '  : : :   00000111110010100
#11000010000110101   ':  :: : : ::    .'-=.|.=-'.    :  : : ::  :'   110000100001101011
#110000001111110010    '.':  .: ' :  ::    :    ::  :  ::.  :'.''   1100000011111100101
#000111 101001010000      ':. :: . :.: :  : :  : :.: . :: .:'*.    000111 1010010100000
#11010000101010000101       ''.'  :  ;  ::   ::  ;  :  ':'*.:'    110100001010100001010
#1101010010101000000111      '**.-:._ ;  :   :  ; _.:-'**.:'    11010100101010000001111
#00111010101 000001001001     ::      '-=::_::=-''.*****:     00111010101 0000010010011
#     __   __  _____  _______ ::_   _   _____  __  :__*[=] _______  _____   _____
#     ||:  || ||    '   |||   :|.'_'.| ||   || ||: :||*---   |||   ||   || ||___||
#     || : || ||---|    |||   '||'-'|| ||___|| || :'||*| |   |||   ||___|| ||':--'
#  .  ||__:|| ||____. _.|||..'*||***||.|_____|.||'*:||.|_|...|||.._|_____|_||  ':.  .
#   +--'.***.--.********.'------'.****. '----------'.***********************.'-----+
#        ;*'    '.***.''          :*'                :*************.'.*****'
#         :.     :**.             ::                 '.*****_---**:   :***:
#         :.      ''              ::                   :._*.          :**:
#       .'*:                     .':                                 :***:
#     :'***'.                 ..'**.                                :*****'.
#                                 
####

printf "
10010001010010100111101001010101          \033[1;31m_\033[0m          100100010100101001111010010101011
10101010100001110110101011110      \033[1;31m_.-=::' '::=-._\033[0m      101010101000011101101010111100
00000111110101010 10001110     \033[1;31m.-:'\033[0m\033[1m:   ';   ;'   :\033[1;31m':-.\033[0m     00000111110101010 100011101
11010010001001010100101     \033[1;31m.::\033[0m\033[1m    ;.  ' \033[1;31m; ;\033[0m\033[1m '  .;  \033[1;31m. ::.\033[0m     110100100010010101001011
100010010010011110010    \033[1;31m.:'\033[0m\033[1m  :  \033[1;31m.\033[0m\033[1m ;. :   \033[1;31m:\033[0m   : .; \033[1;31m;\033[0m\033[1m  :  \033[1;31m':.\033[0m    1000100100100111100100
10 010101010101111    \033[1;31m.:\033[0m\033[1m  :  :'. \033[1;31m:\033[0m\033[1m; :         : \033[1;31m; ;\033[0m\033[1m.':  :  \033[1;31m:.\033[0m      10 0101010101011111
1010101010101110   \033[1;31m...'\033[0m\033[1m :. :'.' \033[1;31m'. ;\033[0m\033[1m      \033[1;34m_\033[0m      \033[1;31m;:.'\033[0m\033[1m '.': .: \033[1;31m'...\033[0m   10101010101011100
11001010000111110   '. :. ',  '  \033[1;31m'.;\033[0m\033[1m  \033[1;34m.-='|'=-.\033[0m  \033[1;31m;.'\033[0m\033[1m  '  ,' .: .'\033[0m   110010100001111101
10001010110111110     ':\033[1;31m.:.       ';\033[0m\033[1m\033[1;34m.''-:-|-:-''.\033[0m\033[1;31m;'\033[0m\033[1m       .:.:' \033[0m    100010101101111100
1110001101010 101   \033[1;31m.\033[0m              \033[1;34m::  :  |  :  ::\033[0m              \033[1m.\033[0m   1110001101010 1011
1110101001010000   \033[1;31m::\033[0m\033[1m .        \033[1;31m;\033[0m\033[1m  \033[1;34m|:---:--|--:---:|\033[0m  \033[1;31m;\033[0m\033[1m        \033[1;31m.\033[0m\033[1m ::\033[0m   11101010010100001
101000000011111   \033[1;31m:\033[0m\033[1m :.:       \033[1;31m.:\033[0m\033[1m   \033[1;34m::  :  |  :  ::\033[0m   \033[1;31m:.\033[0m\033[1m       \033[1;31m:.\033[0m\033[1m: \033[1;31m:\033[0m   1010000000111110
0000011111001010   \033[1;31m:\033[0m\033[1m \033[1;31m:\033[0m\033[1m :  '  \033[1;31m. '\033[0m\033[1m    \033[1;34m'..-:-|-:-..'\033[0m    \033[1;31m' .\033[0m\033[1m  '  : : \033[1;31m:\033[0m   00000111110010100
11000010000110101   \033[1;31m':\033[0m\033[1m  :: : : \033[1;31m:\033[1;31m:\033[0m\033[1m    .\033[1;34m'-=.|.=-'\033[0m\033[1m.    \033[1;31m:  :\033[0m\033[1m : ::  \033[1;31m:'\033[0m   110000100001101011
110000001111110010    \033[1;31m'.\033[0m\033[1m':  .: \033[1;31m' \033[1;31m:\033[0m\033[1m  ::    :    ::  :  \033[1;31m::.\033[0m\033[1m  :'\033[1;31m.''\033[0m   1100000011111100101
000111 101001010000      \033[1;31m':.\033[0m\033[1m :: \033[1;31m. \033[1;31m:\033[0m\033[1m.: :  : :  : :.: \033[1;31m.\033[0m\033[1m :: \033[1;31m.:'*.\033[0m    000111 1010010100000
11010000101010000101       \033[1;31m''.\033[0m\033[1m'  \033[1;31m:\033[0m\033[1m  ;  ::   ::  ;  \033[1;31m:  ':'*.:'\033[0m    110100001010100001010
1101010010101000000111      \033[1;31m'**.-:._\033[0m\033[1m ;  :   :  ; \033[1;31m_.:-'**.:'\033[0m    11010100101010000001111
00111010101 000001001001     \033[1;31m::      '-=::_::=-''.*****:\033[0m     00111010101 0000010010011
     \033[1;34m__   __  _____  _______ \033[0m\033[1;31m::\033[1;34m_   _   _____  __  \033[0m\033[1;31m:\033[1;34m__\033[0m\033[1;31m*\033[1;34m[=] _______  _____   _____\033[0m
     \033[1;34m||:  || ||    '   |||   \033[1;31m:\033[0m\033[1;34m|.'_'.| ||   || ||: \033[0m\033[1;31m:\033[0m\033[1;34m||\033[0m\033[1;31m*\033[0m\033[1;34m---   |||   ||   || ||___||\033[0m
     \033[1;34m|| : || ||---|    |||   \033[1;31m'\033[0m\033[1;34m||'-'|| ||___|| || :\033[0m\033[1;31m'\033[0m\033[1;34m||\033[0m\033[1;31m*\033[0m\033[1;34m| |   |||   ||___|| ||':--'\033[0m
  \033[1;31m.\033[0m  \033[1;34m||\033[1;31m__\033[0m\033[0m\033[1;34m:|| ||____.\033[0m\033[1;31m _.\033[0m\033[1;34m|||\033[0m\033[1;31m..'*\033[0m\033[1;34m||\033[0m\033[1;31m***\033[0m\033[1;34m||\033[0m\033[1;31m.\033[0m\033[1;34m|_____|\033[0m\033[1;34m.\033[0m\033[1;34m||\033[0m\033[1;31m'*\033[0m\033[1;34m:||\033[0m\033[1;31m.\033[0m\033[1;34m|_|\033[0m\033[1;31m...\033[0m\033[1;34m|||\033[0m\033[1;31m.._\033[0m\033[1;34m|_____|\033[0m\033[1;31m_\033[0m\033[1;34m||  ':.\033[0m\033[1;31m  .
   +--'.***.--.********.'------'.****. '----------'.***********************.'-----+
        ;*'    '.***.''          :*'                :*************.'.*****'
         :.     :**.             ::                 '.*****_---**:   :***:
         :.      ''              ::                   :._*.          :**:
       .'*:                     .':                                 :***:
     :'***'.                 ..'**.                                :*****'.\033[0m

\033[34m
/*SSH 网络监测脚本*/
 作者 ： Jessarin000
 日期 ： 2023-12-02
 版本 ： 5.3\033[0m
 
  
    本脚本用于自动化监测 SSH 网络攻击（如在线密码爆破，Nmap 扫描）。\033[31m在启动此脚本前请查看并配置脚本以适应您的系统。\033[0m
本脚本可以结合多种方式在攻击者进入蜜罐前动态监测其在 SSH 连接端口的各种行为。

    \033[1;35m有任何意见或建议请联系作者：<kjx52@outlook.com>\033[0m

\033[33m@注意：·本脚本应配合 log.sh 使用。\033[0m
\033[33m@      ·遇到任何问题或错误请联系作者。\033[0m\n\n
";

USER_LEVEL="$(whoami)";
if [ "$USER_LEVEL" = "root" ];then
	#你用的是root？当真？你傻了吗？
	printf "「\033[33mWARN\033[0m」\033[33m检测到使用 root 账户运行，这可能出现非预期的危险。\033[0m\n";
	USER_LEVEL="/root";
elif [ "$USER_LEVEL" = "kali" ];then
	printf "「？？？」你用蜜罐账户运行？当真？你傻了吗(0 _ 0)?\n";
	sleep 2s;
	exit 001;
else
	#你居然不提权？当真？你傻了吗？:D
	USER_LEVEL="/home/$(whoami)";
fi

sleep 5s;
clear;

#set -euf -o pipefail;

TMP_FILE="$(mktemp -t Tonyhere.XXXXXXX)" || exit 021;
trap 'printf "\n\n[X] 中止。\n"; rm -f "$TMP_FILE"; sleep 5s; exit 020' SIGINT SIGTERM;

if [ ! -f "/tmp/num02" ];then
	printf "\033[1m「\033[1;31mCRITICAL\033[0m\033[1m」\033[0m\033[1;31m未检测到支持环境，紧急终止！\033[0m\n";
	printf "「\033[34mINFO\033[0m」\033[34m返回代码：\033[1;31mCRITICALCode 01\033[0m\n";
	sleep 2s;
	exit 002;
else
	printf "「\033[32mINFO\033[0m」\033[34m支持环境检查正常。\033[0m\n";
fi

if [ "$(systemctl status ssh |grep "Active" |awk '{ print $2 }')" = "inactive" ];then
	printf "\033[1m「\033[1;31mCRITICAL\033[0m\033[1m」\033[0m\033[1;31m未检测到启动环境，紧急终止！\033[0m\n";
	printf "「\033[34mINFO\033[0m」\033[34m返回代码：\033[1;31mCRITICALCode 02\033[0m\n";
	sleep 2s;
	exit 003;
else
	printf "「\033[32mINFO\033[0m」\033[34m启动环境检查正常。\033[0m\n";
fi

#=====================================================

#以下是本程序需要的特殊可执行文件：
EXECUTABLE_FILE[0]="jq";
EXECUTABLE_FILE[1]="xmlstarlet";
EXECUTABLE_FILE[2]="csvformat";

#=====================================================

LACK="";
EXE[0]="";
EXE[1]="";
EXE[2]="";
LEN=${#EXECUTABLE_FILE[@]};
EXE_LACK=0;

echo "$PATH" |awk '{split($0,path,":");for (i in path) print path[i]"\n" }' >"$TMP_FILE";
while read -r EXECUTABLE_FILE_PATH; do
	[[ -z "$EXECUTABLE_FILE_PATH" ]] \
	&& continue;
	for ((i=0 ; i<LEN ; i++))
	do
		if [ "$(ls "$EXECUTABLE_FILE_PATH/${EXECUTABLE_FILE[i]}" 2>/dev/null )" = "" ] \
		&& [ "${EXE[i]}" != "0" ];then
			EXE[i]=1;
		else
			EXE[i]=0;
		fi
	done
done < "$TMP_FILE"
for ((i=0 ; i<LEN ; i++))
do
	if [ "${EXE[i]}" != "0" ];then
		LACK="$LACK\t${EXECUTABLE_FILE[i]} ,\n";
	fi
done

if [ "$LACK" != "" ];then
	printf "「\033[33mWARN\033[0m」\033[33m检测到二进制文件缺失，列表如下：\n$LACK 默认情况下，这将造成本程序日志文件无法转换格式。\033[0m\n";
	printf "[\033[34m?\033[0m] 要中止监测吗[Y/n]:";
	read -r ANS;
	case $ANS in
		y | Y )
			printf "中止。\n";
			sleep 2s;
			exit 022;
		;;
		
		n | N )
			EXE_LACK=1;
		;;
		
		*)
			printf "中止。\n";
			sleep 2s;
			exit 022;
		;;
		
	esac
else
	printf "「\033[32mINFO\033[0m」\033[34m可执行文件校验正常。\033[0m\n";
fi

echo "";

if [ "$(sshd -v 2>&1 |head -n 2 |tail -n 1 |awk '{ print $1,$2 }' |awk -F, '{ print $1 }')" != "OpenSSH_2.3p1 Ubuntu-7" ];then
	printf "「\033[33mWARN\033[0m」\033[33m检测到 SSH 服务版本号未更改。\n\033[0m";
fi

ADD_IP="$(ip a |grep "/21" |awk -F' ' '{ print $2 }' |awk -F'/' '{ print $1 }')";
if [ "$ADD_IP" = "" ];then
	ADD_IP="$(ip a |grep "/24" |awk -F' ' '{ print $2 }' |awk -F'/' '{ print $1 }')";
	if [ "$ADD_IP" = "" ];then
		ADD_IP="$(ip a |grep "brd" |grep "inet" |awk -F' ' '{ print $2 }' |awk -F'/' '{ print $1 }')";
	fi
fi

START_FLAG=1;
ERROR_01=0;
ERROR_02=0;
ERROR_03=0;
FAILURE=0;
ATTACKER=0;
WARNING_TCP=0;
WARNING_SRV=0;
CRITICAL_SHUTDOWN=0;

NMAP_SV=0;
NMAP_ST=0;
NMAP_SCRIPT=0;
NMAP_ALL=0;

unset HOST_0;
unset HOST_1;
unset HOST_2;
unset HOST_3;
unset HOST_4;

#=====================================================

#以下为默认储存路径：
LOG_FILE_DIR="$USER_LEVEL/桌面/SSH-honeypot";
HYDRA_FILE_MAIN="$USER_LEVEL/桌面/SSH-honeypot/SSH_attacker.txt";
NMAP_FILE_MAIN="$USER_LEVEL/桌面/SSH-honeypot/SSH_nmap_host.txt";
STORE_FILE_DIR="/var/log/ssh-honeypot";

#=====================================================

DATE="$(date +"%Y-%m-%d")";
IP_FILE="$STORE_FILE_DIR/$DATE.ip";

function json_to_xml()
{
	jq -r 'to_entries | map({(.key): .value}) | .[]' "$1" | xmlstarlet fo;
}

function json_to_csv()  #虽然我认为没有必要，但是我的 AI 助手 RiW 坚持要加这个函数。他认为客户有可能会将日志转储并用于分析。
{
	jq -r 'to_entries | map([.key, .value]) | .[] | @csv' "$1" | csvformat -H;
}

printf "「\033[32mINFO\033[0m」\033[34m你希望日志文件输出为以下哪种格式：\n1）json _默认_\n2）xml\n3）csv\n\n请输入选项对应的数字：\033[0m";
read -r INT_FORMAT;
FORMAT="${INT_FORMAT:-json}";

function Time_Contrast()
{
	# $1 = $START_FLAG_02 ; $2 = 关键词1. ; $3 = $CURRENT_TIME ; $4 = 关键词2. ; $5 = -v 关键词3
	
	local DATE_02;
	local KEY_WORD1;
	local KEY_WORD2;
	local NUM_002;
	local NUM_003;
	local TIME_002;
	
	DATE_02="$(date +%b\ %d)";
	KEY_WORD1="${4:-}";
	KEY_WORD2="${5:-VALOR_PREDETERMINADO}";
	TMP_HANG_01=0;
	
	if [ "$1" -eq 1 ];then
		NUM_002="$(journalctl -u ssh |grep "$DATE_02" |grep "$2" |grep "$KEY_WORD1" |grep -v "$KEY_WORD2" |awk 'END{print NR}')";
		if [ "$NUM_002" -gt 1 ];then
			for ((i=1 ; i<=NUM_002 ; i++))
			do
				TIME_002="$(journalctl -u ssh |grep "$DATE_02" |grep "$2" |grep "$KEY_WORD1" |grep -v "$KEY_WORD2" |tail -n "$i" |head -n 1 |awk '{ print $3 }' |awk -F: '{ print $1$2$3 }')";
				if [ "$TIME_002" -lt "$3" ];then
					TMP_HANG_01="$((i-1))";
					break;
				fi  
			done
		else
			NUM_003="$(journalctl -u ssh |grep "$DATE_02" |grep "$2" |grep "$KEY_WORD1" |grep -v "$KEY_WORD2" |awk '{ print $3 }' |awk -F: '{ print $1$2$3 }')";
			if [ "$NUM_003" != "" ] \
			&& [ "$NUM_003" -ge "$3" ];then
				TMP_HANG_01=1;
			else
				TMP_HANG_01=0;
			fi
		fi
	fi
}

function Time_Contrast_2()
{
	# $1 = $START_FLAG_02 ; $2 = 关键词. ; $3 = $CURRENT_TIME
	
	local DATE_03;
	local NUM_001;
	local NUM_004;
	local TIME_001;
	
	DATE_03="$(date +%b\ %d)";
	TMP_HANG_03=0;
	
	if [ "$1" -eq 1 ];then
		NUM_001="$(journalctl -u ssh |grep "$DATE_03" |grep "$2" |awk 'END{print NR}')";
		if [ "$NUM_001" -gt 1 ];then
			for ((i=1 ; i<=NUM_001 ; i++))
			do
				TIME_001="$(journalctl -u ssh |grep "$DATE_03" |grep "$2" |tail -n "$i" |head -n 1 |awk '{ print $3 }' |awk -F: '{ print $1$2$3 }')";
				if [ "$TIME_001" -lt "$3" ];then
					TMP_HANG_03="$((i-1))";
					break;
				fi
			done
		else
			NUM_004="$(journalctl -u ssh |grep "$DATE_03" |grep "$2" |awk '{ print $3 }' |awk -F: '{ print $1$2$3 }')";
			if [ "$NUM_004" != "" ] \
			&& [ "$NUM_004" -ge "$3" ];then
				TMP_HANG_03=1;
			else
				TMP_HANG_03=0;
			fi
		fi
	fi
}

ERROR_TIMES=5;
DATE_01="$(date +"%b %d")";
CUR_TIME="$(date +"%T")";
CURRENT_TIME="$(date +"%H%M%S")";
START_FLAG_02=0;

if [ ! -d "$LOG_FILE_DIR" ];then
	mkdir -p "$LOG_FILE_DIR";
fi

if [ ! -d "$STORE_FILE_DIR" ];then
	mkdir -p "$STORE_FILE_DIR";
fi

if [ "$(cat /tmp/num02)" -eq 1 ];then
	while [ "$(cat /tmp/num02)" -eq 1 ]
	do
		
		if [ "$START_FLAG" -eq 1 ];then
			printf "「\033[32mINFO\033[0m」 $CUR_TIME: 开始监控  %s 端口。\n\033[0m" "$(grep "Port " /etc/ssh/sshd_config |awk '{ print $2 }')";
			START_FLAG=0;
		fi

		SSH_STATE="$(journalctl -u ssh |grep "$DATE_01" |grep "Stopped ssh.service" |awk '{ print $3 }' |awk -F: '{ print $1$2$3 }' |tail -n 1)";
		if [ "$SSH_STATE" != "" ] \
		&& [ "$SSH_STATE" -ge "$CURRENT_TIME" ];then
			printf "「\033[33mWARN\033[0m」 %s: \033[33m检测到 SSH 服务似乎被关闭了，请确认是否出现非预期的异常。\n\033[0m" "$CUR_TIME";
			sleep 2s;
			exit 023;
		fi

		ACCEPT_IN="$(journalctl -u ssh |grep "$DATE_01" |grep -v "Accepted password" |grep -v 'St[ao][rp][tp][ie]' |grep -v "listening on")";
		if [ "$(echo "$ACCEPT_IN" |tail -n 1)" != "" ];then
			if [ "$(echo "$ACCEPT_IN" |awk '{ print $3 }' |awk -F: '{ print $1$2$3 }' |tail -n 1)" -ge "$CURRENT_TIME" ];then
				if [ "$ERROR_TIMES" -ge 50 ];then
					printf "\n「\033[32mINFO\033[0m」 %s: 检测到流量。\n\033[0m" "$CUR_TIME";
					ERROR_TIMES=0;
				fi
				START_FLAG_02=1;
				
				# Hydra 网络爆破仪监测
				if [ ! -f "$HYDRA_FILE_MAIN" ];then
					echo -e "# 检测到的 Hydra 网络爆破仪 IP：\n" >"$HYDRA_FILE_MAIN";
				fi
				if [ "$(journalctl -u ssh |grep "$DATE_01" |grep "Failed password for" |tail -n 1)" != "" ] \
				|| [ "$(journalctl -u ssh |grep "$DATE_01" |grep "authentication failure" |tail -n 1)" != "" ];then
					Time_Contrast "$START_FLAG_02" "Failed password for" "$CURRENT_TIME";
					Time_Contrast_2 "$START_FLAG_02" "authentication failure" "$CURRENT_TIME";
					if [ "$TMP_HANG_01" != 0 ] \
					|| [ "$TMP_HANG_03" != 0 ];then
						if [ "$TMP_HANG_01" -ge 20 ];then
							TMP_FAIL_01="$(journalctl -u ssh |grep "$DATE_01" |grep "Failed password for" |tail -n "$TMP_HANG_01" |awk '{ print $11 }' |awk '!visited[$0]++' |grep -v '^$')";
							FAILURE=1;
						fi
						if [ "$TMP_HANG_03" -ge 20 ];then
							TMP_FAIL_02="$(journalctl -u ssh |grep "$DATE_01"  |grep "authentication failure" |tail -n "$TMP_HANG_03" |awk -F' rhost=' '{ print $2 }' |awk '{ print $1 }' |awk '!visited[$0]++' |grep -v '^$')";
							FAILURE=1;
						fi
						if [ "$(journalctl -u ssh |grep "$DATE_01" |grep "error: maximum authentication" |tail -n 1)" != "" ];then
							Time_Contrast "$START_FLAG_02" "error: maximum authentication" "$CURRENT_TIME";
							if [ "$TMP_HANG_01" -ge 10 ];then
								TMP_ATTACK_01="$(journalctl -u ssh |grep "$DATE_01" |grep "error: maximum authentication" |tail -n "$TMP_HANG_01" |awk '{ print $14 }' |awk '!visited[$0]++' |grep -v '^$')";
								ATTACKER=1;
							fi
						fi
						if [ "$ATTACKER" -eq 1 ] \
						&& [ "$FAILURE" -eq 1 ];then
							if [ "$TMP_FAIL_01" != "" ] \
							&& [ "$(echo "$TMP_ATTACK_01" |grep -v '^$' |awk 'END{print NR}')" -eq "$(echo "$TMP_FAIL_01" |grep -v '^$' |awk 'END{print NR}')" ];then
								if [ "$TMP_FAIL_01" != "" ] \
								&& [ "$TMP_ATTACK_01" = "$TMP_FAIL_01" ];then
									EXISTED_ATTACKER="$(grep -v '^$' "$HYDRA_FILE_MAIN")";
									if [ "$(echo "$EXISTED_ATTACKER" |grep -v '^$' |awk '!visited[$0]++' |awk 'END{print NR}')" -eq "$(echo -e "$EXISTED_ATTACKER\n$TMP_ATTACK_01" |grep -v '^$' |awk '!visited[$0]++' |awk 'END{print NR}')" ];then
										printf "\033[1m「\033[1;32mINFO\033[1;37m」 %s: \033[34m检测到来自 %s 的网络爆破攻击（01）。\033[0m\n" "$CUR_TIME" "$TMP_ATTACK_01"; 
										ERROR_01=1;
									else
										printf "\033[1m「\033[1;32mINFO\033[1;37m」 %s: \033[34m检测到来自 %s 的网络爆破攻击（01）。已将攻击者ip记录存档至%s。\033[0m\n" "$CUR_TIME" "$TMP_ATTACK_01" "$HYDRA_FILE_MAIN";
										echo -e "$TMP_ATTACK_01" |grep -v "$EXISTED_ATTACKER" >>"$HYDRA_FILE_MAIN";
										ERROR_01=1;
									fi
									unset EXISTED_ATTACKER;
								elif [ "$TMP_FAIL_01" != "" ];then
									EXISTED_ATTACKER="$(grep -v '^$' "$HYDRA_FILE_MAIN")";
									START_FLAG_03=0;
									if [ "$(echo "$EXISTED_ATTACKER" |awk '!visited[$0]++' |awk 'END{print NR}')" -eq "$(echo -e "$EXISTED_ATTACKER\n$TMP_ATTACK_01" |awk '!visited[$0]++' |awk 'END{print NR}')" ];then
										START_FLAG_03="$((START_FLAG_03+1))";
									fi
									if [ "$(echo "$EXISTED_ATTACKER" |awk '!visited[$0]++' |awk 'END{print NR}')" -eq "$(echo -e "$EXISTED_ATTACKER\n$TMP_FAIL_01" |awk '!visited[$0]++' |awk 'END{print NR}')" ];then
										START_FLAG_03="$((START_FLAG_03+2))";
									fi
									case $START_FLAG_03 in 
										0)
											printf "\033[1m「\033[1;32mINFO\033[1;37m」 %s: \033[34m检测到来自 %s 和 %s 的网络爆破攻击（02）。已将攻击者ip记录存档至%s。\033[0m\n" "$CUR_TIME" "$TMP_ATTACK_01" "$TMP_FAIL_01" "$HYDRA_FILE_MAIN";
											echo -e "$TMP_ATTACK_01" |grep -v "$EXISTED_ATTACKER" >>"$HYDRA_FILE_MAIN";
											echo -e "$TMP_FAIL_01" |grep -v "$EXISTED_ATTACKER" >>"$HYDRA_FILE_MAIN";
											ERROR_01=1;
										;;
										
										1)
											printf "\033[1m「\033[1;32mINFO\033[1;37m」 %s: \033[34m检测到来自 %s 和 %s 的网络爆破攻击（02）。已将攻击者ip（%s）记录存档至%s。\033[0m\n" "$CUR_TIME" "$TMP_ATTACK_01" "$TMP_FAIL_01" "$TMP_FAIL_01" "$HYDRA_FILE_MAIN";
											echo -e "$TMP_FAIL_01" |grep -v "$EXISTED_ATTACKER" >>"$HYDRA_FILE_MAIN";
											ERROR_01=1;
										;;
										
										2)
										  printf "\033[1m「\033[1;32mINFO\033[1;37m」 %s: \033[34m检测到来自 %s 和 %s 的网络爆破攻击（02）。已将攻击者ip（%s）记录存档至%s。\033[0m\n" "$CUR_TIME" "$TMP_ATTACK_01" "$TMP_FAIL_01" "$TMP_ATTACK_01" "$HYDRA_FILE_MAIN";
											echo -e "$TMP_ATTACK_01" |grep -v "$EXISTED_ATTACKER" >>"$HYDRA_FILE_MAIN";
											ERROR_01=1;
										;;
										
										3)
										  printf "\033[1m「\033[1;32mINFO\033[1;37m」 %s: \033[34m检测到来自 %s 和 %s 的网络爆破攻击（02）。\033[0m\n" "$CUR_TIME" "$TMP_ATTACK_01" "$TMP_FAIL_01";
											ERROR_01=1;
										;;
										
										*)
											printf "Amazing...";
										;;
										
									esac
									unset EXISTED_ATTACKER;
								fi
							elif [ "$TMP_FAIL_02" != "" ] \
							&& [ "$(echo "$TMP_ATTACK_01" |grep -v '^$' |awk 'END{print NR}')" -eq "$(echo "$TMP_FAIL_02" |grep -v '^$' |awk 'END{print NR}')" ];then
								if [ "$TMP_FAIL_02" != "" ] \
								&& [ "$TMP_ATTACK_01" = "$TMP_FAIL_02" ];then
									EXISTED_ATTACKER="$(grep -v '^$' "$HYDRA_FILE_MAIN")";
									if [ "$(echo "$EXISTED_ATTACKER" |grep -v '^$' |awk '!visited[$0]++' |awk 'END{print NR}')" -eq "$(echo -e "$EXISTED_ATTACKER\n$TMP_ATTACK_01" |grep -v '^$' |awk '!visited[$0]++' |awk 'END{print NR}')" ];then
										printf "\033[1m「\033[1;32mINFO\033[1;37m」 %s: \033[34m检测到来自 %s 的网络爆破攻击（03）。\033[0m\n" "$CUR_TIME" "$TMP_ATTACK_01";
										ERROR_01=1;
									else
										printf "\033[1m「\033[1;32mINFO\033[1;37m」 %s: \033[34m检测到来自 %s 的网络爆破攻击（03）。已将攻击者ip记录存档至%s。\033[0m\n" "$CUR_TIME" "$TMP_ATTACK_01" "$HYDRA_FILE_MAIN";
										echo -e "$TMP_ATTACK_01" |grep -v "$EXISTED_ATTACKER" >>"$HYDRA_FILE_MAIN";
										ERROR_01=1;
									fi
									unset EXISTED_ATTACKER;
								elif [ "$TMP_FAIL_02" != "" ];then
									EXISTED_ATTACKER="$(grep -v '^$' "$HYDRA_FILE_MAIN")";
									START_FLAG_03=0;
									if [ "$(echo "$EXISTED_ATTACKER" |awk '!visited[$0]++' |awk 'END{print NR}')" -eq "$(echo -e "$EXISTED_ATTACKER\n$TMP_ATTACK_01" |awk '!visited[$0]++' |awk 'END{print NR}')" ];then
										START_FLAG_03="$((START_FLAG_03+1))";
									fi
									if [ "$(echo "$EXISTED_ATTACKER" |awk '!visited[$0]++' |awk 'END{print NR}')" -eq "$(echo -e "$EXISTED_ATTACKER\n$TMP_FAIL_02" |awk '!visited[$0]++' |awk 'END{print NR}')" ];then
										START_FLAG_03="$((START_FLAG_03+2))";
									fi
									case $START_FLAG_03 in 
										0)
											printf "\033[1m「\033[1;32mINFO\033[1;37m」 %s: \033[34m检测到来自 %s 和 %s 的网络爆破攻击（04）。已将攻击者ip记录存档至%s。\033[0m\n" "$CUR_TIME" "$TMP_ATTACK_01" "$TMP_FAIL_02" "$HYDRA_FILE_MAIN";
											echo -e "$TMP_ATTACK_01" |grep -v "$EXISTED_ATTACKER" >>"$HYDRA_FILE_MAIN";
											echo -e "$TMP_FAIL_02" |grep -v "$EXISTED_ATTACKER" >>"$HYDRA_FILE_MAIN";
											ERROR_01=1;
										;;
										
										1)
											printf "\033[1m「\033[1;32mINFO\033[1;37m」 %s: \033[34m检测到来自 %s 和 %s 的网络爆破攻击（04）。已将攻击者ip（%s）记录存档至%s。\033[0m\n" "$CUR_TIME" "$TMP_ATTACK_01" "$TMP_FAIL_02" "$TMP_FAIL_02" "$HYDRA_FILE_MAIN";
											echo -e "$TMP_FAIL_02" |grep -v "$EXISTED_ATTACKER" >>"$HYDRA_FILE_MAIN";
											ERROR_01=1;
										;;
										
										2)
										  printf "\033[1m「\033[1;32mINFO\033[1;37m」 %s: \033[34m检测到来自 %s 和 %s 的网络爆破攻击（04）。已将攻击者ip（%s）记录存档至%s。\033[0m\n" "$CUR_TIME" "$TMP_ATTACK_01" "$TMP_FAIL_02" "$TMP_ATTACK_01" "$HYDRA_FILE_MAIN";
											echo -e "$TMP_ATTACK_01" |grep -v "$EXISTED_ATTACKER" >>"$HYDRA_FILE_MAIN";
											ERROR_01=1;
										;;
										
										3)
											printf "\033[1m「\033[1;32mINFO\033[1;37m」 %s: \033[34m检测到来自 %s 和 %s 的网络爆破攻击（04）。\033[0m\n" "$CUR_TIME" "$TMP_ATTACK_01" "$TMP_FAIL_02";
											ERROR_01=1;
										;;
										
										*)
											printf "Amazing...";
										;;
										
									esac
									unset EXISTED_ATTACKER;
								fi
							elif [ "$(echo "$TMP_ATTACK_01" |grep -v '^$' |awk 'END{print NR}')" -eq 0 ] \
							&& [ "$(echo "$TMP_FAIL_01" |grep -v '^$' |awk 'END{print NR}')" -eq 0 ] \
							&& [ "$(echo "$TMP_FAIL_02" |grep -v '^$' |awk 'END{print NR}')" -eq 0 ];then
								printf "「\033[33mWARN\033[0m」 %s: \033[33m检测到网络爆破攻击，但无法确定攻击者（05）。\033[0m\n" "$CUR_TIME";
								ERROR_01=1;
							else
								if [ "$TMP_FAIL_01" != "" ];then
									EXISTED_ATTACKER="$(grep -v '^$' "$HYDRA_FILE_MAIN")";
									if [ "$(echo "$EXISTED_ATTACKER" |grep -v '^$' |awk '!visited[$0]++' |awk 'END{print NR}')" -eq "$(echo -e "$EXISTED_ATTACKER\n$TMP_FAIL_01" |grep -v '^$' |awk '!visited[$0]++' |awk 'END{print NR}')" ];then
										printf "「\033[32mINFO\033[0m」 %s: \033[34m检测到来自 %s 的网络爆破攻击（06）。\033[0m\n" "$CUR_TIME" "$TMP_FAIL_01";
										ERROR_01=1;
									else
										printf "「\033[32mINFO\033[0m」 %s: \033[34m检测到来自 %s 的网络爆破攻击（06）。已将攻击者ip记录存档至%s。\033[0m\n" "$CUR_TIME" "$TMP_FAIL_01" "$HYDRA_FILE_MAIN";
										echo -e "$TMP_FAIL_01" |grep -v "$EXISTED_ATTACKER" >>"$HYDRA_FILE_MAIN";
										ERROR_01=1;
									fi
									unset EXISTED_ATTACKER;
								elif [ "$TMP_FAIL_02" != "" ];then
									EXISTED_ATTACKER="$(grep -v '^$' "$HYDRA_FILE_MAIN")";
									if [ "$(echo "$EXISTED_ATTACKER" |grep -v '^$' |awk '!visited[$0]++' |awk 'END{print NR}')" -eq "$(echo -e "$EXISTED_ATTACKER\n$TMP_FAIL_02" |grep -v '^$' |awk '!visited[$0]++' |awk 'END{print NR}')" ];then
										printf "「\033[32mINFO\033[0m」 %s: \033[34m检测到来自 %s 的网络爆破攻击（07）。\033[0m\n" "$CUR_TIME" "$TMP_FAIL_02";
										ERROR_01=1;
									else
										printf "「\033[32mINFO\033[0m」 %s: \033[34m检测到来自 %s 的网络爆破攻击（07）。已将攻击者ip记录存档至%s。\033[0m\n" "$CUR_TIME" "$TMP_FAIL_02" "$HYDRA_FILE_MAIN";
										echo -e "$TMP_FAIL_02" |grep -v "$EXISTED_ATTACKER" >>"$HYDRA_FILE_MAIN";
										ERROR_01=1;
									fi
									unset EXISTED_ATTACKER;
								elif [ "$TMP_FAIL_02" != "" ] \
								&& [ "$TMP_FAIL_01" != "" ];then
									EXISTED_ATTACKER="$(grep -v '^$' "$HYDRA_FILE_MAIN")";
									START_FLAG_03=0;
									if [ "$(echo "$EXISTED_ATTACKER" |grep -v '^$' |awk '!visited[$0]++' |awk 'END{print NR}')" -eq "$(echo -e "$EXISTED_ATTACKER\n$TMP_FAIL_01" |grep -v '^$' |awk '!visited[$0]++' |awk 'END{print NR}')" ];then
										START_FLAG_03="$((START_FLAG_03+1))";
									fi
									if [ "$(echo "$EXISTED_ATTACKER" |grep -v '^$' |awk '!visited[$0]++' |awk 'END{print NR}')" -eq "$(echo -e "$EXISTED_ATTACKER\n$TMP_FAIL_02" |grep -v '^$' |awk '!visited[$0]++' |awk 'END{print NR}')" ];then
										START_FLAG_03="$((START_FLAG_03+2))";
									fi
									if [ "$(echo "$TMP_FAIL_01" |grep -v '^$' |awk '!visited[$0]++' |awk 'END{print NR}')" -eq "$(echo -e "$TMP_FAIL_01\n$TMP_FAIL_02" |grep -v '^$' |awk '!visited[$0]++' |awk 'END{print NR}')" ];then
										START_FLAG_03="$((START_FLAG_03+4))";
									fi
									case $START_FLAG_03 in 
										0)
											printf "\033[1m「\033[1;32mINFO\033[1;37m」 %s: \033[34m检测到来自 %s 和 %s 的网络爆破攻击（08）。已将攻击者ip记录存档至%s。\033[0m\n" "$CUR_TIME" "$TMP_FAIL_01" "$TMP_FAIL_02" "$HYDRA_FILE_MAIN";
											echo -e "$TMP_FAIL_01"|grep -v "$EXISTED_ATTACKER" >>"$HYDRA_FILE_MAIN";
											echo -e "$TMP_FAIL_02" |grep -v "$EXISTED_ATTACKER" >>"$HYDRA_FILE_MAIN";
											ERROR_01=1;
										;;
										
										1)
											printf "\033[1m「\033[1;32mINFO\033[1;37m」 %s: \033[34m检测到来自 %s 和 %s 的网络爆破攻击（08）。已将攻击者ip（%s）记录存档至%s。\033[0m\n" "$CUR_TIME" "$TMP_FAIL_01" "$TMP_FAIL_02" "$TMP_FAIL_02" "$HYDRA_FILE_MAIN";
											echo -e "$TMP_FAIL_02" |grep -v "$EXISTED_ATTACKER" >>"$HYDRA_FILE_MAIN";
											ERROR_01=1;
										;;
										
										2)
											printf "\033[1m「\033[1;32mINFO\033[1;37m」 %s: \033[34m检测到来自 %s 和 %s 的网络爆破攻击（08）。已将攻击者ip（%s）记录存档至%s。\033[0m\n" "$CUR_TIME" "$TMP_FAIL_01" "$TMP_FAIL_02" "$TMP_FAIL_01" "$HYDRA_FILE_MAIN";
											echo -e "$TMP_FAIL_01" |grep -v "$EXISTED_ATTACKER" >>"$HYDRA_FILE_MAIN";
											ERROR_01=1;
										;;
										
										#3)
										#	printf "\033[1m「\033[1;32mINFO\033[1;37m」 %s: \033[34m检测到来自 %s 和 %s 的网络爆破攻击。\033[0m\n" "$CUR_TIME" "$TMP_FAIL_01" "$TMP_FAIL_02";
										#	ERROR_01=1;
										#;;
										
										4)
											printf "\033[1m「\033[1;32mINFO\033[1;37m」 %s: \033[34m检测到来自 %s 的网络爆破攻击（08）。已将攻击者ip记录存档至%s。\033[0m\n" "$CUR_TIME" "$TMP_FAIL_01" "$HYDRA_FILE_MAIN";
											echo -e "$TMP_FAIL_01"|grep -v "$EXISTED_ATTACKER" >>"$HYDRA_FILE_MAIN";
											ERROR_01=1;
										;;
										
										#5)
										#	printf "\033[1m「\033[1;32mINFO\033[1;37m」 %s: \033[34m检测到来自 %s 和 %s 的网络爆破攻击。\033[0m\n" "$CUR_TIME" "$TMP_FAIL_01" "$TMP_FAIL_02";
										#	ERROR_01=1;
										#;;
										
										#6)
										#	printf "\033[1m「\033[1;32mINFO\033[1;37m」 %s: \033[34m检测到来自 %s 和 %s 的网络爆破攻击。\033[0m\n" "$CUR_TIME" "$TMP_FAIL_01" "$TMP_FAIL_02";
										# ERROR_01=1;
										#;;
										
										7)
											printf "\033[1m「\033[1;32mINFO\033[1;37m」 %s: \033[34m检测到来自 %s 的网络爆破攻击（08）。\033[0m\n" "$CUR_TIME" "$TMP_FAIL_01";
											ERROR_01=1;
										;;
										
										*)
											printf "Amazing...";
										;;
										
									esac
									unset EXISTED_ATTACKER;
								fi
							fi
						elif [ "$ATTACKER" -eq 0 ] \
						&& [ "$FAILURE" -eq 1 ];then
							EXISTED_ATTACKER="$(grep -v '^$' "$HYDRA_FILE_MAIN")";
							if [ "$TMP_FAIL_01" != "" ];then
								if [ "$(echo "$EXISTED_ATTACKER" |grep -v '^$' |awk '!visited[$0]++' |awk 'END{print NR}')" -eq "$(echo -e "$EXISTED_ATTACKER\n$TMP_FAIL_01" |grep -v '^$' |awk '!visited[$0]++' |awk 'END{print NR}')" ];then
									printf "「\033[32mINFO\033[0m」 %s: \033[34m检测到来自 %s 的网络爆破攻击（09）。\033[0m\n" "$CUR_TIME" "$TMP_FAIL_01";
									ERROR_01=1;
								else
									printf "「\033[32mINFO\033[0m」 %s: \033[34m检测到来自 %s 的网络爆破攻击（09）。已将攻击者ip记录存档至%s。\033[0m\n" "$CUR_TIME" "$TMP_FAIL_01" "$HYDRA_FILE_MAIN";
									echo -e "$TMP_FAIL_01" |grep -v "$EXISTED_ATTACKER" >>"$HYDRA_FILE_MAIN";
									ERROR_01=1;
								fi
							elif [ "$TMP_FAIL_02" != "" ];then
								if [ "$(echo "$EXISTED_ATTACKER" |grep -v '^$' |awk '!visited[$0]++' |awk 'END{print NR}')" -eq "$(echo -e "$EXISTED_ATTACKER\n$TMP_FAIL_02" |grep -v '^$' |awk '!visited[$0]++' |awk 'END{print NR}')" ];then
									printf "「\033[32mINFO\033[0m」 %s: \033[34m检测到来自 %s 的网络爆破攻击（10）。\033[0m\n" "$CUR_TIME" "$TMP_FAIL_02";
									ERROR_01=1;
								else
									printf "「\033[32mINFO\033[0m」 %s: \033[34m检测到来自 %s 的网络爆破攻击（10）。已将攻击者ip记录存档至%s。\033[0m\n" "$CUR_TIME" "$TMP_FAIL_02" "$HYDRA_FILE_MAIN";
									echo -e "$TMP_FAIL_02" |grep -v "$EXISTED_ATTACKER" >>"$HYDRA_FILE_MAIN";
									ERROR_01=1;
								fi
							fi
							unset EXISTED_ATTACKER;
						else
							printf "「\033[32mINFO\033[0m」 %s: \033[34m检测到流量扰动（SSH 认证失败）（11）。\033[0m\n" "$CUR_TIME";
							ERROR_02="$((ERROR_02+1))";
							if [ "$ERROR_02" -ge 4 ];then
								Time_Contrast "$START_FLAG_02" "Failed password for" "$CURRENT_TIME";
								Time_Contrast_2 "$START_FLAG_02" "authentication failure" "$CURRENT_TIME";
								FAIL_3="$(journalctl -u ssh |grep "$DATE_01" |grep "Failed password for" |tail -n "$TMP_HANG_01" |awk '{ print $11 }' |awk '!visited[$0]++' |grep -v '^$')";
								FAIL_4="$(journalctl -u ssh |grep "$DATE_01"  |grep "authentication failure" |tail -n "$TMP_HANG_03" |awk -F' rhost=' '{ print $2 }' |awk '{ print $1 }' |awk '!visited[$0]++' |grep -v '^$')";
								if [ "$FAIL_3" != "" ] \
								&& [ "$FAIL_4" != "" ];then
									EXISTED_ATTACKER="$(grep -v '^$' "$HYDRA_FILE_MAIN")";
									FAIL_6=$(echo -e "$FAIL_3\n$FAIL_4" |awk '!visited[$0]++' |grep -v '^$');
									#echo "$FAIL_6";
									#echo "$EXISTED_ATTACKER";
									if [ "$(echo "$EXISTED_ATTACKER" |grep -v '^$' |awk '!visited[$0]++' |awk 'END{print NR}')" -eq "$(echo -e "$EXISTED_ATTACKER\n$FAIL_6" |grep -v '^$' |awk '!visited[$0]++' |awk 'END{print NR}')" ];then
										printf "\033[1m「\033[1;32mINFO\033[1;37m」 %s: \033[34m检测到来自 %s 的网络爆破攻击（12）。\033[0m\n" "$CUR_TIME" "$FAIL_6";
										ERROR_01=1;
									else
										printf "\033[1m「\033[1;32mINFO\033[1;37m」 %s: \033[34m检测到来自 %s 的网络爆破攻击（12）。已将攻击者ip记录存档至%s。\033[0m\n" "$CUR_TIME" "$FAIL_6" "$HYDRA_FILE_MAIN";
										echo -e "$FAIL_6" |grep -v "$EXISTED_ATTACKER" >>"$HYDRA_FILE_MAIN";
										ERROR_01=1;
									fi
									unset EXISTED_ATTACKER;
								elif [ "$FAIL_3" != "" ] \
								&& [ "$FAIL_4" = "" ];then
									EXISTED_ATTACKER="$(grep -v '^$' "$HYDRA_FILE_MAIN")";
									if [ "$(echo "$EXISTED_ATTACKER" |grep -v '^$' |awk '!visited[$0]++' |awk 'END{print NR}')" -eq "$(echo -e "$EXISTED_ATTACKER\n$FAIL_3" |grep -v '^$' |awk '!visited[$0]++' |awk 'END{print NR}')" ];then
										printf "\033[1m「\033[1;32mINFO\033[1;37m」 %s: \033[34m检测到来自 %s 的网络爆破攻击（13）。\033[0m\n" "$CUR_TIME" "$FAIL_3";
										ERROR_01=1;
									else
										printf "\033[1m「\033[1;32mINFO\033[1;37m」 %s: \033[34m检测到来自 %s 的网络爆破攻击（13）。已将攻击者ip记录存档至%s。\033[0m\n" "$CUR_TIME" "$FAIL_3" "$HYDRA_FILE_MAIN";
										echo -e "$FAIL_3" |grep -v "$EXISTED_ATTACKER" >>"$HYDRA_FILE_MAIN";
										ERROR_01=1;
									fi
									unset EXISTED_ATTACKER;
								elif [ "$FAIL_3" = "" ] \
								&& [ "$FAIL_4" != "" ];then
									EXISTED_ATTACKER="$(grep -v '^$' "$HYDRA_FILE_MAIN")";
									if [ "$(echo "$EXISTED_ATTACKER" |grep -v '^$' |awk '!visited[$0]++' |awk 'END{print NR}')" -eq "$(echo -e "$EXISTED_ATTACKER\n$FAIL_4" |grep -v '^$' |awk '!visited[$0]++' |awk 'END{print NR}')" ];then
										printf "\033[1m「\033[1;32mINFO\033[1;37m」 %s: \033[34m检测到来自 %s 的网络爆破攻击（14）。\033[0m\n" "$CUR_TIME" "$FAIL_4";
										ERROR_01=1;
									else
										printf "\033[1m「\033[1;32mINFO\033[1;37m」 %s: \033[34m检测到来自 %s 的网络爆破攻击（14）。已将攻击者ip记录存档至%s。\033[0m\n" "$CUR_TIME" "$FAIL_4" "$HYDRA_FILE_MAIN";
										echo -e "$FAIL_4" |grep -v "$EXISTED_ATTACKER" >>"$HYDRA_FILE_MAIN";
										ERROR_01=1;
									fi
									unset EXISTED_ATTACKER;
								else
									printf "「\033[33mWARN\033[0m」 %s: \033[33m检测到网络爆破攻击，但无法确定攻击者。（15）\033[0m\n" "$CUR_TIME";
									ERROR_01=1;
								fi
								ERROR_02=0;
								ERROR_03=1;
							fi
							if [ "$ERROR_03" -eq 0 ];then
								ERROR_01=2;
							else
								ERROR_01=1;
							fi
						fi
					fi
				fi
				
				unset TMP_FAIL_01;
				unset TMP_ATTACK_01;
				unset EXISTED_ATTACKER;
				FAILURE=0;
				ATTACKER=0;
				START_FLAG_03=0;
				
				# Nmap 网络扫描仪监测
				if [ ! -f "$NMAP_FILE_MAIN" ];then
					echo -e "# 检测到的 Nmap 网络扫描仪 IP：\n" >"$NMAP_FILE_MAIN";
				fi
				if [ "$(journalctl -u ssh |grep "$DATE_01" |grep "error: kex_exchange_identification")" != "" ];then
					Time_Contrast "$START_FLAG_02" "error: kex_exchange_identification" "$CURRENT_TIME";
					if [ "$TMP_HANG_01" -ge 1 ];then
						if [ "$(journalctl -u ssh |grep "$DATE_01" |grep "error: kex_exchange_identification" |grep "Connection closed by remote host")" != "" ];then
							Time_Contrast "$START_FLAG_02" "error: kex_exchange_identification" "$CURRENT_TIME" "Connection closed by remote host";
							if [ "$TMP_HANG_01" != 0 ];then
								HOST_1="$(journalctl -u ssh |grep "$DATE_01" |grep "Connection closed by" |grep "port" |grep -v "preauth" |tail -n "$TMP_HANG_01" |awk '{ print $9 }' |awk '!visited[$0]++')";
								NMAP_SV=1;
								START_FLAG_03="$((START_FLAG_03+1))";
								ERROR_01=1;
							fi
						fi
						if [ "$(journalctl -u ssh |grep "$DATE_01" |grep "error: kex_exchange_identification" |grep "read: Connection reset by peer")" != "" ];then
							Time_Contrast "$START_FLAG_02" "Connection reset by" "$CURRENT_TIME" "port" "authenticating";
							if [ "$TMP_HANG_01" != 0 ];then
								HOST_2="$(journalctl -u ssh |grep "$DATE_01" |grep "Connection reset by" |grep "port" |tail -n "$TMP_HANG_01" |awk '{ print $9 }' |awk '!visited[$0]++')";
								NMAP_ST=1;
								START_FLAG_03="$((START_FLAG_03+2))";
								ERROR_01=1;
							fi
						fi
						if [ "$(journalctl -u ssh |grep "$DATE_01" |grep "error: kex_exchange_identification" |grep "banner line contains invalid characters")" != "" ];then
							Time_Contrast "$START_FLAG_02" "banner exchange: Connection from" "$CURRENT_TIME" "invalid format";
							if [ "$TMP_HANG_01" != 0 ];then
								HOST_3="$(journalctl -u ssh |grep "$DATE_01" |grep "banner exchange: Connection from" |grep "invalid format" |tail -n "$TMP_HANG_01" |awk '{ print $10 }' |awk '!visited[$0]++')";
								NMAP_SCRIPT=1;
								START_FLAG_03="$((START_FLAG_03+4))";
								ERROR_01=1;
							fi
						fi
					fi
				fi
				if [ "$(journalctl -u ssh |grep "$DATE_01" |grep "Unable to negotiate with" )" != "" ] \
				|| [ "$(journalctl -u ssh |grep "$DATE_01" |grep "error: Protocol major versions differ")" != "" ];then
					Time_Contrast "$START_FLAG_02" "Unable to negotiate with" "$CURRENT_TIME" "no matching host key type found. Their offer";
					if [ "$TMP_HANG_01" != 0 ];then
						HOST_4="$(journalctl -u ssh |grep "$DATE_01" |grep "Unable to negotiate with" |grep "no matching host key type found. Their offer" |tail -n "$TMP_HANG_01" |awk '{ print $10 }' |awk '!visited[$0]++')";
						NMAP_ALL=1;
						START_FLAG_03="$((START_FLAG_03+8))";
						ERROR_01=1;
					fi
				fi
				
				if [ "$NMAP_SV" != 0 ] \
				|| [ "$NMAP_ST" != 0 ] \
				|| [ "$NMAP_SCRIPT" != 0 ] \
				|| [ "$NMAP_ALL" != 0 ];then
					HOST_0="$(printf "$HOST_1\n$HOST_2\n$HOST_3\n$HOST_4" |grep -v '^$' |awk '!visited[$0]++')";
					EXISTED_HOST="$(grep -v '^$' "$NMAP_FILE_MAIN")";
					if [ "$(echo "$EXISTED_HOST" |grep -v '^$' |awk '!visited[$0]++' |awk 'END{print NR}')" -eq "$(echo -e "$EXISTED_HOST\n$HOST_0" |grep -v '^$' |awk '!visited[$0]++' |awk 'END{print NR}')" ];then
						printf "\033[1m「\033[1;32mINFO\033[1;37m」 %s: \033[34m检测到网络/端口扫描仪流量（似乎是 Nmap），来源： %s （01）。\033[0m\n" "$CUR_TIME" "$HOST_0";
						ERROR_01=1;
					elif [ "$HOST_0" != "" ];then
						printf "\033[1m「\033[1;32mINFO\033[1;37m」 %s: \033[34m检测到网络/端口扫描仪流量（似乎是 Nmap），来源： %s （01）。已将攻击者ip记录存档至%s。\033[0m\n" "$CUR_TIME" "$HOST_0" "$NMAP_FILE_MAIN";
						echo -e "$HOST_0" >>"$NMAP_FILE_MAIN";
						ERROR_01=1;
					fi
					
					unset HOST_0;
					unset HOST_1;
					unset HOST_2;
					unset HOST_3;
					unset HOST_4;
					case $START_FLAG_03 in 
						0)
							printf "\033[1m「\033[1;32mINFO\033[1;37m」          |可能的命令： nmap < -p 2023> %s \n\033[0m" "$ADD_IP";
							printf "「\033[32mINFO\033[0m」          \\这似乎只是简单的 nmap -sS 基本扫描。\n";
							ERROR_01=1;
						;;
						
						1)
							printf "\033[1m「\033[1;32mINFO\033[1;37m」          |可能的命令： nmap -sV < -sT> < -p 2023>  %s \n\033[0m" "$ADD_IP";
							printf "「\033[32mINFO\033[0m」          \\监测到的扫描类型：普通服务扫描（因 -sV 扫描是建立在 TCP 端口扫描的基础上的，故无法判断是否使用了 -sT 选项）。\n";
							ERROR_01=1;
						;;
						
						2)
							printf "\033[1m「\033[1;32mINFO\033[1;37m」          |可能的命令： nmap -sT < -p 2023>  %s \n\033[0m" "$ADD_IP";
							printf "「\033[32mINFO\033[0m」          \\监测到的扫描类型：TCP 端口扫描。\n";
							ERROR_01=1;
						;;
						
						3)
							printf "\033[1m「\033[1;32mINFO\033[1;37m」          |可能的命令： nmap -sV -sT < -p 2023>  %s \n\033[0m" "$ADD_IP";
							printf "「\033[32mINFO\033[0m」          \\监测到的扫描类型：普通服务扫描，TCP 端口扫描\n";
							ERROR_01=1;
						;;
						
						4)
							printf "\033[1m「\033[1;32mINFO\033[1;37m」          |可能的命令： nmap {-sC 或-script=\"<脚本类型>\" ...} < -p 2023>  %s \n\033[0m" "$ADD_IP";
							printf "「\033[32mINFO\033[0m」          \\监测到的扫描类型：NSE 脚本扫描。\n";
							ERROR_01=1;
						;;
						
						5)
							printf "\033[1m「\033[1;32mINFO\033[1;37m」          |可能的命令： nmap -sV {-sC 或-script=\"<脚本类型>\" ...} < -p 2023>  %s \n\033[0m" "$ADD_IP";
							printf "「\033[32mINFO\033[0m」          \\监测到的扫描类型：普通服务扫描，NSE 脚本扫描。\n";
							ERROR_01=1;
						;;
						
						6)
							printf "\033[1m「\033[1;32mINFO\033[1;37m」          |可能的命令： nmap -sT {-sC 或-script=\"<脚本类型>\" ...} < -p 2023>  %s \n\033[0m" "$ADD_IP";
							printf "「\033[32mINFO\033[0m」          \\监测到的扫描类型：TCP 端口扫描，NSE 脚本扫描。\n";
							ERROR_01=1;
						;;
						
						7)
							printf "\033[1m「\033[1;32mINFO\033[1;37m」          |可能的命令： nmap -sT -sV {-sC 或-script=\"<脚本类型>\" ...} < -p 2023>  %s \n\033[0m" "$ADD_IP";
							printf "「\033[32mINFO\033[0m」          \\监测到的扫描类型：TCP 端口扫描，普通服务扫描，NSE 脚本扫描。\n";
							ERROR_01=1;
						;;
						
						8)
							printf "\033[1m「\033[1;32mINFO\033[1;37m」          |可能的命令： nmap -A < -p 2023>  %s \n\033[0m" "$ADD_IP";
							printf "「\033[32mINFO\033[0m」          \\监测到的扫描类型：-A 综合扫描。\n";
							ERROR_01=1;
						;;
						
						9)
							printf "\033[1m「\033[1;32mINFO\033[1;37m」          |可能的命令： nmap -sV {-sC 或-script=\"<脚本类型>\" 或-A ...} < -p 2023>  %s \n\033[0m" "$ADD_IP";
							printf "「\033[32mINFO\033[0m」          \\监测到的扫描类型：普通服务扫描（因 -sV 扫描是建立在 TCP 端口扫描的基础上的，故无法判断是否使用了 -sT 选项），综合或 NSE 脚本扫描。\n";
							ERROR_01=1;
						;;
						
						10)
							printf "\033[1m「\033[1;32mINFO\033[1;37m」          |可能的命令： nmap -sT {-sC 或-script=\"<脚本类型>\" 或-A ...} < -p 2023>  %s \n\033[0m" "$ADD_IP";
							printf "「\033[32mINFO\033[0m」          \\监测到的扫描类型：TCP 端口扫描，综合或 NSE 脚本扫描。\n";
							ERROR_01=1;
						;;
						
						11)
							printf "\033[1m「\033[1;32mINFO\033[1;37m」          |可能的命令： nmap -sT -sV {-sC 或-script=\"<脚本类型>\" 或-A ...} < -p 2023>  %s \n\033[0m" "$ADD_IP";
							printf "「\033[32mINFO\033[0m」          \\监测到的扫描类型：TCP 端口扫描，普通服务扫描，综合或 NSE 脚本扫描。\n";
							ERROR_01=1;
						;;
						
						12)
							printf "\033[1m「\033[1;32mINFO\033[1;37m」          |可能的命令： nmap -A {-sC 或-script=\"<脚本类型>\" ...} < -p 2023>  %s \n\033[0m" "$ADD_IP";
							printf "「\033[32mINFO\033[0m」          \\监测到的扫描类型：NSE 脚本扫描，综合扫描。\n";
							ERROR_01=1;
						;;
						
						13)
							printf "\033[1m「\033[1;32mINFO\033[1;37m」          |可能的命令： nmap -sV -A {-sC 或-script=\"<脚本类型>\" ...} < -p 2023>  %s \n\033[0m" "$ADD_IP";
							printf "「\033[32mINFO\033[0m」          \\监测到的扫描类型：普通服务扫描，NSE 脚本扫描，综合扫描。\n";
							ERROR_01=1;
						;;
						
						14)
							printf "\033[1m「\033[1;32mINFO\033[1;37m」          |可能的命令： nmap -sT -A {-sC 或-script=\"<脚本类型>\" ...} < -p 2023>  %s \n\033[0m" "$ADD_IP";
							printf "「\033[32mINFO\033[0m」          \\监测到的扫描类型：TCP 端口扫描，NSE 脚本扫描，综合扫描。\n";
							ERROR_01=1;
						;;
						
						15)
							printf "\033[1m「\033[1;32mINFO\033[1;37m」          |可能的命令： nmap -sT -sV -A {-sC 或-script=\"<脚本类型>\" ...} < -p 2023>  %s \n\033[0m" "$ADD_IP";
							printf "「\033[32mINFO\033[0m」          \\监测到的扫描类型：TCP 端口扫描，普通服务扫描，NSE 脚本扫描，综合扫描。\n";
							ERROR_01=1;
						;;
						
						*)
							printf "Amazing...02";
						;;
						
					esac
					START_FLAG_03=0;
					unset EXISTED_HOST;
				fi
				
				# Netcat 和 Windows Test-NetConnection函数 监测
				if [ "$WARNING_SRV" -lt 2 ];then
					if [ "$NMAP_SV" != 0 ] \
					&& [ "$NMAP_ST" -eq 0 ] \
					&& [ "$NMAP_SCRIPT" -eq 0 ] \
					&& [ "$NMAP_ALL" -eq 0 ];then
						printf "\n";
						printf "「\033[34mINFO\033[0m」 \033[33m请注意\033[0m：\033[1m仅 -sV 普通服务扫描\033[0m不是 Nmap 的默认扫描选项。或许应该考虑 Netcat 的 -z 选项或者 Windows 的 Test-NetConnection 函数？\n";
						printf "「\033[34mINFO\033[0m」        |可能的 Netcat 命令：for i in \$(seq 2020 2030); do nc -zv -w 1 %s \$i; done\n" "$ADD_IP";
						printf "「\033[34mINFO\033[0m」        |可能的 Test-NetConnection 命令：Test-NetConnection --port 2023 %s\n" "$ADD_IP";
				                printf "「\033[34mINFO\033[0m」        \\或：foreach (\$port in 1..1024) {If ((\$a=Test-NetConnection 192.168.50.151 -Port \$port -WarningAction SilentlyContinue).tcpTestSucceeded -eq \$true){ \"TCP port \$port is open\"}}\n";
						WARNING_SRV="$((WARNING_SRV+1))";
					fi
				fi
				
				# Windows TcpClient Socket对象 监测
				if [ "$WARNING_TCP" -lt 2 ];then
					if [ "$NMAP_SV" -eq 0 ] \
					&& [ "$NMAP_ST" != 0 ] \
					&& [ "$NMAP_SCRIPT" -eq 0 ] \
					&& [ "$NMAP_ALL" -eq 0 ];then
						printf "\n";
						printf "「\033[34mINFO\033[0m」 \033[33m请注意\033[0m：\033[1m仅 TCP 端口扫描\033[0m不是 Nmap 的默认扫描选项，亦不是常用选项。或许应该考虑 Windows 的 TcpClient Socket对象？\n";
						printf "「\033[34mINFO\033[0m」        |可能的 TcpClient 命令：1..1024 | %% {echo ((New-Object Net.Sockets.TcpClient).Connect(\"192.168.50.151\", \$_ )) \"TCP port \$_ is open\"} 2>\$null\n";
						WARNING_TCP="$((WARNING_TCP+1))";
					fi
				fi
				
				NMAP_SV=0;
				NMAP_ST=0;
				NMAP_SCRIPT=0;
				NMAP_ALL=0;
				
				ERROR_TIMES=0;
				
				if [ "$(journalctl -u ssh |grep "$DATE_01" |grep "Accepted password")" != "" ] \
				&& [ "$(journalctl -u ssh |grep "$DATE_01" |grep "Accepted password" |awk '{ print $3 }' |awk -F: '{ print $1$2$3 }' |tail -n 1)" -ge "$CURRENT_TIME" ];then
					if [ "$ERROR_01" -eq 0 ];then
						rm -f "$TMP_FILE";
						printf "「\033[33mWARN\033[0m」 %s: \033[33m似乎未监测到异常攻击流量，但 SSH 连接似乎已建立，中止监测。请检查是否为内部人员登录或者二次攻击。\033[0m\n" "$CUR_TIME";
						sleep 2s;
						exit 024;
					elif [ "$ERROR_01" -eq 2 ];then
						printf "\033[1m「\033[1;32mINFO\033[1;37m」 %s: \033[1;34m虽然看起来不太可能，但是攻击者似乎已成功爆破 SSH 弱口令密码。\033[0m\n" "$CUR_TIME";
						printf "\033[1m「\033[1;32mINFO\033[1;37m」\033[1;33m          |（这极有可能是使用社工类字典的密码爆破攻击，请对内部人员进行审查。）\033[0m\n";
						sleep 0.5s;
					else
						printf "\033[1m「\033[1;32mINFO\033[1;37m」 %s: \033[1;35m攻击者似乎已成功获得 SSH 弱口令密码。\033[0m\n" "$CUR_TIME";
						sleep 0.5s;
					fi
				fi
				
				if [ "$(ps -U kali -C sh -F -l -M |grep kali |grep "sshd:" |grep -v grep)" != "" ];then
					printf "\n\033[1m「\033[1;32mINFO\033[0m\033[1m」 %s: \033[0m\033[1;32m检测到 SSH 连接已建立（01）。\033[0m\n" "$CUR_TIME";
					sleep 0.5s;
					CRITICAL_SHUTDOWN=1;
				fi
			else
				if [ "$START_FLAG_02" -eq 0 ];then
					sleep 0.5s;
				fi
				ERROR_TIMES="$((ERROR_TIMES+1))";
			fi
		fi
		
		if [ "$START_FLAG_02" -eq 1 ];then
			sleep 0.1s;
			CUR_TIME="$(date +"%T")";
			CURRENT_TIME="$(date +"%H%M%S")";
		fi
		
		if [ "$START_FLAG_02" -eq 0 ];then
			sleep 0.5s;
		fi
		
		if [ "$CRITICAL_SHUTDOWN" -ge 1 ];then
			CRITICAL_SHUTDOWN="$((CRITICAL_SHUTDOWN+1))";
			sleep 0.5s;
		fi
		if [ "$CRITICAL_SHUTDOWN" -ge 10 ];then
			printf "「\033[31mERROR\033[0m」支持环境未响应！终止监测！\n";
			printf "「\033[34mINFO\033[0m」\033[34m返回代码：\033[31mErrorCode 01\033[0m\n";
			systemctl stop ssh;
			rm -f "$TMP_FILE";
			echo -e "\033[1;5;31m#################################################################\033[0m";
			printf "\033[1;5;31m## 「CRITICAL」 SSH 蜜罐核心进程异常！！紧急终止 SSH 服务！！  ##\033[0m\n";
			printf "\033[1;5;31m## 「CRITICAL」 返回代码：CRITICALCode 04                      ##\033[0m\n";
			echo -e "\033[1;5;31m#################################################################\033[0m";
			sleep 2s;
			exit 005;
		fi
	done
	printf "\n\033[1m「\033[1;32mINFO\033[0m\033[1m」 %s: \033[0m\033[1;32m检测到 SSH 连接已建立（00），中止监测。\033[0m\n" "$CUR_TIME";
	cp "$NMAP_FILE_MAIN" "$IP_FILE";
	cat "$HYDRA_FILE_MAIN" >> "$IP_FILE";
	if [ -s "$IP_FILE" ];then
		sort -u "$IP_FILE" > "$TMP_FILE";
		mv "$TMP_FILE" "$IP_FILE";
	fi
	case "$FORMAT" in
		json)
			;;
			
		xml)
			if [ "$EXE_LACK" -ge 1 ];then
				printf "\n「\033[33mWARN\033[0m」 %s: \033[33m警告：二进制文件缺失，可能无法进行格式转换。\033[0m\n" "";
			fi
			json_to_xml "$IP_FILE" > "$TMP_FILE";
			mv "$TMP_FILE" "$IP_FILE";
			;;
			
		csv)
			if [ "$EXE_LACK" -ge 1 ];then
				printf "\n「\033[33mWARN\033[0m」 %s: \033[33m警告：二进制文件缺失，可能无法进行格式转换。\033[0m\n" "";
			fi
			json_to_csv "$IP_FILE" > "$TMP_FILE";
			mv "$TMP_FILE" "$IP_FILE";
			;;
			
		*)
			;;
			
	esac
	rm -f "$TMP_FILE";
	sleep 2s;
	exit 000;
else
	rm -f "$TMP_FILE";
	printf "\033[1m「\033[1;31mCRITICAL\033[0m\033[1m」\033[0m\033[1;31m支持环境异常，紧急终止！\033[0m\n";
	printf "「\033[34mINFO\033[0m」\033[34m返回代码：\033[1;31mCRITICALCode 03\033[0m\n";
	sleep 2s;
	exit 004;
fi

printf "恭喜解锁彩蛋 —— —— 作者的精神状态：(*O*)\n";sleep 2s;
printf "              _____                                                                           _____ \n";
printf "             | ____|                                                                         |____ |\n";
printf "             ||        _____________                                   _____________              ||\n";
printf "             ||      _|  _________  |_                               _|  _________  |_            ||\n";
printf "             ||     |  _|  ____   |_  |                             |  _|  ____   |_  |           ||\n";
printf "             ||     | |  _| __ |_   | |                             | |  _| __ |_   | |           ||\n";
printf "             ||     | | | -    - |  | |                             | | | -    - |  | |           ||\n";
printf "             ||     | | ||      ||  | |                             | | ||      ||  | |           ||\n";
printf "             ||     | | |_- __ -_-_ | |                             | | |_- __ -_-_ | |           ||\n";
printf "             ||     | |_  |____| -__|_|                             | |_  |____| -__|_|           ||\n";
printf "             ||     |_  |_________                                  |_  |_________                ||\n";
printf "             ||       |___________|                                   |___________|               ||\n";
printf "             ||                       _____________________________                               ||\n";
printf "             ||____                  |_________________________    |                          ____||\n";
printf "             |_____|                                           |___|                         |_____|\n";
printf "\e[14A\033[?25l\033[1m";
printf "  呜～哈哈\n";sleep 0.9s;
printf "\t呀哈哈哈\n";sleep 1.2s;
printf " 哦哈哈哈哈\n";sleep 1s;
printf "\t啊哈哈哈\n";sleep 1.5s;
printf "  呀～～～\n";sleep 2.1s;
printf "\t 吐气～\n";sleep 1.5s;
printf " 喝口水压压惊\n";sleep 0.7s;
printf "\t点个蚊香庆祝一下\n";sleep 0.9s;
printf "    我～擦！！\n";sleep 1.4s;
printf "\t就这？\n";sleep 1.9s;
printf "嘿～\n";sleep 0.3s;
printf "\t   小样～\n";sleep 1.6s;
printf "  这不轻轻松松嘛！\n";sleep 5s;
printf "\033[?25h\033[0m\n\n\n";

printf "PS: 能解锁这个彩蛋就表明你发现了一个相当神奇的 Bug 。请务必告知本人！（有酬）\n";
printf "  作者邮箱 ： < kjx52@outlook.com > \n\n";
printf "感谢使用。\n";
sleep 10s;

exit 0;


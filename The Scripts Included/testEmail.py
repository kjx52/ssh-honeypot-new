#!/usr/bin/python3
# -*- coding: UTF-8 -*-
#/*警告邮件发送脚本*/
# 作者 ： Jessarin000
# 日期 ： 2023-09-17
# 版本 ： 0.5
#
#本脚本使用 Python3 开发。
#通常情况下，本脚本调用的模块已与 Python3 捆绑安装。
#
##注意：·请 务必 修改本脚本配置以适应当前测试环境！！
##     ·遇到任何问题或错误请联系作者。
#

import smtplib
from email import encoders
from email.header import Header
from email.mime.text import MIMEText
from email.utils import parseaddr, formataddr
import sys
import os


def send_mail(dtime,duser,dip,dhostname):
	#基础信息
	# from_addr = input("From:")
	from_addr = "1234567890@qq.com"      #发送邮箱号。
	password = "xxxxxxxxxxxxxxxx"      #发送邮箱授权Token。
	#to_addr = from_addr
	to_addr = "1234567890@qq.com"      #目标邮箱号。
	# password = raw_input("Password:")
	# to_addr = input("To:")
	
	def _format_addr(s):
    		name, addr = parseaddr(s)
    		return formataddr((Header(name, 'utf-8').encode(), addr))
	
	time = os.popen('date +%T-%F').read()
	time = time.replace("\n","")
	smtp_server = "smtp.qq.com"
	mimetex = '您的机器:',dhostname,'，于:',dtime,'，被IP:',dip,'以账号',duser,'进行登录,请确认是否为已授权人员！'
		
	msg = MIMEText(''.join(mimetex), 'plain', 'utf-8')
	msg['From'] = _format_addr("1234567890@qq.com")      #发送邮箱号。
	msg['To'] = _format_addr("1234567890@qq.com")      #目标邮箱号。
	msg['Subject'] = Header("警告：具有潜在威胁的SSH登录！", 'utf-8').encode()
	
	server = smtplib.SMTP_SSL(smtp_server, 465)
	server.set_debuglevel(1)
	server.login(from_addr, password)
	server.sendmail(from_addr, [to_addr], msg.as_string())
	server.quit()


if __name__ == "__main__":
    send_mail(sys.argv[1], sys.argv[2], sys.argv[3], sys.argv[4])

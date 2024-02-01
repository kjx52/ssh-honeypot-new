# Win SSH 蜜罐/SSH-Honeypot For Windows

### 一个 SSH蜜罐的快速部署脚本，基于Windows-OpenSSH。

  本项目为原 Linux SSH 蜜罐的分支，用于在 Windows 环境下自动化部署 SSH 弱口令蜜罐项目，基于 Windows-OpenSSH，无前置项目。

作者 ： Jessarin000 ，本名 Kjx52 ，现名 Skiner。
日期 ： 2023-10-25

> %警告：可能对系统产生非预期的影响！%

> %建议在虚拟环境（VM或Docker）下运行！% 

*有任何意见或建议请联系作者：< kjx52@outlook.com >

*详细说明可以在 < https://xz.aliyun.com/t/12928 >中找到。

本项目原理为修改原SSH 默认连接终端 CMD 为指定伪终端Bacsh（Winbash），模拟Linux下的 Chroot 环境，从而限制攻击者的路径变迁以及代码执行。

**本项目所有可执行文件均由 DEV C++ 5.11 进行编译。**

在*Win_Deployment_Program*目录下有使用NSIS完成封装的安装程序，运行后即可将所有部件添加至*C:\Users\Public\SSHShell*文件夹及桌面。
由于本项目特殊性，请在运行安装程序后以管理员的身份运行*SSH_Deployment_Program.exe*，以自动化设置文件权限以及添加弱口令用户。

详细信息请看 SSH_Deployment_Program.exe。
> 本项目：
>>        默认创建账户为 kali，密码为 kjx00000；
>>        默认创建目录为 C:\Users\kali\Shell
>>        默认无法创建文件。
>>        默认蜜罐终端为 Bacsh。
>>        默认情况下，攻击者在蜜罐中可使用的命令为：cd，ls，cat，cls，pwd以及它们的别名。
>>        补丁添加的命令为：whoami，hostname，id，touch，mkdir和rm，可以从Patch目录下找到它们。 

****(注意：本项目的正常执行与配套终端 Bacsh 有着直接联系，除非你确定你已经有了更好的选择，否则强烈不建议修改 SSHD 终端配置！)****

* 本项目于 2024-02-02 更新，使用 C族语言实现。
* 本项目搭建环境为 Windows 11。
* 注意：
   1. 请在默认活动编码为936（中文-简体）的终端环境下启动本项目终端Bacsh，否则可能引发乱码问题，更多语言版本请联系作者。
   2. 本项目需修改用户变量（添加 SSH 弱口令用户）以及注册表项（ SSH 默认终端），故请以管理员身份运行此程序。
   3. 遇到任何问题或错误请联系作者。

\***将在未来版本中试着加入客户端攻击。**

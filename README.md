# SSH 蜜罐/SSH-Honeypot

### 一个 SSH蜜罐的快速部署脚本，基于Linux-OpenSSH。

  这是一个轻量化的 SSH弱口令蜜罐项目，基于 Debian-Linux 的 OpenSSH，无前置项目。

作者 ： Jessarin000 ，本名 Kjx52 ，现名 Skiner。

> %警告：可能对系统产生非预期的影响！%

> %建议在虚拟环境（VM或Docker）下运行！% 

有任何意见或建议请联系作者：<kjx52@outlook.com>

更详细说明可以在< *https://xz.aliyun.com/t/12884* >中找到。

***在启动此脚本前请查看并配置脚本以适应您的系统。***

**\*请注意在运行 __SSH 蜜罐集成启动器__ 时 ___一定不要___ 最小化所有打开窗口并露出桌面！否则可能会出现很糟糕的后果。**

本项目原理为在 Chroot的隔离目录下建立拥有弱口令的SSH服务账户目录，诱导攻击者进行网络攻击，
从而牵制行动并记录其行为以及ip等信息。

在*完全部署脚本*目录下有使用base64编码完成封装的压缩脚本，运行后即可将快速部署脚本及其启动器添加至桌面。

详细信息请看 SSHdeployment_F.sh。

* 本项目于 2023-09-25 完成，使用 sh脚本实现。
* 本项目搭建环境为 Kali-Linux[^Kali-Linux]。
* 本项目已测试 Linux环境包括：
  1. 测试内核发行号为：
     > 6.1.0-kali9-amd64 
     
     > 5.17.5-zen1-1-zen 
     
     > 4.8.0-52-generic 
  2. 测试内核版本号为：
     > #1 SMP PREEMPT_DYNAMIC Debian 6.1.27-1kali20231 
     
     > #55~16.04.1-Ubuntu SMP Fri Apr 28 14:36:29 UTC 2017 
  3. 测试架构为：
     > x86_64 
     
     > x86 
     
     > ARM 
 * 注意：
   1. 本程序需要 zsh Shell。
   2. 请在默认语言为中文的 Linux 环境下启动此脚本，否则可能引发不可预知的错误。更多语言版本请联系作者。
   3. 若出现权限问题，请使用 sudo 提权运行或使用配套的启动器。
   4. 遇到任何问题或错误请联系作者。

  \***Windows 版本搭建程序已作为本项目分支发布，详情请查看本项目 Win-SSH-Honeypot 分支。**

  \***将在未来版本中试着加入客户端攻击。**
  
*****
  
# SSH Honeypot/SSH-Honeypot

### A quick deployment script for SSH honeypots, based on Linux-OpenSSH.

   This is a lightweight SSH weak password honeypot project, based on OpenSSH of Debian-Linux, with no pre-project.

Author: Jessarin000, real name Kjx52, current name Skiner.

> %Warning: May have unexpected effects on the system! %

> %It is recommended to run in a virtual environment (VM or Docker)! %

If you have any comments or suggestions, please contact the author: <kjx52@outlook.com>

More detailed instructions can be found in < *https://xz.aliyun.com/t/12884* >.

***Please review and configure the script to suit your system before launching this script. ***

**\*Please note that when running the __SSH Honeypot Integrated Launcher__ ___MUST NOT___ minimize all open windows and expose the desktop! Otherwise there may be very bad consequences. **

The principle of this project is to establish an SSH service account directory with a weak password in the isolation directory of Chroot to induce attackers to carry out network attacks.
This will contain the action and record its behavior and IP and other information.

There is a compressed script encapsulated using base64 encoding in the *Full Deployment Script* directory. After running, the quick deployment script and its launcher can be added to the desktop.

See SSHdeployment_F.sh for details.

* This project was completed on 2023-09-25 and was implemented using sh script.
* The construction environment of this project is Kali-Linux[^Kali-Linux].
* This project has been tested on Linux environments including:
   1. The test kernel release number is:
      > 6.1.0-kali9-amd64
     
      > 5.17.5-zen1-1-zen
     
      > 4.8.0-52-generic
   2. The test kernel version number is:
      > #1 SMP PREEMPT_DYNAMIC Debian 6.1.27-1kali20231
     
      > #55~16.04.1-Ubuntu SMP Fri Apr 28 14:36:29 UTC 2017
   3. The test structure is:
      >x86_64
     
      >x86
     
      > ARM
  * Notice:
    1. This program requires zsh Shell.
    2. Please start this script in a Linux environment where the default language is Chinese, otherwise unpredictable errors may occur. Please contact the author for more language versions.
    3. If permission issues occur, please use sudo to run with elevated privileges or use the supporting launcher.
    4. If you encounter any problems or errors, please contact the author.

   \***The Windows version building program has been released as a branch of this project. For details, please check the Win-SSH-Honeypot branch of this project. **

   \***We will try to add client-side attacks in future versions. **


[^Kali-Linux]: 6.1.0-kali9-amd64 #1 SMP PREEMPT_DYNAMIC Debian 6.1.27-1kali1 (2023-05-12) x86_64 GNU/Linux

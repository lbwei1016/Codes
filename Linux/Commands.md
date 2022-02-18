# Help
- `man`: man page
    - `/ [search item]`: to search
# Directory and File
## Go To
- `cd ~` : 回到家目錄
- `cd ~[account]` : 到[account]的家目錄
- `cd`: 回到家目錄
- `cd` .. : 前往上層目錄
- `cd` - : 回到上一個工作目錄
- `.` : 代表當前目錄
- `..` : 代表上一層目錄

## Manipulation
- `pwd [-P]` : 顯示目前所在的目錄； `-P` ： 顯示出確實的路徑，而非使用連結 (link) 路徑
- `mkdir [-mp]`: -m : 設定權限(e.g. 711)；`-p` : 遞迴操作(整層)
- `rmdir [-p]` : 刪除「空」目錄；`-p` : 遞迴操作
- `basename [/.../...]` : 顯示「檔名」 
- `dirname [/.../...]` : 顯示「目錄名」
- `cp [-a][-r][-i] [from] [to]` : 複製檔案(目錄)；`-a` : 基本上代表複製原檔案的一切(包括權限) ；`-r` : 遞迴複製(用於目錄)；`-i` : 出現警告訊息
- `scp`: 將檔案從本機複製到遠端或從遠端複製到本機
    - `scp [帳號@來源主機]:來源檔案 [帳號@目的主機]:目的檔案`
    - 若為本機可以省略 `[帳號@主機]` 
- `touch [file]` : 修改檔案時間 (建立新檔案)
- `rm [-i][-r]` : 刪除檔案(參數意義同 `cp`)
- `mv [-i] [from(name A)] [to (name B)]` : 移動、重新命名檔案
- 檔名為 "`-`" 的檔案要用絕對路徑來開啟：`./-`
- 檔名有空白鍵：`vi "a file with spaces"`
- `file [filename]`: 顯示檔案類型 (*dat, ASCII, etc*)
- `wc [file1] [file2]` : 輸出檔案的換行數、字數與位元組數
    - `wc -l` : 換行數
    - `wc -w` : 字數
    - `wc -c` : 位元組數
    - `wc -m` : 字元數
- `diff [option] [file1 file2...]` : output the difference between files
## Searching
- `which [-a] [command]`: 根據 PATH 找出執行檔的完整檔名
    - `a`: 列出所有結果 (不只第一項) 
- `whereis [file or dir name]`: 在**特定目錄**下搜尋
    - `whereis -l`: 列出**特定目錄** (**特定目錄**是系統設定值)
- `locate [-i] [num] [keyword]`: 在資料庫 `/var/lib/mlocate/` 之中搜尋 (not built-in)
    - `-i`: 忽略大小寫
    - `[num]`: 僅輸出 `num` 行
> `updatedb`: 更新資料庫 (可能要數分鐘)
- `find [-specifics]` : 找尋**當前和子目錄中**符合條件的檔案(目錄)

    - `find -size 1033c`: 大小為`1033 byte`的檔案
    - `find -user [owner] -group [group name]` : 檔案擁有者及群組
    - `find [-...] 2>/dev/null` : 排除因權限無法存取的檔案

- `grep [pattern] [file1/dir1] [file2/dir2]` : Find the **files** that matches the pattern

    > `grep`represents for `g/RE/p` 
    >
    > 可以用一般關鍵字或正規表示法
    >
    > Note: `grep`only support BREs (basic regular expressions); for EREs (extended regular expressions), use `egrep` 

    - `grep -q [...]`: If `pattern` is found, exit with code `0`, otherwise `1`
    - `grep -i [...]`: 忽略大小寫
    - `-n`: 標示行號
    - `-v`: 反向匹配 (排除 `pattern`)
    - `-r`: recursively
    - `-w`: 尋找整個單字
    - `-c`: count the number of occurences

- `egrep 'word1|word2' /path/to/file`: 匹配數個單字 
## Permission
- `umask [SOGO]`: 設定新建檔案的預設權限
    - `S`: 特殊權限
    - `O`: 持有者
    - `G`: 群組
    - `O`: 其他人
    > 注意: `umask` 的設定值表示使用者所**失去**的權限！！
- `chgrp [-R] [group] [file/dir]` : 更改群組 (root)
- `chown [-R] [user:group] [file/dir]` : 更改擁有者 (群組也可以 : `user:group`) (root)
- `chmod [-R] [xyz] [file/dir]` : 檔案權限更改 
    - `r` : 4
    - `w` : 2
    - `x` : 1
    >*e.g. `chmod -R 720 myfile`*
- ***Setuid, Setgid, Sticky BIT***
- ***setuid*** : `chmod "4"751`；cancel : `chmod [0]751`
    > 檔案加入 `setuid` 權限後, 其他用戶可以用檔案**持有者**身份**執行**檔案  
    e.g. `-rws-r-x---`: the ***s***


- ***setgid*** : `chmod "2"751`；cancel : `chmod [0]751`
    > 檔案加入 `setgid` 權限後, 其他用戶可以用該檔案**群組**身份**執行**檔案  
    e.g. `-rwx--sr-x`: the ***s***

- ***sticky bit*** : `chmod "+t" [file]`
    > If a directory has `sticky bit` and user *A* has authority `w` and `x`, then the files created by *A* can only be deleted by *A* herself or *root*.  
    e.g. `drwxrwxrwt`: the ***t*** 

## Read File Content
- `cat` : read the whole file
- `tac` : reversed `cat`
- `nl` : like `cat` but with better line numbers
- `more` : with pages to read
- `less` : enhanced `more`
- `head` : read a few lines from beginning (default 10 lines)
- `tail` : read a few lines at the button (default 10 lines)
- `od` : read binary file
## Compression / Archive File
- `gzip [-c] [file]` : To compress file to `.gz`
    - `-c` : to decompress and output on STDOUT (equivalent to `zcat [file]`)
    
- `bzcat [file]` : decompress `.bzip` 

- `tar [-cxfv] [file]` : 
    >`tar` is a computer software utility for collecting many files into one *archive file*, not for compressing files
    - `-c` : create a new `.tar` file
    - `-x` : extract a `.tar` file
    - `-f` : designate a file, otherwise STDIN
    - `-v` : more detailed listing (for even more :  `-vv`)

## Others
- `mktemp`: Generate a temp file or directory
    - `-d`: generate a directory
    - `-p [path]`: generate the tmp file under `[path]` instead of `/tmp`
    - `/tmp/my_tmp_file_XXXXXX.txt`: 指定檔名格式 (*X* 會被替換成亂數)
> Usage: **MY_TMP_FILE=\`mktemp -d /home/gaga\`**

# Process
> A program is dead, a process is alive, an *executable program in action*.<br>
> The first process in Linux is **init** (PID=1)
## Four states of processes
- **running / runnable (R)**
    - Alreay be **running** or waiting **in the queue** for executioin. (***ready*** to run)
- **waiting / sleeping (S: interruptible; D: uninterruptible)**
    - Wait for some events or operations. (***not*** ready to run)
- **stop (T)**
- **zombie (Z)**
    - A process has **completed** its execution, but is waiting to retrieve its exit state. 
    - If it exits, the process is ***dead***.
## List
- `ps`: show processes
- `pstree`: bring up the entire hierarchy of processes
- `top`: show the dynamic view of processes
- `htop`: enhanced `top` (no built-in)
- `jobs`: list all jobs
    > ***job***: A job is a concept used by the shell - any program you **interactively start** that doesn't detach (ie, not a daemon) is a job. <br>
    > ***process***: Any running programs.
## Foreground / Background
- `[command] &`: Execute *command* in bg..
- `fg [no.]`: Bring the job whose number is *no.* to foreground (fg.).
    - `fg`: Bring the last job sent to the bg. to fg.
- `bg [no.]`: Resume the background job with job number *no.*. 
    - `bg`: Resume the default job (with a **+** at its STAT).
> Background processes don't accept input, but they outputs!!!

### References: 
- https://www.westfloridacomponents.com/blog/life-cycle-process-linux/
- https://unix.stackexchange.com/questions/4214/what-is-the-difference-between-a-job-and-a-process

# Streams
>Every program you may run on the command line has 3 streams, STDIN, STDOUT and STDERR.
- `STDIN [0]`
- `STDOUT [1]`
- `STDERR [2]`
  
    > Note: `cat -` means reading STDIN(user input) for `cat`

## Redirection
- `>` : Save output to a file.
- `>>` : Append output to a file.
- `<` : Read input from a file.
- `2>` : Redirect error messages.
- `&>` : Redirect `STDOUT` and `STDERR` to the same place
    - `2>&1` : redirect `STDERR[2]` to `STDOUT[1]`
    > If there isn't `&`, `2>1` will be identified as redirecting to a file naming '1'

## Piping
- `|` : Send the output from left program as input to right program.
    - `cat data.txt | sort | uniq -u`
# Encode / Decode
-  `base64 [file] [-d]` : Encode file with base64 (`-d` to decode)
- `tr [options] [str1] [str2]` :
    - `str1` : translate from
    - `str2` : : translate to
    > Note: characters are corresponded one-by-one between `str1` and `str2`
    
    >*e.g. `tr a-zA-Z n-za-mN-ZA-M`* : Rot13 encoding
- `iconv -f [source format] -t [convert to] -o [output file] [input file]`: change file's encoding
    > *e.g.* `iconv -f BIG-5 -t utf8 -o test.txt test.txt`

    > Note: DON'T repeat converting the same file or *awful* things may occur.
# Network
## nc (netcat)
- `nc [-vul] [host] [port]` : using the `TCP` or `UDP` protocols to read or write data 
- `-v` : verbose message displayed
- `-u` : use `UDP` instead of `TCP`
- `-l` : listen for an incoming connection **rather than** initiating a connection to a remote host
> *e.g. `echo "Hi" | nc -u localhost 8000`* : transmit a `UDP` packet

> *e.g. `nc -lu localhost 8000`* : accept a packet under `UDP`
## SSH (Secure Shell)
- `ssh [-i [file] ]<user>@<host> [-p [port] ]` : login `host` 
- `-i` : use `file` (containing private key) to connect
- `ssh-keygen -t rsa` : generate `RSA` key under `.ssh/`
> To leave SSH, either `exit` or `Ctrl-d` is fine.
## SSL / TLS 
> *Secure Socket Layer / Transport Layer Security*
- `openssl s_client -quiet -connect localhost[:port]` 
- `s_client` : connect to a remote host using `SSL/TLS`
    - `-quiet` : inhibit printing of session and certificate information
    - `-connect [host:port]` : connect to host
## nmap
- `nmap [host]`: scan `host` for information like `ports` and its operating system, etc.
# Variable
- `declare [-ia] [var name]`: declare a variable *(a string in default)*
    - `-i`: number 
    - `-a`: array
- `read [var name]`: read from `STDIN` to a variable
    - ***call value***: `${var name}`
    - ***assign***: `var=$(command)`: `var`'s value is the output of `command`
# Bash
- `bash [-x] [].sh`: execute shell script
    - `-x`: output the process of script-execution
> *Note*: `sh file.sh` may sometimes be not equivalent to `bash file.sh`

> *see difference between `dash` and `bash`*
- `echo $0`: Look up what current shell is.
    - `$0` expands to the name of the shell or shell script. 
# Shell Session
- `screen`
- `tmux`: *terminal multiplexer*
  
    > press `Ctrl-b` before input commands
    >
    > ref: https://blog.gtwang.org/linux/linux-tmux-terminal-multiplexer-tutorial/
    - `pane`: every `pane` is a independent `shell session`
    - `window`
# Scheduling
- `cron`: 
  
    > *every user* has their own `crontab` (including *system* itself)
- `crontab [-erl]`
    - `-e`: edit
    - `-r`: remove
    - `-l`: list current crontable
# Hash (here to check ***data integrity***)
- `md5sum`: MD5 (*Message Digest algorithm 5*)
- `sha256sum`: SHA-256
# Condition and Loop
```bash
#!/bin/bash

# prints 0000, 0001..., 9999 (pads 0)
# the usage {0000..9999} is valid only under bash
for i in {0000..9999}
do
    echo $i
done
# prints 0, 1..., 9999 (no padding)
# for more detailed infor. about "seq", see "Others" sec.
for i in $(seq 0000 9999)
do
    echo $i
done
```
# Variables

```bash
myname=William # tcsh: set myname=William
sayhi="I am ${myname}" # I am William
notsay='I am ${myname}' # I am ${myname}
withBlank=I\ am\ ${myname}
withquote=It\'s\ my\ pleasure
echo `echo William` # William (`` Back quotes, the stdout of the command)

version=$(uname -r) or version=`uname -r` 
echo ${version} # 13.0 RELEASE

myname="$myname Lin" # append
export myname # environment variable: 僅子程序會繼承父程序的環境變數
# tcsh: setenv name Ruby; unsetenv name

unset myname

env or export # 列出環境變數 
set or declare # 列出所有變數

declare -i sum=100+5 # -i: 將變數定義成為整數類型
# echo ${sum}=> 105
declare -r name=William # -r: readonly
```
* `read -p "Please enter your name: " -t 30 name` 

  * `-p`: 顯示提示字元
  * `-t <seconds>`: 等待使用者多久 

  > `tcsh`: `set name=$<` 

# Superuser
- `su`: requires *root's* password (僅身分變為 *root* (uid=0, gid=0, etc)，其他環境變數不變)
    - `su -l [account]`: 取得 *account* 的權限 (輸入 *account* 的密碼)
    - `su -`: 環境變數跟著變
- `sudo`: requires *user's* password
    > edit `/etc/sudoers` or `/usr/local/etc/sudoers` with `visudo`

# Others

- `sort [file]` : Sort the given file

    - `-n`: numeric sort

    - `-o <output file name>`: output the sorting outcome to a file 

      > e.g. `sort -o file.txt file.txt`: output to the same file (do not use `>`)

- `strings [file]` : Prints the printable character sequences that are at least 4 characters long

- `uniq [file]` :  Filter adjacent matching lines 

    - `-c`: precede each output line with 出現次數

- `exit 0`: exit with code `0` 
    - `echo $?`: Look up the latest exit code 

- `timeout`: to limit file executing time

- `seq [-s "STRING"][-w] [FIRST][INCREMENT][LAST]`: Print numbers from FIRST to LAST, in steps of INCREMENT.
    - `-s "STRING"`: use `STRING` to separate numbers *(default: \n)*
    - `-w`: equalize width by *padding* with leading zeroes

- `cut {-c|-b} <number of character or byte> [file]`: 擷取資料

    - `-c`: character
    - `-b`: byte
    - `-d '[delimiter]'`: specify *delimiter* 
    - `-f <num1,num2,...>`: specify which columns are to be cut

        > e.g. `ls -al | cut -c 1-9,40-`: 擷取`ls -al`中第 1 到 9 個字元及第 40 個字元 (含) 以後的資料

- `xargs [-dnp] <command>`: 將 STDIN 的輸入作為 \<command> 的參數使用 (預設為 `/bin/echo`)

    - `-d\n`: 指定 delimiter 為 `＼n` (預設忽略所有空白、換行、tab)
    - `-n <number>`: 指定每一次執行指令所使用的參數個數上限值
    - `-p`: 顯示執行前確認
    - `-t`: 顯示執行的指令 (執行後)

- `hostname`: print your host name

- `ifconfig`: check network status

- `history`: list history commands

    > In BASH, `Ctrl + r`can be used to search for history commands

    - `!!`: execute the last executed command
    - `![n]`: execute the command that is numbered `n` (`history`列表左方的編號)
    - `!<the first few words of a command>`: 輸入指令的開頭的數個字，來執行`history`中符合該條件的最近指令

- `awk '/pattern/{<command>}' <input file>`: **A very powerful language, used to handle scripts...**  

    - `BEGIN{<actions>}`: `actions` are done before extracting input file
    - `END{<actions>}`: `actions` are done before `awk` ends
    - `substr(string, start, end)`: return the substring of `string`from `start` to `end`(if `end` is not specified, then `end`is the end of the file)
    - `split(string, array, deli)`: split `string`by`deli`and store it in`array` 
        - *array*: `arr[1]` => access the first element (index is ***1***)
    - `match()`

- `sed '<pattern and action>' <input file>`:................
- `shutdown`: literally
    - `-r`: reboot
    - `-h`: halt
    - `-p`: halt + poweroff
    - two types of time format
        - `yymmddhhmm`: *2202152330 = 2022/02/15 23:30* (BSD style)
        - `hh:mm` (Linux style)
        - `+[time]` (defualt minute, change by appending `s`, `m`, or `h`)
> Usage: `sudo shutdown -r {2202152330, +30s} "This is message!"`

> Q: `shutdown` 和 `shutdown -p` 差在哪裡?<br>
> A: 根據觀察，單純 `shutdown` 會進入 ***single user mode***，`shutdown -p` 才會真正關閉電源
- `chfn`: change GECOS (General Electric Comprehensive Operating System)
    - Commonly used to record *personal information*
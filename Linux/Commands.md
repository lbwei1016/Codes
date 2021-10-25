# Help
- `man`: man page
    - `/ [search item]`: to search
# Directory and File
## Go To
- `cd` ~ : 回到家目錄
- `cd ~[account]` : 到[account]的家目錄
- `cd`  : 回到家目錄
- `cd` .. : 前往上層目錄
- `cd` - : 回到上一個目錄

- `.` : 代表當前目錄
- `..` : 代表上一層目錄

## Manipulation
- `pwd [-P]` : 顯示目前所在的目錄； `-P` ： 顯示出確實的路徑，而非使用連結 (link) 路徑

- `mkdir [-mp]`: -m : 設定權限(e.g. 711)；`-p` : 遞迴操作(整層)
- `rmdir [-p]` : 刪除「空」目錄；`-p` : 遞迴操作
- `basename [/.../...]` : 顯示「檔名」 
- `dirname [/.../...]` : 顯示「目錄名」

- `cp [-a][-r][-i] [from] [to]` : 複製檔案(目錄)；`-a` : 基本上代表複製原檔案的一切(包括權限) ；`-r` : 遞迴複製(用於目錄)；`-i` : 出現警告訊息
- `touch [file]` : 建立空檔案
- `rm [-i][-r]` : 刪除檔案(參數意義同 `cp`)
- `mv [-i] [from(name A)] [to (name B)]` : 移動、重新命名檔案
- 檔名為 "`-`" 的檔案要用絕對路徑來開啟：`./-`
- 檔名有空白鍵：`vi "a file with spaces"`
- `file [filename]`: 顯示檔案類型 (*dat, ASCII, etc*)
- `find [-specifics]` : 找尋當前和子目錄中符合條件的檔案(目錄)
    - `find -size 1033c`: 大小為`1033 byte`的檔案
    - `find -user [owner] -group [group name]` : 檔案擁有者及群組
    - `find [-...] 2>/dev/null` : 排除因權限無法存取的檔案
- `wc [file1] [file2]` : 輸出檔案的換行數、字數與位元組數
    - `wc -l` : 換行數
    - `wc -w` : 字數
    - `wc -c` : 位元組數
    - `wc -m` : 字元數
- `diff [option] [file1 file2...]` : output the difference between files
## Permission
- `chgrp [-R] [group] [file/dir]` : 更改群組 (root)
- `chown [-R] [user:group] [file/dir]` : 更改擁有者 (群組也可以 : `user:group`) (root)
- `chmod [-R] [xyz] [file/dir]` : 檔案權限更改 
    - `r` : 4
    - `w` : 2
    - `x` : 1
    >*e.g. `chmod -R 720 myfile`*
- ***Setuid, Setgid, Sticky BIT***
    > 檔案加入 setuid 權限後, 其他用戶可以用檔案持有者身份執行檔案

- ***setuid*** : `chmod "4"751`；cancel : `chmod [0]751`
- ***setgid*** : `chmod "2"751`；cancel : `chmod [0]751`
- ***sticky bit*** : `chmod "+t" [file]`

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
- `tmux`: *teminal multiplexer*
    > press `Ctrl-b` before input commands
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
```sh
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
# Others
- `sort [file]` : Sort the given file
- `strings [file]` : Prints the printable character sequences that are at least 4 characters long
- `grep [pattern] [file1/dir1] [file2/dir2]` : Find contents/files that matches the pattern
    - `grep -q [...]`: If `pattern` is found, exit with code `0`, otherwise `1`
- `uniq [file]` :  Filter adjacent matching lines 
- `exit 0`: exit with code `0` 
    - `echo $?`: Look up the latest exit code 
- `timeout`: to limit file executing time
- `seq [-s "STRING"][-w] [FIRST][INCREMENT][LAST]`: Print numbers from FIRST to LAST, in steps of INCREMENT.
    - `-s "STRING"`: use `STRING` to separate numbers *(default: \n)*
    - `-w`: equalize width by *padding* with leading zeroes


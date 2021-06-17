# Directory and File
- `cd` ~ : 回到家目錄
- `cd ~[account]` : 到[account]的家目錄
- `cd`  : 回到家目錄
- `cd` .. : 前往上層目錄
- `cd` - : 回到上一個目錄

- `.` : 代表當前目錄
- `..` : 代表上一層目錄
- `pwd [-P]` : 顯示目前所在的目錄； `-P` ： 顯示出確實的路徑，而非使用連結 (link) 路徑

- `mkdir [-mp]`: -m : 設定權限(e.g. 711)；`-p` : 遞迴操作(整層)
- `rmdir [-p]` : 刪除「空」目錄；`-p` : 遞迴操作

- `cp [-a][-r][-i] [from] [to]` : 複製檔案(目錄)；`-a` : 基本上代表複製原檔案的一切(包括權限) ；`-r` : 遞迴複製(用於目錄)；`-i` : 出現警告訊息
- `touch [file]` : 建立空檔案
- `rm [-i][-r]` : 刪除檔案(參數意義同 `cp`)
- `mv [-i] [from(name A)] [to (name B)]` : 移動、重新命名檔案
- `chgrp [-R] [group] [file/dir]` : 更改群組 (root)
- `chown [-R] [user:group] [file/dir]` : 更改擁有者 (群組也可以 : `user:group`) (root)
- `chmod [-R] [xyz] [file/dir]` : 檔案權限更改 
    - `r` : 4
    - `w` : 2
    - `x` : 1

    >*e.g. `chmod -R 720 myfile`*
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
# Netcat (nc)
- `nc [-vul] [host] [port]` : using the `TCP` or `UDP` protocols to read or write data 
    - `-v` : verbose message displayed
    - `-u` : use `UDP` instead of `TCP`
    - `-l` : listen for an incoming connection rather than initiating a connection to a remote host
    > *e.g. `echo "Hi" | nc -u localhost 8000`* : transmit a `UDP` packet

    > *e.g. `nc -lu localhost 8000`* : accept a packet under `UDP`
# SSH 
- `ssh <user>@<host> [-p [port] ]` : login `host` 
- `ssh-keygen -t rsa` : generate `RSA` key under `.ssh/`
# Others
- `sort [file]` : Sort the given file
- `strings [file]` : Prints the printable character sequences that are at least 4 characters long
- `grep [pattern] [file1/dir1] [file2/dir2]` : Find contents/files that matches the pattern
- `uniq [file]` :  Filter adjacent matching lines 



# **開始操作前記得 pull !!! 結束前記得 push !!!**

## 一般指令
* **git config alias.** ***[an alias]* *[command]*** : 設定指令縮寫
* **git init** : 初始化當前目錄，讓 Git 對這個目錄開始進行版控（產生 *.git* 目錄）
* **git status** : 查詢目錄狀態
* **git add *(--all)* *[filename]*** : 加入檔案到 Index（暫存區；又叫做 Stage）
* **git commit -m *"[some message]"*** : commit
* **git log *[filename][--oneline][--graph][--author=""][--grep=""][--S][--since][--until][--after]*** : <br>查詢 commit 紀錄（grep: 找 **commit 訊息**包含...的檔案；S: 找檔案**內容**包含...的檔案）</br>
* **git rm [filename]** : 刪除檔案並放入 Index
* **git mv [filename][new filename]** : 更改檔案名稱並放入 Index
* **git commit *[--amend][-m "message"][--no-edit]*** : --amend可以**修改最近一次 commit message** 或將檔案**併入最近一次 commit**
* **git rm --cached *[filename][-f]*** : 將檔案自暫存區移除
* **git reset HEAD *[filename]*** : 刪除已註冊到索引(Index)的檔案
* **git reset HEAD(or hash code / master)**`** : 刪除 commit
---
## Github
- `git remote add [URL]`
- `git push -u origin master` --首次
- `git pull` = `git fetch` + `git merge`
---
## Files
* **.gitconfig** : 這是設定檔
* **.gitignore** : 指名要 git 在 commit 時忽略哪些檔案

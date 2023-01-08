## 一般指令
* `git config alias. [an alias] [command]` : 設定指令縮寫
* `git init` : 初始化當前目錄，讓 Git 對這個目錄開始進行版控（產生 `.git` 目錄）
* `git status` : 查詢目錄狀態
* `git add (--all) [filename]` : 加入檔案到 Index（暫存區；又叫做 Stage）
* `git commit -m "[some message]"` : commit
* `git log [filename][--oneline][--graph][--author=""][--grep=""][--S][--since][--until][--after][-p]`: 查詢 commit 紀錄
    - `grep`: 找 **commit 訊息**包含...的檔案
    - `--S`: 找檔案**內容**包含...的檔案
    - `-p`: 比較 commit 間的差異
* `git rm [filename]` : 刪除檔案並放入 Index
* `git rm --cached [filename][-f]` : 將檔案自暫存區移除 (!!!!!!!)
* `git mv [filename][new filename]` : 更改檔案名稱並放入 Index
* `git commit [--amend][-m "message"][--no-edit]` : --amend可以**修改最近一次 commit message** 或將檔案**併入最近一次 commit**
* `git reset HEAD [filename]` : 刪除已註冊到索引(Index)的檔案
* `git reset HEAD(or hash code / master)` : 刪除 commit
- `git clone [SSH / HTTPS] [new file name]`: 複製 Repository 到本地 (`new file name` is optional)

## Branch
- `git branch [new branch name]`: 在目前位置 (`HEAD` 所指處) 建立一新的 `branch`，但仍指向原先的 `branch` (最初的 `branch` 為 `master`)
- `git branch -d <branch name>`: delete local branch
- `git branch -m master main`: 改 master 為 main (改名)
- `git push <remote name> --delete <branch name>`: delete remote branch
> 若無參數則顯示所有 `branch`
-  `git branch -a`: 顯示 *local* + *remote* 的 `branch`
- `git checkout [-b][branch name]`: 將 `HEAD` 移至 `[branch name]`
    - `-b`: 建立新的 `branch` 並將 `HEAD` 移至該處
## Tag
- `git tag [tag name][commit hash][-a][-m "message"]`: 為 `commit` 加上標籤
    - `-a`: *有附註標籤 （annotated tag）*，會開啟編輯器
    > 若無 `-a`，則標籤是 *輕量標籤（lightweight tag）*，
    > 差別在於，*annotated tag* 除了標籤文字外，還可以有內容

    - `-m`: 不開啟編輯器，直接輸入 *annotated tag* 的內容 (類似 `commit -m`)
- `git show <object>`: 顯示 `<object>` 的資訊 (詳情待查)
    - `git show <tag name>`: 顯示 `tag` 的內容
## Else
* `git bisect start`
    * `git bisect good <commit id>`
    * `git bisect bad <commit id>`
    > 設定 "好的" 和 "壞的點"，然後 `git` 利用二分搜的方式找到錯誤的 commit
    > https://medium.com/%E9%80%B2%E6%93%8A%E7%9A%84-git-git-git/%E5%BF%AB%E9%80%9F%E6%89%BE%E5%87%BA%E9%8C%AF%E8%AA%A4%E9%BB%9E-%E4%BD%BF%E7%94%A8git-bisect-e1c3338e8db1
---
## Github
### **開始操作前記得 pull !!! 結束前記得 push !!!**
- `git remote add [origin] [URL]`
- `git push -u origin master` --首次
- `git pull` = `git fetch` + `git merge`
---
## Files
* `.gitconfig` : 這是設定檔
* `.gitignore` : 指名要 git 在 commit 時忽略哪些檔案

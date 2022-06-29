1. command mode
* h: left 
* j: down 
* k: up
* l: right
2. insert mode
   * `:%s/PATTERN/REPLACEMENT/gc` 
     * `%s` for the whole file
     * `gc`:  confirm before replacement
     * `(...)`: catch a group
       * `\1`: refer to a group
3. command line mode
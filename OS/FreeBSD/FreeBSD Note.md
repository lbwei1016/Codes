# FreeBSD Note

## Kernel

- `/usr/src/sys/i368/conf/`: kernels are placed here
- `/usr/src/sys/amd64/conf/`: my **FreeBSD** is amd64 architecture !!!!!!
  - `GENERIC`: default kernel

### Steps to build a kernel

- `cp GENERIC /root/MYKERNEL`: 先複製一份
- `ln -s /root/MYKERNEL`: 在原地 (`usr/src/...`) 建 link file
- `modify...` 
- `config MYKERNEL`

### Method 1

- `cd ../../compile/MYKERNEL` 
- `make cleandepend && make depend` 
- 



## Internet 

* `em*`: Ethernet **adapter** driver (like Ethernet to USB)
* `fxp*`: Ethernet **device** driver 
Copyright 2009 Takahiro Hashimoto

All rights reserved.

stretch-pwd
===========

This program improve shell prompt long path view

- normal path view
/home/bah/workspace/project/src/main/java $
- stretch-pwd path view
/home/bah/w...src/main/java $

Contents
========
* Build and install stretch-pwd
* Setup for zsh
* Example


Build and install stretch-pwd
=============================
```shell
cd stretch-pwd
make
sudo make install
```

Setup for zsh
=============
Set hook to a chpwd function in your .zshrc
```shell:.zshrc
PS1_WIDTH=30
function chpwd(){
    PS1="%B%m%b:`stretch-pwd -l $PS1_WIDTH` %# "
}
```

Reload configuration
```
$ source .zshrc
```

Example
=======
```
/usr/local/bin/stretch-pwd -l 25 /home/hashimoto/stretch-pwd
```
-> /home/hashi...stretch-pwd

```
/usr/local/bin/stretch-pwd -c ' + ' -l 25 /home/hashimoto/stretch-pwd                                                                                                                                                                           [05/27 16:52:16]
```
-> /home/hashi + stretch-pwd

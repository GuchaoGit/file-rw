#!/bin/bash
app=./fileread.tar.gz
prefix=/home/guc/Study/file-rw/install


echo "正在安装程序"
if [ -e "$app" ] ; then
	mv $app $prefix
	cd $prefix
	tar xzvf fileread.tar.gz 
	rm fileread.tar.gz
	echo "fileread 已安装"
else
	echo "未找到安装包"
fi

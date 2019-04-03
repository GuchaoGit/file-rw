#!/bin/bash

prefix=/home/guc/Study/file-rw/install

echo "正在安装程序"
mv fileread.tar.gz $prefix
cd $prefix
tar xzvf fileread.tar.gz 
rm fileread.tar.gz
echo "fileread 已安装"


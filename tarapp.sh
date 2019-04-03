#!/bin/bash
echo "正在打包程序"

if [ -e "./fileread" ]; then

	tar czf fileread.tar.gz config.ini fileread

	echo "fileread.tar.gz 已打包"

else
	echo "fileread.tar.gz 打包失败，缺失必要文件"
fi


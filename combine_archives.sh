#!/bin/bash

tmpdir=`tempfile`
final_lib=$1
shift
rm -f $final_lib
for i in "$@"
do
	echo $i
	if [[ "$i" =~ ^.*\.a$ ]]; then
		rm -rf $tmpdir
		mkdir -p $tmpdir
		cur_path=$PWD
		cp $i $tmpdir	
		cd $tmpdir
		arn=`basename $i`
		ar x $arn >/dev/null
		rm -f $arn
		arn_tmp=`echo $arn | sed 's/.a$//g'`
		l=`ls`
		for j in $l
		do
			new_name=${arn_tmp}_$j
			mv $j $new_name
		done
		cd $cur_path
		ar r $final_lib $tmpdir/* >/dev/null 2>&1
		if [ $? != 0 ]; then
			echo "ar r $final_lib $i failed!"
			exit 1
		fi
		#rm -rf $tmpdir
		
	else
		ar r $final_lib $i >/dev/null 2>&1
		if [ $? != 0 ]; then
			echo "ar r $final_lib $i failed!"
			exit 1
		fi
	fi
done



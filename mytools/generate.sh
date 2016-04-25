#/usr/bin/bash
#It can be used to generate sh,python file
#Usage:
#      bash generate.sh a.py to create a.py
set +x

function generate_python()
{
	echo "#!/usr/bin/env python" > $1
	echo "# -*- coding: utf-8 -*-" >> $1
	echo "" >> $1
	echo "if __name__ == '__main__':" >> $1
	echo "    main()" >> $1
}

function generate_sh()
{
	echo "#!/bin/bash" > $1
	echo "set -e" >> $1
}

if [ $# -eq 1 ]; then
    file_name=$@
	suffix=${file_name##*.}
	if [ -n "$suffix" ] && [ "$suffix" != "$file_name" ]; then
	    if [ "$suffix" = "py" ]; then
		    generate_python $file_name
		elif [ "$suffix" = "sh" ]; then
			generate_sh $file_name
		else
			echo "Sorry, Not support $suffix file"
		fi
	else
		echo "Now, We only support:"
		echo "1.python file"
		echo "2.shell file"
		read -p "Input 1 for python file...(0 for exit): " choose
		if [ "$choose" -eq 1 ]; then
			generate_python $file_name
		elif [ "$choose" -eq 2 ]; then
			generate_sh $file_name
		else
			exit
		fi
	fi
fi

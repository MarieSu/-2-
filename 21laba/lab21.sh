#!/bin/bash

mode=0

if [ "$1" = "?" ]
    then
    echo "Использование: /home/masha/lab21.sh [ПАРАМЕТР]"
    echo "Удаление файлов, суммарная длинна которых не меньше заданного числа блоков."
else
    if [ -z "$1" ]
    then

	echo ""

	read -p "Введите число блоков: " ch

	echo ""
	mode=2
    elif [ "$1" == "-c" ]
    then

    	if [ $# -gt 1 ]
    	then
    	    echo -e "\n\t\t\tСлишком много аргументов"
    	    
    	    exit -1

    	fi

    	echo -e "\nРежим подтверждения установлен ключом -c"

    	mode=1
    	if [ -z "$2" ]
    	then

            echo ""

            read -p "Введите число блоков: " ch
    elif [ -n "$2" ]
    then

        echo -e "\n\tСлишком много аргументов"

        exit -1
    fi
    else
    	if [ $# -gt 1 ]
    	then
    	    echo -e "\n\t\t\tСлишком много аргументов"
    	    
    	    exit -1
        else
            ch="$1"
    	    mode=2
    	fi
    fi
fi

ans="default"
if [ $mode == 2 ]
then
    find -type f | while read line
    do
        fil=(`find "$line"`)
        c=(`du "$fil"`)
	if [[ $c -ge $ch ]]
	then
	   rm -f "$fil"
	fi
	done
	echo -e "\n\t\t\tФайлы успешно удалены!"
fi
if [ $mode == 1 ]
then

    while [ $ans != "д" ] && [ $ans != "н" ]
    do

	read -p "Удалить эти файлы? [д/н] : " ans
		
    done
    if [ $ans == "д" ] || [ $ans == "default" ]
    then
	find -type f | while read line
	do
    	    fil=(`find "$line"`)
    	    c=(`du "$fil"`)
    	    if [[ $c -ge $ch ]]
            then
    		echo "$fil"
    		rm -f "$fil"
    	    fi
	done
	echo -e "\n\t\t\tФайлы успешно удалены!"

    else

        echo -e "\n\t\tКоманда удаления файлов отменена!"
    fi
fi

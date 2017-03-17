#!/bin/zsh

# variables
PUSH_SWAP=push_swap
CHECKER=checker
TEMPFILE=resulttempfile.txt;
RECOMPILE=0;
ERRORS=errorstempfile.txt

# unchanging variables
YESNO=0;
A=;
RED='\033[0;31m';
WHITE='\033[1m';
CLN='\033[0m';
RM=/bin/rm;
RANGENUM=1000
NUMMAX=5000
WRONGCOUNT=0;
OKCOUNT=0;
SORTCOUNTEROK=0;
SORTCOUNTERKO=0;
MAXNUMBER=0;
MINNUMBER=10000;
MEDIUM=0;
TESTNUM=1;

# push_swap and checker exist
if [ ! -e ${PUSH_SWAP} ]; then
    echo "${PUSH_SWAP} not found";
    exit 1;
fi
if [ ! -e ${CHECKER} ]; then
    echo "${CHECKER} not found";
    exit 1;
fi

#delete errors log file
if [ -e ${ERRORS} ]; then
    rm ${ERRORS};
    touch ${ERRORS};
else
    touch ${ERRORS};
fi

# arguments
if [ "$#" -eq 1 ]; then
	NUMBERS=$1;
	if [ ${NUMBERS} -le 1 ] || [ ${NUMBERS} -gt ${NUMMAX} ]; then
        echo "Error: wrong argument";
        exit 1;
    fi;
	LOOPS=1;
	echo ${WHITE}${NUMBERS}${CLN} "random numbers";
elif [ "$#" -eq 2 ]; then
    NUMBERS=$1;
    if [ ${NUMBERS} -le 1 ] || [ ${NUMBERS} -gt ${NUMMAX} ]; then
        echo "Error: wrong argument";
        exit 1;
    fi;
    LOOPS=$2;
    if [ ${LOOPS} -le 0 ]; then
        echo "Error: wrong argument";
        exit 1;
    fi;
    echo ${WHITE}${LOOPS}${CLN} "loops";
    echo ${WHITE}${NUMBERS}${CLN} "random numbers each";
else
   	echo "usage (default ${WHITE}2${CLN} numbers and ${WHITE}1${CLN} loop): sh pushchecker.sh [NUMBER] [LOOPS]";
   	echo "      script can check: 3, 5, 100, 500 with warnings"
	NUMBERS=2;
	LOOPS=1;
fi

#recompile project before run?
if [ ${RECOMPILE} -eq 1 ]; then
    make ${PUSH_SWAP};
    make clean;
    clear;
fi

# copy variable
LOOPSCOUNT=${LOOPS};

# while loops
while [ ${LOOPS} -gt 0 ]; do
    # generating set of random numbers
    while [ ${YESNO} -lt ${NUMBERS} ]; do
        TEMP=$((RANDOM%${RANGENUM}+0))" ";
        if [[ ${A} == *${TEMP}* ]]; then
            continue;
        else
            A+=${TEMP};
            ((YESNO++));
        fi
    done

    # main body
    echo "\n"${A}"\n";
    ./push_swap ${A} > ${TEMPFILE};
    echo "-----------------------";
    echo "test #" $((TESTNUM++))
    echo "operations: \c";
    OPER=$(cat ${TEMPFILE} | wc -l | tr -d " ");

    if [ ${OPER} -ge ${MAXNUMBER} ]; then
        if [ ${OPER} -ne 0 ]; then
            MAXNUMBER=${OPER};
        fi
    fi
    if [ ${OPER} -le ${MINNUMBER} ]; then
        if [ ${OPER} -ne 0 ]; then
            MINNUMBER=${OPER};
        fi
    fi

    #summ medium operations
    MEDIUM=$((MEDIUM + OPER));

    if [ ${NUMBERS} -eq 2 ]; then
        if [ ${OPER} -gt 1 ]; then
            echo "operations: ${OPER} \n"${A}"\n" >> ${ERRORS}
            echo "${RED}WRONG${CLN} \c";
            ((WRONGCOUNT++));
        else
            echo ${WHITE}"OK \c"${CLN};
            ((OKCOUNT++));
        fi
    elif [ ${NUMBERS} -eq 3 ]; then
        if [ ${OPER} -gt 3 ]; then
            echo "operations: ${OPER} \n"${A}"\n" >> ${ERRORS}
            echo "${RED}WRONG${CLN} \c";
            ((WRONGCOUNT++));
        else
            echo ${WHITE}"OK \c"${CLN};
            ((OKCOUNT++));
        fi
    elif [ ${NUMBERS} -eq 5 ]; then
        if [ ${OPER} -gt 12 ]; then
            echo "operations: ${OPER} \n"${A}"\n" >> ${ERRORS}
            echo "${RED}WRONG${CLN} \c";
            ((WRONGCOUNT++));
        elif [ ${OPER} -le 8 ] && [ ${OPER} -gt 0 ]; then
            echo ${WHITE}"Great! \c"${CLN};
            ((OKCOUNT++));
        else
            echo ${WHITE}"OK \c"${CLN};
            ((OKCOUNT++));
        fi
    elif [ ${NUMBERS} -eq 100 ]; then
        if [ ${OPER} -gt 700 ]; then
            echo "operations: ${OPER} \n"${A}"\n" >> ${ERRORS}
            echo "${RED}WRONG${CLN} \c";
            ((WRONGCOUNT++));
        else
            echo ${WHITE}"OK \c"${CLN};
            ((OKCOUNT++));
        fi
    elif [ ${NUMBERS} -eq 500 ]; then
        if [ ${OPER} -gt 5300 ]; then
            echo "operations: ${OPER} \n"${A}"\n" >> ${ERRORS}
            echo ${RED}"WRONG${CLN} \c";
            ((WRONGCOUNT++));
        else
            echo ${WHITE}"OK${CLN} \c";
            ((OKCOUNT++));
        fi
    fi

    echo ${OPER};
    echo "./checker:  \c";
    R=$(cat ${TEMPFILE} | ./checker $A);
    if [[ ${R} == "OK" ]]; then
        echo ${WHITE}${R}${CLN};
        ((SORTCOUNTEROK++));
    else
        echo "sorting: ${R} \n${A}\n" >> ${ERRORS}
        echo ${RED}${R}${CLN};
        ((SORTCOUNTERKO++));
    fi
    echo "-----------------------";
    rm ${TEMPFILE};
    A=;
    TEMP=;
    YESNO=0;
    ((LOOPS--));
done

echo "\nfinal result (${LOOPSCOUNT} loops): \c";
if [ ${WRONGCOUNT} -eq 0 ]; then
    if [ ${SORTCOUNTERKO} -eq 0 ]; then
        echo ${WHITE}"GOOD"${CLN};
        rm ${ERRORS};
    else
        echo ${RED}"BAD"${CLN};
    fi;
else
    echo ${RED}"BAD"${CLN};
fi

if [ ${LOOPSCOUNT} -gt 1 ]; then
    echo "operations:       ${OKCOUNT} OK / ${WRONGCOUNT} Wrong";
    echo "sorting:          ${SORTCOUNTEROK} OK / ${SORTCOUNTERKO} KO";
    echo "max (operations): ${MAXNUMBER}";
    echo "min (operations): ${MINNUMBER}";
    echo "med (operations): $((MEDIUM/LOOPSCOUNT))"
fi
exit 0

#!/bin/bash

# Syntax printing
function print_syntax() {
    echo
    echo "To generate the txt with the descrition of the possible grammar for the finite state machine"
    echo "specify MAX_NBR_STATES, MAX_NBR_CONNECTIONS, and the txt file name in which the description will be saved:"
    echo "$0 <MAX_NBR_STATES> <MAX_NBR_CONNECTIONS> <TXT_FILE>"
    echo
    exit 1
}

# Write description of state
function write_state() {
  INDEX=$1
  NB_TRANS=$2
  echo "S$INDEX     \"--s$INDEX \"  c   (0,1,2,3,4,5,6) | as.numeric(NumStates)>$INDEX " >> ${TXT_FILE}
  echo "RWM$INDEX   \"--rwm$INDEX \"  i (1,100) | as.numeric(S$INDEX)==0" >> ${TXT_FILE}
  echo "FOV$INDEX   \"--fov$INDEX \"  c (0,1) | as.numeric(S$INDEX) %in% c(2,3,5,6)" >> ${TXT_FILE}
  echo "VEL$INDEX   \"--vel$INDEX \"  c (1.0) | as.numeric(S$INDEX) %in% c(2,3,5,6)" >> ${TXT_FILE}
  echo "CLR$INDEX   \"--clr$INDEX \"  c (2,3) | as.numeric(S$INDEX) %in% c(2,3)" >> ${TXT_FILE}
  echo "PHE$INDEX   \"--phe$INDEX \"  c (0,1,2) | as.numeric(S$INDEX) %in% c(0,1,2,3,4,5,6)" >> ${TXT_FILE}
  if [ ${INDEX} == 0 ]; then
    echo "NumConnections$INDEX \"--n$INDEX \" i (1,4) | as.numeric(NumStates)>1" >> ${TXT_FILE}
  else
    echo "NumConnections$INDEX \"--n$INDEX \" i (1,4) | as.numeric(NumStates)>${INDEX}" >> ${TXT_FILE}
  fi
}

function write_connection() {
  STATE=$1
  CONNECTION=$2
create_range STATE
  echo "N${STATE}x$CONNECTION  \"--n${STATE}x$CONNECTION \" i   (0,3) | as.numeric(NumConnections$STATE)>$CONNECTION " >> ${TXT_FILE}
  echo "C${STATE}x$CONNECTION  \"--c${STATE}x$CONNECTION \" c   (0,1,2,3,4,5,6) | as.numeric(NumConnections$STATE)>$CONNECTION " >> ${TXT_FILE}
  echo "P${STATE}x$CONNECTION  \"--p${STATE}x$CONNECTION \" r   (0,1) | as.numeric(C${STATE}x$CONNECTION) %in% c(0,1,2,3,4,5,6) " >> ${TXT_FILE}
  echo "F${STATE}x$CONNECTION  \"--f${STATE}x$CONNECTION \" c   (0,1) | as.numeric(C${STATE}x$CONNECTION) %in% c(5,6) " >> ${TXT_FILE}
  echo "L${STATE}x$CONNECTION  \"--l${STATE}x$CONNECTION \" c   (2,3) | as.numeric(C${STATE}x$CONNECTION)==5 " >> ${TXT_FILE}
}

function create_range() {
  FORBIDDEN=$1
  RANGE="("
  for I in $(seq 0 $MAX_NBR_STATES)
  do
    if [ ${I} != ${STATE} ]; then
      RANGE="${RANGE}${I},"
    fi
  done
  RANGE=${RANGE::-1}
  RANGE="${RANGE})"
}

if [ $# -lt 3 ]; then
    print_syntax
fi

MAX_NBR_STATES=$(echo "$1-1" | bc)
MAX_NBR_CONNECTIONS=$(echo "$2-1" | bc)
TXT_FILE=$3

# Clear content of file
truncate -s 0 $TXT_FILE

# Write grammar in file
echo "NumStates   \"--nstates \"   i (1,$1)" >> $TXT_FILE
for STATE in $(seq 0 $MAX_NBR_STATES)
do
  write_state $STATE
  for CONNECTION in $(seq 0 $MAX_NBR_CONNECTIONS)
  do
    write_connection $STATE $CONNECTION
  done
done

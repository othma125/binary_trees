#!/bin/bash

sed -e "s/\r//g" $1 > newfile
cp newfile $1
sleep 1
rm newfile


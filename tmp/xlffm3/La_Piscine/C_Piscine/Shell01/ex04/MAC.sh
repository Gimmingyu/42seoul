#!/bin/sh
ifconfig -a | grep 'ether ' | tr -d '\t' | sed 's/ether //' | sed 's/ //g'

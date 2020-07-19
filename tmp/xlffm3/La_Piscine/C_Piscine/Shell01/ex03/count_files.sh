#!/bin/sh
find ./ | wc -l | tr -d ' ' | tr -d '\t'

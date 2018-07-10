#!/bin/bash

# usage : ./backup.sh ***** 
 
git add .
git commit -m "$1"
git push origin

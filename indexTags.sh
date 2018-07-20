#!/bin/bash

#create tags for emaxs - enables jumping to definitions etc

rm -f TAGS
find . -name "*.[ch]" -print | xargs etags -a

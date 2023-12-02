@echo off
doskey m=make -j 4 -f Makefile.Release $T make -j 4 -f Makefile.Debug
doskey mr=make -j 6 -f Makefile.Release
doskey md=make -j 6 -f Makefile.Debug
doskey mc=make cleanall
doskey mq=qmake
doskey cm=release\CodeMerge $*
doskey cmk=pskill CodeMerge
doskey cmd=debug\CodeMerge $*
title CodeMerge

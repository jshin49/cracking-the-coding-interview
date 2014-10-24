@echo off 
setlocal enableDelayedExpansion 

start /wait /B scons -c

:: set SCONS_MSCOMMON_DEBUG=-

start /wait /B scons

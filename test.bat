@echo off 
SETLOCAL ENABLEDELAYEDEXPANSION 
call:main %1
echo.
echo.
echo.&pause&goto:eof

:main
SETLOCAL ENABLEDELAYEDEXPANSION
SET specificFile=%~1
IF [%specificFile%]==[] (
	echo.
	echo.
	echo %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	echo            OPTIONS
	echo %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	echo.
	SET /A COUNT=1
	FOR /F %%x in ('dir /B/AD "%CD%\build\debug"') do (
		SET /A COUNT+=1
		echo 	"!COUNT!) %%x"
	)
)
IF [%specificFile%] NEQ [] (
	echo !specificFile!
	IF "!specificFile!" == "all" (
		SET GLOBALPATH=%CD%\build\debug
		call:ProcessAll "!GLOBALPATH!"
	) 
	IF "!specificFile!" NEQ "all" (
		SET SINGLEPATH=%CD%\build\debug\%specificFile%
		call:ProcessSingle "!SINGLEPATH!" %specificFile%
	)
)
ENDLOCAL
goto:eof

:ProcessAll
SETLOCAL ENABLEDELAYEDEXPANSION
SET localElement="%~1"
echo.
echo.
echo %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
echo        Running ALL Tests
echo %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
FOR /F %%x in ('dir /B/D "%localElement%"') do (
	call:ProcessSingle "%localElement%\%%x" %%x
)
echo.
ENDLOCAL
goto:eof

:ProcessSingle
SETLOCAL ENABLEDELAYEDEXPANSION
SET localElement="%~1"
SET elementName=%~2
echo.
echo.
	FOR %%a in ("%localElement%\*.exe") do (
		echo ------------------------------------------------------------------
		echo Running %elementName%
		echo %%a
		echo ------------------------------------------------------------------
		start "" /B %%a --log_level=all
  	)
ENDLOCAL
goto:eof

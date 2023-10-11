@echo off
setlocal EnableDelayedExpansion
set /p solution="Enter solution file (with extension): "
set /p dataPath="Enter path to data folder (Ex. data): "

set extension5=%solution:~-5%
set extension4=%solution:~-4%
set extension3=%solution:~-3%
set extension2=%solution:~-2%

echo Judging %solution%...
echo.

if /I "%extension5%" == ".java" (
	echo Compiling your solution...
	javac !solution! > nul 2>&1
	if !errorLevel! neq 0 (
		echo.
		echo COMPILE TIME ERROR
		EXIT /b 1
	)
	set solution=java !solution:~0,-5!
) else if /I "%extension4%" == ".cpp" (
	echo Compiling your solution...
	g++ -std=c++11 !solution! -o a.exe > nul 2>&1
	if !errorLevel! neq 0 (
		echo.
		echo COMPILE TIME ERROR
		EXIT /b 1
	)
	set solution=a.exe
) else if /I "%extension3%" == ".py" (
	echo Python detected. No need to compile.
	set solution=python !solution!
) else if /I "%extension2%" == ".c" (
	echo Compiling your solution...
	gcc -std=c11 !solution! -o a.exe > nul 2>&1
	if !errorLevel! neq 0 (
		echo.
		echo COMPILE TIME ERROR
		EXIT /b 1
	)
	set solution=a.exe
) else (
	echo Solution is not a valid Java, C, or C++ file!
	EXIT /b 1
)

echo Successfully compiled.

set tempOut=YOUR_OUTPUT.tmp
set expectedOut=EXPECTED_OUTPUT.tmp

set totalCases=0
set totalCorrect=0
set totalWrong=0
set totalRunTimeError=0

set longestDuration=0

echo.

for /r %%F in (%dataPath%\*.in) do (
	set /a totalCases+=1
	echo Running on %%~nxF...

	set "inFile=%%F"
	set "outFile=%%~pF%%~nF.out"

	copy /y "!outFile!" %expectedOut% > nul 2>&1

	for /F "tokens=1-4 delims=:.," %%a in ("!time!") do (
		set /A "startTime=(((%%a*60)+1%%b %% 100)*60+1%%c %% 100)*100+1%%d %% 100"
	)

	%solution% < !inFile! > %tempOut% 2>&1

	for /F "tokens=1-4 delims=:.," %%a in ("!time!") do (
		set /A "endTime=(((%%a*60)+1%%b %% 100)*60+1%%c %% 100)*100+1%%d %% 100"
	)

	if !errorLevel! equ 0 (
		fc /w "%tempOut%" "%expectedOut%" > nul 2>&1
		if !errorLevel! equ 0 (
			set /a totalCorrect+=1
			echo Result: CORRECT
		) else (
			set /a totalWrong+=1
			echo Result: WRONG ANSWER
		)

		set /A duration=!endTime!-!startTime!

		set /A durationCentis=!duration!%%100
		set /A durationSeconds=!duration!-!durationCentis!
		set /A durationSeconds/=100

		echo Duration: !durationSeconds!.!durationCentis! seconds

		if !duration! gtr !longestDuration! (
			set longestDuration=!duration!
		)
	) else (
		set /a totalRunTimeError+=1
		echo Result: RUN-TIME ERROR
	)
	echo.
)

if %totalCases% equ 0 (
	echo No test cases found!
	echo Make sure the path to the test cases you provided is correct then try again.
) else (
	echo Total Cases: %totalCases%
	echo Total Correct: %totalCorrect%
	echo Total Wrong Answer: %totalWrong%
	echo Total Run-Time Error: %totalRunTimeError%
	echo.

	set /A durationCentis=!longestDuration!%%100
	set /A durationSeconds=!longestDuration!-!durationCentis!
	set /A durationSeconds/=100
	
	echo Longest Duration: !durationSeconds!.!durationCentis! seconds

	echo.
	echo.
	set "suggestedResponse=WRONG ANSWER"
	if %totalCorrect% equ %totalCases% (
		set "suggestedResponse=CORRECT"
	) else if %totalRunTimeError% gtr 0 (
		set "suggestedResponse=RUN-TIME ERROR"
	) else (
		set "suggestedResponse=WRONG ANSWER"
	)
	echo Suggested Response: !suggestedResponse!
	echo.
)

pause

del %tempOut% > nul 2>&1
del %expectedOut% > nul 2>&1
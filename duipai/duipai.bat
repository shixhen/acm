@echo off

g++ ans.cpp -o ans.exe -O2 -std=c++17

g++ test.cpp -o test.exe -O2 -std=c++17
g++ checker.cpp -o checker.exe -O2 -std=c++17
g++ gen.cpp -o gen.exe -O2 -std=c++17
set /a count=0

:loop

set /a count+=1

:: 调用 main.py 生成数据

gen.exe > input.txt

:: 跑正确程序
ans.exe < input.txt > ans.txt

:: 跑待测程序
test.exe < input.txt > test.txt

:: 比对输出
:: fc ans.txt test.txt > nul
checker.exe
if errorlevel 1 (
    echo ========================
    echo Wrong Answer!
    echo input:
    type input.txt
    echo answer:
    type ans.txt
    echo wrong:
    type test.txt
    pause
    exit /b
)

echo Test Case %count% Accepted!
goto loop
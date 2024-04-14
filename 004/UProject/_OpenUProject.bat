@echo off
cd /d %~dp0

echo : == Menu ==
echo : 1 .. Delete Caches And Open UProject.uproject
echo : 2 .. Open UProject.uproject
echo : 3 .. Delete Caches Only
set /p a="„"
goto :_%a%

:_1
:_3
        ::###########################
        ::# DELETE CACHE SUBROUTINE #
        ::###########################
        rd /s /q Binaries 2>nul
        rd /s /q DerivedDataCache 2>nul
        rd /s /q Intermediate 2>nul
        rd /s /q Saved 2>nul
        rd /s /q .vs 2>nul
        del /f .vsconfig 2>nul
        del /f UProject.sln

        if "%a%"=="3" goto :eof

:_2
        start "" UProject.uproject
::pause

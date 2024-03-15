
@REM remove all exe file under the current directory and its subdirectories


@echo off

for /r %%i in (*.exe) do (
    echo %%i
    del %%i
)



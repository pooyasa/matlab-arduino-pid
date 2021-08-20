cd .

if "%1"=="" ("F:\MatLab\bin\win64\gmake"  -f finalBlock.mk all) else ("F:\MatLab\bin\win64\gmake"  -f finalBlock.mk %1)
@if errorlevel 1 goto error_exit

exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
An_error_occurred_during_the_call_to_make

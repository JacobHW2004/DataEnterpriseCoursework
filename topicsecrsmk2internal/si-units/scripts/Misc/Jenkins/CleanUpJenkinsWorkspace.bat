del /q /s "C:\jenkins\workspace\*"
setlocal enabledelayedexpansion
FOR /D  %%p IN ("C:\jenkins\workspace\*.*") DO ( 
mkdir empty_dir 
robocopy empty_dir "%%p" /mir 
rmdir empty_dir 
rmdir "%%p" /s /q
)
FOR /D  %%p IN ("C:\JenkinsWorkspace\workspace\*.*") DO ( 
mkdir empty_dir 
robocopy empty_dir "%%p" /mir 
rmdir empty_dir 
rmdir "%%p" /s /q
)
endlocal
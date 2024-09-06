
IF exist export-compile-commands\ (
    call vendor\bin\premake\premake5 export-compile-commands
) ELSE (
    call vendor\bin\premake\premake5 vs2022
)

PAUSE

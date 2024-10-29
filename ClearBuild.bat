echo cleaning...

rmdir /s /q "Mathilda/build"
rmdir /s /q "bin"
rmdir /s /q "bin-int"
rmdir /s /q "lib"
rmdir /s /q "Mathilda/.clangd"
#visual studio
del /s /q "*.sln"
rmdir /s /q ".vs"

echo build cleaned
PAUSE

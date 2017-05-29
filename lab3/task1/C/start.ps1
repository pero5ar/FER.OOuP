echo "Create .exe..."
gcc main.c myfactory.c -o factory.exe
echo "Create .dlls..."
gcc -shared tiger.c -o tiger.dll
gcc -shared parrot.c -o parrot.dll
echo "Start..."
./factory.exe
echo "-------------------------------------------------------"
echo "Building file..."
echo "-------------------------------------------------------"
g++ -g -o $3 -Wall $1
if [ $? -eq 0 ]; then
    echo "-------------------------------------------------------"
    echo -e "\e[90mNow running with input from $2"
    echo "-------------------------------------------------------"
    #syrupy.py -C -S $3 < $2 #time program.bin < input file
    time $3 < $2
    echo ""
    echo "---------";
    echo "Finished!";
else
    echo "-------------------------------------------------------"
    echo "Compilation failed with code $?"
    echo "-------------------------------------------------------"
fi

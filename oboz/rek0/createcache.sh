for i in `seq 0 1 100`; do 
echo "if (n == $i) {" >> cache.txt
printf "return " >> cache.txt
echo $i | ./rek0.bin >> cache.txt
echo ";" >> cache.txt
echo "}" >> cache.txt
done
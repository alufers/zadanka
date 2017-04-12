files="$(ls | grep ^[a-z]*[0-9])"
for i in $files; do
    prefix="$(echo $i | grep -o ^[a-z]*)"
    mkdir -p $prefix
    mv $i $prefix/$i
done;
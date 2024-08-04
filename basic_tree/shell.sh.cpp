# for file in *;do
# 	if[-f"$file"];then
# 		mv "$file" "$file.cpp"
# 	fi
# done

for file in *; do
    if [ -f "$file" ]; then 
        mv "$file" "$file.cpp"
    fi 
done

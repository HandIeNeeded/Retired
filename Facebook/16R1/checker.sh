while true; do
	./gen>tmp.in
	./C<tmp.in>C.out
	./my<tmp.in>my.out
	if diff C.out my.out; then
		echo "AC"
	else
		echo "WA"
		exit 0
	fi
done


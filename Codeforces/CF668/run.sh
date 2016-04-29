while true; do
    ./gen > tmp.in
    ./my  < tmp.in > my.out
    ./std < tmp.in > std.out

    diff my.out std.out > /dev/null
    if [[ $? == 0 ]]; then
        echo "AC"
    else
        echo "WA"
        vim -O tmp.in std.out my.out
        exit 0
    fi
done


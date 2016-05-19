while true; do
    ./gen > tmp.in
    python std.py < tmp.in > std.out
    ./my  < tmp.in > my.out

    diff my.out std.out > /dev/null
    if [[ $? == 0 ]]; then
        echo "AC"
    else
        echo "WA"
        vim -O tmp.in std.out my.out
        exit 0
    fi
done


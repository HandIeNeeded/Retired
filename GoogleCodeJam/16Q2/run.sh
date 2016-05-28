while true; do
    ./gen > data.in
    python std.py < data.in > std.out
    ./my  < data.in > my.out

    diff my.out std.out > /dev/null
    if [[ $? == 0 ]]; then
        echo "AC"
    else
        echo "WA"
        vim -O data.in std.out my.out
        exit 0
    fi
done


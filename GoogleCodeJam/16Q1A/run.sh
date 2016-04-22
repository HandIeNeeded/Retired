while true; do
    ./gen > tmp.in
    ./std < tmp.in > std.out
    ./my < tmp.in > my.out

    diff my.out std.out > /dev/null
    if [ $? == 0 ]; then
        echo "AC"
    else
        echo "WA"
        vim -O tmp.in std.out my.out
        #echo "Input: **************************************************************"
        #head tmp.in
        #echo "*********************************************************************"
        #echo ""
        #echo "Std: >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"
        #head std.out
        #echo ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"
        #echo ""
        #echo "My: <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"
        #head my.out
        #echo "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"
        #echo ""
        #echo "Check it out!!!"
        exit 0
    fi
done


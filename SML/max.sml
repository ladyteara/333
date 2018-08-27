fun countup_from1 (x : int) =
    let fun count (from : int) =
        if from = x
        then x::[]
        else from :: count (from+1)
    in count 1
    end

fun max1 (xs : int list) =
    if null xs
    then 0
    else if null (tl xs)
    then hd xs
    else if hd xs > max1(tl xs)
    then hd xs
    else max1(tl xs)

fun max2 (xs : int list) =
    if null xs
    then 0
    else if null (tl xs)
    then hd xs
    else
        let val tl_ans = max2 (tl xs)
        in
            if hd xs > tl_ans
            then hd xs
            else tl_ans
        end

fun max3 (xs : int list) =
    if null xs
    then NONE
    else
        let val tl_ans = max3(tl xs)
        in
            if isSome tl_ans andalso valOf tl_ans > hd xs
            then tl_ans
            else SOME (hd xs)
        end
fun sum_list (xs : int list) =
    if null xs
    then 0
    else hd(xs) + sum_list(tl xs)

(* Example
input: [(1,9), (2,3), (4,5)]
output: [1,2,4]
*)
fun firsts (xs : (int*int) list) =
    if null xs
    then []
    else (#1 (hd xs))::(firsts(tl xs))

fun seconds (xs : (int*int) list) =
    if null xs
    then []
    else (#2 (hd xs))::(seconds(tl xs))

(* fn : (int * int) list -> int *)
fun sum_pairs(xs : (int*int) list) =
    (sum_list (firsts xs)) + (sum_list (seconds xs))

val x = 2;
val x = 4;
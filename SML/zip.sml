(*
Write a function 𝚊𝚍𝚍𝙾𝚙𝚝 : 𝚒𝚗𝚝 𝚘𝚙𝚝𝚒𝚘𝚗 * 𝚒𝚗𝚝 𝚘𝚙𝚝𝚒𝚘𝚗 -> 𝚒𝚗𝚝 𝚘𝚙𝚝𝚒𝚘𝚗
that given two "optional" integers, adds them if they are both
present (returning 𝚂𝙾𝙼𝙴 of their sum), or returns 𝙽𝙾𝙽𝙴 if at
least one of the two arguments is 𝙽𝙾𝙽𝙴.
*)
fun addOpt (x : int option, y : int option) =
    if (isSome x) andalso (isSome y)
    then SOME ((valOf x) + (valOf y))
    else NONE

val addopt_test1 = (addOpt (SOME 1, SOME 3)) = SOME 4
val addopt_test2 = (addOpt (NONE, SOME 4)) = NONE
val addopt_test3 = (addOpt (SOME 5, NONE)) = NONE

(*
Write a function 𝚣𝚒𝚙 : 𝚒𝚗𝚝 𝚕𝚒𝚜𝚝 * 𝚒𝚗𝚝 𝚕𝚒𝚜𝚝 -> 𝚒𝚗𝚝 * 𝚒𝚗𝚝
list that given two lists of integers creates consecutive
pairs, and stops when one of the lists is empty. For example:
𝚣𝚒𝚙 ([𝟷,𝟸,𝟹], [𝟺,𝟼]) = [(𝟷,𝟺), (𝟸,𝟼)].
*)
fun zip (xs : int list, ys : int list) =
    if null xs orelse null ys
    then []
    else (hd xs, hd ys) :: zip(tl xs, tl ys)

val zip_test1 = (zip ([1,2,3], [4,6])) = [(1,4), (2,6)]


(*
Write a version 𝚣𝚒𝚙𝙾𝚙𝚝 of 𝚣𝚒𝚙 with return
type (𝚒𝚗𝚝 * 𝚒𝚗𝚝) 𝚕𝚒𝚜𝚝 𝚘𝚙𝚝𝚒𝚘𝚗. This version should return
𝚂𝙾𝙼𝙴 of a list when the original lists have the same length,
and 𝙽𝙾𝙽𝙴 if they do not.
*)
fun zipOpt (xs : int list, ys : int list) =
    let val xs_length = length xs
        val ys_length = length ys
    in
        if xs_length = ys_length
        then SOME (zip (xs, ys))
        else NONE
    end
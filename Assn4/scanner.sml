
(*
    In this file you will implement a datatype for
    the tokens that we will handle in this assignment.
    You will need tokens to represent all of the lexical
    items in expressions like the following:

        1.0 + 1.1 + 3.0
        5.0 – 6.7
        11.3 – (1.4 + 6.4)
*)

datatype TOKEN =
		PLUS
	  | MINUS
	  | LPAREN
	  | RPAREN
	  | NUM of real
	  
	  
(*1.0 + 1.1 + 3.0*)
val exp1 = [NUM 1.0, PLUS, NUM 1.1, PLUS, NUM 3.0]

(*5.0 – 6.7*)
val exp2 = [NUM 5.0, MINUS, NUM 6.7]

(*11.3 – (1.4 + 6.4)*)
val exp3 = [NUM 11.3, MINUS, LPAREN, NUM 1.4, PLUS, NUM 6.4, RPAREN]


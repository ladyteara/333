
(*
    In this file you will implement a parser for
    recognizing expressions similar to the following:

        1.0 + 1.1 + 3.0
        5.0 – 6.7
        11.3 – (1.4 + 6.4)

    As we discussed in class, since your parser is not
    left-recursive it will not have the correct associativity
    for subtraction. Thus, it will generate an incorrect
    parse tree for the following expression:

        1.0 - 2.0 - 3.0

    But that is expected.
*)


(*
    This will load the scanner file for use in this file.
    There are other methods for working with multiple files,
    but this is the most straightforward.
*)
use "scanner.sml";

(*
    This is a simple way to introduce a user-defined exception.
    Essentially, whenever you detect a syntax error you should
    raise this exception:

        raise CalcSyntaxError
*)
exception CalcSyntaxError

datatype expression =
  Dummy
| Subtraction of expression * expression
| Addition of expression * expression
| Number of real

(* (Token list, expression) -> (Token list, expression) *)
fun parse_expression (toks, tree) =
	case toks of
      (* LPAREN expression RPAREN expression' *)
      LPAREN :: toks' => (print "---LPAREN\n";
          let
              val (toks1, tree1) = parse_expression (toks', tree)
          in
              case toks1 of
                  RPAREN :: toks1' => (print "---RPAREN\n"; parse_expression' (toks1', tree1))
                | _ => raise CalcSyntaxError
          end)
      (* NUM expression' *)
    | NUM n :: toks' => (print "---NUM\n"; parse_expression' (toks', Number n))
	  (*everything else*)
    | _ => raise CalcSyntaxError

(* You'll need to fill in this function *)
and parse_expression' (toks, tree) = 
	case toks of
	  PLUS:: toks' => (print "---PLUS\n";
		let 
			val (toks1, tree1) = parse_expression (toks', tree)
			val plusTree = Addition(tree, tree1)
		in
			parse_expression' (toks1, plusTree)
		end)
	| MINUS:: toks' => (print "---MINUS\n";
		let 
			val (toks1, tree1) = parse_expression (toks', tree)
			val minusTree = Subtraction(tree, tree1)
		in
			parse_expression' (toks1, minusTree)
		end)
	| _ => (toks, tree)

fun parse toks = parse_expression (toks, Dummy)


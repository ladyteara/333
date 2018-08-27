(* Write a function that opens a file and reads
   the contents of the file the function should 
   have the type: string -> string list. The
   input string is a file name, and the output
   string list is a list of strings where each
   string is a line in the file. *)

fun readlines (fname : string) =
    let
		val inpfile = TextIO.openIn fname
		fun readLineByLine input =
			case TextIO.inputLine inpfile of
				SOME s => s :: readLineByLine input
				| NONE => []
    in
		readLineByLine [] before TextIO.closeIn inpfile
    end


(* Write a val binding to gain access to the 
   command line arguments. *)

val args = CommandLine.arguments()
val fname = hd args


(* Write another val binding that will be the 
   result of calling the function that you defined 
   above with the first command line argument. *)

val file_lines = readlines fname


(* Finally, you should call the "print" function
   on each item in the list that you acquired
   in the previous step. *)

val _ = map print file_lines


(* This line ensures that the SML/NJ interpreter
   will not treat the command line arguments as
   more sml source files. It should be the final
   line of code in the file. *)
   
val _ = OS.Process.exit(OS.Process.success)


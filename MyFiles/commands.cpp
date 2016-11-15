-1. bash -> Bourne again shell

0. echo $SHELL -> display shell which is used by you.

1. ls -> lists the content example =>
	ls /Users/manishchaurasiya/Desktop/ -> shows the lsit of contents on this particular Desktop directory

2. ls -a -> lists files that normally hidden
  2.1. ls --all -> show the whole info like as "drwxr-xr-x@  38 manishchaurasiya  staff   1.3K Feb 14 14:56 Albums"
  2.2. ls --alh -> same as 2.1.
  2.3. ls -ld -> View the permissions for a specific directory.

3. mkdir "name" -> make Directory

4. cd "name" -> change current working Directory

5. cd .. -> parent of the current directory

6. pwd -> Present working Directory

7. cd ~ -> change to home Directory

8. cp <source> <destination> -> copy file form source to destination

9. cp <source> -> copy file from source to pwd

10. man <command name> -> open refrence for tha command (press "q" for close);

11. a) mv <filenamewithpath> <destination> -> move file to destination as describe
11. b) mv <filename> <newdesiredfilename> -> rename filename

12 a) rm <filename> -> remove the file and you should be inside that files directory
12 b) rm -r <directoryname> -> remove directory, -r stands for recursive, it removes child directory recursively

13. rmdir <directoryname> -> remove directory and you should be inside that parent directory

14. clear -> This will clear all text and leave you with the % prompt at the top of the window.

15. cat <filename> -> The command less writes the contents of a file onto the screen a page at a time.
      Press the [space-bar] if you want to see another page, and type [q] if you want to quit reading.
      As you can see, less is used in preference to cat for long files.

16. touch <newfilename> -> create a new file if it is not exist without permission

17. history -> shows history

18. ~ (tilde) - This is a shortcut for your home directory. eg, if your home directory is /home/ryan
	then you could refer to the directory Documents with the path /home/ryan/Documents or ~/Documents

19. . (dot) - This is a reference to your current directory. eg in the example above we referred to
	Documents on line 4 with a relative path. It could also be written as ./Documents
	(Normally this extra bit is not required but in later sections we will see where it comes in handy).

20. .. (dotdot)- This is a reference to the parent directory. You can use this several times in a path to keep going up the heirarchy.
	eg if you were in the path /home/ryan you could run the command ls ../../ and this would do a listing of the root directory.

21. rm -r <filename> -> remove non-empty Directory

/*********************************** WILD CARDS **********************************/

With WILDCARDS, we are not limited to certain programs or situation.

22. * - represents zero or more characters
	22.1. ls b* -> list all files starts with b.
	22.2. file <path>* -> list all content with its type.

23. ? - represents a single character
	23.1. ls *.??? -> list the files which have extention of three characters.

24. [] - represents a range of characters. you can also include (-) && (^) caret operator;
	24.1. ls [sv]* -> list the files starts with s or v.
	24.2. ls *[0-9]* -> list the files contain the numeric values at all.
	24.3. ls [^a-k]* -> list the files without a & k.


/************************************ Permissions ***********************************/

25. r read -> you may view the contents of the file.

26. w write -> you may change the contents of the file.

27. x execute -> you may execute or run the file if it is a program or script.

Example:
manishs-mbp:solvedProblems manishchaurasiya$ ls -l
total 16
drwxr-xr-x@ 320 manishchaurasiya  staff  10880 Mar  5 13:38 MyFiles
-rw-r--r--@   1 manishchaurasiya  staff     30 Mar  3 16:08 README.md

Explaination :

==>	The first character identifies the file type. If it is a dash ( - ) then it is a normal file.
	If it is a d then it is a directory.

==>	The following 3 characters represent the persmissions for the owner. A letter represents the presence of a permission and
	a dash ( - ) represents the absence of a permission. In this example the owner has all permissions (read, write and execute).

==>	The following 3 characters represent the permissions for the group. In this example the group has the ability to read
	but not write or execute. Note that the order of permissions is always read, then write then execute.

==>	Finally the last 3 characters represent the permissions for others (or everyone else). In this example they have
	the execute permission and nothing else;

28. chmod [permission][path] -> change the permission. (keep in mind)
	* Who are we changing the permission for? [ugoa] - user (or owner), group, others, all
	* Are we granting or revoking the permission - indicated with either a plus ( + ) or minus ( - )
	* Which permission are we setting? - read ( r ), write ( w ) or execute ( x );

	28.1. ls -l frog.png
    -rwxr----x 1 harry users 2.7K Jan 4 07:32 frog.png
	chmod g+x frog.png
	ls -l frog.png
    -rwxr-x--x 1 harry users 2.7K Jan 4 07:32 frog.png

    by using binary numbers or bit permission 1 is set or on..vice versa

    28.2. ls -l frog.png
    -rw-r----x 1 harry users 2.7K Jan 4 07:32 frog.png
	chmod 751 frog.png
	ls -l frog.png
	-rwxr-x--x 1 harry users 2.7K Jan 4 07:32 frog.png
	chmod 240 frog.png
	ls -l frog.png
	--w-r----- 1 harry users 2.7K Jan 4 07:32 frog.png

/************************************ Filters ***********************************/

29. head <filename> -> Head is a program that prints the first so many lines of its input.
	By default it will print the first 10 lines but we may modify this with a command line argument.

30. head [-number of lines to print] [path] -> print number of lines specified.

31. tail <filename> -> Tail is the opposite of head. Tail is a program that prints the last so many lines of its input.
	By default it will print the last 10 lines but we may modify this with a command line argument.

32. tail [-number of lines to print] [path] -> print number of lines specified but from the bottom of the file.

33. sort <filename> -> show lines of the file after sorting..by default it sort aphabedically order.

34. nl <filename> -> show lines with number lines also.

35. nl -s '.' -w 20 x.cpp -> gives padding of 20. check by yourself.

36. wc [-option][path] -> stands for word count.

	36.1. -l will give us lines only, -w will give us words and -m will give us characters.
			The example below gives us just a line count.
			example: wc -l x.cpp   ("20 x.cpp")
			example: wc -lwm x.cpp ("20      56     303 x.cpp")

37. cut [-options] [path] -> cut is a nice little program to use if your content is separated into
							fields (columns) and you only want certain fields;
	37.1. cut -f 1 -d ' ' mysampledata.txt => -d option does (we include the space within single quotes so
											it knows this is part of the argument);
38. uniq [option][path] -> niq stands for unique and its job is to remove duplicate lines from the data.
						 One limitation however is that those lines must be adjacent

39. tac [path] -> It was named this as it does the opposite of cat. Given data it will print the last line first,
				 through to the first line.

40. egrep [command line options] <pattern> [path] -> egrep is a program which will search a given set of data and
		 print every line which contains a given pattern.

	40.1. egrep ';' x.cpp -> show lines which contains ";"
	40.2. egrep -n '{' x.cpp -> show lines which contains { with line number which exactly contains {.
	40.3. egrep -c '{' x.cpp -> count of lines which contains {.
	40.4. for more refrence try this "man egrep".

/************************************ Piping and Redirection ***********************************/

STDIN (0) - Standard input (data fed into the program)
STDOUT (1) - Standard output (data printed by the program, defaults to the terminal)
STDERR (2) - Standard error (for error messages, also defaults to the terminal)

41. > -> The greater than operator ( > ) indicates to the command line that we wish the programs output
		(or whatever it sends to STDOUT) to be saved in a file instead of printed to the screen.

		41.1. ls > myoutput -> save the output of ls command in the file myoutput. if this 'output' file
				then simply save the output otherwsie, it creates the file and the does.

		41.2. wc -l barry.txt > myoutput -> it stores the word count and the barry.txt in the myoutput file.
42. >> -> we can get output	in already existing file rather than overwrite or just new file creation.

		42.1. ls >> myoutput -> as above explain.
43. < -> We will read data from the file and feed it into the program via its STDIN stream.

	43.1 wc -l < barry.txt > myoutput -> try by yourself.

44.	| -> Its called piping and the operator we use is ( | ) (found above the backslash ( \ ) key on most keyboards).
		 What this operator does is feed the output from the program on the left as input to the program on the right.

example:

	manishs-mbp:solvedProblems manishchaurasiya$ ls | head -3
	MyFiles
	README.md
	manishs-mbp:solvedProblems manishchaurasiya$ ls | head -3 | tail -1
	README.md
	manishs-mbp:solvedProblems manishchaurasiya$ ls | head -3 | tail -2
	MyFiles
	README.md
	manishs-mbp:solvedProblems manishchaurasiya$ ls | head -1 | tail -2
	MyFiles
	manishs-mbp:solvedProblems manishchaurasiya$ ls | head -1 | tail -2

/************************************ Process Management ***********************************/

45. top -> want to take a snapshot of what is currently happening on your system.

46. ps -> stands for Process. In its normal usage it will show you just the processes running in your current
			terminal (which is usually not very much).

	@ 'KILLING CRASHED PROGRAM'.

47. kill [PID] -> kill the processes which has Process ID [PID].

	first find the PID. for this, run
		ps aux | grep 'chrome'
		manishchaurasiya   642   0.0  0.0  2432784    624 s000  S+   12:01PM   0:00.00 grep chrome
	then, kill 642.

	@@ 'WHEN DESKTOP HAS LOCKED ?' : Linux actually runs several virtual consoles. Most of the time we only see console 7
	which is the GUI but we can easily get to the others. If the GUI has locked up, and we are in luck, we can get to
	another console and kill the offending process from there. To switch between consoles you use the keyboard sequence
	CTRL + ALT + F<Console>. So CTRL + ALT F2 will get you to a console (if all goes well) where you can run the commands
	as above to identify process ids and kill them. Then CTRL + ALT F7 will get you back to the GUI to see if it has been fixed.
	The general approach is to keep killing processes until the lock up is fixed. Normally you can look for tell tale signs such
	as high CPU or Memory usage and start with those processes first. Sometimes this approach works, sometimes it doesnt and
	you need to restart the computer. Just depends how lucky you are.

48. sleep [numberofseconds] -> wait before presenting you with a prompt again.

49. sleep [numberofseconds] & -> we run the same command but instead put an ampersand ( & ) at the end of the command then we are
	 telling the terminal to run this process in the background.

	 @@ 'We can move jobs between the foreground and background as well. If you press CTRL + z then the currently running foreground
	 process will be paused and moved into the background. We can then use a program called fg which stands for foreground to bring
	 background processes into the foreground'.

	Example :
	manishs-mbp:solvedProblems manishchaurasiya$ sleep 14 &
	[1] 661
	manishs-mbp:solvedProblems manishchaurasiya$ sleep 10
	^Z
	[2]+  Stopped                 sleep 10
	manishs-mbp:solvedProblems manishchaurasiya$ jobs
	[1]-  Done                    sleep 14
	[2]+  Stopped                 sleep 10
	manishs-mbp:solvedProblems manishchaurasiya$ fg 2
	sleep 10

	            KEEP IN MIND
	1: ls- show all the content of that particular directory.
	2: cd ..- for coming out of latest directory.
	3: cd name- for going inside of the director.
	4:touch filename- make a file
	5:./a.out-to run a file
			./a.out<"file name"
	6. stdlib.h for 	rand()
	7. g++ sample.cpp -o <"file name">
	   from above the computer generated a binary file of this name in the same directoryand then
	./"file name"
	  and then gives output
	7.  ./a.out <ipfileName >opfileName
	8. int *value = new int[72];
		by this statement a pointer is generated and which points to very 1st elemnt of the array. That is 7.
		[7][6][][][8][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][].

	value = 0x5fe76d
		and value save the base address of first element.

	9.     	 value[0] = *value
		   value[i] = *(value + i);
		   &value[i] = (value + i);

	10.     <stdio.h>
		%d : integer
		%c : character
		%s : string
		%f : float
		%lf : double
		%lld : long long int (8 byte)
		%p : pointer
	11.	When we pass array as parameter then always keep in mind that it is a pointer which always point to the first
	element....so we 		don't use the & operator in function argument..
		exampel::
		   void (int *ar, int n) OR void (int ar[], int n) {}

	12.	ceil(x) : smallest integer >= x
		floor(x) : largest integer <= x
		truncate(x) : integral part of x   {x} = x - [x]
		example ::
		    x   ceil()   floor()     truncate()
		    0.5   1        0            0
		    2     2        2            2
		   -0.5   0       -1            0
\****************************************************************\

	./aout < #input-file# > #output-file#
	input file se i/p le rha
	aur output o/p file mein jaa rha./a.out <gdf    //i/p
	./a.out >sgdfs  //o/p
	./a.out <adg >dhsgjgds

\***************************************************************|

	Q2: Write a program that asks the user to type n integers of an array.
	The program will then display either
	"the array is growing",
	"the array is decreasing",
	"the array is constant", or
	"the array is growing and decreasing"
	depending on the array..

 \*************************************************************\

		WORK
	1. send him progrm fo structure && series.
	2. Afile on todays expailn topics.

1. call by value : when the values of argument are passed by copy  called call by value.
    example:
         void swap (int a, b) {
            // defenition part
            }
         int main() {
            swap (p, q);
         }
         here, value of p and q are passed to the a and b res.
2. call by refernce : when the values of argument are passed by refernce or passing their address called call by value.
    example:
         void swap (int &a, &b) {
            // defenition part
            }
         int main() {
            swap (p, q);
         }
         here, value of p and q are passed to the a and b res. by thier address so when we change the value of a, b then
         it actually change the value of p, q and we call it the changes are back reflect.

Q1. Why in the stucture the structure variables are passed through the refernce (&)??
==> example:
        void input (Complex &a) {
            \\defenition part
         }
        input (p);

    reason: when we want changes then we use & operator. By this, here we really want to initialize the variables of
    structure variable p.

Q2. Why we use const keyword on passing the struture varibles ??
==> example:
        Complex complexAdd (const Complex &a, const Complex &b) {
        complex d;
        a.real = da.real + b.real;           // compilation error
        return d;
}
here, we does not want to change the values of variable stucture variable a and b.
If by mistake we write any statment in which the values are change then we get the compilation error.
For sake of convenience we use the keyword const.

\**************************************************************************\

void input (Complex *x) {
    scanf ("%d", &((*x).real));
    scanf ("%d", &(x->imaginary);
}

same: x->imaginary || (*x).imaginary

Explain : int *x = new int;

==> In this statemant a memory of space int type allocated in the heap section and the address of this memory is saved
 in a pointer variable name x;




A[] = {7, 8, 5, 1, 19, 11, 2, 6, 3, 15}

                                        (1, 0, 9)[1]
                                          /\
                                         /  \
                                        /    \
                            [1](2, 0, 4)      (3, 5, 9)[2]
                          /  \                         /  \                / [15](15, 9, 9)
                         /    \                       /    \              /
             [5](4, 0, 2)     (5, 3, 4)[1]  [2](6, 5, 7)     (7, 8, 9)[3] \
               /  \                                 /  \                   \ [3](14, 8, 8)
              /    \                               /    \
  [7](8, 0, 1)      [5](9, 2, 2)        [2](12, 5, 6)     [6](13, 7, 7)
          /  \                                    /  \
         /    \                                  /    \
[7](16, 0, 0)  [8](17, 1, 1)        [11](24, 5, 5)      [2](25, 6, 6)


ans = query (1, 0, n-1);

\********************************************************\

#define statements illustration ::
(1) =>
	#define MYNAME 0

	#if MYNAME

	#define TOP printf("X\n");

	#else

	#define TOP printf("Y\n");

	#endif

	using namespace std;

	int main () {
	    TOP;
	    return 0;
	}
(2) =>
	#define MYFUNC(x) cout << #x << ":" << x << "\n";

	using namespace std;

	int main () {
	   int num = 100;
	   MYFUNC (num);
	   return 0;
	}
** (#)operater change X to the string so, this will print num:100 and this will only aplicable in the #define statements.

/************************************************************************************/
      ALIAS NAME:

example:

int swap ( int a, &b) {         //function defenition
}
int main()
{
	int n1, n2;
	swap (n1, n2)            // calling function
}

Here, when the swap function is called then first value of n1 is copied to a
but the variable &b is used the same memory adress of  n2 or in other words
when we swap a and &b then in real n2 is swap with a. so we can say that &b and
n2 are the two n ames of the same memory adress so here &b is an alias name or second name.

* same this concept is used in call by refernce method.
GLOBAL VARIABLES:

int i = 5;

int main() {
	int j = 10;
	//body of main function
}
here, i is a global varible which is assecible in any where in the program,
but j is not...besause j is local variable and it is only asscible in the main().

/*********************************************************************/

#include <queue>
  1. push(), pop(), size(), front(), back();
#include <stack>
  1.push (), pop (), top (), size ();


//////////////// Operating System ////////////
  which "command" => show dir in which command file exists.
  echo $PATH => show dirs of commands
  execlp("ls", "ls", "-l", NULL); => load another binary file of a new process and compiler never
    read the below code because the binary file is changed so its possible to execute the before one.

example :
#include <stdio.h>
#include <unistd.h>

int main () {
    int x = 0;

    printf ("my PID:%d\n", getpid());
    execlp("ls", "ls", "-l", NULL);
    printf ("This should never get executed\n");
    printf ("Creating Child Process Now\n");

    int pid = fork();
    // 2 processes will execute this code after this line independently

    printf ("HELLO WORLD (both processes will print this)\n");

    if (pid == 0) {
        //only child process will get inside this if()
        printf ("(after-fork-child)my PID:%d\n", getpid());
        execlp("ls", "ls", "-l", NULL);
        printf ("This should never get executed\n");
    } else {
        // only parent
        printf ("(after-fork-parent)my PID:%d\n", getpid());
        printf ("My Child's PID:%d\n", pid);
    }

    ++x;
    printf ("BYE WORLD::%d (both processes will print this)\n", x);

    return 0;
}

**    How to print "Hello World!" without using ;
    int main(void)
    {
        if (printf("Hello World")) ;
    }


Ques: What is Dangling pointer?
Ans:  Dangling Pointer is a pointer that doesn’t point to a valid memory location. Dangling pointers arise
      when an object is deleted or deallocated, without modifying the value of the pointer, so that the pointer
     still points to the memory location of the deallocated memory. Following are examples.

example:
int *ptr = (int *) malloc(sizeof(int));
.....
.....
free(ptr)

*ptr = 10;   // ptr is a dangling pointer now and operations like following are invalid
or printf("%d\n", *ptr);

Ques: Difference b/n Array & pointer?
Ans : Pointers are used for storing address of dynamically allocated arrays and for arrays which are
    passed as arguments to functions. In other contexts, arrays and pointer are two different things, see the
    following programs to justify this statement.
    1. Behaviour of sizeof operator
    int main()
    {
       int arr[] = {10, 20, 30, 40, 50, 60};
       int *ptr = arr;
       printf("Size of arr[] %d\n", sizeof(arr));
       printf("Size of ptr %d", sizeof(ptr));
       return 0;
    }
    2. Assigning any address to an array variable is not allowed.
    int main()
    {
       int arr[] = {10, 20}, x = 10;
       int *ptr = &x; // This is fine
       arr = &x;  // Compiler Error
       return 0;
    }

http://geeksquiz.com/commonly-asked-c-interview-questions-set-1/

























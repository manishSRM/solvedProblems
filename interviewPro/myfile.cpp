Amortized complexity : http://stackoverflow.com/questions/200384/constant-amortized-time/249695#249695

copy constructor and assignment operator : http://www.geeksforgeeks.org/copy-constructor-vs-assignment-operator-in-c/

deep copy and shallow copy:
https://www.cs.utexas.edu/~scottm/cs307/handouts/deepCopying.htm
http://www.fredosaurus.com/notes-cpp/oop-condestructors/shallowdeepcopy.html

Templates : http://www.codeproject.com/Articles/257589/An-Idiots-Guide-to-Cplusplus-Templates-Part

Argparse : https://docs.python.org/2/howto/argparse.html
		   https://docs.python.org/3/library/argparse.html#argparse.ArgumentParser.add_argument

Packing And Unpacking Arguments in Python:
	//sample code :

def _test_a(*args, **kvargs):    //unpacking of arguments

	if args:
		_test_function(*args)
	else if kvargs:
		_test_function(**kvargs)

def _test_function(stringValue, intValue, floatValue):
	print 'value1: %s, value2: %d, value3: %f' % (stringValue, intValue, floatValue)


_test_a('Mike',2,3.2)

list_params = ['Udo',7,99.5]
_test_a(*list_params)   //packing of arguments

dict_params = {'stringValue': 'Nami', 'intValue': 23, 'floatValue': 34.67}
_test_a(**dict_params)   // packing of arguments

** : for dictonary
* : for List but actually that is tuple because we cant change in that list thats why tuple.

function decorators : http://thecodeship.com/patterns/guide-to-python-function-decorators/


/**************HTTP******************/
https://www.jmarshall.com/easy/http/#whatis
http://www.tutorialspoint.com/http/http_responses.htm

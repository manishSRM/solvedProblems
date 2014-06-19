const int size = 50,
int queueFront = queueRear = -1;
void push (int element) {
	if (queueRear == size - 1) { 
        printf ("No space of insert element\n");
        return;
    }    	
    else if (queueRear == -1) {
        queue[++queueRear] = element;
        ++queueFront;
    }
    else 
        queue[++queueRear] = element;
	
}
int pop () {
	 if (queueFront == -1) {
        printf ("Nothing to delete\n");
        return 0;
    }
    int item = queue[queueFront++];
    delete item;
    return 1;
}
int empty () {
	if (front == -1) 
		return 1;
	return 0;	
}
int front () {
	if (queueFront == -1) {
		printf ("No element\n");
		return 0;
	}
	return queue[queueFront--];
}
int back () {
	if (queueFront == -1) {
		printf ("No element\n");
		return 0;
	}
	return [queueRear--];
}





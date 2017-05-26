def setBits(N):
    c = 0
    print "Heo"
    while N:
        print ("cur %d"%N)
        if (N >> 1):
            c += 1
        N >>= 1
    return c

T = input()
while T:
	N = input()
	print setBits(N)
	T -= 1
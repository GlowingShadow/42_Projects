import sys
def print_room(nb_room):
	print "##start"
	print "0 0 0"
	print "##end"
	for i in xrange(1, nb_room):
		print i, i, i


def print_link(nb_room):
	for i in xrange(0, nb_room ):
		for j in xrange(i+1, nb_room):
			print str(i) + "-" + str(j)
print "100"
print_room(int(sys.argv[1]))
print_link(int(sys.argv[1]))


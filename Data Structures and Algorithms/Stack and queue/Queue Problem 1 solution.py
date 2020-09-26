# Python Program to check if a queue of first
# n natural number can be sorted using a stack
from queue import Queue

# Function to check if given queue element
# can be sorted into another queue using a
# stack.
def checkSorted(n, q):
	st = []
	expected = 1
	fnt = None

	# while given Queue is not empty.
	while (not q.empty()):
		fnt = q.queue[0]
		q.get()

		# if front element is the
		# expected element
		if (fnt == expected):
			expected += 1

		else:

			# if stack is empty, put the element
			if (len(st) == 0):
				st.append(fnt)

			# if top element is less than element which
			# need to be puted, then return fasle.
			elif (len(st) != 0 and st[-1] < fnt):
				return False

			# else put into the stack.
			else:
				st.append(fnt)

		# while expected element are coming
		# from stack, pop them out.
		while (len(st) != 0 and
				st[-1] == expected):
			st.pop()
			expected += 1

	# if the final expected element value is equal
	# to initial Queue size and the stack is empty.
	if (expected - 1 == n and len(st) == 0):
		return True

	return False

# Driver Code
if __name__ == '__main__':
	q = Queue()
	q.put(5)
	q.put(1)
	q.put(2)
	q.put(3)
	q.put(4)

	n = q.qsize()

	if checkSorted(n, q):
		print("Yes")
	else:
		print("No")

# This code is contributed by PranchalK

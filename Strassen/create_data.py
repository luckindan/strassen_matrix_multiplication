import random
import argparse
import math
import sys

def create_data(x, num, filename):
	filename = str(filename)
	x = int(x)
	num = int(num)
	with open(str(filename), 'w') as f:
		for i in range(x):
			a = []
			for j in range(x):
				a.append(str(int(random.randrange(0,num))))
			f.write(', '.join(a) + '\n')


if __name__ ==  '__main__':
	parser = argparse.ArgumentParser()
	parser.add_argument("matrix_size", help = "the number of row and col", default=100)
	parser.add_argument("max_value", help="The max random value",default=math.sqrt(sys.maxsize)-1)
	parser.add_argument("filename", help="File name where to store data", default='random_data.txt')

	args = parser.parse_args()
	create_data(args.matrix_size, args.max_value, args.filename)
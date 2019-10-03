import random
import argparse
import math
import sys

def create_data(row, col, num, filename):
	filename = str(filename)
	row = int(row)
	col = int(col)
	num = int(num)

	with open(str(filename), 'w') as f:
		for i in range(row):
			a = []
			for j in range(col):
				a.append(str(int(random.randrange(0,num))))
			f.write(', '.join(a) + '\n')


if __name__ ==  '__main__':
	parser = argparse.ArgumentParser()
	parser.add_argument("row", help = "the number of row", default=100)
	parser.add_argument("col", help = "the number of col", default=100)
	
	parser.add_argument("max_value", help="The max random value",default=math.sqrt(sys.maxsize)-1)
	parser.add_argument("filename", help="File name where to store data", default='random_data.txt')

	args = parser.parse_args()
	create_data(args.row, args.col , args.max_value, args.filename)
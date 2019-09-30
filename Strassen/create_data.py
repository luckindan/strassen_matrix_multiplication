import random

with open('random_data.txt', 'w') as f:
	for i in range(900):
		a = []
		for j in range(900):
			a.append(str(int(random.randrange(0,255))))
		f.write(', '.join(a) + '\n')

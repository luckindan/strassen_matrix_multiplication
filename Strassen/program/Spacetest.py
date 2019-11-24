import os
from datetime import datetime
import numpy as np

def main():
	

	signal  = True
	counter = 0

	animation = "|/-\\"
	idx = 0
	try:
		os.system("rm ../Log/memory_limit_report.csv")
		os.system("rm ../Log/memory_usage_report.csv")
	except:
		pass 

	with open("../Log/memory_limit_report.csv", 'a') as f:
			f.write("BAM,SAM,k=4,k=8,k=16,k=32,k=64,k=128,k=256,k=512,k=1024,k=2048,k=half,k=log,k=sqrt,data_size" + '\n')
	
	space_log("BAM,SAM,k=4,k=8,k=16,k=32,k=64,k=128,k=256,k=512,k=1024,k=2048,k=half,k=log,k=sqrt,data_size" + '\n')

	limit = 12
	counter = 1
	while signal and counter <= limit:
		data_size = 2** counter
		for i in range(10):
			signal = executeCode(data_size)

		
		counter+=1

	#breakingPoint = binary_search_datasize(data_size/2, data_size)
	#print("breakingPoint is")
	#print(breakingPoint)

def log(data_size):
	with open("../Log/memory_limit_report.csv", 'a') as f:
			f.write(str(data_size) + '\n')	


def space_log(msg):
	with open("../Log/memory_usage_report.csv", 'a') as f:
			f.write(str(msg))


def get_max_massif(filename):

	with open(filename) as f:
		k = f.read().split()
		alist = []
		
		for i in k:
			try:
				if i[:10] == "mem_heap_B":
					alist.append(int(i.split('=')[1]))
			except:
				pass

		return max(alist)

def analyze_space():
	files = os.listdir()

	massfilename = ""

	for i in files:
		try:
			if i[:4] == "mass":
				massfilename = i
				break
		except:
			pass

	max_memory = get_max_massif(massfilename)
	space_log(str(max_memory) + ',')
	os.system('rm ' + massfilename)

def executeCode(data_size):
	
	command_create_file = "python3 ../data/create_data.py"
	command_run1 = "valgrind --tool=massif --pages-as-heap=yes ./reg"
	command_run2 = "valgrind --tool=massif --pages-as-heap=yes ./strass"
	data_file_name1 =  "../data/"+str(data_size) + "_1.txt"
	data_file_name2 =  "../data/"+str(data_size) + "_2.txt"
	
		#create file here
	command_1 = " ".join([command_create_file,str(data_size),str(data_size), str(65535), data_file_name1])

	command_2 = " ".join([command_create_file,str(data_size),str(data_size), str(65535), data_file_name2])
		
	os.system(command_1)
	os.system(command_2)		
		#run regular computation
	command_3 = " ".join([command_run1, data_file_name1, data_file_name2])
	os.system(command_3)
	analyze_space()

		#run strassen computation
	ks = ['2',
		'4',
		'8',
		'16',
		'32',
		'64',
		'128',
		'256',
		'512',
		'1024',
		'2048',
		str(int(data_size/2)),
		str(int(np.log2(data_size))),
		str(int(np.sqrt(data_size)))
		]

		#execute the strassen k
	for i in ks:
		command_4 = " ".join([command_run2, data_file_name1, data_file_name2, i])		
		os.system(command_4)
		analyze_space()

	os.system("rm " + data_file_name1)
	os.system("rm " + data_file_name2)
	log(data_size)
	space_log(str(data_size) + '\n')
	return True

#	except:
#		print("Error")
#		return False

if __name__ == '__main__':
	main()














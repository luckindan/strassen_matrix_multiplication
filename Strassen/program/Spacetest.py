import os
from datetime import datetime

def main():
	
	data_size = 2
	signal  = True
	counter = 0

	animation = "|/-\\"
	idx = 0
	
	os.system("rm ../Log/memory_limit_report.txt")

	while signal:
		
		signal = executeCode(data_size)

		data_size *=2
		print(str(data_size) + animation[idx % len(animation)], end="\r")
		idx = (idx+1)%len(animation)

	breakingPoint = binary_search_datasize(data_size/2, data_size)
	print("breakingPoint is")
	print(breakingPoint)

def log(data_size):
	with open("../Log/memory_limit_report.txt", 'a') as f:
			f.write(str(data_size) + '\n')	

def binary_search_datasize(data_size_s, data_size_l):
	if data_size_s >= data_size_l:
		return data_size_s

	midpoint = int((data_size_l + data_size_s)/2)
	
	
	is_midpoint = executeCode(midpoint)
	is_midpoint_right = executeCode(midpoint +1)
	is_midpoint_left = executeCode(midpoint-1)

	if is_midpoint and not is_midpoint_right:
		return midpoint
	elif is_midpoint:
		return binary_search_datasize(midpoint+1, data_size_l)
	else:
		return binary_search_datasize(data_size_s, midpoint-1)





def executeCode(data_size):
	
	command_create_file = "python3 ../data/create_data.py"
	command_run = "./out"
	data_file_name1 =  "../data/"+str(data_size) + "_1.txt"
	data_file_name2 =  "../data/"+str(data_size) + "_2.txt"
	try:
		command_1 = " ".join([command_create_file,str(data_size),str(data_size), str(65535), data_file_name1])

		command_2 = " ".join([command_create_file,str(data_size),str(data_size), str(65535), data_file_name2])
		
		command_3 = " ".join([command_run, data_file_name1, data_file_name2])

		os.system(command_1)
		os.system(command_2)
		os.system(command_3)
		os.system("rm " + data_file_name1)
		os.system("rm " + data_file_name2)
		log(data_size)
		return True

	except:
		print("Error")
		return False

if __name__ == '__main__':
	main()














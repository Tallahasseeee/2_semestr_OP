import pickle
class Client:
	surname = ""
	name = ""
	hrs = 0
	mins = 0
	dur = 0
	state = False
	def save(self,line):
		arr = line.split(' ')
		if (len(arr) > 3):
			self.state = True
			self.surname = arr[0]
			self.name = arr[1]
			self.dur = int(arr[3])
			if arr[2].count(':'):
				tm = arr[2].split(':')
				self.hrs = int(tm[0])
				self.mins = int(tm[1])
			else:
				self.state = False
				print("Wrong time format\n")
		else:
			self.state = False
			print("Wrong format\n")

def input_file(filePath):
	#print("Enter client info in format: Surname Name Time(HH:MM) Duration(in minutes)\n")
	line = input("Enter client info in format: Surname Name Time(HH:MM) Duration(in minutes)\n")
	while line != "":
		person = Client()
		person.save(line)
		if person.state == True:
			if check_time(filePath, person) == True:
				with open(filePath,'ab') as file:
					pickle.dump(person,file)
				file.close()
			else:
				print("No time\n")
		line = input()


def check_time(filePath,person):
	flag = True
	person1 = Client()
	with open(filePath,'rb') as file:
		size = file.seek(0,2)
		file.seek(0)
		while file.tell() < size:
			person1 = pickle.load(file)
			chk = True
			chk = ((person1.hrs * 60 + person1.mins + person1.dur > person.hrs * 60 + person.mins) and (person1.hrs * 60 + person1.mins + person1.dur < person.hrs * 60 + person.mins + person.dur)) or ((person.hrs * 60 + person.mins + person.dur > person1.hrs * 60 + person1.mins) and (person.hrs * 60 + person.mins + person.dur < person1.hrs * 60 + person1.mins + person1.dur))
			if chk == True:
				flag = False
	file.close()
	return flag

def show_late_clients(filePath):
	print("\nClients that will come after 16:30:\n")
	person = Client()
	with open(filePath,'rb') as file:
		size = file.seek(0, 2)
		file.seek(0)
		while file.tell() < size:
			person = pickle.load(file)
			if (person.hrs*60 + person.mins) > (16*60 + 30):
				print(person.surname + " " + person.name + " " + str(person.hrs) + ":" + str(person.mins) + " " + str(person.dur) + "\n")
	file.close()

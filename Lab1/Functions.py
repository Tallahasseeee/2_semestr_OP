def input_file(filename):
    with open(filename, 'w') as infile:
        line = input("Enter text (send empty line to finish): \n")
        while line != "":
            infile.write(line + "\n")
            line = input()


def output_file(filename):
    with open(filename, 'r') as file:
        lines = file.read().split("\n")
        for i in lines:
            print(i)


def create_second_file(first_file_name, second_file_name):
    with open(first_file_name, 'r') as infile:
        with open(second_file_name, 'w') as outfile:
            lines = infile.read().split("\n")
            for i in range(len(lines)):
                if lines[i] != "":
                    temp = lines[i]
                    words = temp.split()
                    numbers = []
                    st = ""
                    for j in range (len(words)):
                        st = ""
                        for k in range(len(words[j])):
                            if isDigit(words[j][k]):
                                st += words[j][k]
                            elif isDigit(words[j][k]) == False and st != "":
                                numbers.append(st)
                                st = ""
                        if st != "":
                            numbers.append(st)

                    numbers = change_line(numbers)
                    for q in range(len(numbers)):
                        outfile.write(numbers[q] + " , ")
                    outfile.write("\n")


def isDigit(ch):
    if ch == '1' or ch == '2' or ch == '3' or ch == '4' or ch == '5' or ch == '6' or ch == '7' or ch == '8' or ch == '9' or ch == '0':
        return True
    else:
        return False

def change_line(numbers):
    max = "0"
    memory = ""
    index = 0
    for i in range(len(numbers)):
        if int(max) < int(numbers[i]):
            max = numbers[i]
            index = i
    memory = numbers[0]
    numbers[0] = max
    numbers[index] = memory
    return numbers
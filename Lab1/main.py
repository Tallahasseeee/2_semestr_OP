import math
R = float(input("Введіть радіус основи: "))
H = float(input("Введіть висоту: \n"))
if R > 0 and H > 0:
    print("Об'єм циліндра = " + str(math.pi*R*R*H))
    print("Об'єм циліндра = " + str(math.pi*R*R*H/3))
else:
    print("Введено некоректні дані")
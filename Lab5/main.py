from Functions import *

db = DoubleMatrix()
print("Double Matrix : \n")
db.show_matrix()
print("Sum of elements: " + str(db.Sum()) + "  Determinant: " + str(db.determinant()) + "\n\n")

tp = TripleMatrix()
print("Triple Matrix : \n")
tp.show_matrix()
print("Sum of elements: " + str(tp.Sum()) + "  Determinant: " + str(tp.determinant()) + "\n\n")
print("The result of function is: " + str(result(db, tp)))
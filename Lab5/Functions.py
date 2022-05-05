import random


class TMatrix:
    def __init__(self):
        self.size = 0
        Matrix = []

    def show_matrix(self):
        string = ""
        for i in range(self.size):
            for j in range(self.size):
                string += str(self.Matrix[i][j]) + '  '
            string += '\n'
        print(string)

    def Sum(self):
        res = 0
        for i in range(self.size):
            for j in range(self.size):
                res += self.Matrix[i][j]
        return res

    def determinant(self):
        pass


class DoubleMatrix(TMatrix):
    #Matrix = [[0, 0], [0, 0]]
    def __init__(self):
        self.size = 2
        self.Matrix = [[0, 0], [0, 0]]
        for i in range(self.size):
            for j in range(self.size):
                self.Matrix[i][j] = random.randint(-10, 10)

    def determinant(db):
        return db.Matrix[0][0] * db.Matrix[1][1] - db.Matrix[1][0] * db.Matrix[0][1]


class TripleMatrix(TMatrix):
    size = 3
    Matrix = [[0, 0, 0], [0, 0, 0], [0, 0, 0]]
    def __init__(self):
        for i in range(self.size):
            for j in range(self.size):
                self.Matrix[i][j] = random.randint(-10, 10)

    def determinant(self):
        return self.Matrix[0][0] * self.Matrix[1][1] * self.Matrix[2][2] + self.Matrix[0][1] * self.Matrix[2][0] * \
               self.Matrix[1][2] + self.Matrix[1][0] * \
               self.Matrix[2][1] * self.Matrix[0][2] - self.Matrix[2][0] * self.Matrix[1][1] * self.Matrix[0][2] - \
               self.Matrix[0][0] * self.Matrix[1][2] * \
               self.Matrix[2][1] - self.Matrix[2][2] * self.Matrix[1][0] * self.Matrix[0][1]


def result(db, tp):
    res = tp.Sum() + tp.determinant() + db.determinant()
    return res

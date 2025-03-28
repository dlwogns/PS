# class

class BasicCal:
    a = 1
    def getA(self):
        return getA

class Calculator(BasicCal):
    first_number = 0
    second_number = 0
    def __init__(self, first, second):
        #생성자
        self.first_number = first
        self.second_number = second
        
    def setdata(self, first, second):
        self.first = first
        self.second = second
    
    def add(self):
        result = self.first_number + self.second_number
        return result

#cal1 = Calculator()
#cal1.setdata(1, 2)

cal1 = Calculator(1,2)

cal1.getA()
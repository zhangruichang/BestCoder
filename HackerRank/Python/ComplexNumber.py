import cmath
class ComplexNumber:
    def __init__(self, real, imag):
        self.real=real
        self.imag=imag

def Show(C1):
    if C1.real!=0 and C1.imag!=0:
        if C1.imag>0:
            print ("%.2f" % C1.real)+' + '+("%.2f" % C1.imag)+'i'
        else:
            print ("%.2f" % C1.real)+' - '+("%.2f" % -C1.imag)+'i'
    elif C1.real!=0:
        print ("%.2f" % C1.real)
    elif C1.imag!=0:
        #if C1.imag>0:
        print ("%.2f" % C1.imag)+'i'
    else:
        print ("%.2f" % 0)

def __add__(C1, C2):
    Ans=ComplexNumber(0, 0)
    Ans.real=C1.real+C2.real
    Ans.imag=C1.imag+C2.imag
    return Ans

def __sub__(C1, C2):
    Ans=ComplexNumber(0, 0)
    Ans.real=C1.real-C2.real
    Ans.imag=C1.imag-C2.imag
    return Ans

def __mul__(C1, C2):
    Ans=ComplexNumber(0, 0)
    Ans.real=C1.real*C2.real-C1.imag*C2.imag
    Ans.imag=C1.real*C2.imag+C1.imag*C2.real
    return Ans

def __div__(C1, C2):
    #(a+bi)/(c+di)=(ec+fd)/(c^2+d^2) + (fc-ed)/(c^2+d^2)i
    Ans=ComplexNumber(0, 0)
    Ans.real=(C1.real*C2.real+C1.imag*C2.imag)/(C2.real*C2.real+C2.imag*C2.imag)
    Ans.imag=(C1.imag*C2.real-C1.real*C2.imag)/(C2.real*C2.real+C2.imag*C2.imag)
    return Ans

def Mod(C1):
    return cmath.sqrt(C1.real*C1.real+C1.imag*C1.imag)

a, b=[float(x) for x in raw_input().split()]
C1=ComplexNumber(a, b)
c, d=[float(x) for x in raw_input().split()]
C2=ComplexNumber(c, d)
Show(__add__(C1 , C2))
Show(__sub__(C1, C2))
Show(__mul__(C1,C2))
Show(__div__(C1,C2))
Show(Mod(C1))
Show(Mod(C2))
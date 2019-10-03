class animal:
    def __init__(self,btype="unknown",app="unknown",blood="unknown"):
        self.__btype=btype
        self.__app=app
        self.__blood=blood
    @property
    def btype(self):
        return self.__btype
    @btype.setter
    def btype(self,btype):
        self.__btype=btype
    @property
    def app(self):
        return self.__app
    @app.setter
    def app(self,app):
        self.__app=app
    @property
    def blood(self):
        return self.__blood
    @blood.setter
    def blood(self,blood):
        self.__blood=blood
    def __str__(self):
        return "A {} is {} it is {} it is {}".format(type(self).__name__,self.btype,self.app,self.blood)


class mammal(animal):
    def __init__(self,btype="born alive",app="hair or fur",blood="warm blooded",nurseyoung=True):
        animal.__init__(self,btype,app,blood)
        self.__nurseyoung=nurseyoung
    @property
    def nurseyoung(self):
        return self.__nurseyoung
    @nurseyoung.setter
    def app(self,nurseyoung):
        self.__nurseyoung=nurseyoung

    def __str__(self):
        return super().__str__()+"and it is {} they nurse their young".format(self.nurseyoung)

class reptile(animal):
    def __init__(self,btype="born in an egg or born alive",app="dry scales",blood="cold blooded"):
        animal.__init__(self,btype,app,blood)
    def sumall(self, *args):
        sum=0
        for i in args:
            sum+=1
        return sum
def main():
    animall=animal("born alive")
    print(animall.btype)
    print(animall)
    print()
    mammall=mammal()
    print(mammall)
    print(mammall.btype)
    print(mammall.app)
    print(mammall.blood)
    print(mammall.nurseyoung)
    print()
    reptile1=reptile()
    print(reptile1.btype)
    print(reptile1.app)
    print(reptile1.blood)
    print()
    print("sum : {}".format(reptile1.sumall(1,2,3,4,5)))
    def getbtype(theobject):
        print("the {} is {}".format(type(theobject).__name__,theobject.btype))
    getbtype(mammall)
    getbtype(reptile1)
main()
    

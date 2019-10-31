import time
class car:
    def __init__(self,a=40):
        self.speed = a
    def get_speed(self):
        return print(self._speed)
    def set_speed(self, a):
        if a<=0 or a>=180:
            print("its not in b\w 0-180, can't set to it.")
        else:
            self._speed = a
            print("your speed is set to new value {}".format(a))

    speed = property(get_speed , set_speed)


p1= car()
time.sleep(1)
p1.get_speed()
p1.set_speed(-90)
p1.set_speed(50)
time.sleep(3)
p1.get_speed()
print(p1.speed)
time.sleep(3)
p1.speed = 80
print(p1.speed)
p1.speed = 200
print(p1.speed)

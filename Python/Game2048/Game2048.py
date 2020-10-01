import kivy
from kivy.app import App
from kivy.uix.widget import Widget
from kivy.uix.boxlayout import BoxLayout
from random import choice,random
from kivy.properties import NumericProperty,ObjectProperty,OptionProperty
from kivy.graphics import Color
from kivy.clock import Clock
from kivy.animation import Animation
from kivy.utils import get_color_from_hex
from kivy.core.window import Window

class ButtonBehaviour(object):
    pass

class Number(Widget):
    number = NumericProperty(2)
    scale = .1
    colors = {
        2: get_color_from_hex('#eee4da'),
        4: get_color_from_hex('#ede0c8'),
        8: get_color_from_hex('#f2b179'),
        16: get_color_from_hex('#f59563'),
        32: get_color_from_hex('#f67c5f'),
        64: get_color_from_hex('#f65e3b'),
        128: get_color_from_hex('#edcf72'),
        256: get_color_from_hex('#edcc61'),
        512: get_color_from_hex('#edc850'),
        1024: get_color_from_hex('#edc53f'),
        2048: get_color_from_hex('#edc22e'),
        4096: get_color_from_hex('#ed702e'),
        8192: get_color_from_hex('#ed4c2e')
    }
    def __init__(self,**kwargs):
        super(Number,self).__init__(**kwargs)
        anim = Animation(scale = 1,d = 0.15,t = "out_quad")
        anim.start(self)

    def destroy(self,*args):
        self.parent.rempve_widget(self)

    def Move_to(self,pos):
        if self.pos == pos:
            return
        Animation(pos = pos,d = 0.15,t = "out_quad").start(self)

    def Move_to_and_destroy(self,pos):
        self.destroy()

class Game2048(Widget):
    cube_size = NumericProperty(10)
    cube_padding = NumericProperty(10)
    score = NumericProperty(0)

    def __init__(self,**kwargs):
        super(Game2048,self).__init__()
        self.grid = [
            [None,None,None,None],
            [None,None,None,None],
            [None,None,None,None],
            [None,None,None,None]
        ]
        Window.bind(on_key_down = self.on_touch_down)
    def on_key_down(self,window,key,*args):
        moved = False

        if key == 273:
            moved = self.Move_topdown(True,from_keyboard = True)

    def rebuild_background(self):
        self.canvas.before.clear()
        with self.canvas.before:
            Color(Oxbb /255., Oxad/255., OxaO/255.)
            BorderImage(pos = self.pos,size = self.size,source = 'data/round.png')
            Color(Oxcc/255.,OxcO/255.,Oxb3/255.)
            csize = self.cube_size,self.cube_size

class Game2048(App):
    def build(self):
        return

if __name__ == "__main__":
    Game2048().run()
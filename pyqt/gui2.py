# import sys
# from PyQt5.QtCore import *
from PyQt5.QtGui import *
# from PyQt5 import *
from PyQt5 import QtCore, QtGui, QtWidgets
# # from PySide2.QtWidgets import QApplication, QDialog
from PyQt5.QtWidgets import *

import sys
from PyQt5.QtCore import *
from PyQt5.QtGui import *
from PyQt5 import *


def window():
    app = QtWidgets.QApplication(sys.argv)
    win = QDialog()
    b1 = QPushButton(win)
    b1.setText("Button1")
    b1.move(50, 20)
    b1.clicked.connect(b1_clicked)

    b2 = QPushButton(win)
    b2.setText("Button2")
    b2.move(50, 50)
    b2.clicked.connect(b2_clicked)

    # QObject.connect(b2,SIGNAL("clicked()"),b2_clicked)

    win.setGeometry(100, 100, 200, 100)
    win.setWindowTitle("PyQt")
    win.show()
    sys.exit(app.exec_())


def b1_clicked():
    print("Button 1 clicked")


def b2_clicked():
    print("Button 2 clicked")


if __name__ == '__main__':
    window()

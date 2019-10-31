# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'MenuFun.ui'
#
# Created by: PyQt5 UI code generator 5.13.1
#
# WARNING! All changes made in this file will be lost!


from PyQt5 import QtCore, QtGui, QtWidgets
import math

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(800, 600)
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.formLayout = QtWidgets.QFormLayout(self.centralwidget)
        self.formLayout.setObjectName("formLayout")
        self.label = QtWidgets.QLabel(self.centralwidget)
        self.label.setObjectName("label")
        self.formLayout.setWidget(0, QtWidgets.QFormLayout.LabelRole, self.label)
        self.t1 = QtWidgets.QLineEdit(self.centralwidget)
        self.t1.setObjectName("t1")
        self.formLayout.setWidget(0, QtWidgets.QFormLayout.FieldRole, self.t1)
        self.label_2 = QtWidgets.QLabel(self.centralwidget)
        self.label_2.setObjectName("label_2")
        self.formLayout.setWidget(1, QtWidgets.QFormLayout.LabelRole, self.label_2)
        self.t2 = QtWidgets.QLineEdit(self.centralwidget)
        self.t2.setObjectName("t2")
        self.formLayout.setWidget(1, QtWidgets.QFormLayout.FieldRole, self.t2)
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 800, 22))
        self.menubar.setObjectName("menubar")
        self.menuFile = QtWidgets.QMenu(self.menubar)
        self.menuFile.setObjectName("menuFile")
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)
        self.actioncube = QtWidgets.QAction(MainWindow)
        self.actioncube.setObjectName("actioncube")
        self.actionsquare = QtWidgets.QAction(MainWindow)
        self.actionsquare.setObjectName("actionsquare")
        self.actionsquareroot = QtWidgets.QAction(MainWindow)
        self.actionsquareroot.setObjectName("actionsquareroot")
        self.actionSquare = QtWidgets.QAction(MainWindow)
        self.actionSquare.setObjectName("actionSquare")
        self.actionCube = QtWidgets.QAction(MainWindow)
        self.actionCube.setObjectName("actionCube")
        self.actionSqrRoot = QtWidgets.QAction(MainWindow)
        self.actionSqrRoot.setObjectName("actionSqrRoot")
        self.actionCubeRoot = QtWidgets.QAction(MainWindow)
        self.actionCubeRoot.setObjectName("actionCubeRoot")
        self.menuFile.addAction(self.actionSquare)
        self.menuFile.addAction(self.actionCube)
        self.menuFile.addAction(self.actionSqrRoot)
        self.menuFile.addAction(self.actionCubeRoot)
        self.menubar.addAction(self.menuFile.menuAction())

        self.menuFile.triggered[QtWidgets.QAction].connect(self.menufunction)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow"))
        self.label.setText(_translate("MainWindow", "Number"))
        self.label_2.setText(_translate("MainWindow", "Function"))
        self.menuFile.setTitle(_translate("MainWindow", "File"))
        self.actioncube.setText(_translate("MainWindow", "cube"))
        self.actionsquare.setText(_translate("MainWindow", "square"))
        self.actionsquareroot.setText(_translate("MainWindow", "squareroot"))
        self.actionSquare.setText(_translate("MainWindow", "Square"))
        self.actionCube.setText(_translate("MainWindow", "Cube"))
        self.actionSqrRoot.setText(_translate("MainWindow", "SqrRoot"))
        self.actionCubeRoot.setText(_translate("MainWindow", "CubeRoot"))

    def menufunction(self, action):
        txt = (action.text())
        no = int(self.t1.text())
        print(txt, no)
        if txt == 'Square':
            self.t2.setText(str(no*no))
        if txt == 'Cube':
            self.t2.setText(str(no*no*no))
        if txt == 'SqrRoot':
            self.t2.setText(str(math.sqrt(no)))
        if txt == 'CubeRoot':
            self.t2.setText(str(math.pow(no,1/3)))


    def context_menu(MainWindow):
        menu = QtWidget.QMenu()
        menu.addActon("First Option")
        menu.addActon("Second Option")
        menu.addActon(":)")
        menu.exec_(Qtgui.QCursor.pos())

if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    MainWindow = QtWidgets.QMainWindow()
    ui = Ui_MainWindow()
    ui.setupUi(MainWindow)
    MainWindow.show()
    sys.exit(app.exec_())

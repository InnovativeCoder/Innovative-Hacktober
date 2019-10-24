#!/usr/bin/python3
#  qtgui.py
#  
#  Copyright 2014 huangtao <huangtao.jh@gmail.com>
#  
#  This program is free software; you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation; either version 2 of the License, or
#  (at your option) any later version.
#  
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#  
#  You should have received a copy of the GNU General Public License
#  along with this program; if not, write to the Free Software
#  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
#  MA 02110-1301, USA.
#  
#  
# 项目：库函数
# 名称：QT5库函数
# 作者：黄涛
# 创建：2014-8-3
# 修订：2015-2-6 增加MTreeWidget相关功能

from sys import argv,exit
from os.path import splitext,join,isfile
from functools import partial
from datetime import datetime,date,time
try:
    from PyQt5.QtWidgets import *
    from PyQt5.QtGui import *
    from PyQt5.QtCore import *
except:
    from PyQt4.QtGui import *
    from PyQt4.QtCore import *
from .textparser import parser

class MTreeWidget(QTreeWidget):
    def setColumnWidths(self,*widths):
        if self.columnCount!=len(widths):
            self.setColumnCount(len(widths))
        for i,width in enumerate(widths):
            self.setColumnWidth(i,width)

    def setLabels(self,labels):
        lbls=labels.split("|")
        if self.columnCount!=len(lbls):
            self.setColumnCount(len(lbls))
        self.setHeaderLabels(lbls)

    def setData(self,data):
        def proc_child(owner,data):
            for child in data.childs():
                attrib=child.attrib
                text=attrib['text'] if 'text' in attrib else [child.tag]
                item=QTreeWidgetItem(owner,text)
                if 'icon' in attrib:
                    for i,icon in enumerate(attrib['icon']):
                        item.setIcon(i,QIcon(icon))
                proc_child(item,child)
        proc_child(self,data)
            

class MTableWidget(QTableWidget):
    def setColumnWidths(self,*widths):
        if self.columnCount!=len(widths):
            self.setColumnCount(len(widths))
        for i,width in enumerate(widths):
            self.setColumnWidth(i,width)

    def setHLabels(self,labels):
        lbls=labels.split("|")
        if self.columnCount!=len(lbls):
            self.setColumnCount(len(lbls))
        self.setHorizontalHeaderLabels(lbls)

    def setData(self,data):
        self.setRowCount(len(data))
        for r,row in enumerate(data):
            for c,col in enumerate(row):
                self.setItem(r,c,QTableWidgetItem(col))
                
    def data(self):
        d=[]
        for r in range(self.rowCount()):
            row=[]
            for c in range(self.columnCount()):
                item=self.item(r,c)
                if item is not None:
                    row.append(self.item(r,c).text())
            if row:
                d.append(row)
        return d
                

class MCheckBoxGroup(QGroupBox):
    buttons={}
    _columns=4
    def __init__(self,*args,**kwargs):
        super().__init__(*args,**kwargs)
        self.layout=QGridLayout(self)
        self.setLayout(self.layout)
        self.vals=set()
        
    def setColumns(self,columns):
        if columns>0:
            self._columns=columns
    
    def columns(self):
        return self._columns
    
    def setItems(self,items):
        [button.close() for button in self.buttons]
        self.buttons={}
        for i,(value,label) in enumerate(items):
            button=QCheckBox(label,self)
            self.layout.addWidget(button,i//self._columns,i%self._columns)
            self.buttons[button]=value
            
    def values(self):
        return [value for button,value in self.buttons.items() if button.isChecked()]
                            
    def setValues(self,values):
        self.vals=set(values)
        [button.setChecked(value in values) for button,value in self.buttons.items()]
    
    def delta(self):
        new=set(self.values())
        return list(self.vals-new),list(new-self.vals)
    
    def selectAll(self):
        [button.setChecked(True) for button in self.buttons]
    
    def deSelectAll(self):
        [button.setChecked(False) for button in self.buttons]
        

class MComboBox(QComboBox):
    '''自定义的ComboBox类
    新增setItems函数，便于使用Items来设置下拉菜单    
    '''
    def setCurrentText(self,value):
        pass
    def setItems(self,items):
        self.clear()            #清理下拉菜单
        self.addItems(items)    #新增下拉菜单
        
class MTextEdit(QTextEdit):
    '''
    自定义的多行文本编辑类
    新增plainText方法
    '''
    def plainText(self):        
        return self.toPlainText()  #获取纯文本

class QtGui:
    ALIAS={                         #类型别名
            'edit':QLineEdit,       #单行文本编辑
            'hbox':QHBoxLayout,     #水平框布局
            'vbox':QVBoxLayout,     
            'form':QFormLayout,     #表单布局
            'grid':QGridLayout,     #表格布局
            'button':QPushButton,   #按钮
            'combobox':MComboBox,   #组合框
            'textedit':MTextEdit,   #多行文本编辑框
            'checkboxgroup':MCheckBoxGroup,
            'tablewidget':MTableWidget,
            'treewidget':MTreeWidget,
            }
    WIDGETS={}                      #组件缓存
#    PROPERTYS={}                    #属性缓存
    windows={}                      #窗口缓存
    resources={}                    #资源缓存
    @classmethod
    def get_widget(cls,name):       #从缓存中获取组件
        name=name.lower()
        w=cls.ALIAS.get(name)
        if w:return w
        if not name.startswith('q'):name='q'+name
        return cls.WIDGETS.get(name)
    
    @classmethod
    def get_propertys(cls,widget):  #从缓存中获取属性
        #ps=cls.PROPERTYS.get(widget.__class__)
        #本地变量强制刷新
        #if(ps is None)or('__main__' in str(widget.__class__)):
        ps=dict((x.lower(),x)for x in dir(widget))
        #    cls.PROPERTYS[widget.__class__]=ps 
        return ps
        
    @staticmethod
    def create_icon(owner,path):   #根据文件名生成图标
        if path is not None:      #文件名默认加上根路径或images路径
            for f in ['',owner.base_dir,join(owner.base_dir,'images')]:
                if isfile(join(f,path)):
                    path=join(f,path)
                    break
        return QIcon(path)
        
    @classmethod
    def get_attr(cls,attr,owners):
        def get__attr(attr,owner):
            attr=attr.lower()
            ps=cls.get_propertys(owner)
            if ps and attr in ps:
                return getattr(owner,ps[attr])
                
        if '.' not in attr:
            for owner in owners:
                result=get__attr(attr,owner)
                if result:
                    return result
        else:
            attrs=attr.split('.')
            owner=eval(attrs[0]) if attrs[0] in globals() else cls.get_attr(attrs[0],owners)
            for a in attrs[1:]:
                owner=get__attr(a,owner)
                if owner is None:return None
            else:
                return owner
        
    def __init__(self,file_name=None):   #初始化函数
        if file_name is not None:   #如果有文件名，则加载UI资源
            try:
                for node in parser(file_name):
                    if 'name' in node.attrib:  #缓存窗口资源
                        self.windows[node.attrib['name'].lower()]=node
                    if 'id' in node.attrib:    #缓存锚点资源
                        self.resources[node.attrib['id'].lower()]=node
            except:
                pass
        #缓存所有的Widget及Layout
        widgets=[x for x in globals() if x.startswith('Q')]
        for x in widgets:
            try:
                v=eval(x)
                if issubclass(v,QWidget) or issubclass(v,QLayout):
                    self.WIDGETS[x.lower()]=v
            except:
                pass

    @staticmethod
    def main(Window):         #主程序，需要送一个窗口类
        app=QApplication(argv)
        main_win=Window().widget
        exit(app.exec_())

    def setup_UI(self,owner,name=None,text=None,apps=None):#创建窗口
        actions={}                  #初始化actions
        actiongroups={}             #初始化actiongroups
        def proc_apps(head):            #处理apps，主要是处理菜单及工具栏 
            for app in apps:
                name=app['class']
                text=app.get('text','')
                action=QAction(text,head)
                action.setIcon(self.create_icon(owner,app.get('icon')))
                shortcut=app.get('shortcut')
                if shortcut:
                    action.setShortcut(shortcut)
                action.triggered.connect(partial(owner.add_child,name))
                actions[name]=action
                group=app.get('group',None)
                if group:
                    if group not in actiongroups:
                        actiongroups[group]=QActionGroup(head)
                    actiongroups[group].addAction(action)
            owner.app_list=actions.copy()
                    
        def create_widget(head,tag,attrib):  #创建控件或布局
            Widget=self.get_widget(tag)      #获取控件的类型，如失败则返回
            if Widget is None:return     
            if issubclass(Widget,QLayout): #布局的处理
                return create_layout(head,Widget,attrib)
            text=attrib.get('text')     
            widget=Widget(text)             #生成控件
            if hasattr(head,'addPermanentWidget'):#StatusBar控件处理
                head.addPermanentWidget(widget)
            elif hasattr(head,'addWidget'):  #摆放控件
                add_layout(head,'addWidget',widget,attrib)
            elif hasattr(head,'setCentralWidget'):
                head.setCentralWidget(widget)
            elif hasattr(head,'setWidget'):
                head.setWidget(widget)
            elif hasattr(head,'addTab'):
                label=attrib.get('label')
                head.addTab(widget,label)
            return widget
        
        def create_layout(head,Layout,attrib):#生成布局
            layout=Layout()
            if isinstance(head,QLayout):  #摆放布局
                add_layout(head,'addLayout',layout,attrib)
            elif hasattr(head,'setLayout'):
                head.setLayout(layout)
            return layout

        def add_layout(layout,func,widget,attrib):#摆放布局或控件
            if isinstance(layout,QFormLayout):#表单布局的处理
                label=attrib.get('label')
                args=[widget] if label is None else[label,widget]
                layout.addRow(*args)
            elif isinstance(layout,QGridLayout):#表格布局的处理
                pos=attrib.get('pos')
                args=[int(x) for x in pos.split(',')]
                if len(args) in (2,4):
                    args.insert(0,widget)
                    getattr(layout,func)(*args)
            else:#其他布局的处理
                getattr(layout,func)(widget)
            
        def create_menubar(head,attrib):  #生成菜单栏
            menubar=QMenuBar()         #生成菜单栏
            if hasattr(head,'setMenuBar'):  #设置菜单栏
                head.setMenuBar(menubar)
            return menubar
        
        def create_menu(head,attrib):  #生成菜单项
            text=attrib.get('text')
            if hasattr(head,'addMenu'):  #添加菜单
                menu=head.addMenu(text)
                add_actions(menu,attrib)   #处理actions 属性
                return menu 

        def add_actions(widget,attrib):  #处理actions 属性
            actions=attrib.get('actions')
            if actions:
                widget.addActions(
                        actiongroups[actions].actions())

        def create_action(head,attrib):# 生成action
            href=attrib.get('href')  #引用action的处理
            if href:
                action=actions.get(href)
            else:
                text=attrib.get('text')
                action=QAction(text,head)
                icon=self.create_icon(owner,attrib.get('icon'))
                action.setIcon(icon)
                triggered=attrib.get('triggered')
                if triggered:
                    do_connect(action,'triggered',triggered)
                name=attrib.get('id')
                if name:
                    actions[name]=action
            if hasattr(head,'addAction'): #添加action
                head.addAction(action)
            return action

        def create_toolbar(head,attrib):  #添加工具栏
            toolbar=QToolBar()
            if hasattr(head,'addToolBar'):
                head.addToolBar(toolbar)
                add_actions(toolbar,attrib)
            return toolbar
        
        def create_actiongroup(head,attrib): #生成actiongroup
            actiongroup=QActionGroup(head)
            name=attrib.get('id').lower()
            if name is not None:
                actiongroups[name]=actiongroup
            return actiongroup
        
        def set_property(widget,k,v): #设置属性
            k=k.lower()
            ps=self.get_propertys(widget)
            if k=='icon':
                v=(self.create_icon(v),)
            else:
                v=eval(v)
                if not isinstance(v,tuple):
                    v=(v,)
            for p in ['set','add','']:
                s=p+k
                if s in ps:
                    getattr(widget,ps[s])(*v)
                    break

        def proc_slot(widget,slot,signal):
            do_connect(widget,signal,slot)
            
        def do_connect(widget,signal,slot): #处理连接
            signal=self.get_attr(signal,[widget,owner])
            slot=self.get_attr(slot,[owner,widget])
            if signal and slot:
                signal.connect(slot)

        def set_variable(widget,var,p):  #设置变量
            s=p.split('.')
            t=None
            if len(s)>1:
                p=s[0]
                t=eval(s[-1])
            owner.var_list[var]=WidgetVar(widget,p,t)

        def proc_child(head,node):  #遍历子类型
            if head is None:return
            for child in node:
                tag=child.tag
                if tag=='a':   #处理锚点
                    href=child.attrib.get('href')
                    child=self.resources.get(href)
                    tag=child.tag
                attrib=child.attrib
                func=functions.get(child.tag) #根据TAG获取处理函数
                if func in [set_variable,set_property,do_connect,\
                            proc_slot]:
                    [func(head,k,v)for k,v in attrib.items()]
                else:
                    w=func(head,attrib) if func else create_widget(head,tag,attrib)
                    if w is not None:
                        name=attrib.get('name')
                        if name:
                            setattr(owner,name,w)
                        proc_child(w,child)
               
        def create_statusbar(head,attrib): #处理状态栏
            if hasattr(head,'statusBar'):
                statusbar=head.statusBar()
            if statusbar is None:
                statusbar=QStatusBar()
                if hasattr('setStatusBar'):
                    head.setSatusBar(statusbar)
            return statusbar

        def add_separator(head,attrib):  #处理分割符
            if hasattr(head,'addSeparator'):
                head.addSeparator()

        def add_stretch(head,attrib):  #设置分割栏
            if hasattr(head,'addStretch'):
                head.addStretch()

        functions={
                'menubar':create_menubar,
                'toolbar':create_toolbar,
                'statusbar':create_statusbar,
                'menu':create_menu,
                'actiongroup':create_actiongroup,
                'group':create_actiongroup,
                'separator':add_separator,
                'sep':add_separator,
                'action':create_action,
                'variable':set_variable,
                'var':set_variable,
                'property':set_property,
                'signal':do_connect,                
                'stretch':add_stretch,
                'connect':do_connect,
                'slot':proc_slot,
                }

        node=parser(content=text) if text else self.windows.get(name) #获取窗口资源
        if node:
            widget=create_widget(owner,node.tag,node.attrib) #生成主窗口
            if widget:
                if apps:   #处理apps
                    proc_apps(widget)
                widget.owner=owner
                proc_child(widget,node) # 处理属性及子控件
                owner.widget=widget  #这一句主要是防止系统自动进行垃圾回收
                return widget
            
class Window():    #表单的基类
    initial={}         #初始化数据
    def __init__(self):   #初始化函数
        self.var_list={}
        self.__data={}
        self.widget=None
    
    def __getitem__(self,index):   #获取数据
        if ',' in index:
            names=self.split_str(index,' ,\n\t')
            return tuple(self[name] for name in names)
        else:
            if index in self.var_list:
                return self.var_list[index].get() or None
            else:
                return self.__data.get(index)

    def __setitem__(self,index,value): #设置数据
        if ','in index:
            names=self.split_str(index,' ,\n\t')
            if value:
                for i in range(len(names)):
                    self[names[i]]=value[i]
            else:
                for i in range(len(names)):
                    self[names[i]]=None
        else:
            if index in self.var_list:
                if value is None:
                    value=''
                self.var_list[index].set(value)
            else:
                self.__data[index]=value or None
    
    def datas(self,vars):   #获取数据，返回一个字典
        if isinstance(vars,str):
            vars=vars.split(',')
        return dict([(var,self[var]) for var in vars if var])
        
    def init(self):              #设置初始数据
        self.update(self.initial)
        
    def showask(self,msg):    #弹出询问对话框
        return QMessageBox.question(self.widget,'Question',msg)
    
    def showinfo(self,msg):   #弹出信息对话框
        return QMessageBox.information(self.widget,'Information',msg)
     
    def showerr(self,msg):    #弹出错误对话框
        return QMessageBox.critical(self.widget,'Error',msg)
    
    def get_open_files(self,title,init_dir=None,parttern=None): #弹出打开文件对话框
        a=QFileDialog.getOpenFileNames(self.widget,title,init_dir,parttern)
        if isinstance(a,tuple):
            a=a[0]
        return a 

    def get_save_file(self,title,init_dir=None,parttern=None): #弹出保存文件对话框
        return QFileDialog.getSaveFileName(self.widget,title,init_dir,parttern)

    def update(self,data):  #更新数据
        for k,v in data.items():
            self[k]=v

    def split_str(self,string,seps):  #拆分字符件串
        t,d=0,[]
        string+=seps[0]
        for i in range(len(string)):
            if string[i] in seps:
                if i>t:
                    d.append(string[t:i])
                t=i+1
        return d
    
    def close(self):  #关闭窗口
        if hasattr(self,'owner'):
            self.owner.close()
        else:
            self.widget.close()
            
class MainWindow(Window):
    ui_text=None
    ui_file=None
    apps=None                   #子窗口类
    def __init__(self):         #初始化函化
        super().__init__()
        self.gui=QtGui(self.ui_file)
        self.gui.setup_UI(self,name='mainwindow',text=self.ui_text,
                          apps=self.apps)
        self.init()
        self.widget.move((qApp.desktop().width()-self.widget.width())/2,
                (qApp.desktop().height()-self.widget.height())/2)
        self.widget.show()

    @classmethod
    def run(cls):
        QtGui.main(cls)
 
class MdiWindow(MainWindow):   #主窗口

    childs={}                   #现存的子窗口    
    def create_widget(self,name):  #创建子窗口的主控件
        cls=self.childclasses.get(name)
        if cls is None:
            p=name.split('.')
            m=__import__('.'.join(p[:-1]),fromlist=p[-1:])
            cls=getattr(m,p[-1])
            self.childclasses[name]=cls
        if cls:
            return cls()

    def init(self):    #初始化
        super().init()
        self.mdiarea.subWindowActivated.connect(self.child_changed)
        self.childclasses={}
        
    def child_closeed(self,child):  #子窗口被关闭
        names=[name for name in self.childs if self.childs[name]==child]
        [self.childs.pop(name) for name in names]
        
    def child_changed(self):        #激活的子窗口变化
        child=self.mdiarea.activeSubWindow()
        self['title']='%s [%s]'%(self.title,child.windowTitle()) if child is not None else self.title
        
    def add_child(self,name=None,initial=None,submit=False): #添加子窗口
        child=self.childs.get(name)                 #从存在的子窗口中查找，如存在则激活
        if child:
            self.mdiarea.setActiveSubWindow(child)
            widget=child.widget().owner
        else:
            widget=self.create_widget(name)
            ui_text=widget.ui_text if hasattr(widget,'ui_text') else None
            window_name=name.split('.')[-1].lower()
            self.gui.setup_UI(widget,window_name,text=ui_text)
            widget.init()
            child=self.mdiarea.addSubWindow(widget.widget)
            child.setAttribute(Qt.WA_DeleteOnClose)
            child.destroyed.connect(self.child_closeed)
            self.childs[name]=child
            x=(self.mdiarea.width()-child.width())/2
            y=(self.mdiarea.height()-child.height())/2
            child.move(x,y)
            widget.owner=child
            child.show()
        if initial:
            widget.update(initial)
        if submit:
            widget.submit()
        return widget

class WidgetVar:  #窗口变量
    
    def __init__(self,widget,property_,tp=None):  #初始化函数
        property_=property_.lower()
        if tp:
            self.out_type=tp
        ps=QtGui.get_propertys(widget)
        p=ps.get(property_)
        s=ps.get('set'+property_)
        a=ps.get('add'+property_)
        if p and s:
            self.get_method=getattr(widget,p)
            self.in_type=type(self.get_method())
            self.set_method=getattr(widget,s)
        else:
            if p:
                self.get_method=getattr(widget,p)
                self.set_method=getattr(widget,p)
            if a or s :
                p= s or a
                self.set_method=getattr(widget,p)
 
    def get(self):                    #获取变量函数，如有类型，则进行转换
        var=self.get_method()
        if hasattr(self,'out_type'):
            var=convert(var,self.out_type)
        return var

    def set(self,value):      #设置变量函数，如有指定类型，则进行转换
        if hasattr(self,'in_type'):
            value=convert(value,self.in_type)
        self.set_method(value)

def convert(var,tp=str,fmt=None):  #类型转换函数
    
    def to_int(var):         #转换成整数
        try:
            if type(var) in (date,QDate,QDateTime):
                var=to_datetime(var)
            if type(var) in(float,str):
                return int(var)
            if isinstance(var,bool):
                return 1 if var else 0
            elif isinstance(var,datetime):
                return var.toordinal()            
        except:
            pass
            
    def to_float(var):        #转换成浮点数
        try:
            if isinstance(var,QTime):
                var=var.toPyTime()
            if type(var)in(date,QDate,QDateTime):
                var=to_datetime(var)
            if type(var) in(int,str):
                return float(var)
            if isinstance(var,bool):
                return 1.0 if var else 0.0
            elif isinstance(var,datetime):
                return var.toordinal()+((var.second/60+var.minute)/60+var.hour)/24      
            elif isinstance(var,time):
                return ((var.second/60+var.minute)/60+var.hour)/24
        except:
            pass

    def to_str(var):   #转换成字符串
        if var is not None:
            if type(var) in (QDate,QTime,QDateTime):
                var=to_datetime(var)
            if fmt:
                return format(var,fmt)
            else:
                return '%s'%(var)
        else:
            return ''

    def to_bool(var):  #转换成逻辑值
        return True if var else False
    
    def to_QDate(var):  #转换成日期
        dt=to_datetime(var)
        if dt:
            return QDate(dt.date())
    
    def to_QTime(var):  #转换成时间
        dt=to_datetime(var)
        if dt:
            return QTime(dt.time())
    
    def to_QDateTime(var): #转换成日期时间
        dt=to_datetime(var)
        if dt:
            return QDateTime(*dt.timetuple()[:6])

    def to_time(var):  #转换成时间
        dt=to_datetime(var)
        if dt:
            return dt.time()

    def to_datetime(var): #转换成日期时间
        if True:
            if isinstance(var,str):
                try:
                    var=float(var)
                except:
                    return datetime.strptime(var,'%Y-%m-%d %H:%M:%S')
            if type(var)==QDate:
                var= var.toPyDate()
            if type(var)==QTime:
                var=var.toPyTime()
            if isinstance(var,QDateTime):
                return var.toPyDateTime()
            elif isinstance(var,float):
                d=int(var)
                d=d if d else 1
                dt=datetime.fromordinal(d) if d else datetime()
                t=[]
                d=var
                for k in [24,60,60]:
                    t.append(int(d*k)%k)
                    d*=k
                return dt.replace(hour=t[0],minute=t[1],second=t[2]) 
                
            elif isinstance(var,int):
                if var:
                    return datetime.fromordinal(var)
            elif type(var) in(date,datetime):
                return datetime(*var.timetuple()[:7])
            elif isinstance(var,time):
                return datetime(1,1,1,var.hour,var.minute,var.second)
        else:
            return None

    def to_date(var): #转换成日期
        dt=to_datetime(var)
        if dt:
            return dt.date()
    def default(var):
        return var
    func={
            str:to_str,
            bool:to_bool,
            int:to_int,
            float:to_float,
            datetime:to_datetime,
            QDateTime:to_QDateTime,
            time:to_time,
            QTime:to_QTime,
            date:to_date,
            QDate:to_QDate,
            }
    return var if isinstance(var,tp) else func.get(tp,default)(var)

if __name__=='__main__':
    class A(MainWindow):
        ui_file='a.txt'
        def hello(self):
            t=self['abc']+self['de']
            self.showinfo(str(t))
    A.run()


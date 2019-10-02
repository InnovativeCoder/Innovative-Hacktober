const electron = require('electron');
const url = require('url');
const path = require('path');

const{app, BrowserWindow, Menu, globalShortcut} = electron;

let mainWindow;

app.on('ready', ()=>{
    globalShortcut.register('CommandOrControl+E', () => {
        app.quit();
    });
    mainWindow = new BrowserWindow(
        {
            webPreferences: {
                nodeIntegration: true
            }//, frame:false // comment this line to get DEV TOOls
        }
    );
    mainWindow.maximize();
    mainWindow.loadURL(url.format({
        pathname: path.join(__dirname, 'main.html'),
        protocol: 'file:',
        slashes: true
    }));

    const menu = Menu.buildFromTemplate(mainMenu);
    Menu.setApplicationMenu(menu);
});

const mainMenu = [
    {
        label:'Dev Tools',
        submenu:[
            {
                label: 'Toggle Dev Tools',
                accelerator: 'Ctrl+',
                click(item, focusedWindow){
                    focusedWindow.toggleDevTools();
                }
            }
        ]
    }
];

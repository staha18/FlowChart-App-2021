const path = require('path');
const url = require('url');
const { app, BrowserWindow } = require('electron');
const { ppid } = require('process');


function createWindow() {
    const win = new BrowserWindow({
        width: 1280,
        height: 800,
        icon: 'C:/Users/pesch/Desktop/FlowChart-App/img/flow-icon.ico',
        webPreferences: {
            nodeIntegration: true,
            contextIsolation:false
        }
    });

    win.loadFile('index-main.html');
     win.maximize;
};

app.whenReady().then(createWindow);

app.on('window-all-closed', () => {
    if (process.platform !== 'darwin') {
        app.quit();
    }
});

app.on('activate', () => {
    if (BrowserWindow.getAllWindows().length === 0) {
        createWindow();
    }
});




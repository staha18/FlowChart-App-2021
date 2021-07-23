const path = require('path');
const url = require('url');
const { app, BrowserWindow } = require('electron');
const { ppid } = require('process');


function createWindow() {
    const win = new BrowserWindow({
        width: 600,
        height: 800,
        fullscreen: true,
        webPreferences: {
            nodeIntegration: true,
            contextIsolation:false
        }
    });

    win.loadFile('index-main.html');
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




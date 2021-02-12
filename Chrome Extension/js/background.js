chrome.tabs.onActivated.addListener(tab => {
    chrome.tabs.get(tab.tabId, tabInfo => {
        if(/^https:\/\/www.google/.test(tabInfo.url)){
            chrome.tabs.insertCSS(null, {file: './css/style.css'});
            chrome.tabs.executeScript(null, {file: './js/popup.js'});
        }
    })
});


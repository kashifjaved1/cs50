chrome.tabs.onActivated.addListener(tab => {
    console.log(tab);
    chrome.tabs.get(tab.tabId, tabInfo => {
        if(/^https:\/\/www.google/.test(tabInfo.url)){
            chrome.tabs.insertCSS(null, {file: 'style.css'});
            chrome.tabs.executeScript({file: 'popup.js'});
            chrome.tabs.executeScript({file: "FileSaver.js"});
        }
    });

});


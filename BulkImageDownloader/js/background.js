let tid = 0;
chrome.tabs.query({active: true, currentWindow: true}, (tabs) => {
    tid = tabs[0].id;
    console.log(tid);
})
chrome.runtime.onMessage.addListener((request, sender) => {
    if(request.action === "reloadContentScript"){
        chrome.tabs.executeScript(tid, {file: "js/content.js"});
    }
})
imgList = [];
console.log(imgList);
for(let i = 0; i < document.querySelectorAll("img").length; i++){
    imgList[i] = document.querySelectorAll('img')[i].getAttribute('src');
}

console.log(imgList.length);

chrome.runtime.onMessage.addListener((msg, sender, sendResponse) => {
    if(msg.text === "hello"){
        sendResponse(imgList);
    }
})

document.addEventListener('scroll', _ => {
    chrome.runtime.sendMessage({action: "closePopupPage"});
}, {passive: true});


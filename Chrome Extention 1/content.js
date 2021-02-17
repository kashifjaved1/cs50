//chrome.storage.sync.set({imgList: document.querySelectorAll("img")});

/*let ary = [...document.querySelectorAll("img")];
if (typeof(Storage) !== "undefined") {
    let a = localStorage.setItem("imgList", ary);
    console.log(a.length);
}*/

/*chrome.runtime.onMessage.addListener(gotResponse);

function gotResponse(message, sender, sendResponse) {
    console.log(message);
    if (message.value == "GiveMeTheData") {
        console.log("==");
        //sendResponse({data: imgList});
    }
    else if(message.value === "GiveMeTheData"){
        console.log("===");
    }
    else{
        console.log("nothing here man");
    }
};*/
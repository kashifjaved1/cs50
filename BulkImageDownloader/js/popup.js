document.addEventListener('DOMContentLoaded', function () {

    let btn0 = document.createElement("button");
    btn0.id = "download";
    btn0.innerText = "Download";
    btn0.style.marginRight = "5px";
    document.querySelector("center").appendChild(btn0);

    let btn = document.createElement("button");
    btn.id = "selection";
    btn.innerText = "Select All";
    document.querySelector("center").appendChild(btn);

    document.body.appendChild(document.createElement("br"));

    let msg = {
        text: "hello"
    }

    chrome.tabs.query({active: true, currentWindow: true}, (tabs) => {
        chrome.tabs.sendMessage(tabs[0].id, msg, (response) => {
            console.log(response.length);
            for (let i = 0; i < response.length; i++) {
                let inp = document.createElement("input");
                inp.type = "checkbox";
                inp.id = i;
                document.body.appendChild(inp);
                let img = document.createElement("img");
                img.src = response[i]; // fetching as array
                img.id = i;
                img.onerror = _ => {
                    img.style.display = 'none';
                    inp.type = 'hidden';
                }
                document.body.appendChild(img);
                inp.value = img.src;
            }

            document.getElementById("selection").addEventListener('click', _ => {
                let chkbox = [...document.querySelectorAll('input')];
                console.log(document.getElementById("selection").innerText);
                if(document.getElementById("selection").innerText === "Select All"){
                    document.getElementById("selection").innerText = "Unselect All";
                    for(let i = 0; i < chkbox.length; i++){
                        document.querySelectorAll('input')[i].checked = true;
                    }
                }
                else{
                    document.getElementById("selection").innerText = "Select All";
                    for(let i = 0; i < chkbox.length; i++){
                        document.querySelectorAll('input')[i].checked = false;
                    }
                }
            })

            document.getElementById("download").addEventListener('click', _ => {
                let checked = [...document.querySelectorAll('input:checked')];
                for(let i = 0; i < checked.length; i++){
                    chrome.downloads.download({
                        url: checked[i].value,
                        //filename: "image " + checked[i].id + ".jpg"
                        //saveAs: true
                    });
                }
            })
        })
    })

    chrome.runtime.onMessage.addListener((msg, sender, sendResponse) => {
        if(msg.action === "closePopupPage"){
            chrome.runtime.sendMessage({action: "reloadContentScript"});
            window.close();
        }
    })

})
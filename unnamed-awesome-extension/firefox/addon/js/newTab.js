let searchbar,searchIcon,top_sites_container;
let list_item_template,list_item_node;
let customizer,closebtn,uploadbtn;
let bgimage;
let days_of_week=["Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"];
window.onload=function(){
    console.log("something hpasfs");
    searchbar=document.querySelector('.search-bar');
    searchIcon=document.querySelector('.search-icon');
    list_item_template=document.querySelector('.list-item-template');
    list_item_node=document.importNode(list_item_template.content,true);
    customizer=document.querySelector('.customize');
    closebtn=document.querySelector('.editWindow .close');
    bgimage=document.querySelector('.bg-wallpaper img');
    uploadbtn=document.querySelector('.upload');
    setBackground();
    addTopSites();
    addTime();
    
    searchIcon.addEventListener('click',()=>{
        newTab.search();
    });
  
    searchbar.addEventListener('keyup',e=>{
       if(e.which==13){
           newTab.search();
       }
    });
    customizer.addEventListener('click',()=>{
      toggleEditWindow();
    });
    closebtn.addEventListener('click',e=>{
      toggleEditWindow();
    });
    let images=document.querySelectorAll('.wallpapers img');
    images.forEach(image=>{
      image.addEventListener('click',e=>{
        let src=e.target.src;
        console.log(src);
        bgimage.src=src;
        chrome.storage.sync.set({bgurl:src,type:"default"});
      });
    });
   uploadbtn.addEventListener('click',e=>{
    document.querySelector('.file-selector').addEventListener('change',e=>{
      let file=e.target.files[0];
      let fileSize=Math.ceil(file.size/(1024*1024));
      if(fileSize<=2){
        let fileReader=new FileReader();
        fileReader.onload=()=>{
        chrome.storage.sync.set({type:"custom"});
        chrome.storage.local.set({bgsrc:fileReader.result});
        bgimage.src=fileReader.result;
        toggleEditWindow();
        }
        fileReader.readAsDataURL(file);
      }else{
        showAlert("upload image with less than 2MB");
      }
    

    })
     document.querySelector('.file-selector').click();
   })
}

async function setBackground(){
  let bgSource=await getBackgroundSource();
    if(bgSource && bgSource.type==="default"){
      bgimage.src=bgSource.bgurl;
    }else if(bgSource.type==="custom"){
      console.log("custom");
      chrome.storage.local.get(['bgsrc'],obj=>{
        bgimage.src=obj.bgsrc;
      })
    }
    bgimage.style.display="block";
    return
}

function toggleEditWindow(){
  let editwindow=document.querySelector('.editWindow');
  editwindow.classList.toggle('open');
}

function showAlert(message){
  let alertBox=document.querySelector('.alert');
  alertBox.querySelector('.message').textContent=message;
  alertBox.classList.toggle('show');
  setTimeout(() => {
    alertBox.classList.toggle('show'); 
  }, 3000);
}


let newTab={
    search:function(){
       let query=searchbar.value;
       console.log("called");
       if(query.trim()!=''){
        window.location.href=`https://www.google.com/search?q=${query}`
       }
    }
}
function addTopSites(){
    chrome.topSites.get(topSites=>{
        topSites=topSites.slice(0,8);
       
        let favicon_urls=[];

        topSites.forEach(site=>{
            console.log(site);

            let url = new URL(site.url);
            let faviconUrl = `http://favicongrabber.com/api/grab/${url.host}?pretty=true`;
            favicon_urls.push(faviconUrl);

            let node=list_item_node.cloneNode(true);
            node.querySelector('.label').textContent=site.title;
            node.querySelector('.list-item').title=site.title; 
            node.querySelector('.list-item').href=site.url; 
            let logo=node.querySelector('.site-icon');


          chrome.storage.local.get([faviconUrl],(ob)=>{
        
            if(ob[faviconUrl]){
              logo.src=ob[faviconUrl];
            }else{
            fetch(faviconUrl)
              .then(res => res.json())
              .then(data => {
                let src = data.icons[0].src || undefined;
                if (src) {
                  fetch(src).then(res => res.arrayBuffer()).then(buffer => {
                    var base64Flag = 'data:image/jpeg;base64,';
                    var imageStr = arrayBufferToBase64(buffer);
                    logo.src = base64Flag + imageStr;
                    //set the image here
                    chrome.storage.local.set({
                      [faviconUrl]: base64Flag + imageStr
                    });
                  }).catch(err => err);

                }
              })
              .catch(err => err);
            }
        })

            document.querySelector('.top-sites').appendChild(node);
        })
    })
}



function arrayBufferToBase64(buffer) {
    var binary = '';
    var bytes = [].slice.call(new Uint8Array(buffer));
    bytes.forEach((b) => binary += String.fromCharCode(b));
    return window.btoa(binary);
  };
  
  function removeUnUsedCache(favicon_urls){
     chrome.storage.local.get((cache=>{
        let cached_urls=Object.keys(cache);
        cached_urls.forEach(url => {
            if(!favicon_urls.includes(url)){
              chrome.storage.local.remove(url);
  
            }
        });
  
     }))
  }
  function addTime(){
      let timeDay=document.querySelector('.time-day');
      let date=document.querySelector('.date');
      let d= new Date();
      let [day,month,_date,year]=d.toString().split(' ');
      let [time,ampm]=d.toLocaleString().split(" ").slice(-2);
      
      timeDay.textContent=time.split(":").slice(0,2).join(":")+` ${ampm},${days_of_week[d.getDay()]}`;
      date.textContent=`${month} ${_date},${year}`;
      setTimeout(() => {
          addTime();
      }, 10000);
  }
  
  function getBackgroundSource(){
     return new Promise((resolve,reject)=>{
       chrome.storage.sync.get((obj)=>{
         resolve(obj);
       });
     })
  }


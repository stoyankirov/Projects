"use strict";

function myFunction(){
    var x=document.getElementById("nav");
    if(x.className === "myNav")
    {
        x.className+=" responsive";
    }
    else
    {
        x.className="myNav";
    }
}

var themeChange = document.getElementById("theme");
themeChange.addEventListener("click",()=>{
    var documentBody=document.querySelector("body");
    if(documentBody.classList.contains("dark-theme"))
    {
        documentBody.classList.remove("dark-theme");
    }
    else{
        documentBody.classList.add("dark-theme");
    }
})



"use strict";

var slideIndex = [1,1,1,1,1,1,1,1];
var slideId = ["slides1","slides2","slides3","slides4","slides5","slides6","slides7","slides8"];
showSlides(1,0);
showSlides(1,1);
showSlides(1,2);
showSlides(1,3);
showSlides(1,4);
showSlides(1,5);
showSlides(1,6);
showSlides(1,7);

function plusSlides(n,no){
    showSlides(slideIndex[no] += n,no);
}
function showSlides(n, no){
    var i;
    var x = document.getElementsByClassName(slideId[no]);
    if(n > x.length){
        slideIndex[no]=1;
    }
    if(n<1){
        slideIndex[no]=x.length;
    }
    for(i=0;i<x.length;i++){
        x[i].style.display = "none";
    }
    x[slideIndex[no]-1].style.display = "block";
    x[slideIndex[no]-1].getElementsByTagName("div")[0].innerHTML =  `${slideIndex[no]} / ${x.length}`;
}
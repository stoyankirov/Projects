"use strict";

var firebaseConfig = {
    apiKey: "AIzaSyBfgswbrS2Kef0FkXeuc1jIUAYsZIhpBw4",
    authDomain: "autoland-f87b4.firebaseapp.com",
    databaseURL: "https://autoland-f87b4.firebaseio.com",
    projectId: "autoland-f87b4",
    storageBucket: "autoland-f87b4.appspot.com",
    messagingSenderId: "766122799180",
    appId: "1:766122799180:web:2eca774eb70997025804e9",
    measurementId: "G-92L3SS33GQ"
};
firebase.initializeApp(firebaseConfig);
firebase.analytics();
  
var messagesRef = firebase.database().ref("messages");

document.getElementsByTagName("form")[0].addEventListener("submit",submitForm);

function submitForm(e){
    e.preventDefault();

    var fname = getInputVal("fname");
    var lname = getInputVal("lname");
    var pnumber = getInputVal("pnumber");
    var email = getInputVal("email");
    var make = getInputVal("make");
    var model = getInputVal("model");
    var year = getInputVal("year");
    var price = getInputVal("price");
    var additional = getInputVal("additional");

    saveMessage(fname, lname, pnumber, email, make, model, year, price, additional);


}

function getInputVal(id){
    return document.getElementById(id).value;
}

function saveMessage(fname, lname, pnumber, email, make, model, year, price, additional){
    var newMessageRef = messagesRef.push();
    newMessageRef.set({
       fname: fname, 
       lname: lname,
       pnumber: pnumber,
       email: email,
       make: make,
       model: model,
       year: year,
       price: price,
       additional: additional
    });
}



"use strict";

function validateNames(){
    var x=document.forms["myForm"]["firstName"].value;
    var y=document.forms["myForm"]["lastName"].value;
    var i,j;

    for(i=0;i<x.length;i++)
    {
        if((x[i]<"a"||x[i]>"z")&&(x[i]<"A"||x[i]>"Z"))
        {
            alert("Error! Please input correct data.");
            return false;
        }
    }

    for(j=0;j<y.length;j++)
    {
        if((y[j]<"a"||y[j]>"z")&&(y[j]<"A"||y[j]>"Z"))
        {
            alert("Error! Please input correct data.");
            return false;
        }
    }

    return true;
}

function validatePhoneNumber(){
    var x=document.forms["myForm"]["phoneNumber"].value;
    var i;
    
    for(i=0;i<x.length;i++)
    {
        if(x[i]<"0"||x[i]>"9")
        {
            alert("Error! Please input correct data.");
            return false;
        }
    }

    return true;
}
function validateEmail(){
    var x=document.forms["myForm"]["email"].value;

    var n = x.indexOf("@");
    var m = x.lastIndexOf(".");

    if(n===0 || n>m || n===-1 || m===-1 || n+1===m)
    {
        alert("Error! Please input correct data.");
        return false;
    }
    return false;
}
function validateForm()
{   
    return validateNames()&&validatePhoneNumber()&&validateEmail();
}
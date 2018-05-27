
//Tablica dla arduino
 var TablicaDlaArduino = [0];
 //Przyciski
 var wButton = $(".w");
 var sButton = $(".s");
 var aButton = $(".a");
 var dButton = $(".d");
 //Głowa
 var _8Button = $("._8");
 var _2Button = $("._2");
 var _4Button = $("._4");
 var _6Button = $("._6");
 var _5Button = $("._5");
 //Funkcyjne
 var F0Button = $(".F0");
 var F1Button = $(".F1");
 var F2Button = $(".F2");
 var F3Button = $(".F3");
 var F4Button = $(".F4");
 var F5Button = $(".F5");
 //Okno Log na stronie
 var TextArea = $(".TextArea");
 //boolowskie zmienne dla holdingu klawisza
 var wHold,sHold,aHold,dHold, _8Hold, _2Hold, _4Hold, _6Hold, _5Hold, F0Hold, F1Hold, F2Hold, F3Hold, F4Hold, F5Hold = false;
 var ws = new WebSocket("ws://206.189.207.171:80");
 ws.onopen = function(e) {
 console.log('Connection to server opened');
 AppendLineToLog('Connection to server opened');
 }
 function sendMessage() {
 ws.send($('#message').val());
 }
 function sendMessage2() {
 console.log(TablicaDlaArduino);
 AppendLineToLog(TablicaDlaArduino);
 ws.send(TablicaDlaArduino);
 }
 ws.onmessage = function(e) {
 if(typeof e.data === "string"){
 console.log("String message received", e, e.data);
 } else {
 console.log("Other message received", e, e.data);
 }
}


//Keyboard input
document.addEventListener('keydown', (event) => {
  const keyName = event.key;
  //alert('keypress event\n\n' + 'key: ' + keyName);
  if(keyName=="w" && !wHold){TablicaDlaArduino[0] = 1;wHold = true;sendMessage2(); ColorButton(wButton);}
  if(keyName=="s" && !sHold){TablicaDlaArduino[0] = 2;sHold = true;sendMessage2(); ColorButton(sButton);}
  if(keyName=="a" && !aHold){TablicaDlaArduino[0] = 3;aHold = true;sendMessage2(); ColorButton(aButton);}
  if(keyName=="d" && !dHold){TablicaDlaArduino[0] = 4;dHold = true;sendMessage2(); ColorButton(dButton);}
  //Sterowanie głową
  if(keyName=="8" && !_8Hold){TablicaDlaArduino[0] = 2;_8Hold = true;sendMessage2(); ColorButton(_8Button);}
  if(keyName=="2" && !_2Hold){TablicaDlaArduino[0] = 6;_2Hold = true;sendMessage2(); ColorButton(_2Button);}
  if(keyName=="4" && !_4Hold){TablicaDlaArduino[1] = 6;_4Hold = true;sendMessage2(); ColorButton(_4Button);}
  if(keyName=="6" && !_6Hold){TablicaDlaArduino[1] = 2;_6Hold = true;sendMessage2(); ColorButton(_6Button);}
  if(keyName=="5" && !_5Hold){TablicaDlaArduino[1] = 4;TablicaDlaArduino[0] = 4;_5Hold = true;sendMessage2(); ColorButton(_5Button);}
  //Funkcyjne
  if(keyName=="e" && !F0Hold){TablicaDlaArduino[2] = 1;F0Hold = true;sendMessage2(); ColorButton(F0Button);}
  if(keyName=="r" && !F1Hold){TablicaDlaArduino[2] = 2;F1Hold = true;sendMessage2(); ColorButton(F1Button);}
  if(keyName=="t" && !F2Hold){TablicaDlaArduino[2] = 3;F2Hold = true;sendMessage2(); ColorButton(F2Button);}
  if(keyName=="y" && !F3Hold){TablicaDlaArduino[2] = 4;F3Hold = true;sendMessage2(); ColorButton(F3Button);}
  if(keyName=="u" && !F4Hold){TablicaDlaArduino[2] = 5;F4Hold = true;sendMessage2(); ColorButton(F4Button);}
  if(keyName=="i" && !F5Hold){TablicaDlaArduino[2] = 6;F5Hold = true;sendMessage2(); ColorButton(F5Button);}
});
//Funkcja kolorująca wciśnięty guzik
function ColorButton(e){
  $(e).css("background-color", "yellow");
}
//Funkcja usuwająca kolor przy keyupie
function UnColorButton(e){
  $(e).css("background-color", "grey");
}
//Keyup
document.addEventListener('keyup', (event) => {
  const keyName = event.key;
  //TablicaDlaArduino = [4,4,0,0,0,0,0,0,0,0];
  if(keyName=="w"){wHold = false; UnColorButton(wButton)}
  if(keyName=="s"){sHold = false; UnColorButton(sButton)}
  if(keyName=="a"){aHold = false; UnColorButton(aButton)}
  if(keyName=="d"){dHold = false; UnColorButton(dButton)}
  //sterowanie głową
  if(keyName=="8"){_8Hold = false; UnColorButton(_8Button)}
  if(keyName=="2"){_2Hold = false; UnColorButton(_2Button)}
  if(keyName=="4"){_4Hold = false; UnColorButton(_4Button)}
  if(keyName=="6"){_6Hold = false; UnColorButton(_6Button)}
  if(keyName=="5"){_5Hold = false; UnColorButton(_5Button)}
  //Funkcyjne
  if(keyName=="e"){F0Hold = false; UnColorButton(F0Button)}
  if(keyName=="r"){F1Hold = false; UnColorButton(F1Button)}
  if(keyName=="t"){F2Hold = false; UnColorButton(F2Button)}
  if(keyName=="y"){F3Hold = false; UnColorButton(F3Button)}
  if(keyName=="u"){F4Hold = false; UnColorButton(F4Button)}
  if(keyName=="i"){F5Hold = false; UnColorButton(F5Button)}
  sendMessage2();
});

//Funkcja appendująca linię do Loga na stronie
function AppendLineToLog(wyraz){
  var Data = new Date();
  $(TextArea).append(wyraz +" | "+ Data.getHours()+":"+Data.getMinutes()+":"+Data.getSeconds()+"\n" ); 
  $(TextArea).scrollTop($(TextArea)[0].scrollHeight);
}
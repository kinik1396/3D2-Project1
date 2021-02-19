import processing.serial.*;
Serial myPort;
String myText="";
void setup(){
size(420, 780);
myPort = new Serial(this, "COM4", 9600);
myPort.bufferUntil('n');
}
void serialEvent (Serial myPort){
myText = myPort.readStringUntil('n');
}
void draw(){
background(0);

if (mouseX>30 && mouseX<30+350 && mouseY>30 && mouseY<30+175 && mousePressed && (mouseButton == LEFT)) {
  fill (80,199,199); // red when mouse over
  rect(30, 30, 350, 175, 7);
  fill(255);
  textSize(32);
  text("Color Wipe",(240/2), 30+(190/2));
  myPort.write('1');
}
else{
  fill(255);
  rect(30, 30, 350, 175, 7);
  fill(80,199,199);
  textSize(32);
  text("Color Wipe",(240/2), 30+(190/2));
}
if (mouseX>30 && mouseX<30+350 && mouseY>300 && mouseY<300+175 && mousePressed && (mouseButton == LEFT)) {
  fill (199, 80, 80); // red when mouse over
  rect(30, 300, 350, 175, 7);
  fill(255);
  textSize(32);
  text("Rainbow",(280/2), 300+(190/2));
  myPort.write('0');
}
else{
  fill(255);
  rect(30, 300, 350, 175, 7);
  fill(199, 80, 80);
  textSize(32);
  text("Rainbow",(280/2), 300+(190/2));
  
}
if (mouseX>30 && mouseX<30+350 && mouseY>570 && mouseY<570+175 && mousePressed && (mouseButton == LEFT)) {
  fill (80, 199, 103); // red when mouse over
  rect(30, 570, 350, 175, 7);
  fill(255);
  textSize(32);
  text("Theatre",(290/2), 570+(190/2));
  myPort.write('2');
}
else{
  fill(255);
  rect(30, 570, 350, 175, 7);
  fill(80, 199, 103);
  textSize(32);
  text("Theatre", (290/2), 570+(190/2));
  
}

}
//https://howtomechatronics.com/tutorials/arduino/processing/

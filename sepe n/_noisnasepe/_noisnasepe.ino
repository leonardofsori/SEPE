// this code for testing wifi access point control 
// www.dcmote.duino,lk
// coding by Tharindu Ireshana : Leader of DCmote Open Sourse Project
// www.facebook.com/dcremote
// https://github.com/irashana
// www.facebook.com/tharinduireshana
// tirashana@gmail.com
// 94715376785


#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>

/* Set these to your desired credentials. */
const char *ssid = "ifc_projeto";
const char *password = "";

ESP8266WebServer server(80);

const String HTTP_HEAD           = "<!DOCTYPE html><html><head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1, user-scalable=no\"/><title>É NOIS NA SEPE</title>";
const String HTTP_STYLE  = "<style>button { padding: 10px;} li { list-style-type: none; margin-bottom: 10px;} h1{ position: relative; top: -25%; text-align: left; padding-left: 2.5%;} .menu1 { position: relative; left: 0; top: 25%; width: 100%; text-align: left; padding-left: 40%;} .menu2 { position: relative; left: 0; top: 75%; width: 100%; text-align: left; padding-left: 40%;} body { position: relative; top: 50px; left: 0%;}</style>";
const String HTTP_SCRIPT        = "<script>function c(l){document.getElementById('s').value=l.innerText||l.textContent;document.getElementById('p').focus();}</script>";
const String HTTP_HEAD_END      = "</head><body><div style='text-align:left;display:inline-block;min-width:260px;'>";

const String HOMEPAGE = "<nav class=\"menu1\"><h1>PISO 1</h1><ul><li>Sala:</li><ul><li><p>Lampada</p><form action=\"/cmd1\" method=\"get\"><INPUT TYPE=\"RADIO\" NAME=\"oplampsala\" VALUE=\"/oplampsala1\"> desliga </form> <form action=\"/cmd2\" method=\"get\"><INPUT TYPE=\"RADIO\" NAME=\"oplampsala\" VALUE=\"/oplampsala2\"> liga </form><li></ul><li>Cozinha<li><ul><li><p>Lampada</p><INPUT TYPE=\"RADIO\" NAME=\"oplampcozi\" VALUE=\"oplampcozi1\" checked> desliga <INPUT TYPE=\"RADIO\" NAME=\"oplampcozi\" VALUE=\"oplampcozi2\">liga <li><p>Chaleira</p> <INPUT TYPE=\"RADIO\" NAME=\"opchaleira\" VALUE=\"opchaleira1\" checked> desliga <INPUT TYPE=\"RADIO\" NAME=\"opchaleira\" VALUE=\"opchaleira2\">liga<li></ul></ul></nav><nav class=\"menu2\"<h1>PISO 2</h1><ul><li>Quarto Casal:<li><ul><li><p>Lâmpada</p><INPUT TYPE=\"RADIO\" NAME=\"oplampcasal\" VALUE=\"oplampcasal1\" checked> desliga <INPUT TYPE=\"RADIO\" NAME=\"oplampcasal\" VALUE=\"oplampcasal2\">liga <li></ul><li>Quarto Crianças:<li><ul><li><p>Lâmpada</p> <INPUT TYPE=\"RADIO\" NAME=\"oplampcri\" VALUE=\"oplampcri1\" checked> desliga <INPUT TYPE=\"RADIO\" NAME=\"oplampcri\" VALUE=\"oplampcri2\">liga <li></ul></ul></nav>";

//const String HOMEPAGE = "<form action=\"/cmd1\" method=\"get\"><button class=\"button3\">Red</button></form><br/><form action=\"/cmd2\" method=\"get\"><button class=\"button6\">Green</button></form><br/> <form action=\"/cmd3\" method=\"get\"><button class=\"button2\">Yellow</button></form><br/><form action=\"/cmd4\" method=\"get\"><button class=\"button4\">Off</button></form><br/> <form action=\"/cmd7\" method=\"get\"><button class=\"button7\">All</button></form><br/>   ";






/* Just a little test message.  Go to http://192.168.4.1 in a web browser
 * connected to this access point to see it.
 */
void handleRoot() {
 String s =HTTP_HEAD;
       s += HTTP_STYLE;
      s += HTTP_SCRIPT;  
      s += HTTP_HEAD_END;
      s+=HOMEPAGE;
  server.send(200, "text/html", s);
 
}

void cmd1() {
 String s =HTTP_HEAD;
       s += HTTP_STYLE;
      s += HTTP_SCRIPT;  
      s += HTTP_HEAD_END;
      s+=HOMEPAGE;
  server.send(200, "text/html", s);
   digitalWrite(D7,LOW);
} 

void cmd2() {
 String s =HTTP_HEAD;
       s += HTTP_STYLE;
      s += HTTP_SCRIPT;  
      s += HTTP_HEAD_END;
      s+=HOMEPAGE;
  server.send(200, "text/html", s);
   digitalWrite(D7,HIGH);
} 

void oplampcozi1() {
 String s =HTTP_HEAD;
       s += HTTP_STYLE;
      s += HTTP_SCRIPT;  
      s += HTTP_HEAD_END;
      s+=HOMEPAGE;
  server.send(200, "text/html", s);
    digitalWrite(D6,LOW);
}


void oplampcozi2() {
 String s =HTTP_HEAD;
       s += HTTP_STYLE;
      s += HTTP_SCRIPT;  
      s += HTTP_HEAD_END;
      s+=HOMEPAGE;
  server.send(200, "text/html", s);
    digitalWrite(D6,HIGH);
}

void opchaleira1() {
 String s =HTTP_HEAD;
       s += HTTP_STYLE;
      s += HTTP_SCRIPT;  
      s += HTTP_HEAD_END;
      s+=HOMEPAGE;
  server.send(200, "text/html", s);
   digitalWrite(D5,LOW);
}
void opchaleira2() {
 String s =HTTP_HEAD;
       s += HTTP_STYLE;
      s += HTTP_SCRIPT;  
      s += HTTP_HEAD_END;
      s+=HOMEPAGE;
  server.send(200, "text/html", s);
   digitalWrite(D5,HIGH);
}

void oplampcasal1() {
 String s =HTTP_HEAD;
       s += HTTP_STYLE;
      s += HTTP_SCRIPT;  
      s += HTTP_HEAD_END;
      s+=HOMEPAGE;
  server.send(200, "text/html", s);
   digitalWrite(D4,LOW);
}


void oplampcasal2() {
 String s =HTTP_HEAD;
       s += HTTP_STYLE;
      s += HTTP_SCRIPT;  
      s += HTTP_HEAD_END;
      s+=HOMEPAGE;
  server.send(200, "text/html", s);
   digitalWrite(D4,HIGH);
}

void oplampcri1() {
 String s =HTTP_HEAD;
       s += HTTP_STYLE;
      s += HTTP_SCRIPT;  
      s += HTTP_HEAD_END;
      s+=HOMEPAGE;
  server.send(200, "text/html", s);
   digitalWrite(D3,LOW);
}
void oplampcri2() {
 String s =HTTP_HEAD;
       s += HTTP_STYLE;
      s += HTTP_SCRIPT;  
      s += HTTP_HEAD_END;
      s+=HOMEPAGE;
  server.send(200, "text/html", s);
   digitalWrite(D3,HIGH);
}


void setup() {
  delay(1000);
  pinMode(D7,OUTPUT);
  pinMode(D6,OUTPUT);
  pinMode(D5,OUTPUT);
  pinMode(D4,OUTPUT);
  pinMode(D3,OUTPUT);
 
    digitalWrite(D0,LOW);
    
  Serial.begin(115200);
  Serial.println();
  Serial.print("Configuring access point...");
  /* You can remove the password parameter if you want the AP to be open. */
  WiFi.softAP(ssid, password);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server.on("/", handleRoot);
  server.on("/cmd1", cmd1);
  server.on("/cmd2", cmd2);
  server.on("/oplampcozi1", oplampcozi1);
  server.on("/oplampcozi2", oplampcozi2);
  server.on("/opchaleira1", opchaleira1);
  server.on("/opchaleira2", opchaleira2);
  server.on("/oplampcasal1", oplampcasal1);
  server.on("/oplampcasal2", oplampcasal2);
  server.on("/oplampcri1", oplampcri1);
  server.on("/oplampcri2", oplampcri2);
  
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}

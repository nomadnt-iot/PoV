uint8_t delayTime = 2; //sub-char delay time
uint8_t charBreak = 5; //char delay time

// led matrix
uint8_t LED[] = {4, 3, 2, 1, 0};

uint8_t a[] = {1, 6, 26, 6, 1};
uint8_t b[] = {31, 21, 21, 10, 0};
uint8_t c2[] = {14, 17, 17, 10, 0};
uint8_t d[] = {31, 17, 17, 14, 0};
uint8_t e[] = {31, 21, 21, 17, 0};
uint8_t f[] = {31, 20, 20, 16, 0};
uint8_t g[] = {14, 17, 19, 10, 0};
uint8_t h[] = {31, 4, 4, 4, 31};
uint8_t i[] = {0, 17, 31, 17, 0};
uint8_t j[] = {0, 17, 30, 16, 0};
uint8_t k[] = {31, 4, 10, 17, 0};
uint8_t l[] = {31, 1, 1, 1, 0};
uint8_t m[] = {31, 12, 3, 12, 31};
uint8_t n[] = {31, 12, 3, 31, 0};
uint8_t o[] = {14, 17, 17, 14, 0};
uint8_t p[] = {31, 20, 20, 8, 0};
uint8_t q[] = {14, 17, 19, 14, 2};
uint8_t r[] = {31, 20, 22, 9, 0};
uint8_t s[] = {8, 21, 21, 2, 0};
uint8_t t[] = {16, 16, 31, 16, 16};
uint8_t u[] = {30, 1, 1, 30, 0};
uint8_t v[] = {24, 6, 1, 6, 24};
uint8_t w[] = {28, 3, 12, 3, 28};
uint8_t x[] = {17, 10, 4, 10, 17};
uint8_t y[] = {17, 10, 4, 8, 16};
uint8_t z[] = {19, 21, 21, 25, 0};

uint8_t eos[] = {0, 1, 0, 0, 0};
uint8_t excl[] = {0, 29, 0, 0, 0};
uint8_t ques[] = {8, 19, 20, 8, 0};

const char *message = "Jacopo Sallemi";

void setup(){
  for(uint8_t i = 0; i < 5; i++){
      pinMode(LED[i], OUTPUT);
      digitalWrite(LED[i], HIGH);
      delay(300);
  }

  for(uint8_t i = 0; i < 5; i++){
    digitalWrite(LED[4 - i], LOW);
    delay(300);
  }
}

void displayLine(int line)
{
  int myline;
  myline = line;

  if (myline>=16) {digitalWrite(LED[0], HIGH); myline-=16;} else {digitalWrite(LED[0], LOW);}
  if (myline>=8)  {digitalWrite(LED[1], HIGH); myline-=8;}  else {digitalWrite(LED[1], LOW);}
  if (myline>=4)  {digitalWrite(LED[2], HIGH); myline-=4;}  else {digitalWrite(LED[2], LOW);}
  if (myline>=2)  {digitalWrite(LED[3], HIGH); myline-=2;}  else {digitalWrite(LED[3], LOW);}
  if (myline>=1)  {digitalWrite(LED[4], HIGH); myline-=1;}  else {digitalWrite(LED[4], LOW);}
}

void displayChar(char c)
{
  if (c == 'a'){for (int i = 0; i <5; i++){displayLine(a[i]);delay(delayTime);}displayLine(0);}
  if (c == 'b'){for (int i = 0; i <5; i++){displayLine(b[i]);delay(delayTime);}displayLine(0);}
  if (c == 'c'){for (int i = 0; i <5; i++){displayLine(c2[i]);delay(delayTime);}displayLine(0);}
  if (c == 'd'){for (int i = 0; i <5; i++){displayLine(d[i]);delay(delayTime);}displayLine(0);}
  if (c == 'e'){for (int i = 0; i <5; i++){displayLine(e[i]);delay(delayTime);}displayLine(0);}
  if (c == 'f'){for (int i = 0; i <5; i++){displayLine(f[i]);delay(delayTime);}displayLine(0);}
  if (c == 'g'){for (int i = 0; i <5; i++){displayLine(g[i]);delay(delayTime);}displayLine(0);}
  if (c == 'h'){for (int i = 0; i <5; i++){displayLine(h[i]);delay(delayTime);}displayLine(0);}
  if (c == 'i'){for (int it = 0; it <5; it++){displayLine(i[it]);delay(delayTime);}displayLine(0);}
  if (c == 'j'){for (int i = 0; i <5; i++){displayLine(j[i]);delay(delayTime);}displayLine(0);}
  if (c == 'k'){for (int i = 0; i <5; i++){displayLine(k[i]);delay(delayTime);}displayLine(0);}
  if (c == 'l'){for (int i = 0; i <5; i++){displayLine(l[i]);delay(delayTime);}displayLine(0);}
  if (c == 'm'){for (int i = 0; i <5; i++){displayLine(m[i]);delay(delayTime);}displayLine(0);}
  if (c == 'n'){for (int i = 0; i <5; i++){displayLine(n[i]);delay(delayTime);}displayLine(0);}
  if (c == 'o'){for (int i = 0; i <5; i++){displayLine(o[i]);delay(delayTime);}displayLine(0);}
  if (c == 'p'){for (int i = 0; i <5; i++){displayLine(p[i]);delay(delayTime);}displayLine(0);}
  if (c == 'q'){for (int i = 0; i <5; i++){displayLine(q[i]);delay(delayTime);}displayLine(0);}
  if (c == 'r'){for (int i = 0; i <5; i++){displayLine(r[i]);delay(delayTime);}displayLine(0);}
  if (c == 's'){for (int i = 0; i <5; i++){displayLine(s[i]);delay(delayTime);}displayLine(0);}
  if (c == 't'){for (int i = 0; i <5; i++){displayLine(t[i]);delay(delayTime);}displayLine(0);}
  if (c == 'u'){for (int i = 0; i <5; i++){displayLine(u[i]);delay(delayTime);}displayLine(0);}
  if (c == 'v'){for (int i = 0; i <5; i++){displayLine(v[i]);delay(delayTime);}displayLine(0);}
  if (c == 'w'){for (int i = 0; i <5; i++){displayLine(w[i]);delay(delayTime);}displayLine(0);}
  if (c == 'x'){for (int i = 0; i <5; i++){displayLine(x[i]);delay(delayTime);}displayLine(0);}
  if (c == 'y'){for (int i = 0; i <5; i++){displayLine(y[i]);delay(delayTime);}displayLine(0);}
  if (c == 'z'){for (int i = 0; i <5; i++){displayLine(z[i]);delay(delayTime);}displayLine(0);}
  if (c == '!'){for (int i = 0; i <5; i++){displayLine(excl[i]);delay(delayTime);}displayLine(0);}
  if (c == '?'){for (int i = 0; i <5; i++){displayLine(ques[i]);delay(delayTime);}displayLine(0);}
  if (c == '.'){for (int i = 0; i <5; i++){displayLine(eos[i]);delay(delayTime);}displayLine(0);}
  delay(charBreak);
}

void displayString(char* s){
  for(int i = 0; i<=strlen(s); i++){
    displayChar(s[i]);
  }
}

void loop(){
  displayString(message);
}

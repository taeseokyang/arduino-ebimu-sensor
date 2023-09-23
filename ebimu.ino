#define SBUF_SIZE 64

char sbuf[SBUF_SIZE];
signed int sbuf_cnt=0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  int rbytes = Serial.available();
  for(int n=0;n<rbytes;n++){
    sbuf[sbuf_cnt] = Serial.read();
    if (sbuf[sbuf_cnt] == '*'){
      for(int m=0;m<sbuf_cnt;m++){
        Serial.print(sbuf[m]);
        if(m==sbuf-1){
          Serial.print("\n");
        }
      }
      sbuf_cnt = 0;
    }else{
      sbuf_cnt++;
    }
  }
  delay(100);
}
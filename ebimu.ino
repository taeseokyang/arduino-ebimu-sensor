#define BUF_SIZE 64 //버퍼 사이즈
char buf[BUF_SIZE];//버퍼
int now_buf_idx=0;//현재 버퍼 인덱스
int valid_check_num = 0;//유효성 검사 정수
int rbytes = 0;//시리얼 버퍼 길이
char *data = NULL;
float roll = 0;
float pitch = 0;
float yaw = 0;
void setup() {
  Serial.begin(115200);
  Serial.println("Roll,Pitch,Yaw");
}

void loop() {
  rbytes = Serial.available();//시리얼 버퍼 길이 확인
  for(int n=0;n<rbytes;n++){
    buf[now_buf_idx] = Serial.read(); //데이터 읽기
    //유효성 검사
    if (buf[now_buf_idx] == ',' ){valid_check_num++;}
    if(buf[now_buf_idx] == '*' ){valid_check_num=valid_check_num+100;}
    if(buf[now_buf_idx] == '\n'){//데이터 출력
      if (valid_check_num == 102){//유효성 검사 확인
        buf[0] = ' ';//* 제거

        //데이터 파싱
        data = strtok(buf, ","); 
        roll = atof(data);
        Serial.print(roll);
        Serial.print(",");

        data = strtok(NULL, ",");
        pitch = atof(data);
        Serial.print(pitch);
        Serial.print(",");

        data = strtok(NULL, ",");
        yaw = atof(data);
        Serial.print(yaw);

        Serial.print("\n");
      }
      now_buf_idx = 0;//버퍼 위치 초기화
      valid_check_num = 0;//유효성 검사 정수 초기화
    }else{now_buf_idx++;} //버퍼 위치 증가
  }
}
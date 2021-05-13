

volatile byte cline = 0;
volatile boolean L1 = false;
volatile boolean L2 = false;
volatile boolean L3 = false;
volatile boolean L4 = false;
byte dat =0;

int back_line(){
  if(cline>2){//отезжаем от линии
    if(!L1){
      dat=1;
    }
    if(!L2){
      dat=2;
    }
    if(!L3){
      dat=3;
    }
    if(!L4){
      dat=4;
    }
    Serial.print('L',dat);
    cline=0; 
  }
  
}


void setup() {
  Serial.begin(9600);
  attachInterrupt(0, line_1, RISING);
  attachInterrupt(1, line_2, RISING);
  attachInterrupt(2, line_3, RISING);
  attachInterrupt(3, line_4, RISING);
  attachInterrupt(4, Start, RISING);
  attachInterrupt(5, Mode, RISING);
  attachInterrupt(6, Mode2, RISING);
}

void loop() {
  
}
void Mode2(){
  Serial.print('G','1');
}

void Mode(){
  Serial.print('F','1');
}

void Start(){
  Serial.print('S','1');
}

void line_1(){
  cline<3?cline++:back_line();
  L1 = true;
}
void line_2(){
  cline<3?cline++:back_line();
  L2 = true;
}
void line_3(){
  cline<3?cline++:back_line();
  L3 = true;
}
void line_4(){
  L4 = true;
  cline<3?cline++:back_line();
}


//условие?первое:второе
